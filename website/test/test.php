<!-- https://www.youtube.com/watch?v=oxGmXOKazw0 -->
<!DOCTYPE html>
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
  <link rel="stylesheet" type="text/css" href="stylefail.css">
  <link rel="stylesheet" type="text/css" href="style/timelapsestyle.css">
</head>

<body>

<div id="container">
  <div class="sidebar">
    <img src="openwcslogo.png" width="250px"></img>
    <ul id="nav">
      <li><a href="startpage.php">Dashboard</a></li>
      <li><a class="selected" href="timelapse.php">Timelapse</a></li>
      <li><a href="live.php">Live Video</a></li>
      <li><a href="motiondetection.php">Motion Detection</a></li>
      <li><a href="filebrowser.php">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
    </ul>
  </div>

  <div class="content">
    <h1>Heading</h1>

    <div id="left">
      <div class="box-top">Subheading</div>
      <div class="box-panel">
          Content
      </div>
    </div>

    <div id="right">
      <div class="box-top">Subheading</div>
      <div class="box-panel">
        Content
      </div>
    </div>
</body>



</html>
