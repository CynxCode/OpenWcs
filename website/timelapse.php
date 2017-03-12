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
  <link rel="stylesheet" type="text/css" href="style/style.css">
  <link rel="stylesheet" type="text/css" href="style/timelapsestyle.css">
</head>

<body>

<div id="container">
  <div class="sidebar">
    <img src="style/pics/logo/openwcslogo.png" width="250px"></img>
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
    <h1>Timelapse</h1>

    <div id="left">
      <div class="box-top">Configuration:</div>
      <div class="box-panel">
        <form>
          <p>Picture Interval[s]:</p>
          <p><input type="number" id="invsnap" name="invsnap" step="1" max="1000"></p>
          <p>End Time[min]:</p>
          <p><input type="number" id="invcreate" name="invcreate" step="1" max="1000"</p>
          <p>FPS:</p>
          <p><input type="number" id="fps" name="fps" step="1" max="140"</p>
          </p>
          <button formaction="http://localhost:9000/timelapse" class="btn_submit" align="center" >Capture Screenshot</button>
        </form>
        </form>
      </div>
    </div>

    <div id="right">
      <div class="box-top">Information:</div>
      <div class="box-panel">
        <ul id="inf" type="circle">
          <li><u>Picture Interval</u>:</li>
          Set the time (in seconds) between pictures.<br>
          <br>
          <li><u>End Time</u>:</li>
          Set the time (in minutes) when the application should create the timelapse.<br>
          <br>
          <li><u>FPS</u>:</li>
          Set the FPS of the timelapse video.<br>
          <br>
          <li><u>Example</u>:</li>
          Picture Intervall = 50s, End Time = 90min, FPS = 2:<br>
          With this settings the application takes every 5 seconds a pictures,
          creates a timelapse with the pictures after 1h and 30min with 2 FPS. <br>
          Timelapse duration =  ((EndTime*60s)/PictureIntervall)/FPS <br>
        --> ((90min*60s)/50s)/2 = 54s.
        </ul>
      </div>
    </div>
</body>



</html>
