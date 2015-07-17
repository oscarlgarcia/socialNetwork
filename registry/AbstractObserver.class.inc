<?php

/*
* Clase que define los metodos Observadores de forma abstracta
* autor : Oscar Garcia
*/

abstract class AbstractObserver{
	abstract function update(AbstractSubject $subject_in);  	
}
?>