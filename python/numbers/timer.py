import time
from threading import Timer


def test(count):
    if count == 0:
        return 
    count -= 1
    print(count)
    Timer(1, test, args = {count}).start()

x = int(input("enter a num: "))
 
test(x)    