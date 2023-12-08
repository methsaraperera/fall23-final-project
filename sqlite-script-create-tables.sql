-- admin definition

CREATE TABLE 'admin'(
'faculty_id' TEXT,
'name' TEXT,
'username' TEXT,
'password' TEXT,
PRIMARY KEY ('username')
);


-- class definition

CREATE TABLE `class` (
  `class_id` TEXT PRIMARY KEY,
  `class_name` TEXT
);


-- degree_path definition

CREATE TABLE `degree_path` (
  `path_id` INTEGER PRIMARY KEY,
  `path_name` TEXT);


-- class_co_requisites definition

CREATE TABLE `class_co_requisites` (
  `class_id` TEXT,
  `class_co_req_id` TEXT,
  PRIMARY KEY (class_id, class_co_req_id),
  FOREIGN KEY (`class_id`) REFERENCES `class` (`class_id`),
  FOREIGN KEY (`class_co_req_id`) REFERENCES `class` (`class_id`)
);


-- class_pre_requisites definition

CREATE TABLE `class_pre_requisites` (
  `class_id` TEXT,
  `class_pre_req_id` TEXT,
  PRIMARY KEY (class_id, class_pre_req_id),
  FOREIGN KEY (`class_id`) REFERENCES `class` (`class_id`),
  FOREIGN KEY (`class_pre_req_id`) REFERENCES `class` (`class_id`)
);


-- path_require definition

CREATE TABLE `path_require` (
  `path_id` INTEGER,
  `path_class` TEXT,
  PRIMARY KEY (`path_id`, `path_class`),
  FOREIGN KEY (`path_id`) REFERENCES `degree_path` (`path_id`),
  FOREIGN KEY (`path_class`) REFERENCES `class` (`class_id`)
);