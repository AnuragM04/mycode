size = int(input("Enter pyramid size : "))

for row in range(0, size):
    rstr = ""
    for sp in range(size - row):
        rstr += " "
    for star in range(0, 2*row + 1):
        rstr += "*"
    print(rstr)