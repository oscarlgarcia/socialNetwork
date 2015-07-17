$(function() {

  //------ Enlazamos el evento click para cada pagina
  $(".tree li a" ).bind( "click", function() 
  {
    window.location.href = "admin_cms/edit/"+$( this ).data("parent");
  });

});