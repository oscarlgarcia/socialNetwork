<link rel="stylesheet" href="lib/codemirror/codemirror.css"/>
<link rel="stylesheet" href="lib/rating/star-rating.min.css"/>
<link rel="stylesheet" href="lib/codemirror/theme/solarized.css">
<link rel="stylesheet" href="lib/codemirror/addon/display/fullscreen.css" />
<script src="lib/codemirror/codemirror.js"></script>
<script src="lib/codemirror/mode/javascript/javascript.js"></script>
<script src="lib/codemirror/addon/selection/active-line.js"></script>
<script src="lib/codemirror/addon/display/fullscreen.js"></script>
<script src="lib/rating/star-rating.min.js"></script>
<script src="lib/charCounter/charcounter.js"></script>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="snippets/browse">Snippets</a></li>
        <li class="active">View</li>
  </ul>
  <!-- Snippets panel -->
  <div class="row">
    <div class="col-md-12">
      <div class="panel panel-primary">
  	    <div class="panel-heading">
  	      <div class="row">
            <div class="col-md-6">
  	          <span class="fa fa-list"></span> {title}
  	        </div>
  		    <div class="col-md-6">
  		      <form id="favForm" name="favForm" method="POST" action="snippets/">
  		        <input type="hidden" value="1" id="ajaxRequest"  name="ajaxRequest" />
                <input type="hidden" value="{action}" id="favAction" name="favAction" />
  	            <button type="button" id="favBtn" class="btn btn-primary btn-sm pull-right" data-loading-text="Guardando..." data-toggle="button"><span id="fav_star" class="fa {fav_msg}"></span></button>
  	          </form>
  	        </div>
  	      </div>
  	    </div>
        <div class="panel-body">
          <div class="row">
            <div class="col-md-6">
  		      <p>{description}</p>
  		    </div>  
  		    <div class="col-md-6 text-center">
  		      <span>Categoria: <a href="snippets/category/{category}" class="label label-info">{category}</a></span>
			  <form role="form" id="ratingForm" name="ratingForm" method="POST" action="snippets/rating" >
  		        <input id="rating" name="rating" type="number" class="rating" min=0 max=5 step=0.5 data-symbol="&#x2605;" data-readonly="{rating_readonly}" data-show-caption="false" value="{rating}" data-show-clear="false" data-size="xs"/>
				<input type="hidden" value="1" id="ajaxRequest"  name="ajaxRequest" />
			  </form>
  		      <p id="valoracion"> Valoracion:{rating} <small>/</small> 5 </p>
  		      <span >Tags:</span> 
  		      <!-- START tags -->
  		      <a href="snippets/tag/{tag_name}" class="label label-info">{tag_name}</a>
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
  	      <div class="row">
  	        <div class="col-md-12 pull-right">
  		      <div class="alert alert-info">
                <i class="fa fa-info-circle"></i> Presiona (F11) en el editor para cambiar a pantalla completa.
              </div>
  		    </div>
          </div>
  	    </div> 
		<!-- END snippet -->
      </div>
    </div>
  </div>
  <!-- End Snippets panel -->
  <!-- related Panel -->
  <div class="row">
    <div class="col-md-12">
	  <label>Snippets relacionados</label>
	  <div class="panel panel-default">
        <div class="panel-body">
	  <!-- START related -->
	  <div class="col-md-2">
        <div class="panel panel-default related">
		  <div class="panel-body">
		    <div class="text-center">
		      <a href="snippets/view/{related_ID}">
		        <img class="img-rounded"  alt="{full_title} "width="80" height="80" aaa="sss" src="{related_image_category}">
                <h5>{related_title}</h5>
			  </a>
            </div>
	      </div>
	    </div>  
	  </div>
	  <!-- END related -->
	  </div>
	  </div>
    </div>
  </div>
  <!-- end related Panel -->
  <!-- comments Panel -->
  <div class="row">
    <div class="col-md-12">
	  <label> Comentarios</label>
      <div class="panel panel-default comment">
        <div class="panel-body" id="comment-box">
        </div>
	  </div>
	</div>
  </div>
  <!-- end comments-->
  <!-- comments feedback panel -->
    <div class="row">
      <div class="col-md-12">
	    <form role="form" id="commentForm" name="commentForm" method="POST" action="snippets/" >
		  <input type="hidden" value="1" id="ajaxRequest"  name="ajaxRequest" />
		  <div class="col-md-12">
		    <div class="form-group">
              <label for="InputMessage">Comenta este Snippet</label>  <span id="counter">450 caracteres max.</span>
              <div class="input-group">
                <textarea name="comment" id="comment" class="form-control counted" rows="3"></textarea>
                <span id="comment-btn" class="input-group-addon btn btn-default" data-loading-text="Guardando..." ><i class="fa fa-comment comment-feedback"></i></span>
			  </div>
            </div>
		  </div>
		</form> 
	  </div>
	</div>
  <!-- comments feedback panel -->
</div>
<script type="text/javascript"  src="lib/snippets/view_snippets.js"></script>
<script type="text/javascript"  src="lib/rating/rate_it.js"></script>
<script type="text/javascript"  src="lib/comments/comments.js"></script>
<script type="text/javascript"  src="lib/favorites/favorites.js"></script>