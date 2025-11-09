# Create a Program to take database name and backup all the tables into a folder in CSV/Json/XML Formats

import mysql.connector
import json

def create_database(dbname):
    sql = "CREATE DATABASE " + dbname
    mycursor = mydb.cursor()
    mycursor.execute(sql)

def use_database(dbname):
    sql = "USE " + dbname
    mycursor = mydb.cursor()    
    mycursor.execute(sql)
        
def create_table(tablename):
    sql = f"CREATE TABLE {tablename} (id varchar(10),f_name varchar(30), l_name varchar(30), branch varchar(30), age int, blood_group : varchar(5), email varchar(50))"
    mycursor = mydb.cursor()
    mycursor.execute(sql)

def insert_table(tablename, val1, val2, val3, val4, val5, val6, val7):
    sql = f"INSERT INTO {tablename} VALUES({val1},{val2},{val3},{val4},{val5},{val6},{val7})"
    mycursor = mydb.cursor()
    mycursor.execute(sql)

def backup_data(tablename):
    sql = "SELECT * FROM " + tablename
    mycursor = mydb.cursor()    
    mycursor.execute(sql)
    file = open("backup_db.json", "wt")
    for x in mycursor:
        json_format = json.dumps(x, indent=2)
        file.write(json_format)
    file.close()

def read_data():
    with open("backup_db.json", "rt") as file:
        data = json.load(file)
        return data

mydb = mysql.connector.connect(
    host="localhost",
    user="anurag",
    password="mysql"
)

create_database("SMS")
use_database("SMS")
create_table("students")
insert_table("students", "22VE1A6668", "Anurag", "Meshram", "AIML", 18, "O+ve", "immortal@gmail.com")
insert_table("students", "22VE1A6668", "Adarsh", "Meshram", "NEURO", 16, "O+ve", "adarsh@gmail.com")
insert_table("students", "22VE1A6668", "Kiran", "Meshram", "ENT", 48, "O+ve", "kiran@gmail.com")
backup_data("students")

students_data = read_data()
if not students_data:
    print("Failed to read students data")
    exit(-1)
else:
    student_id = input("Enter Student ID : ")
    if student_id in students_data:
        print(students_data[student_id])