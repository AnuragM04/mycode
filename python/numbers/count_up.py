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

t_sec = 1
countdown_timer(t_sec)