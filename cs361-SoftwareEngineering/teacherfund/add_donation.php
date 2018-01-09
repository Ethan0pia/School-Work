<html>
<head>
<title>Add Student</title>
</head>
<body>
<?php
$userID;
//test
if(isset($_POST['email']))
{
	$email=$_POST['email']
	$userID="SELECT user_id FROM tf_login WHERE email=".$email."";
}

    
if(isset($_POST['submit'])){
	//sets email from incoming user. Not checked because it is assumed that user will come in already with email.

    $data_missing = array();
    
    if(empty($_POST['type'])){

        // Adds name to array
        $data_missing[] = 'type';

    } else {

        // Trim white space 
        $f_name = trim($_POST['type']);

    }

    if(empty($_POST['goal'])){

        // Adds goal to array
        $data_missing[] = 'goal';

    } else{

        // Trim white space
        $l_name = trim($_POST['goal']);

    }

    if(empty($_POST['description'])){

        // Adds description to array
        $data_missing[] = 'description';

    } else {

        // Trim white space
        $email = trim($_POST['description']);

    }
    
    if(empty($data_missing)){
        
        require_once('../mysqli_connect.php');
        
        $query = "INSERT INTO tf_fund_request (userID, type, goal, description) VALUES (?, ?, ?, ?)";
        
        $stmt = mysqli_prepare($dbc, $query);
        
        mysqli_stmt_bind_param($stmt, "isis", $userID, $type,
                               $goal, $description);
        
        mysqli_stmt_execute($stmt);
        
        $affected_rows = mysqli_stmt_affected_rows($stmt);
        
        if($affected_rows == 1){
            
            echo 'Donation Entered';
            
            mysqli_stmt_close($stmt);
            
            mysqli_close($dbc);
            
        } else {
            
            echo 'Error Occurred<br />';
            echo mysqli_error();
            
            mysqli_stmt_close($stmt);
            
            mysqli_close($dbc);
            
        }
        
    } else {
        
        echo 'You need to enter the following data<br />';
        
        foreach($data_missing as $missing){
            
            echo "$missing<br />";
            
        }
        
    }
    
}

?>

<form action="add_donation.php" method="post">
    
    <b>Add a Donation Post Request</b>
    
<p>Type:
<input type="text" name="type" size="30" value="" />
</p>

<p>Goal:
<input type="text" name="goal" size="30" value="" />
</p>

<p>Description:
<input type="text" name="description" size="30" value="" />
</p>
<p>
    <input type="submit" name="submit" value="Send" />
</p>
    
</form>
<form method="post" action="profile.php">
	<input type="hidden" name="userID" value="'.$userID.'">
        <button type="submit">Return to Profile</button>
        </form>';
</body>
</html>


