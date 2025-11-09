from db.db_mysql import db_mysql

# def add_student():
#     mydb = db_mysql("localhost", "anurag", "mysql")
#     mydb.connect()
#     mydb.insert_student()
    
# def remove_student():
#     mydb = db_mysql("localhost", "anurag", "mysql")
#     mydb.connect()
#     mydb.remove_student()
    
# def search_student():
#     mydb = db_mysql("localhost", "anurag", "mysql")
#     mydb.connect()
#     mydb.get_student()
    
def list_student():
    mydb = db_mysql("localhost", "sms", "anurag", "mysql")
    mydb.connect()
    students = mydb.get_all_students()
    for val in students:
        print(val)
    
print("STUDENT MANAGEMENT SYSTEM")
while True:
    print("1: Add student")
    print("2: Remove student")
    print("3: Search student")
    print("4: List students")
    print("5: Exit")
    choice = int(input("Enter your choice: "))

    match choice:
        # case 1:
        #     add_student()

        # case 2:
        #     remove_student()

        # case 3:
        #     search_student()

        case 4:
            list_student()

        case 5:
            print("Thank you")
            break

        case _:
            print("Enter valid choice")

    if choice > 5:
        break