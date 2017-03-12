<div class="panel panel-primary">
  <div class="panel-heading">
	  <h3 class="panel-title"><span class="badge">{controller_count}</span> Controladores Encontrados</h3>
	</div>
	<div class="panel-body">
    <form class="navbar-form row" role="search" method="post" action="admin_controllers/search">
      <div class="col-md-6">
        <div class="input-group">
          <input type="text" class="form-control" placeholder="Busca un Controlador" id="search" name="search" value="{controller.search}">
          <div class="input-group-btn">
            <button class="btn btn-default" type="submit"><i class="fa fa-search"></i></button>
          </div>
        </div>
      </div>
      <div class="col-md-6">
        <a class="btn btn-info pull-right" href="admin_controllers/add">
          <i class="fa fa-plus"></i> Agregar Controlador</a>
      </div>
    </form>
  </div>
</div>
<script type="text/javascript" src="lib/search/search_animation.js"></script>