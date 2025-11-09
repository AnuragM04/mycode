import mysql.connector
import json

def use_database(dbname):
    sql = "USE " + dbname
    mycursor = mydb.cursor()    
    mycursor.execute(sql)

def search_dbs(tablename, id):
    sql = f" SELECT * FROM {tablename} WHERE roll_no = '{id}' "
    mycursor = mydb.cursor()
    mycursor.execute(sql)
    for x in mycursor:
        print(x)
        
def parse_data(tablename, choice):
    sql = f"SELECT * FROM {tablename}"
    mycursor = mydb.cursor()
    mycursor.execute(sql)
    
    if choice == '2':
        data = {}
        for row in mycursor:
            data[row[0]] = {"Roll No":row[0], "Name":row[1], "Branch":row[2], "Section":row[3], "Phone No":row[4], "Blood Group":row[5], "Email":row[6], "Date of Birth":str(row[7])}
        
        download_json(data)
        print(f"Data saved to file successfully.")
    else:
        for row in mycursor:
            data = f"{row[0]},{row[1]},{row[2]},{row[3]},{row[4]},{row[5]},{row[6]},{str(row[7])}\n"
            download_csv(data)
        print(f"Data saved to file successfully.")

def download_csv(data):
    with open("SMS.csv", "at") as file:
        file.write(data)
            
def download_json(data):
    json_format = json.dumps(data, indent = 4)
    with open("SMS.json", "wt") as file:
        file.write(json_format)
           
def upload():
    while True:
        print("\n\n1: Download to CSV")
        print("2: Download to JSON")
        print("3: Get student details: ")
        print("4: Exit")
        choice = input("Your choice, should you choose to accept it: ")
        
        match choice:
            case "1":
                parse_data(input("Enter name of the table: "), choice)
            
            case "2":
                parse_data(input("Enter name of the table: "), choice)
            
            case "3":
                tablename, id = input("Enter Table Name and Roll number of Student: ").split()
                search_dbs(tablename, id.upper())
            
            case "4":
                print("This code will self-destruct in five seconds...\nThank you.")
                break
            
            case _:
                print("Choice failed")
        
        if choice > "4":
            break

mydb = mysql.connector.connect(
    host="localhost",
    user="anurag",
    password="mysql"
)

use_database("sms")
upload()