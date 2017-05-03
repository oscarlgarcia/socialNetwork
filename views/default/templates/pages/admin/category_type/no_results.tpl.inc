    <div class="panel panel-primary">
	   <div class="panel-heading">
		  <h3 class="panel-title"><span class="badge">{category_count}</span> Tipos de Categorias Encontradas</h3>
		</div>
		<div class="panel-body">
        <form class="navbar-form" role="search" method="post" action="admin_category_type/search">
           <div class="input-group">
             <input type="text" class="form-control" placeholder="Buscar Tipos de Categorias" id="search" name="search" value="{category.search}">
             <div class="input-group-btn">
               <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
             </div>
           </div>
         </form>
        </div>
    </div>
    <script type="text/javascript" src="lib/search/search_animation.js"></script>