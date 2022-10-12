<?php
require_once('database.php');

// Get category ID and grade level
$name = filter_input(INPUT_POST, 'name');
$categoryID = filter_input(INPUT_POST, 'subjectList', FILTER_VALIDATE_INT);
$grade = filter_input(INPUT_POST, 'grade_level', FILTER_VALIDATE_INT);
if ($categoryID == NULL || $categoryID == FALSE){
	$categoryID = 1;
}
if ($grade == NULL || $grade == FALSE){
	$grade = 1;
}
if ($name == NULL || $name == FALSE){
	$name = "";
}


// Get questions for selected category
$queryQuestions = 'SELECT * FROM question
                  WHERE category_id = :categoryID AND grade_level = :grade
                  ORDER BY question_id';
$statement3 = $db->prepare($queryQuestions);
$statement3->bindValue(':categoryID', $categoryID);
$statement3->bindValue(':grade', $grade);
$statement3->execute();
$questions = $statement3->fetchAll();
$statement3->closeCursor();
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <title>Quiz</title>
    <link rel="stylesheet" type="text/css" href="main.css" />
</head>

<body>
<header><h1>Quiz</h1></header>
<main>
 <form action="submit_quiz.php" method="post"
              id="submit_quiz">
	<input type="hidden" name="cat_id"
        value="<?php echo $categoryID; ?>">
    <input type="hidden" name="grade"
         value="<?php echo $grade; ?>">
	<input type="hidden" name="name"
         value="<?php echo $name; ?>">
	
	<?php $counter = 1;?>
		<?php foreach ($questions as $question) : ?>
		<?php $answer = "answer" . $counter;?>
			<p><?php echo $counter . ". " . $question['question_text']; ?></p>
			<input type="text" name="<?php echo "answer" . $counter;?>" value="">
		<?php $counter++;?>
	<?php endforeach; ?>
	<br><br>
	
	<input type="submit" name="submitQuiz" value="Submit">
	</form>
</main>
<footer>
    <p>Project 2</p>
</footer>
</body>
</html>