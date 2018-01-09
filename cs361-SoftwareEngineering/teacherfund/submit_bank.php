<?php
    require_once('../mysqli_connect.php');
?>

<!-- HTML for add bank -->

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
      <title>Save a Bank</title>
    </head>

  <body>
    <form method="post" action="profile.php">
      <legend></legend>
      <br>

        <?php
		if(isset($_POST['userID'])) $id=$_POST['userID'];
		if(isset($_POST['checkAcct'])) $checkAcct=$_POST['checkAcct'];
		if(isset($_POST['routNum'])) $routNum=$_POST['routNum'];
		
		$sql = "INSERT INTO tf_bank(userID, checkAcct, routNum) 
		VALUES ($id,$checkAcct,$routNum)";

		if ($dbc->query($sql) === TRUE) {
			echo "Bank account successfully added! Hooray!";
		
			echo'<input type="hidden" name="userID" value="'.$id.'">
			';
		} else {
			echo "Error: " . $sql . "<br>" . $mysqli->error;
		}
					?>
        <input type="submit" name="ccSubmit" value="Return to Profile">
    </form>
  </body>

</html>
