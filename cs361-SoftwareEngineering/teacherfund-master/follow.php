<?php
        require_once('../mysqli_connect.php');

	
// query to find user id

if(!($stmt = $dbc->prepare("SELECT userID FROM tf_login WHERE email=?"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!($stmt->bind_param("s",$_POST['email']))){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
}
if(!$stmt->bind_result($userID)){
	echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
}
//assign user ID to $donorID for future use
while($stmt->fetch()){
	$donorID = $userID;
}
$stmt->close();

// query to insert into relationship table
if(!($stmt = $dbc->prepare("INSERT INTO tf_following(donorID, teacherID) VALUES (?,?)"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}
if(!($stmt->bind_param("ii",$donorID,$_POST['teacherID']))){
	//$donorID,$_POST['teacherID']
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}
if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
} else {
	//query to find teacher name
	echo "teacher followed";
}
echo'<form method="post" action="profile.php">
				<input type="hidden" name="userID" value="'.$donorID.'">
        <button type="submit">Return to Profile</button>
        </form>';
?>
