<?php
	require_once('mysqli_connect.php');
?>
<!DOCTYPE html>

  
<html>
<head>
    <meta charset="UTF-8">
    <title>Add Artifact</title>
	</style>
</head>

<body>
<form method="post" action="edit.php">
        <fieldset>
            <legend>Edit Site Information</legend><br>
					<?php
					$site = $_POST['site'];
					 echo 'Site Number: <input name="site" value="'.$site.'"><input name="oldSite" type="hidden" value="'.$site.'">';
					 
					?>
					<br>
					<?php
					$site = $_POST['site'];
					if(!($stmt = $mysqli->prepare("SELECT name FROM sites WHERE id='$site'"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($name)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo 'Site Name: <input type="text" name="name" value="'.$name.'"><br>';
					}
					$stmt->close();

					if(!($stmt = $mysqli->prepare("SELECT state FROM sites WHERE id='$site'"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
					}

					if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					if(!$stmt->bind_result($state)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
					}
					while($stmt->fetch()){
					 echo 'State: <select name="state"><option value="'.$state.'">'.$state.'</option>
                <option value="AL">AL</option><option value="AK">AK</option>
                <option value="AZ">AZ</option><option value="AR">AR</option>
                <option value="CA">CA</option><option value="CO">CO</option>
                <option value="CT">CT</option><option value="DE">DE</option>
                <option value="DC">DC</option>
                <option value="FL">FL</option><option value="GA">GA</option>
                <option value="HI">HI</option><option value="ID">ID</option>
                <option value="IL">IL</option><option value="IN">IN</option>
                <option value="IA">IA</option><option value="KS">KS</option>
                <option value="KY">KY</option><option value="LA">LA</option>
                <option value="ME">ME</option><option value="MD">MD</option>
                <option value="MA">MA</option><option value="MI">MI</option>
                <option value="MN">MN</option><option value="MS">MS</option>
                <option value="MO">MO</option><option value="MT">MT</option>
                <option value="NE">NE</option><option value="NV">NV</option>
                <option value="NH">NH</option><option value="NJ">NJ</option>
                <option value="NM">NM</option><option value="NY">NY</option>
                <option value="NC">NC</option><option value="ND">ND</option>
                <option value="OH">OH</option><option value="OK">OK</option>
                <option value="OR">OR</option><option value="PA">PA</option>
                <option value="PR">PR</option>
                <option value="RI">RI</option><option value="SC">SC</option>
                <option value="SD">SD</option><option value="TN">TN</option>
                <option value="TX">TX</option><option value="UT">UT</option>
                <option value="VT">VT</option><option value="VA">VA</option>
                <option value="WA">WA</option><option value="WV">WV</option>
                <option value="WI">WI</option><option value="WY">WY</option>
                </select>';
					}
					$stmt->close();
					?>
        </fieldset>
        <input type="submit" name="addSubmit" value="Confirm Site Edit">
    </form>
	<br>
	<div><a href="main_page.php">Return to Homepage</a></div>
</body>
</html>

