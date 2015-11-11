<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">Tags</h3>
	</div>
	<div class="panel-body">
    <!-- START errors -->
    <div class="alert alert-danger" id="{error_msg}">{error_text}</div>
    <!-- END errors -->
    <div class="col-md-6">
      <form  method="post" action="admin_tags/update/{id}" id="update_tag_form">
        <div class="form-group">
          <label for="tag_name" class="control-label" >Cambia el nombre del Tag</label>
          <input class="form-control"  value="{tag_name}" name="tag_name" id="tag_name" type="text"  maxlength="400" autofocus="" tabindex="1">
        </div> 
        <div class="form-group">
        <input value="{tag_name}" name="name_hidden" id="name_hidden" type="hidden">
        <input type="submit" value="Actualizar Tag" name="btn" id="btn-updateTag" class="pull-right btn btn-primary" tabindex="2"> 
        </div> 
      </form>
    </div>
    <div class="col-md-6">
      <form  method="post" action="admin_tags/reasig/{id}" id="reasig_tag_form">
        <div class="form-group">
          <label for="tag_select" class="control-label" >O Asignalo a otro Tag</label>
          <select class="form-control" id="tag_select" name="tag_select" tabindex="3" >
            <option value="-1" selected="true">Selecciona un Tag</option>
            <!-- START tag -->
              <option value="{tagID}">{tagName}</option>
            <!-- END tag -->
          </select>
        </div> 
        <div class="form-group">
        <input value="{id}" name="id_hidden" id="id_hidden" type="hidden">
        <input type="submit" value="Reasignar a este Tag" name="btn" id="btn-reasigTag" class="pull-right btn btn-primary" tabindex="2"> 
        </div> 
      </form>
    </div>
    <!-- -->

    <div class="row">

    <div class="col-md-3">
      <b> Snippets Asociados</b>
      <div class="list-group">
        <!-- START snippets -->
        <a href="admin_snippets/view/{snippet_ID}" class="list-group-item">
          <h5 class="list-group-item-heading">{snippet_title}</h5>
        </a>
        <!-- END snippets -->
      </div>
    </div>

     <div class="col-md-3">
      <b> Links Asociados</b>
      <div class="list-group">
        <!-- START links -->
        <a href="admin_links/view/{link_ID}" class="list-group-item">
          <h5 class="list-group-item-heading">{link_title}</h5>
        </a>
        <!-- END links -->
      </div>
    </div>

     <div class="col-md-3">
      <b> P&aacute;ginas Asociadas</b>
      <div class="list-group">
        <!-- START pages -->
        <a href="admin_cms/edit/{page_ID}" class="list-group-item">
          <h5 class="list-group-item-heading">{page_title}</h5>
        </a>
        <!-- END pages -->
      </div>
    </div>

     <div class="col-md-3">
      <b> Im&aacute;genes Asociadas</b>
      <div class="list-group media_btn">
        <!-- START media -->
        <a class="list-group-item" data-url="{media_url}" data-toggle="modal" data-target="#img_modal">
          <h5 class="list-group-item-heading">{media_title}</h5>
        </a>
        <!-- END media -->
      </div>
    </div>

  </div>
  </div> 

<!-- Modal html -->
<div id="img_modal" class="modal fade">
  <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">x</span><span class="sr-only">Close</span></button>
          <h4 class="modal-title">Vista Previa</h4>
        </div>
        <div class="modal-body">
          <img width="70%" height="70%" id="media_id"/>
        </div>
        </div>
    </div>
</div>
<!-- end Modal html -->
</div>
<script type="text/javascript" src="lib/tags/update_tag.js"></script>
<script type="text/javascript" src="lib/imageUpload/image-view.js"></script>