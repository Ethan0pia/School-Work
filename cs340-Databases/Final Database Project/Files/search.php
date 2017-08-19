<?php
	require_once('mysqli_connect.php');
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Search Database</title>
</head>
<body>
	<h2>Search for artifacts</h2>
	<div>
		<form method="post" action="siteFilter.php">
			<fieldset>
				<legend>Filter By Site</legend>
				Site Name: <select one name="site">
					<?php

						if(!($stmt = $mysqli->prepare("SELECT id, name FROM sites"))){
							echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
						}

						if(!$stmt->execute()){
							echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
						}
						if(!$stmt->bind_result($id, $name)){
							echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
						}
						while($stmt->fetch()){
						 echo '<option value="'.$id.'">'.$id.'-'.$name.'</option>\n';
						}
						$stmt->close();
						?>
					</select>
			</fieldset>
			<input type="submit" value="Search" />
		</form>
	</div>
	<br>
	<div>
		<form method="post" action="materialFilter.php">
			<fieldset>
				<legend>Filter By Material</legend>
				Material Name: <select one name="material">
					<?php

						if(!($stmt = $mysqli->prepare("SELECT id, name FROM materials"))){
							echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
						}

						if(!$stmt->execute()){
							echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
						}
						if(!$stmt->bind_result($id, $name)){
							echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
						}
						while($stmt->fetch()){
						 echo '<option value="'.$id.'">'.$name.'</option>\n';
						}
						$stmt->close();
						?>
					</select>
			</fieldset>
			<input type="submit" value="Search" />
		</form>
	</div>


</body>
<html>