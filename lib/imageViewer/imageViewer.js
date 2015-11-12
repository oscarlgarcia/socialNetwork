/*
* Plugin para ver la imagen
*/
 $(function() { 

  //------ Enlazamos el evento click para cada imagen de categoria
  $("#dev-table").delegate("td img","click", function() 
  {
    $("#imageViewer").attr("src",$( this ).data("url"));
    $(".modal-title").text($( this ).data("title"));
    $("#viewerModal").modal('toggle');
  });

});