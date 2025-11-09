import mysql.connector
from model.student import Student
from model.parent import Parent
from model.course import Course

class db_mysql:
    def __init__(self, host, db, userID, pwd) -> None:
        self.host = host
        self.db = db
        self.user = userID
        self.password = pwd
        self.con = None

    def connect(self) -> bool:
        self.con = mysql.connector.connect(
                    host = self.host,
                    database = self.db,
                    user = self.user,
                    password = self.password
                )
        return self.con != None
    
    def is_connected(self) -> bool:
        return self.con != None

    def get_all_students(self):
        sql = "SELECT * FROM students;"
        cursor = self.con.cursor()
        cursor.execute(sql)
        tup : tuple = ()
        for row in cursor:
            std = Student(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13])
            tup += (std, )
        return tup
        
    def get_all_parents(self):
        sql = "SELECT * FROM PARENT;"
        cursor = self.con.cursor()
        cursor.execute(sql)

    def get_all_courses(self):
        sql = "SELECT * FROM COURSE;"
        cursor = self.con.cursor()
        cursor.execute(sql)
        for x in cursor:
            print(x)

    def get_student(self, id) -> Student:
        sql = f"SELECT * FROM STUDENT WHERE ID = '{id}'"
        cursor = self.con.cursor()
        cursor.execute(sql)
        for x in cursor:
            print(x)

    def get_parent(self, id) -> Parent:
        sql = f"SELECT * FROM PARENT WHERE ID = '{id}'"
        cursor = self.con.cursor()
        cursor.execute(sql)
        for x in cursor:
            print(x)

    def get_course(self, id) -> Course:
        sql = f"SELECT * FROM COURSE WHERE ID = '{id}'"
        cursor = self.con.cursor()
        cursor.execute(sql)
        for x in cursor:
            print(x)
            
    # def insert_student(self):
    #     sql = f"INSERT INTO student VALUES(\"{student.student.get_id}\",\"{student.student}\",\"{student.student}\",\"{student.student}\",\"{student.student}\",\"{student.student}\",\"{student.student}\",\"{student.student}\");"
    #     pass
    
    # def remove_student(self):
    #     pass
    
    # def insert_parent(self):
    #     sql = f"INSERT INTO parent VALUES(\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\",\"{parent.parent.}\");"
    #     pass
    
    # def remove_parent(self):
    #     pass
    
    # def insert_course(self):
    #     sql = f"INSERT INTO course VALUES(\"{course.course}\",\"{course.course}\",\"{course.course}\",\"{course.course}\",\"{course.course}\",\"{course.course}\",\"{course.course}\",\"{course.course}\");"
    #     pass
    
    # def remove_course(self):
    #     pass