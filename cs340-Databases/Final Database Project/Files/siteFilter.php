<?php
	require_once('mysqli_connect.php');
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Search Database</title>
	<!--- style borrowed from www.textfixer.com --->
	<style type="text/css">
		table.gridtable {
			font-family: verdana,arial,sans-serif;
			font-size:11px;
			color:#333333;
			border-width: 1px;
			border-color: #666666;
			border-collapse: collapse;
		}
		table.gridtable th {
			border-width: 1px;
			padding: 8px;
			border-style: solid;
			border-color: #666666;
			background-color: #dedede;
		}
		table.gridtable td {
			border-width: 1px;
			padding: 8px;
			border-style: solid;
			border-color: #666666;
			background-color: #ffffff;
		}
	</style>
</head>
<body>
	<h2>Results</h2>
	<table class="gridtable">
		<tr>
			<th>Site Name</th>
			<th>Artifact FS #</th>
			<th>Description</th>
			<th>TU #</th>
			<th>TU Level</th>
			<th>Date Excavated</th>
		</tr>
		
		<?php
		if(!($stmt = $mysqli->prepare("SELECT s.name, a.fs_number, a.description, a.tu_number, a.tu_level, a.date_excavated
									FROM artifacts a INNER JOIN sites s ON a.site_id = s.id WHERE s.id=?"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}

		if(!($stmt->bind_param("s",$_POST['site']))){
			echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
		}

		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		if(!$stmt->bind_result($site_name, $fs_num, $desc, $tu_num, $tu_level, $date_ex)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $site_name . "\n</td>\n<td>\n" . $fs_num . "\n</td>\n<td>\n" . $desc . "\n</td>\n<td>\n";
			echo $tu_num . "\n</td>\n<td>\n" . $tu_level . "\n</td>\n<td>\n" . $date_ex . "\n</td>\n</tr>";
		}
		
		
		
		$stmt->close();
		?>
	</table><br>
	<a href="main_page.php">Main Page</a>
</body>
</html>