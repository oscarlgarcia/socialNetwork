-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 22-06-2015 a las 17:54:31
-- Versión del servidor: 5.6.17
-- Versión de PHP: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `ecpsn`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `badges`
--

CREATE TABLE IF NOT EXISTS `badges` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `description` varchar(200) NOT NULL,
  `path_image` varchar(400) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Tabla que almacena los badges\n' AUTO_INCREMENT=6 ;

--
-- Volcado de datos para la tabla `badges`
--

INSERT INTO `badges` (`ID`, `name`, `description`, `path_image`) VALUES
(1, 'no.badge', 'No Badge', '/no'),
(2, 'user.activate', 'El Usuario ha activado el perfil', '/www/wwww'),
(3, 'user.fav.get', 'El usuario ha recibido un favorito', 'favbadge'),
(4, 'user.comment.add', 'Se ha agregado un comentario', 'commentAdd'),
(5, 'user.comment.get', 'Se ha recibido un comentario', 'commentGet');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `badges_achieved`
--

CREATE TABLE IF NOT EXISTS `badges_achieved` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_User` bigint(20) NOT NULL,
  `ID_Badge` bigint(20) NOT NULL,
  `showed` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `fk1_idx` (`ID_User`),
  KEY `fk2_idx` (`ID_Badge`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Almacena la relacion de badges por usuario\n' AUTO_INCREMENT=38 ;

--
-- Volcado de datos para la tabla `badges_achieved`
--

INSERT INTO `badges_achieved` (`ID`, `ID_User`, `ID_Badge`, `showed`) VALUES
(20, 8, 2, 0),
(21, 8, 2, 0),
(22, 10, 2, 0),
(23, 8, 3, 0),
(24, 8, 4, 0),
(25, 10, 4, 0),
(26, 8, 5, 0),
(27, 11, 2, 0),
(28, 10, 2, 0),
(29, 12, 2, 0),
(30, 13, 2, 0),
(31, 14, 2, 0),
(32, 13, 3, 0),
(33, 13, 5, 0),
(34, 10, 5, 0),
(35, 10, 3, 0),
(36, 14, 3, 0),
(37, 14, 5, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `category`
--

CREATE TABLE IF NOT EXISTS `category` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Tabla que almacena las categorias',
  `name` varchar(100) NOT NULL,
  `image_category` varchar(400) NOT NULL,
  `description` varchar(400) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Tabla para guardar los lenguajes y cualquier otra categoria  /* comment truncated */ /*de snippets y otras actividades*/' AUTO_INCREMENT=18 ;

--
-- Volcado de datos para la tabla `category`
--

INSERT INTO `category` (`ID`, `name`, `image_category`, `description`) VALUES
(1, 'Java', 'java.png', ' Lorem ipsum dolor sit amet, consectetur adipiscing elit. \n        Sed feugiat consectetur pellentesque. Nam ac elit risus, \n        ac blandit dui. Duis rutrum porta tortor ut convallis.\n        Duis rutrum porta tortor ut convallis.'),
(2, 'Ruby', 'ruby.png', 'Un lenguaje de programación dinámico y de código abierto enfocado en la simplicidad y productividad. Su elegante sintaxis se siente natural al leerla y fácil al escribirla.'),
(3, 'Groovy', 'groovy.png', ' Lorem ipsum dolor sit amet, consectetur adipiscing elit. \n        Sed feugiat consectetur pellentesque. Nam ac elit risus, \n        ac blandit dui. Duis rutrum porta tortor ut convallis.\n        Duis rutrum porta tortor ut convallis.'),
(4, 'PHP', 'php.png', 'PHP (acrónimo recursivo de PHP: Hypertext Preprocessor) es un lenguaje de código abierto muy popular especialmente adecuado para el desarrollo web y que puede ser incrustado en HTML.'),
(5, 'CSS', 'css3.png', ''),
(6, 'HTML5', 'HTML5.png', ''),
(7, 'Javascript', 'javascript.svg', ''),
(12, 'Dart', 'dart.png', ''),
(13, 'Scala', 'scala.png', ''),
(14, 'Python', 'python.png', ''),
(15, 'AngularJs', 'angular.png', 'AngularJS es un framework MVC de JavaScript para el Desarrollo Web Front End que permite crear aplicaciones SPA (Single-Page Applications).'),
(16, 'MySQL', 'mysql.png', ''),
(17, 'Clojure', 'clojure.png', 'Clojure es un lenguaje de programación de propósito general dialecto de Lisp. ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comments_links`
--

