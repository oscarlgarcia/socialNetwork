    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{users_count}</span> Usuarios Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_users/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca usuarios" name="user_search" value="{user.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="glyphicon glyphicon-search"></i></button>
             </div>
           </div>
         </form>        
        <table class="table table-hover" id="dev-table">
		    <thead>
		      <tr>
			     <th>ID</th>
				  <th>Login</th>
				  <th>Email</th>
				  <th>Registrado</th>
				  <th>Acciones</th>
			   </tr>
		    </thead>
		    <tbody>
		    <!-- START users -->
		      <tr>
		        <td>{id}</td>
		  	     <td>{login}</td>
			     <td>{email}</td>
			     <td>{date}</td>
              <td>
			    <button type="button" class="btn btn-info btn-xs"><span class="glyphicon glyphicon-calendar"></span></button>
			    <button type="button" class="btn btn-warning btn-xs"><span class="glyphicon glyphicon-ban-circle"></span></button>
                <button type="button" class="btn btn-danger btn-xs"><span class="glyphicon glyphicon-trash"></span></button>
                
				
              </td>
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