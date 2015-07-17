$(function() {

  $("#search").focus(function() {
    $("#search").animate(
      {
       width: 400,
      }, 
      500, 
      "swing");

  });

  $("#search").focusout(function() {
    $("#search").animate(
      {
       width: 200,
      }, 
      500, 
      "swing");
  });




});