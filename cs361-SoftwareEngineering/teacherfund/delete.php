<?php
	require_once('../mysqli_connect.php');

	if(!empty($_POST)){
		echo $_POST['id'] . '<br>';
		
		$query = 'DELETE FROM tf_login WHERE userID=?';
		
		$stmt = $dbc->prepare($query);
		
		$stmt->bind_param("s", $_POST['id']);

		$stmt->execute();

	}

	$query = "SELECT L.userID,  L.email, L.pass, U.f_name, U.l_name, U.userType FROM tf_login L
	INNER JOIN tf_users U ON L.userID = U.userID";

	$stmt = $dbc->prepare($query);

    $stmt->execute();

    $stmt->bind_result($id, $em, $pa, $fn, $ln, $ty);

	echo "<table><tr><th>userID</th><th>email</th><th>pass</th><th>First</th><th>Last</th><th>Type</th></tr>";

	$ids = [];

    while($stmt->fetch()){
		echo '<tr><td>'.$id.'</td><td>'.$em.'</td><td>'.$pa.'</td><td>'.$fn.'</td><td>'.$ln.'</td><td>'.$ty.'</td>';		
		array_push($ids, $id);
	}

	echo '</table>';

	echo "<br><br>";

	echo '<form method="post"><label>Delete User: </label><select name="id">';

	foreach ($ids as $i){
		echo '<option value="'.$i.'">'.$i.'</option>';
	}

	echo '</select><br><input type="submit" value="Delete">';
?>
