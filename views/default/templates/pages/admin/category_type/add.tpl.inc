<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<script type="text/javascript" src="lib/tagging/jquery.tagsinput.js"></script>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nuevo Tipo de Categor&iacute;a</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_category_type/register" name="categoryForm" id="categoryForm">
      <div class="form-group upload_group">
        <label  class="control-label" for="categoryName">Nombre del tipo de Categoria</label>
        <input name="categoryName" maxlength="400" id="categoryName" value="{categoryName}" type="text" class="form-control" />
      </div>
      <div class="pull-right">
        <input type="submit" value="Guardar Tipo de Categor&iacute;a" name="btn" id="btn-addCat" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="10"> 
      </div>
    </form>
  </div>
<script type="text/javascript" src="lib/category/category-type-add.js"></script>