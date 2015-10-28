<?php

/**
 * Clase Upload 
 * Gestiona la subida de imagenes  
 */
class Upload {

  private $uploadDirectory; 
  // '/Library/WebServer/Documents/socialNetwork/static/resources/images/';
  private $relative;
  private $errorImage;
  private $fileName;
  private $fileExt;
  private $fileSize;
  private $ramdomNumber;
  private $newFileName;
  private $registry;


  /*
  * Constructor explicito para este objeto
  */
  public function __construct( Registry $registry, $uploadDirectoryPath = '/wamp/www/socialNetwork/static/resources/images/', $relativePath = 'static/resources/images/', $errorImagePath = 'views/default/images/site/img_error.png')
  {

    $this->registry = $registry;
  	require_once( FRAMEWORK_PATH . 'models/media.inc');
	$media=new Media($this->registry);

  	if(isset($_FILES["FileInput"]) && $_FILES["FileInput"]["error"] == UPLOAD_ERR_OK)
    {
      $this->uploadDirectory = $uploadDirectoryPath;
      $this->relative        = $relativePath;
  	  $this->errorImage      = $errorImagePath;
      $this->fileSize        = getimagesize($_FILES['FileInput']['tmp_name']);
      $this->fileName        = strtolower($_FILES['FileInput']['name']);
      $this->fileExt         = substr($this->fileName, strrpos($this->fileName, '.'));
      $this->ramdomNumber    = rand(0, 9999999999);
      $this->newFileName     = $this->ramdomNumber.$this->fileExt;

      if(move_uploaded_file($_FILES['FileInput']['tmp_name'], $this->uploadDirectory.$this->newFileName ))
      {

      	$media->setName(htmlspecialchars($this->registry->getObject('db')->sanitizeData($_POST['imageName']),ENT_IGNORE));
        $media->setUrl($this->relative.$this->newFileName);
        $media->setSize($this->fileSize[0]."x".$this->fileSize[1]);
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
	      echo "<img id='imageUploaded' src='".$this->relative.$this->newFileName."'  style='border:1px;' class='img-thumbnail' />";
        exit();
        
      }else{
        echo "<img src='".$this->errorImage."'  style='border:1px;' class='img-thumbnail' />";
        exit();
      }


    }else
    {
      echo "<img src='".$this->errorImage."'  style='border:1px;' class='img-thumbnail' />";
      exit();
    }
	
  }

   

}
?>