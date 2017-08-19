<?php
	require_once('mysqli_connect.php');
?>

<html>
<head>
<title>Add Client</title>
</head>
<body>
<?php
		//Sources/helpful links: http://www.newthinktank.com/2014/09/php-mysql-tutorial/

		//get variables
        if(isset($_POST['site'])) $site=$_POST['site'];
		if(isset($_POST['tu'])) $tu=$_POST['tu'];
		if(isset($_POST['lvl'])) $lvl=$_POST['lvl'];
		if(isset($_POST['fs'])) $fs=$_POST['fs'];
		if(isset($_POST['description'])) $description=$_POST['description'];
		if(isset($_POST['date'])) $date=$_POST['date'];

		//add artifact to database
		$sql = "INSERT INTO artifacts (fs_number, description, tu_number, site_id,
				tu_level, date_excavated) VALUES ('$fs', '$description', '$tu', '$site', '$lvl', '$date')";

		if ($mysqli->query($sql) === TRUE) {
			echo "New record created successfully";
		} else {
			echo "Error: " . $sql . "<br>" . $mysqli->error;
		}


		//add material types to database
		foreach ($_POST['material'] as $mats)
		{
			//add mat
			$sql = "INSERT INTO artifact_materials (fs_number, material_id) VALUES ('$fs', '$mats')";
			if ($mysqli->query($sql) === TRUE) {
				echo "New record created successfully";
			} else {
				echo "Error: " . $sql . "<br>" . $mysqli->error;
			}
		}
?>

<script>window.open("main_page.php","_self");</script>

</body>
</html>
