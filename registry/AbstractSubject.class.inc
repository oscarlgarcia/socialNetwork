<?php

/*
* Clase que define los metodos Subject de forma abstracta
* autor : Oscar Garcia
*/

abstract class AbstractSubject{
	
  abstract function attach(AbstractObserver $observer_in);
  abstract function detach(AbstractObserver $observer_in);
  abstract function notify($event,$userID,$ip='',$data='');
  
}

?>