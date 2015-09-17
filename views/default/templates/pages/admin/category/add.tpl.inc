<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nueva Categor&iacute;a</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_category/register" name="uploadImageForm" id="uploadImageForm" enctype="multipart/form-data">
      <div class="form-group upload_group">
        <label  class="control-label" for="categoryName">Nombre de la Categoria</label>
        <input name="categoryName" maxlength="400" id="categoryName" type="text" class="form-control upload_width" />
      </div>
      <div class="form-group upload_group">
        <label  class="control-label" for="categoryDescription">Descripci&oacute;n de la categor&iacute;a</label>
        <textarea name="categoryDescription" id="categoryDescription" type="text" class="form-control upload_width" /></textarea>
      </div>
      <input id="fileName" placeholder="Selecciona una imagen" disabled="disabled" class="filefilter"/>
      <div class="upload_div btn btn-primary">
        <span class="fa fa-folder-open-o"></span>
        <input name="FileInput" id="FileInput" type="file" class="upload" />
      </div>
      <div class="form-group upload_group">
        <button type="button" class="btn btn-primary" id="uploadbtn" data-loading-text="Subiendo..." data-toggle="button"><span class="fa fa-cloud-upload"></span> Cargar Imagen</button>
      </div>
    </form>
  </div>
<script type="text/javascript" src="lib/imageUpload/category-upload.js"></script>
<script type="text/javascript" src="lib/imageUpload/input-update.js"></script>