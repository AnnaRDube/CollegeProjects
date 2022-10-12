<?php
require('database.php');
$query = 'SELECT *
          FROM category
          ORDER BY category_id';
$statement = $db->prepare($query);
$statement->execute();
$categories = $statement->fetchAll();
$statement->closeCursor();

$query2 = 'SELECT *
          FROM grade
          ORDER BY grade_id';
$statement2 = $db->prepare($query2);
$statement2->execute();
$grades = $statement2->fetchAll();
$statement2->closeCursor();
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
    <form action="start_quiz.php" method="post"
              id="start_quiz">
    <section>
	<h2>Name</h2>
	<input type="text" name="name" value="">
	</section>
	<hr>	
	<section>
		<h2>Grade Level</h2>
		<select name="grade_level">
			<option>Select Grade Level</option>
			<?php foreach ($grades as $grade) : ?>
                <option value="<?php echo $grade['grade_id']; ?>">
                    <?php echo $grade['grade_text']; ?>
                </option>
            <?php endforeach; ?>
		</select>
	</section>
	
	<section>
	<hr>
	<h2>Subject</h2>
	   <select name="subjectList">
			<option>Select Subject</option>
            <?php foreach ($categories as $category) : ?>
                <option value="<?php echo $category['category_id']; ?>">
                    <?php echo $category['category_name']; ?>
                </option>
            <?php endforeach; ?>
       </select><br>
	</section>
	
	<div><p>Points are assigned based on difficulty. Example: A 3rd grade question is worth 3 points. A 4th grade question is worth 4 points, etc.</p>
	</div>
	
	<div>
	<input type="submit" name="Start" value="Start">
	</div>
</form>
</main>
<footer>
    <p>Project 2</p>
</footer>
</body>
</html>