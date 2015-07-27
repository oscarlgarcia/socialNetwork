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
        <a href="admin_snippets/search"><span class="glyphicon glyphicon-arrow-left"></span> Regresar al listado</a>
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
                  <li><a href="admin_snippets/view/{id}"><span class="fa fa-eye"></span> Ver</a></li>
                  <li class="divider"></li>
                  <li><a href="admin_snippets/publish/{id}"><span class="fa fa-check"></span> Publicar</a></li>
                  <li><a href="admin_snippets/ban/{id}"><span class="fa fa-ban"></span> Retirar</a></li>
                  <li class="divider"></li>
                  <li ><a id="delete" data-deleteurl="admin_snippets/delete/{id}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-12">
  		      <p>{description}</p>
  		      <!-- START logs -->
  		        <div class="media">
   <a class="pull-left" href="#">
      <span class="glyphicon {imageEvent} icon-48"></span>
   </a>
   <div class="media-body">
      <h5 class="media-heading">El usuario: <b>{user_login}</b></h5>
      <p>Ha ejecutado la acci&oacute;n: <b>{event}</b> el: {created}</p>
   </div>
</div> 
<!-- END logs -->
  		    </div>  
  	      </div>

  	    </div> 
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
            <h4 class="modal-title">Se va a eliminar este Snippet</h4>
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