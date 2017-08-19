<?php
	require_once('mysqli_connect.php');
?>


<!DOCTYPE html>

  
<html>
<head>
    <meta charset="UTF-8">
    <title>Artifact Database</title>
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
	    <!--- filter options --->
	    <form method="get" action="search.php">
        <button type="submit">Search Database</button>
        </form>
	
	<!--- SITES table --->
	<h2>SITES</h2>
	<table class="gridtable">
		<tr>
			<th>Site Number</th>
			<th>Site Name</th>
			<th>State</th>
		</tr>
		
	<?php
		//dynamically populate table
		//step 1 - prepare statement using SQL query
		if(!($stmt = $mysqli->prepare("SELECT id, name, state FROM sites"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}
		
		//step 2 - bind parameters to SQL query (if necessary)
		
		//step 3 - execute query
		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 4 - bind the results of the query to variables that can be used to build html
		if(!$stmt->bind_result($id, $name, $state)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 5 - fetch statement goes through each returned row in result and information can be accessed
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $id . "\n</td>\n<td>\n" . $name . "\n</td>\n<td>\n" . $state . "\n</td>\n</tr>\n";
		}
		
		//step 6 - close statement
		$stmt->close();
		
		?>
	</table>
	        <!--- add site --->
    	<form method="get" action="addSite.html">
        <button type="submit">Add Site</button>
        </form>
		<!--- edit site --->
    	<form method="get" action="editSt.php">
        <button type="submit">Edit Site</button>
        </form>
        
        
    	<!--- Test Units table --->
	<h2>TEST UNITS</h2>
	<table class="gridtable">
		<tr>
			<th>Test Unit #</th>
			<th>Site #</th>
		</tr>
		
	<?php
		//dynamically populate table
		//step 1 - prepare statement using SQL query
		if(!($stmt = $mysqli->prepare("SELECT tu_number, site_id FROM test_units"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}
		
		//step 2 - bind parameters to SQL query (if necessary)
		
		//step 3 - execute query
		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 4 - bind the results of the query to variables that can be used to build html
		if(!$stmt->bind_result($tu_number, $site_id)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 5 - fetch statement goes through each returned row in result and information can be accessed
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $tu_number . "\n</td>\n<td>\n" . $site_id . "\n</td>\n</tr>\n";
		}
		
		//step 6 - close statement
		$stmt->close();
		
		?>
	</table>
	
	        <!--- add Test Unit --->
    	<form method="get" action="addTU_form.php">
        <button type="submit">Add Test Unit</button>
        </form>
	
	
	<!--- ARTIFACTS table --->
	<h2>ARTIFACTS</h2>
	<table class="gridtable">
		<tr>
			<th>FS #</th>
			<th>Test Unit ID</th>
			<th>TU Level</th>
			<th>Site ID</th>
			<th>Date Excavated</th>
			<th>Description</th>
		</tr>
		
		<?php
		//dynamically populate table
		//step 1 - prepare statement using SQL query
		if(!($stmt = $mysqli->prepare("SELECT fs_number, tu_number, tu_level, site_id, date_excavated, description FROM artifacts"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}
		
		//step 2 - bind parameters to SQL query (if necessary)
		
		//step 3 - execute query
		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 4 - bind the results of the query to variables that can be used to build html
		if(!$stmt->bind_result($fs_number, $tu_number, $tu_level, $site_id, $date_excavated, $description)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 5 - fetch statement goes through each returned row in result and information can be accessed
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $fs_number . "\n</td>\n<td>\n" . $tu_number . "\n</td>\n<td>\n" . $tu_level . "\n</td>\n<td>\n";
			echo $site_id . "\n</td>\n<td>\n" . $date_excavated . "\n</td>\n<td>\n" . $description . "\n</td>\n</tr>\n";
		}
		
		//step 6 - close statement
		$stmt->close();
		
		?>
	</table>
	
	    	<!--- add artifact --->
    	<form method="get" action="enterSite.php">
        <button type="submit">Add Artifact</button>
        </form>

	<!--- MATERIAL table --->
	<h2>ARTIFACT MATERIALS</h2>
	<table class="gridtable">
		<tr>
			<th>Artifact FS #</th>
			<th>Material ID #</th>
		</tr>
		
	<?php
		//dynamically populate table
		//step 1 - prepare statement using SQL query
		if(!($stmt = $mysqli->prepare("SELECT am.fs_number, m.id FROM artifact_materials 
		                                am INNER JOIN materials m ON am.material_id = m.id"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}
		
		//step 2 - bind parameters to SQL query (if necessary)
		
		//step 3 - execute query
		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 4 - bind the results of the query to variables that can be used to build html
		if(!$stmt->bind_result($fs_number, $id)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 5 - fetch statement goes through each returned row in result and information can be accessed
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $fs_number . "\n</td>\n<td>\n" . $id . "\n</td>\n</tr>\n";
		}
		
		//step 6 - close statement
		$stmt->close();
		
		?>
	</table>
		<!--- add material relationship --->
    	<form method="get" action="addM_form.php">
        <button type="submit">Add Material Artifact Relationship</button>
        </form>

		<!--- MATERIAL TYPES table --->
	<h2>MATERIAL TYPES</h2>
	<table class="gridtable">
		<tr>
			<th>Material ID #</th>
			<th>Material Type/Name</th>
		</tr>
		
	<?php
		//dynamically populate table
		//step 1 - prepare statement using SQL query
		if(!($stmt = $mysqli->prepare("SELECT id, name FROM materials"))){
			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
		}
		
		//step 2 - bind parameters to SQL query (if necessary)
		
		//step 3 - execute query
		if(!$stmt->execute()){
			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 4 - bind the results of the query to variables that can be used to build html
		if(!$stmt->bind_result($id, $name)){
			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
		}
		
		//step 5 - fetch statement goes through each returned row in result and information can be accessed
		while($stmt->fetch()){
			echo "<tr>\n<td>\n" . $id . "\n</td>\n<td>\n" . $name . "\n</td>\n</tr>\n";
		}
		
		//step 6 - close statement
		$stmt->close();
		
		?>
	</table>
		<!--- add material Type --->
    	<form method="get" action="addMT.html">
        <button type="submit">Add Material Type</button>
        </form>

		<!--- Remove many to many--->
    	<form method="get" action="removeMT_form.php">
        <button type="submit">Remove Material Type (Many to Many)</button>
        </form>
	
</body>
</html>

