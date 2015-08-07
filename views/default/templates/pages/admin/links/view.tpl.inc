<div class="container-fluid ecpGlobal-margin">
  <!-- Snippets panel -->
  <div class="row">
    <div class="col-md-12">
        <a href="admin_links/search"><span class="glyphicon glyphicon-arrow-left"></span> Regresar al listado</a>
      <div class="panel panel-primary">
  	    <div class="panel-heading">
  	      <div class="row">
            <div class="col-md-9">
  	          <span class="fa fa-list"></span> {title}
  	        </div>
  	        <div class="col-md-3">
              <div class="btn-group">
                <button type="button" class="btn btn-xs btn-success">{id}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-xs btn-success dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li><a href="admin_links/history/{id}"><span class="fa fa-calendar"></span> Historial</a></li>
                  <li class="divider"></li>
                  <li><a href="admin_links/publish/{id}"><span class="fa fa-check"></span> Publicar</a></li>
                  <li><a href="admin_links/ban/{id}"><span class="fa fa-ban"></span> Retirar</a></li>
                  <li class="divider"></li>
                  <li class="deleteButton"><a id="delete" data-deleteurl="admin_links/delete/{id}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-8">
  		      <p>{description}</p>
  		    </div>  
  		    <div class="col-md-4 text-center">
  		      <span >Tags:</span> 
  		      <!-- START tags -->
  		      <a href="admin_tags/view/{tag_name}" class="label label-info">{tag_name}</a>
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
  		        <a href="{url}" target="_blank"><span class="fa fa-external-link"></span> {url}</a>
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
 <!-- MODAL -->
    <div id="delete_modal" class="modal fade">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h4 class="modal-title">Se va a eliminar este Link</h4>
          </div>
          <div class="modal-body">
            <p class="text-warning">Est&aacute;s seguro? Esta operaci&oacute;n no podr&aacute; deshacerse</p>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
            <a id="delete_link" type="button" class="btn btn-danger">Confirmar eliminaci&oacute;n</a>
          </div>
        </div>
      </div>
    </div>
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>