drop database if exists DubeQuizzes;
CREATE DATABASE DubeQuizzes;
USE DubeQuizzes;

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `category` (
  `category_id` int(11) NOT NULL AUTO_INCREMENT,
  `category_name` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`category_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;


LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES (1,'Math'),(2,'Science'),(3,'Geography');
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;


DROP TABLE IF EXISTS `grade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `grade` (
  `grade_id` int(11) NOT NULL AUTO_INCREMENT,
  `grade_text` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`grade_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;


LOCK TABLES `grade` WRITE;
/*!40000 ALTER TABLE `grade` DISABLE KEYS */;
INSERT INTO `grade` VALUES (1,'1st Grade'),(2,'2nd Grade'),(3,'3rd Grade'),(4,'4th Grade'),(5,'5th Grade');
/*!40000 ALTER TABLE `grade` ENABLE KEYS */;
UNLOCK TABLES;


DROP TABLE IF EXISTS `question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `question` (
  `question_id` int(11) NOT NULL AUTO_INCREMENT,
  `question_text` varchar(300) DEFAULT NULL,
  `grade_level` int(11) NOT NULL,
  `category_id` int(11) NOT NULL,
  `answer` varchar(60) NOT NULL,
  PRIMARY KEY (`question_id`),
  KEY `category_id` (`category_id`),
  KEY `grade_level` (`grade_level`),
  CONSTRAINT `question_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `category` (`category_id`),
  CONSTRAINT `question_ibfk_2` FOREIGN KEY (`grade_level`) REFERENCES `grade` (`grade_id`)
) ENGINE=InnoDB AUTO_INCREMENT=76 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;


LOCK TABLES `question` WRITE;
/*!40000 ALTER TABLE `question` DISABLE KEYS */;
INSERT INTO `question` VALUES (1,'How many continents are there?',1,3,'7'),(2,'True or false. Paris the capital of France. (T/F)',1,3,'T'),(3,'In which country are the famous Pyramids of Giza?',1,3,'Eqypt'),(4,'In what city is the White House located?',1,3,'Washington D.C.'),(5,'How many states are in the United States of America?',1,3,'50'),(6,'Which state is called the Lone Star state?',2,3,'Texas'),(7,'In what state is the Grand Canyon located?',2,3,'Arizona'),(8,'Which of these countries is not located in North America: Canada, Brazil, the United States, or Mexico?',2,3,'Brazil'),(9,'To travel from New York to London, one must fly over which ocean?',2,3,'The Atlantic Ocean'),(10,'In what country is the famous Taj Mahal located?',2,3,'India'),(11,'What is the longest river in the world?',3,3,'The Amazon'),(12,'True or false. The country of Greece is located in Asia. (T/F)',3,3,'F'),(13,'What is the name for a body of land that is completely surrounded by water?',3,3,'An island'),(14,'What is the capital of New York?',3,3,'Albany'),(15,'There are four Great Lakes in the United States? Which of these is not one: Michigan-Huron, Superior, Powell, Erie, or Ontario?',3,3,'Powell'),(16,'Where is the largest desert in the world located?',4,3,'Northern Africa'),(17,'There are four kingdoms in the United Kingdom? Which of these is not one: England, Denmark, Northern Ireland, Scotland, or Wales?',4,3,'Denmark'),(18,'Which country is the largest in size?',4,3,'Russia'),(19,'True or false. The United States and Mexico are separated by the Red River? (T/F)',4,3,'F'),(20,'What is the southernmost continent called?',4,3,'Antarctica'),(21,'True or false. French is the main language spoken in the Canadian province of Quebec. (T/F)',5,3,'T'),(22,'Which country is both an island and a continent?',5,3,'Australia'),(23,'What is the name of the sea bordered by Europe to the north and North Africa to the south?',5,3,'The Mediterranean Sea'),(24,'True or false. The mountain range that includes Mount Everest is called the Alps. (T/F)',5,3,'F'),(25,'True or false. Imaginary lines traversing the globe from pole to pole are called Meridians. (T/F)',5,3,'T'),(26,'What causes tides?',1,2,'the moon'),(27,'The south pole of the magnet and the north pole of another magnet will do what: stick together or repel each other?',1,2,'stick together'),(28,'What is the force that causes objects to fall to the ground?',1,2,'gravity'),(29,'A caterpillar changes and grows into a what?',1,2,'butterfly'),(30,'True or false. The heart is the biggest organ in the human body? (T/F)',1,2,'F'),(31,'What is H2O also known as?',2,2,'water'),(32,'True or false. Nitrogen is the gas is in the air we breathe? (T/F)',2,2,'F'),(33,'Carbon dioxide is the gas that plants release and that humans and animals breathe in?',2,2,'F'),(34,'Earth is located in what galaxy?',2,2,'The Milky Way'),(35,'True or false. Bats are mammals. (T/F)',2,2,'T'),(36,'What phenomenon might be felt on the surface when two tectonic plates rub against each other?',3,2,'earthquake'),(37,'The hardest naturally occurring mineral is',3,2,'diamond'),(38,'True or false. Venus is the closest planet to the sun. (T/F)',3,2,'F'),(39,'True or false. The process by which plants eat and make energy is called Photosynthesis. (T/F)',3,2,'T'),(40,'Does the sun orbit the Earth?',3,2,'no'),(41,'What is the part of the eye that controls how much light enters: Pupil, Cornea, or Retina?',4,2,'Pupil'),(42,'What planet is nicknamed the \"Red Planet?\"',4,2,'Mars'),(43,'True or false. Animals that eat only meat are known as Omnivores. (T/F)',4,2,'F'),(44,'How many days does Earth take to revolve once around the sun?',4,2,'365'),(45,'True or false. The freezing point of water is 32°F or 0°C. (T/F)',4,2,'T'),(46,'True or false. The Earth is at least 4 billion years old? (T/F)',5,2,'T'),(47,'There are three states of matter: solid, liquid, and... ',5,2,'gas'),(48,'The Earth has 4 layers, the thickest of which is the mantle. The thinnest layer is called the...?',5,2,'crust'),(49,'True or false. Animals without backbones are known as vertebrates. (T/F)',5,2,'F'),(50,'What species can live on both water and land:  amphibians, reptiles or mammals?',5,2,'amphibians'),(51,'How many face cards are in a regular deck of playing cards?',1,1,'12'),(52,'The first day of the 20th century was 1 January...',1,1,'1901'),(53,'How many states made up the United States before Alaska and Hawaii joined?',1,1,'48'),(54,'True or false. 12 is the largest number that can be pronounced with a single syllable. (T/F)',1,1,'T'),(55,'You peer through a window into a classroom and count 20 eyes. If each person has a normal number of eyes, how many people are in the room?',1,1,'10'),(56,'What is the area of a triangle with a height of 4 and a width of 4?',2,1,'8'),(57,'Solve the following equation: 3 + 2 / 1 = ...',2,1,'5'),(58,'On a class field trip, there are 4 buses taking 36 students to the zoo. Each bus has the same number of student. How many students are on each bus?',2,1,'9'),(59,'2 dozen kittens and 3 dozen puppies get adopted from the shelter. How many animals were adopted?',2,1,'60'),(60,'What number is the Roman numeral XVI?',2,1,'16'),(61,'When writing out a fraction, the numbers above and below the vinculum are called the...',3,1,'numerator and denominator'),(62,'To the nearest multiple of 10, how many kilograms of cheese are in 110 pounds of cheese?',3,1,'50'),(63,'If a shopping cart contains 1 apple, 2 bananas, 3 oranges, 4 hot dogs, what percent of the cart\'s total contents is fruit: 60%, 40%, 50%, or 70%?',3,1,'60%'),(64,'If the first person takes 25% of the cake and the second person takes 20% of the remainder, how much of the original cake remains?',3,1,'60%'),(65,'How many grams are in a thousand kilograms?',3,1,'one million'),(66,'If a train leaves the station and travels at 60 kilometers per hour, how much time will have passed when it arrives at a station 300 kilometers away: 4 hours, 5 hours, 5.5 hours, or 6 hours?',4,1,'5 hours'),(67,'The interior angles of a triangle always sum to...',4,1,'180 degrees'),(68,'A farmer notices that every day for the past 10 days, the number of pigeons in his field has doubled. There are 1024 pigeons in the field today, and there were 2 pigeons there the first day. How many pigeons were there yesterday?',4,1,'512'),(69,'You have 20 pairs of shoes, but there is only room in your closet for 8 shoes. How many shoes do you have to get rid of?',4,1,'32 shoes'),(70,'Solve the following equation: 5 + 3 * 4 / 2 - 1 =',4,1,'10'),(71,'A hexagon has how many sides?',5,1,'6'),(72,'A father has 7 daughters and 100 dollars. If he wants to give each daughter an equal amount of money, rounding to the nearest dollar, how much much does each daughter get?',5,1,'14 dollars'),(73,'If a football field is 100 yards long, how many feet long is the football field?',5,1,'300 feet'),(74,'You collect 48 pieces of Halloween candy. Your parents say you can eat 2 pieces per day, plus an extra piece on Saturdays and Sundays. How many weeks will it take to finish all of your candy? ',5,1,'3 weeks'),(75,'Solve the following equation: (2 * 4)/(5 + 3 - 1)^0',5,1,'8');
/*!40000 ALTER TABLE `question` ENABLE KEYS */;
UNLOCK TABLES;


DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(60) DEFAULT NULL,
  `score` int(8) DEFAULT NULL,
  `grade_id` int(11) DEFAULT NULL,
  `cat_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  KEY `cat_id` (`cat_id`),
  KEY `grade_id` (`grade_id`),
  CONSTRAINT `user_ibfk_1` FOREIGN KEY (`cat_id`) REFERENCES `category` (`category_id`),
  CONSTRAINT `user_ibfk_2` FOREIGN KEY (`grade_id`) REFERENCES `grade` (`grade_id`)
) ENGINE=InnoDB AUTO_INCREMENT=57 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;


LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (22,'Anna',20,4,1),(34,'Jim',4,1,2),(35,'Anna',12,3,3),(36,'Matt',8,2,3),(37,'Jill',25,5,2),(38,'Annie',3,1,2),(39,'Maria',16,4,1),(40,'Sarah',12,3,3),(41,'Billy',16,4,1),(42,'Nate',20,5,3),(43,'Jane',5,1,1),(44,'Jane',0,1,1),(45,'James',6,2,2),(47,'Nate',12,3,2),(48,'James',6,2,2),(49,'anna',15,3,1),(50,'Bob',12,4,2),(51,'Bob',12,4,2),(52,'Nate',20,5,3),(53,'Anna',15,3,1),(54,'John',16,4,1),(56,'Anna',16,4,2);
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