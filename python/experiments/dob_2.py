from datetime import datetime, timedelta

yr,mont,dy= map(int,input("Enter year ,month ,day separated by spaces = ").split())

gvn_DOB=datetime(yr, mont, dy)

current_date = datetime.today()

age_in_days = current_date - gvn_DOB

print("The age in days and time for the Given DOB = ", age_in_days)