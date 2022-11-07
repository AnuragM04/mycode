
size = int(input("Enter pyramid size : "))

for i in range(0, size): 
    for j in range(i):
        print(" ", end="")
    for j in range(i, size):
        print("*", end="")
    for j in range(i, size-1):
        print("*", end="")
    print()
print(.rstrip())
for a in range(size, -1, -1):  
    for b in range(a):
        print(" ", end="")
    for b in range(a, size):
        print("*", end="")
    for b in range(a, size-1):
        print("*", end="")
    print()