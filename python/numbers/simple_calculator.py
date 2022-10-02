op = input('''Enter the type of operation
                  a - addition, s - subtraction, m - multiplication, d - division: ''')
num_1 = int(input("Number 1? "))
num_2 = int(input("Number 2? "))
result = 0
oper = " "
if op == "a" or op == "A":
    result = num_1 + num_2
    oper = "+"
elif op == "s" or op == "S":
    result = num_1 - num_2
    oper = "-"
elif op == "m" or op == "M":
    result = num_1 * num_2
    oper = "*"
elif op ==  "d" or op == "D":
    if num_2 == 0:
        print("num_1 cannot be divided by zero")
        exit(0)
    result = num_1 / num_2
    oper = "/"
else:
    print("invalid operator")
    exit(0)
print(num_1, oper, num_2, "=", result)