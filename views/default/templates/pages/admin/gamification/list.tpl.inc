    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{gamification_count}</span> Reglas encontradas</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_gamification/search">
           <div class="col-md-6">
             <div class="input-group">
               <input type="text" class="form-control" placeholder="Busca una Regla" id="search" name="search" value="{gamification.search}">
               <div class="input-group-btn">
                 <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
               </div>
             </div>
           </div>
           <div class="col-md-6">
             <a class="btn btn-info pull-right" href="admin_gamification/add"><i class="fa fa-plus"></i> Agregar una Regla</a>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Evento</th>
            <th>Titulo</th>
            <th>Descripci&oacute;n</th>
            <th>Umbral</th>
            <th>Experiencia</th>
            <th>Reputacion</th>
            <th>Nivel</th>
            <th>Insignia</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START gamification -->
		      <tr>
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-info">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-info dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li class="deleteButton"><a id="delete" data-deleteurl="admin_gamification/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-1">{name}</td>
            <td class="col-md-1">{title}</td>
            <td class="col-md-1">{description}</td>
            <td class="col-md-1">{threshold}</td>
            <td class="col-md-1">{xp}</td>
            <td class="col-md-1">{rp}</td>
            <td class="col-md-1">{lp}</td>
            <td class="col-md-2"><img src="{image}" class="img-thumbnail" width="30%" height="30%" /></td>
          </tr>
        <!-- END gamification -->
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
            <h4 class="modal-title">Se va a eliminar esta Regla</h4>
          </div>
          <div class="modal-body">
            <p class="text-warning">Est&aacute;s seguro? Esta operaci&oacute;n no podr&aacute; deshacerse</p>
            <p class="text-warning">Realizar esta acci&oacute;n afectar&aacute; la forma que se asignan las insignias</p>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
            <a id="delete_link" type="button" class="btn btn-danger">Confirmar eliminaci&oacute;n</a>
          </div>
        </div>
      </div>
    </div>
    <!-- fin MODAL -->
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>
