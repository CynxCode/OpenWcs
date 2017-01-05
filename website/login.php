<?php
$username = $_POST["username"];
$password = $_POST["password"];

$pass = sha1($password); 

echo $pass;

if($username == "Admin" AND $pass=="8be3c943b1609fffbfc51aad666d0a04adf83c9d")
   {
   header("location: startpage.html");
   }
else
   {
   header("location: login_false.html");
   }

?>
