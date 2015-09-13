    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{users_count}</span> Usuarios Encontrados</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_users/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Busca Usuarios" id="search" name="search" value="{user.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
             </div>
           </div>   
         </form>
        </div>
    </div>
    <script type="text/javascript" src="lib/search/search_animation.js"></script>