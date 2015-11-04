$(function() {

  // Cargamos el notificador
  var source = new EventSource("http://localhost/socialNetwork/notification");

  // Creamos el listener para mostrar las notificaciones
  var listener = function (event) {
    var n = noty(
    {
      layout: 'bottomRight',
      text: event.data,
      type: 'information',
      maxVisible: 50,
      timeout: 10000
    }
    );

    
  };

  // Creamos el listener para la barra
  var notifBar = function (event) {
    $("#notification-label").show();  
    $("#notification-count").text(event.data);
    $("#notification-count").show();
  };

  // escuchamos los eventos     
  //source.addEventListener("open", listener);
  source.addEventListener("announce", notifBar);
  source.addEventListener("show", listener);

  //oculta el label de notificacion
  $("#notification-button").click(function () {
    $("#notification-label").hide();
  });


});