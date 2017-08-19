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

	if(isset($_POST['mat'])) $mat=$_POST['mat'];
	if(isset($_POST['fs'])) $fs=$_POST['fs'];

	$sql = "INSERT INTO artifact_materials (fs_number, material_id)
	VALUES ('$fs', '$mat')";

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
