<?php
		require_once('../mysqli_connect.php');
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Profile</title>
</head>

<body>
<?php
		if(isset($_POST['email'])) $email=$_POST['email'];
		if(isset($_POST['userID'])) $userID=$_POST['userID'];

		if(!($stmt = $dbc->prepare("SELECT userID FROM tf_login WHERE email='$email' OR userID='$userID'"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}

		if(!$stmt->execute()){
			echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		}
		if(!$stmt->bind_result($id)){
			echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		}
		 while ($stmt->fetch()) {
		}
	
		if(!($stmt = $dbc->prepare("SELECT f_name, l_name FROM tf_users WHERE userID=$id"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}

		if(!$stmt->execute()){
			echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		}
		
		if(!$stmt->bind_result($f_name, $l_name)){
			echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		}
		while ($stmt->fetch()) {
		}


		echo "<h1>Welcome $f_name $l_name!</h1>";
		echo'<form method="post" action="save_cc.php">
				<input type="hidden" name="userID" value="'.$id.'">
        <button type="submit">Add a Credit Card</button>
        </form>';

		echo'<form method="post" action="save_bank.php">
				<input type="hidden" name="userID" value="'.$id.'">
        <button type="submit">Add a Bank Account</button>
        </form>';
			echo'<form method="post" action="add_donation.php">
				<input type="hidden" name="userID" value="'.$id.'">
        <button type="submit">Add a Fund</button>
        </form>';
	
	echo'<form method="post" action="easy_find.html">
				<input type="hidden" name="userID" value="'.$id.'">
        <button type="submit">Find a Teacher</button>
        </form>';

?>

</body>

</html> 
