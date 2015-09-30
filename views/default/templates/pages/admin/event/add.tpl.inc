<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nuevo Setting</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_settings/register">
      <div class="form-group">
        <label for="setting_key">Nombre del Setting</label>
        <input type="text" class="form-control" id="setting_key" name="setting_key" value ="{setting_key}">
      </div>
      <div class="form-group">
        <label for="setting_value">Valor del Setting</label>
        <textarea class="form-control" id="setting_value" name="setting_value">{setting_value}</textarea>
      </div>
      <div class="form-group col-md-12">
        <button class="btn btn-info pull-right" id="btn-addSetting" type="submit"><i class="fa fa-plus"></i> Agregar Setting</button>
      </div>
    </form>
  </div>
<script type="text/javascript" src="lib/settings/add-settings.js"></script>