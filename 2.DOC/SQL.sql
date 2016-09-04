--创建库
CREATE DATABASE School

--使用SchoolManage
use School

--创建 t_class
CREATE TABLE t_Class
(
    cID     varchar(50)     PRIMARY key,    --班级ID
    cName   varchar(50)     NOT NULL        --班级名
)

--创建 t_student
CREATE TABLE t_Student
(
    sID     varchar(50)     PRIMARY key,                        --学生ID
    sName   varchar(50)     NOT NULL,                           --学生名
    sGender varchar(50)     NOT NULL DEFAULT 'UnKnow',          --学生性别
    sBirth  datetime        NOT NULL DEFAULT '1970/1/1',        --学生生日
    cID     varchar(50)     FOREIGN KEY REFERENCES t_Class(cID) --班级表外键 班级ID
)

--创建 t_course
CREATE TABLE t_Course
(
    couID   varchar(50)     PRIMARY key,    --课程ID
    couName varchar(50)     NOT NULL        --课程名
)

--创建 t_select_course
CREATE TABLE t_Select_Course
(
    sID     varchar(50)     FOREIGN KEY REFERENCES t_Student(sID),      --学生表外键 学生ID
    couID   varchar(50)     FOREIGN KEY REFERENCES t_Course(couID),     --课程表外键 课程ID
    Score   float           NOT NULL,                                   --课程成绩
	PRIMARY key(sID, couID)                                             --设置 复合主键
)