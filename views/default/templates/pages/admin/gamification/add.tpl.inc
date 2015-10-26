<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<script type="text/javascript" src="lib/tagging/jquery.tagsinput.js"></script>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nueva Categor&iacute;a</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_category/register" name="categoryForm" id="categoryForm">
      <div class="form-group upload_group">
        <label  class="control-label" for="categoryName">Nombre de la Categoria</label>
        <input name="categoryName" maxlength="400" id="categoryName" value="{categoryName}" type="text" class="form-control" />
      </div>
      <div class="form-group upload_group">
        <label  class="control-label" for="categoryDescription">Descripci&oacute;n de la categor&iacute;a</label>
        <textarea name="categoryDescription" id="categoryDescription"  class="form-control" />{categoryDescription}</textarea>
      </div>
      <div class="form-group">
        <label  class="control-label" for="categoryDescription">Imagen de la categor&iacute;a: </label>
        <input id="categoryImage" name="categoryImage"  value="{categoryImage}" placeholder="Selecciona una imagen" type="number" class="filefilter"/>
        <div class="upload_div btn btn-primary">
        <span class="fa fa-cloud-download"></span>
        <input name="categoryImageBtn" id="categoryImageBtn" class="upload" data-toggle="modal" data-target="#mediaModal" />
      </div>
      </div>
      
      <div class="pull-right">
        <input type="submit" value="Guardar Categor&iacute;a" name="btn" id="btn-addCat" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="10"> 
      </div>
    </form>
  </div>

<!-- Modal HTML -->
<div id="mediaModal" class="modal fade">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal">
          <span aria-hidden="true">x</span>
          <span class="sr-only">Close</span>
        </button>
        <h4 class="modal-title"> Im&aacute;genes Disponibles</h4>
      </div>
      <div class="modal-body">
        <ul class="nav nav-tabs">
          <li class="active"><a href="#upload" data-toggle="tab">Subir Im&aacute;genes</a></li>
          <li><a href="#browse" data-toggle="tab">Explorar Im&aacute;genes</a></li>
        </ul>
        <!-- Tab content-->
        <div id="myTabContent" class="tab-content">
          <div class="tab-pane upload_tab active in" id="upload">
            <div class="alert alert-danger" id="uploadErrorMsg"></div>
            <form action="admin_category/image_upload" class="form-inline" method="post" enctype="multipart/form-data" id="uploadImageForm">
              <div class="form-group upload_group">
                <label  class="control-label" for="imageName">Nombre de la Imagen</label>
                <input name="imageName" maxlength="400" id="imageName" type="text" class="form-control upload_width" />
              </div>
              <div class="form-group upload_group">
                <label  class="control-label" for="tags">Tags</label>
                <input name="tags" id="tags" type="text" class="form-control upload_width" />
              </div>
              <input id="fileName" placeholder="Busca imagenes" disabled="disabled" class="form-control"/>
              <div class="upload_div btn btn-primary">
                <span class="fa fa-folder-open-o"></span>
                <input name="FileInput" id="FileInput" type="file" class="upload" />
              </div>
              <div class="form-group upload_group">
                <button type="button" class="btn btn-primary" id="uploadbtn" data-loading-text="Subiendo..." data-toggle="button"><span class="fa fa-cloud-upload"></span> Cargar Imagen</button>
              </div>
            </form>
            <div id="output"></div>
          </div>
          <div class="tab-pane upload_tab fade" id="browse">
            <form action="admin_category/image_browse" class="form-inline" method="post" id="imageSearchForm">
              <div class="input-group">
                <input type="text" class="form-control" placeholder="Busca Imagenes" name="image_search" value="">
                <div class="input-group-btn">
                  <button class="btn btn-default" type="submit" id="image_button_search">
                    <i class="glyphicon glyphicon-search"></i>
                  </button>
                </div>
              </div>
            </form>
            <div id="image_box"></div>             
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<!-- End modal-->
<script type="text/javascript" src="lib/imageUpload/imageUpload.js"></script>
<script type="text/javascript" src="lib/imageUpload/input-update.js"></script>
<script type="text/javascript" src="lib/imageUpload/image-search.js"></script>
<script type="text/javascript" src="lib/category/category-assign.js"></script>
<script type="text/javascript" src="lib/category/category-add.js"></script>