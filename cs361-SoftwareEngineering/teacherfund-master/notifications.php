<?php
	require_once('../mysqli_connect.php');
	if(!($stmt = $dbc->prepare("SELECT donorID FROM following WHERE teacherID=?"))){
		echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	}
	if(!($stmt->bind_param("sss",$_POST['teacherID']))){
		echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()){
		echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	}
	if(!$stmt->bind_result($donorID)){
		echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	}
	while($stmt->fetch()){
	  	if(!($stmt = $dbc->prepare("SELECT type, goal, description FROM tf_fund_request WHERE fundID=$fundID"))){
		  echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	 	 }
		  if(!$stmt->execute()){
			  echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		  }
    		  if(!$stmt->bind_result($type, $goal, $description)){
			  echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	  	}
		$stmt->close();
   		 if(!($stmt = $dbc->prepare("SELECT f_name, l_name FROM tf_users WHERE userID=$teacherID"))){
			  echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	 	 }
	 	 if(!$stmt->execute()){
			  echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
		  }
   		 if(!$stmt->bind_result($f_name, $l_name)){
		   	 echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	  	}
		$stmt->close();
        	if(!($stmt = $dbc->prepare("SELECT email FROM tf_users WHERE userID=$donorID"))){
			  echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	 	 }
	 	 if(!$stmt->execute()){
			  echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	  	}
    		if(!$stmt->bind_result($email)){
		    echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	 	 }
    		$stmt->close();
   	 	#send email with new temporary password
    		 $subject="New Fund for $f_name $l_name";
   		 $message="$f_name $l_name has posted a new fund. 
   		 They are trying to get \$$goal for $type.
  		 $description.";
  		 $var= $email;
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
	}
	$stmt->close();
	
?>
