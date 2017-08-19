<!DOCTYPE html>
  
<html>
<head>
    <meta charset="UTF-8">
    <title>Artifact Database</title>
</head>

<body>	
	<?php
	require_once('mysqli_connect.php');

	if(isset($_POST['site'])) $site=$_POST['site'];
	if(isset($_POST['tu'])) $tu=$_POST['tu'];

	$sql = "INSERT INTO test_units (tu_number, site_id)
	VALUES ('$tu','$site')";

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
