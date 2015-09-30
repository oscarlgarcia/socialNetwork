<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Tags</h3>
	</div>
	<div class="panel-body">
      <div class="alert alert-warning">
          Modificar un Setting puede Traer consecuencias inesperadas en el Site. 
      </div>
      <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
      <div class="col-md-12">
      <form  method="post" action="admin_settings/update/{id}" id="update_setting_form">
        <div class="form-group">
          <label for="setting_key" class="control-label" >Cambia el nombre del Setting</label>
          <input class="form-control"  value="{setting_key}" name="setting_key" id="setting_key" type="text"  maxlength="400" autofocus="" tabindex="1">
        </div>
         <div class="form-group">
          <label for="setting_value" class="control-label" >Cambia el Valor</label>
          <textarea class="form-control" name="setting_value" id="setting_value">{setting_value}</textarea>
        </div> 
        <div class="form-group">
        <input value="{setting_key}" name="setting_hidden" id="setting_hidden" type="hidden">
        <input type="submit" value="Actualizar el Setting" name="btn" id="btn-updateSetting" class="pull-right btn btn-primary" tabindex="2"> 
        </div> 
      </form>
    </div>
</div>
</div>
<script type="text/javascript" src="lib/settings/update-settings.js"></script>