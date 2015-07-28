<div class="container-fluid ecpGlobal-margin">
  <!-- Snippets panel -->
  <div class="row">
    <div class="col-md-12">
        <a href="admin_snippets/search"><span class="glyphicon glyphicon-arrow-left"></span> Regresar al listado</a>
      <div class="panel panel-primary">
  	    <div class="panel-heading">
  	      <div class="row">
            <div class="col-md-9">
  	          <span class="fa fa-list"></span> {title}
  	        </div>
  	        <div class="col-md-3">
              <div class="btn-group">
                <button type="button" class="btn btn-xs btn-success">{id}</button>
                <button type="button" data-toggle="dropdown" class="btn btn-xs btn-success dropdown-toggle"> <span class="caret"></span></button>
                <ul class="dropdown-menu">
                  <li><a href="admin_snippets/history/{id}"><span class="fa fa-calendar"></span> Historial</a></li>
                  <li class="divider"></li>
                  <li><a href="admin_snippets/publish/{id}"><span class="fa fa-check"></span> Publicar</a></li>
                  <li><a href="admin_snippets/ban/{id}"><span class="fa fa-ban"></span> Retirar</a></li>
                  <li class="divider"></li>
                  <li ><a id="delete" data-deleteurl="admin_snippets/delete/{id}" data-toggle="modal" data-target="#delete_modal"><span class="fa fa-trash"></span> Eliminar</a></li>
                </ul>
              </div>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-8">
  		      <p>{description}</p>
  		    </div>  
  		    <div class="col-md-4 text-center">
  		      <span >Tags:</span> 
  		      <!-- START tags -->
  		      <a href="admin_tags/view/{tag_name}" class="label label-info">{tag_name}</a>
  		      <!-- END tags -->
  		    </div>
  	      </div>
  	      <div class="row">
  	        <div class="col-md-12">
  	          <hr>
  	        </div>
  	      </div>	
  	      <div class="row">
  	        <div class="col-md-12">
  		      <div class="form-group">
  		        <textarea disabled id="code" name="code" >{code}</textarea>
              </div>
  		    </div>
          </div>
  	    </div> 
		<!-- END snippet -->
      </div>
    </div>
  </div>
  <!-- End Snippets panel -->
</div>


 <div class="well profile">
            <div class="col-sm-12">
                <div class="col-xs-12 col-sm-8">
                    <h2>Nicole Pearson</h2>
                    <p><strong>About: </strong> Web Designer / UI. </p>
                    <p><strong>Hobbies: </strong> Read, out with friends, listen to music, draw and learn new things. </p>
                    <p><strong>Skills: </strong>
                        <span class="tags">html5</span> 
                        <span class="tags">css3</span>
                        <span class="tags">jquery</span>
                        <span class="tags">bootstrap3</span>
                    </p>
                </div>             
                <div class="col-xs-12 col-sm-4 text-center">
                    <figure>
                        <img src="http://www.localcrimenews.com/wp-content/uploads/2013/07/default-user-icon-profile.png" alt="" class="img-circle img-responsive">
                        <figcaption class="ratings">
                            <p>Ratings
                            <a href="#">
                                <span class="fa fa-star"></span>
                            </a>
                            <a href="#">
                                <span class="fa fa-star"></span>
                            </a>
                            <a href="#">
                                <span class="fa fa-star"></span>
                            </a>
                            <a href="#">
                                <span class="fa fa-star"></span>
                            </a>
                            <a href="#">
                                 <span class="fa fa-star-o"></span>
                            </a> 
                            </p>
                        </figcaption>
                    </figure>
                </div>
            </div>            
            <div class="col-xs-12 divider text-center">
                <div class="col-xs-12 col-sm-4 emphasis">
                    <h2><strong> 20,7K </strong></h2>                    
                    <p><small>Followers</small></p>
                    <button class="btn btn-success btn-block"><span class="fa fa-plus-circle"></span> Follow </button>
                </div>
                <div class="col-xs-12 col-sm-4 emphasis">
                    <h2><strong>245</strong></h2>                    
                    <p><small>Following</small></p>
                    <button class="btn btn-info btn-block"><span class="fa fa-user"></span> View Profile </button>
                </div>
                <div class="col-xs-12 col-sm-4 emphasis">
                    <h2><strong>43</strong></h2>                    
                    <p><small>Snippets</small></p>
                    <div class="btn-group dropup btn-block">
                      <button type="button" class="btn btn-primary"><span class="fa fa-gear"></span> Options </button>
                      <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown">
                        <span class="caret"></span>
                        <span class="sr-only">Toggle Dropdown</span>
                      </button>
                      <ul class="dropdown-menu text-left" role="menu">
                        <li><a href="#"><span class="fa fa-envelope pull-right"></span> Send an email </a></li>
                        <li><a href="#"><span class="fa fa-list pull-right"></span> Add or remove from a list  </a></li>
                        <li class="divider"></li>
                        <li><a href="#"><span class="fa fa-warning pull-right"></span>Report this user for spam</a></li>
                        <li class="divider"></li>
                        <li><a href="#" class="btn disabled" role="button"> Unfollow </a></li>
                      </ul>
                    </div>
                </div>
            </div>
       </div> 


 <!-- MODAL -->
    <div id="delete_modal" class="modal fade">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h4 class="modal-title">Se va a eliminar este Snippet</h4>
          </div>
          <div class="modal-body">
            <p class="text-warning">Est&aacute;s seguro? Esta operaci&oacute;n no podr&aacute; deshacerse</p>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
            <a id="delete_link" type="button" class="btn btn-danger">Confirmar eliminaci&oacute;n</a>
          </div>
        </div>
      </div>
    </div>
<script type="text/javascript" src="lib/menuOps/delete_confirm.js"></script>