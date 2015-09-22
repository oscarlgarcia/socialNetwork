/**
* Plugin para subir una imagen de forma generica en PAGE
*/

$(function() {


  //---- Para subir el archivo de imagen ----- 
  // el boton se llama uploadbtn    
  // el formulario uploadImageForm
  $('#uploadbtn').click(function(){ 
    $(this).button('loading');   
    var iData = new FormData($('#uploadImageForm')[0]);
    var action = $("#uploadImageForm").attr('action');
    $.ajax({
      type: "POST",
      processData: false,
      contentType: false,
      url: action,
      data: iData,
      beforeSend: beforeSubmit,
      resetForm: true,
      success: onSucess
    }); 
    return false; 
  });




  function onSucess(msg)
  {
    $('#output').html(msg);
    $('#uploadbtn').button('reset');
    $('#tags').importTags('');
    $("#uploadImageForm").trigger("reset");
    $("#uploadErrorMsg").fadeOut('slow'); 
  } 


  function beforeSubmit()
  {
   
    if($.trim($('#imageName').val()).length == 0 ) 
    {  
      $("#uploadErrorMsg").html("Falta el nombre de la imagen").fadeIn('slow'); 
      $('#uploadbtn').button('reset');   
      return false;  
    }

    if($.trim($('#tags').val()).length == 0 ) 
    {  
      $("#uploadErrorMsg").html("Nos falta los Tags").fadeIn('slow');
      $('#uploadbtn').button('reset');    
      return false;  
    }

    if($.trim($('#FileInput').val()).length == 0 ) 
    {  
      $("#uploadErrorMsg").html("Falta la imagen").fadeIn('slow');
      $('#uploadbtn').button('reset');    
      return false;  
    }
  
    if (window.File && window.FileReader && window.FileList && window.Blob)
    {
      var fsize = $('#FileInput')[0].files[0].size; //get file size
      var ftype = $('#FileInput')[0].files[0].type; // get file type
      switch(ftype)
      {
        case 'image/png': 
        case 'image/gif': 
        case 'image/jpeg': 
        case 'image/jpg':  
        case 'image/pjpeg':
          break;
        default:
          $("#uploadErrorMsg").html("Tipo de archivo invalido:"+ftype).fadeIn('slow');
          $('#uploadbtn').button('reset');   
          return false;  
      }
    
      if(fsize>1048576) 
      {
        $("#uploadErrorMsg").html("La imagen es grande:"+fsize).fadeIn('slow');
        $('#uploadbtn').button('reset');   
        return false;
      }
    }
    else
    {
      $("#uploadErrorMsg").html("Please upgrade your browser").fadeIn('slow');
      return false;
    }
  }

  // Cargamos los tags para la imagen
  $('#tags').tagsInput({
    width:'auto',
    defaultText:'+tag',
    maxChars : 10,
    height:'34px'
  });


});