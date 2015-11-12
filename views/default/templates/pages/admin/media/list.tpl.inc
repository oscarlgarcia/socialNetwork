<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<link rel="stylesheet" href="lib/tagging/jquery.tagsinput.css" />
<script type="text/javascript" src="lib/tagging/jquery.tagsinput.js"></script>
  <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{media_count}</span> Im&aacute;genes encontradas</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_media/search">
           <div class="col-md-6">
             <div class="input-group">
               <input type="text" class="form-control" placeholder="Busca una Imagen" id="search" name="search" value="{media.search}">
               <div class="input-group-btn">
                 <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
               </div>
             </div>
           </div>
           <div class="col-md-6">
            <div class="upload_div btn btn-primary pull-right">
              <span class="fa fa-cloud-upload"></span> Agregar una Imagen
               <input name="ImageBtn" id="ImageBtn" class="upload" data-toggle="modal" data-target="#mediaModal" />
            </div>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Nombre</th>
            <th>URL</th>
            <th>Imagen</th>
            <th>Tama&ntilde;o</th>
            <th>Tags</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START media -->
		      <tr>
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-info">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-info dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li class="deleteButton"><a id="delete" data-deleteurl="admin_media/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-2"><a href="admin_media/view/{ID}">{name}</a></td>
            <td class="col-md-2">{url}</td>
            <td class="col-md-2"><img src="{url}" class="img-thumbnail" data-url="{url}" data-title="{name}" width="30%" height="30%" /></td>
            <td class="col-md-2">{size}</td>
            <td class="col-md-2">{all_tags}</td>
          </tr>
        <!-- END media -->
		    </tbody>
        </table>
        <div class="col-md-9">
          <ul class="pagination">
            {page_items}
          </ul>
        </div>
        </div>
    </div>

<!-- MODAL delete -->
  <div id="delete_modal" class="modal fade">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
          <h4 class="modal-title">Se va a eliminar esta Categor&iacute;a</h4>
        </div>
        <div class="modal-body">
          <p class="text-warning">Est&aacute;s seguro? Esta operaci&oacute;n no podr&aacute; deshacerse</p>
          <p class="text-warning">Realizar esta acci&oacute;n puede producir efectos en el Site; te aconsejo no realizarla</p>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
          <a id="delete_link" type="button" class="btn btn-danger">Confirmar eliminaci&oacute;n</a>
        </div>
      </div>
    </div>
  </div>
<!-- fin MODAL -->

<!-- MODAL viewer -->
  <div id="viewerModal" class="modal fade">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
          <h4 class="modal-title"></h4>
        </div>
        <div class="modal-body">
          <img id="imageViewer" width="100%" height="100%" class="img-thumbnail"/>
        </div>
      </div>
    </div>
  </div>
<!-- fin viewer -->

<!-- Modal MEDIA -->
<div id="mediaModal" class="modal fade">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal">
          <span aria-hidden="true">x</span>
          <span class="sr-only">Close</span>
        </button>
        <h4 class="modal-title"> Media Wizard</h4>
      </div>
      <div class="modal-body">
        <ul class="nav nav-tabs">
          <li class="active"><a href="#upload" data-toggle="tab">Subir Im&aacute;genes</a></li>
        </ul>
        <!-- Tab content-->
        <div id="myTabContent" class="tab-content">
          <div class="tab-pane upload_tab active in" id="upload">
            <div class="alert alert-danger" id="uploadErrorMsg"></div>
            <form action="admin_media/image_upload" class="form-inline" method="post" enctype="multipart/form-data" id="uploadImageForm">
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
        </div>
      </div>
    </div>
  </div>
</div>
<!-- End modal-->
<script type="text/javascript" src="lib/imageUpload/imageUpload.js"></script>
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>
<script type="text/javascript" src="lib/imageViewer/imageViewer.js"></script>
