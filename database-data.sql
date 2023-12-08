INSERT INTO admin (faculty_id,name,username,password) VALUES
	 ('FAC0001','John Doe','admin1','admin1');
INSERT INTO class (class_id,class_name) VALUES
	 ('CSC 101','Principles in Information Technology and Computation'),
	 ('CSC 111','Introduction to Programming'),
	 ('CSC 211','Adv. Programming Techniques'),
	 ('CSC 215','Fundamentals of Computer Systems'),
	 ('CSC 231','Discrete Structures and Applications to Computer Science'),
	 ('CSC 331','Data Structures'),
	 ('CSC 350','Software Development'),
	 ('MAT 206.5','Intermediate Algebra & Precalculus'),
	 ('MAT 301','Analytic Geometry and Calculus I'),
	 ('MAT 302','Analytic Geometry and Calculus II');
INSERT INTO class (class_id,class_name) VALUES
	 ('SPE 100','Fundamentals of Public Speaking'),
	 ('ENG 101','English Composition'),
	 ('PHY 215','University Physics I'),
	 ('ENG 201','Introduction to Literature');
INSERT INTO class_co_requisites (class_id,class_co_req_id) VALUES
	 ('MAT 301','PHY 215'),
	 ('PHY 215','MAT 301');
INSERT INTO class_pre_requisites (class_id,class_pre_req_id) VALUES
	 ('CSC 111','CSC 101'),
	 ('CSC 211','CSC 111'),
	 ('CSC 215','CSC 111'),
	 ('CSC 231','CSC 111'),
	 ('CSC 350','CSC 211'),
	 ('CSC 311','CSC 211'),
	 ('CSC 311','CSC 231'),
	 ('MAT 301','MAT 206.5'),
	 ('MAT 302','MAT 301');
INSERT INTO degree_path (path_id,path_name) VALUES
	 (1,'Computer Information Systems'),
	 (2,'Computer Network Technologys'),
	 (3,'Computer Science'),
	 (4,'Geographic Information Science');
INSERT INTO path_require (path_id,path_class) VALUES
	 (3,'CSC 101'),
	 (3,'CSC 111'),
	 (3,'CSC 201'),
	 (3,'CSC 215'),
	 (3,'CSC 231'),
	 (3,'CSC 331'),
	 (3,'CSC 350'),
	 (3,'MAT 206.5'),
	 (3,'MAT 301'),
	 (3,'MAT 302');
INSERT INTO path_require (path_id,path_class) VALUES
	 (1,'CSC 101'),
	 (1,'CSC 111'),
	 (1,'ENG 101'),
	 (3,'ENG 101'),
	 (3,'ENG 201');
