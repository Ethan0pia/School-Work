<?php
	require_once('mysqli_connect.php');
?>


<!DOCTYPE html>

  
<html>
<head>
    <meta charset="UTF-8">
    <title>Add Artifact</title>
	</style>
</head>

<body>
<form method="post" action="addArt.php">
        <fieldset>
            <legend>Add an Artifact</legend><br>
					<?php
					$site = $_POST['site'];
					 echo 'Site: <input type="hidden" name="site" value="'.$site.'">'.$site.'</option>';
					?>
				<br>
				 

			   Test Unit Number:<select id="tu" name="tu">
					<?php
					$site = $_POST['site'];
					if(!($stmt = $mysqli->prepare("SELECT tu_number FROM test_units WHERE site_id='$site'"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($number)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo '<option value="'.$number.'">'.$number.'</option>\n';
					}
					$stmt->close();
					?>
				</select><br>
			
            Test Unit Level: <input type="text" name="lvl"><br>
            Artifact FS Number: <input type="text" name="fs"><br>

            Material (ctrl+click to select multiple)<br><select multiple name="material[]">
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
				<br>
				Description: <input type="text" name="description"><br>
				Date: <input type="date" name="date"><br>
        </fieldset>
        <input type="submit" name="addSubmit" value="Add Artifact">
    </form>
	<br>
	<div><a href="/~dunhamet/databasefinal/main_page.php">Return to Homepage</a></div>
</body>
</html>

