    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{comments_count}</span> Comentarios Encontrados</h3>
		</div>
		<div class="panel-body">    
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Comentario</th>
            <th>Autor</th>
            <th>Fecha</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START comments -->
		      <tr class="{class}">
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-{class}">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-{class} dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                <li><a href="admin_snippets/publish/{ID}"><span class="fa fa-check"></span> Publicar</a></li>
                <li><a href="admin_snippets/ban/{ID}"><span class="fa fa-ban"></span> Retirar</a></li>
                <li class="divider"></li>
                <li class="deleteButton" ><a id="delete" data-deleteurl="admin_snippets/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-4"><textarea rows="3" cols="40" readonly="true" >{comment}</textarea></td>
            <td class="col-md-3">{user}</td>
            <td class="col-md-3">{dateAdded}</td>
          </tr>
        <!-- END comments -->
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
    <script type="text/javascript" src="lib/search/search_animation.js"></script>
    <script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>