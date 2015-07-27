    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{snippets_count}</span> Snippets Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_snippets/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca Snippets" id="search" name="search" value="{snippet.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="glyphicon glyphicon-search"></i></button>
             </div>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Titulo</th>
            <th>Autor</th>
            <th>Categor&iacute;a</th>
            <th>Publicado</th>
            <th>Comentarios</th>
            <th>Rating</th>
            <th>Favorito</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START snippets -->
		      <tr class="{class}">
		        <td class="col-md-1">
              <div class="btn-group">
                <button type="button" class="btn btn-{class}">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-{class} dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li><a href="admin_snippets/view/{ID}"><span class="fa fa-eye"></span> Ver</a></li>
                  <li><a href="admin_snippets/history/{ID}"><span class="fa fa-calendar"></span> Historial</a></li>
                  <li class="divider"></li>
                  <li><a href="admin_snippets/publish/{ID}"><span class="fa fa-check"></span> Publicar</a></li>
                  <li><a href="admin_snippets/ban/{ID}"><span class="fa fa-ban"></span> Retirar</a></li>
                  <li class="divider"></li>
                  <li ><a id="delete" data-deleteurl="admin_snippets/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-3"><a href="admin_snippets/view/{ID}">{title}</a></td>
            <td class="col-md-1">{author}</td>
            <td class="col-md-1">{category}</td>
            <td class="col-md-2">{fecha}</td>
            <td class="col-md-1">{comments}</td>
            <td class="col-md-1">{rating}</td>
            <td class="col-md-1">{faved}</td>
          </tr>
        <!-- END snippets -->
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