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
  	          <a href="admin_snippets/history/{id}" class="btn btn-info btn-xs"><span class="glyphicon glyphicon-calendar"></span></a>
              <a href="admin_snippets/delete/{id}" class="btn btn-danger btn-xs"><span class="glyphicon glyphicon-trash"></span></a>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-6">
  		      <p>{description}</p>
  		    </div>  
  		    <div class="col-md-6 text-center">
  		      <span >Tags:</span> 
  		      <!-- START tags -->
  		      <a href="snippets/tag/{tag_name}" class="label label-info">{tag_name}</a>
  		      <!-- END tags -->
  		    </div>
  	      </div>
  	      <div class="row">
  	        <div class="col-md-12">
  	          <hr>
  	        </div>
  	      </div>	
  	      <div class="row">
  	        <div class="col-md-12">
  		      <div class="form-group">
  		        <textarea disabled id="code" name="code" >{code}</textarea>
              </div>
  		    </div>
          </div>
  	    </div> 
		<!-- END snippet -->
      </div>
    </div>
  </div>
  <!-- End Snippets panel -->
</div>
<script type="text/javascript" src="lib/snippets/view_snippets.js"></script>