def get_employee_info():
    name = input("Enter employee name: ")
    id = input("Enter employee ID: ")
    
    day = int(input("Enter Birth day: "))
    if day > 31 or day <= 0:
        print("Invalid birth day")
        day = int(input("Please Re-enter: "))
        
    month = int(input("Enter Birth month: "))
    if month > 12 or month <= 0:
        print("Invalid birth month")
        month = int(input("Please Re-enter: "))        
        
    year = int(input("Enter Birth year: "))
    if 2023-year > 120 or year <= 0:
        print("Invalid birth year")
        year = int(input("Please Re-enter: ")) 
    
    salary = int(input("Enter employee salary: "))
    if salary <= 0:
        print("Invalid Salary")
        salary = int(input("Please Re-enter: "))
    
    employee_info = {}
    dob = "{}/{}/{}".format(day,month,year)
    employee_info["Name"] = name
    employee_info["Id"] = id
    employee_info["Dob"] = dob
    employee_info["Salary"] = salary
    
    return employee_info

def save_employee_info(employee):
    name = input("Enter employee name: ")
    file = open("c:/Users/ANURAG/Dev/mycode/python/Projects/employee_database.csv","a")
    if name == employee["Name"]:
        for value in employee.values(): 
            file.writelines("%s, " % (value))
    else:
        print("File not found")
    file.close()
    
def display_all():
    file = open("c:/Users/ANURAG/Dev/mycode/python/Projects/employee_database.csv", "r")
    print(file.read())
    file.close()
    
def display_employee_info():
    string = " "
    name = input("Enter the name of employee: ")
    file = open("c:/Users/ANURAG/Dev/mycode/python/Projects/employee_database.csv", "r")
    while string != "":
        string2 = file.readline()
        if name.lower() in string2.lower():
            print(string2)
        else:
            continue  

def remove_employee_data():
    string = ""
    string2 = " "
    name = input("Enter the name of employee: ")
    file = open("c:/Users/ANURAG/Dev/mycode/python/Projects/employee_database.csv", "r")
    while string2 != "":
        string2 = file.readline()
        if name.lower() in string2.lower():
            continue
        else:
            string = string + string2
                     
    file.close()
    file = open("c:/Users/ANURAG/Dev/mycode/python/Projects/employee_database.csv", "w")
    file.write(string)
    file.close()            

choice = 0
data = {}
while int(choice) <= 4:
    print("1. Add Employee data")
    print("2. Remove employee data")
    print("3. Display employee data")
    print("4. Exit")
    choice = input("Enter your choice: ")
    
    if choice == '1':
        data = get_employee_info()
        save_employee_info(data)
    elif choice == '2':
        remove_employee_data()
    elif choice == '3':
        display_employee_info()
    elif choice == '4':
        print("Exiting program.")
        break
    else:
        print("Invalid choice.")