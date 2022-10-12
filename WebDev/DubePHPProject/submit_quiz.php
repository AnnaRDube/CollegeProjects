<?php
require_once('database.php');

$name = filter_input(INPUT_POST, 'name');
$catID = filter_input(INPUT_POST, 'cat_id', FILTER_VALIDATE_INT);
$grade = filter_input(INPUT_POST, 'grade', FILTER_VALIDATE_INT);

$question1 = filter_input(INPUT_POST, 'answer1');
$question2 = filter_input(INPUT_POST, 'answer2');
$question3 = filter_input(INPUT_POST, 'answer3');
$question4 = filter_input(INPUT_POST, 'answer4');
$question5 = filter_input(INPUT_POST, 'answer5');

$ansArray = array($question1, $question2, $question3, $question4, $question5);

if ($question1 == NULL || $question1 == FALSE){
	$question1 = "";
}
if ($question2 == NULL || $question2 == FALSE){
	$question2 = "";
}
if ($question3 == NULL || $question3 == FALSE){
	$question3 = "";
}
if ($question4 == NULL || $question4 == FALSE){
	$question4 = "";
}
if ($question5 == NULL || $question5 == FALSE){
	$question5 = "";
}
if ($catID == NULL || $catID == FALSE){
	$catID = 1;
}
if ($grade == NULL || $grade == FALSE){
	$grade = 1;
}
if ($name == NULL || $name == FALSE){
	$name = "";
}

//get answers query
$queryQuestions = 'SELECT * FROM question
                  WHERE category_id = :catID AND grade_level = :grade
                  ORDER BY question_id';
$statement3 = $db->prepare($queryQuestions);
$statement3->bindValue(':catID', $catID);
$statement3->bindValue(':grade', $grade);
$statement3->execute();
$questions = $statement3->fetchAll();
$statement3->closeCursor();

$counter = 0;
$numMissed = 0;
$numCorrect = 0;
$score = 0;
foreach ($questions as $answer){
	if(strtoupper($answer['answer']) === strtoupper($ansArray[$counter])){
		$numCorrect++;
	} else {$numMissed++;}
	$counter++;
}
$score = ($numCorrect / 5) * 100;

$scoreTotal = 0;

//insert new score
if($name != ""){
	$scoreTotal = $grade * $numCorrect;

	$queryInsert = 'INSERT INTO `user`(`user_name`, `score`, `cat_id`, `grade_id`) 
					VALUES (:name, :scoreTotal,:catID, :grade)';
	$statement2 = $db->prepare($queryInsert);
	$statement2->bindValue(':catID', $catID);
	$statement2->bindValue(':grade', $grade);
	$statement2->bindValue(':name', $name);
	$statement2->bindValue(':scoreTotal', $scoreTotal);
	$statement2->execute();
	$statement2->closeCursor();
}

//get scores
$queryUsers = 'SELECT * FROM user
                  ORDER BY score DESC LIMIT 5';
$statement = $db->prepare($queryUsers);
$statement->execute();
$users = $statement->fetchAll();
$statement->closeCursor();

$queryGradeUsers = 'SELECT * FROM user
					WHERE grade_id = :grade
                    ORDER BY score DESC LIMIT 5';
$statement4 = $db->prepare($queryGradeUsers);
$statement4->bindValue(':grade', $grade);
$statement4->execute();
$usersByGrade = $statement4->fetchAll();
$statement4->closeCursor();

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <title>Quiz</title>
    <link rel="stylesheet" type="text/css" href="main.css" />
</head>

<body>
<header><h1>Quiz Results</h1></header>
<main> 
<div class="submissionPage">
	<p id="incorrect">Incorrect: <?php echo $numMissed?></p>
	<p id="correct">Correct: <?php echo $numCorrect?></p>
	<p id="total">Grade: <?php echo $score?></p>
</div>

<section>
	<h2>Your Points</h2>
	   <span><?php if($name)echo $name; ?>:</span>
	   <span><?php echo $scoreTotal; ?></span>
</section>

<section>
	<h2>High Scores</h2>
	<table>
	<?php foreach ($users as $user) : ?>
		<tr>
			<td><?php echo $user['user_name']; ?></td>
			<td><?php echo $user['score']; ?></td>
		</tr>
	<?php endforeach; ?>
	</table>
</section>

<section>
	<h2 id="hide">Return to Menu</h2>
	<a href="index.php">Main Menu</a>
</section>

</main>
<footer>
    <p>Project 2</p>
</footer>
</body>
</html>