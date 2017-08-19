SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE IF EXISTS `artifacts`;
DROP TABLE IF EXISTS `sites`;
DROP TABLE IF EXISTS `test_units`;
DROP TABLE IF EXISTS `artifact_materials`;
DROP TABLE IF EXISTS `materials`;

CREATE TABLE `sites`(
    `id` varchar(255) NOT NULL,
    `name` varchar(255),
	`state` char(2),
    PRIMARY KEY (id)
)ENGINE=innodb;

CREATE TABLE `test_units`(
   `tu_number` varchar(255) NOT NULL,
   `site_id` varchar(255) NOT NULL,
   PRIMARY KEY (tu_number, site_id),
   FOREIGN KEY(site_id) REFERENCES sites (id) ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=innodb;

CREATE TABLE `artifacts`(
    `fs_number` int(11) NOT NULL,
    `site_id` varchar(255) NOT NULL,
    `description` text,
	`tu_number` varchar(255) NOT NULL,
	`tu_level` varchar(255),
	`date_excavated` date,
    PRIMARY KEY (fs_number),
    FOREIGN KEY(tu_number) REFERENCES test_units (tu_number) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(site_id) REFERENCES sites (id) ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=innodb;

CREATE TABLE `materials`(
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255),
    PRIMARY KEY (id)
)ENGINE=innodb;

CREATE TABLE `artifact_materials`(
    `fs_number` int(11) NOT NULL,
	`material_id` int(11) NOT NULL,
    PRIMARY KEY (fs_number, material_id),
	FOREIGN KEY(fs_number) REFERENCES artifacts (fs_number) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(material_id) REFERENCES materials (id) ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=innodb;

SET FOREIGN_KEY_CHECKS = 1;

