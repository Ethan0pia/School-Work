<?php
        require_once('../mysqli_connect.php');
?>
	
<!DOCTYPE html>

  
<html>
<head>
    <meta charset="UTF-8">
    <title>Search Results</title>
</head>

<body>
    <h1>Results</h1>

    <table>
        <tr>
            <th>Teacher</th>
            <th>School</th>
            <th>City</th>
            <th>State</th>
        </tr>
			
<?php
	//updated to also select userID for purpose of creating HTML follow button
	if(!($stmt = $dbc->prepare("SELECT u.userID, u.l_name, s.name, s.city, s.state FROM tf_users u INNER JOIN
								tf_teaching t ON u.userID = t.teacherID INNER JOIN
								tf_schools s ON t.schoolID = s.schoolID
								WHERE u.l_name=? AND s.city=? AND s.state=?"))){
		echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	}
	if(!($stmt->bind_param("sss",$_POST['l_name'],$_POST['city'],$_POST['state']))){
		echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()){
		echo "Execute failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	}
	//updated to also bind userID to the result
	if(!$stmt->bind_result($userID, $l_name, $school, $city, $state)){
		echo "Bind failed: "  . $dbc->connect_errno . " " . $dbc->connect_error;
	}
	while($stmt->fetch()){
		echo "<tr>\n<td>\n" . $l_name . "\n</td>\n<td>\n" . $school . "\n</td>\n<td>\n" . $city . "\n</td>\n<td>\n" . $state . "\n</td>\n<td>\n";
		makeFollowButton($userID);
		echo "</td>\n</tr>\n";
	}
	$stmt->close();
	
	
	
	//makeFollowButton function creates an HTML button that adds a teacher to a user's follow list
	function makeFollowButton($id){ 
		echo "<form method='post' action='confirm.php'>\n";
		echo "<input type='hidden' name='id' value='" . $id . "'>";
		echo "<input type='submit' name='follow' value='Follow This Teacher'>\n";
		echo "</form>\n";
		
	}
	
?>

	</table>
</body>
</html>
