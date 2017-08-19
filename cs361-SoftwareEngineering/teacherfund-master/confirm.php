<?php
        require_once('../mysqli_connect.php');
	
?>


<!DOCTYPE html>

  
<html>
<head>
    <meta charset="UTF-8">
    <title>Confirm</title>
</head>

<body>
	<h3>Please enter email to confirm</h3>
	<form method="post" action="follow.php">
		Email:<input type="text" name="email">
		<input type="hidden" name="teacherID" value="<?php echo $_POST['id']; ?>">
		<input type="submit">
	</form>


</body>
</html>
