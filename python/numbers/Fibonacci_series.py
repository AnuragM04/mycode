num_1= 0
num_2= 1
print(num_1)
print(num_2)
for num in range(0, 20):
    fib = num_1 + num_2
    print(fib)
    num_1 = num_2
    num_2 = fib