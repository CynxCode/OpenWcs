<!-- https://www.youtube.com/watch?v=oxGmXOKazw0 -->
<?php
session_start();
if (!isset($_SESSION['login_user'])) {
   header("location: login_false.php");
}
?>

<html>
<head>
  <?php
  include_once 'header.php';
  ?>
  <title>OpenWCS</title>
  <meta charset="utf-8">
  <link rel="stylesheet" type="text/css" href="style/style.css">
  <link rel="stylesheet" type="text/css" href="style/livestyle.css">
</head>

<body>

<div id="container">
  <div class="sidebar">
    <img src="style/pics/logo/openwcslogo.png" width="250px"></img>
    <ul id="nav">
      <li><a href="startpage.php">Dashboard</a></li>
      <li><a href="timelapse.php">Timelapse</a></li>
      <li><a href="live.php">Live Video</a></li>
      <li><a href="motiondetection.php">Motion Detection</a></li>
      <li><a href="filebrowser.php" class="selected">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>
  <div class="content">
    <h1>File Browser</h1>


    <div id="left">
      <div class="box-top">Pictures & Video</div>
      <div class="box-panel">
        <?php
        $path = "download/Pictures";
        $dh = opendir($path);
        $i=1;
        while (($file = readdir($dh)) !== false) {
            if($file != "." && $file != ".." && $file != "index.php" && $file != ".htaccess" && $file != "error_log" && $file != "cgi-bin") {
                echo "<a href='$path/$file'>$file</a><br /><br />";
                $i++;
            }
        }
        closedir($dh);
        ?>

    </div>
  </div>

    <div id="right">
      <div class="box-top">Manual & other stuff</div>
      <div class="box-panel">
        <?php
        $path = "download/manual";
        $dh = opendir($path);
        $i=1;
        while (($file = readdir($dh)) !== false) {
            if($file != "." && $file != ".." && $file != "index.php" && $file != ".DS_Store" && $file != ".htaccess" && $file != "error_log" && $file != "cgi-bin") {
                echo "<a href='$path/$file'>$file</a><br /><br />";
                $i++;
            }
        }
        closedir($dh);
        ?>

    </div>


</div>


</body>



</html>
