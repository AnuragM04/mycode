import mysql.connector
import json

def use_database(dbname):
    sql = "USE " + dbname
    mycursor = mydb.cursor()    
    mycursor.execute(sql)

def insert_table(tablename, val1, val2, val3, val4, val5, val6, val7, val8):
    sql = f"INSERT INTO {tablename} VALUES(\"{val1}\",\"{val2}\",\"{val3}\",\"{val4}\",\"{val5}\",\"{val6}\",\"{val7}\",\"{val8}\")"
    mycursor = mydb.cursor()
    mycursor.execute(sql)
    mydb.commit()

def upload_csv(tablename):
    keys = "Roll No, Name, Branch, Section, Phone No, Blood Group, Email, Date Of Birth"
    with open("SMS.csv", "rt") as sf:
        while True:
            str_buff = sf.readline()
            if not str_buff:
                break
            else:
                dictn = dict(zip(keys.split(", "), str_buff.strip().split(",")))
                dob = dictn["Date Of Birth"].split("-")
                dob.reverse()                
                insert_table(tablename, dictn["Roll No"], dictn["Name"], dictn["Branch"], dictn["Section"], dictn["Phone No"], dictn["Blood Group"], dictn["Email"], "-".join(dob))
   
def upload_json(tablename):
    keys = "Roll No, Name, Branch, Section, Phone No, Blood Group, Email, Date Of Birth"
    with open("SMS.json", "rt") as file:
        dictn = json.load(file)
        if not dictn:
            print("Failed to read students data")
            exit(-1)
        else:
            print(insert_table(tablename, dictn["Roll No"], dictn["Name"], dictn["Branch"], dictn["Section"], dictn["Phone No"], dictn["Blood Group"], dictn["Email"], dictn["Date Of Birth"]))
    
def upload():
    while True:
        print("\n\n1: Upload from CSV")
        print("2: Upload from JSON")
        print("3: Upload Individual Student data")
        print("4: Exit")
        choice = input("Your choice, should you choose to accept it: ")
        
        match choice:
            case "1":
                upload_csv(input("Enter name of the table: "))
                
            case "2":
                upload_json(input("Enter name of the table: "))
            
            case "3":
                tablename = input("Enter name of the table: ")
                roll_no = input("Enter Roll Number: ")
                name = input("Enter Name: ")
                branch = input("Enter Branch: ")
                section = input("Enter Section: ")
                phn_num = input("Enter Phone Number: ")
                bld_grp = input("Enter Blood Group: ")
                email = input("Enter Email: ")
                dob = input("Enter Date of Birth(YYYY-MM-DD): ")
                insert_table(tablename, roll_no, name, branch, section, phn_num, bld_grp, email, dob)
            
            case "3":
                print("This code will self-destruct in five seconds...\nThank you.")
                break
            
            case _:
                print("Choice failed")
        
        if choice > "4":
            break
        pass

mydb = mysql.connector.connect(
    host="localhost",
    user="anurag",
    password="mysql"
)

use_database("sms")
upload()