CREATE TABLE IF NOT EXISTS `comments_links` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `added` datetime NOT NULL,
  `approved` tinyint(1) NOT NULL,
  `comment` varchar(1000) NOT NULL,
  `ID_User` bigint(20) NOT NULL,
  `ID_Link` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_comments_links1_idx` (`ID_User`),
  KEY `fk_comments_links2_idx` (`ID_Link`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Volcado de datos para la tabla `comments_links`
--

INSERT INTO `comments_links` (`ID`, `added`, `approved`, `comment`, `ID_User`, `ID_Link`) VALUES
(1, '2014-12-17 00:14:30', 0, 'sam`Ã±e\r\n', 8, 1),
(2, '2014-12-22 01:19:21', 0, 'ejemplo desde mac', 8, 1),
(3, '2015-03-27 14:06:43', 0, 'asdasdsdfsdf\r\n', 8, 18),
(4, '2015-03-27 14:06:52', 0, 'sdfsdfs\r\n', 8, 19),
(5, '2015-06-08 15:40:27', 0, 'assfsdfsadf', 8, 18);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comment_snippet`
--

CREATE TABLE IF NOT EXISTS `comment_snippet` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Identificador del Comentario',
  `comment` varchar(1000) NOT NULL COMMENT 'Comentario',
  `added` datetime NOT NULL COMMENT 'Fecha de Agregado ',
  `ID_User` bigint(20) NOT NULL COMMENT 'Usuario que lo realizo',
  `ID_Snippet` bigint(20) NOT NULL COMMENT 'Snippet al que pertenece',
  `approved` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID` (`ID`),
  KEY `ID_User` (`ID_User`),
  KEY `FK_comment_snippet2` (`ID_Snippet`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=111 ;

--
-- Volcado de datos para la tabla `comment_snippet`
--

INSERT INTO `comment_snippet` (`ID`, `comment`, `added`, `ID_User`, `ID_Snippet`, `approved`) VALUES
(61, 'Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim', '2014-10-01 12:44:06', 8, 38, 1),
(72, '&lt;!doctype html&gt;\r\n&lt;html lang=&quot;en&quot;&gt;\r\n&lt;head&gt;\r\n  &lt;meta charset=&quot;utf-8&quot;&gt;\r\n  &lt;title&gt;The Brand New Web Site&lt;/title&gt;\r\n  &lt;meta name=&quot;description&quot; content=&quot;The Brand New Web Site&quot;&gt;\r\n  &lt;meta name=&quot;author&quot; content=&quot;Barattalo.it&quot;&gt;\r\n  &lt;link rel=&quot;stylesheet&quot; href=&quot;css/styles.css?v=1.0&quot;&gt;\r\n  &lt;!--[if lt IE 9]&gt;\r\n  &lt;script src=&quot;http://html5shiv.googlecode.com/svn/trunk/html5.js&quot;&gt;&lt;/script&gt;\r\n  &lt;![endif]--&gt;\r\n&lt;/head&gt;\r\n&lt;body&gt;\r\n \r\n \r\n \r\n	&lt;!-- run javascript at the end --&gt;\r\n  &lt;script src=&quot;js/scripts.js&quot;&gt;&lt;/script&gt;\r\n&lt;/body&gt;\r\n&lt;/html&gt;', '2014-10-01 13:38:55', 8, 38, 1),
(75, 'Fenomenal lo guardar&Atilde;&copy; se&Atilde;&plusmn;or mac''allistair ', '2014-10-01 13:48:15', 8, 38, 1),
(79, 'delete from snippets where 1; commit', '2014-10-01 13:49:51', 8, 38, 1),
(80, 'fenomenal se&ntilde;or avi&oacute;n mac''alistais \\|@#~&euro;&not;][{}&lt;&lt;&gt;&gt;&gt;&lt;&lt;&ordf;&ordf;&ordf;!!&quot;&quot;&middot;&middot;&quot;%&amp;%$&amp;((/()''=()=?^PK&Ntilde;HKJ', '2014-10-01 13:50:37', 8, 38, 1),
(81, 'Good Eric Meyer reset!', '2014-10-01 14:29:09', 8, 40, 1),
(83, 'fdghfdghdfh', '2014-10-01 17:14:36', 8, 38, 1),
(86, 'Test Comment', '2014-10-21 14:31:00', 10, 68, 1),
(87, 'Esto es la leche!!', '2014-10-22 17:39:24', 8, 71, 1),
(88, 'Gracias Se&ntilde;or macallistar''s ', '2014-10-22 17:41:48', 10, 71, 1),
(89, 'Esto es asi?\r\n \r\npreg_match(&quot;/(enum\\((.*?)\\))/&quot;, $result[&quot;Type&quot;], $enumArray);\r\n$getEnumSet = explode(&quot;''&quot;, $enumArray[&quot;2&quot;]);\r\n$getEnumSet = preg_replace(&quot;/,/&quot;, &quot;&quot;, $getEnumSet);\r\n\r\n', '2014-10-22 17:42:06', 10, 71, 1),
(90, 'wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwcxxxxxxxxxxcxcxcxcx', '2014-11-03 16:48:11', 8, 71, 1),
(91, 'Ejemplo con Ajax loaded', '2014-11-04 14:07:29', 8, 70, 1),
(92, 'señor', '2014-11-04 14:56:51', 8, 38, 1),
(93, 'avión señorito ///////\\\\\\\\\\\\&lt;&gt;'''''''''''''''''''''''' ª!!"!ª"·ª!·$!·"$5$·$&amp;/%&amp;/()&amp;)=()=¿)=¿)=¡;:;:;:_;_:&gt;Z&gt;ñ´ñ´ñ', '2014-11-04 14:57:21', 8, 38, 1),
(94, 'Äáéíúó ', '2014-11-04 14:59:23', 8, 38, 1),
(95, 'asdfasdfasdf\r\nasasdfas\r\ndfa\r\nsdf\r\nasdf', '2014-11-04 18:06:00', 8, 71, 1),
(96, 'sdfthsrty srthger sy\r\nhgw trg\r\ns d\r\nffgs\r\ndffg \r\n', '2014-11-04 18:06:05', 8, 71, 1),
(97, 'Limbo!!\r\n', '2014-12-02 12:55:35', 8, 79, 1),
(100, 'dfgdsfgsdfgsdfgsdfgsdfgsdfg', '2015-02-10 00:51:31', 8, 89, 1),
(101, 'Otro comment', '2015-02-10 00:56:10', 10, 89, 1),
(102, 'efsdfasfasfd', '2015-02-14 20:05:12', 8, 90, 1),
(103, 'dfdfgdafgsdfg', '2015-02-15 13:47:56', 10, 90, 1),
(104, 'Test', '2015-03-01 21:06:23', 8, 41, 1),
(107, 'fsdfsdf', '2015-05-13 17:07:57', 8, 80, 1);

--
-- Disparadores `comment_snippet`
--
DROP TRIGGER IF EXISTS `comment_snippet_add`;
DELIMITER //
CREATE TRIGGER `comment_snippet_add` AFTER INSERT ON `comment_snippet`
 FOR EACH ROW UPDATE snippets SET totalComments = (totalComments+1) WHERE snippets.ID = NEW.ID_Snippet
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `controllers`
--

CREATE TABLE IF NOT EXISTS `controllers` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `controller` varchar(255) NOT NULL,
  `active` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Para registrar los controladores del site\n' AUTO_INCREMENT=12 ;

--
-- Volcado de datos para la tabla `controllers`
--

INSERT INTO `controllers` (`ID`, `controller`, `active`) VALUES
(1, 'authenticate', 1),
(2, 'profile', 0),
(3, 'snippets', 1),
(4, 'links', 1),
(5, 'admin_users', 1),
(6, 'admin_snippets', 1),
(7, 'admin_links', 1),
(8, 'tutoriales', 1),
(9, 'admin_cms', 1),
(10, 'captcha', 1),
(11, 'tuts', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `event`
--

CREATE TABLE IF NOT EXISTS `event` (
  `eventName` varchar(100) NOT NULL,
  `description` varchar(450) NOT NULL,
  `imageEvent` varchar(400) NOT NULL,
  PRIMARY KEY (`eventName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Registra los eventos de la aplicacion';

--
-- Volcado de datos para la tabla `event`
--

INSERT INTO `event` (`eventName`, `description`, `imageEvent`) VALUES
('user.activate', 'Evento que ocurre cuando un usuario activa su perfil', ''),
('user.comment.add', 'El usuario ha comentado algo', 'glyphicon-pencil'),
('user.comment.get', 'EL usuario ha recibido un comentario', ''),
('user.fav.add', 'El usuario hace un favorito', 'glyphicon-heart'),
('user.fav.del', 'El usuario borra un favorito', 'glyphicon-heart-empty'),
('user.fav.get', 'El usuario recibe un favorito', ''),
('user.link.add', 'El usuario ha agregado un Link', ''),
('user.login', 'Evento que ocurre cuando un usuario inicia sesión', ''),
('user.logout', 'Evento que ocurre cuando un usuario cierra sesión', ''),
('user.page.add', 'El usuario ha agregado una pagina al cms', 'fa-leanpub'),
('user.password.forgot', 'Evento que ocurre cuando un usuario solicita cambio de contraseña por olvido', ''),
('user.password.reset', 'Evento que ocurre cuando un usuario cambia la constraseña', ''),
('user.profile.view', 'Evento generado al ver nuestro perfil', ''),
('user.rating.add', 'El usuario a hecho un rating', 'glyphicon-star'),
('user.snippet.add', 'Evento generado al añadir un snippet', 'glyphicon-plus-sign');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gamification_rules`
--

CREATE TABLE IF NOT EXISTS `gamification_rules` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `eventName` varchar(100) NOT NULL,
  `ID_Badge` bigint(20) NOT NULL,
  `threshold` bigint(20) NOT NULL,
  `experience_points` bigint(20) NOT NULL,
  `reputation_points` bigint(20) NOT NULL,
  `level_points` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_gamification_rules_2_idx` (`ID_Badge`),
  KEY `fk_gamification_rules_1_idx` (`eventName`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Almacena las reglas de asignacion de puntos y badges' AUTO_INCREMENT=7 ;

--
-- Volcado de datos para la tabla `gamification_rules`
--

INSERT INTO `gamification_rules` (`ID`, `eventName`, `ID_Badge`, `threshold`, `experience_points`, `reputation_points`, `level_points`) VALUES
(1, 'user.activate', 2, 1, 10, 1, 0),
(2, 'user.snippet.add', 2, 1, 10, 1, 0),
(3, 'user.snippet.add', 1, 35, 10, 1, 1),
(4, 'user.fav.get', 3, 1, 15, 3, 0),
(5, 'user.comment.add', 4, 1, 11, 1, 0),
(6, 'user.comment.get', 5, 1, 11, 1, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `links`
--

CREATE TABLE IF NOT EXISTS `links` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `URL` mediumtext NOT NULL,
  `Description` varchar(400) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `ID_User` bigint(20) NOT NULL,
  `rating` decimal(10,2) NOT NULL DEFAULT '0.00',
  `totalVotes` double NOT NULL DEFAULT '0',
  `totalFav` double NOT NULL DEFAULT '0',
  `totalComments` double NOT NULL DEFAULT '0',
  `added` datetime NOT NULL,
  `totalBroken` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `fk_link_user_idx` (`ID_User`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=20 ;

--
-- Volcado de datos para la tabla `links`
--

INSERT INTO `links` (`ID`, `URL`, `Description`, `Title`, `ID_User`, `rating`, `totalVotes`, `totalFav`, `totalComments`, `added`, `totalBroken`) VALUES
(1, 'http://www.dzone.com/links/r/how_to_scroll_to_the_top_of_a_webpage_using_jquer.html', 'Put forth are a few steps to send push notification with sound and badge effect.', 'Sending push notifications with sound and badge effect', 10, '5.00', 1, 0, 0, '2014-11-18 00:00:00', 0),
(2, 'http://www.dzone.com/links/r/how_to_scroll_to_the_top_of_a_webpage_using_jquer.html', 'Put forth are a few steps to send push notification with sound and badge effect.', 'Sending push notifications with sound and badge effect 2', 11, '4.00', 1, 0, 0, '2014-11-18 00:00:00', 0),
(14, 'https://gorails.com/setup/osx/10.10-yosemite', 'We will be setting up a Ruby on Rails development environment on Mac OS X 10.10 Yosemite.\r\n\r\nOlder versions of OS X are mostly compatible so follow along as far as you can and then Google search for any problems you run into. There are plenty of people who have documented solutions for them.', 'Setup Ruby On Rails on Mac OS X 10.10 Yosemite', 8, '0.00', 0, 0, 0, '2015-01-05 01:43:57', 0),
(15, 'sdfsdfsdf', 'sdfsdfsdf', 'sdfsdf', 8, '0.00', 0, 0, 0, '2015-01-05 02:31:43', 0),
(16, 'http://sourcecookbook.com/es/recipes/41/validar-una-url-con-expresiones-regulares', 'Como Validar una URL ', 'Como validar una URL', 8, '0.00', 0, 0, 0, '2015-01-06 01:59:43', 0),
(17, 'http://radar.oreilly.com/nat/page/121', 'Links de interes', 'Radar Oreilly', 8, '0.00', 0, 0, 0, '2015-01-06 17:47:44', 0),
(18, 'http://www.lexicalist.com/', 'Lexicalist uses artificial intelligence to analyze the web and figure out who''s talking about what. The result is a demographic picture of language in actual use today.', 'LEXICALIST', 8, '2.00', 1, 0, 0, '2015-01-06 17:48:16', 0),
(19, '', '', '', 8, '5.00', 1, 0, 0, '2015-03-27 13:48:54', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lista_favoritos_snippets`
--

CREATE TABLE IF NOT EXISTS `lista_favoritos_snippets` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Snippets` bigint(20) NOT NULL,
  `ID_User` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_lista_favoritos_snippets_1_idx` (`ID_Snippets`),
  KEY `fk_lista_favoritos_snippets_2_idx` (`ID_User`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Almacena los snippets favoritos del usuario' AUTO_INCREMENT=100 ;

--
-- Volcado de datos para la tabla `lista_favoritos_snippets`
--

INSERT INTO `lista_favoritos_snippets` (`ID`, `ID_Snippets`, `ID_User`) VALUES
(27, 45, 8),
(40, 71, 10),
(46, 71, 8),
(50, 75, 8),
(51, 74, 8),
(54, 38, 8),
(56, 81, 8),
(61, 89, 8),
(62, 89, 10),
(63, 90, 8),
(64, 90, 10),
(66, 41, 8),
(69, 54, 8),
(98, 80, 8),
(99, 79, 8);

--
-- Disparadores `lista_favoritos_snippets`
--
DROP TRIGGER IF EXISTS `fav_snippet__add`;
DELIMITER //
CREATE TRIGGER `fav_snippet__add` AFTER INSERT ON `lista_favoritos_snippets`
 FOR EACH ROW UPDATE snippets SET totalFav = totalFav+1 WHERE snippets.ID = NEW.ID_Snippets
//
DELIMITER ;
DROP TRIGGER IF EXISTS `fav_snippet_del`;
DELIMITER //
CREATE TRIGGER `fav_snippet_del` BEFORE DELETE ON `lista_favoritos_snippets`
 FOR EACH ROW begin
IF @disable_trigger IS NULL THEN
UPDATE snippets SET totalFav = IF( totalFav>0 ,totalFav-1, 0)WHERE snippets.ID = OLD.ID_Snippets;
END IF;
end
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lista_tag_snippet`
--

CREATE TABLE IF NOT EXISTS `lista_tag_snippet` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Tag` bigint(20) NOT NULL,
  `ID_Snippets` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_Lista_Tag_Snippet_1_idx` (`ID_Tag`),
  KEY `fk_Lista_Tag_Snippet_2_idx` (`ID_Snippets`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Mantiene la relacion de tags por snippet' AUTO_INCREMENT=173 ;

--
-- Volcado de datos para la tabla `lista_tag_snippet`
--

INSERT INTO `lista_tag_snippet` (`ID`, `ID_Tag`, `ID_Snippets`) VALUES
(1, 1, 38),
(2, 2, 38),
(3, 3, 38),
(4, 4, 38),
(9, 5, 40),
(10, 6, 40),
(11, 3, 40),
(12, 7, 41),
(13, 8, 41),
(14, 6, 41),
(15, 4, 41),
(16, 9, 41),
(17, 10, 43),
(18, 11, 43),
(19, 12, 43),
(20, 4, 43),
(21, 13, 43),
(22, 14, 44),
(23, 3, 44),
(24, 15, 44),
(25, 16, 44),
(26, 17, 44),
(27, 6, 45),
(28, 18, 45),
(29, 19, 45),
(30, 20, 45),
(31, 21, 45),
(32, 22, 45),
(33, 9, 45),
(41, 14, 47),
(42, 14, 47),
(43, 23, 47),
(44, 24, 47),
(45, 14, 48),
(46, 25, 48),
(47, 18, 48),
(48, 26, 48),
(49, 14, 49),
(50, 27, 49),
(51, 28, 49),
(52, 29, 49),
(53, 30, 49),
(54, 6, 50),
(55, 31, 50),
(56, 32, 50),
(57, 33, 50),
(58, 34, 50),
(59, 35, 51),
(60, 36, 51),
(61, 34, 51),
(62, 37, 51),
(63, 31, 51),
(64, 3, 52),
(65, 38, 52),
(66, 39, 52),
(67, 34, 52),
(68, 40, 53),
(69, 41, 53),
(70, 34, 53),
(71, 42, 54),
(72, 31, 54),
(73, 43, 54),
(74, 44, 54),
(75, 45, 55),
(76, 46, 55),
(77, 47, 55),
(78, 48, 55),
(79, 49, 56),
(80, 25, 56),
(81, 46, 56),
(82, 50, 56),
(83, 51, 57),
(84, 52, 57),
(85, 4, 58),
(86, 53, 58),
(87, 54, 58),
(88, 55, 59),
(89, 56, 59),
(90, 4, 59),
(91, 57, 60),
(92, 58, 60),
(93, 34, 60),
(94, 59, 61),
(95, 60, 61),
(96, 61, 61),
(97, 10, 61),
(98, 59, 62),
(99, 60, 62),
(100, 61, 62),
(101, 10, 62),
(102, 62, 63),
(103, 63, 63),
(104, 13, 63),
(105, 62, 64),
(106, 63, 64),
(107, 13, 64),
(108, 55, 65),
(109, 64, 65),
(110, 56, 65),
(111, 55, 66),
(112, 65, 66),
(113, 56, 66),
(114, 66, 67),
(115, 67, 67),
(116, 68, 67),
(117, 69, 67),
(118, 66, 68),
(119, 67, 68),
(120, 68, 68),
(121, 69, 68),
(122, 70, 69),
(123, 71, 69),
(124, 72, 70),
(125, 73, 70),
(126, 74, 71),
(127, 75, 71),
(128, 76, 71),
(129, 77, 71),
(130, 78, 71),
(133, 14, 74),
(134, 14, 75),
(136, 79, 77),
(137, 6, 77),
(138, 80, 77),
(139, 4, 77),
(140, 13, 78),
(141, 81, 78),
(142, 82, 79),
(143, 83, 79),
(144, 84, 79),
(145, 85, 80),
(146, 84, 80),
(147, 14, 80),
(148, 43, 80),
(149, 86, 81),
(150, 87, 81),
(151, 88, 81),
(159, 108, 89),
(160, 109, 90),
(169, 124, 94),
(170, 125, 94),
(171, 126, 94),
(172, 127, 94);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `list_favorites_links`
--

CREATE TABLE IF NOT EXISTS `list_favorites_links` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Users` bigint(20) NOT NULL,
  `ID_Links` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_favorites_links1_idx` (`ID_Links`),
  KEY `fk_favorites_links2_idx` (`ID_Users`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=22 ;

--
-- Volcado de datos para la tabla `list_favorites_links`
--

INSERT INTO `list_favorites_links` (`ID`, `ID_Users`, `ID_Links`) VALUES
(16, 8, 1),
(20, 8, 19),
(21, 8, 18);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `list_favorite_page`
--

CREATE TABLE IF NOT EXISTS `list_favorite_page` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Page` bigint(20) NOT NULL,
  `ID_User` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_favorite_page_1_idx` (`ID_Page`),
  KEY `fk_favorite_page_2_idx` (`ID_User`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `list_media_tags`
--

CREATE TABLE IF NOT EXISTS `list_media_tags` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_media` bigint(20) NOT NULL,
  `ID_tag` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FK_list_tags_idx` (`ID_tag`),
  KEY `FK_listmedia_media_idx` (`ID_media`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Volcado de datos para la tabla `list_media_tags`
--

INSERT INTO `list_media_tags` (`ID`, `ID_media`, `ID_tag`) VALUES
(3, 3, 117),
(4, 3, 118),
(5, 4, 119),
(6, 4, 117),
(7, 5, 86),
(8, 5, 117),
(9, 6, 120),
(10, 6, 117),
(11, 7, 35),
(12, 7, 117),
(13, 8, 3),
(14, 8, 117),
(15, 9, 88);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `list_tags_links`
--

CREATE TABLE IF NOT EXISTS `list_tags_links` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Tags` bigint(20) NOT NULL,
  `ID_Links` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_list_tags_links1_idx` (`ID_Tags`),
  KEY `fk_list_tags_links2_idx` (`ID_Links`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=18 ;

--
-- Volcado de datos para la tabla `list_tags_links`
--

INSERT INTO `list_tags_links` (`ID`, `ID_Tags`, `ID_Links`) VALUES
(1, 3, 1),
(2, 6, 1),
(3, 6, 2),
(6, 89, 14),
(7, 83, 14),
(8, 63, 14),
(9, 93, 14),
(10, 94, 15),
(11, 83, 16),
(12, 95, 16),
(13, 10, 16),
(14, 96, 17),
(15, 85, 18),
(16, 97, 18),
(17, 121, 19);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `list_tag_page`
--

CREATE TABLE IF NOT EXISTS `list_tag_page` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Page` bigint(20) NOT NULL,
  `ID_Tag` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_tag_page_1_idx` (`ID_Page`),
  KEY `fk_tag_page_2_idx` (`ID_Tag`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `logger`
--

CREATE TABLE IF NOT EXISTS `logger` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ipAddress` varchar(100) NOT NULL,
  `route` longtext NOT NULL,
  `date` datetime NOT NULL,
  `session` varchar(100) NOT NULL DEFAULT 'NOSESSION',
  `browser` longtext NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='Tabla para registrar las entradas al site\nRegistrará ' AUTO_INCREMENT=326 ;

--
-- Volcado de datos para la tabla `logger`
--

INSERT INTO `logger` (`ID`, `ipAddress`, `route`, `date`, `session`, `browser`) VALUES
(10, '127.0.0.1', 'tuts', '2015-06-22 10:49:08', '8', '""'),
(11, '127.0.0.1', 'tuts', '2015-06-22 10:49:18', '8', '""'),
(12, '127.0.0.1', 'tuts', '2015-06-22 10:50:53', '8', '""'),
(13, '127.0.0.1', 'tuts', '2015-06-22 10:50:55', '8', '""'),
(14, '127.0.0.1', 'tuts', '2015-06-22 10:52:40', '8', '""'),
(15, '127.0.0.1', 'tuts', '2015-06-22 10:52:42', '8', '""'),
(16, '127.0.0.1', 'tuts', '2015-06-22 11:04:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(17, '127.0.0.1', 'tuts', '2015-06-22 11:05:21', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(18, '127.0.0.1', 'tuts', '2015-06-22 11:05:58', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(19, '127.0.0.1', 'snippets/browse', '2015-06-22 11:06:01', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(20, '127.0.0.1', 'home', '2015-06-22 11:12:12', '8', '""'),
(21, '127.0.0.1', 'home', '2015-06-22 11:13:32', '8', '""'),
(22, '127.0.0.1', 'home', '2015-06-22 11:16:34', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(23, '127.0.0.1', 'snippets/browse', '2015-06-22 11:16:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(24, '127.0.0.1', 'authenticate/logout', '2015-06-22 11:17:07', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(25, '127.0.0.1', 'authenticate/login', '2015-06-22 11:17:11', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(26, '127.0.0.1', '', '2015-06-22 11:17:13', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(27, '127.0.0.1', '', '2015-06-22 11:54:38', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(28, '127.0.0.1', 'admin_cms/browse', '2015-06-22 12:25:58', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(29, '127.0.0.1', 'admin_cms/edit/15', '2015-06-22 12:26:00', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(30, '127.0.0.1', 'admin_users/browse', '2015-06-22 12:26:08', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(31, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 12:50:24', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(32, '127.0.0.1', 'admin_snippets/history/91', '2015-06-22 12:50:41', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(33, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 12:50:43', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(34, '127.0.0.1', 'admin_snippets/history/90', '2015-06-22 12:50:45', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(35, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 12:50:46', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(36, '127.0.0.1', 'admin_snippets/history/81', '2015-06-22 12:50:48', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(37, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 12:50:49', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(38, '127.0.0.1', 'admin_users/browse', '2015-06-22 12:52:07', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(39, '127.0.0.1', 'admin_users/browse', '2015-06-22 12:52:53', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(40, '127.0.0.1', 'authenticate/logout', '2015-06-22 12:53:20', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(41, '127.0.0.1', 'authenticate/login', '2015-06-22 12:53:22', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(42, '127.0.0.1', '', '2015-06-22 12:53:23', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(43, '127.0.0.1', 'snippets/add', '2015-06-22 12:53:25', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(44, '127.0.0.1', 'snippets/register', '2015-06-22 12:53:32', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(45, '127.0.0.1', 'snippets/browse', '2015-06-22 12:53:32', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(46, '127.0.0.1', 'snippets/view/92', '2015-06-22 12:53:33', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(47, '127.0.0.1', 'snippets/show_comment', '2015-06-22 12:53:34', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(48, '127.0.0.1', 'snippets/fav', '2015-06-22 12:53:35', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(49, '127.0.0.1', 'snippets/rating', '2015-06-22 12:53:36', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(50, '127.0.0.1', 'snippets/browse', '2015-06-22 12:53:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(51, '127.0.0.1', 'snippets/view/92', '2015-06-22 12:57:12', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(52, '127.0.0.1', 'snippets/show_comment', '2015-06-22 12:57:12', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(53, '127.0.0.1', 'snippets/unfav', '2015-06-22 12:57:13', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(54, '127.0.0.1', 'snippets/fav', '2015-06-22 12:57:15', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(55, '127.0.0.1', 'snippets/browse', '2015-06-22 12:57:16', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(56, '127.0.0.1', 'snippets/browse', '2015-06-22 12:57:18', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(57, '127.0.0.1', 'snippets/browse', '2015-06-22 12:57:19', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(58, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:00:57', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(59, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:00:57', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(60, '127.0.0.1', 'snippets/comment', '2015-06-22 13:01:00', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(61, '127.0.0.1', 'snippets/browse', '2015-06-22 13:01:02', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(62, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:02:33', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(63, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:02:33', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(64, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:02:34', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(65, '127.0.0.1', 'snippets/fav', '2015-06-22 13:02:35', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(66, '127.0.0.1', 'snippets/browse', '2015-06-22 13:02:36', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(67, '127.0.0.1', 'snippets/browse', '2015-06-22 13:05:09', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(68, '127.0.0.1', 'snippets/browse', '2015-06-22 13:05:11', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(69, '127.0.0.1', 'snippets/browse', '2015-06-22 13:05:11', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(70, '127.0.0.1', 'snippets/browse', '2015-06-22 13:05:11', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(71, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:25', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(72, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:26', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(73, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:26', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(74, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:27', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(75, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:07:29', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(76, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:07:29', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(77, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:30', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(78, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:31', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(79, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:33', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(80, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:07:42', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(81, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:07:42', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(82, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:43', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(83, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(84, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(85, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(86, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(87, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(88, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(89, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(90, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(91, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(92, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:07:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(93, '127.0.0.1', 'snippets/fav', '2015-06-22 13:07:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(94, '127.0.0.1', 'snippets/browse', '2015-06-22 13:07:48', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(95, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:07:59', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(96, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:07:59', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(97, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:08:00', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(98, '127.0.0.1', 'snippets/fav', '2015-06-22 13:08:01', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(99, '127.0.0.1', 'snippets/browse', '2015-06-22 13:08:02', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(100, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:08:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(101, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:08:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(102, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:08:06', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(103, '127.0.0.1', 'snippets/fav', '2015-06-22 13:08:09', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(104, '127.0.0.1', 'snippets/browse', '2015-06-22 13:08:10', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(105, '127.0.0.1', 'snippets/browse', '2015-06-22 13:11:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(106, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:11:39', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(107, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:11:39', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(108, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:11:40', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(109, '127.0.0.1', 'snippets/browse', '2015-06-22 13:11:42', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(110, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:11:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(111, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:11:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(112, '127.0.0.1', 'snippets/fav', '2015-06-22 13:11:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(113, '127.0.0.1', 'snippets/browse', '2015-06-22 13:11:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(114, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:11:55', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(115, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:11:55', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(116, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:11:56', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(117, '127.0.0.1', 'snippets/fav', '2015-06-22 13:11:57', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(118, '127.0.0.1', 'snippets/browse', '2015-06-22 13:11:58', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(119, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:12:13', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(120, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:12:14', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(121, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:12:28', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(122, '127.0.0.1', 'admin_snippets/view/92', '2015-06-22 13:12:31', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(123, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:12:34', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(124, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:12:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(125, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:12:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(126, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:12:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(127, '127.0.0.1', 'snippets/fav', '2015-06-22 13:12:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(128, '127.0.0.1', 'snippets/browse', '2015-06-22 13:12:47', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(129, '127.0.0.1', 'admin_snippets/delete/92', '2015-06-22 13:12:56', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(130, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:12:56', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(131, '127.0.0.1', 'snippets/view/92', '2015-06-22 13:15:46', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(132, '127.0.0.1', 'snippets/browse', '2015-06-22 13:15:51', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(133, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:15:55', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(134, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:15:56', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(135, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:15:57', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(136, '127.0.0.1', 'snippets/browse', '2015-06-22 13:15:59', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(137, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:16:01', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(138, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:16:01', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(139, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:01', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(140, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:03', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(141, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:03', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(142, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:03', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(143, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(144, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(145, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(146, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(147, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(148, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:04', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(149, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(150, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(151, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(152, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(153, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(154, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:16:05', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(155, '127.0.0.1', 'snippets/fav', '2015-06-22 13:16:06', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(156, '127.0.0.1', 'snippets/view/91', '2015-06-22 13:16:07', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(157, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:16:07', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(158, '127.0.0.1', 'snippets/browse', '2015-06-22 13:16:09', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(159, '127.0.0.1', 'admin_snippets/delete/91', '2015-06-22 13:16:18', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(160, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:25:59', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(161, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:26:01', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(162, '127.0.0.1', 'admin_snippets/delete/91', '2015-06-22 13:26:04', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(163, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:26:04', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(164, '127.0.0.1', 'snippets/browse', '2015-06-22 13:26:14', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(165, '127.0.0.1', 'snippets/add', '2015-06-22 13:26:18', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(166, '127.0.0.1', 'snippets/register', '2015-06-22 13:26:24', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(167, '127.0.0.1', 'snippets/browse', '2015-06-22 13:26:24', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(168, '127.0.0.1', 'snippets/view/93', '2015-06-22 13:26:26', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(169, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:26:26', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(170, '127.0.0.1', 'snippets/fav', '2015-06-22 13:26:28', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(171, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:26:28', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(172, '127.0.0.1', 'snippets/fav', '2015-06-22 13:26:29', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(173, '127.0.0.1', 'snippets/rating', '2015-06-22 13:26:30', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(174, '127.0.0.1', 'snippets/comment', '2015-06-22 13:26:32', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(175, '127.0.0.1', 'snippets/browse', '2015-06-22 13:26:34', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(176, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:26:42', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(177, '127.0.0.1', 'admin_snippets/delete/93', '2015-06-22 13:26:44', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(178, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 13:26:44', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(179, '127.0.0.1', 'snippets/browse', '2015-06-22 13:26:58', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(180, '127.0.0.1', 'snippets/view/80', '2015-06-22 13:27:20', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(181, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:27:21', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(182, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:27:23', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(183, '127.0.0.1', 'snippets/fav', '2015-06-22 13:27:24', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(184, '127.0.0.1', 'snippets/browse', '2015-06-22 13:27:26', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(185, '127.0.0.1', 'snippets/view/79', '2015-06-22 13:27:35', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(186, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:27:35', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(187, '127.0.0.1', 'snippets/unfav', '2015-06-22 13:27:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(188, '127.0.0.1', 'snippets/browse', '2015-06-22 13:27:38', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(189, '127.0.0.1', 'snippets/view/79', '2015-06-22 13:27:42', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(190, '127.0.0.1', 'snippets/show_comment', '2015-06-22 13:27:42', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(191, '127.0.0.1', 'snippets/fav', '2015-06-22 13:27:43', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(192, '127.0.0.1', 'snippets/browse', '2015-06-22 13:27:44', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(193, '127.0.0.1', 'tuts', '2015-06-22 14:36:08', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(194, '127.0.0.1', 'home', '2015-06-22 14:49:57', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(195, '127.0.0.1', 'tuts', '2015-06-22 16:05:35', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(196, '127.0.0.1', 'admin_snippets/history/90', '2015-06-22 16:05:45', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(197, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:05:53', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(198, '127.0.0.1', 'admin_snippets/view/90', '2015-06-22 16:09:02', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(199, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:09:06', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(200, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:10:07', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(201, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:10:28', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(202, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:10:29', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(203, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:10:31', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(204, '127.0.0.1', 'snippets/browse', '2015-06-22 16:11:12', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(205, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:11:46', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(206, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:12:24', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(207, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:12:47', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(208, '127.0.0.1', 'admin_users/browse', '2015-06-22 16:12:49', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(209, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:12:54', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(210, '127.0.0.1', 'snippets/browse', '2015-06-22 16:13:31', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(211, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:13:33', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(212, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:15:05', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(213, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:15:32', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(214, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:15:45', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(215, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:16:48', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(216, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:17:03', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(217, '127.0.0.1', 'admin_users/browse', '2015-06-22 16:17:16', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(218, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:17:28', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(219, '127.0.0.1', 'admin_snippets/view/90', '2015-06-22 16:18:17', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(220, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:18:21', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(221, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:30:45', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(222, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:30:56', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(223, '127.0.0.1', 'admin_snippets/view/78', '2015-06-22 16:31:27', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(224, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:31:33', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(225, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:31:36', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(226, '127.0.0.1', 'admin_snippets/browse/3', '2015-06-22 16:31:39', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(227, '127.0.0.1', 'admin_snippets/browse/4', '2015-06-22 16:31:43', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(228, '127.0.0.1', 'admin_snippets/browse/5', '2015-06-22 16:31:49', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(229, '127.0.0.1', 'admin_snippets/browse/6', '2015-06-22 16:31:53', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(230, '127.0.0.1', 'admin_snippets/browse/7', '2015-06-22 16:31:54', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(231, '127.0.0.1', 'admin_snippets/browse/8', '2015-06-22 16:31:56', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(232, '127.0.0.1', 'admin_snippets/browse/7', '2015-06-22 16:31:58', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(233, '127.0.0.1', 'admin_snippets/browse/6', '2015-06-22 16:31:58', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(234, '127.0.0.1', 'admin_snippets/browse/5', '2015-06-22 16:31:59', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(235, '127.0.0.1', 'admin_snippets/browse/3', '2015-06-22 16:31:59', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(236, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:32:01', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(237, '127.0.0.1', 'admin_cms/browse', '2015-06-22 16:32:15', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(238, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:32:22', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(239, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:40:41', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(240, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:43:34', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(241, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:43:51', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(242, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:44:07', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(243, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:45:07', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(244, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:45:26', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(245, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 16:45:45', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(246, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:45:54', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(247, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:46:11', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(248, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:47:19', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(249, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:52:41', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(250, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:52:44', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(251, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:52:47', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(252, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:52:53', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(253, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:53:13', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(254, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:54:55', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(255, '127.0.0.1', 'admin_snippets/browse/1', '2015-06-22 16:55:02', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(256, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:55:06', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(257, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:55:34', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(258, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:56:01', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(259, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:56:02', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(260, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:56:14', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(261, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:56:42', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(262, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:57:00', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(263, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:57:11', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(264, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:57:30', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(265, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:57:38', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(266, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:58:28', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(267, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 16:59:46', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(268, '127.0.0.1', 'admin_snippets/view/78', '2015-06-22 17:00:17', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(269, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:00:20', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(270, '127.0.0.1', 'admin_snippets/view/90', '2015-06-22 17:00:24', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(271, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:00:25', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(272, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 17:00:27', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(273, '127.0.0.1', 'admin_snippets/history/78', '2015-06-22 17:00:30', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(274, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 17:00:31', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(275, '127.0.0.1', 'admin_snippets/browse/1', '2015-06-22 17:00:33', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(276, '127.0.0.1', 'admin_snippets/history/90', '2015-06-22 17:00:35', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(277, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:00:38', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(278, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:01:22', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(279, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 17:01:27', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(280, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 17:01:38', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(281, '127.0.0.1', 'snippets/add', '2015-06-22 17:02:30', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(282, '127.0.0.1', 'snippets/register', '2015-06-22 17:05:54', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(283, '127.0.0.1', 'snippets/browse', '2015-06-22 17:05:54', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(284, '127.0.0.1', 'admin_snippets/browse/2', '2015-06-22 17:06:04', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(285, '127.0.0.1', 'admin_snippets/browse/1', '2015-06-22 17:06:06', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(286, '127.0.0.1', 'admin_snippets/view/94', '2015-06-22 17:06:29', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(287, '127.0.0.1', 'admin_snippets/history/94', '2015-06-22 17:06:42', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(288, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:06:55', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(289, '127.0.0.1', 'admin_snippets/history/90', '2015-06-22 17:06:58', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(290, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:07:01', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(291, '127.0.0.1', 'admin_snippets/history/80', '2015-06-22 17:07:04', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(292, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:07:14', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(293, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:07:24', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(294, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:07:40', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(295, '127.0.0.1', 'admin_cms/edit/4', '2015-06-22 17:07:58', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(296, '127.0.0.1', 'snippets/browse', '2015-06-22 17:13:56', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(297, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:35:22', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(298, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:35:23', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(299, '127.0.0.1', 'admin_cms/add', '2015-06-22 17:35:40', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(300, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:35:41', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(301, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:39:43', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(302, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:40:59', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(303, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:42:38', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(304, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:43:26', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(305, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:45:08', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(306, '127.0.0.1', 'admin_snippets/search', '2015-06-22 17:45:18', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(307, '127.0.0.1', 'admin_snippets/search', '2015-06-22 17:45:53', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(308, '127.0.0.1', 'admin_snippets/search', '2015-06-22 17:45:57', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(309, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:46:03', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(310, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:47:29', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(311, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:47:29', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"');
INSERT INTO `logger` (`ID`, `ipAddress`, `route`, `date`, `session`, `browser`) VALUES
(312, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:47:58', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(313, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:47:59', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(314, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:50:11', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(315, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:50:11', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(316, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:50:30', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(317, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:50:30', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(318, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:50:37', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(319, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:50:38', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(320, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:51:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(321, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:51:45', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(322, '127.0.0.1', 'snippets/view/94', '2015-06-22 17:53:31', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(323, '127.0.0.1', 'snippets/show_comment', '2015-06-22 17:53:32', '8', '"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36"'),
(324, '127.0.0.1', 'admin_cms/browse', '2015-06-22 17:53:40', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"'),
(325, '127.0.0.1', 'admin_snippets/browse', '2015-06-22 17:53:44', '11', '"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0"');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `media`
--

CREATE TABLE IF NOT EXISTS `media` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(400) NOT NULL,
  `url` text NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Volcado de datos para la tabla `media`
--

INSERT INTO `media` (`ID`, `name`, `url`) VALUES
(3, 'angular', 'static/resources/images/159346685.png'),
(4, 'Apache', 'static/resources/images/308193617.png'),
(5, 'Logo de Clojure', 'static/resources/images/898589656.png'),
(6, 'Este es el logo mas esperado de DART', 'static/resources/images/178581892.png'),
(7, 'Este es otro logo, es el de Groovy', 'static/resources/images/767471818.png'),
(8, 'Este logo representa al lenguaje de desarrollo HTML5, el nuevo estandard en HTML', 'static/resources/images/1305110893.png'),
(9, 'example', 'static/resources/images/1407225310.png');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `notification`
--

CREATE TABLE IF NOT EXISTS `notification` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `user_ID` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `page`
--

CREATE TABLE IF NOT EXISTS `page` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `url` text NOT NULL,
  `body` longtext NOT NULL,
  `parent` bigint(20) NOT NULL,
  `created` datetime NOT NULL,
  `ordenation` int(11) NOT NULL,
  `published` tinyint(1) NOT NULL DEFAULT '0',
  `updated` datetime NOT NULL,
  `title` text NOT NULL,
  `type` bigint(20) NOT NULL,
  `level` bigint(20) NOT NULL,
  `keywords_se` text NOT NULL,
  `description_se` text NOT NULL,
  `associated` datetime DEFAULT NULL,
  `vars` text,
  `category` bigint(20) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_page_type_idx` (`type`),
  KEY `fk_page_category_idx` (`category`),
  KEY `fk_page_pagelevel_idx` (`level`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=25 ;

--
-- Volcado de datos para la tabla `page`
--

INSERT INTO `page` (`ID`, `url`, `body`, `parent`, `created`, `ordenation`, `published`, `updated`, `title`, `type`, `level`, `keywords_se`, `description_se`, `associated`, `vars`, `category`) VALUES
(2, 'php-construye-un-arbol-desplegable-con-php-css-y-jquery', '<p>Un &aacute;rbol desplegable es una de las funcionalidades que implementan los sistemas de gesti&oacute;n de contenidos ( CMS) para mostrar la relaci&oacute;n entre las p&aacute;ginas enlazadas con su parent, o tambi&eacute;n la ubicaci&oacute;n de ficheros dentro de un sistema operativo ( Sistema de directorios), su utilidad radica en la visualizaci&oacute;n de forma jer&aacute;rquica de los recursos y de quien dependen o enlazan los mismos. Este art&iacute;culo explicar&aacute; los pasos necesarios para crear el &aacute;rbol desde el dise&ntilde;o de la base de datos hasta la visualizaci&oacute;n con PHP y jQuery.</p>\r\n\r\n<p>Para ilustrar como crear este &aacute;rbol, vamos a dise&ntilde;ar un peque&ntilde;o sistema de gesti&oacute;n de contenidos ( creaci&oacute;n de p&aacute;ginas) las cuales tendr&aacute;n un padre al que pertenece, aqu&iacute; no nos enfocaremos en la construcci&oacute;n de p&aacute;ginas en s&iacute; (es decir no validaremos campos de la pagina ni gestionaremos un editor WYSIWYG), sino en el dise&ntilde;o del modelo y el desarrollo de los componentes para extraer la informaci&oacute;n y mostrarlo en una p&aacute;gina web.</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">$.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">fn</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">extend</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; treed</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">:</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><strong>var</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;tree&nbsp;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">=</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;$</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; tree.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">addClass</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&quot;tree&quot;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; tree.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">find</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;li&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">has</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&quot;ul&quot;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">each</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp;&nbsp;</span><strong>var</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;branch&nbsp;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">=</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;$</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><em>//li with children ul</em><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; branch.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">prepend</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&quot;&quot;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; branch.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">addClass</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;branch&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; branch.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">on</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;click&#39;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">,</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">e</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span><strong>if</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">==</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;e.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">target</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span><strong>var</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;icon&nbsp;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">=</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;$</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">children</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;i:first&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; icon.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">toggleClass</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&quot;fa-minus-square-o fa-plus-square-o&quot;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">children</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">children</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">toggle</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; branch.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">children</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">children</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">toggle</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;.branch .indicator&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">on</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;click&#39;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">,</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">closest</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;li&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">click</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;.branch&gt;a&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">each</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">on</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;click&#39;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">,</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">e</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">closest</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;li&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">click</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; &nbsp; e.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">preventDefault</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;.branch button&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">on</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;click&#39;</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">,</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><strong>function</strong><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">e</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>this</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">closest</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&#39;li&#39;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">click</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp; &nbsp; e.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">preventDefault</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; &nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><br />\r\n<span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">$</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><strong>function</strong><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">{</span><br />\r\n<span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">&nbsp; $</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(51, 102, 204); font-family:monaco,lucida console,monospace">&quot;.tree&quot;</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="background-color:rgb(241, 241, 241); color:rgb(0, 0, 0); font-family:monaco,lucida console,monospace">.</span><span style="color:rgb(102, 0, 102); font-family:monaco,lucida console,monospace">treed</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">(</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span><br />\r\n<span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">}</span><span style="color:rgb(0, 153, 0); font-family:monaco,lucida console,monospace">)</span><span style="color:rgb(51, 153, 51); font-family:monaco,lucida console,monospace">;</span></p>\r\n', 0, '2015-05-29 11:05:44', 1, 1, '2015-05-29 11:05:44', ' Construye una arbol desplegable con PHP, CSS y jQuery', 1, 3, 'php , jquery, tutorial, java ', 'Te mostramos como crear un arbol en jQuery y php', NULL, NULL, 4);
INSERT INTO `page` (`ID`, `url`, `body`, `parent`, `created`, `ordenation`, `published`, `updated`, `title`, `type`, `level`, `keywords_se`, `description_se`, `associated`, `vars`, `category`) VALUES
(3, 'http://jsfiddle.net/gabrieleromanato/mxq9R/', '<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;">a-check-circle&nbsp;[&iuml;Â&tilde;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&Acirc;Â</span>&nbsp;fa-check-circle-o&nbsp;[&iuml;ÂÂ]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&hellip;&Scaron;</span>&nbsp;fa-check-square&nbsp;[&iuml;&hellip;&Scaron;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&dagger;</span>&nbsp;fa-check-square-o&nbsp;[&iuml;Â&dagger;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&ordm;</span>&nbsp;fa-chevron-circle-down&nbsp;[&iuml;&bdquo;&ordm;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&middot;</span>&nbsp;fa-chevron-circle-left&nbsp;[&iuml;&bdquo;&middot;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&cedil;</span>&nbsp;fa-chevron-circle-right&nbsp;[&iuml;&bdquo;&cedil;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&sup1;</span>&nbsp;fa-chevron-circle-up&nbsp;[&iuml;&bdquo;&sup1;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&cedil;</span>&nbsp;fa-chevron-down&nbsp;[&iuml;Â&cedil;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&ldquo;</span>&nbsp;fa-chevron-left&nbsp;[&iuml;Â&ldquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&rdquo;</span>&nbsp;fa-chevron-right&nbsp;[&iuml;Â&rdquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&middot;</span>&nbsp;fa-chevron-up&nbsp;[&iuml;Â&middot;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&reg;</span>&nbsp;fa-child&nbsp;[&iuml;&dagger;&reg;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&lsquo;</span>&nbsp;fa-circle&nbsp;[&iuml;&bdquo;&lsquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&OElig;</span>&nbsp;fa-circle-o&nbsp;[&iuml;&bdquo;&OElig;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Dagger;&Aring;&frac12;</span>&nbsp;fa-circle-o-notch&nbsp;[&iuml;&Dagger;Å½]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Dagger;&rsaquo;</span>&nbsp;fa-circle-thin&nbsp;[&iuml;&Dagger;&rsaquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&ordf;</span>&nbsp;fa-clipboard&nbsp;[&iuml;&fnof;&ordf;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&euro;&mdash;</span>&nbsp;fa-clock-o&nbsp;[&iuml;&euro;&mdash;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&euro;&Acirc;Â</span>&nbsp;fa-close&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&euro;Â]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&sbquo;</span>&nbsp;fa-cloud&nbsp;[&iuml;&fnof;&sbquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&shy;</span>&nbsp;fa-cloud-download&nbsp;[&iuml;&fnof;&shy;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&reg;</span>&nbsp;fa-cloud-upload&nbsp;[&iuml;&fnof;&reg;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&hellip;&mdash;</span>&nbsp;fa-cny&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&hellip;&mdash;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&iexcl;</span>&nbsp;fa-code&nbsp;[&iuml;&bdquo;&iexcl;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&brvbar;</span>&nbsp;fa-code-fork&nbsp;[&iuml;&bdquo;&brvbar;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Dagger;&lsaquo;</span>&nbsp;fa-codepen&nbsp;[&iuml;&Dagger;&lsaquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&acute;</span>&nbsp;fa-coffee&nbsp;[&iuml;&fnof;&acute;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&euro;&ldquo;</span>&nbsp;fa-cog&nbsp;[&iuml;&euro;&ldquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&sbquo;&hellip;</span>&nbsp;fa-cogs&nbsp;[&iuml;&sbquo;&hellip;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&rsaquo;</span>&nbsp;fa-columns&nbsp;[&iuml;&fnof;&rsaquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&micro;</span>&nbsp;fa-comment&nbsp;[&iuml;Â&micro;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&yen;</span>&nbsp;fa-comment-o&nbsp;[&iuml;&fnof;&yen;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&sbquo;&dagger;</span>&nbsp;fa-comments&nbsp;[&iuml;&sbquo;&dagger;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&brvbar;</span>&nbsp;fa-comments-o&nbsp;[&iuml;&fnof;&brvbar;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&hellip;&Aring;&frac12;</span>&nbsp;fa-compass&nbsp;[&iuml;&hellip;Å½]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&brvbar;</span>&nbsp;fa-compress&nbsp;[&iuml;Â&brvbar;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&circ;&Aring;&frac12;</span>&nbsp;fa-connectdevelop&nbsp;[&iuml;&circ;Å½]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&hellip;</span>&nbsp;fa-copy&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&fnof;&hellip;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Dagger;&sup1;</span>&nbsp;fa-copyright&nbsp;[&iuml;&Dagger;&sup1;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&sbquo;&Acirc;Â</span>&nbsp;fa-credit-card&nbsp;[&iuml;&sbquo;Â]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&yen;</span>&nbsp;fa-crop&nbsp;[&iuml;&bdquo;&yen;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Acirc;Â&rsaquo;</span>&nbsp;fa-crosshairs&nbsp;[&iuml;Â&rsaquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&frac14;</span>&nbsp;fa-css3&nbsp;[&iuml;&bdquo;&frac14;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&sup2;</span>&nbsp;fa-cube&nbsp;[&iuml;&dagger;&sup2;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&sup3;</span>&nbsp;fa-cubes&nbsp;[&iuml;&dagger;&sup3;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&bdquo;</span>&nbsp;fa-cut&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&fnof;&bdquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&micro;</span>&nbsp;fa-cutlery&nbsp;[&iuml;&fnof;&micro;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&fnof;&curren;</span>&nbsp;fa-dashboard&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&fnof;&curren;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&circ;&Acirc;Â</span>&nbsp;fa-dashcube&nbsp;[&iuml;&circ;Â]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&Dagger;&euro;</span>&nbsp;fa-database&nbsp;[&iuml;&Dagger;&euro;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&euro;&raquo;</span>&nbsp;fa-dedent&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&euro;&raquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&yen;</span>&nbsp;fa-delicious&nbsp;[&iuml;&dagger;&yen;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&bdquo;&circ;</span>&nbsp;fa-desktop&nbsp;[&iuml;&bdquo;&circ;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&frac12;</span>&nbsp;fa-deviantart&nbsp;[&iuml;&dagger;&frac12;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&circ;&trade;</span>&nbsp;fa-diamond&nbsp;[&iuml;&circ;&trade;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&brvbar;</span>&nbsp;fa-digg&nbsp;[&iuml;&dagger;&brvbar;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&hellip;&bull;</span>&nbsp;fa-dollar&nbsp;<span style="color:rgb(179, 179, 179)">(alias)</span>&nbsp;[&iuml;&hellip;&bull;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&dagger;&rsquo;</span>&nbsp;fa-dot-circle-o&nbsp;[&iuml;&dagger;&rsquo;]</div>\r\n\r\n<div class="col-md-4 col-sm-6 col-lg-3" style="box-sizing: border-box; position: relative; min-height: 1px; padding-left: 15px; padding-right: 15px; float: left; width: 292.5px; font-family: proxima-nova, ''Helvetica Neue'', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 20px;"><span style="font-family:fontawesome; font-size:inherit">&iuml;&euro;&trade;</span>&nbsp;fa-download&nbsp;[&iuml;&euro;&trade;]</div>\r\n', 4, '2015-04-08 17:41:43', 1, 1, '2015-04-08 17:41:43', 'http://jsfiddle.net/gabrieleromanato/mxq9R/', 1, 1, 'dffdghfghdfgh drrgsddrrg , aaegr , aaeadg f,a edgf,12,3,4,54,5,6,7', 'dfghdfghdfgh', NULL, NULL, 12),
(4, 'snippets-exporta-desde-tu-base-de-datos-a-tu-seeds-rb', '<p>En un art&iacute;culo anterior te mostramos como poblar ( populate) nuestra base de datos a partir del archivo<span style="color:rgb(51, 51, 51)"><em>seeds.rb</em></span>, y como generar informaci&oacute;n aleatoria utilizando para ello&nbsp;<span style="color:rgb(51, 51, 51)"><em>Faker</em>&nbsp;</span>y&nbsp;<em><span style="color:rgb(51, 51, 51)">Factory_Girl</span></em>&nbsp;( ver&nbsp;<span style="color:rgb(51, 51, 51)"><span style="color:rgb(0, 0, 255)"><a href="http://www.elclubdelprogramador.com/2015/04/06/snippets-trabajando-con-seeds-y-faker-en-rails/" style="margin: 0px; padding: 0px; vertical-align: baseline; text-decoration: none; color: rgb(51, 51, 51) !important; background: transparent;" target="_blank" title="Trabajando con seeds y Faker  en Rails"><span style="color:rgb(0, 0, 255)">aqu&iacute;</span></a></span></span>), ahora os mostraremos como realizar el proceso contrario, es decir a partir de informaci&oacute;n almacenada en Base de datos como exportarlo al archivo&nbsp;<em><span style="color:rgb(51, 51, 51)">seeds.rb</span></em>.</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<h4>Creando una tarea rake</h4>\r\n\r\n<p>Para los que a&uacute;n no lo conoc&eacute;is Rake, es la herramienta de automatizaci&oacute;n de construcci&oacute;n utilizada en Ruby ( y por extensi&oacute;n en rails) para realizar tareas y agrupadas en namespaces. Haremos uso de una tarea de rake para crear nuestra exportaci&oacute;n de datos, para ello lo primero que debemos hacer es generar el esqueleto de la tarea:</p>\r\n\r\n<div class="codecolorer-container ruby geshi" style="margin: 0px 0px 10px; padding: 0px; border: 1px solid rgb(159, 159, 159); outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; font-family: Monaco, ''Lucida Console'', monospace; color: rgb(0, 0, 0); overflow: auto; white-space: nowrap; width: 600px; background: rgb(241, 241, 241);">\r\n<table cellpadding="0" cellspacing="0" style="background:transparent; border-collapse:collapse; border-spacing:0px; border:0px; font-stretch:normal; line-height:1.4em; margin:0px 30px; outline:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:right; vertical-align:baseline">\r\n			<div style="margin: 0px; padding: 0px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; width: 23px; background: transparent;">1</div>\r\n			</td>\r\n			<td style="vertical-align:baseline">\r\n			<div class="ruby codecolorer" style="margin: 0px; padding: 5px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;">rails g task nombre_namespace nombre_tarea nombre_tarea2 .....</div>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n\r\n<p>La sentencia acepta el nombre del namespace y el nombre de las tareas que deseamos ejecutar separadas por espacio. El esqueleto del script se crea en el directorio /lib/tasks/ con el nombre del namespace.</p>\r\n\r\n<p>Abrimos el archivo y nos encontraremos con lo siguiente:</p>\r\n\r\n<div class="codecolorer-container ruby geshi" style="margin: 0px 0px 10px; padding: 0px; border: 1px solid rgb(159, 159, 159); outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; font-family: Monaco, ''Lucida Console'', monospace; color: rgb(0, 0, 0); overflow: auto; white-space: nowrap; width: 600px; background: rgb(241, 241, 241);">\r\n<table cellpadding="0" cellspacing="0" style="background:transparent; border-collapse:collapse; border-spacing:0px; border:0px; font-stretch:normal; line-height:1.4em; margin:0px 30px; outline:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:right; vertical-align:baseline">\r\n			<div style="margin: 0px; padding: 0px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; width: 23px; background: transparent;">1<br />\r\n			2<br />\r\n			3<br />\r\n			4<br />\r\n			5</div>\r\n			</td>\r\n			<td style="vertical-align:baseline">\r\n			<div class="ruby codecolorer" style="margin: 0px; padding: 5px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;">namespace&nbsp;<strong>:nombre_namespace</strong>&nbsp;<strong>do</strong><br />\r\n			&nbsp; desc&nbsp;<span style="color:rgb(153, 102, 0)">&quot;TODO&quot;</span><br />\r\n			&nbsp; task nombre_tarea:&nbsp;<strong>:environment</strong>&nbsp;<strong>do</strong><br />\r\n			&nbsp;&nbsp;<strong>end</strong><br />\r\n			<strong>end</strong></div>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n\r\n<p>Ahora a&ntilde;adimos el c&oacute;digo para iterar sobre la tabla que queremos exportar</p>\r\n\r\n<div class="codecolorer-container ruby geshi" style="margin: 0px 0px 10px; padding: 0px; border: 1px solid rgb(159, 159, 159); outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; font-family: Monaco, ''Lucida Console'', monospace; color: rgb(0, 0, 0); overflow: auto; white-space: nowrap; width: 600px; background: rgb(241, 241, 241);">\r\n<table cellpadding="0" cellspacing="0" style="background:transparent; border-collapse:collapse; border-spacing:0px; border:0px; font-stretch:normal; line-height:1.4em; margin:0px 30px; outline:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:right; vertical-align:baseline">\r\n			<div style="margin: 0px; padding: 0px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; width: 23px; background: transparent;">1<br />\r\n			2<br />\r\n			3<br />\r\n			4<br />\r\n			5<br />\r\n			6<br />\r\n			7<br />\r\n			8</div>\r\n			</td>\r\n			<td style="vertical-align:baseline">\r\n			<div class="ruby codecolorer" style="margin: 0px; padding: 5px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;">namespace&nbsp;<strong>:nombre_namespace</strong>&nbsp;<strong>do</strong><br />\r\n			&nbsp; desc&nbsp;<span style="color:rgb(153, 102, 0)">&quot;Exports table information from database&quot;</span><br />\r\n			&nbsp; task nombre_tarea:&nbsp;<strong>:environment</strong>&nbsp;<strong>do</strong><br />\r\n			&nbsp; &nbsp; Tabla.<span style="color:rgb(153, 0, 204)">order</span><strong>(</strong><strong>:id</strong><strong>)</strong>.<span style="color:rgb(153, 0, 204)">all</span>.<span style="color:rgb(153, 0, 204)">each</span>&nbsp;<strong>do</strong>&nbsp;<strong>|</strong>payment<strong>|</strong><br />\r\n			&nbsp; &nbsp; &nbsp;&nbsp;<strong>puts</strong>&nbsp;<span style="color:rgb(153, 102, 0)">&quot;Tabla.create(#{tabla.serializable_hash.delete_if {|key, value| [&#39;created_at&#39;,&#39;updated_at&#39;,&#39;id&#39;].include? &nbsp;(key)}.to_s.gsub(/[{}]/,&#39;&#39;)})&quot;</span><br />\r\n			&nbsp; &nbsp;&nbsp;<strong>end</strong><br />\r\n			&nbsp;&nbsp;<strong>end</strong><br />\r\n			<strong>end</strong></div>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n\r\n<p>Para ejecutar la tarea debemos ejecutar la sentencia:</p>\r\n\r\n<div class="codecolorer-container ruby geshi" style="margin: 0px 0px 10px; padding: 0px; border: 1px solid rgb(159, 159, 159); outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; font-family: Monaco, ''Lucida Console'', monospace; color: rgb(0, 0, 0); overflow: auto; white-space: nowrap; width: 600px; background: rgb(241, 241, 241);">\r\n<table cellpadding="0" cellspacing="0" style="background:transparent; border-collapse:collapse; border-spacing:0px; border:0px; font-stretch:normal; line-height:1.4em; margin:0px 30px; outline:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:right; vertical-align:baseline">\r\n			<div style="margin: 0px; padding: 0px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; width: 23px; background: transparent;">1</div>\r\n			</td>\r\n			<td style="vertical-align:baseline">\r\n			<div class="ruby codecolorer" style="margin: 0px; padding: 5px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;">rake nombre_namespace:nombre_tarea</div>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n\r\n<p>Por &uacute;tlimo generamos el archivo seeds.rb con la salida que nos da la tarea de la forma:</p>\r\n\r\n<div class="codecolorer-container ruby geshi" style="margin: 0px 0px 10px; padding: 0px; border: 1px solid rgb(159, 159, 159); outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; font-family: Monaco, ''Lucida Console'', monospace; color: rgb(0, 0, 0); overflow: auto; white-space: nowrap; width: 600px; background: rgb(241, 241, 241);">\r\n<table cellpadding="0" cellspacing="0" style="background:transparent; border-collapse:collapse; border-spacing:0px; border:0px; font-stretch:normal; line-height:1.4em; margin:0px 30px; outline:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:right; vertical-align:baseline">\r\n			<div style="margin: 0px; padding: 0px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; width: 23px; background: transparent;">1</div>\r\n			</td>\r\n			<td style="vertical-align:baseline">\r\n			<div class="ruby codecolorer" style="margin: 0px; padding: 5px; border: 0px; outline: 0px; vertical-align: baseline; font-stretch: normal; line-height: 1.4em; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;">rake nombre_namespace:nombre_tarea &nbsp;<strong>&gt;</strong>&nbsp;seeds.<span style="color:rgb(153, 0, 204)">rb</span></div>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<h4>Te Puede Interesar:</h4>\r\n\r\n<p><span style="color:rgb(51, 51, 51)"><span style="color:rgb(0, 0, 255)"><a href="http://www.elclubdelprogramador.com/2015/04/06/snippets-trabajando-con-seeds-y-faker-en-rails/" style="margin: 0px; padding: 0px; vertical-align: baseline; text-decoration: none; color: rgb(51, 51, 51) !important; background: transparent;" target="_blank" title="Trabajando con seeds y Faker  en Rails"><span style="color:rgb(0, 0, 255)">Trabajando con seeds y Faker en Rails</span></a></span></span></p>\r\n\r\n<p><span style="color:rgb(51, 51, 51)"><span style="color:rgb(0, 0, 255)"><a href="http://www.elclubdelprogramador.com/2015/01/22/rails-trabajando-con-clases-propias-en-rails/" style="margin: 0px; padding: 0px; vertical-align: baseline; text-decoration: none; color: rgb(51, 51, 51) !important; background: transparent;" target="_blank" title="Trabajando con clases propias en Rails"><span style="color:rgb(0, 0, 255)">Trabajando con clases propias en Rails</span></a></span></span></p>\r\n\r\n<p><span style="color:rgb(51, 51, 51)"><span style="color:rgb(0, 0, 255)"><a href="http://www.elclubdelprogramador.com/2014/11/26/rails-captura-todas-tus-peticiones-erroneas-404-con-rails/" style="margin: 0px; padding: 0px; vertical-align: baseline; text-decoration: none; color: rgb(51, 51, 51) !important; background: transparent;" target="_blank" title="Captura todas tus peticiones errÃƒÂ³neas (404) con Rails"><span style="color:rgb(0, 0, 255)">Captura todas tus peticiones err&oacute;neas (404) con Rails</span></a></span></span></p>\r\n', 0, '2015-04-09 12:56:27', 1, 1, '2015-04-09 12:56:27', 'Exporta desde tu base de datos a tu seeds.rb', 1, 1, 'ruby, seeds, rake', 'Como exportar la base de datos a seeds.rb, aleluya ', NULL, NULL, 2),
(5, 'sadfasdf', '<p>This is my textarea tasdfasdfasdfasdfasfo be replaced with CKEditor.</p>\r\n', 2, '2015-04-20 15:55:52', 1, 0, '2015-04-20 15:55:52', 'dfgvasdgf', 2, 1, 'sadfas', 'dfasdfasdf', NULL, NULL, 17),
(6, 'rrrrr', 'dfgsdfgsdfg s\r\n\r\ndef index\r\nrespond_to do |format|\r\nflash[:status] = request.path\r\nformat.html { render :file => "public/404.html.erb" }\r\nformat.all { render :nothing => true,:status => "404 Not Found" }\r\nend\r\nend', 0, '2015-06-09 16:52:22', 0, 0, '2015-06-09 16:52:22', 'rrrrrrr', 1, 1, 'fff', 'fff', NULL, NULL, 4),
(7, 'asdfasdf', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-05-22 13:39:13', 0, 0, '2015-05-22 13:39:13', 'sdfasdf', 1, 1, 'asdf', 'asdfasdf', NULL, NULL, 17),
(8, 'fgsdfg', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-05-22 14:12:52', 1, 0, '2015-05-22 14:12:52', 'asgsdfgsd', 1, 1, 'dsfgsd', 'fgsdfg', NULL, NULL, 15),
(9, 'fgsdfg', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-05-22 14:13:39', 1, 0, '2015-05-22 14:13:39', 'sdfgsdfgsd', 1, 1, 'gsdfgsdf', 'gsdfgsdfg', NULL, NULL, 5),
(13, 'sdfsdfsdfsdf', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-05-28 11:31:30', 1, 0, '2015-05-28 11:31:30', 'sdfsdf', 1, 1, 'sdfs', 'df', NULL, NULL, 17),
(14, 'sdfsdfsdf', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-05-28 11:40:47', 0, 1, '2015-05-28 11:40:47', 'ssddfsdfsdf', 1, 2, 'wdadsa', 'sdasdasd', NULL, NULL, 5),
(15, 'sdfsdfsdf', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-06-01 13:52:33', 0, 0, '2015-06-01 13:52:33', 'angular 1', 1, 2, '', '', NULL, NULL, 15),
(16, 'sdfsdfs', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-06-01 13:52:49', 0, 1, '2015-06-01 13:52:49', 'angular 3', 1, 3, '', '', NULL, NULL, 15);
INSERT INTO `page` (`ID`, `url`, `body`, `parent`, `created`, `ordenation`, `published`, `updated`, `title`, `type`, `level`, `keywords_se`, `description_se`, `associated`, `vars`, `category`) VALUES
(17, 'install-clojure', '<h2 style="font-style:normal; text-align:start">Installing Clojure</h2>\r\n\r\n<p style="text-align:start">A fast and easy way to get started with Clojure is to download and run <a href="https://github.com/arthuredelstein/clooj#readme" style="margin: 0px; padding: 0px; border: 0px; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; color: rgb(117, 21, 144); transition: color 0.3s; -webkit-transition: color 0.3s; white-space: pre-wrap; word-wrap: break-word;">Clooj</a>. Clooj is an Integrated Development Environment for Clojure.</p>\r\n\r\n<p style="text-align:start">As an alternative, the Clojure website provides <a href="http://clojure.org/getting_started" style="margin: 0px; padding: 0px; border: 0px; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; color: rgb(117, 21, 144); transition: color 0.3s; -webkit-transition: color 0.3s; white-space: pre-wrap; word-wrap: break-word;">instructions for installing Clojure the traditional way</a>.</p>\r\n\r\n<p style="text-align:start">The primary way of interacting with Clojure is through the REPL (Read-Evaluate-Print-Loop). The REPL Reads expressions that you give it, Evaluates the expressions, Prints the value that is the result, and Loops around for more input.</p>\r\n\r\n<p style="text-align:start"><a name="atoms"></a></p>\r\n\r\n<h1 style="text-align:start">Atoms</h1>\r\n\r\n<p style="text-align:start">There are two categories of Clojure expressions, <em>atoms</em> and <em>lists</em>. Atoms are like the primitive types in other languages. Letâ€™s use the <span style="font-family:inherit; font-size:18.3999996185303px">REPL</span> to explore some atoms.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Numbers</h3>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">5</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">5</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">The number 5 is evaluated and the result is displayed.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Booleans</h3>\r\n\r\n<p style="text-align:start">Hereâ€™s another atom:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">true</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">true</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Clojure supports boolean <code>TRUE</code> and <code>FALSE</code> values, represented as <code>true</code> and <code>false</code>respectively.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Nil</h3>\r\n\r\n<p style="text-align:start">Here is another important atom:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">nil</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">nil</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">This is Clojureâ€™s name for no-value, or null. It resolves to Javaâ€™s <code>null</code> value.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Strings</h3>\r\n\r\n<p style="text-align:start">Here is a Clojure string:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"Hello, world!"</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"Hello, world!"</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Clojure strings follow the same rules as Java strings, so for instance, <code>"\\t"</code> represents the ASCII <code>TAB</code> character. The Java API is the primary way to make calculations on a string.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Symbols</h3>\r\n\r\n<p style="text-align:start">Symbols are stand-in names for values. Theyâ€™re sort of like what you would call a constant in other languages. Clojure doesnâ€™t have variables. And unlike other languages, Clojure makes a distinction between a symbol and its value.</p>\r\n\r\n<p style="text-align:start">When a symbol is evaluated, its value is returned:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">3</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">4</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">5</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">6</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">7</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">8</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">9</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">10</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:749px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">*file*</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"NO_SOURCE_PATH"</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">*compile-path*</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"classes"</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">*clojure-version*</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">{</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:major</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span>, <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:minor</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span>, <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:incremental</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">0</span>, <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:qualifier</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">nil</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">}</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">*command-line-args*</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">nil</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">+</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">#</span><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px"><core$_PLUS_</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">clojure.core$_PLUS_</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">@</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">6</span><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">d581e80></span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">The above shows some of Clojureâ€™s built-in symbols. By convention, built-in symbols begin and end with â€˜*â€™ if they bind to data. The last symbol shown â€œ+â€ is a built-in function.</p>\r\n\r\n<h3 style="color:rgb(34, 34, 34); font-style:normal; text-align:start">Keywords</h3>\r\n\r\n<p style="text-align:start">Keywords are like symbols, except that they do not bind to an arbitrary value. They always bind to themselves. Keywords always start with a colon (<code>:</code>). Here are some keywords:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">3</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">4</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">5</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">6</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:a</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:a</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:_123</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:_123</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:KEY</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:KEY</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start"><a name="lists"></a></p>\r\n\r\n<h2 style="font-style:normal; text-align:start">Lists</h2>\r\n\r\n<p style="text-align:start">Near the beginning of the tutorial we saw a function call:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">+ </span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Function calls use lists to define the call. Lists are comprised of an opening and closing parenthesis, and zero or more elements. Each element is separated by whitespace or commas.</p>\r\n\r\n<p style="text-align:start">Lists can be both a data structure and a functional call form. When used as a function call, the first element of the lists is a function. Any remaining elements in the list are the functionâ€™s arguments.</p>\r\n\r\n<p style="text-align:start">When a list is used to perform an operation, it is called a <em>form</em>. The function element of the form is referred to as the <em>operator</em>. Strictly, it isnâ€™t always a function. There are three kinds of forms:<em>functions</em>, <em>macros</em>, and <em>special forms</em>.</p>\r\n\r\n<p style="text-align:start">Although the list can be used to perform operations, it can also be used to represent data. There is an important consequence of code and data sharing the same syntax: code can be manipulated as if it were data because it <em>is</em> data.</p>\r\n\r\n<p style="text-align:start">One way to use lists simply as data is to use Clojureâ€™s built-in operation, <code>list</code>:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">3</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">4</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">5</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">6</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">list </span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">list </span><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">a</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">b</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">c</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">a</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">b</span> <span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">c</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">list </span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"one"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"two"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"three"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"one"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"two"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"three"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">List items can be atoms, other lists, or other data structures that are part of Clojure.</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">list </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:foo</span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">list </span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">4</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">5</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">6</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">])</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:foo</span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">4</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">5</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">6</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">])</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Clojure also has a short-cut syntax for creating a list as data. Just prepend the list with a single-quote character:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">''</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Creating a list this way has a slightly different effect. The list items are left unevaluated. They can be undefined, and Clojure wonâ€™t complain.</p>\r\n\r\n<p style="text-align:start">Using some of Clojureâ€™s built-in operations, information can be extracted from the data. The following expression returns the first element of the given list.</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">first </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">''</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"one"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"two"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"three"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">))</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"one"</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Another operation returns all the elements except the first:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">rest </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">''</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"one"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"two"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"three"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">))</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"two"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"three"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start"><a name="vectors"></a></p>\r\n\r\n<h2 style="font-style:normal; text-align:start">Vectors</h2>\r\n\r\n<p style="text-align:start">The vector is another data structure, similar to a list. Vectors are zero-based arrays. They can contain any value, and any mix of value types, just like lists. Here are a few examples:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">3</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">4</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">5</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">6</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:a</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">0</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"hello"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">:a</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">0</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"hello"</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[]</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[]</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">The nice thing about vectors is you donâ€™t have to do anything special to use them as data as you do with lists.</p>\r\n\r\n<p style="text-align:start">Other languages give you a handy syntax for getting an arrayâ€™s element by its index. So, how is this accomplished with Clojureâ€™s vectors? Perform an operation:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">([</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">Here, we fetch the value at index <code>2</code>, which is <code>9</code>. The vector itself is the operator of the form. This may seem a little weird at first, but eventually it makes a lot of sense. Its argument is <code>2</code>. The general form for this operation is <code>(vector index)</code>. Compare this with JavaScript, which is similar:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">,</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">,</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">][</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">]</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">You can use the same operation on vectors as we did earlier with lists:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">3</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">4</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">5</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">6</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">first </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">])</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">last </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">])</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(133, 153, 0) !important; font-family:inherit; font-size:13px">rest </span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">[</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">7</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">])</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">(</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">8</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">9</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">)</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">That last one was a bit unexpected. It didnâ€™t return a vector. It looks like a list instead.</p>\r\n\r\n<p style="text-align:start"><a name="maps-sets"></a></p>\r\n\r\n<h2 style="font-style:normal; text-align:start">Maps and Sets</h2>\r\n\r\n<p style="text-align:start">In addition to lists as a data type, Clojure provides syntax for defining <em>maps</em> and <em>sets</em>.</p>\r\n\r\n<p style="text-align:start">Maps define a set of unique key-value pairs:</p>\r\n\r\n<p> \r\n<div class="highlight" style="margin: 0px; padding: 0px; border: 1px solid rgb(5, 35, 43) !important; font-family: inherit; font-style: inherit; font-variant: inherit; font-weight: inherit; font-stretch: inherit; line-height: inherit; font-size: 18.3999996185303px; vertical-align: baseline; overflow-y: hidden; overflow-x: auto; background: rgb(0, 43, 54);">\r\n<table style="border-collapse:collapse; border-spacing:0px; border:0px; font-family:inherit; font-size:18.3999996185303px; font-stretch:inherit; font-style:inherit; font-variant:inherit; font-weight:inherit; line-height:inherit; margin:0px; padding:0px; vertical-align:baseline">\r\n	<tbody>\r\n		<tr>\r\n			<td style="text-align:left; vertical-align:middle">\r\n			<pre style="text-align:right">\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">1</span>\r\n<span style="color:rgb(88, 110, 117) !important; font-family:inherit; font-size:13px">2</span>\r\n</pre>\r\n			</td>\r\n			<td style="text-align:left; vertical-align:middle; width:757px">\r\n			<pre>\r\n<code><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(38, 139, 210) !important; font-family:inherit; font-size:13px">user=></span> <span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">{</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"a"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span>, <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"b"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span>, <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"c"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">}</span>\r\n</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px"><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">{</span><span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"a"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">1</span>, <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"b"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">2</span>, <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">"c"</span> <span style="color:rgb(42, 161, 152) !important; font-family:inherit; font-size:13px">3</span><span style="color:rgb(147, 161, 161) !important; font-family:inherit; font-size:13px">}</span>\r\n</span></code></pre>\r\n			</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n</div>\r\n</p>\r\n\r\n<p style="text-align:start">The map above maps the string <code>"a"</code> to the number <code>1</code>, <code>"b"</code> to the number <code>2</code>, and <code>"c"</code> to the number <code>3</code>. The commas between each pair are optional, to enhance readability of the code. Clojure treats the commas nearly the same as whitespace. You can put commas anywhere between elements of an expression:</p>\r\n\r\n<p style="text-align:start"> </p>\r\n\r\n<h4 style="text-align: start;">Mas de Este tutorial</h4>\r\n\r\n<ul class=''list-group''>\r\n	<a href=''tuts/rterterte'' class=''list-group-item''>Clojure Tutorial for the Non-Lisp Programmer II Parte</a>\r\n	<a href=''tuts/dffdfdfsdfsdf-sdfgasdfas-df'' class=''list-group-item''>Clojure Tutorial for the Non-Lisp Programmer III Parte</a>\r\n</ul>\r\n', 0, '2015-06-11 13:55:55', 0, 1, '2015-06-11 13:55:55', 'Clojure Tutorial for the Non-Lisp Programmer', 1, 1, 'fgsdgsd', 'I intend to keep this tutorial as accurate and up-to-date as possible. If you have any suggestions for changes, please leave a comment at the bottom of this page.', NULL, NULL, 17);
INSERT INTO `page` (`ID`, `url`, `body`, `parent`, `created`, `ordenation`, `published`, `updated`, `title`, `type`, `level`, `keywords_se`, `description_se`, `associated`, `vars`, `category`) VALUES
(18, 'rterterte', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 17, '2015-06-10 16:23:06', 0, 1, '2015-06-10 16:23:06', 'Clojure Tutorial for the Non-Lisp Programmer II Parte', 1, 1, 'asfsdf', 'sdfsdfs sdf sdfsfd sdfs f', NULL, NULL, 17),
(19, 'zlib-configuration', '<p><span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">Does anyone find these two statements contradictory? Am I not understanding something, or are these statements actually contradicting each other? </span><br />\r\n<br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">Statement ONE from output_handler:</span><br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">&quot;output_handler must be empty if this [zlib.output_compression] is set &#39;On&#39; ! Instead you must use zlib.output_handler.&quot;</span><br />\r\n<br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">Statement TWO from zlib.output_handler:</span><br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">&quot;You cannot specify additional output handlers if zlib.output_compression is activated ...&quot;</span><br />\r\n<br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">Statement ONE says you have to use zlib.output_handler, if zlib.output_compression is turned ON. Statement TWO says that, if zlib.output_compression is turned ON, you cannot use zlib.output_handler. </span><br />\r\n<br />\r\n<span style="background-color:rgb(255, 255, 255); color:rgb(0, 0, 0); font-family:fira mono,source code pro,monospace; font-size:14px">what the heck?</span></p>\r\n', 0, '2015-06-08 17:00:20', 0, 1, '2015-06-08 17:00:20', 'Configuraci&oacute;n en tiempo de ejecuci&oacute;n', 1, 2, 'dfsdfs', 'El comportamiento de estas funciones se ve afectado por la configuraciÃ³n de php.ini.', NULL, NULL, 4),
(20, 'zlib-configuration-2', '<p style="text-align:start">La extensi&oacute;n zlib ofrece la opci&oacute;n de comprimir de manera trasparente las p&aacute;ginas sobre la marcha, si el navegador que hace la solicitud lo soporta. Por lo tanto hay tres opciones en el <a class="link" href="http://php.net/manual/es/configuration.file.php" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">archivo de configuraci&oacute;n</a><var>php.ini</var>.</p>\r\n\r\n<table class="doctable table" style="-webkit-text-stroke-width:0px; background-color:rgb(242, 242, 242); border-collapse:collapse; border-color:rgb(204, 204, 204); border-spacing:0px; color:rgb(51, 51, 51); font-family:fira sans,source sans pro,helvetica,arial,sans-serif; font-size:16px; font-style:normal; font-variant:normal; font-weight:normal; letter-spacing:normal; line-height:24px; margin:0px 0px 1.5rem; orphans:auto; text-align:start; text-indent:0px; text-transform:none; white-space:normal; widows:1; width:824px; word-spacing:0px">\r\n	<caption><strong>Opciones de Configuraci&oacute;n de Zlib</strong></caption>\r\n	<thead>\r\n		<tr>\r\n			<th style="background-color:rgb(196, 201, 223); text-align:left">Nombre</th>\r\n			<th style="background-color:rgb(196, 201, 223); text-align:left">Por defecto</th>\r\n			<th style="background-color:rgb(196, 201, 223); text-align:left">Cambiable</th>\r\n			<th style="background-color:rgb(196, 201, 223); text-align:left">Historial de cambios</th>\r\n		</tr>\r\n	</thead>\r\n	<tbody>\r\n		<tr>\r\n			<td style="vertical-align:top"><a class="link" href="http://php.net/manual/es/zlib.configuration.php#ini.zlib.output-compression" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">zlib.output_compression</a></td>\r\n			<td style="vertical-align:top">&quot;0&quot;</td>\r\n			<td style="vertical-align:top">PHP_INI_ALL</td>\r\n			<td style="vertical-align:top">Disponible desde PHP 4.0.5.</td>\r\n		</tr>\r\n		<tr>\r\n			<td style="vertical-align:top"><a class="link" href="http://php.net/manual/es/zlib.configuration.php#ini.zlib.output-compression-level" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">zlib.output_compression_level</a></td>\r\n			<td style="vertical-align:top">&quot;-1&quot;</td>\r\n			<td style="vertical-align:top">PHP_INI_ALL</td>\r\n			<td style="vertical-align:top">Disponible desde PHP 4.3.0.</td>\r\n		</tr>\r\n		<tr>\r\n			<td style="vertical-align:top"><a class="link" href="http://php.net/manual/es/zlib.configuration.php#ini.zlib.output-handler" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">zlib.output_handler</a></td>\r\n			<td style="vertical-align:top">&quot;&quot;</td>\r\n			<td style="vertical-align:top">PHP_INI_ALL</td>\r\n			<td style="vertical-align:top">Disponible desde PHP 4.3.0.</td>\r\n		</tr>\r\n	</tbody>\r\n</table>\r\n\r\n<p><span style="background-color:rgb(242, 242, 242); color:rgb(51, 51, 51); font-family:fira sans,source sans pro,helvetica,arial,sans-serif; font-size:16px">Para m&aacute;s detalles y definiciones de los modos de PHP_INI_*, vea </span><a class="xref" href="http://php.net/manual/es/configuration.changes.modes.php" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153); font-family: ''Fira Sans'', ''Source Sans Pro'', Helvetica, Arial, sans-serif; font-size: 16px; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: 24px; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 1; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(242, 242, 242);">D&oacute;nde se puede realizar un ajuste de configuraci&oacute;n</a><span style="background-color:rgb(242, 242, 242); color:rgb(51, 51, 51); font-family:fira sans,source sans pro,helvetica,arial,sans-serif; font-size:16px">.</span></p>\r\n\r\n<p style="text-align:start">He aqu&iacute; una breve explicaci&oacute;n de las directivas de configuraci&oacute;n.</p>\r\n\r\n<p style="text-align:start">&nbsp;</p>\r\n\r\n<p><code>zlib.output_compression</code> <a class="type boolean" href="http://php.net/manual/es/language.types.boolean.php" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">boolean</a>/<a class="type integer" href="http://php.net/manual/es/language.types.integer.php" style="border-bottom-width: 1px; border-bottom-style: solid; text-decoration: none; color: rgb(51, 102, 153);">integer</a></p>\r\n\r\n<p>Para comprimir p&aacute;ginas transparentemente. Si esta opci&oacute;n est&aacute; configurada en &quot;On&quot; en <var>php.ini</var> o en la configuraci&oacute;n de Apache, las p&aacute;ginas ser&aacute;n comprimidas si el navegador env&iacute;a un encabezado &quot;Accept-Encoding: gzip&quot; o &quot;deflate&quot;. Los encabezados &quot;Content-Encoding: gzip&quot; (respectivamente &quot;deflate&quot;) y &quot;Vary: Accept-Encoding&quot; ser&aacute;n agregados a la salida. En tiempo de ejecuci&oacute;n, esto se puede configurar s&oacute;lo antes de enviar cualquier salida.</p>\r\n\r\n<p>Esta opci&oacute;n tambi&eacute;n acepta valores enteros en lugar del booleano &quot;On&quot;/&quot;Off&quot;, usando esto se puede configurar el tama&ntilde;o del buffer de salida (por defecto es 4KB).</p>\r\n', 0, '2015-06-08 17:01:13', 0, 1, '2015-06-08 17:01:13', 'Configuraci&oacute;n en tiempo de ejecuci&oacute;n II Parte', 1, 2, 'sdfsdf', 'sdfsdfsdf', NULL, NULL, 4),
(21, 'rails-captura-todas-tus-peticiones-erroneas-404-con-rails', '<p>&iquest;Que bonito es Rails para desarrollar verdad?, poder definir nuestras rutas, nuestros controladores, modelos, test, todo de forma autom&aacute;tica, sin complicaciones o no?, lo cierto es que nos agiliza el desarrollo en gran medida pero hay siempre algunos aspectos que se nos escapan, por ejemplo si llamamos a un controlador o una ruta que no existe, lo hab&eacute;is probado?, cuando Rails hace una petici&oacute;n a un recurso que no existe nos muestra un informe de error muy poco amigable ( y feo) por lo que debemos hacernos cargo de eso cuanto antes, &iquest;Como? Capturando todas las peticiones err&oacute;neas o sin tener en cuenta y redireccionandolas a un &uacute;nico controlador, de esta forma evitamos &ldquo;huecos&rdquo; en nuestro esquema de enrutamiento e identificamos URL que hayamos olvidado de manejar ( Ocurre mas a menudo de lo que creemos).</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>Peticiones Errantes</p>\r\n\r\n<p>Supongamos que alg&uacute;n usuario &ldquo;por equivocaci&oacute;n&rdquo; intente acceder a un recurso en nuestra aplicaci&oacute;n web, por ejemplo a&nbsp; http://miapp.com/algun/recurso/inexistente.&nbsp;&nbsp; Uppss, vemos que nuestra aplicaci&oacute;n nos muestra toda la traza inform&aacute;ndonos que no existe dicho recurso al no existir una ruta, controlador, action ,etc, por lo que primero que todo vamos a hacernos con una ruta. Abrimos el archivo de rutas de nuestra aplicaci&oacute;n (&nbsp; /config/routes.rb ) y a&ntilde;adimos:</p>\r\n\r\n<p>[xx]&nbsp;&nbsp;get &#39;*path&#39; =&gt; &quot;cuatro_cero_cuatro#index&quot; [xxx]</p>\r\n\r\n<p>Aqu&iacute; lo importante en tener en cuenta es que debemos a&ntilde;adirla como &uacute;ltima ruta, para que las request que no &ldquo;entren&rdquo;&nbsp; por las rutas normales sean capturadas por esta &uacute;ltima ( Como una esponja de peticiones que lo absorbe todo). Lo siguiente a definir es nuestro controlador cuatro_cero_cuatro (recordad generar el controlador con el comando Rails generate&hellip; ):</p>\r\n\r\n<p>[xx]dddd[xxx]</p>\r\n\r\n<p>Hemos creado un controlador que procesar&aacute; todas las peticiones y las redireccionar&aacute; al template 404.html.erb. Si llamamos al recurso con una extensi&oacute;n diferente a html ( json, xml, etc) no mostraremos nada. Ahora mismo pode&iacute;s iniciar la aplicaci&oacute;n y probar que efectivamente os redireccionar&aacute; al template ( claro a&uacute;n no lo tenemos, vamos a crearlo).</p>\r\n\r\n<p>[xx]<br />\r\n&lt;% if flash[:status] %&gt;</p>\r\n\r\n<p>&lt;%= flash[:status] %&gt; - 404 Not Found</p>\r\n\r\n<p><br />\r\n&lt;% end %&gt;<br />\r\n[xxx]</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>Y ya lo tenemos!, un &ldquo;404 Not Found&rdquo; totalmente funcional.</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>Registrando el Acceso</p>\r\n\r\n<p>Hasta ahora solo redireccionamos a una p&aacute;gina de Error 404 todas las peticiones que no gestionemos con nuestras rutas, pero si queremos conocer realmente que est&aacute;n haciendo o a que recursos los usuarios m&aacute;s se equivocan vamos a tener que persistir los recursos que se solicitan, y para ello creamos nuestro modelo.</p>\r\n\r\n<p>[xx]<br />\r\nclass Cuatrocerocuatro &lt; ActiveRecord::Base</p>\r\n\r\n<p>def self.add_request(host=&#39;vacio&#39;, path=&#39;vacio&#39;, referer=&#39;vacio&#39;)<br />\r\nrequest = Cuatrocerocuatro.new(:host=&gt;host,:path=&gt;path,:referer=&gt;referer)<br />\r\nrequest.save<br />\r\nend</p>\r\n\r\n<p>end<br />\r\n[xxx]</p>\r\n\r\n<p>No olvidemos nuestro script de migraci&oacute;n:</p>\r\n\r\n<p>[xx]<br />\r\nclass CreateCuatrocerocuatros &lt; ActiveRecord::Migration<br />\r\ndef change<br />\r\ncreate_table :cuatrocerocuatros do |t|<br />\r\nt.string :host, :path, :referer<br />\r\nt.timestamps<br />\r\nend<br />\r\nend</p>\r\n\r\n<p>def self.down<br />\r\ndrop_table :cuatrocerocuatros<br />\r\nend</p>\r\n\r\n<p>end<br />\r\n[xxx]</p>\r\n\r\n<p>Y por supuesto llamar al m&eacute;todo de registrar la petici&oacute;n en nuestro controlador, para esto modificamos el action Index:</p>\r\n\r\n<p>\r\n[xx] \r\ndef index\r\n  Cuatrocerocuatro.add_request(request.host,request.path,request.env[''HTTP_REFERER'' ] || '' '' )\r\n  respond_to do |format|\r\n    flash[:status] = request.path\r\n    format.html { render :file => "public/404.html.erb" }\r\n    format.all { render :nothing => true,:status => "404 Not Found" }\r\n  end\r\nend\r\n[xxx]</p>\r\n\r\n<p>Solo nos queda migrar la tabla ( rake db:migrate) y probar!.</p>\r\n', 0, '2015-06-09 17:43:21', 0, 1, '2015-06-09 17:43:21', 'Captura todas tus peticiones err&oacute;neas (404) con Rails', 1, 1, 'asasd', 'Captura todas tus peticiones erroneas', NULL, NULL, 2),
(22, 'snippets-utilizando-variables-en-sentencias-en-mysql', '<p>Asignar a una variable el resultado de una Sentencia SELECT para utilizarla en otras operaciones es algo que se puede realizar en MySQL de una forma sencilla. La sint&aacute;xis es @nombreVariable := valor. DondenombreVariable es el nombre de la variable y el valor, es el resultado que queremos asignar. Esta variable puede utilizarse en posteriores sentencias donde la sintaxis de la misma permita incluir expresiones, como es el caso de clausulas WHERE o en sentencias INSERT.</p>\r\n\r\n<p>[xx] SELECT @variable:= campo FROM TABLA WHERE campo=&#39;algun valor&#39; [xxx]</p>\r\n\r\n<p><span style="background-color:rgb(255, 255, 255); color:rgb(92, 92, 92); font-family:open sans,helvetica neue,helvetica,arial,sans-serif; font-size:14px">Una vez que obtenemos el valor del campo, podemos utilizarlo en otras sentencias</span></p>\r\n\r\n<p>[xx] DELETE FROM TABLA WHERE campo= @variable [xxx]</p>\r\n\r\n<p><span style="background-color:rgb(255, 255, 255); color:rgb(92, 92, 92); font-family:open sans,helvetica neue,helvetica,arial,sans-serif; font-size:14px">Podemos combinar campos de nuestra tabla, realizar operaciones &nbsp;y el resultado asignarlo a una variable</span></p>\r\n\r\n<p>[xx] SELECT @variable:= MAX(campo,campo2) FROM&nbsp; TABLA WHERE campo=&#39;algun valor&#39; [xxx]</p>\r\n\r\n<p><span style="background-color:rgb(255, 255, 255); color:rgb(92, 92, 92); font-family:open sans,helvetica neue,helvetica,arial,sans-serif; font-size:14px">Esta variable persistir&aacute; en memoria, hasta que le asignemos otro valor o cerremos la sesi&oacute;n MySQL. Por &uacute;ltimo las variables solo pueden utilizarse donde se puedan incluir expresiones, hay que estar pendiente de donde es, ya que no se permiten utilizar variables donde se deben definir contantes o identificadores literales. Por Ejemplo:</span></p>\r\n\r\n<p>[xx]mysql&gt; SET @tbl_name = CONCAT(&#39;tbl_&#39;,FLOOR(RAND( )*1000000)); mysql&gt; <strong>CREATE TABLE @tbl_name (int_col INT);</strong> ERROR 1064 at line 2: You have an error IN your SQL syntax near &#39;@tbl_name (int_col INT)&#39; at line 1 [xxx]</p>\r\n', 0, '2015-06-09 17:28:02', 0, 1, '2015-06-09 17:28:02', 'Utilizando variables en sentencias en MySQL', 1, 1, 'mysql', 'Asignar a una variable el resultado de una Sentencia SELECT para utilizarla en otras operaciones es algo que se puede realizar en MySQL de una forma sencilla. La sintaxis es  @nombreVariable := valor. Donde nombreVariable es el nombre de la variable y el valor, es el resultado que queremos asignar. Esta variable puede utilizarse en posteriores sentencias donde la sintaxis de la misma permita incluir expresiones, como es el caso de clausulas WHERE o en sentencias INSERT.', NULL, NULL, 16),
(23, 'dffdfdfsdfsdf-sdfgasdfas-df', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 17, '2015-06-10 16:28:56', 0, 1, '2015-06-10 16:28:56', 'Clojure Tutorial for the Non-Lisp Programmer III Parte', 1, 2, 'Clojure Tutorial for the Non-Lisp Programmer III Parte', 'Clojure Tutorial for the Non-Lisp Programmer III Parte', NULL, NULL, 17),
(24, 'sdfsdfsdf', '<p>This is my textarea to be replaced with CKEditor.</p>\r\n', 0, '2015-06-11 15:58:13', 0, 1, '2015-06-11 15:58:13', 'Scala para todos', 1, 1, 'seo,seo2,seo3', 'Seo para todos', NULL, NULL, 13);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `page_level`
--

CREATE TABLE IF NOT EXISTS `page_level` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `description` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Volcado de datos para la tabla `page_level`
--

INSERT INTO `page_level` (`ID`, `name`, `description`) VALUES
(1, 'Principiante', 'bla'),
(2, 'Intermedio', NULL),
(3, 'Avanzado', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `page_type`
--

CREATE TABLE IF NOT EXISTS `page_type` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Volcado de datos para la tabla `page_type`
--

INSERT INTO `page_type` (`ID`, `name`) VALUES
(1, 'Tutoriales'),
(2, 'How-To');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `rating_links`
--

CREATE TABLE IF NOT EXISTS `rating_links` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Links` bigint(20) NOT NULL,
  `ID_Users` bigint(20) NOT NULL,
  `vote` decimal(10,2) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_rating_links1_idx` (`ID_Links`),
  KEY `fk_rating_links2_idx` (`ID_Users`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Volcado de datos para la tabla `rating_links`
--

INSERT INTO `rating_links` (`ID`, `ID_Links`, `ID_Users`, `vote`) VALUES
(2, 2, 8, '4.00'),
(3, 1, 8, '5.00'),
(4, 18, 8, '2.00'),
(5, 19, 8, '5.00');

--
-- Disparadores `rating_links`
--
DROP TRIGGER IF EXISTS `rating_link_update_avg`;
DELIMITER //
CREATE TRIGGER `rating_link_update_avg` AFTER INSERT ON `rating_links`
 FOR EACH ROW UPDATE links SET rating = ( SELECT AVG(vote) from rating_links where rating_links.ID_Links=Links.ID) 
, totalVotes=totalVotes+1 WHERE Links.ID=NEW.ID_Links
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `rating_snippet`
--

CREATE TABLE IF NOT EXISTS `rating_snippet` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_User` bigint(20) NOT NULL,
  `ID_Snippet` bigint(20) NOT NULL,
  `voto` decimal(10,2) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FK_rating_snippet1` (`ID_Snippet`),
  KEY `FK_rating_snippet2` (`ID_User`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Tabla para almacenar las valoraciones' AUTO_INCREMENT=34 ;

--
-- Volcado de datos para la tabla `rating_snippet`
--

INSERT INTO `rating_snippet` (`ID`, `ID_User`, `ID_Snippet`, `voto`) VALUES
(16, 8, 38, '3.00'),
(17, 8, 40, '4.00'),
(18, 8, 41, '4.50'),
(19, 8, 55, '4.00'),
(20, 8, 71, '3.50'),
(21, 10, 71, '3.00'),
(22, 14, 80, '3.50'),
(23, 8, 79, '4.00'),
(24, 8, 81, '4.00'),
(26, 8, 89, '4.00'),
(27, 10, 89, '5.00'),
(28, 8, 90, '4.00'),
(29, 10, 90, '4.00'),
(31, 8, 54, '2.50');

--
-- Disparadores `rating_snippet`
--
DROP TRIGGER IF EXISTS `rating_snippet_update_avg`;
DELIMITER //
CREATE TRIGGER `rating_snippet_update_avg` AFTER INSERT ON `rating_snippet`
 FOR EACH ROW UPDATE snippets SET rating = ( SELECT AVG(voto) from rating_snippet where rating_snippet.ID_Snippet=snippets.ID) 
, totalVotes=totalVotes+1 WHERE snippets.ID=NEW.ID_Snippet
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `search_stat`
--

CREATE TABLE IF NOT EXISTS `search_stat` (
  `search_date` date NOT NULL,
  `search_term_id` bigint(20) NOT NULL,
  `hit` bigint(20) NOT NULL DEFAULT '1',
  PRIMARY KEY (`search_date`),
  KEY `fk_stat_term_idx` (`search_term_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `search_term`
--

CREATE TABLE IF NOT EXISTS `search_term` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `term` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `settings`
--

CREATE TABLE IF NOT EXISTS `settings` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `key` varchar(255) NOT NULL,
  `value` longtext NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=16 ;

--
-- Volcado de datos para la tabla `settings`
--

INSERT INTO `settings` (`ID`, `key`, `value`) VALUES
(1, 'site_name', 'El Club del Programador | Tutoriales, tips, herramientas y recursos para el desarrollador'),
(2, 'site_url', 'http://localhost/socialNetwork/'),
(3, 'view', 'default'),
(4, 'logged_pages_base', 'pages/user/'),
(5, 'snippet_editor_message', '/* Este es tu editor de Snippets:\r\n* Con F11 entras en modo edición de pantalla completa. \r\n* Con F11 de nuevo (o Esc) sales del modo pantalla completa.\r\n* Puedes arrastrar y soltar (Drag & Drop) tus archivos de código fuente dentro del editor directamente.\r\n* Sé tú mismo, programa, muéstranos tu talento! */'),
(6, 'admin_pages_base', 'pages/admin/'),
(7, 'avatar_path', 'views/default/images/avatar/'),
(8, 'site_description', 'Tutoriales, tips, herramientas y recursos para el desarrollador'),
(9, 'site_keywords', 'patron, sistema, php, ejemplos, snippet, tutorial'),
(12, 'code_open', '[xx]'),
(13, 'code_close', '[xxx]'),
(14, 'code_open_replace', '<textarea disabled class="code_replace">'),
(15, 'code_close_replace', '</textarea>');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `snippets`
--

CREATE TABLE IF NOT EXISTS `snippets` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `Title` varchar(100) NOT NULL,
  `Code` longtext NOT NULL,
  `description` varchar(600) NOT NULL DEFAULT 'Sin Descripcion',
  `ID_Category` bigint(20) NOT NULL,
  `ID_USER` bigint(20) NOT NULL,
  `rating` decimal(10,2) NOT NULL DEFAULT '0.00',
  `totalVotes` int(10) unsigned NOT NULL DEFAULT '0',
  `totalFav` int(11) NOT NULL DEFAULT '0',
  `totalComments` int(11) NOT NULL DEFAULT '0',
  `added` datetime NOT NULL,
  PRIMARY KEY (`ID`,`ID_Category`,`ID_USER`),
  KEY `fk_snippets_2` (`ID_Category`),
  KEY `fk_snippets_3` (`ID_USER`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Almacena los snippets que se registran en el site\n' AUTO_INCREMENT=95 ;

--
-- Volcado de datos para la tabla `snippets`
--

INSERT INTO `snippets` (`ID`, `Title`, `Code`, `description`, `ID_Category`, `ID_USER`, `rating`, `totalVotes`, `totalFav`, `totalComments`, `added`) VALUES
(38, 'Better HTML 5 basic starter template', '<!doctype html>\r\n<html lang="en">\r\n<head>\r\n  <meta charset="utf-8">\r\n  <title>The Brand New Web Site</title>\r\n  <meta name="description" content="The Brand New Web Site">\r\n  <meta name="author" content="Barattalo.it">\r\n  <link rel="stylesheet" href="css/styles.css?v=1.0">\r\n  <!--[if lt IE 9]>\r\n  <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>\r\n  <![endif]-->\r\n</head>\r\n<body>\r\n \r\n \r\n \r\n	<!-- run javascript at the end -->\r\n  <script src="js/scripts.js"></script>\r\n</body>\r\n</html>', 'This is a basic HTML5 starter template that I use when I start a new project. Scripts should go at the end.', 1, 8, '3.00', 7, 1, 9, '2014-09-29 10:51:51'),
(40, 'HTML5 Ready CSS Reset', '/*&nbsp;&nbsp;&nbsp;html5doctor.com Reset Stylesheet (Eric Meyer''s Reset Reloaded + HTML5 baseline)&nbsp;&nbsp;v1.4 2009-07-27 | Authors: Eric Meyer & Richard Clark&nbsp;&nbsp;html5doctor.com/html-5-reset-stylesheet/*/\r\nhtml, body, div, span, object, iframe,\r\nh1, h2, h3, h4, h5, h6, p, blockquote, pre,\r\nabbr, address, cite, code,\r\ndel, dfn, em, img, ins, kbd, q, samp,\r\nsmall, strong, sub, sup, var,\r\nb, i,\r\ndl, dt, dd, ol, ul, li,\r\nfieldset, form, label, legend,\r\ntable, caption, tbody, tfoot, thead, tr, th, td,\r\narticle, aside, figure, footer, header,&nbsp;hgroup, menu, nav, section, menu,\r\ntime, mark, audio, video {\r\nmargin:0;\r\npadding:0;\r\nborder:0;\r\noutline:0;\r\nfont-size:100%;\r\nvertical-align:baseline;\r\nbackground:transparent;\r\n}\r\n \r\narticle, aside, figure, footer, header,\r\nhgroup, nav, section { display:block; }\r\n \r\nnav ul { list-style:none; }\r\n \r\nblockquote, q { quotes:none; }\r\n \r\nblockquote:before, blockquote:after,\r\nq:before, q:after { content:''''; content:none; }\r\n \r\na { margin:0; padding:0; font-size:100%; vertical-align:baseline; background:transparent; }\r\n \r\nins { background-color:#ff9; color:#000; text-decoration:none; }\r\n \r\nmark { background-color:#ff9; color:#000; font-style:italic; font-weight:bold; }\r\n \r\ndel { text-decoration: line-through; }\r\n \r\nabbr[title], dfn[title] { border-bottom:1px dotted #000; cursor:help; }\r\n \r\n/* tables still need cellspacing="0" in the markup */\r\ntable { border-collapse:collapse; border-spacing:0; }\r\n \r\nhr { display:block; height:1px; border:0; border-top:1px solid #ccc; margin:1em 0; padding:0; }\r\n \r\ninput, select { vertical-align:middle; }\r\n/* END RESET CSS */', 'Eric Meyer''s Reset Reloaded + HTML 5, from Boilerplate', 2, 8, '4.00', 1, 0, 1, '2014-09-29 10:54:05'),
(41, 'Opacity Hack', 'selector {\r\n  filter: alpha(opacity=60); /* MSIE/PC */\r\n  -moz-opacity: 0.6; /* Mozilla 1.6 and older */\r\n  opacity: 0.6;\r\n}', 'Sets the opacity of an element and its children. Doesn''t validate. Mozilla began supporting the opacity rule in version 1.7, so ''-moz-opacity'' may not be necessary...', 2, 8, '4.50', 1, 1, 1, '2014-10-01 17:12:35'),
(43, 'Browser Detection', '// Browser detection\r\n \r\n// Internet Explorer\r\nvar ie  = document.all != null;  //ie4 and above\r\nvar ie5 = document.getElementById && document.all;\r\nvar ie6 = document.getElementById && document.all&&(navigator.appVersion.indexOf("MSIE 6.")>=0);\r\n \r\n// Netscape\r\nvar ns4 = document.layers != null;\r\nvar ns6 = document.getElementById && !document.all;\r\nvar ns  = ns4 || ns6;\r\n \r\n// Firefox\r\nvar ff  = !document.layers && !document.all;\r\n \r\n// Opera\r\nvar op  = navigator.userAgent.indexOf("opera")>0;\r\nvar op7 = op && operaVersion() <= 7;\r\nvar op8 = op && operaVersion() >= 8;\r\n \r\n// Detects the Opera version\r\nfunction operaVersion() {\r\n  agent = navigator.userAgent;\r\n  idx = agent.indexOf("opera");	\r\n  if (idx>-1) {\r\n    return parseInt(agent.subString(idx+6,idx+7));\r\n  }\r\n}', 'Detects the browser and its version.', 1, 8, '0.00', 0, 0, 0, '2014-10-02 17:59:49'),
(44, 'Wordpress: Replace a theme''s Google font with your', '/** ******** ******** ******** ******** ******** ******** ******** ******** \r\n* TITLE:        Add Font\r\n* DESCRIPTION: Add Specific Google Font\r\n*/\r\n \r\nfunction add_fonts() {\r\n  // Styles Format:  wp_enqueue_style($handle, $src, $deps, $ver, $media);\r\n        wp_register_style(''open-sans'', ''http://fonts.googleapis.com/css?family=Bree+Serif:400,300,700'', array(), false, ''all'');\r\n        wp_enqueue_style( ''open-sans'');\r\n}\r\nadd_action(''wp_enqueue_scripts'', ''add_fonts'', 100);', 'You like a theme but it''s referencing a Google font you want to switch out. Here''s the simplest way to do it, by keeping the .class names but switching out the Google Font URL', 4, 8, '0.00', 0, 0, 0, '2014-10-06 11:22:21'),
(45, 'Awesome Image Hover Effect with Caption', '#mainwrapper {  \r\n  font: 10pt normal Arial, sans-serif;  \r\n  height: auto;  \r\n  margin: 80px auto 0 auto;\r\n  text-align: center;  \r\n  width: 660px;  \r\n}  \r\n \r\n#mainwrapper .box {\r\n    border: 5px solid #fff;\r\n    cursor: pointer;\r\n    height: 172px;\r\n    float: left;\r\n    margin-bottom: 20px;\r\n    position: relative;\r\n    overflow: hidden;\r\n    width: 300px;\r\n    -webkit-box-shadow: 1px 1px 1px 1px #ccc;\r\n    -moz-box-shadow: 1px 1px 1px 1px #ccc;\r\n    box-shadow: 1px 1px 1px 1px #ccc;\r\n}\r\n \r\n#mainwrapper .box img {\r\n    position: absolute;\r\n    left: 0;\r\n    -webkit-transition: all 300ms ease-out;\r\n    -moz-transition: all 300ms ease-out;\r\n    -o-transition: all 300ms ease-out;\r\n    -ms-transition: all 300ms ease-out;\r\n    transition: all 300ms ease-out;\r\n	width: auto;\r\n	height: 100%;\r\n}\r\n \r\n \r\n#mainwrapper .box .caption {\r\n    background-color: rgba(0,0,0,0.8);\r\n    position: absolute;\r\n    color: #fff;\r\n    z-index: 100;\r\n    -webkit-transition: all 300ms ease-out;\r\n    -moz-transition: all 300ms ease-out;\r\n    -o-transition: all 300ms ease-out;\r\n    -ms-transition: all 300ms ease-out;\r\n    transition: all 300ms ease-out;\r\n    left: 0;\r\n}\r\n#mainwrapper .box .fade-caption, #mainwrapper .box .scale-caption {\r\n    opacity: 0;\r\n    width: 280px;\r\n    height: 152px;\r\n    text-align: left;\r\n    padding: 15px;\r\n}\r\n \r\n#mainwrapper .box:hover .fade-caption {  \r\n    opacity: 1;  \r\n}', 'This Effect is Mostly Created with Combination of Javascript and Css By the Below CSS Code Create Same Effect without javascript', 5, 8, '0.00', 0, 1, 0, '2014-10-07 16:13:51'),
(47, 'Image Upload with Php', '<!-- Form Area -->\r\n<form enctype="multipart/form-data" action="uploader.php" method="post"> \r\nSelect Image: <input type="file" name="userfile"> \r\n<input type="submit" value="Upload!"> \r\n</form> \r\n<!-- Form Area -->\r\n \r\n<?php \r\n \r\n# Variables\r\n$path = "images/";  \r\n$max_size = "200000"; \r\n \r\n# File\r\n$filename = $_POST[''userfile'']; \r\n \r\n# Control\r\nif (!isset($HTTP_POST_FILES[''userfile''])) exit; \r\n \r\nif (is_uploaded_file($HTTP_POST_FILES[''userfile''][''tmp_name''])) { \r\n \r\nif ($HTTP_POST_FILES[''userfile''][''size'']>$max_size) {  \r\necho "The File is Too Big. The Max File Size is $max_size KB<br>n";  \r\nexit;  \r\n} \r\n \r\n# Type Control\r\nif ( \r\n   ($HTTP_POST_FILES[''userfile''][''type'']=="image/gif")   ||          \r\n   ($HTTP_POST_FILES[''userfile''][''type'']=="image/jpg")   ||   \r\n   ($HTTP_POST_FILES[''userfile''][''type'']=="image/bmp")   || \r\n   ($HTTP_POST_FILES[''userfile''][''type'']=="image/png")   || \r\n   ($HTTP_POST_FILES[''userfile''][''type'']=="image/jpeg") \r\n) \r\n{ \r\n \r\n# If File Exist\r\nif (file_exists($path . $HTTP_POST_FILES[''userfile''][''name'']))  \r\n{  \r\necho "A File With That Name Already Exists!<br>";  \r\nexit;  \r\n} \r\n \r\n$res = copy($HTTP_POST_FILES[''userfile''][''tmp_name''], $path . \r\n \r\n$HTTP_POST_FILES[''userfile''][''name'']); \r\nif (!$res){  \r\necho "Upload Failed!<br>";  \r\nexit;  \r\n}  \r\nelse{  \r\necho "Upload Sucessful!<br>";  \r\n} \r\n \r\necho "File Name: ".$HTTP_POST_FILES[''userfile''][''name'']."<br>"; \r\necho "File Size: ".$HTTP_POST_FILES[''userfile''][''size'']." bytes<br>"; \r\necho "File Type: ".$HTTP_POST_FILES[''userfile''][''type'']."<br>"; \r\necho "<a href=$path".$HTTP_POST_FILES[''userfile''][''name''].">View Image</a>"; \r\n}  \r\nelse  \r\n{ \r\necho "Wrong File Type<br>";  \r\nexit;  \r\n} \r\n} \r\n \r\n?>', 'You can use this script in your projects when you need an image upload function. It checks file type, file size and error report. I also want you to check giochi di spongebob and gratis mahjong too. I hope you will like this code line.\r\n\r\nHave a nice work.\r\n\r\nBest wishes.', 4, 8, '0.00', 0, 0, 0, '2014-10-09 16:02:13'),
(48, 'Simple image rotation with PHP', '/Add before <html> tags\r\n//Script\r\nif ($_COOKIE[\\''head\\''] != \\"\\") {\r\n$ausgabe = $_COOKIE[\\''head\\''];\r\n}\r\nelse {\r\n$bilder = array(\\"bild1\\", \\"bild2\\", \\"bild3\\");\r\n$ausgabe = $bilder[rand(0,2)];\r\nsetcookie (\\"head\\", $ausgabe, time()+1000);\r\n}\r\n \r\n \r\n//Output\r\n$sufix = \\".jpg\\";\r\n$dir = \\"http://localhost/weblog/covers/\\";\r\nif (isset($_COOKIE[head])) {\r\necho \\''<img src=\\"\\''.$dir.$ausgabe.$sufix.\\''\\" alt=\\"Cover\\" />\\'';\r\n}\r\nelse {\r\necho \\''<img src=\\"http://localhost/weblog/alt.jpg\\" />\\'';\r\n}', 'Simple image rotation with PHP', 4, 8, '0.00', 0, 0, 0, '2014-10-09 16:04:21'),
(49, 'Zend_Form_Element isValid', 'public function isValid($value, $context = null)\r\n    {\r\n    $this->setValue($value);\r\n    $value = $this->getValue();\r\n \r\n    if ((('''' === $value) || (null === $value))\r\n    && !$this->isRequired()\r\n    && $this->getAllowEmpty()\r\n    ) {\r\n    return true;\r\n    }\r\n    //....\r\n \r\n    }', 'Zend_Form_Element isValid', 4, 8, '0.00', 0, 0, 0, '2014-10-09 17:37:38'),
(50, 'Style links by file type', 'a[href$=".pdf"] { background: url(icon-pdf.png) left center no-repeat; padding-left: 30px; }\r\na[href$=".doc"] { background: url(icon-doc.png) left center no-repeat; padding-left: 30px; }', 'A good use case for these is labeling file download anchor links with icons based on what type of file they are. For example, PDF''s get a PDF icon and Word Documents get a Word icon', 5, 8, '0.00', 0, 0, 0, '2014-10-09 17:39:13'),
(51, 'file to md5 using Groovy and AntBuilder', 'String fileToMd5( File aFile ) {\r\n    def antx = new AntBuilder();\r\n    antx.checksum( file: aFile.path, property: "result1" )\r\n    return antx.project.properties.result1;\r\n}', 'Groovy file to md5 using Groovy and AntBuilder', 3, 8, '0.00', 0, 0, 0, '2014-10-13 16:15:13'),
(52, 'drawTest', '<!DOCTYPE html>\r\n<html lang="en">\r\n<head>\r\n<meta charset="utf-8">\r\n<title>Draw Test</title>\r\n<script>\r\n//<![CDATA[\r\nvar drawControl = function(drawWidth, drawHeight) {\r\nvar drawContainer = document.createElement(''div''),\r\ntoolbarUl = document.createElement(''ul''),\r\ncanvasEl = document.createElement(''canvas'');\r\n \r\nthis.canvasEl = canvasEl;\r\n \r\nwindow.SelectedButton = ''Line'';\r\n \r\nvar toolbarIcons = [\r\n{name: ''Cursor''},\r\n{name: ''Line''},\r\n{name: ''Rectangle''},\r\n{name: ''Ellipse''},\r\n{name: ''Isosceles Triangle''},\r\n{name: ''Right Triangle''}\r\n];\r\n \r\nfor(var iconIndex = 0; iconIndex < toolbarIcons.length; iconIndex++) {\r\nvar newIconLi = document.createElement(''li''),\r\nnewIconA = document.createElement(''a'');\r\nnewIconA.href = ''#'';\r\nnewIconA.onclick = function(mouseEvt) {\r\nwindow.SelectedButton = String(this.innerHTML);\r\n\r\nif(document.getElementById(''SelectedButton''))\r\ndocument.getElementById(''SelectedButton'').id = '''';\r\nthis.id = ''SelectedButton'';\r\n\r\nmouseEvt.preventDefault();\r\n};\r\nnewIconA.appendChild(document.createTextNode(toolbarIcons[iconIndex].name));\r\nnewIconLi.appendChild(newIconA);\r\ntoolbarUl.appendChild(newIconLi);\r\n}\r\n \r\ncanvasEl.width = drawWidth;\r\ncanvasEl.height = drawHeight;\r\ncanvasEl.style.width = canvasEl.width + ''px'';\r\ncanvasEl.style.height = canvasEl.height + ''px'';\r\n\r\ncanvasEl.onmousedown = function(mouseEvt) {\r\nvar cursorPosition = {\r\nx: mouseEvt.pageX - this.offsetLeft,\r\ny: mouseEvt.pageY - this.offsetTop\r\n};\r\n \r\nwindow.startPoint = {x: Number(cursorPosition.x), y: Number(cursorPosition.y)};\r\n};\r\nwindow.onmousemove = function(mouseEvt) {\r\nvar cursorPosition = {\r\nx: mouseEvt.pageX - window.drawTest.canvasEl.offsetLeft,\r\ny: mouseEvt.pageY - window.drawTest.canvasEl.offsetTop\r\n};\r\n \r\nif(window.startPoint) {\r\nwindow.drawTest.canvasEl.width = window.drawTest.canvasEl.width; // resetting width also clears canvas\r\nwindow.drawTest[''render'' + window.SelectedButton.replace(/\\s/g, '''')](window.startPoint, cursorPosition);\r\n}\r\n};\r\nwindow.onmouseup = function(mouseEvt) {\r\nwindow.startPoint = null;\r\nwindow.drawTest.canvasEl.width = window.drawTest.canvasEl.width; // clears canvas\r\n};\r\n \r\ndrawContainer.appendChild(toolbarUl);\r\ndrawContainer.appendChild(canvasEl);\r\n \r\ndrawContainer.className = ''SniktaDraw'';\r\n \r\ndocument.body.appendChild(drawContainer);\r\n};\r\ndrawControl.prototype.renderLine = function(point1, point2) {\r\nvar ctx = this.canvasEl.getContext(''2d'');\r\n \r\nctx.beginPath();\r\nctx.moveTo(point1.x, point1.y);\r\nctx.lineTo(point2.x, point2.y);\r\nctx.closePath();\r\nctx.stroke();\r\n};\r\ndrawControl.prototype.renderRectangle = function(point1, point2) {\r\nvar ctx = this.canvasEl.getContext(''2d''),\r\nboundingBox = {\r\ntop: Math.min(point1.y, point2.y),\r\nright: Math.max(point1.x, point2.x),\r\nbottom: Math.max(point1.y, point2.y),\r\nleft: Math.min(point1.x, point2.x)\r\n};\r\n \r\nctx.beginPath();\r\nctx.rect(boundingBox.left, boundingBox.top, boundingBox.right - boundingBox.left, boudingBox.bottom - boundingBox.top);\r\nctx.closePath();\r\nctx.stroke();\r\nctx.fill();\r\n};\r\ndrawControl.prototype.renderEllipse = function(point1, point2) { // h/t http://stackoverflow.com/questions/2172798/how-to-draw-an-oval-in-html5-canvas\r\nvar ctx = this.canvasEl.getContext(''2d''),\r\nxRadius = Math.abs(point1.x - point2.x) / 2,\r\ncenterX = (point1.x + point2.x) / 2,\r\ncenterY = (point1.y + point2.y) / 2;\r\nctx.save();\r\nctx.scale(xRadius, xRadius / yRadius);\r\nctx.beginPath();\r\nctx.arc(centerX, centerY, xRadius, 0, Math.PI * 2, false);\r\nctx.stroke();\r\nctx.fill();\r\nctx.closePath();\r\nctx.restore();\r\n};\r\ndrawControl.prototype.renderIsoscelesTriangle = function(point1, point2) {\r\nvar ctx = this.canvasEl.getContext(''2d''),\r\nboundingBox = {\r\ntop: Math.min(point1.y, point2.y),\r\nright: Math.max(point1.x, point2.x),\r\nbottom: Math.max(point1.y, point2.y),\r\nleft: Math.min(point1.x, point2.x)\r\n}, topCenter = {\r\nx: (boundingBox.left + boundingBox.right) / 2,\r\ny: boundingBox.top\r\n}, bottomLeft = {\r\nx: boundingBox.left,\r\ny: boundingBox.bottom\r\n}, bottomRight = {\r\nx: boundingBox.right,\r\ny: boundingBox.bottom\r\n};\r\n \r\nthis.renderLine(topCenter, bottomLeft);\r\nthis.renderLine(topCenter, bottomRight);\r\nthis.renderLine(bottomLeft, bottomRight);\r\n};\r\ndrawControl.prototype.renderRightTriangle = function(point1, point2) {\r\nvar ctx = this.canvasEl.getContext(''2d''),\r\nboundingBox = {\r\ntop: Math.min(point1.y, point2.y),\r\nright: Math.max(point1.x, point2.x),\r\nbottom: Math.max(point1.y, point2.y),\r\nleft: Math.min(point1.x, point2.x)\r\n}, topLeft = {\r\nx: boundingBox.left,\r\ny: boundingBox.top\r\n}, bottomRight = {\r\nx: boundingBox.right,\r\ny: boundingBox.bottom\r\n}, bottomLeft = {\r\nx: boundingBox.left,\r\ny: boundingBox.bottom\r\n};\r\nthis.renderLine(topLeft, bottomRight);\r\nthis.renderLine(topLeft, bottomLeft);\r\nthis.renderLine(bottomLeft, bottomRight);\r\n};\r\n function runTest() {\r\nwindow.drawTest = new drawControl(640, 480);\r\n}\r\n//]]>\r\n</script>\r\n<style type="text/css">\r\n/*<![CDATA[*/\r\n/* http://meyerweb.com/eric/tools/css/reset/sv2.0 | 20110126sLicense:none (public domain)*/html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,embed,figure,figcaption,footer,header,hgroup,menu,nav,output,ruby,section,summary,time,mark,audio,video{margin:0;padding:0;border:0;font-size:100%;font:inherit;vertical-align:baseline;}/* HTML5 display-role reset for older browsers */article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section{display:block;}body{line-height:1;}ol,ul{list-style:none;}blockquote,q{quotes:none;}blockquote:before,blockquote:after,q:before,q:after{content:'''';content:none;}table{border-collapse:collapse;border-spacing:0;}\r\n body{padding:1em;font:80% Tahoma,Arial,Helvetica,sans-serif;}\r\n \r\ndiv.SniktaDraw{position:relative;}\r\n \r\ndiv.SniktaDraw>ul>li>a {\r\ndisplay: block;\r\nfloat: left;\r\ncolor: black;\r\ntext-decoration: none;\r\nborder: 1px solid #d3d3d3;\r\nbackground: #f5f5f5;\r\npadding: 0.25em 0.6em;\r\nmargin-left: -1px;\r\n}\r\ndiv.SniktaDraw>ul>li:first-child>a{margin-left:0px;}\r\ndiv.SniktaDraw>ul>li>a#SelectedButton,div.SniktaDraw>ul>li>a:hover{background:#d3d3d3;border-color:#a1a1a1;position:relative;}\r\n div.SniktaDraw>canvas {\r\nborder: 1px solid #d3d3d3;\r\ndisplay: block;\r\nclear: both;\r\n}\r\n/*]]>*/\r\n</style>\r\n</head>\r\n<body onload="runTest();">\r\n</body>\r\n</html>', 'drawTest', 6, 8, '0.00', 0, 0, 0, '2014-10-13 16:20:56'),
(53, 'i18n Deserializer', '// Deserializer for i18n objects.\r\n// \r\n// This will take all the child elements in the .i18n element and populate the localization object\r\n// with the textual content in the element and extend the parent object with dot notation key based\r\n// on the class of the element.\r\n// \r\n// Eg.  	<div class="i18n">\r\n//       		<div class="demo textString">Translated text</div>\r\n//        	</div>\r\n// \r\n//          would add the key(s) localization.demo.textString\r\n//          and set the value for the key to "Translated text"\r\n// \r\n// Use {i18n()} to populate internationalization.\r\n// \r\n// @return undefined\r\n \r\nvar localization = {};\r\n \r\nfunction i18n(){ //Sets up the i18n object\r\n    var i18n = {};\r\n    $(".i18n").children().each(function(){\r\n        if($(this).attr("class")) {\r\n            var val = $(this).text();\r\n            var serialized = [$(this).attr("class").replace(/\\s/gi,".")].join(".");\r\n \r\n            if (serialized.indexOf(''.'') > -1) {\r\n              var attrs = serialized.split(''.'');\r\n              var tx = i18n;\r\n \r\n              for (var i = 0; i < attrs.length - 1; i++) {\r\n                if (i18n[attrs[i]] == undefined)\r\n                  i18n[attrs[i]] = {};\r\n                tx = i18n[attrs[i]];\r\n              }\r\n \r\n              tx[attrs[attrs.length - 1]] = val;\r\n \r\n            } else {\r\n \r\n              if (i18n[serialized] != null) {\r\n                if (!i18n[serialized].push) {\r\n                  i18n[serialized] = [i18n[serialized]];\r\n                }\r\n \r\n                i18n[serialized].push(val);\r\n              } else {\r\n                i18n[serialized] = val;\r\n              }\r\n \r\n            }\r\n        }\r\n    });\r\n    $.extend(localization,i18n);\r\n}', 'Deserializer for i18n objects.\r\n\r\nThis will take all the child elements in the .i18n element and populate the localization object with the textual content in the element and extend the parent object with dot notation key based on the class of the element.\r\n\r\nEg. Translated text\r\n\r\nwould add the key(s) localization.demo.textString and set the value for the key to "Translated text"\r\n\r\nUse {i18n()} t', 7, 8, '0.00', 0, 0, 0, '2014-10-13 16:22:28'),
(54, 'Deleting a file, directory, or symlink', 'import ''dart:io'';\r\n\r\nvoid main() {\r\n  // Create a temporary directory.\r\n  Directory.systemTemp.createTemp(''my_temp_dir'')\r\n    .then((directory) {\r\n      // Confirm it exists.\r\n      directory.exists().then(print); // Prints ''true''.\r\n      // Delete the directory.\r\n      return directory.delete();\r\n    })\r\n    .then((directory) {\r\n      // Confirm it no longer exists.\r\n      directory.exists().then(print); // Prints ''false''\r\n    });\r\n}', 'Use the FilesSystemEntity delete() method to delete a file, directory, or symlink. This method is inherited by File, Directory, and Link.', 12, 8, '2.50', 1, 0, 0, '2014-10-13 16:29:39'),
(55, 'Complex Operations', 'object complexOps extends Application {\r\n  class Complex(val re: Double, val im: Double) {\r\n    def + (that: Complex) =\r\n      new Complex(re + that.re, im + that.im)\r\n    def - (that: Complex) =\r\n      new Complex(re - that.re, im - that.im)\r\n    def * (that: Complex) =\r\n      new Complex(re * that.re - im * that.im,\r\n                  re * that.im + im * that.re)\r\n    def / (that: Complex) = {\r\n      val denom = that.re * that.re + that.im * that.im\r\n      new Complex((re * that.re + im * that.im) / denom,\r\n                  (im * that.re - re * that.im) / denom)\r\n    }\r\n    override def toString =\r\n      re + (if (im < 0) "-" + (-im) else "+" + im) + "*i"\r\n  }\r\n  val x = new Complex(2, 1); val y = new Complex(1, 3)\r\n  println(x + y)\r\n}', 'Complex Operations', 13, 8, '4.00', 1, 0, 0, '2014-10-13 16:31:36'),
(56, 'My first GUI python calculator', 'from Tkinter import *\r\nimport tkMessageBox\r\n \r\ndef calc():\r\n    try:\r\n        #addition\r\n        if oper.get() == ''+'':\r\n            try:\r\n                value = float(num1.get()) + float(num2.get())\r\n            except:\r\n                tkMessageBox.showerror("Error!", ''Something went wrong! Maybe invalid entries'')\r\n \r\n        #subtraction\r\n        if oper.get() == ''-'':\r\n            try:\r\n                value = float(num1.get()) - float(num2.get())\r\n            except:\r\n                tkMessageBox.showerror("Error!", ''Something went wrong! Maybe invalid entries'')\r\n        #multiplication\r\n        if oper.get() == ''x'' or oper.get() == ''*'':\r\n            try:\r\n                value = float(num1.get()) * float(num2.get())\r\n            except:\r\n                tkMessageBox.showerror("Error!", ''Something went wrong! Maybe invalid entries'')\r\n        #Division\r\n        if oper.get() == ''/'':\r\n            if num2.get() == ''0'':\r\n                #checks if user is trying to divide by zero\r\n                tkMessageBox.showerror(''Division Error'', ''num2 value = 0 No dividing by 0'')\r\n            else:\r\n                try:\r\n                    value = float(num1.get()) / float(num2.get())\r\n                except:\r\n                    tkMessageBox.showerror("Error!", ''Something went wrong! Maybe invalid entries'')\r\n \r\n        str(num1)\r\n        str(oper)\r\n        str(num2)\r\n        answer = Label(app, text=''{0} {1} {2}=''.format(num1.get(), oper.get(), num2.get()))\r\n        answer.grid(row=3, column= 0, sticky=SW)\r\n        answer2 = Label(app, text=value)\r\n        answer2.grid(row=4, column= 0, sticky=S)\r\n    except:\r\n        tkMessageBox.showerror("Error!", ''Something went wrong! Maybe invalid entries'')\r\n \r\n \r\nglobal value\r\nvalue = 0\r\n \r\n#Modify window\r\nroot = Tk()\r\nroot.title(''Calculator by Nicholas Cannon'')\r\nroot.geometry(''340x132'')\r\nroot.resizable(0,0)\r\n \r\n \r\n#creating frame\r\napp = Frame(root)\r\napp.pack()\r\n \r\n#window attributes below\r\nlabel1 = Label(app, text=''Enter number 1 -->'')\r\nlabel1.grid(row=0, column=0, sticky=NW)\r\n \r\nlabel2 = Label(app, text=''Enter operator -->'')\r\nlabel2.grid(row=1, column=0, sticky=W)\r\n \r\nlabel3 = Label(app, text=''Enter number 2 -->'')\r\nlabel3.grid(row=2, column= 0, sticky=W)\r\n \r\nglobal num1\r\nnum1 = StringVar()\r\nnumber1 = Entry(app, textvariable= num1)\r\nnumber1.grid(row=0, column=1, sticky=NE)\r\n \r\nglobal oper\r\noper = StringVar()\r\noperator = Entry(app, textvariable= oper)\r\noperator.grid(row=1, column=1, sticky=E)\r\n \r\nglobal num2\r\nnum2 = StringVar()\r\nnumber2 = Entry(app, textvariable = num2)\r\nnumber2.grid(row=2, column=1, sticky=E)\r\n \r\nbutton = Button(app, text=''Calculate'', command = calc)\r\nbutton.grid(row=3, column=1, sticky=SE)\r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n#start main loop\r\nroot.mainloop()', 'My first calculator with GUI. I made the GUI with tkinter.', 14, 8, '0.00', 0, 0, 0, '2014-10-13 16:34:44'),
(57, 'Navigation Menu', '<!-- Adding the ng-app declaration to initialize AngularJS -->\r\n<div id="main" ng-app>\r\n<!-- The navigation menu will get the value of the "active" variable as a class.\r\n The $event.preventDefault() stops the page from jumping when a link is clicked. -->\r\n\r\n<nav class="{{active}}" ng-click="$event.preventDefault()">\r\n\r\n<!-- When a link in the menu is clicked, we set the active variable -->\r\n\r\n<a href="#" class="home" ng-click="active=''home''">Home</a>\r\n<a href="#" class="projects" ng-click="active=''projects''">Projects</a>\r\n<a href="#" class="services" ng-click="active=''services''">Services</a>\r\n<a href="#" class="contact" ng-click="active=''contact''">Contact</a>\r\n</nav>\r\n\r\n<!-- ng-show will show an element if the value in the quotes is truthful,\r\n while ng-hide does the opposite. Because the active variable is not set\r\n initially, this will cause the first paragraph to be visible. -->\r\n\r\n<p ng-hide="active">Please click a menu item</p>\r\n<p ng-show="active">You chose <b>{{active}}</b></p>\r\n</div>', 'As a first example, we will build a navigation menu that highlights the selected entry', 15, 8, '0.00', 0, 0, 0, '2014-10-13 16:49:04'),
(58, 'Css Media Querie', '@media screen and (min-width:1200px){\r\nimg {\r\nmax-width:1000px;\r\n}\r\n\r\n#container{\r\nwidth:1100px;\r\n}\r\n\r\nheader h1 a{\r\nwidth:1100px;\r\nheight:180px;\r\nbackground:url(image.jpg) no-repeat 0 0;\r\n}\r\n\r\n}', 'Ejemplo de Media Querie', 5, 8, '0.00', 0, 0, 0, '2014-10-16 12:44:20'),
(59, 'Replace string mysql', 'UPDATE your_table\r\nSET your_field = REPLACE(your_field, ''articles/updates/'', ''articles/news/'')\r\nWHERE your_field LIKE ''%articles/updates/%''', 'Replace string mysql', 16, 8, '0.00', 0, 0, 0, '2014-10-16 12:45:14'),
(60, 'Print json object in JavaScript', 'var s='''';\r\n          //--------------------\r\n          function get_obj(objel, deep) {\r\n \r\n              var s3= new Array(deep*3).join(''&nbsp;'');\r\n \r\n              for (var el in objel) {\r\n \r\n                  s3+=typeof(objel[el])+'' : ''+el+'' = ''\r\n \r\n                          if (typeof(objel[el])==''object'')\r\n \r\n                              s3+=String.fromCharCode(13)+String.fromCharCode(10)+\r\n                                       get_obj(objel[el], deep+1);\r\n                           else {\r\n                              s3+= objel[el]+String.fromCharCode(13)+String.fromCharCode(10);\r\n                                  }\r\n             }\r\n                 return s3;\r\n \r\n          }\r\n          //--------------------\r\n          s=get_obj(inf,0);', 'Print json object in JavaScript', 7, 8, '0.00', 0, 0, 0, '2014-10-20 13:21:11'),
(61, 'Create new Object From Variable in JavaScript', 'var className = "PluginClass";\r\n// get a reference to the class object itself\r\n// (we''ve assumed the class is defined in a global scope)\r\nvar myclass = window[className];\r\n// now you have a reference to the object, the new keyword will work:\r\nvar inst = new myclass();\r\n// now call to the required method of your class\r\n// alert(inst.validate("4111111111111111", "visa"));', 'This example of code allows you to create a new object in javascript (using simple inheritance) such that the class of the object is defined from a variable. After creating the object you may use it for your purposes.', 7, 8, '0.00', 0, 0, 0, '2014-10-20 13:26:41'),
(62, 'Create new Object From Variable in JavaScript', 'var className = "PluginClass";\r\n// get a reference to the class object itself\r\n// (we''ve assumed the class is defined in a global scope)\r\nvar myclass = window[className];\r\n// now you have a reference to the object, the new keyword will work:\r\nvar inst = new myclass();\r\n// now call to the required method of your class\r\n// alert(inst.validate("4111111111111111", "visa"));', 'This example of code allows you to create a new object in javascript (using simple inheritance) such that the class of the object is defined from a variable. After creating the object you may use it for your purposes.', 7, 8, '0.00', 0, 0, 0, '2014-10-20 13:27:43'),
(63, 'strip html tags from a string in Javascript', '<HTML> \r\n<HEAD> \r\n<TITLE> Regular Expressions: stripping HTML tags </TITLE> \r\n</HEAD> \r\n<BODY> \r\n<SCRIPT LANGUAGE="JavaScript"> \r\nvar htstring = ''<p align="Left"><b>Hello</b> <I>World</I></p>''; \r\nvar stripped = htstring.replace(/(<([^>]+)>)/ig,""); \r\n \r\nwith (document) { \r\nwrite (''Original string:'' + htstring + ''<br>''); \r\nwrite (''Stripped string:<br><br>'' + stripped); \r\n} \r\n</SCRIPT> \r\n</BODY> \r\n</HTML>', 'strip html tags from a string in Javascript', 7, 8, '0.00', 0, 0, 0, '2014-10-20 15:42:43'),
(64, 'strip html tags from a string in Javascript', '<HTML> \r\n<HEAD> \r\n<TITLE> Regular Expressions: stripping HTML tags </TITLE> \r\n</HEAD> \r\n<BODY> \r\n<SCRIPT LANGUAGE="JavaScript"> \r\nvar htstring = ''<p align="Left"><b>Hello</b> <I>World</I></p>''; \r\nvar stripped = htstring.replace(/(<([^>]+)>)/ig,""); \r\n \r\nwith (document) { \r\nwrite (''Original string:'' + htstring + ''<br>''); \r\nwrite (''Stripped string:<br><br>'' + stripped); \r\n} \r\n</SCRIPT> \r\n</BODY> \r\n</HTML>', 'strip html tags from a string in Javascript', 7, 8, '0.00', 0, 0, 0, '2014-10-20 15:55:47'),
(65, 'javascript replace all instances in a string', '<script type="text/javascript">\r\nvar visitorName = "Chuck";\r\nvar myOldString = "Hello username! I hope you enjoy your stay username.";\r\nvar myNewString = myOldString.replace(/username/g, visitorName);\r\n \r\ndocument.write("Old string =  " + myOldString); \r\ndocument.write("<br />New string = " + myNewString);\r\n \r\n</script>', 'javascript replace all instances in a string', 7, 8, '0.00', 0, 0, 0, '2014-10-20 15:56:24'),
(66, 'PHP replace words in a string', '<?php\r\n    $variable = ereg_replace(''delete'', '''', $variable);\r\n?>', 'PHP replace words in a string', 4, 8, '0.00', 0, 0, 0, '2014-10-20 15:57:29'),
(67, 'Find words adjacent to a word given by its index i', '# Created December 1, 2010\r\n# Released into the public domain by Josh Atkins\r\n#\r\n# find_adjacent_words(''This is a test'', 5, 1, true)  #=> This\r\n# find_adjacent_words(''This is a test'', 5, 2, false) #=> a test\r\n# find_adjacent_words(''This is a test'', 5, 2, 3)     #=> [''This'', ''a test'']\r\n \r\ndef find_adjacent_words(text, position, word_count, left_of_position)\r\nif left_of_position == 3\r\nadjacent_words = Array.new\r\nadjacent_words.insert(-1, find_adjacent_words(text, position, word_count, true))\r\nadjacent_words.insert(-1, find_adjacent_words(text, position, word_count, false))\r\nreturn adjacent_words\r\nelse\r\nif position == nil || !position.kind_of?(Integer) || position > text.length\r\nposition = left_of_position ? text.length : 0\r\nelse\r\nwhile text[position] != 32 && position >= 0 && position <= text.length\r\nposition += left_of_position ? -1 : 1\r\nend\r\nend\r\noriginal_position  = position\r\ntext               = text.strip\r\ncurrent_word_count = left_of_position ? 0 : word_count || nil\r\nwhile (left_of_position && position > 1 && (!word_count || current_word_count < word_count)) || (!left_of_position && position < text.length && (!current_word_count || current_word_count > 0))\r\nposition += left_of_position ? -1 : 1\r\nif (left_of_position && !(position > 1 && text[position] == 32 && text[position-1] == 32)) || (!left_of_position && !(position < text.length && text[position] == 32 && text[position+1] == 32))\r\ncurrent_word_count += left_of_position ? 1 : -1 if text[position+(left_of_position ? -1 : 1)] == 32 if current_word_count\r\nend\r\nend\r\nreturn (left_of_position ? text[(position > 0 ? position - 1 : position)..original_position] : text[original_position..position]).to_s.strip\r\nend\r\nend', 'Find words adjacent to a word given by its index in a string', 4, 8, '0.00', 0, 0, 0, '2014-10-20 16:08:25'),
(68, 'Find words adjacent to a word given by its index i', '# Created December 1, 2010\r\n# Released into the public domain by Josh Atkins\r\n#\r\n# find_adjacent_words(''This is a test'', 5, 1, true)  #=> This\r\n# find_adjacent_words(''This is a test'', 5, 2, false) #=> a test\r\n# find_adjacent_words(''This is a test'', 5, 2, 3)     #=> [''This'', ''a test'']\r\n \r\ndef find_adjacent_words(text, position, word_count, left_of_position)\r\nif left_of_position == 3\r\nadjacent_words = Array.new\r\nadjacent_words.insert(-1, find_adjacent_words(text, position, word_count, true))\r\nadjacent_words.insert(-1, find_adjacent_words(text, position, word_count, false))\r\nreturn adjacent_words\r\nelse\r\nif position == nil || !position.kind_of?(Integer) || position > text.length\r\nposition = left_of_position ? text.length : 0\r\nelse\r\nwhile text[position] != 32 && position >= 0 && position <= text.length\r\nposition += left_of_position ? -1 : 1\r\nend\r\nend\r\noriginal_position  = position\r\ntext               = text.strip\r\ncurrent_word_count = left_of_position ? 0 : word_count || nil\r\nwhile (left_of_position && position > 1 && (!word_count || current_word_count < word_count)) || (!left_of_position && position < text.length && (!current_word_count || current_word_count > 0))\r\nposition += left_of_position ? -1 : 1\r\nif (left_of_position && !(position > 1 && text[position] == 32 && text[position-1] == 32)) || (!left_of_position && !(position < text.length && text[position] == 32 && text[position+1] == 32))\r\ncurrent_word_count += left_of_position ? 1 : -1 if text[position+(left_of_position ? -1 : 1)] == 32 if current_word_count\r\nend\r\nend\r\nreturn (left_of_position ? text[(position > 0 ? position - 1 : position)..original_position] : text[original_position..position]).to_s.strip\r\nend\r\nend', 'Find words adjacent to a word given by its index in a string', 4, 8, '0.00', 0, 0, 1, '2014-10-20 16:09:37'),
(69, 'Get unique field values', 'fieldName = ""\r\nnamesList = sorted(set((row.getValue(fieldName) for row in arcpy.SearchCursor(r'''',fields=fieldName))))\r\nfor x in namesList:\r\n    print x', 'Get unique field values', 14, 8, '0.00', 0, 0, 0, '2014-10-20 16:10:53'),
(70, 'get list of all values in a field MySQL', 'SELECT DISTINCT ''fieldname'' FROM ''tablename''', 'get list of all values in a field MySQL', 16, 8, '0.00', 0, 0, 1, '2014-10-20 16:12:02'),
(71, 'Get Enumerated Values for a MySQL Field', 'function enum($table, $field) {\r\n$result = @mysql_query("show columns from {$table} like \\"$field\\"");\r\n$result = @mysql_fetch_assoc($result);\r\nif($result["Type"])\r\n{\r\npreg_match("/(enum\\((.*?)\\))/", $result["Type"], $enumArray);\r\n$getEnumSet = explode("''", $enumArray["2"]);\r\n$getEnumSet = preg_replace("/,/", "", $getEnumSet);\r\n$enumFields = array();\r\nforeach($getEnumSet as $enumFieldValue)\r\n{\r\nif($enumFieldValue)\r\n{\r\n$enumFields[] = $enumFieldValue;\r\n}\r\n}\r\nreturn $enumFields;\r\n}\r\nreturn false;\r\n}', 'Returns an array of values specified for an enumerated MySQL field', 16, 8, '3.25', 2, 2, 6, '2014-10-20 16:14:09'),
(74, '&ntilde;a&ntilde;ito avi&oacute;n', 'Tu codigo aquí.... php', ',ENT_COMPAT,''UTF-8'' Vamos a construir un ejemplo en PHP que realice la misma funcionalidad, eso si, omitir&eacute; por cuestiones pr&aacute;cticas, el estilo y dise&ntilde;o de Facebook, as&iacute; que comencemos. La idea que subyace detr&aacute;s de esta funcionalidad es la de poder procesar el contenido de la p&aacute;gina en cuesti&oacute;n y extraer de ella toda la informaci&oacute;n contenida en las etiquetas HTML (&lt;title&gt;, &lt;img&gt;, &lt;meta description&gt;, etc), sirvi&eacute;ndonos para ello de funciones especificas que nos proporciona PHP.', 5, 8, '0.00', 0, 1, 0, '2014-11-04 10:44:50'),
(75, 'delete from Snippets where 1;', 'Todo tuyo.... dfgadsfgsd', 'Vamos a construir un ejemplo en PHP que realice la misma funcionalidad, eso si, omitir&eacute; por cuestiones pr&aacute;cticas, el estilo y dise&ntilde;o de Facebook, as&iacute; que comencemos. La idea que subyace detr&aacute;s de esta funcionalidad es la de poder procesar el contenido de la p&aacute;gina en cuesti&oacute;n y extraer de ella toda la informaci&oacute;n contenida en las etiquetas HTML (&lt;title&gt;, &lt;img&gt;, &lt;meta description&gt;, etc), sirvi&eacute;ndonos para ello de funciones especificas que nos proporciona PHP.', 4, 8, '0.00', 0, 1, 0, '2014-11-04 10:48:53'),
(77, 'Animated Tooltips With Very Little Coding', 'The HTML:\r\n<div class="tipWrapper">\r\n<span class="tipbox spanlink">In the horizontal</span>\r\n<div class="tiphor"> You can get some wild effects by\r\n playing with the borders and shadows.</div></div>\r\n \r\n<div id="vslide" class="tipWrapper"><span id="tboxv" class="tipbox spanlink">or in the vertical</span>\r\n<div class="tipvert">This  tooltip can go up or down to fit into any design.</div></div>\r\n \r\nCSS for horizontal:\r\n \r\n.tiphor {\r\n                    position:absolute;\r\n                    visibility:hidden;\r\n                    overflow:hidden;\r\n                    z-index:0;\r\n                    top:0px;\r\n                    left:0px;\r\n                    width:4px;\r\n                    height:4.5em;\r\n                    background-color:white;                                       \r\n                } \r\n.tipbox:hover     {\r\n                                visibility:visible;\r\n                                width:150px;\r\n                                height:4em;\r\n                                overflow:hidden;\r\n                            } \r\n.spanlink:hover~.tiphor {\r\n                                        left:150px;\r\n                                        transition:left 2s;\r\n                                        width:160px;\r\n                                        visibility:visible;\r\n                              }\r\n \r\nCSS for vertical:\r\n \r\n#tboxv  {\r\n                width:160px;\r\n            }\r\n.tipvert {\r\n                    position:absolute;\r\n                    visibility:hidden;\r\n                    overflow:hidden;\r\n                    z-index:0;\r\n                    top:0px;\r\n                    left:0px;\r\n                    width:4px;\r\n                    height:4.5em;\r\n                    background-color:white;                                       \r\n                } \r\n.spanlink:hover~.tipvert {\r\n                                        top:-5em;\r\n                                        transition:top 2s;\r\n                                        width:160px;\r\n                                        visibility:visible;\r\n                              }\r\n#hereseven  {\r\n                    margin-top:8em;\r\n                  }', 'Using a sibling relationship in CSS allows all kinds of tooltips effects without scripting or a lot of coding. There are a bunch of different effects on the page and the possibilities are limited only by imagination.', 5, 10, '0.00', 0, 0, 0, '2014-11-12 17:44:52'),
(78, 'HTML5 Mobile Video with Flash, Silverlight, Java, Animated GIF and Download fallback', '<!DOCTYPE html>\r\n<html>\r\n<head>\r\n  <meta charset="utf-8" />\r\n  <title>HTML5 Video with Flash and Download fallback</title>\r\n  <!--[if lt IE 9]>\r\n     <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>\r\n  <![endif]-->\r\n  <style type="text/css">\r\n      header, section, footer, aside, nav, article, figure, audio, video, canvas { display:block; }\r\n      img { border:0; vertical-align:middle; }\r\n  </style>\r\n</head>\r\n<body>\r\n<div id="movie">\r\n  <video id="movie_html5" width="320" height="240" preload controls>\r\n    <source src="video.webm" type=''video/webm; codecs="vp8, vorbis"'' />\r\n    <source src="video.ogv" type=''video/ogg; codecs="theora, vorbis"'' />\r\n    <source src="video.mp4" />\r\n    <object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" id="movie_object" name="movie_object" width="320" height="240" type="application/x-shockwave-flash" data="player.swf"> \r\n      <param name="movie" value="player.swf" />\r\n      <param name="wmode" value="transparent" />\r\n      <param name="allowfullscreen" value="true" />\r\n      <param name="allowscriptaccess" value="always" />\r\n      <param name="flashvars" value="file=video.flv&image=video.jpg" />\r\n      <embed type="application/x-shockwave-flash" id="movie_embed" name="movie_embed" \r\n             src="player.swf"\r\n             width="320"\r\n             height="240"\r\n             bgcolor="#000000"\r\n             allowscriptaccess="always"\r\n             allowfullscreen="true"\r\n             wmode="transparent"\r\n             flashvars="file=video.flv&image=video.jpg">\r\n        <noembed>\r\n          <!-- Java Applet OGG player, see: http://git.xiph.org/?p=cortado.git;a=blob;f=README -->\r\n          <applet id="movie_java" name="movie_java" code="com.fluendo.player.Cortado.class" archive="http://theora.org/cortado.jar" width="320" height="240"> \r\n            <param name="url" value="video.ogv" />\r\n            <param name="autoPlay" value="false" />\r\n            <!-- Mobile stream (Image can be an Animated GIF for playback with no sound) -->\r\n            <div id="movie_mobile">              \r\n              <a href="video.3gp"><img alt="PLAY" src="video.gif" width="320" height="240" /></a>\r\n            </div>\r\n          </applet>       \r\n        </noembed>       \r\n      </embed>\r\n    </object>\r\n   <!-- JW Silverlight WMV player -->\r\n    <div id="movie_silverlight" name="movie_silverlight" style="display:none; position:relative; top:8px; left:8px;">&nbsp;</div>\r\n    <script type="text/javascript" src="silverlight.js"></script>\r\n    <script type="text/javascript" src="wmvplayer.js"></script>    \r\n    <script type="text/javascript">      \r\n      var hasSilverlight = Boolean(window.Silverlight);\r\n      if (hasSilverlight) {\r\n        var cnt = document.getElementById("movie_silverlight"); //media container\r\n        cnt.style.display = ''block'';                           //show Silverlight\r\n        document.getElementById("movie_object").style.display=''none''; //hide Flash, Java and Mobile\r\n        var xaml = "wmvplayer.xaml";                            //XAML player\r\n        var cfg = { file:"video.wmv", image:"video.jpg", width:"320", height:"240" }; //configure WMV file, preview thumbnail, width/height\r\n        var ply = new jeroenwijering.Player(cnt, xaml, cfg);\r\n      }\r\n    </script>\r\n  </video>\r\n  <!-- Offer direct download link to play in Browser plugin or allow System default Media Player to take over -->\r\n  <p>\r\n  Download: <a href="video.mp4">MP4</a> | <a href="video.webm">WebM</a> | <a href="video.ogv">Ogg</a> | <a href="video.3gp">3gp</a> | <a href="video.flv">Flash</a> | <a href="video.wmv">WMV</a>\r\n  </p>\r\n</div>\r\n</body>\r\n</html>', 'Due to device capability inconsistencies and fragmentation, in order to play on the broadest range of devices, approximately 6 formats would be required:\r\nFlash - VP6 (IE 4-6, Netscape, some tablets/PDAs, legacy Desktop browsers)\r\nSilverlight - WMV (IE7+, Windows Phone)\r\nHTML5 video - Ogg Theora (FF, Fenick, Opera, Opera Mobile)\r\nHTML5 video - WebM VP8 (Chrome, Android phones/tablets)\r\nHTML5 video or Java Applet - MP4 baseline H.264 (Safari, iOS devices: iPad/iPod/iPhone, J2SE/J2ME devices)\r\nMobile video - 3GP via RTSP or HTTP ', 5, 12, '0.00', 0, 0, 0, '2014-11-13 12:32:02'),
(79, 'Save all images from RSS feed', 'RSS_URL = ''http://35photo.ru/rss/photo_day.xml''\r\nOUT_NAM = "/var/tmp/${new Date().format(''YYYYMMddHHmmss'')}"\r\n \r\nnew XmlParser().parse(RSS_URL).channel.item.description*.text()*.findAll(/(?i)<img\\s[^>]+>/) {im ->\r\n	im.findAll(/(?i)src=[''"]([^''"]+\\.([^.''"]+))[''"]/) {ma, sr, ex ->\r\n		new FileOutputStream(OUT_NAM + "${sr.hashCode()}.$ex").write(new URL(sr).getBytes())\r\n	}\r\n}', 'Gets &quot;src&quot; attributes from all &quot;img&quot; tags in RSS entries descriptions', 3, 13, '4.00', 1, 1, 1, '2014-11-13 12:33:23'),
(80, 'List all images from directory', '<?php\r\n                $dir = "assets/images/";\r\n                foreach (glob($dir . ''/*'') as $filename) {\r\n                   echo "<img src=''" . $filename . "''><br/>";\r\n            }', 'List all images from directory', 4, 14, '3.50', 1, 1, 1, '2014-11-13 12:38:13'),
(81, 'Listing special forms', '(keys clojure.lang.Compiler/specials)', 'Title tells everything', 17, 8, '4.00', 1, 1, 0, '2014-12-02 13:02:47'),
(89, 'dfafasdfasdfasdfasf', 'fdgsdfgsdfgsdfg', 'afgdfgfdsdf', 17, 8, '4.50', 2, 2, 2, '2015-02-10 00:51:11'),
(90, '23123123', '1323123', '123123123', 15, 8, '4.00', 2, 2, 2, '2015-02-14 20:00:45'),
(94, 'How to add text-to-speech and speech-to-text features to your SIP software by using Microsoft Speech', 'using System;\r\nusing System.Threading;\r\nusing Ozeki.Media.MediaHandlers;\r\nusing Ozeki.Media.MediaHandlers.Speech;\r\n \r\nnamespace Microsoft_Speech_Platform\r\n{\r\n    class Program\r\n    {\r\n        static Speaker _speaker;\r\n        static Microphone _microphone;\r\n        static MediaConnector _connector;\r\n        static TextToSpeech _tts;\r\n        static SpeechToText _stt;\r\n \r\n        static void Main(string[] args)\r\n        {\r\n            _microphone = Microphone.GetDefaultDevice();\r\n            _speaker = Speaker.GetDefaultDevice();\r\n            _connector = new MediaConnector();\r\n \r\n            SetupTextToSpeech();\r\n \r\n            SetupSpeechToText();\r\n \r\n            while (true) Thread.Sleep(10);\r\n        }\r\n \r\n        static void SetupTextToSpeech()\r\n        {\r\n            _tts = new TextToSpeech();\r\n            _tts.AddTTSEngine(new MSSpeechPlatformTTS());\r\n \r\n            var voices = _tts.GetAvailableVoices();\r\n            foreach (var voice in voices)\r\n            {\r\n                if (voice.Language.Equals("en-GB"))\r\n                    _tts.ChangeLanguage(voice.Language, voice.Name);\r\n            }\r\n \r\n            _speaker.Start();\r\n            _connector.Connect(_tts, _speaker);\r\n            _tts.AddAndStartText("Hello World!");\r\n        }\r\n \r\n \r\n        static void SetupSpeechToText()\r\n        {\r\n            string[] words = {"Hello", "Welcome"};\r\n            _stt = SpeechToText.CreateInstance(words);\r\n            _stt.WordRecognized += stt_WordRecognized;\r\n            _stt.ChangeSTTEngine(new MSSpeechPlatformSTT());\r\n \r\n            var recognizers = _stt.GetRecognizers();\r\n            foreach (var recognizer in recognizers)\r\n            {\r\n                if (recognizer.Culture.Name == "en-GB")\r\n                    _stt.ChangeRecognizer(recognizer.ID);\r\n            }\r\n \r\n            _connector.Connect(_microphone, _stt);\r\n            _microphone.Start();\r\n        }\r\n \r\n        static void stt_WordRecognized(object sender, SpeechDetectionEventArgs e)\r\n        {\r\n            Console.WriteLine("Word recognized: {0}", e.Word);\r\n        }\r\n    }\r\n}', 'In my previous snippet I have written about converting text to speech using C#. This code snippet can be used not just for allowing your computer to read txt aloud, but also for speech recognition. To implement this functionality I used Microsoft Speech Platform 11 along with Ozeki VoIP SIP SDK. The first one provides two classes (MSSpeechPlatformSTT, MSSpeechPlatformTTS) for text-to-speech and speech-to-text, and the VoIP SDK ensures the necessary VoIP components. The source code below is ready for use, so you only need to copy&amp;paste it', 13, 8, '0.00', 0, 0, 0, '2015-06-22 17:05:54');

--
-- Disparadores `snippets`
--
DROP TRIGGER IF EXISTS `delete_snippet`;
DELIMITER //
CREATE TRIGGER `delete_snippet` BEFORE DELETE ON `snippets`
 FOR EACH ROW begin
SET @disable_trigger = 1;
DELETE from lista_favoritos_snippets where lista_favoritos_snippets.ID_Snippets = old.ID;
DELETE from snippet_log where snippet_log.ID_Snippet = old.ID;
DELETE from lista_tag_snippet where lista_tag_snippet.ID_Snippets = old.ID;
DELETE from comment_snippet where comment_snippet.ID_Snippet = old.ID;
DELETE from rating_snippet where rating_snippet.ID_Snippet = old.ID;
SET @disable_trigger = NULL;
END
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `snippet_log`
--

CREATE TABLE IF NOT EXISTS `snippet_log` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `ID_Snippet` bigint(20) NOT NULL,
  `event` varchar(100) CHARACTER SET utf8 NOT NULL,
  `ID_User` bigint(20) NOT NULL,
  `created` datetime NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk_snippetlog_snippet_idx` (`ID_Snippet`),
  KEY `fk_snippetlog_user_idx` (`ID_User`),
  KEY `fk_snippetlog_event_idx` (`event`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=102 ;

--
-- Volcado de datos para la tabla `snippet_log`
--

INSERT INTO `snippet_log` (`ID`, `ID_Snippet`, `event`, `ID_User`, `created`) VALUES
(16, 90, 'user.snippet.add', 8, '2015-02-14 20:00:45'),
(17, 90, 'user.rating.add', 8, '2015-02-14 20:05:07'),
(18, 90, 'user.fav.add', 8, '2015-02-14 20:05:08'),
(19, 90, 'user.comment.add', 8, '2015-02-14 20:05:12'),
(20, 90, 'user.fav.add', 10, '2015-02-15 13:47:49'),
(21, 90, 'user.rating.add', 10, '2015-02-15 13:47:50'),
(22, 90, 'user.comment.add', 10, '2015-02-15 13:47:56'),
(23, 41, 'user.fav.add', 8, '2015-03-01 21:06:13'),
(24, 41, 'user.fav.del', 8, '2015-03-01 21:06:16'),
(25, 41, 'user.comment.add', 8, '2015-03-01 21:06:23'),
(26, 41, 'user.fav.add', 8, '2015-03-01 21:06:42'),
(34, 54, 'user.fav.add', 8, '2015-05-13 17:06:47'),
(35, 54, 'user.rating.add', 8, '2015-05-13 17:06:49'),
(36, 80, 'user.fav.add', 8, '2015-05-13 17:07:44'),
(37, 80, 'user.comment.add', 8, '2015-05-13 17:07:57'),
(97, 80, 'user.fav.del', 8, '2015-06-22 13:27:23'),
(98, 80, 'user.fav.add', 8, '2015-06-22 13:27:24'),
(99, 79, 'user.fav.del', 8, '2015-06-22 13:27:37'),
(100, 79, 'user.fav.add', 8, '2015-06-22 13:27:43'),
(101, 94, 'user.snippet.add', 8, '2015-06-22 17:05:54');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tags`
--

CREATE TABLE IF NOT EXISTS `tags` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `tag_name` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Tabla que almacena las etiquetas con las que se catalogan cu /* comment truncated */ /*alquier cosa en el site\n*/' AUTO_INCREMENT=128 ;

--
-- Volcado de datos para la tabla `tags`
--

INSERT INTO `tags` (`ID`, `tag_name`) VALUES
(1, 'starter'),
(2, 'template'),
(3, 'html5'),
(4, 'ejemplo'),
(5, 'eric''s meyer reset'),
(6, 'css'),
(7, 'opacity'),
(8, 'hack'),
(9, 'tutorial'),
(10, 'javascript'),
(11, 'browser'),
(12, 'detector'),
(13, 'html'),
(14, 'php'),
(15, 'como'),
(16, 'funcion'),
(17, 'wordpress'),
(18, 'image'),
(19, 'hover'),
(20, 'effect'),
(21, 'caption'),
(22, 'snippet'),
(23, 'Upload'),
(24, 'Form'),
(25, 'simple'),
(26, 'rotation'),
(27, 'zend'),
(28, 'isvalid'),
(29, 'function'),
(30, 'framework'),
(31, 'file'),
(32, 'type'),
(33, 'icon'),
(34, 'sample'),
(35, 'groovy'),
(36, 'antbuilder'),
(37, 'md5'),
(38, 'draw'),
(39, 'test'),
(40, 'i18n'),
(41, 'deserializer'),
(42, 'delete'),
(43, 'directory'),
(44, 'symlink'),
(45, 'complex'),
(46, 'operations'),
(47, 'numbers'),
(48, 'scala'),
(49, 'calculator'),
(50, 'gui'),
(51, 'navigation'),
(52, 'menu'),
(53, 'media'),
(54, 'query'),
(55, 'replace'),
(56, 'string'),
(57, 'print'),
(58, 'json'),
(59, 'new'),
(60, 'object'),
(61, 'call'),
(62, 'strip'),
(63, 'tags'),
(64, 'instances'),
(65, 'word'),
(66, 'how'),
(67, 'find'),
(68, 'words'),
(69, 'adjacent'),
(70, 'unique'),
(71, 'fields'),
(72, 'distinct'),
(73, 'table'),
(74, 'enumerated'),
(75, 'values'),
(76, 'array'),
(77, 'field'),
(78, 'mysql'),
(79, 'tooltip'),
(80, 'animate'),
(81, 'fallback'),
(82, 'save'),
(83, 'url'),
(84, 'images'),
(85, 'list'),
(86, 'clojure'),
(87, 'listing'),
(88, 'example'),
(89, 'yosemite'),
(90, 'rails'),
(91, 'install'),
(92, 'gdf'),
(93, 'ruby'),
(94, 'sdfsdfsdf'),
(95, 'validar'),
(96, 'links'),
(97, 'twitter'),
(98, 'dfgsfgsdg'),
(99, 'dfgdsg'),
(100, 'dfvfv'),
(101, 'ff'),
(102, 'gfsdfg'),
(103, 'lik'),
(104, 'gggg'),
(105, 'fgdfg'),
(106, 'fdgsdf'),
(107, 'sdfgsdfg'),
(108, 'dfg'),
(109, '2322'),
(110, 'aaaa'),
(111, 'aaaaa'),
(112, 'sssss'),
(113, 'eee'),
(114, 'e'),
(115, 'ee'),
(116, 'marca'),
(117, 'logo'),
(118, 'angular'),
(119, 'apache'),
(120, 'dart'),
(121, ''),
(122, 'sdfsdf'),
(123, '12311'),
(124, 'c++'),
(125, 'voip'),
(126, 'text-to'),
(127, 'speech');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Tabla que almacena toda la información referente al usuario',
  `user_login` varchar(60) NOT NULL COMMENT 'login\n',
  `user_pass` varchar(100) NOT NULL COMMENT 'password',
  `password_salt` varchar(100) NOT NULL COMMENT 'semilla del password',
  `twitter_name` varchar(100) DEFAULT NULL COMMENT 'Perfil twitter',
  `user_email` varchar(100) NOT NULL COMMENT 'email\n',
  `user_url` varchar(100) DEFAULT NULL COMMENT 'URL del usuario',
  `user_registered` datetime NOT NULL COMMENT 'Fecha de registro',
  `user_status` int(11) NOT NULL COMMENT 'Define los status del \nusuario\n\n0 - inactivo\n1- active\n2- banned\n3- deleted',
  `display_name` varchar(100) NOT NULL COMMENT 'Nombre que mostramos',
  `experience_points` bigint(20) NOT NULL DEFAULT '0' COMMENT 'Puntos de experiencia',
  `reputation_points` bigint(20) NOT NULL DEFAULT '0' COMMENT 'puntos de reputacion',
  `level_points` bigint(20) NOT NULL DEFAULT '0' COMMENT 'El nivel de gamificacion',
  `reset_key` varchar(100) DEFAULT NULL COMMENT 'Clave para el reset del password',
  `reset_expires` datetime DEFAULT NULL COMMENT 'Fecha de expiración para la solicitud de reset de password',
  `activation_key` varchar(100) DEFAULT NULL COMMENT 'Almacena la clave para la activacióndel usuario cuando se registra',
  `user_level` int(11) NOT NULL DEFAULT '0' COMMENT 'Define los niveles del  usuario  basico 0  - admin 10',
  `profile_image` varchar(500) NOT NULL DEFAULT 'comment.png',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=19 ;

--
-- Volcado de datos para la tabla `users`
--

INSERT INTO `users` (`ID`, `user_login`, `user_pass`, `password_salt`, `twitter_name`, `user_email`, `user_url`, `user_registered`, `user_status`, `display_name`, `experience_points`, `reputation_points`, `level_points`, `reset_key`, `reset_expires`, `activation_key`, `user_level`, `profile_image`) VALUES
(8, 'oscarlgarcia', '$2a$07$106c84709b2b7a5e6ef78OyF32F8K7bPfSiIbfvx3UDKZaLZZquoW', '$2a$07$106c84709b2b7a5e6ef78a7f7e226c2d656ca810e48d$', NULL, 'oscarlgarcia@gmail.com', NULL, '2014-03-06 01:26:52', 1, 'oscarlgarcia', 157, 107, 1, '60eeb732ec5dac454243178ae6c0c4d8', '2015-03-26 16:57:58', '624e86b4c38468e7695a8ac71ebd4c61', 0, 'oscar.jpg'),
(10, 'pedro', '$2a$07$1c173912f89d4921d411euyGh1S5gXebi9./pkETmwwIQgby5Ibty', '$2a$07$1c173912f89d4921d411e8cef1e53e9acf5c5c6839de$', NULL, 'pedroperez@ff.com', NULL, '2014-10-20 17:50:29', 1, 'pedro', 57, 7, 0, NULL, NULL, '5033fd6a244f95b9d33e4a388f0f0eb4', 0, 'user3.png'),
(11, 'director', '$2a$07$441112768ee904e1c81bbOY6nCGoWambFLWFsBygKLjHAHuy2r6kC', '$2a$07$441112768ee904e1c81bbae0cb9110b3c473e4b6a444$', NULL, 'oscar.garcia@elclubdelprogramador.com', NULL, '2014-11-06 14:58:21', 1, 'director', 10, 1, 0, NULL, NULL, '13945b33caf58e2d7770f0637f008807', 10, 'user3.png'),
(12, 'usuario2', '$2a$07$fb026efc8f989177cd0dduBxYBVgBgRbTEppx5C35VaQqs63noETG', '$2a$07$fb026efc8f989177cd0dd227a5a0a4d01a7ebb5bf26e$', NULL, 'usuarios2@gmsail.com', NULL, '2014-11-13 12:25:42', 1, 'usuario2', 10, 1, 0, NULL, NULL, '101be302634e6345c900ce239d5c5905', 0, 'gravatar.jpg'),
(13, 'usuario3', '$2a$07$653ca6a92c2b784192e93Oi5Ghi4zWQ8aryZZeklD2dIvqpj.Qtgu', '$2a$07$653ca6a92c2b784192e93a2f2c433a079fcf28b193b0$', NULL, 'usuarios3@gmsail.com', NULL, '2014-11-13 12:26:25', 1, 'usuario3', 36, 5, 0, NULL, NULL, '6af78b66065197267fd4d1c0663dadbf', 0, 'user2.png'),
(14, 'usuario4', '$2a$07$b4d6df0f9e5dc9c4cf7aceKu2Z.mMePcjAnRYIqtLSmZ9DDw97zuG', '$2a$07$b4d6df0f9e5dc9c4cf7acf7682caccef3b398b2aeb18$', NULL, 'usuarios4@gmsail.com', NULL, '2014-11-13 12:26:41', 1, 'usuario4', 36, 5, 0, NULL, NULL, '99cd3c5c9584d87afb801e966ce90462', 0, 'use4.png'),
(15, 'usuario33', '$2a$07$8d2b9e64e8a270943c0e4O7/9xAD27qzxcj9VlwCrXDPDZgu6n3hq', '$2a$07$8d2b9e64e8a270943c0e4bcdbee09c1a081fc8c735fa$', NULL, 'pepo@gmailq.com', NULL, '2015-01-25 18:25:17', 0, 'usuario33', 0, 0, 0, NULL, NULL, 'dfc413eb9bdf80c35158267bab8ccb6d', 0, 'comment.png'),
(16, 'joselito', '$2a$07$90acf88669b8d7a087345uez1pAPhPq5hH4RFMiojvXDAxWYEGs/W', '$2a$07$90acf88669b8d7a0873454ed8607a465409b6aa67d71$', NULL, '111@ww.com', NULL, '2015-03-31 17:44:46', 0, 'joselito', 0, 0, 0, NULL, NULL, '47beb7c7a45efc6a7e17d663b1677f72', 0, 'comment.png'),
(17, 'joselito1', '$2a$07$8ae54628eb36fa0a77ad8ubMcatC63P8F9kQQbvgvNV60MiOafRl2', '$2a$07$8ae54628eb36fa0a77ad8753e6489e4d7650c63662dd$', NULL, '111@ww.com11', NULL, '2015-03-31 17:47:38', 0, 'joselito1', 0, 0, 0, NULL, NULL, '76c6d6a13d3687818bc2a868d4e22c60', 0, 'comment.png'),
(18, 'joselito2', '$2a$07$a04108d704628180ef865uWlNoSHMmITGBVUEVq7i4TNg9EIipuou', '$2a$07$a04108d704628180ef86555af41582190f7171d7289a$', NULL, '111@ww.com1111', NULL, '2015-03-31 17:51:35', 0, 'joselito2', 0, 0, 0, NULL, NULL, 'f0d732a66e5fb7ae40da31171d010c9e', 0, 'comment.png');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `user_event`
--

CREATE TABLE IF NOT EXISTS `user_event` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Son las acciones que determinado usuario puede realizar, estas acciones se van añadiendo a medida que el usuario avance de niveles\n',
  `ID_User` bigint(20) NOT NULL,
  `eventName` varchar(100) NOT NULL,
  `ipaddress` varchar(60) DEFAULT NULL,
  `data` varchar(400) DEFAULT NULL,
  `dateExecuted` datetime NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `fk2_idx` (`ID_User`),
  KEY `fk_user_event_1_idx` (`eventName`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='Tabla que almacena los eventos del site que ha realizado un  /* comment truncated */ /*usuario*/' AUTO_INCREMENT=1331 ;

--
-- Volcado de datos para la tabla `user_event`
--

INSERT INTO `user_event` (`ID`, `ID_User`, `eventName`, `ipaddress`, `data`, `dateExecuted`) VALUES
(144, 8, 'user.password.forgot', '127.0.0.1', '{"email":""oscarlgarcia@gmail.com""}', '2014-03-24 23:47:03'),
(145, 8, 'user.password.reset', '127.0.0.1', '', '2014-03-24 23:48:12'),
(146, 8, 'user.login', '127.0.0.1', '', '2014-03-25 00:02:01'),
(147, 8, 'user.logout', '127.0.0.1', '', '2014-03-25 00:08:15'),
(148, 8, 'user.login', '127.0.0.1', '', '2014-03-25 00:08:22'),
(149, 8, 'user.login', '127.0.0.1', '', '2014-03-26 22:07:28'),
(150, 8, 'user.logout', '127.0.0.1', '', '2014-03-26 22:11:33'),
(151, 8, 'user.login', '127.0.0.1', '', '2014-03-26 22:11:38'),
(152, 8, 'user.logout', '127.0.0.1', '', '2014-03-26 22:11:48'),
(153, 8, 'user.login', '127.0.0.1', '', '2014-03-26 22:12:10'),
(154, 8, 'user.login', '127.0.0.1', '', '2014-03-26 23:47:42'),
(155, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:01:45'),
(156, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 00:09:19'),
(157, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:09:24'),
(158, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:12:41'),
(159, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 00:13:27'),
(160, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:13:39'),
(161, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 00:22:21'),
(162, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:22:27'),
(163, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 00:23:47'),
(164, 8, 'user.login', '127.0.0.1', '', '2014-03-27 00:24:50'),
(165, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 01:03:13'),
(166, 8, 'user.login', '127.0.0.1', '', '2014-03-27 01:03:26'),
(167, 8, 'user.logout', '127.0.0.1', '', '2014-03-27 01:03:48'),
(168, 8, 'user.login', '127.0.0.1', '', '2014-03-27 01:10:20'),
(169, 8, 'user.login', '127.0.0.1', '', '2014-03-28 00:21:04'),
(170, 8, 'user.login', '127.0.0.1', '', '2014-03-28 00:43:46'),
(171, 8, 'user.logout', '127.0.0.1', '', '2014-03-28 00:49:32'),
(172, 8, 'user.login', '127.0.0.1', '', '2014-03-28 00:49:39'),
(173, 8, 'user.login', '127.0.0.1', '', '2014-03-28 01:56:30'),
(174, 8, 'user.logout', '127.0.0.1', '', '2014-03-28 02:01:00'),
(175, 8, 'user.login', '127.0.0.1', '', '2014-03-28 02:01:05'),
(176, 8, 'user.login', '::1', '', '2014-04-01 00:06:27'),
(177, 8, 'user.login', '::1', '', '2014-04-02 00:00:30'),
(178, 8, 'user.logout', '::1', '', '2014-04-02 00:06:29'),
(179, 8, 'user.login', '::1', '', '2014-04-02 23:50:09'),
(180, 8, 'user.login', '::1', '', '2014-04-04 19:20:12'),
(181, 8, 'user.login', '::1', '', '2014-04-04 22:55:53'),
(182, 8, 'user.logout', '::1', '', '2014-04-04 23:44:36'),
(183, 8, 'user.login', '::1', '', '2014-04-04 23:45:38'),
(184, 8, 'user.logout', '::1', '', '2014-04-05 00:23:12'),
(185, 8, 'user.login', '::1', '', '2014-04-05 00:23:34'),
(186, 8, 'user.logout', '::1', '', '2014-04-05 00:36:32'),
(187, 8, 'user.login', '::1', '', '2014-04-05 00:37:45'),
(188, 8, 'user.login', '::1', '', '2014-04-05 10:27:48'),
(189, 8, 'user.login', '::1', '', '2014-04-11 19:21:45'),
(190, 8, 'user.logout', '::1', '', '2014-04-11 19:33:48'),
(191, 8, 'user.login', '::1', '', '2014-04-11 19:33:52'),
(192, 8, 'user.login', '::1', '', '2014-04-11 21:27:14'),
(193, 8, 'user.login', '::1', '', '2014-04-12 19:38:36'),
(194, 8, 'user.login', '::1', '', '2014-04-12 19:46:12'),
(195, 8, 'user.login', '::1', '', '2014-04-13 12:08:02'),
(196, 8, 'user.login', '::1', '', '2014-04-13 12:11:40'),
(197, 8, 'user.logout', '::1', '', '2014-04-13 12:13:14'),
(198, 8, 'user.login', '::1', '', '2014-04-13 12:14:18'),
(199, 8, 'user.login', '::1', '', '2014-04-13 14:57:13'),
(200, 8, 'user.login', '::1', '', '2014-04-13 20:10:28'),
(201, 8, 'user.logout', '::1', '', '2014-04-13 20:20:19'),
(202, 8, 'user.login', '::1', '', '2014-04-13 20:20:28'),
(203, 8, 'user.login', '::1', '', '2014-04-13 20:26:01'),
(204, 8, 'user.login', '::1', '', '2014-04-13 21:48:38'),
(205, 8, 'user.login', '::1', '', '2014-04-13 21:56:36'),
(206, 8, 'user.login', '::1', '', '2014-04-13 23:13:56'),
(207, 8, 'user.login', '::1', '', '2014-04-13 23:33:13'),
(208, 8, 'user.logout', '::1', '', '2014-04-13 23:33:23'),
(209, 8, 'user.login', '::1', '', '2014-04-14 21:39:29'),
(210, 8, 'user.login', '::1', '', '2014-04-14 23:41:12'),
(211, 8, 'user.login', '::1', '', '2014-04-15 22:09:58'),
(212, 8, 'user.logout', '::1', '', '2014-04-15 22:10:03'),
(213, 8, 'user.login', '::1', '', '2014-04-15 22:10:10'),
(214, 8, 'user.login', '::1', '', '2014-04-17 21:55:43'),
(215, 8, 'user.login', '::1', '', '2014-04-18 16:37:20'),
(216, 8, 'user.login', '::1', '', '2014-04-18 16:47:12'),
(217, 8, 'user.login', '::1', '', '2014-04-18 18:18:43'),
(218, 8, 'user.login', '::1', '', '2014-04-18 23:20:17'),
(219, 8, 'user.logout', '::1', '', '2014-04-18 23:21:21'),
(220, 8, 'user.login', '::1', '', '2014-04-18 23:21:36'),
(221, 8, 'user.logout', '::1', '', '2014-04-18 23:33:04'),
(222, 8, 'user.login', '::1', '', '2014-04-18 23:33:10'),
(223, 8, 'user.login', '::1', '', '2014-04-19 14:36:23'),
(224, 8, 'user.login', '::1', '', '2014-04-19 14:45:26'),
(225, 8, 'user.login', '::1', '', '2014-04-19 20:21:37'),
(226, 8, 'user.login', '::1', '', '2014-04-19 21:50:44'),
(227, 8, 'user.login', '::1', '', '2014-04-20 14:08:42'),
(228, 8, 'user.login', '::1', '', '2014-04-20 19:59:03'),
(229, 8, 'user.logout', '::1', '', '2014-04-20 20:24:39'),
(230, 8, 'user.login', '::1', '', '2014-04-20 20:24:59'),
(231, 8, 'user.logout', '::1', '', '2014-04-20 20:25:15'),
(232, 8, 'user.login', '::1', '', '2014-04-20 20:25:37'),
(233, 8, 'user.logout', '::1', '', '2014-04-20 20:26:57'),
(234, 8, 'user.login', '::1', '', '2014-04-20 20:33:37'),
(235, 8, 'user.login', '::1', '', '2014-04-20 23:34:03'),
(236, 8, 'user.logout', '::1', '', '2014-04-21 01:22:43'),
(237, 8, 'user.login', '::1', '', '2014-04-21 12:43:44'),
(238, 8, 'user.login', '::1', '', '2014-04-21 13:52:44'),
(239, 8, 'user.login', '::1', '', '2014-04-21 16:05:32'),
(240, 8, 'user.login', '::1', '', '2014-04-21 17:50:00'),
(241, 8, 'user.login', '::1', '', '2014-04-21 18:43:29'),
(242, 8, 'user.login', '::1', '', '2014-04-21 19:58:13'),
(243, 8, 'user.login', '::1', '', '2014-04-21 22:55:22'),
(244, 8, 'user.login', '::1', '', '2014-04-21 23:28:23'),
(245, 8, 'user.login', '127.0.0.1', '', '2014-04-21 23:30:58'),
(246, 8, 'user.login', '::1', '', '2014-04-22 19:33:28'),
(247, 8, 'user.login', '::1', '', '2014-04-24 01:07:07'),
(248, 8, 'user.login', '::1', '', '2014-04-24 19:32:30'),
(249, 8, 'user.login', '::1', '', '2014-04-26 00:29:24'),
(250, 8, 'user.login', '::1', '', '2014-04-26 17:38:31'),
(251, 8, 'user.login', '::1', '', '2014-04-26 20:17:12'),
(252, 8, 'user.login', '::1', '', '2014-04-26 22:14:38'),
(253, 8, 'user.login', '::1', '', '2014-04-27 15:30:38'),
(254, 8, 'user.login', '::1', '', '2014-04-28 00:41:50'),
(255, 8, 'user.login', '127.0.0.1', '', '2014-04-28 00:44:43'),
(256, 8, 'user.login', '::1', '', '2014-04-28 00:48:57'),
(257, 8, 'user.login', '::1', '', '2014-04-28 19:16:46'),
(258, 8, 'user.login', '::1', '', '2014-04-28 21:14:58'),
(259, 8, 'user.login', '::1', '', '2014-05-01 19:14:40'),
(260, 8, 'user.login', '::1', '', '2014-05-01 19:15:58'),
(261, 8, 'user.login', '::1', '', '2014-05-02 21:54:40'),
(262, 8, 'user.login', '::1', '', '2014-05-03 17:30:07'),
(263, 8, 'user.login', '::1', '', '2014-05-03 18:41:46'),
(264, 8, 'user.login', '::1', '', '2014-05-03 19:28:13'),
(265, 8, 'user.logout', '::1', '', '2014-05-03 19:28:22'),
(266, 8, 'user.login', '::1', '', '2014-05-03 20:01:35'),
(267, 8, 'user.login', '::1', '', '2014-05-06 00:12:06'),
(268, 8, 'user.login', '::1', '', '2014-05-12 00:36:06'),
(269, 8, 'user.logout', '::1', '', '2014-05-12 00:43:03'),
(270, 8, 'user.login', '::1', '', '2014-05-12 00:43:08'),
(271, 8, 'user.login', '127.0.0.1', '', '2014-05-12 23:45:31'),
(272, 8, 'user.login', '127.0.0.1', '', '2014-05-19 23:31:26'),
(273, 8, 'user.login', '127.0.0.1', '', '2014-05-22 20:36:34'),
(274, 8, 'user.login', '::1', '', '2014-05-24 00:51:27'),
(275, 8, 'user.login', '::1', '', '2014-05-24 16:22:01'),
(276, 8, 'user.login', '::1', '', '2014-05-24 17:15:33'),
(277, 8, 'user.login', '::1', '', '2014-05-26 22:53:52'),
(278, 8, 'user.login', '::1', '', '2014-05-28 20:53:55'),
(279, 8, 'user.login', '127.0.0.1', '', '2014-05-28 21:08:23'),
(280, 8, 'user.login', '::1', '', '2014-05-28 22:54:49'),
(281, 8, 'user.login', '127.0.0.1', '', '2014-05-28 23:51:41'),
(282, 8, 'user.login', '::1', '', '2014-05-28 23:53:06'),
(283, 8, 'user.login', '::1', '', '2014-05-29 23:38:13'),
(284, 8, 'user.login', '127.0.0.1', '', '2014-05-29 23:47:21'),
(285, 8, 'user.login', '127.0.0.1', '', '2014-05-30 00:08:33'),
(286, 8, 'user.login', '::1', '', '2014-05-30 21:13:43'),
(287, 8, 'user.login', '::1', '', '2014-05-31 00:05:16'),
(288, 8, 'user.login', '::1', '', '2014-05-31 23:24:58'),
(289, 8, 'user.login', '::1', '', '2014-06-01 14:52:45'),
(290, 8, 'user.login', '::1', '', '2014-06-01 16:50:21'),
(291, 8, 'user.login', '::1', '', '2014-06-01 18:51:07'),
(292, 8, 'user.login', '::1', '', '2014-06-01 20:47:13'),
(293, 8, 'user.login', '::1', '', '2014-06-01 22:20:38'),
(294, 8, 'user.login', '::1', '', '2014-06-01 23:52:28'),
(295, 8, 'user.logout', '::1', '', '2014-06-02 00:05:08'),
(296, 8, 'user.login', '::1', '', '2014-06-02 00:05:48'),
(297, 8, 'user.logout', '::1', '', '2014-06-02 00:29:10'),
(298, 8, 'user.login', '::1', '', '2014-06-02 00:30:43'),
(299, 8, 'user.logout', '::1', '', '2014-06-02 00:30:48'),
(300, 8, 'user.login', '::1', '', '2014-06-02 00:34:37'),
(301, 8, 'user.login', '::1', '', '2014-06-02 23:22:08'),
(302, 8, 'user.login', '::1', '', '2014-06-03 21:03:19'),
(303, 8, 'user.login', '::1', '', '2014-06-03 23:09:10'),
(304, 8, 'user.login', '127.0.0.1', '', '2014-06-03 23:51:27'),
(305, 8, 'user.login', '::1', '', '2014-06-04 20:27:22'),
(306, 8, 'user.login', '::1', '', '2014-06-04 21:20:56'),
(307, 8, 'user.login', '127.0.0.1', '', '2014-06-04 22:06:08'),
(308, 8, 'user.login', '::1', '', '2014-06-05 00:00:33'),
(309, 8, 'user.login', '::1', '', '2014-06-05 22:58:44'),
(310, 8, 'user.login', '::1', '', '2014-06-06 00:25:32'),
(311, 8, 'user.login', '::1', '', '2014-06-07 00:51:59'),
(312, 8, 'user.login', '::1', '', '2014-06-07 02:36:49'),
(313, 8, 'user.login', '::1', '', '2014-06-08 01:46:12'),
(314, 8, 'user.login', '::1', '', '2014-06-08 23:45:32'),
(315, 8, 'user.login', '::1', '', '2014-06-09 23:32:35'),
(316, 8, 'user.login', '::1', '', '2014-06-09 23:32:42'),
(317, 8, 'user.login', '::1', '', '2014-06-11 00:06:14'),
(318, 8, 'user.login', '::1', '', '2014-06-14 21:54:49'),
(319, 8, 'user.login', '::1', '', '2014-06-15 00:55:22'),
(320, 8, 'user.login', '::1', '', '2014-06-15 15:54:34'),
(321, 8, 'user.login', '::1', '', '2014-06-15 18:47:49'),
(322, 8, 'user.login', '::1', '', '2014-06-15 19:44:53'),
(323, 8, 'user.login', '::1', '', '2014-06-15 21:14:04'),
(324, 8, 'user.login', '::1', '', '2014-06-15 23:26:17'),
(325, 8, 'user.login', '::1', '', '2014-06-19 16:16:54'),
(326, 8, 'user.login', '::1', '', '2014-06-19 18:52:36'),
(327, 8, 'user.login', '::1', '', '2014-06-19 19:14:03'),
(328, 8, 'user.login', '::1', '', '2014-06-20 23:56:33'),
(329, 8, 'user.login', '::1', '', '2014-06-21 00:08:41'),
(330, 8, 'user.logout', '::1', '', '2014-06-21 00:43:44'),
(331, 8, 'user.login', '::1', '', '2014-06-21 00:57:00'),
(332, 8, 'user.login', '::1', '', '2014-06-21 01:19:16'),
(333, 8, 'user.login', '::1', '', '2014-06-21 23:54:59'),
(334, 8, 'user.login', '::1', '', '2014-06-22 17:00:35'),
(335, 8, 'user.login', '::1', '', '2014-06-24 11:24:21'),
(336, 8, 'user.login', '::1', '', '2014-06-24 18:02:55'),
(337, 8, 'user.login', '::1', '', '2014-06-24 21:18:35'),
(338, 8, 'user.login', '::1', '', '2014-06-28 13:39:29'),
(339, 8, 'user.login', '::1', '', '2014-06-30 00:01:22'),
(340, 8, 'user.login', '::1', '', '2014-07-01 23:08:19'),
(341, 8, 'user.login', '::1', '', '2014-07-02 22:01:56'),
(342, 8, 'user.login', '::1', '', '2014-07-03 22:02:18'),
(343, 8, 'user.login', '::1', '', '2014-07-04 22:16:28'),
(344, 8, 'user.login', '::1', '', '2014-07-06 20:58:10'),
(345, 8, 'user.login', '::1', '', '2014-07-06 22:02:42'),
(346, 8, 'user.login', '::1', '', '2014-07-12 13:04:47'),
(347, 8, 'user.login', '::1', '', '2014-07-12 14:53:43'),
(348, 8, 'user.login', '::1', '', '2014-07-12 18:53:07'),
(349, 8, 'user.login', '::1', '', '2014-07-12 20:36:36'),
(350, 8, 'user.login', '::1', '', '2014-07-12 22:43:12'),
(351, 8, 'user.login', '::1', '', '2014-07-13 10:24:29'),
(352, 8, 'user.login', '::1', '', '2014-07-13 19:56:56'),
(353, 8, 'user.login', '::1', '', '2014-07-19 00:37:36'),
(354, 8, 'user.logout', '::1', '', '2014-07-19 00:48:18'),
(355, 8, 'user.login', '::1', '', '2014-07-19 00:49:07'),
(356, 8, 'user.login', '::1', '', '2014-07-19 14:29:14'),
(357, 8, 'user.login', '::1', '', '2014-07-19 19:52:56'),
(358, 8, 'user.login', '::1', '', '2014-07-20 19:18:20'),
(359, 8, 'user.login', '::1', '', '2014-07-21 22:12:36'),
(360, 8, 'user.login', '::1', '', '2014-07-24 00:09:58'),
(361, 8, 'user.login', '127.0.0.1', '', '2014-07-24 08:15:57'),
(362, 8, 'user.login', '127.0.0.1', '', '2014-07-24 08:19:11'),
(363, 8, 'user.login', '127.0.0.1', '', '2014-07-24 08:23:32'),
(364, 8, 'user.login', '127.0.0.1', '', '2014-07-24 08:25:53'),
(365, 8, 'user.login', '127.0.0.1', '', '2014-07-24 22:35:52'),
(366, 8, 'user.login', '127.0.0.1', '', '2014-07-24 22:39:54'),
(367, 8, 'user.login', '127.0.0.1', '', '2014-07-24 22:44:24'),
(368, 8, 'user.login', '127.0.0.1', '', '2014-07-24 23:52:46'),
(369, 8, 'user.login', '127.0.0.1', '', '2014-07-26 20:01:44'),
(370, 8, 'user.login', '127.0.0.1', '', '2014-07-26 21:05:39'),
(371, 8, 'user.login', '127.0.0.1', '', '2014-07-27 15:39:18'),
(373, 8, 'user.login', '127.0.0.1', '', '2014-07-27 20:00:39'),
(379, 8, 'user.login', '127.0.0.1', '', '2014-07-27 22:15:18'),
(380, 8, 'user.login', '127.0.0.1', '', '2014-07-27 22:20:42'),
(381, 8, 'user.login', '127.0.0.1', '', '2014-07-28 00:04:47'),
(382, 8, 'user.login', '127.0.0.1', '', '2014-07-28 01:09:34'),
(383, 8, 'user.snippet.add', '127.0.0.1', '', '2014-07-28 01:10:00'),
(384, 8, 'user.snippet.add', '127.0.0.1', '', '2014-07-28 01:13:53'),
(385, 8, 'user.login', '127.0.0.1', '', '2014-07-28 08:30:47'),
(386, 8, 'user.login', '127.0.0.1', '', '2014-07-28 21:18:01'),
(387, 8, 'user.login', '127.0.0.1', '', '2014-07-28 22:40:25'),
(388, 8, 'user.login', '127.0.0.1', '', '2014-07-29 08:01:48'),
(389, 8, 'user.login', '127.0.0.1', '', '2014-07-30 23:39:32'),
(390, 8, 'user.login', '127.0.0.1', '', '2014-07-31 22:12:37'),
(391, 8, 'user.login', '127.0.0.1', '', '2014-08-02 21:36:56'),
(392, 8, 'user.login', '::1', '', '2014-08-03 20:16:02'),
(393, 8, 'user.login', '::1', '', '2014-08-03 23:12:12'),
(394, 8, 'user.snippet.add', '::1', '', '2014-08-03 23:41:17'),
(395, 8, 'user.login', '::1', '', '2014-08-04 21:57:35'),
(396, 8, 'user.login', '127.0.0.1', '', '2014-09-29 10:45:47'),
(397, 8, 'user.snippet.add', '127.0.0.1', '', '2014-09-29 10:51:51'),
(398, 8, 'user.snippet.add', '127.0.0.1', '', '2014-09-29 10:52:22'),
(399, 8, 'user.snippet.add', '127.0.0.1', '', '2014-09-29 10:54:05'),
(400, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-01 17:12:35'),
(401, 8, 'user.logout', '127.0.0.1', '', '2014-10-02 17:37:00'),
(402, 8, 'user.login', '127.0.0.1', '', '2014-10-02 17:37:02'),
(403, 8, 'user.logout', '127.0.0.1', '', '2014-10-02 17:40:46'),
(404, 8, 'user.login', '127.0.0.1', '', '2014-10-02 17:40:49'),
(405, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-02 17:59:49'),
(406, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-06 11:22:23'),
(407, 8, 'user.logout', '127.0.0.1', '', '2014-10-06 13:43:30'),
(408, 8, 'user.login', '127.0.0.1', '', '2014-10-06 13:43:38'),
(409, 8, 'user.logout', '127.0.0.1', '', '2014-10-07 13:16:15'),
(410, 8, 'user.login', '127.0.0.1', '', '2014-10-07 13:16:18'),
(411, 8, 'user.logout', '127.0.0.1', '', '2014-10-07 14:04:02'),
(412, 8, 'user.login', '127.0.0.1', '', '2014-10-07 14:04:03'),
(413, 8, 'user.logout', '127.0.0.1', '', '2014-10-07 14:04:20'),
(414, 8, 'user.login', '127.0.0.1', '', '2014-10-07 14:04:21'),
(415, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-07 16:13:52'),
(416, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-07 16:29:51'),
(417, 8, 'user.logout', '127.0.0.1', '', '2014-10-09 13:04:07'),
(418, 8, 'user.login', '127.0.0.1', '', '2014-10-09 13:04:52'),
(419, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-09 16:02:13'),
(420, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-09 16:04:22'),
(421, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-09 17:37:39'),
(422, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-09 17:39:13'),
(423, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:15:14'),
(424, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:20:57'),
(425, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:22:28'),
(426, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:29:39'),
(427, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:31:36'),
(428, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:34:45'),
(429, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-13 16:49:04'),
(430, 8, 'user.logout', '127.0.0.1', '', '2014-10-16 11:09:23'),
(431, 8, 'user.login', '127.0.0.1', '', '2014-10-16 11:09:27'),
(432, 8, 'user.logout', '127.0.0.1', '', '2014-10-16 11:41:30'),
(433, 8, 'user.login', '127.0.0.1', '', '2014-10-16 11:46:07'),
(434, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-16 12:44:21'),
(435, 8, 'user.snippet.add', '127.0.0.1', '', '2014-10-16 12:45:15'),
(436, 8, 'user.logout', '127.0.0.1', '', '2014-10-17 12:17:46'),
(437, 8, 'user.login', '127.0.0.1', '', '2014-10-17 12:29:37'),
(438, 8, 'user.logout', '127.0.0.1', '', '2014-10-17 12:29:43'),
(439, 8, 'user.login', '127.0.0.1', '', '2014-10-17 12:30:49'),
(440, 8, 'user.logout', '127.0.0.1', '', '2014-10-17 12:30:54'),
(441, 8, 'user.login', '127.0.0.1', '', '2014-10-17 12:36:29'),
(442, 8, 'user.logout', '127.0.0.1', '', '2014-10-17 12:36:33'),
(443, 8, 'user.login', '127.0.0.1', '', '2014-10-17 13:29:20'),
(444, 8, 'user.logout', '127.0.0.1', '', '2014-10-17 13:30:56'),
(445, 8, 'user.login', '127.0.0.1', '', '2014-10-20 10:06:17'),
(446, 8, 'user.snippet.add', '127.0.0.1', 'null', '2014-10-20 13:21:12'),
(447, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Create new Object From Variable in JavaScript""}', '2014-10-20 13:27:44'),
(448, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""strip html tags from a string in Javascript""}', '2014-10-20 15:42:43'),
(449, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""strip html tags from a string in Javascript""}', '2014-10-20 15:55:47'),
(450, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""javascript replace all instances in a string""}', '2014-10-20 15:56:24'),
(451, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""PHP replace words in a string""}', '2014-10-20 15:57:29'),
(452, 8, 'user.logout', '127.0.0.1', '', '2014-10-20 15:58:00'),
(453, 8, 'user.logout', '127.0.0.1', '', '2014-10-20 15:58:12'),
(454, 8, 'user.login', '127.0.0.1', '', '2014-10-20 15:58:21'),
(455, 8, 'user.logout', '127.0.0.1', '', '2014-10-20 15:58:28'),
(456, 8, 'user.login', '127.0.0.1', '', '2014-10-20 16:04:57'),
(457, 8, 'user.logout', '127.0.0.1', '', '2014-10-20 16:05:00'),
(458, 8, 'user.login', '127.0.0.1', '', '2014-10-20 16:06:58'),
(459, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Find words adjacent to a word given by its index in a string""}', '2014-10-20 16:08:25'),
(460, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Find words adjacent to a word given by its index in a string""}', '2014-10-20 16:09:37'),
(461, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Get unique field values""}', '2014-10-20 16:10:53'),
(462, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""get list of all values in a field MySQL""}', '2014-10-20 16:12:02'),
(463, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Get Enumerated Values for a MySQL Field""}', '2014-10-20 16:14:10'),
(464, 8, 'user.logout', '127.0.0.1', '', '2014-10-20 17:50:08'),
(465, 10, 'user.activate', '127.0.0.1', '', '2014-10-20 17:54:15'),
(466, 10, 'user.login', '127.0.0.1', '', '2014-10-20 17:54:26'),
(467, 10, 'user.logout', '127.0.0.1', '', '2014-10-21 16:01:49'),
(468, 8, 'user.login', '127.0.0.1', '', '2014-10-21 16:12:27'),
(469, 10, 'user.login', '127.0.0.1', '', '2014-10-22 15:31:37'),
(470, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:07:02'),
(471, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:07:02'),
(472, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:24'),
(473, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:26'),
(474, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:26'),
(475, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:43'),
(476, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:44'),
(477, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 16:29:44'),
(478, 8, 'user.login', '127.0.0.1', '', '2014-10-22 17:38:54'),
(479, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:39:10'),
(480, 8, 'user.rating.add', '127.0.0.1', '{"id_snippet":""71"","rating":""3.5""}', '2014-10-22 17:39:12'),
(481, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:39:24'),
(482, 8, 'user.logout', '127.0.0.1', '', '2014-10-22 17:39:54'),
(483, 10, 'user.login', '127.0.0.1', '', '2014-10-22 17:39:59'),
(484, 10, 'user.rating.add', '127.0.0.1', '{"id_snippet":""71"","rating":""3""}', '2014-10-22 17:40:08'),
(485, 10, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:41:48'),
(486, 8, 'user.comment.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:41:49'),
(487, 10, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:42:06'),
(488, 8, 'user.comment.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 17:42:06'),
(489, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:08:20'),
(490, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:08:22'),
(491, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:08:22'),
(492, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:09:18'),
(493, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:09:21'),
(494, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:09:21'),
(495, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:09:24'),
(496, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:10:07'),
(497, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:10:07'),
(498, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:11:06'),
(499, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:11:10'),
(500, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:11:10'),
(501, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:55'),
(502, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:57'),
(503, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:57'),
(504, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:58'),
(505, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:59'),
(506, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:12:59'),
(507, 10, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:13:08'),
(508, 10, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:13:16'),
(509, 8, 'user.fav.get', '127.0.0.1', '{"id_snippet":""71""}', '2014-10-22 18:13:16'),
(510, 10, 'user.logout', '127.0.0.1', '', '2014-10-23 12:35:39'),
(511, 8, 'user.login', '127.0.0.1', '', '2014-10-23 12:45:11'),
(512, 8, 'user.logout', '127.0.0.1', '', '2014-10-27 12:56:55'),
(513, 8, 'user.login', '127.0.0.1', '', '2014-10-27 12:56:57'),
(514, 8, 'user.logout', '127.0.0.1', '', '2014-11-03 10:36:46'),
(515, 8, 'user.login', '127.0.0.1', '', '2014-11-03 10:48:04'),
(516, 8, 'user.logout', '127.0.0.1', '', '2014-11-03 10:49:51'),
(517, 8, 'user.login', '127.0.0.1', '', '2014-11-03 10:49:58'),
(518, 8, 'user.logout', '127.0.0.1', '', '2014-11-03 11:34:46'),
(519, 8, 'user.login', '127.0.0.1', '', '2014-11-03 11:34:49'),
(520, 8, 'user.logout', '127.0.0.1', '', '2014-11-03 13:34:18'),
(521, 8, 'user.login', '127.0.0.1', '', '2014-11-03 13:34:40'),
(522, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-03 16:48:11'),
(523, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""\\u00c3\\u00b1a\\u00c3\\u00b1ito avi\\u00c3\\u00b3n""}', '2014-11-04 10:40:22'),
(524, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""\\u00c3\\u00b1a\\u00c3\\u00b1ito avi\\u00c3\\u00b3n""}', '2014-11-04 10:42:17'),
(525, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""&ntilde;a&ntilde;ito avi&oacute;n""}', '2014-11-04 10:44:50'),
(526, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""delete from Snippets where 1;""}', '2014-11-04 10:48:53'),
(527, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 10:49:09'),
(528, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""74""}', '2014-11-04 10:56:03'),
(529, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""74""}', '2014-11-04 10:56:09'),
(530, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""74""}', '2014-11-04 10:56:17'),
(531, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""74""}', '2014-11-04 10:56:22'),
(532, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:57:40'),
(533, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:57:46'),
(534, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:57:49'),
(535, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:57:54'),
(536, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:57:59'),
(537, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 10:58:03'),
(538, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:45:00'),
(539, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:46:08'),
(540, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:05'),
(541, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:23'),
(542, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:24'),
(543, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:25'),
(544, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:26'),
(545, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""75""}', '2014-11-04 11:47:27'),
(546, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""74""}', '2014-11-04 11:47:33'),
(547, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""sdfsfs""}', '2014-11-04 12:37:52'),
(548, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""70""}', '2014-11-04 14:07:15'),
(549, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""70""}', '2014-11-04 14:07:17'),
(550, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""70""}', '2014-11-04 14:07:29'),
(551, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-11-04 14:56:51'),
(552, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-11-04 14:57:21'),
(553, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-11-04 14:59:24'),
(554, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 18:06:00'),
(555, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""71""}', '2014-11-04 18:06:05'),
(556, 8, 'user.logout', '127.0.0.1', '', '2014-11-06 14:53:25'),
(557, 11, 'user.activate', '127.0.0.1', '', '2014-11-06 15:02:07'),
(558, 11, 'user.login', '127.0.0.1', '', '2014-11-06 15:02:31'),
(559, 11, 'user.logout', '127.0.0.1', '', '2014-11-06 15:02:35'),
(560, 11, 'user.login', '127.0.0.1', '', '2014-11-06 17:34:18'),
(561, 11, 'user.logout', '127.0.0.1', '', '2014-11-06 17:44:00'),
(562, 8, 'user.login', '127.0.0.1', '', '2014-11-06 17:44:25'),
(563, 8, 'user.logout', '127.0.0.1', '', '2014-11-06 17:45:25'),
(564, 11, 'user.login', '127.0.0.1', '', '2014-11-06 17:45:34'),
(565, 11, 'user.logout', '127.0.0.1', '', '2014-11-07 12:28:42'),
(566, 8, 'user.login', '127.0.0.1', '', '2014-11-07 12:28:56'),
(567, 8, 'user.logout', '127.0.0.1', '', '2014-11-07 12:29:43'),
(568, 8, 'user.login', '127.0.0.1', '', '2014-11-07 12:29:45'),
(569, 8, 'user.logout', '127.0.0.1', '', '2014-11-07 12:36:02'),
(570, 8, 'user.login', '127.0.0.1', '', '2014-11-07 12:51:34'),
(571, 8, 'user.logout', '127.0.0.1', '', '2014-11-07 12:56:32'),
(572, 8, 'user.login', '127.0.0.1', '', '2014-11-07 12:57:47'),
(573, 8, 'user.logout', '127.0.0.1', '', '2014-11-07 12:58:10'),
(574, 11, 'user.login', '127.0.0.1', '', '2014-11-07 13:00:17'),
(575, 11, 'user.logout', '127.0.0.1', '', '2014-11-07 13:00:27'),
(576, 8, 'user.login', '127.0.0.1', '', '2014-11-07 13:56:25'),
(577, 8, 'user.logout', '127.0.0.1', '', '2014-11-07 13:59:41'),
(578, 11, 'user.login', '127.0.0.1', '', '2014-11-07 14:00:00'),
(579, 11, 'user.login', '::1', '', '2014-11-08 16:01:09'),
(580, 11, 'user.login', '::1', '', '2014-11-08 20:21:49'),
(581, 11, 'user.login', '::1', '', '2014-11-08 20:42:32'),
(582, 11, 'user.logout', '::1', '', '2014-11-08 20:43:58'),
(583, 11, 'user.login', '::1', '', '2014-11-08 21:23:17'),
(584, 11, 'user.logout', '::1', '', '2014-11-08 22:03:07'),
(585, 8, 'user.login', '::1', '', '2014-11-08 22:03:11'),
(586, 8, 'user.logout', '::1', '', '2014-11-08 22:03:38'),
(587, 8, 'user.login', '::1', '', '2014-11-08 22:03:47'),
(588, 8, 'user.logout', '::1', '', '2014-11-08 22:03:52'),
(589, 11, 'user.login', '::1', '', '2014-11-08 22:03:56'),
(590, 11, 'user.login', '::1', '', '2014-11-08 22:40:13'),
(591, 11, 'user.logout', '::1', '', '2014-11-08 22:57:27'),
(592, 8, 'user.login', '::1', '', '2014-11-08 22:57:31'),
(593, 8, 'user.logout', '::1', '', '2014-11-08 23:10:38'),
(594, 11, 'user.login', '::1', '', '2014-11-08 23:10:42'),
(595, 11, 'user.logout', '::1', '', '2014-11-08 23:35:28'),
(596, 8, 'user.login', '::1', '', '2014-11-08 23:35:36'),
(597, 8, 'user.logout', '::1', '', '2014-11-08 23:38:41'),
(598, 11, 'user.login', '::1', '', '2014-11-08 23:38:46'),
(599, 11, 'user.login', '::1', '', '2014-11-09 10:40:59'),
(600, 11, 'user.login', '::1', '', '2014-11-09 14:11:22'),
(601, 11, 'user.login', '::1', '', '2014-11-09 14:49:58'),
(602, 11, 'user.login', '::1', '', '2014-11-09 15:57:55'),
(603, 11, 'user.login', '::1', '', '2014-11-09 18:28:32'),
(604, 11, 'user.login', '::1', '', '2014-11-09 20:09:26'),
(605, 11, 'user.logout', '::1', '', '2014-11-09 21:03:18'),
(606, 11, 'user.login', '::1', '', '2014-11-09 21:03:27'),
(607, 11, 'user.logout', '::1', '', '2014-11-09 21:07:34'),
(608, 11, 'user.login', '::1', '', '2014-11-09 21:07:39'),
(609, 11, 'user.login', '::1', '', '2014-11-09 22:04:32'),
(610, 11, 'user.login', '::1', '', '2014-11-10 11:50:44'),
(611, 11, 'user.logout', '127.0.0.1', '', '2014-11-11 14:22:01'),
(612, 8, 'user.login', '127.0.0.1', '', '2014-11-11 14:22:03'),
(613, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""57""}', '2014-11-12 14:27:54'),
(614, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""57""}', '2014-11-12 14:28:02'),
(615, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""57""}', '2014-11-12 14:28:46'),
(616, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""57""}', '2014-11-12 14:28:49'),
(617, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 16:48:02'),
(618, 11, 'user.login', '127.0.0.1', '', '2014-11-12 16:48:22'),
(619, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 16:48:49'),
(620, 8, 'user.login', '127.0.0.1', '', '2014-11-12 16:48:52'),
(621, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 16:50:21'),
(622, 11, 'user.login', '127.0.0.1', '', '2014-11-12 16:50:25'),
(623, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 16:51:00'),
(624, 11, 'user.login', '127.0.0.1', '', '2014-11-12 16:51:04'),
(625, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 16:51:08'),
(626, 8, 'user.login', '127.0.0.1', '', '2014-11-12 16:51:11'),
(627, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 16:51:17'),
(628, 11, 'user.login', '127.0.0.1', '', '2014-11-12 16:51:20'),
(629, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 16:58:01'),
(630, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:00:15'),
(631, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:01:32'),
(632, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:01:34'),
(633, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:01:38'),
(634, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:01:44'),
(635, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:01:50'),
(636, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:02:02'),
(637, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:02:06'),
(638, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:02:09'),
(639, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:02:13'),
(640, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:02:31'),
(641, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:02:34'),
(642, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:02:41'),
(643, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:03:32'),
(644, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:03:35'),
(645, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:04:52'),
(646, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:04:56'),
(647, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:05:00'),
(648, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:05:02'),
(649, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:05:05'),
(650, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:05:11'),
(651, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:05:57'),
(652, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:06:03'),
(653, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:06:55'),
(654, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:07:02'),
(655, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:07:29'),
(656, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:07:32'),
(657, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:07:35'),
(658, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:07:40'),
(659, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:07:48'),
(660, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:07:50'),
(661, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:07:53'),
(662, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:07:56'),
(663, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:08:00'),
(664, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:08:06'),
(665, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:08:32'),
(666, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:08:35'),
(667, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:08:42'),
(668, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:08:46'),
(669, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:09:30'),
(670, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:09:35'),
(671, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:11:06'),
(672, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:11:10'),
(673, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:11:21'),
(674, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:11:35'),
(675, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:11:53'),
(676, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:11:57'),
(677, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:12:11'),
(678, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:12:13'),
(679, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:12:18'),
(680, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:12:46'),
(681, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:12:52'),
(682, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:12:55'),
(683, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:13:05'),
(684, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:13:07'),
(685, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:13:26'),
(686, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:13:30'),
(687, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:13:58'),
(688, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:14:00'),
(689, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:16:31'),
(690, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:16:33'),
(691, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:16:36'),
(692, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:22:05'),
(693, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:22:08'),
(694, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:22:16'),
(695, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:22:30'),
(696, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:22:32'),
(697, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:22:41'),
(698, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:23:37'),
(699, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:23:42'),
(700, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:23:45'),
(701, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:25:38'),
(702, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:25:40'),
(703, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:25:46'),
(704, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:25:48'),
(705, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:29:37'),
(706, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:29:39'),
(707, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:36:03'),
(708, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:36:05'),
(709, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:36:32'),
(710, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:36:35'),
(711, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:36:37'),
(712, 11, 'user.login', '127.0.0.1', '', '2014-11-12 17:36:40'),
(713, 11, 'user.logout', '127.0.0.1', '', '2014-11-12 17:36:58'),
(714, 8, 'user.login', '127.0.0.1', '', '2014-11-12 17:37:01'),
(715, 8, 'user.logout', '127.0.0.1', '', '2014-11-12 17:43:35'),
(716, 10, 'user.login', '127.0.0.1', '', '2014-11-12 17:43:40'),
(717, 10, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Animated Tooltips With Very Little Coding""}', '2014-11-12 17:44:52'),
(718, 10, 'user.logout', '127.0.0.1', '', '2014-11-13 12:25:09'),
(719, 8, 'user.login', '127.0.0.1', '', '2014-11-13 12:27:27'),
(720, 8, 'user.logout', '127.0.0.1', '', '2014-11-13 12:27:36'),
(721, 12, 'user.login', '127.0.0.1', '', '2014-11-13 12:27:44'),
(722, 12, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""HTML5 Mobile Video with Flash, Silverlight, Java, Animated GIF and Download fallback""}', '2014-11-13 12:32:02'),
(723, 12, 'user.logout', '127.0.0.1', '', '2014-11-13 12:32:16'),
(724, 13, 'user.login', '127.0.0.1', '', '2014-11-13 12:32:22'),
(725, 13, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Save all images from RSS feed""}', '2014-11-13 12:33:24'),
(726, 13, 'user.logout', '127.0.0.1', '', '2014-11-13 12:37:19'),
(727, 14, 'user.login', '127.0.0.1', '', '2014-11-13 12:37:27'),
(728, 14, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""List all images from directory""}', '2014-11-13 12:38:13'),
(729, 14, 'user.fav.add', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:21:57'),
(730, 14, 'user.fav.del', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:21:58'),
(731, 14, 'user.fav.add', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:23:42'),
(732, 14, 'user.fav.del', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:23:43'),
(733, 14, 'user.fav.add', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:23:55'),
(734, 14, 'user.fav.del', '127.0.0.1', '{"id_snippet":""80""}', '2014-11-14 13:23:57'),
(735, 14, 'user.rating.add', '127.0.0.1', '{"id_snippet":""80"","rating":""3.5""}', '2014-11-14 13:24:00'),
(736, 14, 'user.logout', '127.0.0.1', '', '2014-11-21 12:58:49'),
(737, 8, 'user.login', '127.0.0.1', '', '2014-11-24 12:38:33'),
(738, 8, 'user.logout', '127.0.0.1', '', '2014-11-25 17:49:58'),
(739, 11, 'user.login', '127.0.0.1', '', '2014-11-25 17:50:02'),
(740, 11, 'user.logout', '127.0.0.1', '', '2014-11-25 17:50:39'),
(741, 8, 'user.login', '127.0.0.1', '', '2014-11-26 12:07:48'),
(742, 8, 'user.logout', '127.0.0.1', '', '2014-12-02 10:56:45'),
(743, 11, 'user.login', '127.0.0.1', '', '2014-12-02 10:57:18'),
(744, 11, 'user.logout', '127.0.0.1', '', '2014-12-02 10:57:23'),
(745, 8, 'user.login', '127.0.0.1', '', '2014-12-02 10:57:26'),
(746, 8, 'user.logout', '127.0.0.1', '', '2014-12-02 12:40:37'),
(747, 8, 'user.login', '127.0.0.1', '', '2014-12-02 12:40:40'),
(748, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:51:57'),
(749, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:51:58'),
(750, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:55:01'),
(751, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:55:02'),
(752, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:55:04'),
(753, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""38""}', '2014-12-02 12:55:07'),
(754, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""79""}', '2014-12-02 12:55:22'),
(755, 13, 'user.fav.get', '127.0.0.1', '{"id_snippet":""79""}', '2014-12-02 12:55:22'),
(756, 8, 'user.rating.add', '127.0.0.1', '{"id_snippet":""79"","rating":""4""}', '2014-12-02 12:55:23'),
(757, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""79""}', '2014-12-02 12:55:35'),
(758, 13, 'user.comment.get', '127.0.0.1', '{"id_snippet":""79""}', '2014-12-02 12:55:35'),
(759, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""Listing special forms""}', '2014-12-02 13:02:47'),
(760, 8, 'user.login', '::1', '', '2014-12-13 15:11:22'),
(761, 8, 'user.login', '192.168.1.135', '', '2014-12-14 23:37:35'),
(762, 8, 'user.login', '192.168.1.135', '', '2014-12-15 23:20:34'),
(763, 8, 'user.login', '192.168.1.135', '', '2014-12-17 00:09:06'),
(764, 8, 'user.comment.add', '192.168.1.135', '{"id_snippet":""1""}', '2014-12-17 00:14:31'),
(765, 10, 'user.comment.get', '192.168.1.135', '{"id_snippet":""1""}', '2014-12-17 00:14:31'),
(766, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 00:55:12'),
(768, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 00:55:30'),
(770, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 00:56:09'),
(772, 8, 'user.fav.del', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:00:14'),
(773, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:05:36'),
(775, 8, 'user.fav.del', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:07:37'),
(776, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:10:51'),
(778, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:11:45'),
(780, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:30:54'),
(781, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:31:48'),
(782, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:32:38'),
(783, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:34:58'),
(784, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:35:23'),
(786, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:36:16'),
(787, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:36:21'),
(789, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:38:42'),
(790, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:38:45'),
(792, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:41:04'),
(793, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:41:07'),
(795, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:43:19'),
(796, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:43:22'),
(798, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:44:25'),
(799, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:44:28'),
(801, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:45:37'),
(802, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:46:39'),
(803, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:50:12'),
(804, 8, 'user.fav.del', '192.168.1.135', '{"id_Links":""1""}', '2014-12-17 01:50:42'),
(805, 8, 'user.fav.add', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:50:45'),
(806, 10, 'user.fav.get', '192.168.1.135', '{"id_links":""1""}', '2014-12-17 01:50:45'),
(807, 8, 'user.login', '::1', '', '2014-12-18 20:07:18'),
(808, 8, 'user.login', '192.168.1.136', '', '2014-12-19 19:28:54'),
(809, 8, 'user.fav.add', '192.168.1.136', '{"id_snippet":""81""}', '2014-12-19 19:43:43'),
(810, 8, 'user.fav.del', '192.168.1.136', '{"id_snippet":""81""}', '2014-12-19 19:43:44'),
(811, 8, 'user.rating.add', '192.168.1.136', '{"id_snippet":""81"","rating":""4""}', '2014-12-19 19:43:46'),
(812, 8, 'user.login', '192.168.1.136', '', '2014-12-19 19:44:55'),
(813, 8, 'user.logout', '192.168.1.128', '', '2014-12-19 20:05:20'),
(814, 11, 'user.login', '192.168.1.128', '', '2014-12-21 01:40:34'),
(815, 11, 'user.logout', '192.168.1.128', '', '2014-12-21 01:40:47'),
(816, 8, 'user.login', '192.168.1.128', '', '2014-12-21 01:40:58'),
(817, 8, 'user.login', '192.168.1.128', '', '2014-12-21 01:42:01'),
(818, 8, 'user.login', '192.168.1.128', '', '2014-12-21 10:56:34'),
(819, 8, 'user.login', '192.168.1.133', '', '2014-12-22 00:50:00'),
(820, 8, 'user.comment.add', '192.168.1.133', '{"id_snippet":""1""}', '2014-12-22 01:19:21'),
(821, 10, 'user.comment.get', '192.168.1.133', '{"id_snippet":""1""}', '2014-12-22 01:19:21'),
(822, 8, 'user.login', '192.168.1.128', '', '2014-12-22 10:16:18'),
(823, 8, 'user.login', '192.168.1.132', '', '2014-12-24 18:26:17'),
(824, 8, 'user.login', '192.168.1.132', '', '2014-12-24 19:41:29'),
(825, 8, 'user.login', '192.168.1.132', '', '2014-12-25 11:38:28'),
(826, 8, 'user.login', '192.168.1.132', '', '2014-12-25 19:27:31'),
(827, 8, 'user.login', '192.168.1.133', '', '2014-12-25 23:44:56'),
(828, 8, 'user.login', '192.168.1.133', '', '2014-12-26 00:05:11'),
(829, 8, 'user.login', '192.168.1.133', '', '2014-12-26 00:15:50'),
(830, 8, 'user.login', '127.0.0.1', '', '2014-12-26 00:20:45'),
(831, 8, 'user.logout', '::1', '', '2015-01-03 23:05:27'),
(832, 8, 'user.login', '::1', '', '2015-01-03 23:05:29'),
(833, 8, 'user.rating.add', '::1', '{"id_links":""1"","rating":""3""}', '2015-01-03 23:40:50'),
(834, 8, 'user.rating.add', '::1', '{"id_links":""2"","rating":""4""}', '2015-01-03 23:44:09'),
(835, 8, 'user.rating.add', '::1', '{"id_links":""1"","rating":""5""}', '2015-01-03 23:44:45'),
(837, 8, 'user.link.add', '::1', '{"link_name":""dfgdfgd""}', '2015-01-05 01:41:20'),
(838, 8, 'user.link.add', '::1', '{"link_name":""Setup Ruby On Rails on Mac OS X 10.10 Yosemite""}', '2015-01-05 01:43:57'),
(839, 8, 'user.link.add', '::1', '{"link_name":""sdfsdf""}', '2015-01-05 02:31:43'),
(840, 8, 'user.logout', '::1', '', '2015-01-05 22:48:41'),
(841, 8, 'user.login', '::1', '', '2015-01-05 22:48:47'),
(842, 8, 'user.link.add', '::1', '{"link_name":""Como validar una URL""}', '2015-01-06 01:59:43'),
(843, 8, 'user.link.add', '::1', '{"link_name":""Radar Oreilly""}', '2015-01-06 17:47:44'),
(844, 8, 'user.link.add', '::1', '{"link_name":""LEXICALIST""}', '2015-01-06 17:48:16'),
(845, 8, 'user.logout', '::1', '', '2015-01-15 23:19:31'),
(846, 11, 'user.login', '::1', '', '2015-01-15 23:19:47'),
(847, 11, 'user.logout', '::1', '', '2015-01-15 23:21:02'),
(848, 8, 'user.login', '::1', '', '2015-01-15 23:21:20'),
(849, 11, 'user.login', '::1', '', '2015-01-18 18:51:00'),
(850, 8, 'user.login', '::1', '', '2015-01-22 23:54:08'),
(851, 8, 'user.rating.add', '::1', '{"id_links":""18"","rating":""2""}', '2015-01-22 23:54:53'),
(852, 8, 'user.fav.add', '::1', '{"id_links":""18""}', '2015-01-22 23:54:57'),
(853, 8, 'user.fav.add', '::1', '{"id_snippet":""81""}', '2015-01-22 23:55:59'),
(854, 8, 'user.logout', '::1', '', '2015-01-25 15:50:28'),
(855, 11, 'user.login', '::1', '', '2015-01-25 15:50:31'),
(856, 11, 'user.logout', '::1', '', '2015-01-25 18:15:14'),
(857, 8, 'user.login', '::1', '', '2015-01-25 18:15:17'),
(858, 8, 'user.logout', '::1', '', '2015-01-25 18:15:24'),
(859, 11, 'user.login', '::1', '', '2015-01-25 18:15:28'),
(860, 8, 'user.login', '::1', '', '2015-01-25 18:18:28'),
(861, 11, 'user.logout', '::1', '', '2015-01-25 18:24:47'),
(862, 11, 'user.login', '::1', '', '2015-01-25 18:25:33'),
(863, 8, 'user.snippet.add', '::1', '{"snippet_name":""rsdfgsdfg""}', '2015-01-28 00:38:29'),
(864, 8, 'user.snippet.add', '::1', '{"snippet_name":""fgsdfgsdgf""}', '2015-01-28 00:41:07'),
(865, 8, 'user.snippet.add', '::1', '{"snippet_name":""dfgsdfg""}', '2015-01-28 00:52:15'),
(866, 8, 'user.rating.add', '::1', '{"id_snippet":""84"","rating":""3.5""}', '2015-01-28 00:52:20'),
(867, 8, 'user.fav.add', '::1', '{"id_snippet":""84""}', '2015-01-28 00:52:21'),
(868, 8, 'user.comment.add', '::1', '{"id_snippet":""84""}', '2015-01-28 00:52:32'),
(869, 8, 'user.snippet.add', '::1', '{"snippet_name":""dfvdfgdfg""}', '2015-01-28 01:03:21'),
(870, 8, 'user.fav.add', '::1', '{"id_snippet":""85""}', '2015-01-28 01:03:26'),
(871, 11, 'user.logout', '::1', '', '2015-01-29 00:15:34'),
(872, 8, 'user.login', '::1', '', '2015-01-29 00:15:38'),
(873, 8, 'user.fav.del', '::1', '{"id_snippet":""85""}', '2015-01-29 00:43:42'),
(874, 8, 'user.fav.add', '::1', '{"id_snippet":""85""}', '2015-01-29 00:43:57'),
(875, 8, 'user.fav.del', '::1', '{"id_snippet":""85""}', '2015-01-29 00:44:25'),
(876, 8, 'user.fav.add', '::1', '{"id_snippet":""85""}', '2015-01-29 00:44:29'),
(877, 8, 'user.fav.del', '::1', '{"id_snippet":""85""}', '2015-01-29 00:44:50'),
(878, 8, 'user.fav.add', '::1', '{"id_snippet":""85""}', '2015-01-29 00:44:57'),
(879, 8, 'user.fav.del', '::1', '{"id_snippet":""85""}', '2015-01-29 00:44:59'),
(880, 8, 'user.fav.add', '::1', '{"id_snippet":""85""}', '2015-01-29 00:45:00'),
(881, 8, 'user.logout', '::1', '', '2015-01-29 00:45:53'),
(882, 11, 'user.login', '::1', '', '2015-01-29 00:45:56'),
(883, 8, 'user.login', '::1', '', '2015-01-29 00:46:19'),
(884, 8, 'user.rating.add', '::1', '{"id_snippet":""85"","rating":""4""}', '2015-01-29 00:46:29'),
(885, 8, 'user.comment.add', '::1', '{"id_snippet":""85""}', '2015-01-29 00:46:36'),
(886, 8, 'user.snippet.add', '::1', '{"snippet_name":""dfgdsfgsdfgsd""}', '2015-01-29 00:52:13'),
(887, 8, 'user.rating.add', '::1', '{"id_snippet":""86"","rating":""4.5""}', '2015-01-29 00:52:17'),
(888, 8, 'user.fav.add', '::1', '{"id_snippet":""86""}', '2015-01-29 00:52:19'),
(889, 8, 'user.comment.add', '::1', '{"id_snippet":""86""}', '2015-01-29 00:52:23'),
(890, 11, 'user.login', '::1', '', '2015-02-04 23:30:27'),
(891, 11, 'user.login', '::1', '', '2015-02-10 00:04:38'),
(892, 11, 'user.logout', '::1', '', '2015-02-10 00:27:41'),
(893, 8, 'user.login', '::1', '', '2015-02-10 00:27:45'),
(894, 8, 'user.snippet.add', '::1', '{"snippet_name":""sdgfgfdsgsdfgsdgf""}', '2015-02-10 00:29:46');
INSERT INTO `user_event` (`ID`, `ID_User`, `eventName`, `ipaddress`, `data`, `dateExecuted`) VALUES
(895, 8, 'user.snippet.add', '::1', '{"snippet_name":""adgsdfgsdfg""}', '2015-02-10 00:31:26'),
(896, 8, 'user.snippet.add', '::1', '{"snippet_name":""dsfgsdsdfg""}', '2015-02-10 00:32:33'),
(897, 8, 'user.snippet.add', '::1', '{"snippet_name":""dsfgsdsdfg""}', '2015-02-10 00:34:42'),
(898, 8, 'user.snippet.add', '::1', '{"snippet_name":""dsfgsdsdfg""}', '2015-02-10 00:35:39'),
(899, 8, 'user.logout', '::1', '', '2015-02-10 00:37:41'),
(900, 11, 'user.login', '::1', '', '2015-02-10 00:37:45'),
(901, 11, 'user.logout', '::1', '', '2015-02-10 00:38:00'),
(902, 8, 'user.login', '::1', '', '2015-02-10 00:38:03'),
(903, 8, 'user.snippet.add', '::1', '{"snippet_name":""sfsdfgsdfg""}', '2015-02-10 00:38:21'),
(904, 8, 'user.logout', '::1', '', '2015-02-10 00:38:24'),
(905, 11, 'user.login', '::1', '', '2015-02-10 00:38:28'),
(906, 11, 'user.logout', '::1', '', '2015-02-10 00:45:34'),
(907, 8, 'user.login', '::1', '', '2015-02-10 00:45:37'),
(908, 8, 'user.snippet.add', '::1', '{"snippet_name":""svbvzxcvzxcvzxcv""}', '2015-02-10 00:46:03'),
(909, 8, 'user.rating.add', '::1', '{"id_snippet":""88"","rating":""4""}', '2015-02-10 00:46:07'),
(910, 8, 'user.fav.add', '::1', '{"id_snippet":""88""}', '2015-02-10 00:46:09'),
(911, 8, 'user.fav.del', '::1', '{"id_snippet":""88""}', '2015-02-10 00:46:19'),
(912, 8, 'user.fav.add', '::1', '{"id_snippet":""88""}', '2015-02-10 00:46:23'),
(913, 8, 'user.comment.add', '::1', '{"id_snippet":""88""}', '2015-02-10 00:46:36'),
(914, 8, 'user.comment.add', '::1', '{"id_snippet":""88""}', '2015-02-10 00:48:33'),
(915, 8, 'user.logout', '::1', '', '2015-02-10 00:50:39'),
(916, 11, 'user.login', '::1', '', '2015-02-10 00:50:43'),
(917, 11, 'user.logout', '::1', '', '2015-02-10 00:50:52'),
(918, 8, 'user.login', '::1', '', '2015-02-10 00:50:55'),
(919, 8, 'user.snippet.add', '::1', '{"snippet_name":""dfafasdfasdfasdfasf""}', '2015-02-10 00:51:11'),
(920, 8, 'user.fav.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:17'),
(921, 8, 'user.rating.add', '::1', '{"id_snippet":""89"","rating":""4""}', '2015-02-10 00:51:19'),
(922, 8, 'user.comment.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:31'),
(923, 8, 'user.fav.del', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:35'),
(924, 8, 'user.fav.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:35'),
(925, 8, 'user.fav.del', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:36'),
(926, 8, 'user.fav.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:51:36'),
(927, 8, 'user.logout', '::1', '', '2015-02-10 00:52:03'),
(928, 10, 'user.login', '::1', '', '2015-02-10 00:52:28'),
(929, 10, 'user.rating.add', '::1', '{"id_snippet":""89"","rating":""5""}', '2015-02-10 00:55:40'),
(930, 10, 'user.fav.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:56:03'),
(931, 8, 'user.fav.get', '::1', '{"id_snippet":""89""}', '2015-02-10 00:56:03'),
(932, 10, 'user.comment.add', '::1', '{"id_snippet":""89""}', '2015-02-10 00:56:10'),
(933, 8, 'user.comment.get', '::1', '{"id_snippet":""89""}', '2015-02-10 00:56:10'),
(934, 10, 'user.logout', '::1', '', '2015-02-12 01:05:45'),
(935, 11, 'user.login', '::1', '', '2015-02-12 01:05:49'),
(936, 11, 'user.logout', '::1', '', '2015-02-14 20:00:28'),
(937, 8, 'user.login', '::1', '', '2015-02-14 20:00:32'),
(938, 8, 'user.snippet.add', '::1', '{"snippet_name":""23123123""}', '2015-02-14 20:00:45'),
(939, 8, 'user.rating.add', '::1', '{"id_snippet":""90"","rating":""4""}', '2015-02-14 20:05:07'),
(940, 8, 'user.fav.add', '::1', '{"id_snippet":""90""}', '2015-02-14 20:05:08'),
(941, 8, 'user.comment.add', '::1', '{"id_snippet":""90""}', '2015-02-14 20:05:12'),
(942, 8, 'user.logout', '::1', '', '2015-02-14 21:01:47'),
(943, 11, 'user.login', '::1', '', '2015-02-14 21:01:51'),
(944, 11, 'user.logout', '::1', '', '2015-02-15 13:47:39'),
(945, 10, 'user.login', '::1', '', '2015-02-15 13:47:42'),
(946, 10, 'user.fav.add', '::1', '{"id_snippet":""90""}', '2015-02-15 13:47:49'),
(947, 8, 'user.fav.get', '::1', '{"id_snippet":""90""}', '2015-02-15 13:47:49'),
(948, 10, 'user.rating.add', '::1', '{"id_snippet":""90"","rating":""4""}', '2015-02-15 13:47:50'),
(949, 10, 'user.comment.add', '::1', '{"id_snippet":""90""}', '2015-02-15 13:47:56'),
(950, 8, 'user.comment.get', '::1', '{"id_snippet":""90""}', '2015-02-15 13:47:56'),
(951, 10, 'user.logout', '::1', '', '2015-02-15 13:48:00'),
(952, 11, 'user.login', '::1', '', '2015-02-15 13:48:03'),
(953, 11, 'user.logout', '::1', '', '2015-02-15 23:04:40'),
(954, 8, 'user.login', '::1', '', '2015-02-15 23:04:44'),
(955, 8, 'user.logout', '::1', '', '2015-02-15 23:21:19'),
(956, 11, 'user.login', '::1', '', '2015-02-15 23:21:22'),
(957, 11, 'user.logout', '::1', '', '2015-02-19 20:45:36'),
(958, 8, 'user.login', '::1', '', '2015-02-19 20:45:39'),
(959, 8, 'user.login', '::1', '', '2015-02-25 11:09:40'),
(960, 8, 'user.logout', '::1', '', '2015-02-25 11:21:52'),
(961, 11, 'user.login', '::1', '', '2015-02-25 11:21:56'),
(962, 11, 'user.logout', '::1', '', '2015-03-01 21:05:57'),
(963, 8, 'user.login', '::1', '', '2015-03-01 21:06:00'),
(964, 8, 'user.fav.add', '::1', '{"id_snippet":""41""}', '2015-03-01 21:06:13'),
(965, 8, 'user.fav.del', '::1', '{"id_snippet":""41""}', '2015-03-01 21:06:16'),
(966, 8, 'user.comment.add', '::1', '{"id_snippet":""41""}', '2015-03-01 21:06:23'),
(967, 8, 'user.fav.add', '::1', '{"id_snippet":""41""}', '2015-03-01 21:06:42'),
(968, 8, 'user.snippet.add', '::1', '{"snippet_name":""asfasdfasdf""}', '2015-03-01 21:07:17'),
(969, 8, 'user.rating.add', '::1', '{"id_snippet":""91"","rating":""4.5""}', '2015-03-01 21:07:21'),
(970, 8, 'user.fav.add', '::1', '{"id_snippet":""91""}', '2015-03-01 21:07:22'),
(971, 8, 'user.comment.add', '::1', '{"id_snippet":""91""}', '2015-03-01 21:07:52'),
(972, 8, 'user.fav.del', '::1', '{"id_Links":""18""}', '2015-03-01 21:08:19'),
(973, 8, 'user.fav.add', '::1', '{"id_links":""18""}', '2015-03-01 21:08:20'),
(974, 8, 'user.logout', '::1', '', '2015-03-01 21:13:22'),
(975, 11, 'user.login', '::1', '', '2015-03-01 21:13:26'),
(976, 8, 'user.login', '::1', '', '2015-03-01 23:09:57'),
(977, 8, 'user.logout', '::1', '', '2015-03-01 23:10:56'),
(978, 11, 'user.login', '::1', '', '2015-03-01 23:11:23'),
(979, 11, 'user.logout', '::1', '', '2015-03-01 23:11:24'),
(980, 11, 'user.login', '::1', '', '2015-03-01 23:11:52'),
(981, 11, 'user.logout', '::1', '', '2015-03-01 23:13:09'),
(982, 11, 'user.login', '::1', '', '2015-03-01 23:13:13'),
(983, 11, 'user.logout', '::1', '', '2015-03-01 23:13:19'),
(984, 8, 'user.login', '::1', '', '2015-03-01 23:13:22'),
(985, 8, 'user.logout', '::1', '', '2015-03-01 23:17:02'),
(986, 8, 'user.login', '::1', '', '2015-03-01 23:17:08'),
(987, 11, 'user.login', '127.0.0.1', '', '2015-03-02 11:33:57'),
(988, 11, 'user.logout', '127.0.0.1', '', '2015-03-03 15:08:58'),
(989, 8, 'user.login', '127.0.0.1', '', '2015-03-03 15:09:02'),
(990, 8, 'user.logout', '127.0.0.1', '', '2015-03-03 15:09:13'),
(991, 11, 'user.login', '127.0.0.1', '', '2015-03-03 15:09:20'),
(992, 11, 'user.page.add', '127.0.0.1', '{"page_title":""342342""}', '2015-03-03 17:24:51'),
(993, 11, 'user.page.add', '127.0.0.1', '{"page_title":""ssdfdfs""}', '2015-03-03 17:26:40'),
(994, 11, 'user.page.add', '127.0.0.1', '{"page_title":""fsfdsdf""}', '2015-03-03 17:27:35'),
(995, 11, 'user.page.add', '127.0.0.1', '{"page_title":""http:\\/\\/bootsnipp.com\\/snippets\\/featured\\/bootstrap-30-treeview""}', '2015-03-03 17:35:28'),
(996, 11, 'user.page.add', '127.0.0.1', '{"page_title":""fdsdf""}', '2015-03-12 17:05:25'),
(997, 11, 'user.page.add', '127.0.0.1', '{"page_title":"" Construye una arbol desplegable con PHP, CSS y jQuery""}', '2015-03-12 17:07:30'),
(998, 11, 'user.login', '127.0.0.1', '', '2015-03-17 10:38:46'),
(999, 11, 'user.page.add', '127.0.0.1', '{"page_title":""http:\\/\\/jsfiddle.net\\/gabrieleromanato\\/mxq9R\\/""}', '2015-03-17 17:00:22'),
(1000, 11, 'user.login', '127.0.0.1', '', '2015-03-18 13:33:12'),
(1001, 11, 'user.login', '127.0.0.1', '', '2015-03-23 12:13:13'),
(1002, 11, 'user.logout', '127.0.0.1', '', '2015-03-23 15:20:54'),
(1003, 8, 'user.login', '127.0.0.1', '', '2015-03-23 15:20:58'),
(1004, 8, 'user.logout', '127.0.0.1', '', '2015-03-23 15:21:19'),
(1005, 11, 'user.login', '127.0.0.1', '', '2015-03-23 15:21:22'),
(1006, 11, 'user.logout', '127.0.0.1', '', '2015-03-23 15:22:16'),
(1007, 8, 'user.login', '127.0.0.1', '', '2015-03-23 15:22:19'),
(1008, 8, 'user.logout', '127.0.0.1', '', '2015-03-23 15:24:53'),
(1009, 11, 'user.login', '127.0.0.1', '', '2015-03-23 15:24:56'),
(1010, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 12:29:25'),
(1011, 8, 'user.login', '127.0.0.1', '', '2015-03-24 12:29:31'),
(1012, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 12:44:15'),
(1013, 8, 'user.login', '127.0.0.1', '', '2015-03-24 12:44:51'),
(1014, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 13:50:42'),
(1015, 8, 'user.login', '127.0.0.1', '', '2015-03-24 13:50:44'),
(1016, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 13:51:08'),
(1017, 8, 'user.login', '127.0.0.1', '', '2015-03-24 13:51:11'),
(1018, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 13:52:26'),
(1019, 8, 'user.login', '127.0.0.1', '', '2015-03-24 13:52:30'),
(1020, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 13:57:49'),
(1021, 8, 'user.login', '127.0.0.1', '', '2015-03-24 13:57:52'),
(1022, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 13:58:05'),
(1023, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 13:59:09'),
(1024, 11, 'user.login', '127.0.0.1', '', '2015-03-24 13:59:13'),
(1025, 11, 'user.login', '127.0.0.1', '', '2015-03-24 14:00:08'),
(1026, 11, 'user.login', '127.0.0.1', '', '2015-03-24 14:00:25'),
(1027, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 15:15:57'),
(1028, 11, 'user.login', '127.0.0.1', '', '2015-03-24 16:42:13'),
(1029, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 16:42:31'),
(1030, 11, 'user.login', '127.0.0.1', '', '2015-03-24 16:42:34'),
(1031, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 16:44:39'),
(1032, 11, 'user.login', '127.0.0.1', '', '2015-03-24 16:44:44'),
(1033, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 16:47:44'),
(1034, 11, 'user.login', '127.0.0.1', '', '2015-03-24 16:47:48'),
(1035, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 16:48:48'),
(1036, 11, 'user.login', '127.0.0.1', '', '2015-03-24 16:48:52'),
(1037, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:07:18'),
(1038, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:07:21'),
(1039, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:12:59'),
(1040, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:13:02'),
(1041, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:28:25'),
(1042, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:29:41'),
(1043, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:29:43'),
(1044, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:30:24'),
(1045, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:30:27'),
(1046, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:30:31'),
(1047, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:31:19'),
(1048, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:31:25'),
(1049, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:31:29'),
(1050, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:31:32'),
(1051, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:35:39'),
(1052, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:36:36'),
(1053, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:36:39'),
(1054, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:36:43'),
(1055, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:38:02'),
(1056, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:40:47'),
(1057, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:40:50'),
(1058, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:40:55'),
(1059, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:40:58'),
(1060, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:41:00'),
(1061, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:41:03'),
(1062, 11, 'user.logout', '127.0.0.1', '', '2015-03-24 17:41:06'),
(1063, 8, 'user.login', '127.0.0.1', '', '2015-03-24 17:43:49'),
(1064, 8, 'user.logout', '127.0.0.1', '', '2015-03-24 17:43:51'),
(1065, 11, 'user.login', '127.0.0.1', '', '2015-03-24 17:43:54'),
(1066, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:03:45'),
(1067, 11, 'user.login', '127.0.0.1', '', '2015-03-25 10:03:47'),
(1068, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:03:49'),
(1069, 8, 'user.login', '127.0.0.1', '', '2015-03-25 10:03:51'),
(1070, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 10:03:55'),
(1071, 8, 'user.login', '127.0.0.1', '', '2015-03-25 10:05:15'),
(1072, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 10:05:18'),
(1073, 11, 'user.login', '127.0.0.1', '', '2015-03-25 10:05:20'),
(1074, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:05:22'),
(1075, 11, 'user.login', '127.0.0.1', '', '2015-03-25 10:09:42'),
(1076, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:09:44'),
(1077, 8, 'user.login', '127.0.0.1', '', '2015-03-25 10:09:47'),
(1078, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 10:10:05'),
(1079, 8, 'user.login', '127.0.0.1', '', '2015-03-25 10:37:48'),
(1080, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 10:37:55'),
(1081, 11, 'user.login', '127.0.0.1', '', '2015-03-25 10:37:58'),
(1082, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:38:01'),
(1083, 11, 'user.login', '127.0.0.1', '', '2015-03-25 10:42:06'),
(1084, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 10:42:20'),
(1085, 8, 'user.login', '127.0.0.1', '', '2015-03-25 10:42:58'),
(1086, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 10:43:02'),
(1087, 8, 'user.login', '127.0.0.1', '', '2015-03-25 11:45:39'),
(1088, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 12:30:10'),
(1089, 8, 'user.login', '127.0.0.1', '', '2015-03-25 12:38:03'),
(1090, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 12:38:29'),
(1091, 11, 'user.login', '127.0.0.1', '', '2015-03-25 12:38:32'),
(1092, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 12:38:44'),
(1093, 8, 'user.login', '127.0.0.1', '', '2015-03-25 13:09:49'),
(1094, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 13:10:02'),
(1095, 8, 'user.login', '127.0.0.1', '', '2015-03-25 13:10:04'),
(1096, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 13:10:09'),
(1097, 8, 'user.login', '127.0.0.1', '', '2015-03-25 13:11:11'),
(1098, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 13:11:15'),
(1099, 8, 'user.login', '127.0.0.1', '', '2015-03-25 13:17:59'),
(1100, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 13:18:02'),
(1101, 8, 'user.login', '127.0.0.1', '', '2015-03-25 13:33:24'),
(1102, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 13:33:27'),
(1103, 11, 'user.login', '127.0.0.1', '', '2015-03-25 13:33:29'),
(1104, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 13:33:32'),
(1105, 11, 'user.login', '127.0.0.1', '', '2015-03-25 15:58:13'),
(1106, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 15:58:17'),
(1107, 8, 'user.login', '127.0.0.1', '', '2015-03-25 15:58:21'),
(1108, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 15:58:25'),
(1109, 8, 'user.login', '127.0.0.1', '', '2015-03-25 15:58:29'),
(1110, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 15:59:44'),
(1111, 11, 'user.login', '127.0.0.1', '', '2015-03-25 15:59:47'),
(1112, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 16:05:08'),
(1113, 8, 'user.login', '127.0.0.1', '', '2015-03-25 16:05:11'),
(1114, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 16:16:06'),
(1115, 11, 'user.login', '127.0.0.1', '', '2015-03-25 16:16:08'),
(1116, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 16:16:16'),
(1117, 8, 'user.login', '127.0.0.1', '', '2015-03-25 16:20:40'),
(1118, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 16:21:25'),
(1119, 11, 'user.login', '127.0.0.1', '', '2015-03-25 16:21:27'),
(1120, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 16:21:37'),
(1121, 8, 'user.login', '127.0.0.1', '', '2015-03-25 16:37:17'),
(1122, 8, 'user.logout', '127.0.0.1', '', '2015-03-25 16:42:31'),
(1123, 11, 'user.login', '127.0.0.1', '', '2015-03-25 16:42:34'),
(1124, 11, 'user.logout', '127.0.0.1', '', '2015-03-25 16:49:04'),
(1125, 8, 'user.login', '127.0.0.1', '', '2015-03-26 12:42:06'),
(1126, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 12:44:34'),
(1127, 8, 'user.login', '127.0.0.1', '', '2015-03-26 12:44:36'),
(1128, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 13:05:22'),
(1129, 8, 'user.login', '127.0.0.1', '', '2015-03-26 13:37:33'),
(1130, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 16:31:46'),
(1131, 8, 'user.login', '127.0.0.1', '', '2015-03-26 16:32:34'),
(1132, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 16:33:37'),
(1133, 8, 'user.login', '127.0.0.1', '', '2015-03-26 16:34:04'),
(1134, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 16:34:08'),
(1135, 8, 'user.password.forgot', '127.0.0.1', '{"email":""oscarlgarcia@gmail.com""}', '2015-03-26 16:45:19'),
(1136, 8, 'user.password.reset', '127.0.0.1', '', '2015-03-26 16:46:00'),
(1137, 8, 'user.password.forgot', '127.0.0.1', '{"email":""oscarlgarcia@gmail.com""}', '2015-03-26 16:46:11'),
(1138, 8, 'user.password.reset', '127.0.0.1', '', '2015-03-26 16:46:28'),
(1139, 8, 'user.password.forgot', '127.0.0.1', '{"email":""oscarlgarcia@gmail.com""}', '2015-03-26 16:53:49'),
(1140, 8, 'user.password.reset', '127.0.0.1', '', '2015-03-26 16:55:09'),
(1141, 8, 'user.password.forgot', '127.0.0.1', '{"email":""oscarlgarcia@gmail.com""}', '2015-03-26 16:55:17'),
(1142, 8, 'user.password.reset', '127.0.0.1', '', '2015-03-26 16:57:58'),
(1143, 8, 'user.login', '127.0.0.1', '', '2015-03-26 16:58:10'),
(1144, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 16:58:13'),
(1145, 8, 'user.login', '127.0.0.1', '', '2015-03-26 16:58:34'),
(1146, 8, 'user.logout', '127.0.0.1', '', '2015-03-26 16:58:36'),
(1147, 8, 'user.login', '127.0.0.1', '', '2015-03-26 17:24:59'),
(1148, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-03-27 13:34:53'),
(1149, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-03-27 13:46:39'),
(1150, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-03-27 13:46:40'),
(1151, 8, 'user.link.add', '127.0.0.1', '{"link_name":""""}', '2015-03-27 13:48:54'),
(1152, 8, 'user.fav.del', '127.0.0.1', '{"id_Links":""18""}', '2015-03-27 14:06:35'),
(1153, 8, 'user.fav.add', '127.0.0.1', '{"id_links":""18""}', '2015-03-27 14:06:37'),
(1154, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""18""}', '2015-03-27 14:06:43'),
(1155, 8, 'user.rating.add', '127.0.0.1', '{"id_links":""19"","rating":""5""}', '2015-03-27 14:06:48'),
(1156, 8, 'user.fav.add', '127.0.0.1', '{"id_links":""19""}', '2015-03-27 14:06:49'),
(1157, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""19""}', '2015-03-27 14:06:52'),
(1158, 8, 'user.logout', '127.0.0.1', '', '2015-03-30 11:52:59'),
(1159, 11, 'user.login', '127.0.0.1', '', '2015-03-30 12:00:21'),
(1160, 11, 'user.logout', '127.0.0.1', '', '2015-03-30 12:05:00'),
(1161, 11, 'user.login', '127.0.0.1', '', '2015-03-30 13:03:29'),
(1162, 11, 'user.logout', '127.0.0.1', '', '2015-03-30 16:51:13'),
(1163, 8, 'user.login', '127.0.0.1', '', '2015-03-30 16:51:16'),
(1164, 8, 'user.login', '127.0.0.1', '', '2015-03-30 17:37:52'),
(1165, 8, 'user.logout', '127.0.0.1', '', '2015-03-30 17:38:13'),
(1166, 11, 'user.login', '127.0.0.1', '', '2015-03-31 12:21:10'),
(1167, 11, 'user.login', '127.0.0.1', '', '2015-03-31 13:55:18'),
(1168, 11, 'user.logout', '127.0.0.1', '', '2015-03-31 16:59:34'),
(1169, 11, 'user.login', '127.0.0.1', '', '2015-04-06 12:16:20'),
(1170, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Exporta desde tu base de datos a tu seeds.rb""}', '2015-04-08 12:57:41'),
(1171, 11, 'user.logout', '127.0.0.1', '', '2015-04-16 19:20:37'),
(1172, 8, 'user.login', '127.0.0.1', '', '2015-04-17 11:03:38'),
(1173, 8, 'user.logout', '127.0.0.1', '', '2015-04-20 12:31:06'),
(1174, 8, 'user.login', '127.0.0.1', '', '2015-04-20 12:31:12'),
(1175, 8, 'user.logout', '127.0.0.1', '', '2015-04-20 15:55:03'),
(1176, 11, 'user.login', '127.0.0.1', '', '2015-04-20 15:55:06'),
(1177, 11, 'user.page.add', '127.0.0.1', '{"page_title":""dfgvasdgf""}', '2015-04-20 15:55:42'),
(1178, 11, 'user.logout', '127.0.0.1', '', '2015-04-20 15:56:08'),
(1179, 8, 'user.login', '127.0.0.1', '', '2015-04-23 16:17:56'),
(1180, 8, 'user.logout', '127.0.0.1', '', '2015-04-27 13:17:32'),
(1181, 8, 'user.login', '127.0.0.1', '', '2015-04-27 13:17:38'),
(1182, 8, 'user.logout', '127.0.0.1', '', '2015-05-12 13:53:48'),
(1183, 11, 'user.login', '127.0.0.1', '', '2015-05-12 14:00:32'),
(1184, 11, 'user.logout', '127.0.0.1', '', '2015-05-12 14:03:28'),
(1185, 8, 'user.login', '127.0.0.1', '', '2015-05-12 14:03:32'),
(1186, 8, 'user.logout', '127.0.0.1', '', '2015-05-12 14:05:03'),
(1187, 8, 'user.login', '127.0.0.1', '', '2015-05-13 17:01:47'),
(1188, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""54""}', '2015-05-13 17:06:47'),
(1189, 8, 'user.rating.add', '127.0.0.1', '{"id_snippet":""54"","rating":""2.5""}', '2015-05-13 17:06:49'),
(1190, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""80""}', '2015-05-13 17:07:43'),
(1191, 14, 'user.fav.get', '127.0.0.1', '{"id_snippet":""80""}', '2015-05-13 17:07:43'),
(1192, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""80""}', '2015-05-13 17:07:57'),
(1193, 14, 'user.comment.get', '127.0.0.1', '{"id_snippet":""80""}', '2015-05-13 17:07:57'),
(1194, 8, 'user.logout', '127.0.0.1', '', '2015-05-22 13:02:28'),
(1195, 11, 'user.login', '127.0.0.1', '', '2015-05-22 13:02:32'),
(1196, 11, 'user.page.add', '127.0.0.1', '{"page_title":""rrrrrrr""}', '2015-05-22 13:10:11'),
(1197, 11, 'user.logout', '127.0.0.1', '', '2015-05-22 13:14:23'),
(1198, 8, 'user.login', '127.0.0.1', '', '2015-05-22 13:14:25'),
(1199, 8, 'user.logout', '127.0.0.1', '', '2015-05-22 13:38:57'),
(1200, 11, 'user.login', '127.0.0.1', '', '2015-05-22 13:39:00'),
(1201, 11, 'user.page.add', '127.0.0.1', '{"page_title":""sdfasdf""}', '2015-05-22 13:39:13'),
(1202, 11, 'user.logout', '127.0.0.1', '', '2015-05-22 13:39:14'),
(1203, 8, 'user.login', '127.0.0.1', '', '2015-05-22 13:39:16'),
(1204, 8, 'user.login', '127.0.0.1', '', '2015-05-22 13:41:31'),
(1205, 8, 'user.login', '127.0.0.1', '', '2015-05-22 13:42:44'),
(1206, 8, 'user.logout', '127.0.0.1', '', '2015-05-22 14:12:31'),
(1207, 11, 'user.login', '127.0.0.1', '', '2015-05-22 14:12:35'),
(1208, 11, 'user.page.add', '127.0.0.1', '{"page_title":""asgsdfgsd""}', '2015-05-22 14:12:52'),
(1209, 11, 'user.page.add', '127.0.0.1', '{"page_title":""sdfgsdfgsd""}', '2015-05-22 14:13:39'),
(1210, 8, 'user.logout', '127.0.0.1', '', '2015-05-26 16:37:08'),
(1211, 11, 'user.login', '127.0.0.1', '', '2015-05-26 16:37:13'),
(1212, 11, 'user.login', '127.0.0.1', '', '2015-05-26 17:12:48'),
(1213, 11, 'user.page.add', '127.0.0.1', '{"page_title":""sdfsdf""}', '2015-05-28 11:31:30'),
(1214, 11, 'user.page.add', '127.0.0.1', '{"page_title":""ssddfsdfsdf""}', '2015-05-28 11:40:47'),
(1215, 11, 'user.logout', '127.0.0.1', '', '2015-05-29 11:13:38'),
(1216, 8, 'user.login', '127.0.0.1', '', '2015-05-29 11:13:40'),
(1217, 8, 'user.logout', '127.0.0.1', '', '2015-06-01 13:52:02'),
(1218, 11, 'user.login', '127.0.0.1', '', '2015-06-01 13:52:06'),
(1219, 11, 'user.page.add', '127.0.0.1', '{"page_title":""angular 1""}', '2015-06-01 13:52:33'),
(1220, 11, 'user.page.add', '127.0.0.1', '{"page_title":""angular 3""}', '2015-06-01 13:52:49'),
(1221, 11, 'user.logout', '127.0.0.1', '', '2015-06-01 13:52:52'),
(1222, 8, 'user.login', '127.0.0.1', '', '2015-06-01 13:52:57'),
(1223, 8, 'user.logout', '127.0.0.1', '', '2015-06-05 13:23:28'),
(1224, 11, 'user.login', '127.0.0.1', '', '2015-06-05 13:23:31'),
(1225, 11, 'user.logout', '127.0.0.1', '', '2015-06-05 13:24:07'),
(1226, 8, 'user.login', '127.0.0.1', '', '2015-06-05 13:24:09'),
(1227, 8, 'user.logout', '127.0.0.1', '', '2015-06-05 13:46:45'),
(1228, 11, 'user.login', '127.0.0.1', '', '2015-06-05 13:46:48'),
(1229, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Clojure Tutorial for the Non-Lisp Programmer""}', '2015-06-05 13:48:10'),
(1230, 11, 'user.logout', '127.0.0.1', '', '2015-06-05 13:48:13'),
(1231, 8, 'user.login', '127.0.0.1', '', '2015-06-05 13:48:16'),
(1232, 11, 'user.login', '127.0.0.1', '', '2015-06-05 13:49:32'),
(1233, 11, 'user.page.add', '127.0.0.1', '{"page_title":""trterterte""}', '2015-06-05 13:50:00'),
(1234, 11, 'user.login', '127.0.0.1', '', '2015-06-08 13:33:50'),
(1235, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-08 15:38:58'),
(1236, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-08 15:38:59'),
(1237, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-08 15:39:10'),
(1238, 8, 'user.fav.del', '127.0.0.1', '{"id_Links":""18""}', '2015-06-08 15:40:18'),
(1239, 8, 'user.fav.add', '127.0.0.1', '{"id_links":""18""}', '2015-06-08 15:40:20'),
(1240, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""18""}', '2015-06-08 15:40:27'),
(1241, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Configuraci&oacute;n en tiempo de ejecuci&oacute;n""}', '2015-06-08 17:00:20'),
(1242, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Configuraci&oacute;n en tiempo de ejecuci&oacute;n II Parte""}', '2015-06-08 17:01:13'),
(1243, 11, 'user.login', '127.0.0.1', '', '2015-06-09 14:09:22'),
(1244, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Captura todas tus peticiones err&oacute;neas (404) con Rails""}', '2015-06-09 14:13:54'),
(1245, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Utilizando variables en sentencias en MySQL""}', '2015-06-09 16:54:43'),
(1246, 8, 'user.logout', '127.0.0.1', '', '2015-06-09 17:32:55'),
(1247, 11, 'user.login', '127.0.0.1', '', '2015-06-09 17:32:58'),
(1248, 11, 'user.logout', '127.0.0.1', '', '2015-06-09 17:40:06'),
(1249, 8, 'user.login', '127.0.0.1', '', '2015-06-09 17:40:08'),
(1250, 11, 'user.page.add', '127.0.0.1', '{"page_title":""Clojure Tutorial for the Non-Lisp Programmer III Parte""}', '2015-06-10 16:28:56'),
(1251, 11, 'user.page.add', '127.0.0.1', '{"page_title":""sdfsdfsdfsfdsf""}', '2015-06-11 15:57:34'),
(1252, 8, 'user.logout', '::1', '', '2015-06-21 20:32:27'),
(1253, 11, 'user.login', '::1', '', '2015-06-21 20:32:31'),
(1254, 11, 'user.logout', '::1', '', '2015-06-21 21:02:25'),
(1255, 8, 'user.login', '::1', '', '2015-06-21 21:02:30'),
(1256, 8, 'user.logout', '::1', '', '2015-06-21 21:05:37'),
(1257, 11, 'user.login', '::1', '', '2015-06-21 21:05:41'),
(1258, 11, 'user.logout', '::1', '', '2015-06-21 21:13:55'),
(1259, 8, 'user.login', '::1', '', '2015-06-21 21:13:59'),
(1260, 8, 'user.logout', '::1', '', '2015-06-21 22:20:11'),
(1261, 11, 'user.login', '::1', '', '2015-06-21 22:20:15'),
(1262, 11, 'user.logout', '::1', '', '2015-06-21 22:31:13'),
(1263, 8, 'user.login', '::1', '', '2015-06-21 23:10:33'),
(1264, 8, 'user.logout', '127.0.0.1', '', '2015-06-22 11:17:07'),
(1265, 11, 'user.login', '127.0.0.1', '', '2015-06-22 11:17:11'),
(1266, 11, 'user.logout', '127.0.0.1', '', '2015-06-22 12:53:20'),
(1267, 8, 'user.login', '127.0.0.1', '', '2015-06-22 12:53:22'),
(1268, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""sdsfsdf""}', '2015-06-22 12:53:32'),
(1269, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 12:53:35'),
(1270, 8, 'user.rating.add', '127.0.0.1', '{"id_snippet":""92"","rating":""3.5""}', '2015-06-22 12:53:36'),
(1271, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 12:57:13'),
(1272, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 12:57:15'),
(1273, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:01:00'),
(1274, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:02:34'),
(1275, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:02:35'),
(1276, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:07:30'),
(1277, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:07:31'),
(1278, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:43'),
(1279, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:44'),
(1280, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:44'),
(1281, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:45'),
(1282, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:45'),
(1283, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:45'),
(1284, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:45'),
(1285, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:45'),
(1286, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:46'),
(1287, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:46'),
(1288, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:46'),
(1289, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:07:47'),
(1290, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:08:00'),
(1291, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:08:01'),
(1292, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:08:06'),
(1293, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:08:09'),
(1294, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:11:40'),
(1295, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:11:45'),
(1296, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:11:56'),
(1297, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:11:57'),
(1298, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:12:45'),
(1299, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""92""}', '2015-06-22 13:12:46'),
(1300, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:15:57'),
(1301, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:01'),
(1302, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:03'),
(1303, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:03'),
(1304, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:03'),
(1305, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1306, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1307, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1308, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1309, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1310, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:04'),
(1311, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:05'),
(1312, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:05'),
(1313, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:05'),
(1314, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:05'),
(1315, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:05'),
(1316, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:06'),
(1317, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""91""}', '2015-06-22 13:16:06'),
(1318, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""s1231231231""}', '2015-06-22 13:26:24'),
(1319, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""93""}', '2015-06-22 13:26:28'),
(1320, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""93""}', '2015-06-22 13:26:28'),
(1321, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""93""}', '2015-06-22 13:26:29'),
(1322, 8, 'user.rating.add', '127.0.0.1', '{"id_snippet":""93"","rating":""5""}', '2015-06-22 13:26:30'),
(1323, 8, 'user.comment.add', '127.0.0.1', '{"id_snippet":""93""}', '2015-06-22 13:26:32'),
(1324, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""80""}', '2015-06-22 13:27:23'),
(1325, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""80""}', '2015-06-22 13:27:24'),
(1326, 14, 'user.fav.get', '127.0.0.1', '{"id_snippet":""80""}', '2015-06-22 13:27:24'),
(1327, 8, 'user.fav.del', '127.0.0.1', '{"id_snippet":""79""}', '2015-06-22 13:27:37'),
(1328, 8, 'user.fav.add', '127.0.0.1', '{"id_snippet":""79""}', '2015-06-22 13:27:43'),
(1329, 13, 'user.fav.get', '127.0.0.1', '{"id_snippet":""79""}', '2015-06-22 13:27:43'),
(1330, 8, 'user.snippet.add', '127.0.0.1', '{"snippet_name":""How to add text-to-speech and speech-to-text features to your SIP software by using Microsoft Speech""}', '2015-06-22 17:05:54');

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `badges_achieved`
--
ALTER TABLE `badges_achieved`
  ADD CONSTRAINT `fk1` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk2` FOREIGN KEY (`ID_Badge`) REFERENCES `badges` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `comments_links`
--
ALTER TABLE `comments_links`
  ADD CONSTRAINT `fk_comments_links1` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_comments_links2` FOREIGN KEY (`ID_Link`) REFERENCES `links` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `comment_snippet`
--
ALTER TABLE `comment_snippet`
  ADD CONSTRAINT `FK_comment_snippet1` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`),
  ADD CONSTRAINT `FK_comment_snippet2` FOREIGN KEY (`ID_Snippet`) REFERENCES `snippets` (`ID`);

--
-- Filtros para la tabla `gamification_rules`
--
ALTER TABLE `gamification_rules`
  ADD CONSTRAINT `fk_gamification_rules_1` FOREIGN KEY (`eventName`) REFERENCES `event` (`eventName`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_gamification_rules_2` FOREIGN KEY (`ID_Badge`) REFERENCES `badges` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `links`
--
ALTER TABLE `links`
  ADD CONSTRAINT `fk_link_user` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `lista_favoritos_snippets`
--
ALTER TABLE `lista_favoritos_snippets`
  ADD CONSTRAINT `fk_lista_favoritos_snippets_1` FOREIGN KEY (`ID_Snippets`) REFERENCES `snippets` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_lista_favoritos_snippets_2` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `lista_tag_snippet`
--
ALTER TABLE `lista_tag_snippet`
  ADD CONSTRAINT `fk_Lista_Tag_Snippet_1` FOREIGN KEY (`ID_Tag`) REFERENCES `tags` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_Lista_Tag_Snippet_2` FOREIGN KEY (`ID_Snippets`) REFERENCES `snippets` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `list_favorites_links`
--
ALTER TABLE `list_favorites_links`
  ADD CONSTRAINT `fk_favorites_links1` FOREIGN KEY (`ID_Links`) REFERENCES `links` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_favorites_links2` FOREIGN KEY (`ID_Users`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `list_favorite_page`
--
ALTER TABLE `list_favorite_page`
  ADD CONSTRAINT `fk_favorite_page_1` FOREIGN KEY (`ID_Page`) REFERENCES `page` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_favorite_page_2` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `list_media_tags`
--
ALTER TABLE `list_media_tags`
  ADD CONSTRAINT `FK_listmedia_media` FOREIGN KEY (`ID_media`) REFERENCES `media` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `FK_listmedia_tags` FOREIGN KEY (`ID_tag`) REFERENCES `tags` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `list_tags_links`
--
ALTER TABLE `list_tags_links`
  ADD CONSTRAINT `fk_list_tags_links1` FOREIGN KEY (`ID_Tags`) REFERENCES `tags` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_list_tags_links2` FOREIGN KEY (`ID_Links`) REFERENCES `links` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `list_tag_page`
--
ALTER TABLE `list_tag_page`
  ADD CONSTRAINT `fk_tag_page_1` FOREIGN KEY (`ID_Page`) REFERENCES `page` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_tag_page_2` FOREIGN KEY (`ID_Tag`) REFERENCES `tags` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `page`
--
ALTER TABLE `page`
  ADD CONSTRAINT `fk_page_category` FOREIGN KEY (`category`) REFERENCES `category` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_page_pagelevel` FOREIGN KEY (`level`) REFERENCES `page_level` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_page_type` FOREIGN KEY (`type`) REFERENCES `page_type` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `rating_links`
--
ALTER TABLE `rating_links`
  ADD CONSTRAINT `fk_rating_links1` FOREIGN KEY (`ID_Links`) REFERENCES `links` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_rating_links2` FOREIGN KEY (`ID_Users`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `rating_snippet`
--
ALTER TABLE `rating_snippet`
  ADD CONSTRAINT `FK_rating_snippet1` FOREIGN KEY (`ID_Snippet`) REFERENCES `snippets` (`ID`),
  ADD CONSTRAINT `FK_rating_snippet2` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`);

--
-- Filtros para la tabla `search_stat`
--
ALTER TABLE `search_stat`
  ADD CONSTRAINT `fk_stat_term` FOREIGN KEY (`search_term_id`) REFERENCES `search_term` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `snippets`
--
ALTER TABLE `snippets`
  ADD CONSTRAINT `fk_snippets_2` FOREIGN KEY (`ID_Category`) REFERENCES `category` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_snippets_3` FOREIGN KEY (`ID_USER`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `snippet_log`
--
ALTER TABLE `snippet_log`
  ADD CONSTRAINT `fk_snippetlog_event` FOREIGN KEY (`event`) REFERENCES `event` (`eventName`),
  ADD CONSTRAINT `fk_snippetlog_snippet` FOREIGN KEY (`ID_Snippet`) REFERENCES `snippets` (`ID`),
  ADD CONSTRAINT `fk_snippetlog_user` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`);

--
-- Filtros para la tabla `user_event`
--
ALTER TABLE `user_event`
  ADD CONSTRAINT `fk_user_event_1` FOREIGN KEY (`eventName`) REFERENCES `event` (`eventName`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_user_event_2` FOREIGN KEY (`ID_User`) REFERENCES `users` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;