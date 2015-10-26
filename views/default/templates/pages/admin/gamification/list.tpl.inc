    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{rule_count}</span> Reglas encontradas</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_category/search">
           <div class="col-md-6">
             <div class="input-group">
               <input type="text" class="form-control" placeholder="Busca una Categoria" id="search" name="search" value="{category.search}">
               <div class="input-group-btn">
                 <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
               </div>
             </div>
           </div>
           <div class="col-md-6">
             <a class="btn btn-info pull-right" href="admin_category/add"><i class="fa fa-plus"></i> Agregar Categor&iacute;a</a>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Nombre</th>
            <th>Imagen asociada</th>
            <th>Descripci&oacute;n</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START category -->
		      <tr>
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-info">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-info dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li class="deleteButton"><a id="delete" data-deleteurl="admin_category/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-2">{categoryName}</td>
            <td class="col-md-3"><img src="{categoryImage}" class="img-thumbnail" width="30%" height="30%" /></td>
            <td class="col-md-5">{categoryDescripition}</td>
          </tr>
        <!-- END category -->
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
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>
