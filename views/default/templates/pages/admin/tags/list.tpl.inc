    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{tags_count}</span> Tags Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_tags/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca Tags" id="search" name="search" value="{tags.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
             </div>
           </div>
         </form>        
        <table class="table table-hover " id="dev-table">
		    <thead>
		      <tr>
			      <th><span class="fa fa-tasks"></span> ID</th>
				    <th>Tag</th>
            <th>Snippets</th>
            <th>Links</th>
            <th>P&aacute;ginas</th>
            <th>Im&aacute;genes</th>
			    </tr>
		    </thead>
		    <tbody>
		    <!-- START tags -->
		      <tr>
		        <td class="col-md-2">
              <div class="btn-group">
                <button type="button" class="btn btn-info">{ID}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-info dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li class="deleteButton"><a id="delete" data-deleteurl="admin_tags/delete/{ID}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
            </td>
		  	    <td class="col-md-2"><a href="admin_tags/view/{tag_name}">{tag_name}</a></td>
            <td class="col-md-2">{total_snippets}</td>
            <td class="col-md-2">{total_links}</td>
            <td class="col-md-2">{total_pages}</td>
            <td class="col-md-2">{total_media}</td>
          </tr>
        <!-- END tags -->
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
            <h4 class="modal-title">Se va a eliminar este Tag</h4>
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
    <!-- fin MODAL -->
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>
