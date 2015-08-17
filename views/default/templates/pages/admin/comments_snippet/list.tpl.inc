    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{comments_snippet_count}</span> Snippets Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_comments_snippet/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca Comentarios" id="search" name="search" value="{comments_snippet.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
             </div>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Comentario</th>
            <th>Autor</th>
            <th>Publicado</th>
            <th>Snippet</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START comments_snippet -->
		      <tr class="{class}">
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-{class}">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-{class} dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li><a href="admin_comments_snippet/publish/{ID}"><span class="fa fa-check"></span> Publicar</a></li>
                  <li><a href="admin_comments_snippet/ban/{ID}"><span class="fa fa-ban"></span> Retirar</a></li>
                  <li class="divider"></li>
                  <li class="deleteButton" ><a id="delete" data-deleteurl="admin_comments_snippet/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-3"><textarea rows="5" cols="50" readonly="true">{comment}</textarea></td>
            <td class="col-md-2"><a href="admin_comments_snippet/listByUser/{user_id}">{user}</a></td>
            <td class="col-md-2">{dateAdded}</td>
            <td class="col-md-3"><a href="admin_comments_snippet/listBySnippet/{snippet_id}">{title}</a></td>
          </tr>
        <!-- END comments_snippet -->
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
            <h4 class="modal-title">Se va a eliminar este Comentario</h4>
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