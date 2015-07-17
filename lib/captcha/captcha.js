$(function() {
  

  $("#captcha_reload").click(function(){
   $("#captcha_img").attr('src','captcha/'+ new Date().getTime());
  });


});