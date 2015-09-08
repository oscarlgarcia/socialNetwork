$(function() {
  
 $(".media_btn a").bind( "click", function() 
 {
   $("#media_id").attr("src",$(this).data("url")); 
 });


});