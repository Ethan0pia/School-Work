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
    	<form method="post" action="addTU.php">
        <fieldset>
            <legend>Add a Test Unit</legend><br>
			Test Unit Number:<input type="text" name="tu"><br>
            Site Number <select one name="site">
		        <?php

					if(!($stmt = $mysqli->prepare("SELECT id FROM sites"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($name)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo '<option value="'.$name.'">'.$name.'</option>\n';
					}
					$stmt->close();
					?>
				</select>
        </fieldset>
        <input type="submit" name="addSubmit" value="Add Test Unit">
    </form>
</body>
</html>

