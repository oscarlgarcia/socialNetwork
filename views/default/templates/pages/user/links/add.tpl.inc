<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<script src="lib/tagging/jquery.tagsinput.js"></script>
<script src="lib/charCounter/charcounter.js"></script>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="links/browse">Links</a></li>
        <li class="active">Add</li>
  </ul>
  <div class="row">
    <div class="col-md-12">
	  <div class="panel panel-primary">
	    <div class="panel-heading">
         <h5><span class="glyphicon glyphicon-pencil"></span> Nuevo Link</h5>
	    </div>
		<div class="panel-body">
		<!-- START errors -->
		 <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
		<!-- END errors -->
		<form method="post" action="links/register" accept-charset="UTF-8">
		  <div class="form-group">
              <label for="title" class="control-label" >Titulo</label>
              <input class="form-control"  name="title" id="title" type="text"  maxlength="100" autofocus="" tabindex="1">
          </div>
		  <div class="form-group">
            <label for="description" class="control-label">Descripci&oacute;n</label>  <span id="counter_description">550 caracteres max.</span>
            <textarea class="form-control counted_description" name="description" id="description" tabindex="2" ></textarea>
          </div>
          <div class="form-group">
              <label for="url" class="control-label" >Url</label>
              <input class="form-control"  name="url" id="url" type="text"  maxlength="400" autofocus="" tabindex="1">
          </div>
		  <div class="row">
		    <div class="col-md-12">
		      <div class="form-group">
		        <label for="tags" class="control-label">Tags</label>
		          <input type="text" class="form-control" name="tags" id="tags" tabindex="5" ></textarea>
              </div>
		    </div>
		  </div>
		  
		</div>
	    <div class="panel-footer clearfix">
          <div class="pull-right">
		    <input type="submit" value="Agrega tu Link" name="btn" id="btn-addLink" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="6">
          </div>
        </div>
		</form>
    </div>
  </div>
  </div>
</div>
<script type="text/javascript" src="lib/links/add_links.js"></script>
