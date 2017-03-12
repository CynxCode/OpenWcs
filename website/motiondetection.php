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
  <link rel="stylesheet" type="text/css" href="style/motiondetectionstyle.css">
</head>

<body>


<div id="container">

  <div class="sidebar">
    <img src="style/pics/logo/openwcslogo.png" width="250px"></img>
    <ul id="nav">
      <li><a href="startpage.php">Dashboard</a></li>
      <li><a href="timelapse.php">Timelapse</a></li>
      <li><a href="live.php">Live Video</a></li>
      <li><a class="selected" href="motiondetection.php">Motion Detection</a></li>
      <li><a href="filebrowser.php">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>

  <div class="content">
    <h1>Motion Detection</h1>

    <div id="left">
      <div class="box-top">Configuration</div>
      <div class="box-panel">

      <form action="">
        Press Button to turn Motion Detection on.
      </form>

    </div>
      </div>

    <div id="right">
      <div class="box-top">Log File</div>
      <div class="box-panel">
        <form action="">Log File<br>
          <input type="Radio" name="ONOFF" value="ON">ON<br>
          <input type="Radio" name="ONOFF" value="OFF" checked="checked">OFF<br>
          <input type="email" name="email" Placeholder="Email Adress">
         </form>
       </div>
</body>



</html>
