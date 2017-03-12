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
      <li><a class="selected" href="live.php">Live Video</a></li>
      <li><a href="motiondetection.php">Motion Detection</a></li>
      <li><a href="filebrowser.php">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>
  <div class="content">
    <h1>Live Video</h1>


    <div id="box">
      <div class="box-top">Webcam</div>
      <div class="box-panel">
        <img src="http://localhost:9000/30" alt="Error connecting to Webcam! Is OpenWcs running propberly?" width="100%" style="max-height:70%;"/>
      </div>

      <form a target="_blank" action="">
        <button formaction="http://localhost:9000/snap" class="btn_snap" align="center" >Capture Screenshot</button>
      </form>
    </div>
  </div>

</div>


</body>



</html>
