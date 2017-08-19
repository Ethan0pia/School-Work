//Sources/helpful links: http://www.newthinktank.com/2014/09/php-mysql-tutorial/

<html>
<head>
<title>Add Client</title>
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

    if(empty($_POST['biography'])){

        // Adds name to array
        $data_missing[] = 'biography';

    } else{

        // Take off white space from the biography and store in biography
        $biography = trim($_POST['biography']);

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
//***************************************************************************************************
    
    if(empty($data_missing)){
        
        require_once('../mysqli_connect.php');
        
        $query = "INSERT INTO tf_users (email, biography, f_name,
        l_name) VALUES (?, ?, ?, ?)";
        
        $stmt = mysqli_prepare($dbc, $query);
        
        mysqli_stmt_bind_param($stmt, "ssss", $email,
                               $biography, $f_name, $l_name);
        
        mysqli_stmt_execute($stmt);
        
        $affected_rows = mysqli_stmt_affected_rows($stmt);
        
        if($affected_rows == 1){
            
            echo 'Client Entered';
            
            mysqli_stmt_close($stmt);
            
            mysqli_close($dbc);
            
        } else {
            
            echo 'Error Occurred<br />';
            echo mysqli_error();
            
            mysqli_stmt_close($stmt);
            
            mysqli_close($dbc);
            
        }
        
    } else {
        
        echo 'You need to enter this data that was missing<br />';
        
        foreach($data_missing as $missing){
            
            echo "$missing<br />";
            
        }
        
    }
    
}

?>

<form action="/~robertky/cs361/clientadd.php" method="post">
    
<b>Add a New Client</b>
    
<p>Email:
<input type="text" name="email" size="30" value="" />
</p>

<p>Biography:
<input type="text" name="biography" size="100" value="" />
</p>

<p>First Name:
<input type="text" name="f_name" size="30" maxlength="255" value="" />
</p>

<p>Last Name:
<input type="text" name="l_name" size="30" maxlength="255" value="" />
</p>

<p>
    <input type="submit" name="submit" value="Send" />
</p>
    
</form>
</body>
</html>
