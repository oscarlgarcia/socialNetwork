$(function() {

  // Cargamos el notificador
  var source = new EventSource("http://localhost/socialNetwork/notification");

  // Creamos el listener ( lo que se hara cuando se reciba el evento)
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

  // escuchamos los eventos     
  //source.addEventListener("open", listener);
  source.addEventListener("message", listener);
  //source.addEventListener("error", listener);

  //oculta el label de notificacion
  $("#notification-button").click(function () {
      $("#notification-label").hide("slow");
  });



});