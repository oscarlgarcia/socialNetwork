<link rel="stylesheet" href="lib/codemirror/codemirror.css"/>
<link rel="stylesheet" href="lib/rating/star-rating.min.css"/>
<link rel="stylesheet" href="lib/codemirror/theme/solarized.css">
<link rel="stylesheet" href="lib/codemirror/addon/display/fullscreen.css" />
<script src="lib/codemirror/codemirror.js"></script>
<script src="lib/codemirror/mode/javascript/javascript.js"></script>
<script src="lib/codemirror/addon/selection/active-line.js"></script>
<script src="lib/codemirror/addon/display/fullscreen.js"></script>
<script src="lib/rating/star-rating.min.js"></script>
<script src="lib/charCounter/charcounter.js"></script>
<div class="container-fluid ecpGlobal-margin">
  <!-- Snippets panel -->
  <div class="row">
    <div class="col-md-12">
        <a href="admin_snippets/browse"><span class="glyphicon glyphicon-arrow-left"></span> Regresar al listado</a>
      <div class="panel panel-primary">
  	    <div class="panel-heading">
  	      <div class="row">
            <div class="col-md-9">
  	          <span class="fa fa-list"></span> {title}
  	        </div>
  	        <div class="col-md-3">
  	          <a href="admin_snippets/view/{id}" class="btn btn-success btn-xs"><span class="glyphicon glyphicon-eye-open"></span></a>
              <a href="admin_snippets/delete/{id}" class="btn btn-danger btn-xs"><span class="glyphicon glyphicon-trash"></span></a>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-12">
  		      <p>{description}</p>
  		      <!-- START logs -->
  		        <div class="media">
   <a class="pull-left" href="#">
      <span class="glyphicon {imageEvent} icon-48"></span>
   </a>
   <div class="media-body">
      <h5 class="media-heading">El usuario: <b>{user_login}</b></h5>
      <p>Ha ejecutado la acci&oacute;n: <b>{event}</b> el: {created}</p>
   </div>
</div> 
<!-- END logs -->
  		    </div>  
  	      </div>

  	    </div> 
      </div>
    </div>
  </div>
  <!-- End Snippets panel -->
</div>