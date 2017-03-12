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
      <li><a href="filebrowser.php">Download Files</a></li>
      <li><a href="settings.php">Settings</a></li>
      <li><a class="selected" href="about.php">About</a></li>
      <a href="logout.php"><input type="submit" name="btn_logout" value="Logout" class="btn_logout"></a>
  </div>

  <div class="content">
    <h1>About</h1>

    <div id="box">
      <div class="box-panel">
        <h2>OpenWcs</h2>
        Open-Source Webcam Software<br>
        Created by Konstantin Papesh (@SydoxX) & Lorenz Kofler (@Ballonen)<br><br>
        <h3>What's that?</h3>
        We're aiming to create a webcam software for linux users and embedded system
        enthusiasts which is easy to control and easy to setup. Setting up a webcam
        on a Raspberry for example is a long and exhausting task. Programs
        and dependencies have to be installed, most programs are already
        abandoned and the few alternatives don't really have an easy interface
        and few functions.<br><br>
        <h3>Reporting Bugs</h3>
        <ol type="number">
          <li>Always update to the latest code on master, we make many merges
            every day and it is possible the bug has already been fixed!</li>
          <li> Search issues to make sure that somebody has not already reported the same bug.</li>
          <li>Add a issue including information about your system and how to reproduce the bug.</li>
        </ol><br><br>

        <h3>Requesting a feature</h3>
        <ol>
          <li>Search issues to make sure that somebody has not already requested the same feature.
            If you find a matching request, feel free to add any additional comments to the existing issue.</li>
          <li>Add a issue that is labeled as a Feature (and select any other appropriate labels)
             and includes a detailed description of your request.</li>
        </ol>


    </div>


  </div>

</div>


</body>


</html>
