<?php

/**
 * Clase Pagination 
 * Facilita la paginacion de registros
 */
class Pagination {
	
	//La query que sera paginada
	private $query = "";
	
	// La query procesada que sera ejecutada
	private $executedQuery = "";
	
	// El maximo numero de resutados por pagina
	private $limit = 25;
	
	// El offset de los resultados
	private $offset = 0;
	
	// El metodo de paginacion
	private $method = 'query';
	
	// El ID de cache si paginamos por resultados cacheados
	private $cache;
	
	// Los resultados si los ejecutamos directamente
	private $results;
	
	// El numero de filas
	private $numRows;
	
	// El numero de filas por pagina actual 
	private $numRowsPage;
	
	// Numero de paginas que tiene el resultset
	private $numPages;
	
	// Es la primera pagina de resultados?
	private $isFirst;
	
	// o es la ultima?
	private $isLast;
	
	// pagina actual en la que estamos
	private $currentPage;
	
	/**
	 * Constructor
	 * @param Object registry
	 * @return void
	 */
    function __construct( Registry $registry) 
    {
    	$this->registry = $registry;
    }
    
    /**
     * Fija la query a paginar
     * @param String $sql
     * @return void
     */
    public function setQuery( $sql )
    {
    	$this->query = $sql;
    }
    
    /**
     * Fija el limite  de cuantos resultados deben aparecer por pagina
     * @param int $limit
     * @return void
     */
    public function setLimit( $limit )
    {
    	$this->limit = $limit;	
    }
     /**
     * Comprueba si el offset es valido
     * @param int $offset
     * @return true if valid offset
     */
    public function checkOffset($offset)
    {	
		if($offset<=0)
		  return false;
		
		if ($this->numRows==0)
		  return false;
		 
		if ($offset>$this->numPages)
		  return false;
		
		
		return true;
    }
	
	
	
    /**
     * Fija el offset -se restara 1 por que empieza en bd en 0 y en la url en 1, por ejemplo si el offset es 0,entonces 
	 * debemos mostrar la primera pagina de resultados
     * @param int $offset
     * @return void
     */
    public function setOffset( $offset )
    {
    	$this->offset = $offset;
    }
    
    /**
     * Fija el metodo que usaremos para la paginacion
     * @param String $method [cache|do]
     * @return void
     */
    public function setMethod( $method )
    {
    	$this->method = $method;
    }
    
    /**
     * Procesa la query, y fija las propiedades de paginacion
     * @return bool
     */
    public function generatePagination()
    {
    	$temp_query = $this->query;
    	
    	// cuantos resultados?
    	$this->registry->getObject('db')->executeQuery( $temp_query );
    	$nums = $this->registry->getObject('db')->numRows();
    	$this->numRows = $nums;
    	
    	// limite!
    	$limit = " LIMIT ";
    	$limit .= ( $this->offset * $this->limit ) . ", " . $this->limit;
    	$temp_query = $temp_query . $limit;
    	$this->executedQuery = $temp_query;
    	if( $this->method == 'cache' )
    	{
    		$this->cache = $this->registry->getObject('db')->cacheQuery( $temp_query );
    	}
    	elseif( $this->method == 'do' )
    	{
    		$this->registry->getObject('db')->executeQuery( $temp_query );
    		$this->results = $this->registry->getObject('db')->getRows();
    	}
		
		// num pages
		$this->numPages = ceil($this->numRows / $this->limit);
		
		// is first
		$this->isFirst = ( $this->offset == 0 ) ? true : false;
		
		// is last
		
		$this->isLast = ( ( $this->offset + 1 ) == $this->numPages ) ? true : false;
		
		// current page
		$this->currentPage = ( $this->numPages == 0 ) ? 0 : $this->offset +1;
		$this->numRowsPage = $this->registry->getObject('db')->numRows();
		if( $this->numRowsPage == 0 )
		{
			return false;
		}
		else
		{
			return true;
		}
    	
    }
    
