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

	if(isset($_POST['oldSite'])) $oldSite=$_POST['oldSite'];
	if(isset($_POST['site'])) $site=$_POST['site'];
	if(isset($_POST['name'])) $name=$_POST['name'];
	if(isset($_POST['state'])) $state=$_POST['state'];

	$sql = "UPDATE sites SET id='$site', name='$name', state='$state' where id='$oldSite'";

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
