    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{users_count}</span> Usuarios Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_users/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca usuarios" id="search" name="search" value="{user.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
             </div>
           </div>
         </form>        
        <table class="table table-hover" id="dev-table">
		    <thead>
		      <tr>
			     <th>ID</th>
				  <th>Username</th>
				  <th>Email</th>
				  <th>Registrado</th>
				  <th>#Veces Loggeado</th>
				  <th>&Uacute;ltimo Login</th>
			   </tr>
		    </thead>
		    <tbody>
		    <!-- START users -->
		      <tr class="{class}">
		        <td>
                <div class="btn-group">
	              <button type="button" class="btn btn-{class}">{id}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-{class} dropdown-toggle"> <span class="caret"></span></button>
                  <ul class="dropdown-menu"> 
                  	<li><a href="#"><span class="fa fa-wechat"></span> Mensaje</a>
                    <li><a href="#"><span class="fa fa-calendar"></span> Historial</a>
                    <li><a href="#"><span class="fa fa-ban"></span> Bloquear</a>
                    <li><a href="#"><span class="fa fa-trash"></span> Eliminar</a>
			      </ul>
		        </td>
		  	     <td><a href="admin_users/view/{id}">{login}</a></td>
			     <td>{email}</td>
			     <td>{date}</td>
			     <td>{total_login}</td>
			     <td>{last_login}</td>
            </tr>
            <!-- END users -->
		    </tbody>
        </table>
        <div class="col-md-9">
          <ul class="pagination">
            {page_items}
          </ul>
        </div>
        </div>
    </div>
<script type="text/javascript" src="lib/search/search_animation.js"></script>
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>