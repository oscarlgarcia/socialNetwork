<?php

/**
 * Clase ImageUpload 
 * Gestiona la subida de imagenes al CMS 
 */
class ImageUpload {



    if(isset($_FILES["FileInput"]) && $_FILES["FileInput"]["error"] == UPLOAD_ERR_OK)
    {
      $UploadDirectory    = '/wamp/www/socialNetwork/static/resources/images/'; 
      //$UploadDirectory    = '/Library/WebServer/Documents/socialNetwork/static/resources/images/';
      $relative           = 'static/resources/images/';
      $errorImage         = 'views/default/images/site/img_error.png';
      $File_Name          = strtolower($_FILES['FileInput']['name']);
      $File_Ext           = substr($File_Name, strrpos($File_Name, '.')); //get file extention
      $Random_Number      = rand(0, 9999999999); //Random number to be added to name.
      $NewFileName        = $Random_Number.$File_Ext; //new file name
    
      if(move_uploaded_file($_FILES['FileInput']['tmp_name'], $UploadDirectory.$NewFileName ))
      {
        $media->setName(htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['imageName']),ENT_IGNORE));
        $media->setUrl($relative.$NewFileName);
        $id = $media->save();

        //Guardamos los Tags
		    require_once FRAMEWORK_PATH . 'models/tags.inc';
	    
        // leemos los tags y los separamos por comas
		    $tags=explode(",", $this->registry->getObject('db')->sanitizeData(htmlentities($_POST['tags'])));
        foreach($tags as $clave=>$value)
		    {
		      $myTag = new Tags( $this->registry);
		      $myTag->setTagName(strtolower($value));
		      $idTags[]=$myTag->save();
		    }
			  
        //Guardamos la relacion entre tags y media
		    require_once FRAMEWORK_PATH . 'models/tags_media.inc';
		    //Por cada Tag guardamos su relacion con el media
        foreach($idTags as $clave=>$value)
		    {
		      $myTag_media = new Tags_Media( $this->registry);
		      $myTag_media->setIDTag($value);
		      $myTag_media->setIDMedia($id);
		      $idTags_snippet[]=$myTag_media->save();
		    }
			  echo "<img id='imageUploaded' src='".$relative.$NewFileName."'  style='border:1px;' class='img-thumbnail' />";
        exit();
      }else{
     	  echo "<img src='".$errorImage."'  style='border:1px;' class='img-thumbnail' />";
        exit();
      }
    }
    else
    {
      echo "<img src='".$errorImage."'  style='border:1px;' class='img-thumbnail' />";
      exit();
    }



}
?>