    /**
     * Obtenemos los resultado cacheados
     * @return int
     */
    public function getCache()
    {
    	return $this->cache;
    }
    
    /**
     * Obtenemos el result set
     * @return array
     */
    public function getResults()
    {
    	return $this->results;
    }
    
    public function getNextPage() {
    	
    	return $this->currentPage;
    }
    
    public function getPrevPage1() {
    	
    	return $this->currentPage-2;
    }
    
    /**
     * Obtenemos el num de paginas
     * @return int
     */
    public function getNumPages()
    {
    	return $this->numPages;
    }
    
    /**
     * Es la primera pagina?
     * @return bool
     */
    public function isFirst()
    {
    	return $this->isFirst;
    }
    
    /**
     * Es la ultima?
     * @return bool
     */
    public function isLast()
    {
    	return $this->isLast;
    }
    
    /**
     * Dame la pagina actual
     * @return int
     */
    public function getCurrentPage()
    {
    	return $this->currentPage;
    }
	
	 /**
     * Dame el total de resultados
     * @return int
     */
    public function getTotalRows()
    {
    	return $this->numRows;
    }
    
    // Dame el numero de filas por pagina
    public function getNumRowsPage()
    {
    	return $this->numRowsPage;    	
    }
  
    public function getOffset()
    {
    	return $this->offset;
    }
    
    // Metodo que muestra los links de paginación
    public function showPagination($controller,$action,$parameter1,$parameter2){	  

      $prev="<li><a href=\"snippets/{controller}/{previous}\"><span>&laquo;</span></a></li>";
      $next="<li><a href=\"snippets/{controller}/{next}\"><span>&raquo;</span></a></li>";	  
	  
	  // Si es mas de 5 solo se ponen 5
	  // si es menos de 5 se ponen los que hay
	  // Si es last page se inhabilita la de next
	  // si es first page se inhabilita previous
	  
	  $pn=$this->getCurrentPage();
	  $lastPage=$this->getNumPages();
	  $centerPages = "";
      $sub1 = $pn - 1;
      $sub2 = $pn - 2;
      $add1 = $pn + 1;
      $add2 = $pn + 2;	   	   
      
	  $to_print=""; 
	  $href= "<a href=\"".$controller."/".$action."/";
      if (!is_null($parameter1)){
	    if(!is_numeric($parameter1))
		  $href .=$parameter1."/";
	  } 

	  
	  if ($this->numRowsPage<=$this->limit){  // si es solo 1 pagina
		$to_print .= "<li class=\"disabled\"><span>&laquo;</span></li><li class=\"active\"><span>".$pn ."</span></li><li class=\"disabled\"><span>&raquo;</span></li>";
	  
	  }else{  //si hay 2 o mas paginas
	   
        if($this->isFirst()){ //si es la primera inhabilitamos el previous
		  $to_print.="<li class=\"disabled\"><span>&laquo;</span></li>";
	    }else{ //sino ponemos link al actual -1
	      $to_print.="<li>".$href.($sub1)."\"><span>&laquo;</span></a></li>";
	    }
	  
	    //construimos la paginacion
		$range=2;
		$from=$pn - $range;
        $until= $pn + $range;
		for($i=$from;$i<=$until;$i++){
		  if (($i > 0) && ($i <= $lastPage)) { // Si es una pagina valida
		    if($pn==$i){ // es la pagina actual?
		      $to_print.="<li class=\"active\"><span>".$i ."</span></li>";
		    }else{
		      $to_print.="<li>".$href.$i."\"><span>".$i."</span></a></li>";
		    }
		 
		  }
		}  
	   if($this->isLast()){ //si es la ultima inhabilitamos el next
	    $to_print.="<li class=\"disabled\"><span>&raquo;</span></li>";
	   }else{ //sino ponemos link al actual +1
	       $to_print.="<li>".$href.($add1)."\"><span>&raquo;</span></a></li>";
	   }

      }
      $this->registry->getObject('template')->getPage()->addTag( 'page_items', $to_print );

   }
    
}
?>