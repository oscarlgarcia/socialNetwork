    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{controller_count}</span> Controladores Encontrados</h3>
		</div>
		<div class="panel-body">
      <form class="navbar-form row" role="search" method="post" action="admin_controllers/search">
        <div class="col-md-6">
          <div class="input-group">
            <input type="text" class="form-control" placeholder="Busca un Controlador" id="search" name="search" value="{controller.search}">
            <div class="input-group-btn">
              <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
            </div>
          </div>
        </div>
        <div class="col-md-6">
          <a class="btn btn-info pull-right" href="admin_controllers/add"><i class="fa fa-plus"></i> Agregar Controlador</a>
        </div>
      </form>        
      <table class="table table-hover " id="dev-table">
		  <thead>
		    <tr>
			    <th><span class="fa fa-tasks"></span> ID</th>
			    <th>Nombre del Controlador</th>
          <th>Modificado</th>
          <th>Descripci&oacute;n</th>
			  </tr>
		  </thead>
		  <tbody>
		    <!-- START controllers -->
		    <tr class="{class}">
		      <td class="col-md-3">
            <div class="btn-group">
              <button type="button" class="btn btn-{class}">{ID}</button>
              <button type="button" data-toggle="dropdown" class="btn btn-{class} dropdown-toggle"> <span class="caret"></span></button>
              <ul class="dropdown-menu">
                <li><a href="admin_controllers/publish/{ID}"><span class="fa fa-check"></span> Habilitar</a></li>
                <li><a href="admin_controllers/ban/{ID}"><span class="fa fa-ban"></span> Deshabilitar</a></li>
                <li class="divider"></li>
                <li class="deleteButton" ><a id="delete" data-deleteurl="admin_controllers/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
              </ul>
            </div>
          </td>
		  	  <td class="col-md-3"><a href="admin_controllers/view/{ID}">{controller}</a></td>
          <td class="col-md-3">{created}</td>
          <td class="col-md-3">{description}</td>
        </tr>
        <!-- END controllers -->
		  </tbody>
    </table>
    <div class="col-md-9">
      <ul class="pagination">
        {page_items}
      </ul>
    </div>
  </div>
</div>
<!-- MODAL -->
<div id="delete_modal" class="modal fade">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
          <h4 class="modal-title">Se va a eliminar este Controlador</h4>
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
<script type="text/javascript" src="lib/search/search_animation.js"></script>
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>