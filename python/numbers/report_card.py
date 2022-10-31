

def get_student_info():
        student = {}
        print("Enter student details: ")
        student["name"] = input("Name: ")
        if len(student["name"]) == 0:
            return student
        student["maths1"] = int(input("Maths1: "))
        student["maths2"] = int(input("Maths2: "))
        student["physics"] = int(input("Physics: "))
        student["chemistry"] = int(input("Chemistry: "))
        student["english"] = int(input("English: "))
        student["sanskrit"] = int(input("Sanskrit: "))
        student["total"] = student["maths1"] + student["maths2"] + student["physics"] + student["chemistry"] + student["english"] + student["sanskrit"]
        student["percentage"] = (student["total"]/470)*100
        return student                   

def show_student_info():
    print("\n\n\n")
    details = ["Name", "Maths1", "Maths2", "Physics", "Chemistry", "English", "Sanskrit", "Total", "Percentage"]
    for prop in details:
        print("{0:^12}".format(prop), end="")
    print("\n")
    for k, v in students.items():
        for l in v.values():
            print("{0:^12}".format(l), end="")
        print("")

def get_all_student_info():
    while True:
        student = get_student_info()
        name = student["name"]
        if len(name) == 0:
            break
        else:
            students[name] = student
            
students = {}
get_all_student_info()
show_student_info()
 
