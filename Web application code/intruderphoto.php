<?php
session_start();

if(!$_SESSION['email'])
{

    header("Location: index.php");//redirect to login page to secure the welcome page without login access.
}

?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no" />
<title>Automated Home Security System | Inturder Photos</title>
<link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
<link rel="stylesheet" href="bootstrap/css/bootstrap-theme.min.css">
</head>

<body>


<div class="navbar navbar-default navbar-static-top" role="navigation">
    <div class="container">
 <a class="navbar-brand" style="float: right" href="logout.php">Logout</a>
        
 
    </div>
</div>

<div class="container">

	<div class="page-header">

    	<h2 class="h3">Automated Home Security System | Intruder Photos<h2>
    </div>

<center><iframe src="http://www.flickr.com/photos/139554945@N06/26150403031/player/" width="640" height="480" frameborder="0" allowfullscreen webkitallowfullscreen mozallowfullscreen oallowfullscreen msallowfullscreen></iframe></center>





</body>
</html>