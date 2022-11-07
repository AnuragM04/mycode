
def pyramid(size, inverse):
    increment = 1
    start = 0 
    end = size
    if inverse == True:
        increment = -1
        start = size
        end = 0
    for a in range(start, end, increment):
        for y in range(a):
            print(" ", end="")
        for y in range(a, size):
            print("*", end="")
        for y in range(a, size-1):
            print("*", end="")
        print()
  
# for i in range(0, size): 
#     for j in range(i):
#         print(" ", end="")
#     for j in range(i, size):
#         print("*", end="")
#     for j in range(i, size-1):
#         print("*", end="")
#     print()
size = int(input("Enter pyramid size : "))
pyramid(size, False)
pyramid(size, True)