<?php


$conn = mysqli_connect("localhost","angel.rivera","5jtz1CAB5vND24yr","angelrivera");



$name= $_POST['name'];
$email= $_POST['email'];
$subject= $_POST['subject'];
$message= $_POST['message'];

$sql = "INSERT INTO `tbl_contact` (`Id`, `fldName`, `fldEmail`, `fldPhone`, `fldMessage`) VALUES ('0', '$name', '$email', '$subject', '$message')";

$rs = mysqli_query($conn, $sql);


?>