<?php
$servername = "sql305.epizy.com";
$username = "epiz_33990739";
$password = "pGutYtN6OfOF";
$dbname = "epiz_33990739_Resume";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "sent successfully";
?>