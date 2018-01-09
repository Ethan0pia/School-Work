	<form action="signup.php" method="post">

		<h3>Sign Up</h3>
		<br>	
		<label>First Name:</label>
		<br>
		<input type="text" name="f_name" size="30" maxlength="255" value="" />
		<br>	
		<label>Last Name:</label>
		<br>
		<input type="text" name="l_name" size="30" maxlength="255" value="" />
		<br>
		<label>About You:</label>
		<br>
		<input type="text" name="biography" size="10" value="" />
		<br>
		<label>I am a...</label><br>
		<input type="radio" name="usertype" value="donor" checked >Donor<br>
		<input type="radio" name="usertype" value="teacher">Teacher<br>
		<br>
		<label>Email:</label>
		<br>
		<input type="email" name="email" size="30" value="" />
		<br>
		<label>Password:</label>
		<br>
		<input class="pass" type="password" name="password" size="30" value="">
		<br><br>
		<label>Confirm Password:</label>
		<input class="pass" type="password" name="confirmpassword" size="30" value="">
		<br><br>
		<input id="submit" type="submit" name="submit" value="Sign Up" />
	</form>
<script>
	document.getElementById("submit").addEventListener("click", function(){
		var passwords = document.getElementsByClassName("pass");
			
		if(passwords[0].value != passwords[1].value){
			event.preventDefault();
			alert("Passwords must match");
		}

	});
</script>
