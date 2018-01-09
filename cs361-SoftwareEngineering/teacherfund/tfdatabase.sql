DROP TABLE IF EXISTS `tf_fund_request`;
DROP TABLE IF EXISTS `tf_ccard`;
DROP TABLE IF EXISTS `tf_following`;
DROP TABLE IF EXISTS `tf_bank`;
DROP TABLE IF EXISTS `tf_teaching`;
DROP TABLE IF EXISTS `tf_schools`;
DROP TABLE IF EXISTS `tf_users`;
DROP TABLE IF EXISTS `tf_login`;

CREATE TABLE `tf_login`(
    `userID` int(11) NOT NULL AUTO_INCREMENT,
    `pass` varchar(255) NOT NULL,
    `email` varchar(255) NOT NULL,
    PRIMARY KEY (userID),
    UNIQUE KEY (email)
)ENGINE=innodb;

CREATE TABLE `tf_users` (
    `userID` int(11) NOT NULL,
    `photo` varchar(255),
    `biography` text,
    `f_name` varchar(255) NOT NULL,
    `l_name` varchar(255) NOT NULL,
    `userType` varchar(255) NOT NULL,
    FOREIGN KEY(userID) references tf_login (userID) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=innodb;

CREATE TABLE tf_ccard (
    userID int(11) NOT NULL,
    cardNum bigint(16) NOT NULL,
    exp date NOT NULL,
    type varchar(255) NOT NULL,
    FOREIGN KEY(userID) references tf_login (userID) ON DELETE CASCADE  ON UPDATE CASCADE
)engine=innodb;

CREATE TABLE tf_bank (
    userID int(11) NOT NULL,
    checkAcct int(20) NOT NULL,
    routNum int(20) NOT NULL,
    FOREIGN KEY (userID) REFERENCES tf_login (userID) ON DELETE CASCADE  ON UPDATE CASCADE
)engine=innodb;

CREATE TABLE tf_following (
    teacherID int(11) NOT NULL,
    donorID int(11) NOT NULL,
    FOREIGN KEY (teacherID) REFERENCES tf_login (userID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (donorID) REFERENCES tf_login (userID) ON DELETE CASCADE ON UPDATE CASCADE
) engine=innodb;

CREATE TABLE tf_fund_request (
    userID int(11) NOT NULL,
    fundID int(11) AUTO_INCREMENT NOT NULL,
    type varchar(255),
    goal int(11) NOT NULL,
    raised int(11),
    description text,
    PRIMARY KEY (fundID),
    FOREIGN KEY (userID) REFERENCES tf_login (userID) ON DELETE CASCADE  ON UPDATE CASCADE
)engine=innodb;


CREATE TABLE tf_schools (
	schoolID int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	city varchar(255) NOT NULL,
	state varchar(255) NOT NULL,
	PRIMARY KEY (schoolID)
)engine=innodb;


CREATE TABLE tf_teaching (
	teacherID int(11) NOT NULL,
	schoolID int(11) NOT NULL,
	FOREIGN KEY (teacherID) REFERENCES tf_login (userID) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (schoolID) REFERENCES tf_schools (schoolID) ON UPDATE CASCADE ON DELETE CASCADE,
	PRIMARY KEY (teacherID, schoolID)
) engine=innodb;

INSERT INTO tf_login (email, pass) VALUES 
("donor@fake.com", "password"), 
("teacher@fake.com", "password");

INSERT INTO tf_users (f_name, l_name, userType, userID) VALUES 
("mr", "donor", "donor", (SELECT userID FROM tf_login WHERE email="donor@fake.com")), 
("mrs", "teacher", "teacher", (SELECT userID FROM tf_login WHERE email="teacher@fake.com"));

INSERT INTO tf_ccard (userID, cardNum, exp, type) VALUES
((SELECT userID FROM tf_login WHERE email="donor@fake.com"), 2345123412341234, "1/11/17", "visa");

INSERT INTO tf_bank (userID, checkAcct, routNum) VALUES
((SELECT userID FROM tf_login WHERE email="teacher@fake.com"), 514521, 134543);

INSERT INTO tf_following (donorID, teacherID) VALUES 
((SELECT userID FROM tf_login WHERE email="donor@fake.com"), 
(SELECT userID FROM tf_login WHERE email="teacher@fake.com"));

INSERT INTO tf_fund_request (userID, goal, description) VALUES
((SELECT userID FROM tf_login WHERE email="teacher@fake.com"), 672, "I need bus tickets for my Planeteers(tm)!");

INSERT INTO tf_schools (name, city, state) VALUES ("Springfield Elementary School", "Springfield", "OR");

INSERT INTO tf_teaching (teacherID, schoolID) VALUES (
(SELECT userID FROM tf_login WHERE email="teacher@fake.com"), 
(SELECT schoolID FROM tf_schools WHERE name="Springfield Elementary School"));
