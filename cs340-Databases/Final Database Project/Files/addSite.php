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

	if(isset($_POST['siteName'])) $siteName=$_POST['siteName'];
	if(isset($_POST['siteID'])) $siteID=$_POST['siteID'];
	if(isset($_POST['state'])) $state=$_POST['state'];

	$sql = "INSERT INTO sites (id, name, state)
	VALUES ('$siteID', '$siteName', '$state')";

	if ($mysqli->query($sql) === TRUE) {
	  echo "New record created successfully";
	} else {
	  echo "Error: " . $sql . "<br>" . $mysqli->error;
	}

	
	$sql = "INSERT INTO test_units (tu_number, site_id)
	VALUES ('Surface', '$siteID')";

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
