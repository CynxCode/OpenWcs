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
  <title>OpenWcs</title>
  <meta charset="utf-8">
  <link rel="stylesheet" type="text/css" href="style/style.css">
</head>

<body>

<div id="container">
  <div class="sidebar">
    <img src="style/pics/logo/openwcslogo.png" width="250px"></img>
    <ul id="nav">
      <li><a class="selected" href="startpage.php">Dashboard</a></li>
      <li><a href="timelapse.php">Timelapse</a></li>
      <li><a href="live.php">Live Video</a></li>
      <li><a href="motiondetection.php">Motion Detection</a></li>
      <li><a href="filebrowser.php">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>

  <div class="content">
    <h1>Dashboard</h1>

    <div id="left">
      <div class="box-top">Status</div>
      <div class="box-panel">
        0 Zeitraffer gestartet<br>
	0 Zeitgesteuerte Aufnahmen gestartet
      </div>
    </div>

      <div id="right">
        <div class="box-top">Status</div>
        <div class="box-panel">
          0 Zeitraffer gestartet<br>
            0 Zeitgesteuerte Aufnahmen gestartet
      </div>
      </div>
    </div>


</body>


</html>
