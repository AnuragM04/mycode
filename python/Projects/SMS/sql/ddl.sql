drop database sms;

create table student(
    student_id varchar(25) PRIMARY KEY,
    first_name varchar(50),
    last_name varchar(50),
    password varchar(45),
    branch varchar(20),
    class varchar(10),
    mobile_number varchar(15),
    phone_number varchar(15),
    blood_group varchar(5),
    email varchar(100),
    parent_id int,
    date_of_birth date,
    date_of_join date,
    last_login_date date,
);

create table parent(
    parent_id int PRIMARY KEY, 
    first_name varchar(50),
    last_name varchar(50),
    password varchar(45),
    mobile_number varchar(15),
    phone_number varchar(15),
    email varchar(100),
    date_of_birth date,
    date_of_join date,
    last_login_date date,
);

create table teacher(
    teacher_id int PRIMARY KEY, 
    first_name varchar(50),
    last_name varchar(50),
    password varchar(45),
    mobile_number varchar(15),
    phone_number varchar(15),
    email varchar(100),
    date_of_birth date,
    date_of_join date,
    last_login_date date,
);

create table course(
    course_id int PRIMARY KEY, 
    name varchar(50),
    description varchar(500)
);

create table attendance(
    date date,
    student_id varchar(15),
    remark varchar(10)
);

create table exam(
    date date,
    subject varchar(15),
    exam_id int
);

create table results(
    student_id varchar(15),
    exam_id int,
    course_id int,
    marks varchar(20)
);