<?php
$username = $_POST["username"];
$password = $_POST["password"];
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
