//Sources/helpful links: http://www.newthinktank.com/2014/09/php-mysql-tutorial/

<?php
// Get a connection to db
require_once('../mysqli_connect.php');

// Create a query for the database. First table starts here****************
$query = "SELECT userID, pass FROM tf_login";

// Get a response from the database
$response = @mysqli_query($dbc, $query);

// If the query executed properly, then do this
if($response){

echo '<table align="left"
cellspacing="5" cellpadding="8">

<tr><td align="left"><b>User ID</b></td>
<td align="left"><b>Password</b></td></tr>';

// mysqli_fetch_array will return a row of data
while($row = mysqli_fetch_array($response)){

//$query = "SELECT userID, userName, pass FROM tf_login"; Used for refernce.

echo '<tr><td align="left">' . 
$row['userID'] . '</td><td align="left">' . 
$row['pass'] . '</td><td align="left">';

echo '</tr>';
}

echo '</table>';

} else {

echo "Couldn't get database<br />";

echo mysqli_error($dbc);

}

//Second Table starts here****************************************
$query = "SELECT userID, email, biography, f_name, l_name  FROM tf_users";

// Get a response from the database
$response = @mysqli_query($dbc, $query);

// If the query executed properly, then do this
if($response){

echo '<table align="left"
cellspacing="5" cellpadding="8">
<tr><td align="left"><b>User ID</b></td>
<td align="left"><b>Email</b></td>
<td align="left"><b>Biography</b></td>
<td align="left"><b>First Name</b></td>
<td align="left"><b>Last Name</b></td></tr>';

// mysqli_fetch_array return row from query
while($row = mysqli_fetch_array($response)){

//$query = "SELECT userID, userName, pass FROM tf_login"; Used for refernce.

echo '<tr><td align="left">' . 
$row['userID'] . '</td><td align="left">' . 
$$row['email'] . '</td><td align="left">' . 
$row['biography'] . '</td><td align="left">' . 
$row['f_name'] . '</td><td align="left">' . 
$row['l_name'] . '</td><td align="left">';

echo '</tr>';
}

echo '</table>';

} else {

echo "Couldn't issue database<br />";

echo mysqli_error($dbc);

}
// Close connection to db
mysqli_close($dbc);

?>
