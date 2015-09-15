<link rel="stylesheet" type="text/css" href="lib/pagesTree/pagesTree.css"/>
<link rel="stylesheet" type="text/css" href="lib/page/page.css"/>
<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<script type="text/javascript" src="lib/ckeditor/ckeditor.js"></script>
<script type="text/javascript" src="lib/pagesTree/pagesTree.js"></script>
<script type="text/javascript" src="lib/tagging/jquery.tagsinput.js"></script>
  <div class="panel panel-primary">
    <div class="panel-heading">
      <h3 class="panel-title">Nueva P&aacute;gina</h3>
	  </div>
    <form  method="post" action="admin_cms/register" accept-charset="UTF-8" id="add_page_form">
	  <div class="panel-body">
      <!-- START errors -->
        <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
      <!-- END errors -->
      <div class="form-group">
        <label for="title" class="control-label" >Titulo</label>
        <input class="form-control"  name="title" id="title" type="text"  maxlength="400" autofocus="" tabindex="1">
      </div>
      <div class="form-group">
        <label for="url" class="control-label" >URL</label>
        <input class="form-control"  name="url" id="url" type="text"  maxlength="400" autofocus="" tabindex="2">
      </div>
      <div class="row">
        <div class="col-xs-6 form-group">
          <label for="category" class="control-label" >Categoria</label>
          <select class="form-control" id="category" name="category" tabindex="3" >
            <option value="-1" selected="true">Selecciona una Categoria</option>
            <!-- START category -->
              <option value="{categoryID}">{categoryName}</option>
            <!-- END category -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Tipo de P&aacute;gina</label>
          <select class="form-control" id="type" name="type" tabindex="4" >
            <option value="-1" selected="true">Selecciona el tipo de P&aacute;gina</option>
            <!-- START type -->
              <option value="{type_id}">{type_name}</option>
            <!-- END type -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Nivel</label>
          <select class="form-control" id="level" name="level" tabindex="4" >
            <option value="-1" selected="true">Selecciona el nivel de dificultad</option>
            <!-- START level -->
              <option value="{level_id}">{level_name}</option>
            <!-- END level -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Publicar</label>
          <div class="form-group">
            <div class="btn-group" data-toggle="buttons">
              <label class="btn btn-default active">
                <input type="radio" name="publish" value="0" />No
              </label> 
              <label class="btn btn-default">
                <input type="radio" name="publish" value="1" />Si
              </label> 
            </div>
          </div>
        </div>
      </div>
      <div class="form-group">
        <label for="parent" class="control-label" >Parent</label>
        <input type="hidden" id="parent" name="parent" value="0"> 
        <div class="treePanel" tabindex="5">
          {page_tree}
        </div>
      </div>
      <div class="form-group">
        <button type="button" tabindex="6" class="btn btn-primary" data-toggle="modal" data-target="#mediaModal"><span class="fa fa-image"></span> Subir Imagen</button>
      </div>
      <div class="form-group">
        <label for="editor" class="control-label" >Contenido</label>
        <textarea name="editor" id="editor" rows="50" cols="80" tabindex="7">
          This is my textarea to be replaced with CKEditor.
        </textarea>
      </div>
      <div class="form-group">
        <label for="keywords" class="control-label" >Keywords para SEO</label>
        <input class="form-control"  name="keywords" id="keywords" type="text"  maxlength="400" autofocus="" tabindex="8"></textarea>
      </div>
      <div class="form-group">
        <label for="description" class="control-label" >Descripcion para SEO</label>
        <textarea class="form-control" name="description" id="description" rows="3" cols="50" tabindex="9"></textarea>
      </div>  
    </div>
    <div class="panel-footer clearfix">
      <div class="pull-right">
        <input type="button" id="preview-btn" class="btn btn-warning" value="Vista Preliminar" />
		    <input type="submit" value="Guardar Pagina" name="btn" id="btn-addPage" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="10"> 
      </div>
    </div>  
  </form>
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
            <form action="admin_cms/image_upload" class="form-inline" method="post" enctype="multipart/form-data" id="uploadImageForm">
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
            <form action="admin_cms/image_browse" class="form-inline" method="post" id="imageSearchForm">
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
</div> <!-- end todo -->
<script type="text/javascript" src="lib/imageUpload/imageUpload.js"></script>
<script type="text/javascript" src="lib/imageUpload/input-update.js"></script>
<script type="text/javascript" src="lib/imageUpload/image-search.js"></script>
<script type="text/javascript" src="lib/page/add_page.js"></script>