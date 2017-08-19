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
    <form method="post" action="editSite.php">
        			Site Number:<select id="site" name="site">
					<?php
					if(!($stmt = $mysqli->prepare("SELECT id FROM sites"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($id)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo '<option value="'. $id . '"> ' . $id . '</option>\n';
					}
					$stmt->close();
					?>
				</select>
        <button type="submit">Edit</button>
    </form>

</body>
</html>
