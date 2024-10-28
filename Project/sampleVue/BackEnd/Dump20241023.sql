-- MySQL dump 10.13  Distrib 8.0.40, for Win64 (x86_64)
--
-- Host: localhost    Database: test
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `accident_log`
--

DROP TABLE IF EXISTS `accident_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accident_log` (
  `accident_id` int NOT NULL,
  `accident_date` timestamp NULL DEFAULT NULL,
  `arrival_date` timestamp NULL DEFAULT NULL,
  `result` varchar(20) NOT NULL,
  `accident_position` varchar(50) NOT NULL,
  `log_date` timestamp NOT NULL,
  `accident_video` varchar(255) NOT NULL,
  `robot_id` int NOT NULL,
  PRIMARY KEY (`accident_id`),
  KEY `accident_log_robot_id_fkey_idx` (`robot_id`),
  CONSTRAINT `accident_log_robot_id_fkey` FOREIGN KEY (`robot_id`) REFERENCES `robot` (`robot_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accident_log`
--

LOCK TABLES `accident_log` WRITE;
/*!40000 ALTER TABLE `accident_log` DISABLE KEYS */;
/*!40000 ALTER TABLE `accident_log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `admin` (
  `admin_id` bigint NOT NULL AUTO_INCREMENT,
  `uid` bigint NOT NULL,
  PRIMARY KEY (`admin_id`),
  KEY `admin_uid_fkey_idx` (`uid`),
  CONSTRAINT `admin_uid_fkey` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `allow`
--

DROP TABLE IF EXISTS `allow`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `allow` (
  `allow_id` bigint NOT NULL AUTO_INCREMENT,
  `allow_date` timestamp NULL DEFAULT NULL,
  `admin_id` bigint DEFAULT NULL,
  `uid` bigint DEFAULT NULL,
  PRIMARY KEY (`allow_id`),
  KEY `allow_uid_fkey_idx` (`uid`),
  KEY `allow_admin_id_fkey_idx` (`admin_id`),
  CONSTRAINT `allow_admin_id_fkey` FOREIGN KEY (`admin_id`) REFERENCES `admin` (`admin_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `allow_uid_fkey` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `allow`
--

LOCK TABLES `allow` WRITE;
/*!40000 ALTER TABLE `allow` DISABLE KEYS */;
/*!40000 ALTER TABLE `allow` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cameras`
--

DROP TABLE IF EXISTS `cameras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cameras` (
  `camera_id` bigint NOT NULL,
  `camera_position` varchar(255) NOT NULL,
  `video` varchar(255) NOT NULL,
  PRIMARY KEY (`camera_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cameras`
--

LOCK TABLES `cameras` WRITE;
/*!40000 ALTER TABLE `cameras` DISABLE KEYS */;
/*!40000 ALTER TABLE `cameras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `notification`
--

DROP TABLE IF EXISTS `notification`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `notification` (
  `notice_id` bigint NOT NULL,
  `notice_type` varchar(255) NOT NULL,
  `is_read` tinyint(1) NOT NULL,
  `is_delete` tinyint(1) NOT NULL,
  `create_date` timestamp NOT NULL,
  `uid` bigint NOT NULL,
  PRIMARY KEY (`notice_id`),
  KEY `notification_uid_fkey` (`uid`),
  CONSTRAINT `notification_uid_fkey` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `notification`
--

LOCK TABLES `notification` WRITE;
/*!40000 ALTER TABLE `notification` DISABLE KEYS */;
/*!40000 ALTER TABLE `notification` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `report`
--

DROP TABLE IF EXISTS `report`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `report` (
  `report_time` int NOT NULL,
  `modifined_date` timestamp NOT NULL,
  PRIMARY KEY (`report_time`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `report`
--

LOCK TABLES `report` WRITE;
/*!40000 ALTER TABLE `report` DISABLE KEYS */;
/*!40000 ALTER TABLE `report` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `robot`
--

DROP TABLE IF EXISTS `robot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `robot` (
  `robot_id` int NOT NULL,
  `report_time` int NOT NULL,
  PRIMARY KEY (`robot_id`),
  KEY `robot_report_time_fkey_idx` (`report_time`),
  CONSTRAINT `robot_report_time_fkey` FOREIGN KEY (`report_time`) REFERENCES `report` (`report_time`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `robot`
--

LOCK TABLES `robot` WRITE;
/*!40000 ALTER TABLE `robot` DISABLE KEYS */;
/*!40000 ALTER TABLE `robot` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `uid` bigint NOT NULL AUTO_INCREMENT,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `phone` varchar(11) NOT NULL,
  `grade` varchar(255) NOT NULL DEFAULT '일반',
  `create_date` timestamp NOT NULL,
  `modified_date` timestamp NULL DEFAULT NULL,
  `image` mediumblob,
  `authorization` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'test_email','abcd1234','손오공','01012341234','일반','2024-10-23 02:07:32','2024-10-23 06:44:07',NULL,0);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-10-23 17:41:45
