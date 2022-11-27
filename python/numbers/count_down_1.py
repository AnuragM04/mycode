import time
from threading import Timer

def countdown_timer(total_seconds):
    if total_seconds == 0:
        return
    seconds = total_seconds % 60
    minutes = int((total_seconds/60)) % 60
    hours = int(int(total_seconds/60) / 60) % 60
    print(f"{hours:02}: {minutes:02}: {seconds:02}", end="\r")
    Timer(1, countdown_timer, args = {total_seconds + 1}).start()


hrs = int(input("Hours: "))
min = int(input("Minutes: "))
sec = int(input("Seconds: "))

if hrs>23 or hrs<0:
    print("Invalid hours")
    exit(1)
if min>59 or min<0:
    print("Invalid minutes")
    exit(1)
if sec>59 or sec<0:
    print("Invalid seconds")
    exit(1)


t_sec = hrs*3600  + min*60 + sec
countdown_timer(t_sec)