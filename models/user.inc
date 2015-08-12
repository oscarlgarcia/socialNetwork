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
  * Busca los usuarios para administracion de usuarios
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
  public function search( $offset=1, $criteria = "" )
  {
    $this->paginatedResult->setLimit($this->limit);
    $this->paginatedResult->setOffset( $offset-1);
    $query="SELECT ( select count(ID_User) from user_event where eventName='user.login' and id_user = u.id ) as total_login, DATE_FORMAT((select max(dateExecuted) from user_event where eventName='user.login' and id_user = u.id ),'%d %b %Y %T') as last_login, u.id, u.user_login as login, s.status_class as class , DATE_FORMAT(u.user_registered,'%d %b %Y %T') as date, u.user_email as email FROM users u left join user_event  e on u.id = e.ID_user left join operational_status s on s.id = u.user_status where  u.user_level!=10 and (user_login like '%".$criteria."%' or user_email like '%".$criteria."%' ) group by u.id order by e.dateExecuted asc";
    $this->paginatedResult->setQuery( $query );
    $this->paginatedResult->setMethod( 'cache' );
    $this->paginatedResult->generatePagination();
    return $this->paginatedResult;
  }


  /*
  * Metodo que retorna toda la info disponible para administracion del usuario
  * El objeto retornado poseerá los siguientes atributos
  * - ID
  * - login
  * - twitter
  * - email
  * - display_name
  * - puntos de experiencia
  * - puntos de reputacion
  * - Puntos de nivel
  * - Tipo de usuario
  * - Imagen del perfil
  * - Total de snippets creados
  * - Total Links creados
  * - Total de Comentarios de snippets

  */
  public function getUser($userID){
    
    $query = "SELECT count(DISTINCT s.ID) as total_snippets, count(DISTINCT l.ID) as total_links, count(DISTINCT cs.ID) as total_comments_snippets, count(DISTINCT cl.ID) as total_comments_links, u.ID as ID, u.user_login as login, u.twitter_name as twitter, u.user_email as email, u.user_url as url, u.display_name as display, u.experience_points as experience, u.reputation_points as reputation , u.level_points as level, u.user_level as granted , u.profile_image as image from users u  left join snippets s on u.ID = s.ID_User left join links l on u.ID = l.ID_User left join comment_snippet cs on u.ID = cs.ID_User left join comments_links cl on u.ID = cl.ID_User where u.ID = ".$userID ;
    $this->registry->getObject('db')->executeQuery( $query );
    if( $this->registry->getObject('db')->numRows() > 0 )
    {
      $data = $this->registry->getObject('db')->getRows();
      $tempo['ID'] = $data['ID'];
      $tempo['login'] = $data['login'];
      $tempo['twitter'] = $data['twitter'];
      $tempo['email'] = $data['email'];
      $tempo['url'] = $data['url'];
      $tempo['display'] = $data['display'];
      $tempo['experience'] = $data['experience'];
      $tempo['reputation'] = $data['reputation'];
      $tempo['level'] = $data['level'];
      $tempo['granted'] = $data['granted'];
      $tempo['image'] = $data['image'];
      $tempo['total_snippets'] = $data['total_snippets'];
      $tempo['total_links'] = $data['total_links'];
      $tempo['total_comments_snippets'] = $data['total_comments_snippets'];
      $tempo['total_comments_links'] = $data['total_comments_links'];
      return $tempo;
    }
    return null;

  }

	
}
?>