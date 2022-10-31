size = int(input("Enter pyramid size : "))

# for row in range(0, size):
#     rstr = ""
#     for sp in range(0, row):
#         rstr += "-"
#     for star in range(size - 2*row):
#         rstr += "*"
#     print(rstr)

    
for i in range(0, size):
    for j in range(i):
        print(" ", end="")
    for j in range(i, size):
        print("*", end="")
    for j in range(i, size-1):
        print("*", end="")
    print()
    

# for i in range(4):
#     for j in range(4-i):
#         print("#", end="")
#     print() 