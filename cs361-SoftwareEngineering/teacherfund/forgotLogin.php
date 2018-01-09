<?php
        require_once('../mysqli_connect.php');	
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Forgot Login Info</title>
</head>

<?php
#source:https://stackoverflow.com/questions/16737910/generating-a-random-unique-8-character-string-using-mysql
$var = $_POST["email"];
#generates new password
$newPass=uniqid();


#updates table with new info
$query = "UPDATE `tf_login` SET pass='$newPass' WHERE email='$var'";
$response = @mysqli_query($dbc, $query) or die(mysql_error());
	
#send email with new temporary password
$subject="Password Reset";
$message="Your new password is: $newPass.";
$var= $_POST["email"];
#source:https://www.sitepoint.com/sending-emails-php-phpmailer/ 
require_once "vendor/autoload.php";
$mail = new PHPMailer;
$mail->SMTPDebug = 0;                              
$mail->isSMTP();                                    
$mail->Host = "smtp.gmail.com";
$mail->SMTPAuth = true;                          
$mail->Username = "teacherfunds@gmail.com";                 
$mail->Password = "ethandunham";                           
$mail->SMTPSecure = "tls";                           
$mail->Port = 587;                                   
$mail->From = "TeachersFund@gmail.com";
$mail->FromName = "Teacher's Fund";
$mail->addAddress($var, " ");
$mail->isHTML(true);
$mail->Subject = $subject;
$mail->Body = $message;
$mail->send()
?>
<script>window.open("login.php","_self")</script>
</body>
</html>