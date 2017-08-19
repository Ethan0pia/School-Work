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
    	<form method="post" action="removeMT.php">
        <fieldset>
            <legend>Add a Material Type Relationship</legend><br>
            Material Name/Type: <select one name="name">
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
        </fieldset>
        <input type="submit" name="removeSubmit" value="Remove Material Type and all Relationships associated with it.">
</body>
</html>

