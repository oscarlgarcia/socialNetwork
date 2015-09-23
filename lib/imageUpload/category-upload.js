/**
 * Plugin para subir la imagen de la categoria 
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
    $("#uploadImageForm").trigger("reset");
    $("#error_msg").fadeOut('slow'); 
  }

  function beforeSubmit()
  {
   
    if($.trim($('#categoryName').val()).length == 0 ) 
    {  
      $("#error-msg").html("Falta el nombre de la Categoria").fadeIn('slow'); 
      $('#uploadbtn').button('reset');   
      return false;  
    }

    if($.trim($('#categoryDescription').val()).length == 0 ) 
    {  
      $("#error-msg").html("Falta la descripci&oacute;n de la Categoria").fadeIn('slow'); 
      $('#uploadbtn').button('reset');   
      return false;  
    }

    if($.trim($('#FileInput').val()).length == 0 ) 
    {  
      $("#error-msg").html("Falta la imagen").fadeIn('slow');
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
          $("#error-msg").html("Tipo de archivo invalido:"+ftype).fadeIn('slow');
          $('#uploadbtn').button('reset');   
          return false;  
      }
    
      if(fsize>1048576) 
      {
        $("#error-msg").html("La imagen es grande:"+fsize).fadeIn('slow');
        $('#uploadbtn').button('reset');   
        return false;
      }
    }
    else
    {
      $("#error-msg").html("Please upgrade your browser").fadeIn('slow');
      return false;
    }
  }

});