<html>
<head>
	<title>View Donations</title>
	<meta charset="UTF-8">	
</head>
<body>
	<table>
	<tr>
		<th>tf_login.email</th>
		<th>fundID</th>
		<th>type</th>
		<th>goal</th>
		<th>raised</th>
		<th>description</th>
	</tr>
	<?php
        
		require_once('../mysqli_connect.php');
		
			$query = 'SELECT L.email, F.fundID, F.type, F.goal, F.raised, F.description
					FROM tf_fund_request F INNER JOIN tf_login L on L.userID = F.userID 
					WHERE 1';
			$stmt = $dbc->prepare($query);
			
			if($stmt->execute()){
				
				$stmt->store_result();
				$stmt->bind_result($email, $id, $type, $goal, $raised, $desc);
				
				while($stmt->fetch()){
					echo '<tr><td>'.$email.'</td><td>'.$id.'</td><td>'.$type.'
						</td><td>'.$goal.'</td><td>'.$raisd.'</td><td>'.$desc.'
						</td></tr>';
				}
			}

		
	
	?>
	</table>
</body>
</html>

