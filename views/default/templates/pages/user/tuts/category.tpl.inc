<link rel="stylesheet" href="lib/tutorials/list.css"></link>
<div class="container-fluid ecpGlobal-margin">
  <ul class="breadcrumb">
        <li><a href="home">Home</a></li>
        <li><a href="tuts">Tutoriales</a></li>
        <li class="active">{category_name}</li>
  </ul>
  <div class="row">
        <div class="col-xs-12">
            <div class="box">
              <div class="box-icon">
              <img src="{category_image}" width="100" height="100" class="img-circle" /> 
              </div>
              <div class="info">
                    <h4 class="text-center">{category_name}</h4>
                    <p>{category_description}</p>
              </div>
            </div>
        </div>
  </div>
  <div class="row">
    <div class="col-md-12">
      <h4>Niveles Disponibles</h4>
    </div>
  </div>
  <div class="row">
    <!-- START langs -->
    <div class="col-md-4">
      <div class="pin">
        <h4><a href="tuts/{category_name}/{level_name}">{level_name}</a></h4>
        <h4>{level_stars}</h4>
        <p>
        <br>Total Tutoriales: {level_total}
        </p>
	    </div>  
	  </div>
	<!-- END langs -->
  </div>
</div>