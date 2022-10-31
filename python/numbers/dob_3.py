import datetime
from dateutil import relativedelta

yr = int(input("enter birth year = "))
mon = int(input("enter birth month(in numbers) = "))
day = int(input("enter birth date = "))
current_date = datetime.datetime.now()
if (yr > current_date.year) or (yr < 1900):
    print("Enter a valid year")
    exit(0)
if (mon > 12) or (mon < 1):
    print("Enter a valid month")
    exit(0)
if (day > 31) or (day < 1):
    print("Enter a valid date")
    exit(0)
dob = datetime.datetime(yr, mon, day)
if current_date < dob:
    print("Enter a valid date of birth")
    exit(0)
delta1 = current_date - dob
#delta = relativedelta.relativedelta(current_date, dob)
#print("Age = ", delta.year, " years ", delta.month, " months ", delta.days, " days")
print("Age = ", delta1.days, " days old ")