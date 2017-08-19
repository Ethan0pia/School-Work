<!DOCTYPE html>
<html>
<head>
<title>Sign Up</title>
</head>
<body>
<?php

if(isset($_POST['submit'])){
    
    $data_missing = array();
    
    if(empty($_POST['email'])){
        // Adds name to array
        $data_missing[] = 'email';
    } else {

        // Take off white space from the email and store in email
        $email = trim($_POST['email']);
    }



    if(empty($_POST['f_name'])){
        // Adds name to array
        $data_missing[] = 'f_name';
    } else {
        // Take off white space from the f_name and add to f_name
        $f_name = trim($_POST['f_name']);
    }

    if(empty($_POST['l_name'])){
        // Adds name to array
        $data_missing[] = 'l_name';
    } else {
        // Take off white space from the l_name and add to l_name
        $l_name = trim($_POST['l_name']);
	}

	if(empty($_POST['password'])){
        // Adds name to array
        $data_missing[] = 'password';
    } else {
        // Take off white space from the l_name and add to l_name
        $password = trim($_POST['password']);
    }
    
	if(empty($_POST['usertype'])){
        // Adds name to array
        $data_missing[] = 'usertype';
    } else {
        // Take off white space from the l_name and add to l_name
        $usertype = trim($_POST['usertype']);
	}
    
	// Take off white space from the biography and store in biography
    $biography = trim($_POST['biography']);

//***************************************************************************************************
    
    if(empty($data_missing)){

      	require_once('../mysqli_connect.php');
	  
		$query = "INSERT INTO tf_login (pass, email) VALUES (?, ?)";
        $stmt = mysqli_prepare($dbc, $query);
        $stmt->bind_param("ss", $password, $email);
        
		mysqli_stmt_execute($stmt);
        
        $affected_rows = mysqli_stmt_affected_rows($stmt);
        
        if($affected_rows == 1){
        	$query = "INSERT INTO tf_users (biography, f_name, l_name, userType, userID)"
			. "VALUES (?, ?, ?, ?, (SELECT userID FROM tf_login WHERE email = ?))";
        	
			$stmt = mysqli_prepare($dbc, $query);
        	$stmt->bind_param("sssss", $biography, $f_name, $l_name, $usertype, $email);
       
       		$stmt->execute();

        	if( 1 == mysqli_stmt_affected_rows($stmt)) {
            	echo 'Thanks for joining Teacher Fund!';
			
				if($usertype == "teacher"){
					echo '<p><a href="addschool.php">Click here</a> to add your school.</p>';
				}
			
			}
            
        } else {
            echo 'Error Occurred<br />';
            echo mysqli_error();
			include "signup_form.php";
        }
            
        mysqli_stmt_close($stmt);
            
        mysqli_close($dbc);
        
    } else {
        
        echo 'You need to enter this data that was missing<br />';
        
        foreach($data_missing as $missing){
            
            echo "$missing<br />";
			include "signup_form.php";
            
        }
        
    }
    
} else {
	include "signup_form.php";
}

?>    
</body>
</html>
