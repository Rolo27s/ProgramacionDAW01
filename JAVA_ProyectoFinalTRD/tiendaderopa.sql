-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost:3307
-- Tiempo de generación: 21-05-2023 a las 14:04:52
-- Versión del servidor: 10.4.28-MariaDB
-- Versión de PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `tiendaderopa`
--
CREATE DATABASE IF NOT EXISTS `tiendaderopa` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_spanish2_ci;
USE `tiendaderopa`;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `id` int(11) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `talla` varchar(10) NOT NULL,
  `precio` decimal(10,2) NOT NULL,
  `stock` int(10) NOT NULL,
  `tipoTejido` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish2_ci;

--
-- Volcado de datos para la tabla `producto`
--

INSERT INTO `producto` (`id`, `nombre`, `talla`, `precio`, `stock`, `tipoTejido`) VALUES
(1, 'Falda', 'S', 29.99, 20, 'Algodón'),
(2, 'Camisa', 'M', 39.99, 30, 'Lino'),
(3, 'Jeans', 'L', 49.99, 10, 'Denim'),
(4, 'Sudadera', 'XS', 39.99, 15, 'Algodón'),
(5, 'Zapatos', 'L', 59.45, 5, 'Cuero'),
(6, 'Sombrero', 'M', 24.99, 25, 'Paja'),
(7, 'Abrigo', 'L', 89.99, 8, 'Lana'),
(9, 'Calcetines', 'M', 9.99, 50, 'Algodón'),
(10, 'Gorra', 'M', 19.99, 30, 'Poliéster'),
(11, 'Botas', 'L', 23.68, 7, 'Cuero y poliester');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `producto`
--
ALTER TABLE `producto`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
