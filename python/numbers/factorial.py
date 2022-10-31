import time

def facto(x):
    f = 1
    for i in range(1, x+1):
        f = f*i
    return f

def fact(num):
    if num == 0 or num == 1:
        return 1
    else:
        return num*fact(num-1)
    
x = int(input("Enter a number: "))

start = time.time()
factorial = fact(x)     
end = time.time()
print("Factorial recursively of ", x, "! = ", factorial, " in ", end-start)

start = time.time()
factorial = facto(x)     
end = time.time()
print("Factorial of ", x, "! = ", factorial, " in ", end-start)