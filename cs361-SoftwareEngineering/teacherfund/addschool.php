<?php
        require_once('../mysqli_connect.php');	
?>

<html>
<head>
	<title>Add School</title>
</head>
<body>
<?php

	$query = "SELECT state, city, name FROM tf_schools";

	$stmt = $dbc->prepare($query);

	$stmt->execute();

	$stmt->bind_result($state, $city, $school);

	while($stmt->fetch()){

		if(empty($schools[$state][$city])){
			$schools[$state][$city] = array();
		}
		array_push( $schools[$state][$city], $school);	
	}

	$schoolJSON = json_encode($schools);
?>

<label>Email: </label><input type="email" id="email" name="email">
<p>Select your school you teach at. If your's is not available, add it to the list</p>
<form id="oldschool" method="POST" action="schooladded">
	<fieldset>
	<legend>Select Existing School</legend>
	<label>State: </label><select id="states" name="state" ></select><br>
	<label>City: </label><select id="cities" name="city" hidden></select><br>
	<label>School: </label><select id="schools" name="school"  hidden></select><br>
	<input type="submit">
	</fieldset>
</form>
<form id="newschool" method="POST" action="schooladded">
	<fieldset>
	<legend>Add New School</legend>
		<label>State: </label>
		<select name="state">
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
        </select><br>
		<label>City: </label>
		<input type="text" name="city"><br>	
		<label>School: </label>
		<input type="text" name="school"><br>
		<input type="submit" id="newschoolsubmit">
		<input type="hidden"  name="newschool">	
	</fieldset>
</form>

<script>
	//gets schoolJSON object from PHP
	var schoolsObj = JSON.parse('<?php echo $schoolJSON ?>');
	console.log(schools);


	//populate states dropdown menu
	var states = document.getElementById("states");
	for(state in schoolsObj){
		createOption(states, state);
	}
	states.selectedIndex = -1;
	

	//populate cities dropdown when city is selected
	states.onchange = function() {
		var cities = document.getElementById("cities");
		cities.style.display = "inline";
		cities.innerHTML = "";
		for(city in schoolsObj[states.value]){
			createOption(cities, city);
		}
		cities.selectedIndex = -1;
	};

	//populate schools dropdown when state is selected
	cities.onchange = function() {
		var city = document.getElementById("cities");
		var schools = document.getElementById("schools");
		schools.style.display = "inline";
		schools.innerHTML = "";
		var l = schoolsObj[states.value][city.value].length;
		for(var i=0; i < l; i++){
			createOption(schools, schoolsObj[states.value][city.value][i]);
		}
		schools.selectedIndex = -1; 
	};

	//make sure email entered
/*	document.addEventListener("click", function(){
		if(event.target.type == "submit") {
			if(document.getElementById("email").value == ""){
				alert("Please enter your email address");
				event.preventDefault();
			}
		}
	});
*/
	/************** function definitions *****************/
	
	//populates a select node "obj"  with option "value"
	function createOption(obj, value){
		obj.append(document.createElement("option"));
		obj.lastElementChild.value = value;
		obj.lastElementChild.textContent = value;
	}

</script>

</body>
</html>
