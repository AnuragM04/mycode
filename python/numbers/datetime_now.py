import datetime
from threading import Timer
from time import sleep

def date_time_now():
    crnt_date_time = datetime.datetime.now()
    print(crnt_date_time.strftime("%d-%m-%Y %H:%M:%S"), end="\r")
    Timer(1, date_time_now).start()

date_time_now()
while True:
    sleep(10)