<link rel="stylesheet" href="lib/codemirror/codemirror.css">
<link rel="stylesheet" href="lib/codemirror/theme/solarized.css">
<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<link rel="stylesheet" href="lib/codemirror/addon/display/fullscreen.css" />
<script src="lib/codemirror/codemirror.js"></script>
<script src="lib/codemirror/mode/javascript/javascript.js"></script>
<script src="lib/codemirror/addon/selection/active-line.js"></script>
<script src="lib/codemirror/addon/display/fullscreen.js"></script>
<script src="lib/codemirror/addon/display/placeholder.js"></script>
<script src="lib/tagging/jquery.tagsinput.js"></script>
<script src="lib/charCounter/charcounter.js"></script>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="snippets/browse">Snippets</a></li>
        <li class="active">Add</li>
  </ul>
  <div class="row">
    <div class="col-md-12">
	  <div class="panel panel-primary">
	    <div class="panel-heading">
         <h5><span class="fa fa-pencil"></span> Nuevo Snippet</h5>
	    </div>
		<div class="panel-body">
		<!-- START errors -->
		 <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
		<!-- END errors -->
		<form method="post" action="snippets/register" accept-charset="UTF-8">
		  <div class="form-group">
              <label for="title" class="control-label" >Titulo</label>
              <input class="form-control"  name="title" id="title" type="text"  maxlength="100" autofocus="" tabindex="1">
          </div>
		  <div class="form-group">
            <label for="description" class="control-label">Descripci&oacute;n</label>  <span id="counter_description">550 caracteres max.</span>
            <textarea class="form-control counted_description" name="description" id="description" tabindex="2" ></textarea>
          </div>
		  <div class="row">
			<div class="col-xs-6 col-sm-4 col-md-4">
			  <div class="form-group">
			  <label for="category" class="control-label">Lenguaje</label>
			  <select class="form-control" id="category" name="category" tabindex="3" >
			    <option value="-1" selected="true">Selecciona un Lenguaje</option>
                <!-- START category -->
                <option value="{categoryID}">{categoryName}</option>
                <!-- END category -->
              </select>
			  </div>
			</div>
		  </div>
		  <div class="row">
		    <div class="col-md-12">
		      <div class="form-group">
		        <label for="code" class="control-label">Snippet</label>
		        <textarea id="code" name="code" tabindex="4" placeholder="{snippet_editor_message}"></textarea>
              </div>
		    </div>
		  </div>
		  <div class="row">
		    <div class="col-md-12">
		      <div class="form-group">
		        <label for="tags" class="control-label">Tags</label>
		      <input type="text" class="form-control" name="tags" id="tags" tabindex="5" /></textarea>
              </div>
		    </div>
		  </div>
		  
		</div>
	    <div class="panel-footer clearfix">
          <div class="pull-right">
		    <input type="submit" value="Agrega tu Snippet" name="btn" id="btn-addsnippet" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="6">
          </div>
        </div>
		</form>
    </div>
  </div>
  </div>
</div>
<script type="text/javascript"  src="lib/snippets/add_snippets.js"></script>