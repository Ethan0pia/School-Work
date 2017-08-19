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
    <form method="post" action="submit_cc.php">
        <fieldset>
            <legend>Credit Card Information</legend><br>
			
					<?php
					if(isset($_POST['userID'])) $id=$_POST['userID'];
					echo'<input type="hidden" name="userID" value="'.$id.'">';
					?>
				</select><br>
			Card Type: <select name="type" value="choose one">
				<option>Choose One</option>
                <option name="visa">Visa</option>
                <option name="mastercard">Mastercard</option>
                <option name="amex">American Express</option>
                <option name="discover">Discover</option></select><br>
            Card Number: <input type="text" name="cardNum"><br>
            Exp Date: <input type="text" name="exp" value="mm/yy">
        </fieldset>
        <input type="submit" name="ccSubmit" value="submit">
    </form>
</body>

</html> 


