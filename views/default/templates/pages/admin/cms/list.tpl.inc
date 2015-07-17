<script type="text/javascript" src="lib/pagesTree/pagesTree.js"></script>
<link rel="stylesheet" type="text/css" href="lib/pagesTree/pagesTree.css"/>
<div class="panel panel-primary">
  <div class="panel-heading">
    <h3 class="panel-title">P&aacute;ginas CMS</h3>
  </div>
  <div class="panel-body">
  	<form class="navbar-form" role="search" method="post">
      <div class="form-group">
        <input type="text" class="form-control" placeholder="Busca la p&aacute;gina" name="search" id="search" width="200">
      </div>
    </form>    
    {page_tree}
  </div>
</div>
<script type="text/javascript" src="lib/page/view_page.js" ></script>
<script type="text/javascript" src="lib/pagesTree/pagesTree_search.js"></script>
<script type="text/javascript" src="lib/search/search_animation.js"></script>