from datetime import datetime

year = int(input("enter birth year = "))
month = int(input("enter birth month(in numbers) = "))
date = int(input("enter birth date = "))

dob_1 = datetime.now(year)
dob_2 = datetime.now(month)
dob_3 = datetime.now(date)

current_date = datetime.now()

age = current_date - (dob_1, dob_2, dob_3)

print("Age = ", age)