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
              <h2><strong>{reputation}</strong></h2>   
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
                <h2><strong>{experience}</strong></h2>   
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
                <h2><strong>{level}</strong></h2>   
              </div>
            </div>                 
          </div> 
        </div>  
        
        <div class="col-sm-6">
          <div class="widget navy-bg text-center">
            <div class="row">
              <div class="col-sm-3">
                <i class="fa fa-code fa-3x"></i>
              </div>
              <div class="col-sm-4">
                <span>Snippets</span>
                <h2><strong><a href="admin_snippets/listByUser/{login}">{total_snippets}</a></strong></h2>                    
              </div>
              <div class="col-sm-5">
                <span>Comentarios</span>
                <h2><strong><a href="admin_users/comments/{login}">{total_comments_snippets}</a></strong></h2>                    
              </div>
            </div>
          </div>
        </div>

        <div class="col-sm-6">
          <div class="widget lazur-bg text-center">
            <div class="row">
              <div class="col-sm-3">
                <i class="fa fa-bookmark fa-3x"></i>
              </div>
              <div class="col-sm-4">
                <span>Links</span>
                <h2><strong><a href="admin_links/listByUser/{login}">{total_links}</a></strong>
              </div>
              <div class="col-sm-5">
                <span>Comentarios</span>
                <h2><strong><a href="admin_snippets/listByUser/{login}">{total_comments_links}</a></strong></h2>                    
              </div>
            </div>
          </div>
        </div>

         <div class="col-sm-8">
          <div class="widget winter-blonde-bg text-center">
            <div class="row">
              <div class="col-sm-3">
                <i class="fa fa-heart fa-3x"></i>
              </div>
              <div class="col-sm-3">
                <span>Snippets</span>
                <h2><strong>{xxxx}</strong></h2>   
              </div>
              <div class="col-sm-3">
                <span>Links</span>
                <h2><strong>{xxxx}</strong></h2>   
              </div>
              <div class="col-sm-3">
                <span>Tutoriales</span>
                <h2><strong>{xxxx}</strong></h2>   
              </div>
            </div>                 
          </div> 
        </div>  
          
          <div class="col-sm-4">
            <div class="widget yellow-bg text-center">
              <div class="row">
                <div class="col-sm-3">
                  <i class="fa fa-user fa-3x"></i>
                </div>
                <div class="col-sm-5">
                  <span>Sesiones</span>
                  <h2><strong><a href="admin_snippets/listByUser/{login}">{xxxx}</a></strong></h2>                    
                </div>
              </div>
            </div>
          </div>  

          <div class="col-sm-4">
            <div class="widget red-bg text-center">
              <div class="row">
                <div class="col-sm-3">
                  <i class="fa fa-history fa-3x"></i>
                </div>
                <div class="col-sm-5">
                  <span>Historial</span>
                  <h2><strong><a href="admin_users/history/{ID}">{xxxx}</a></strong></h2>                    
                </div>
              </div>
            </div>
          </div>

       </div> 
     <!-- Fin Perfil -->
      </div>
    </div>
  </div>