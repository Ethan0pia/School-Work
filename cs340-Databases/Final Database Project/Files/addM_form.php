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
		<!--- add new site --->
    	<form method="post" action="addM.php">
        <fieldset>
            <legend>Add a Material Type Relationship</legend><br>
            Artifact FS Number: <select one name="fs">
		        <?php

					if(!($stmt = $mysqli->prepare("SELECT fs_number, description FROM artifacts"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($id, $des)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo '<option value="'.$id.'">'.$id.'-'.$des.'</option>\n';
					}
					$stmt->close();
					?>
				</select>
				Material Type: <select one name="mat">
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
        <input type="submit" name="addSubmit" value="Add Material Relationship">
    </form>
    <div><a href="/~dunhamet/databasefinal/main_page.php">Return to Homepage</a></div>
</body>
</html>

