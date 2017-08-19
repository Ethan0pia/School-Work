<?php
        require_once('../mysqli_connect.php');	
?>

<!DOCTYPE html>
<html>
<head>
<title>Login</title>
</head>
<body>

<?php

if( !empty($_POST)) {

	$data_missing = array();
    
	if(empty($_POST['email'])){
        // Adds name to array
        $data_missing[] = 'email';
    } else {
        // Take off white space from the email and store in email
        $email = trim($_POST['email']);
    }
    
	if(empty($_POST['password'])){
        // Adds name to array
        $data_missing[] = 'password';
    } else {
        // Take off white space from the biography and store in biography
        $password = trim($_POST['password']);
    }

//***************************************************************************************************
    
    if(empty($data_missing)){
        
        $query = "SELECT pass FROM `tf_login` WHERE email = ?";
       
        $stmt = $dbc->prepare($query);
        
		$stmt->bind_param("s", $email);
        
        $stmt->execute();

		$stmt->store_result();

		if($stmt->num_rows){
    
			$stmt->bind_result($col1);

			$stmt->fetch();

			if( 0 == strcmp($password, $col1) ){
						
						echo'
						<form action="profile.php" method="post" id="form">
							<input type="hidden" name="email" value="'.$email.'">
						</form>

						<script>
							document.getElementById("form").submit();
						</script>
						';

            }
			else {
				echo "<h3>Hmmm...</h3><p>Passwords do not match.</p>";
				include "login_form.php";
			}
            
        } else {
            
            echo '<h3>Sorry</h3><p>User email could not be found<p>';
			include "login_form.php";
        }    
           $stmt->close(); 
           $dbc->close();
        
    } else {
        
        echo 'You need to enter this data that was missing<br />';
        
        foreach($data_missing as $missing){
            
            echo "$missing<br />";
           	include "login_form.php"; 
        }   
    }
}
else {
	echo "<h3>Login:</h3><p>Enter your username and password.</p>";
	include "login_form.php";
}
?>

</body>
</html>
