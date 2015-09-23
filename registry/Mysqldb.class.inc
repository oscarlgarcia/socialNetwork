<?php
/**
*  Clase para manejo de Base de datos
*
* @author Oscar Garcia
* @version 1.0
*/
class Mysqldb {
	
	
  /**
  * Permite multiples conexiones a la base de datos
  * cada conexion se almacena como un elemento in el array y la conexion
  * activa se mantiene en una variable
  */
  private $connections = array();

  /**
  * Nos dice que conexion utilizar, para cambiar la conexion activa 
  * utilizamos setActiveConnection($id)
  */
  private $activeConnection = 0;
  
  /**
  * Consultas que han sido ejecutadas y el resultado almacenado para uso posterior
  * principalmente por el template engine
  */
  private $queryCache = array();

  
  /**
  * Datos que han sido ejecutadas y el resultado almacenado para uso posterior
  * principalmente por el template engine
  */
  private $dataCache = array();

  /**
  * Numero de consultas ejecutadas durante el proceso de ejecucion 
  */
  private $queryCounter = 0;
  
  /**
  * Registra la ultima consulta
  */
  private $last;
  
  /**
  * Referencia al objeto Registry
  */
  private $registry;

  /**
  * Constructor
  */
  public function __construct( Registry $registry )
  {
    $this->registry = $registry;	
  }

  /**
  * Crea una nueva conexion a la base de datos
  * @param String database hostname
  * @param String database username
  * @param String database password
  * @param String database que estamos usando
  * @return int el id de la nueva conexion
  */
  public function newConnection( $host, $user, $password, $database )
  {
    $this->connections[] = @new mysqli( $host, $user, $password,$database );
    
    if( mysqli_connect_errno() )
    {
    	  // TODO: poner en un layout decente
        die(' Error connecting to DBhost. '.$this->connections[0]->connect_error. "  <- remover esto"  );
        // TODO registrar este error en log 
    }
    $connection_id = count( $this->connections )-1;
    return $connection_id;
  }


     /**
     * Cierra la conexion activa
     * @return void
     */
    public function closeConnection()
    {
    	$this->connections[$this->activeConnection]->close();
    }
    
  
  /**
  * Permite cambiar la conexion de base de datos activa para
  * la siguiente operacion
  * @param int  el nuevo ID de conexion 
  * @return void
  */
  public function setActiveConnection( int $new )
  {
    $this->activeConnection = $new;
  }

  /**
   * Almacena una query en la cache para procesarla posteriomente
   * @param String la consulta
   * @return el indice de la query en la cache
   */
  public function cacheQuery( $queryStr )
  {
    //var_dump($queryStr);
    if( !$result = $this->connections[$this->activeConnection]->query( $queryStr ) )
    {
	   trigger_error('Error executing and caching query: '.$this->connections[$this->activeConnection]->error, E_USER_ERROR);
	   return -1;
	 }
	 else
	 {
	   $this->queryCache[] = $result;
		return count($this->queryCache)-1;
	 }
  }
   
  /**
   * Devuelve el numero de filas de la cache
   * @param int el indice de la query en la cache
   * @return int el numero de filas
   */
  public function numRowsFromCache( $cache_id )
  {
    return $this->queryCache[$cache_id]->num_rows;	
  }
    
  /**
   * Devuelve las filas de una query cacheada
   * @param int el indice de la query en la cache
   * @return Array de la fila
   */
  public function resultsFromCache( $cache_id )
  {
    return $this->queryCache[$cache_id]->fetch_array(MYSQLI_ASSOC);
  }
    
  /**
   * Almacena datos en cache
   * @param array de datos
   * @return int el indice del array en la cache
   */
  public function cacheData( $data )
  {
    $this->dataCache[] = $data;
    return count( $this->dataCache )-1;
  }
    
  /**
   * Devuelve los datos de la cache
   * @param int indice de los datos cacheados
   * @return array de datos
   */
  public function dataFromCache( $cache_id )
  {
    return $this->dataCache[$cache_id];
  }
    
