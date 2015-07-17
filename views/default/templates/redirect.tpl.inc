<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en"> 
<head> 
	<base href="{site_url}" />
	<meta http-equiv="refresh" content="1;url={url}">
	<title>{site_name}</title>
	<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" /> 
  <meta name="description" content="{site_description}" />
  <meta name="keywords" content="{site_keywords}" /> 
	<link rel="stylesheet" type="text/css" href="views/default/css/bootstrap.min.css" />
	<link rel="stylesheet" type="text/css" href="views/default/css/bootstrap-theme.min.css" />
	<link rel="stylesheet" type="text/css" href="views/default/css/site.css" />
</head> 
<body>
<div id="wrap" class="ecpGlobal-bg">
  <div role="navigation" class="navbar navbar-inverse navbar-fixed-top ecpnavbar-bg">
     <div class="container-fluid">
      <!-- Toggle for mobile -->
      <div class="navbar-header">
        <button type="button" data-target="#navbarCollapse" data-toggle="collapse" class="navbar-toggle">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
        <a href="#" class="navbar-brand"><img src="views/default/images/site/titulo.png"></a>
      </div>
    </div>
  </div>
  <div class="jumbotron ecpAlpha0-bg">
    <div class="container">
      <h2>{heading}</h2>
      <p>{message}</p>
      <p>If you are not redirected, please </p>
	  <p><a href="{url}" class="btn btn-success btn-lg">Click here</a></p>
    </div>
  </div>
</div> <!-- Wrap Div -->
<div id="footer">
   <div class="container">
     <p class="text-muted">Copyright 2014 | El Club del Programador .</p>
   </div>
</div>
<script type="text/javascript" src="lib/jquery/jquery-2.1.0.min.js" ></script>
<script type="text/javascript" src="views/default/js/bootstrap.min.js"></script>
</body> 
</html>