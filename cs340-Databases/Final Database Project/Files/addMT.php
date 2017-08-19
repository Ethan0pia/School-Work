<?php
	require_once('mysqli_connect.php');
?>

<!DOCTYPE html>
  
<html>
<head>
    <meta charset="UTF-8">
    <title>Artifact Database</title>
</head>

<body>	
	<?php

	if(isset($_POST['material'])) $material=$_POST['material'];

	$sql = "INSERT INTO materials (name)
	VALUES ('$material')";

	if ($mysqli->query($sql) === TRUE) {
	  echo "New record created successfully";
	} else {
	  echo "Error: " . $sql . "<br>" . $mysqli->error;
	}

	$mysqli->close();
?>

<script>window.open("main_page.php","_self");</script>


</body>
</html>
