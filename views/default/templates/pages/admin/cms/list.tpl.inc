<script type="text/javascript" src="lib/pagesTree/pagesTree.js"></script>
<link rel="stylesheet" type="text/css" href="lib/pagesTree/pagesTree.css"/>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">P&aacute;ginas CMS</h3>
  </div>
  <div class="panel-body">
  	<form class="navbar-form" role="search" method="post">
      <div class="form-group col-md-6">
        <input type="text" class="form-control" placeholder="Busca la p&aacute;gina" name="search" id="search" width="200">
      </div>
      <div class="form-group col-md-6">
        <a class="btn btn-info pull-right" href="admin_cms/add"><i class="fa fa-plus"></i> Agregar P&aacute;gina</a>
      </div>
    </form>  
    <div class="form-group  col-md-12">
    {page_tree}  
    </div>  
  </div>
</div>
<script type="text/javascript" src="lib/page/view_page.js" ></script>
<script type="text/javascript" src="lib/pagesTree/pagesTree_search.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>