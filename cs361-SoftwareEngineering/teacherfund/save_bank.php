<?php
		require_once('../mysqli_connect.php');
?>

<!-- HTML for save bank -->

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Save Bank</title>
</head>

<body>
    <form method="post" action="submit_bank.php">
        <fieldset>
            <legend>Bank Information</legend><br>
					<?php
					if(isset($_POST['userID'])) $id=$_POST['userID'];
					echo'<input type="hidden" name="userID" value="'.$id.'">';
					?>
			Account Number: <input type="text" name="checkAcct"><br>
            Routing Number: <input type="text" name="routNum"><br> 
        </fieldset>
        <input type="submit" name="bankSubmit" value="submit">
    </form>
</body>

</html> 





