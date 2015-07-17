<?php

/**
 * Clase PagesTree 
 * Construye el Arbol de padres de las paginas del cms
 */
class PagesTree {
	
	private $registry;
	
	/**
	 * Constructor
	 * @param Object registry
	 * @return void
	 */
  function __construct( Registry $registry) 
  {
    $this->registry = $registry;
  }
    
  /*
  * Devuelve un Array con todas las paginas
  * anidadas con sus padres
  */
  public function pagesAsTree(array $elements, $parent = -1){
    $branch = array();
    foreach ($elements as $element) {
      if ($element['parent'] == $parent) {
        $children = $this->pagesAsTree($elements, $element['ID']);
        if ($children) {
          $element['children'] = $children;
        }
        $branch[] = $element;
      }
    }
    return $branch;
  }


  public function showTree(array $elements, $flag = true){
    
    if ($flag)
      $html = '<ul class="tree">';
    else
      $html = '<ul>';

    foreach ($elements as $element) {
        if(isset($element['children']) && is_array($element['children'])){
            $html .= '<li><a data-parent="'. $element['ID'] . '"  >'.$element['title'].'</a>' ; 
            $html .= $this->showTree($element['children'], false);
        }else
        {   
            $html .= '<li><a data-parent="'. $element['ID'] . '"  >'.$element['title'].'</a>' ;
        }

    }
     $html .= '</li></ul>';
     return $html;
  }
    
}
?>