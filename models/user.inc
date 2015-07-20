<?php

require_once ("Object.inc");
/**
* Clase Modelo para gestionar los datos de la tabla
* User
*/
class UserModel extends Object{
	
  // Propiedades del Usuario
  private $id;
  private $userLogin;
  private $userPass;
  private $passwordSalt;
  private $twitterName;
  private $userEmail;
  private $userUrl;
  private $userRegistered;
  private $userStatus;
  private $displayName;
  private $experiencePoints;
  private $reputationPoints;
  private $resetKey;
  private $resetExpires;
  private $activationKey;
  private $userLevel;
  private $limit = 5;
   	
  /**
  * Guarda un objeto User y lo retorna como objeto
  */
  public function save($user,$event){
	 
  }
	

  public function addReputationPoints($user,$points) 
  {
    $sql = "Update users set reputation_points=reputation_points+{$points} where ID='{$user}'";
    $this->registry->getObject('db')->executeQuery( $sql );
  }
  
  
  public function addExperiencePoints($user,$points) 
  {
    $sql = "Update users set experience_points=experience_points+{$points} where ID='{$user}'";
    $this->registry->getObject('db')->executeQuery( $sql );
  }
	
  public function addLevel($user,$level) 
  {
    $sql = "Update users set level_points=level_points+{$level} where ID='{$user}'";
    $this->registry->getObject('db')->executeQuery( $sql );
  }
  
  
  /**
  * Genera lista de usuarios paginados
  * El objeto retornado poseerá los siguientes atributos
  *  - Id del Usuario
  *  - Username
  *  - Email
  *  - Fecha de alta
  *  - # veces loggeado
  *  - Ultimo login
  * @param int $offset 
  * @return Object pagination object
  */
  public function listUsers( $offset=1 )
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset( $offset-1);
    $query="SELECT ( select count(ID_User) from user_event where eventName='user.login' and id_user = u.id ) as total_login, DATE_FORMAT((select max(dateExecuted) from user_event where eventName='user.login' and id_user = u.id ),'%d %b %Y %T') as last_login, u.id, u.user_login as login, DATE_FORMAT(u.user_registered,'%d %b %Y %T') as date, u.user_email as email FROM users u left join user_event  e on u.id = e.ID_user where  u.user_level!=10 group by u.id order by u.user_registered desc , e.dateExecuted asc";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
  /**
  * Genera lista de usuarios paginados
  * @param criterio
  * @return Object pagination object
  */
  public function search($criteria )
  {
    //Solo se mostraran los primeros 100 para no hacer paginación
    $this->paginatedResult->setLimit(100);
    $this->paginatedResult->setOffset(0);
    $query="SELECT id, user_login as login, user_registered as date, user_email as email FROM users where user_level!=10 and (user_login like '%".$criteria."%' or user_email like '%".$criteria."%' ) order by user_registered desc";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }
	
}

?>