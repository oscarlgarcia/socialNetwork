<?php
//
//	Un script de captcha sencillo basado en el de 
//  Cory LaViska de "A Beautiful Site" 
//
class Captcha {

  private $registry;
  private $captcha_config;


   /**
   * Constructor
   */
  public function __construct( Registry $registry,$config = array() ) 
  {
	$this->registry = $registry;
    // poner todo esto en el constants
	$bg_path = dirname(__FILE__) . '/backgrounds/';
	$font_path = dirname(__FILE__) . '/fonts/';
	$this->captcha_config = array(
		'code' => '',
		'min_length' => 7,
		'max_length' => 7,
		'backgrounds' => array(
			$bg_path . '45-degree-fabric.png',
			$bg_path . 'cloth-alike.png',
			$bg_path . 'grey-sandbag.png',
			$bg_path . 'kinda-jean.png',
			$bg_path . 'polyester-lite.png',
			$bg_path . 'stitched-wool.png',
			$bg_path . 'white-carbon.png',
			$bg_path . 'stars.png',
			$bg_path . 'turtle.png',
			$bg_path . 'tiles.png',
			$bg_path . 'white-wave.png'
		),
		'fonts' => array(
			$font_path . 'times_new_yorker.ttf',
			$font_path . '1942.ttf',
			$font_path . 'SolsHand.ttf'
		),
		'characters' => 'ABCDEFGHJKLMNPRSTUVWXYZabcdefghjkmnprstuvwxyz23456789',
		'min_font_size' => 20,
		'max_font_size' => 24,
		'color' => '#666',
		'angle_min' => 0,
		'angle_max' => 10,
		'shadow' => true,
		'shadow_color' => '#fff',
		'shadow_offset_x' => -1,
		'shadow_offset_y' => 1
	);
	
	// Si viene un array sobrescribo el de default
	if( is_array($config) ) {
		foreach( $config as $key => $value ) $this->captcha_config[$key] = $value;
	}
	
	// aplicamos validaciones
	if( $this->captcha_config['min_length'] < 1 ) $this->captcha_config['min_length'] = 1;
	if( $this->captcha_config['angle_min'] < 0 ) $this->captcha_config['angle_min'] = 0;
	if( $this->captcha_config['angle_max'] > 10 ) $this->captcha_config['angle_max'] = 10;
	if( $this->captcha_config['angle_max'] < $this->captcha_config['angle_min'] ) $this->captcha_config['angle_max'] = $this->captcha_config['angle_min'];
	if( $this->captcha_config['min_font_size'] < 10 ) $this->captcha_config['min_font_size'] = 10;
	if( $this->captcha_config['max_font_size'] < $this->captcha_config['min_font_size'] ) $this->captcha_config['max_font_size'] = $this->captcha_config['min_font_size'];
	
  }
 
  function generateCaptcha(){

    // usamos milliseconds en lugar de seconds
	srand(microtime() * 100);

	// Si no hay "CODE" generamos el captcha aleatorio
	if( empty($this->captcha_config['code']) ) {
		$this->captcha_config['code'] = '';
		$length = rand($this->captcha_config['min_length'], $this->captcha_config['max_length']);
		while( strlen($this->captcha_config['code']) < $length ) {
			$this->captcha_config['code'] .= substr($this->captcha_config['characters'], rand() % (strlen($this->captcha_config['characters'])), 1);
		}
	}
	
	// Generamos el html
	$image_src = "captcha/image";
	$_SESSION['_CAPTCHA']['config'] = serialize($this->captcha_config);
	return array(
		'code' => $this->captcha_config['code'],
		'image_src' => $image_src
	);




  }

  private function hex2rgb($hex_str, $return_string = false, $separator = ',') {
    $hex_str = preg_replace("/[^0-9A-Fa-f]/", '', $hex_str); // Gets a proper hex string
	$rgb_array = array();
	if( strlen($hex_str) == 6 ) {
	  $color_val = hexdec($hex_str);
	  $rgb_array['r'] = 0xFF & ($color_val >> 0x10);
	  $rgb_array['g'] = 0xFF & ($color_val >> 0x8);
	  $rgb_array['b'] = 0xFF & $color_val;
	} elseif( strlen($hex_str) == 3 ) {
	  $rgb_array['r'] = hexdec(str_repeat(substr($hex_str, 0, 1), 2));
	  $rgb_array['g'] = hexdec(str_repeat(substr($hex_str, 1, 1), 2));
	  $rgb_array['b'] = hexdec(str_repeat(substr($hex_str, 2, 1), 2));
	} else {
	  return false;
	}
	  return $return_string ? implode($separator, $rgb_array) : $rgb_array;
	}

  // Comprueba que la palabra corresponda con la imagen
  function checkCaptcha($word){
    $this->captcha_config = unserialize($_SESSION['_CAPTCHA']['config']);
    unset($_SESSION['_CAPTCHA']);
    return ($word == $this->captcha_config['code'])?true:false;
  }


  function drawImage(){
  
    $this->captcha_config = unserialize($_SESSION['_CAPTCHA']['config']);
	if( !$this->captcha_config ) exit();
    
    // Use milliseconds instead of seconds
	srand(microtime() * 100);
	
	// Pick random background, get info, and start captcha
	$background = $this->captcha_config['backgrounds'][rand(0, count($this->captcha_config['backgrounds']) -1)];

	list($bg_width, $bg_height, $bg_type, $bg_attr) = getimagesize($background);
	
	$captcha = imagecreatefrompng($background);

	$color = $this->hex2rgb($this->captcha_config['color']);
	$color = imagecolorallocate($captcha, $color['r'], $color['g'], $color['b']);
	
	// Determine text angle
	$angle = rand( $this->captcha_config['angle_min'], $this->captcha_config['angle_max'] ) * (rand(0, 1) == 1 ? -1 : 1);
	
	// Select font randomly
	$font = $this->captcha_config['fonts'][rand(0, count($this->captcha_config['fonts']) - 1)];
	
    //Set the font size.
	$font_size = rand($this->captcha_config['min_font_size'], $this->captcha_config['max_font_size']);
	$text_box_size = imagettfbbox($font_size, $angle, $font, $this->captcha_config['code']);
	
	// Determine text position
	$box_width = abs($text_box_size[6] - $text_box_size[2]);
	$box_height = abs($text_box_size[5] - $text_box_size[1]);
	$text_pos_x_min = 0;
	$text_pos_x_max = ($bg_width) - ($box_width);
	$text_pos_x = rand($text_pos_x_min, $text_pos_x_max);			
	$text_pos_y_min = $box_height;
	$text_pos_y_max = ($bg_height) - ($box_height / 2);
	$text_pos_y = rand($text_pos_y_min, $text_pos_y_max);
    
    // Draw shadow
	if( $this->captcha_config['shadow'] ){
		$shadow_color = $this->hex2rgb($this->captcha_config['shadow_color']);
	 	$shadow_color = imagecolorallocate($captcha, $shadow_color['r'], $shadow_color['g'], $shadow_color['b']);
		imagettftext($captcha, $font_size, $angle, $text_pos_x + $this->captcha_config['shadow_offset_x'], $text_pos_y + $this->captcha_config['shadow_offset_y'], $shadow_color, $font, $this->captcha_config['code']);	
	}
	
	// Draw text
	imagettftext($captcha, $font_size, $angle, $text_pos_x, $text_pos_y, $color, $font, $this->captcha_config['code']);	
	
	// Output image
	header("Content-type: image/png");
	imagepng($captcha);

  }

  function printValues(){

  	var_dump($this->captcha_config);
  }


}