 $(function() { 

  //------ Enlazamos el evento click para cada imagen de categoria
  $(".tab-content").delegate(".image_browser td img","click", function() 
  {
    $("#categoryImage").val($( this ).data("category"));
    $("#mediaModal").modal('toggle');
  });

});