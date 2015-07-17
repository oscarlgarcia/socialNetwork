<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li class="active">Snippets</li>
  </ul>
  <div class="row ecpGlobal-margin-bottom" >
    <div class="col-md-8">
      <div class="alert alert-info">
        <p>Snippets es un repositorio p&uacute;blico de c&oacute;digo fuente. Crea de forma f&aacute;cil tu colecci&oacute;n de snippets y comp&aacute;rtelas con la comunidad de desarrolladores. 
		Contamos con m&aacute;s de <span class="badge">{snippets_count}</span> Snippets registrados.</p>
      </div>	
    </div>
    <div class="col-md-4">	  
      <a class="btn btn-primary btn-lg" href="snippets/add" ><span class="fa fa-plus-circle"></span> Crea tu Snippet</a>
    </div>
  </div>
  <div class="row">
    <div class="col-md-9">
      <div class="panel panel-primary">
        <div class="panel-heading">
          <span class="fa fa-list"></span> Repositorio de Snippets {ordered_by} 
	      <div class="btn-group pull-right">
		    <button type="button" class="btn btn-primary btn-xs">Ordenar por:</button>
            <button type="button" class="btn btn-primary btn-xs dropdown-toggle" data-toggle="dropdown"><span class="caret"></span></button>
	        <ul class="dropdown-menu slidedown">
              <li><a href="snippets/{order_controller1}">{order_text1}</a></li>
			  <li><a href="snippets/{order_controller2}">{order_text2}</a></li>
			  <li><a href="snippets/{order_controller3}">{order_text3}</a></li>
            </ul>
          </div>
        </div>
        <div class="panel-body">
          <!-- START snippet -->
          <div class="row">
            <div class="col-md-12 snippet">
              <div class="row">
                <div class="col-md-12">
                  <h4><strong><a href="snippets/view/{ID}" >{title}</a></strong></h4>
                </div>
              </div>
              <div class="row">
                <div class="col-md-12 snippet-header-line">
                  Por: <a href="snippets/user/{author}"><img src="{topUserURL}{profile_image}" class="img-rounded" width="24" height="24"></a> | <span class="fa fa-folder-open"></span> <a href="snippets/category/{category}">{category}</a> |
                  <span class="fa fa-calendar"></span> {fecha} | <span class="fa fa-star"></span> {rating} | <span class="fa fa-heart"></span> {faved} | 
				  <span class="fa fa-comment"></span> {comments} | <span class="fa fa-tags"></span>Tags : {all_tags}
                </div>
              </div>
              <div class="row snippet-content">
                <div class="col-md-2">
                  <a href="#"><img src="views/default/images/lang/{image_category}" class="img-thumbnail" id="img-snippet" alt="java"></a>
                </div>
                <div class="col-md-10">
                  <p>{description}</p>
                  <p><a class="btn btn-info" href="snippets/view/{ID}">Ver Snippet</a></p>
                </div>
              </div>
            </div>
          </div>
          <!-- END snippet -->
          <!-- pagination -->
          <div class="col-md-9">
            <ul class="pagination">
                {page_items}
            </ul>
          </div>                             		
          <!-- end pagination -->
        </div>
      </div>
    </div>
	<div class="col-md-3">
	<div class="panel panel-primary">
        <div class="panel-heading">
		  <span class="fa fa-user"></span> Top Contributors
	    </div>
		<div class="panel-body">
		<ul class="widget">
		<!-- START contributors -->
		  <li>
		    <a href="snippets/user/{user_login}"><img src="{topUserURL}{profile_image}" class="img-rounded"  width="36" height="36" alt="{total}"></a>
		  </li>
		<!-- END contributors -->
		</ul>
	    </div>
    </div>
	  <div class="panel panel-primary ">
		  <div class="panel-body widget">
		    <img src="views/default/images/site/adword.png">
	    </div>
    </div>
	<div class="panel panel-primary">
        <div class="panel-heading">
		<span class="fa fa-tags"></span> Tags populares
	    </div>
		<div class="panel-body">
		<ul class="widget">
		<!-- START tags -->
		<li>
		  <a href="snippets/tag/{name}" class="label label-default">{name}</a>
		</li>
		<!-- END tags -->
		</ul>
	    </div>
    </div>
	</div>
  </div>
  <div class="row">
    <div class="col-md-12">
      <label>Busca por Categor&iacute;as</label>
    </div>
  </div>
  <div class="row">
    <!-- START langs -->
    <div class="col-md-2">
      <div class="panel panel-default grey">
		    <div class="panel-body">
		      <div class="text-center">
		        <a href="snippets/category/{category_name}">
		          {category_name} <span class="badge">{category_total}</span>
	          </a>
          </div>
	      </div>
	    </div>  
	  </div>
	<!-- END langs -->
  </div>
</div>