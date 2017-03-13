<?php
$temp = trim($_POST['username']);
$temp = mysql_real_escape_string($temp);
$username = utf8_decode($temp);
$temp = trim($_POST['password']);
$temp = mysql_real_escape_string($temp);
$password = utf8_decode($temp);
$pass = hash ( "sha256" , $password , false );

if($username == "Admin" AND $pass=="e7cf3ef4f17c3999a94f2c6f612e8a888e5b1026878e4e19398b23bd38ec221a")
   {
  session_start();
  $_SESSION['login_user'] = true;
   header("location: startpage.php");
   }
else
   {
   header("location: login_false.php");
   session_destroy();
   }
?>
