<link rel="stylesheet" href="lib/profile/profile.css" />
<div class="container-fluid">
  <!-- Snippets panel -->
  <div class="row">
    <div class="col-md-offset-1 col-md-9">
      <!-- Perfil -->
      <div class="profile">
        <div class="col-sm-12">
          <div class="col-xs-12 col-sm-8">
            <h2>{login}</h2>
            <p><strong>About: </strong> Web Designer / UI. </p>
            <p><strong>Twitter: </strong><a href="https://twitter.com/{twitter}" target="_blank" rel="nofollow">{twitter}</a></p>
            <p><strong>URL: </strong><a href="{url}" target="_blank" rel="nofollow">{url}</a></p>
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
              <img src="{topUserURL}{image}" width="128px" height="128px" class="img-circle img-responsive">
            </figure>
          </div>
        </div>    
        <div class="col-sm-4">
          <div class="widget yellow-bg text-center">
            <div class="row">
            <div class="col-sm-4">
               <i class="fa fa-trophy fa-3x"></i>
            </div>
            <div class="col-sm-8">
              <span>Reputacion</span>
              <h2><strong>{total_comments_snippets}</strong></h2>   
            </div>
            </div>                 
          </div> 
        </div>  
        <div class="col-sm-4">
          <div class="widget brown-bg text-center">
            <div class="row">
              <div class="col-sm-4">
                <i class="fa fa-trophy fa-3x"></i>
              </div>
              <div class="col-sm-8">
                <span>Experiencia</span>
                <h2><strong>{total_comments_snippets}</strong></h2>   
              </div>
            </div>                 
          </div> 
        </div>  
        <div class="col-sm-4">
          <div class="widget pruple-bg text-center">
            <div class="row">
              <div class="col-sm-4">
                <i class="fa fa-trophy fa-3x"></i>
              </div>
              <div class="col-sm-8">
                <span>Nivel</span>
                <h2><strong>{total_comments_snippets}</strong></h2>   
              </div>
            </div>                 
          </div> 
        </div>  
        
        <div class="col-sm-4">
          <div class="widget navy-bg text-center">
            <div class="row">
              <div class="col-sm-4">
                <i class="fa fa-code fa-3x"></i>
              </div>
              <div class="col-sm-8">
                <span>Snippets</span>
                <h2><strong><a href="admin_snippets/listByUser/{login}">{total_snippets}</a></strong></h2>                    
              </div>
            </div>
          </div>
        </div>

          <div class="col-sm-2">
            <div class="widget navy-bg text-center">
              <i class="fa fa-bookmark fa-2x"></i>
              <h2><strong>{total_links}</strong></h2>                    
              <p><small>Links</small></p>
            </div>
          </div>
          <div class="col-sm-2">
            <div class="widget lazur-bg text-center">
              <i class="fa fa-comment fa-2x"></i>
              <h2><strong>{total_comments_snippets}</strong></h2>                    
              <p><small>Snippets</small></p>
            </div>
          </div>
          <div class="col-sm-2">
            <div class="widget lazur-bg text-center">
              <i class="fa fa-comment fa-2x"></i>
              <h2><strong>{total_comments_snippets}</strong></h2>                    
              <p><small>Links</small></p>
            </div> 
          </div>  
          <div class="col-sm-2">
            <div class="widget yellow-bg text-center">
              <i class="fa fa-user fa-2x"></i>
              <h2><strong>{total_comments_snippets}</strong></h2>                    
              <p><small>Logged</small></p>
            </div> 
          </div>  
          <div class="col-sm-2">
            <div class="widget red-bg text-center">
              <i class="fa fa-history fa-2x"></i>
              <h2><strong>{total_comments_snippets}</strong></h2>                    
              <p><small>Historial</small></p>
            </div> 
          </div>  
       </div> 
     <!-- Fin Perfil -->
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