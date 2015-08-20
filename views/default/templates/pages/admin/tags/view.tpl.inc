<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nueva P&aacute;gina</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_cms/update/{id}" accept-charset="UTF-8" id="add_page_form">
      <div class="form-group">
        <label for="title" class="control-label" >Titulo</label>
        <input class="form-control"  value="{title}" name="title" id="title" type="text"  maxlength="400" autofocus="" tabindex="1">
      </div>
      <div class="form-group">
        <label for="url" class="control-label" >URL</label>
        <input class="form-control" value="{url}" name="url" id="url" type="text"  maxlength="400" autofocus="" tabindex="2">
      </div>
      <div class="row">
        <div class="col-xs-6 form-group">
          <label for="category" class="control-label" >Categoria</label>
          <select class="form-control" id="category" name="category" tabindex="3" >
            <option value="-1" >Selecciona una Categoria</option>
            <!-- START category -->
            <option value="{categoryID}" {categorySelected} >{categoryName}</option>
            <!-- END category -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Type</label>
          <select class="form-control" id="type" name="type" tabindex="4" >
            <option value="-1">Selecciona el tipo de P&aacute;gina</option>
            <!-- START type -->
            <option value="{type_id}" {type_selected}>{type_name}</option>
            <!-- END type -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Nivel</label>
          <select class="form-control" id="level" name="level" tabindex="4" >
            <option value="-1" selected="true">Selecciona el nivel de dificultad</option>
            <!-- START level -->
            <option value="{level_id}" {level_selected}>{level_name}</option>
            <!-- END level -->
          </select>
        </div>
        <div class="col-xs-6 form-group">
          <label for="type" class="control-label" >Publicar</label>
          <div class="form-group">
            <div class="btn-group" data-toggle="buttons">
              <label class="btn btn-default {page_publish_no}">
                <input type="radio" name="publish" value="0" {page_publish_no_selected} />No
              </label> 
              <label class="btn btn-default {page_publish_yes}">
                <input type="radio" name="publish" value="1" {page_publish_yes_selected} />Si
              </label> 
            </div>
          </div>
        </div>
      </div>
      <div class="form-group">
        <label for="treePanel" class="control-label" >Parent</label>
          <div class="treePanel" tabindex="5">
            {page_tree}
          </div>
          </div>
          <div class="form-group ">
            <label for="parent" class="control-label" >Parent Id Selected</label>
            <input type="text" id="parent" name="parent" value="{parent}" class="form-control" > 
          </div>
          <div class="form-group">
            <button type="button" tabindex="6" class="btn btn-primary" data-toggle="modal" data-target="#mediaModal"><span class="fa fa-image"></span> Subir Imagen</button>
          </div>
          <div class="form-group">
            <button type="button" tabindex="6" class="btn btn-primary" data-toggle="modal" data-target="#htmlSourceModal"><span class="fa fa-file-code-o"></span> Ver HMTL</button>
          </div>
          <div class="form-group">
            <label for="editor" class="control-label" >Contenido</label>
            <textarea name="editor" id="editor" rows="50" cols="80" tabindex="7">
              {body}
            </textarea>
          </div>
          <div class="form-group">
            <label for="keywords" class="control-label" >Keywords para SEO</label>
            <input class="form-control" value="{keywords}" name="keywords" id="keywords" type="text"  maxlength="400" autofocus="" tabindex="8">
          </div>
          <div class="form-group">
            <label for="description" class="control-label" >Descripcion para SEO</label>
            <textarea class="form-control" name="description" id="description" rows="3" cols="50" tabindex="9">{description}</textarea>
          </div>  
        </div>
      <div class="panel-footer clearfix">
        <div class="pull-right">
          <input type="button" id="preview-btn" class="btn btn-warning" value="Vista Preliminar" />
		      <input type="submit" value="Actualizar Pagina" name="btn" id="btn-addPage" data-loading-text="Guardando ..." class="btn btn-primary" tabindex="10" /> 
        </div>
      </div>  
    </form>

<!-- Modal html -->
<div id="htmlSourceModal" class="modal fade">
  <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">x</span><span class="sr-only">Close</span></button>
          <h4 class="modal-title"> HTML Source</h4>
        </div>
        <div class="modal-body">
          <textarea cols="88" rows="20">{body}</textarea>
        </div>
        </div>
    </div>
</diV>
<!-- end Modal html -->

<!-- Modal imagenes -->
  <div id="mediaModal" class="modal fade">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">x</span><span class="sr-only">Close</span></button>
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
  <!-- End modal imagenes-->
  </div>