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
      <li><a class="selected" href="picture.php">Bild</a></li>
      <li><a href="timelapse.php">Timelapse</a></li>
      <li><a href="live.php">Live</a></li>
      <li><a href="motiondetection.php">Motion Detection</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a href="about.php"> About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>

  <div class="content">
    <h1>Motion Detection</h1>

    <div id="box">
      <div class="box-top">Press Button to snap a pic</div>
      <div class="box-panel">

      <form action="">
        <button formaction="/snap">Snap!</button>
      </form>


  </div>

</div>


</body>



</html>
