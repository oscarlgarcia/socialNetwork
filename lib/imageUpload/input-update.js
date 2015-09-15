 /**
 * Plugin para cambiar el nombre del input de la imagen 
 */
 $(function() { 

    //mostramos en nombre del archivo en el input
    $('#FileInput').change(function() { 
      $("#fileName").val($(this).val());
    });

  });