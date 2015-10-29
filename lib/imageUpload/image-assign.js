/*
* Plugin para asignar al Input el Id de la imagen que se selecciona
*/
 $(function() { 

  //------ Enlazamos el evento click para cada imagen de categoria
  $(".tab-content").delegate(".image_browser td img","click", function() 
  {
    $("#image").val($( this ).data("media"));
    $("#mediaModal").modal('toggle');
  });

});