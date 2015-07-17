<?php

require_once( 'AbstractObserver.class.inc' );
/*
 * Clase para gestionar la suma de puntos y 
 * experiencia en la gamificacion
 * autor : Oscar Garcia
 */

class Gamification extends AbstractObserver{
  
	/**
	 * Constructor
	 */
	public function __construct( Registry $registry )
	{
		$this->registry = $registry;
	}
	
	/**
	* Metodo para actualizar el valor de un evento realizado
	*/
	public function update(AbstractSubject $subject) 
	{    
      require_once( FRAMEWORK_PATH . 'models/user_event.inc');
      $user_event = new User_Event( $this->registry );
	  $threshold=$user_event->getThresholdByUserEvent($subject->getUserTrigger(),$subject->getEvent());	 	
      $this->checkAndSave($threshold,$subject);     
	}


  /*
  * Metodo para comprobar si merece premio
  * Accede a la tabla Gamification_Rules para comprobar si tiene premio
  */
  public function checkAndSave($threshold,$subject)
  {   
      require_once( FRAMEWORK_PATH . 'models/gamification_rules.inc');
      $rule = new Gamification_Rules( $this->registry );
      $rows=  $rule->findRuleByEvent($subject->getEvent());
	  
      foreach($rows as $row)
     {
     	  // Si el threshold se cumple
        if ($row['threshold']==$threshold)
        {
        	   // Y la recompensa tiene badge 
        	  if ($row['ID_Badge']!="1") 
        	  {
        	  	require_once( FRAMEWORK_PATH . 'models/badges_achieved.inc');
                $badge = new Badges_Achieved( $this->registry );
                $badge->save($row['ID_Badge'],$subject->getUserTrigger());
        	  }
           require_once( FRAMEWORK_PATH . 'models/user.inc');
           $user = new UserModel( $this->registry );
           $user->addReputationPoints($subject->getUserTrigger(),$row['reputation_points']);          
           $user->addExperiencePoints($subject->getUserTrigger(),$row['experience_points']);
		   $user->addLevel($subject->getUserTrigger(),$row['level_points']);
		   
        }
     }
  }
  
}

?>