  /**
  * Borra registros de la Base de datos
  * @param String Tabla desde la que eliminaremos
  * @param String condicion de eliminacion
  * @param int numero de elementos limite que eliminaremos
  * @return void
  */
  public function deleteRecords( $table, $condition, $limit )
  {
    $limit = ( $limit == '' ) ? '' : ' LIMIT ' . $limit;
    $delete = "DELETE FROM {$table} WHERE {$condition} {$limit}";
    $this->executeQuery( $delete );
  }

  /**
  * Actualizamos registros en la base de datos
  * @param String Tabla
  * @param array de cambios field => value
  * @param String condicion de actualizacion 
  * @return bool
  */
  public function updateRecords( $table, $changes, $condition )
  {
    $update = "UPDATE " . $table . " SET ";
    foreach( $changes as $field => $value )
    {
      $update .= "`" . $field . "`='{$value}',";
    }
    
    // remove our trailing ,
    $update = substr($update, 0, -1);
    if( $condition != '' )
    {
      $update .= " WHERE " . $condition;
    }
    
    $this->executeQuery( $update );
    return true;
  }


  /**
  * Insert registros dentro de la base de datos 
  * @param String La tabla
  * @param array de datos a incluir  field => value
  * @return bool
  */
  public function insertRecords( $table, $data )
  {
    // configuramos los parametros de entrada
    $fields = "";
    $values = "";
    // populate them
    foreach ($data as $f => $v)
    {
      $fields .= "`$f`,";
      $values .= ( is_numeric( $v ) && ( intval( $v ) == $v ) ) ? $v."," : "'$v',";
    }
    // remove our trailing ,
    $fields = substr($fields, 0, -1);
    // remove our trailing ,
    $values = substr($values, 0, -1);
    
    $insert = "INSERT INTO $table ({$fields}) VALUES({$values})";
    //echo $insert;
    //var_dump($insert);
    $this->executeQuery( $insert );
    return true;
  }

    
    public function lastInsertID()
    {
	    return $this->connections[ $this->activeConnection]->insert_id;
    }
 
  /**
  * Ejecuta una consulta
  * @param String la consulta
  * @return void
  */
  public function executeQuery( $queryStr )
  {
    if( !$result = $this->connections[$this->activeConnection]->query( $queryStr ) )
    {
    	 // TODO: Poner en properties
	  echo 'Error executing query: ' . $queryStr .' -'.$this->connections[$this->activeConnection]->error,E_USER_ERROR;
      trigger_error('Error executing query: ' . $queryStr .' -'.$this->connections[$this->activeConnection]->error,E_USER_ERROR);
    }
    else
    {
      $this->last = $result;
    }
  }

            
  /**
  * Obtiene las filas  de la mas reciente consulta ejecutada 
  * No toma en cuenta las consultas cacheadas
  * @return array
  */
  public function getRows()
  {
    return $this->last->fetch_array(MYSQLI_ASSOC);
  }
  
  
  /* Obtiene el total de resultados de la ultima operacion
   * Sin tomar en cuenta las consultas cacheadas
  */
   public function numRows()
  {
    return $this->last->num_rows;
  }
  

  /**
  * Devuleve el numero de columnas afectadas
  * @return int numero de columnas
  */
  public function affectedRows()
  {
    return $this->last->affected_rows;
  }        
        
 /**
  * Saneamos los datos
  * @param String datos a ser saneados
  * @return String datos saneados
  */
  public function sanitizeData( $value )
  {
    // quitamos slashes
    if ( get_magic_quotes_gpc() )
    {
      $value = stripslashes ( $value );
    }
    // comillas
    if ( version_compare( phpversion(), "4.3.0" ) == "-1" )
    {
      $value = $this->connections[$this->activeConnection]->escape_string( $value );
    }  
    else
    {
      $value = $this->connections[$this->activeConnection]->real_escape_string( $value );
    } 
    return $value;
  }    
    
 /**
  * Destructor 
  * cierra todas las conexiones
  */
  public function __deconstruct()
  {
    foreach( $this->connections as $connection )
    {
      $connection->close();
    }
  }

}
?>