<html>
<head>
    <title>School Added</title>
</head>
<body>
<?php


require_once('../mysqli_connect.php');

if(!empty($_POST['city']) && !empty($_POST['state']) && !empty($_POST['school'])){
	//if the addtype is new, add school info to db
	
	if(array_key_exists('newschool', $_POST)){
		$query = "INSERT INTO tf_schools (city, state, name) VALUES (?, ?, ?)";
		$stmt = $dbc->prepare($query);
		$stmt->bind_param("sss", $_POST['city'], $_POST['state'], $_POST['school']);

		if($stmt->execute()){
			echo "School Added";
    		
			//if we got an email, update the relationship
		    if(!empty($_POST['email'])){
				$query = 'INSERT INTO tf_teacher (teacherID, schoolID) VALUES(' . 
					'(SELECT userID FROM tf_login WHERE	userID="?")' . 
					'(SELECT schoolID FROM tf_schools WHERE state="?" AND city="?" AND name="?"))';
				$stmt = $dbc->prepare($query);
				$stmt->bind_param("ssss",$_POST['email'], $_POST['city'], $_POST['state'], $_POST['school']);
				echo " to your profile.";
			}  
		}
	}
}	
?>
</body>
</html>
