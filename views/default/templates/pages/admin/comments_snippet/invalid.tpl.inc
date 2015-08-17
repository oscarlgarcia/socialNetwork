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
        </div>
    </div>
    <script type="text/javascript" src="lib/search/search_animation.js"></script>