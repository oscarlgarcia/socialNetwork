<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nuevo Controlador</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_cms/register" accept-charset="UTF-8" id="add_page_form">
      <div class="form-group">
        <label for="controller_name">Nombre del Controlador</label>
        <input type="text" class="form-control" id="controller_name" name="controller_name">
      </div>
      <div class="form-group">
        <label for="controller_description">Descripci&oacute;n del Controlador</label>
        <textarea class="form-control" id="controller_description" name="controller_description"></textarea>
      </div>
      <div class="form-group col-md-12">
        <button class="btn btn-info pull-right" id="btn-addController" type="submit"><i class="fa fa-plus"></i> Agregar Controlador</button>
      </div>
    </form>
  </div>
<script type="text/javascript" src="lib/controllers/add_controller.js"></script>