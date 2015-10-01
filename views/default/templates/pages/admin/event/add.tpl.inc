<link rel="stylesheet" type="text/css" href="lib/imageUpload/imageUpload.css"/>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Nuevo Evento</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <form  method="post" action="admin_event/register">
      <div class="form-group">
        <label for="eventName">Nombre del Evento</label>
        <input type="text" class="form-control" id="eventName" name="eventName" value ="{event_name}">
      </div>
      <div class="form-group">
        <label for="eventDescription">Descripci&oacute;n del Evento</label>
        <textarea class="form-control" id="eventDescription" name="eventDescription">{event_description}</textarea>
      </div>
      <div class="form-group">
        <label  class="control-label" for="eventImage">Icono del Evento </label>
        <input id="eventImage" name="eventImage"  value="{event_image}" placeholder="Selecciona una imagen"  class="filefilter"/>
        <div class="upload_div btn btn-primary">
        <span class="fa fa-flag"></span>
        <input name="eventImageBtn" id="eventImageBtn" class="upload" data-toggle="modal" data-target="#mediaModal" />
      </div>
      </div>
      <div class="form-group col-md-12">
        <button class="btn btn-info pull-right" id="btn-addSetting" type="submit"><i class="fa fa-plus"></i> Agregar Evento</button>
      </div>
    </form>
  </div>
<!-- Modal HTML -->
<div id="mediaModal" class="modal fade">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal">
          <span aria-hidden="true">x</span>
          <span class="sr-only">Close</span>
        </button>
        <h4 class="modal-title"><span class="fa fa-flag"></span> Font Awesome!</h4>
      </div>
      <div class="modal-body">
        <div id="browse">
            <form action="admin_category/image_browse" class="form-inline" method="post" id="imageSearchForm">
              <div class="input-group">
                <input type="text" class="form-control" placeholder="Busca Imagenes" name="image_search" value="">
                <div class="input-group-btn">
                  <button class="btn btn-default" type="submit" id="image_button_search">
                    <i class="glyphicon glyphicon-search"></i>
                  </button>
                </div>
              </div>
            </form>
            <div id="image_box"></div>             
          </div>
       
      </div>
    </div>
  </div>
</div>
<!-- End modal-->
<script type="text/javascript" src="lib/event/add-event.js"></script>
<script type="text/javascript" src="lib/event/font-awesome-display.js"></script>