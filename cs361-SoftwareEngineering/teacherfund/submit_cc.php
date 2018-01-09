<?php
    require_once('../mysqli_connect.php');
?>

<!-- HTML for save cc -->

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
      <title>Save a Credit Card</title>
    </head>

  <body>
    <form method="post" action="profile.php">
        <legend></legend>
        <br>

          <?php
            if(!($stmt = $dbc->prepare("INSERT INTO tf_ccard(userID, cardNum, exp, type) VALUES (?,?,?,?)"))){
	            echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!($stmt->bind_param("iiss",$_POST['userID'],$_POST['cardNum'],$_POST['exp'],$_POST['type']))){
	            echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!$stmt->execute()){
	            echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
            } else {
	            echo "Credit card successfully added! Hooray!";
            }

					if(isset($_POST['userID'])) $id=$_POST['userID'];
					echo'<input type="hidden" name="userID" value="'.$id.'">
          ';
					?>
      <input type="submit" name="ccSubmit" value="Return to Profile">
    </form>
  </body>

</html>