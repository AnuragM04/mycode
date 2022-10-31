
lst = [3, 7, 2, 10, 8, 5, 3, 1]
      #0, 1, 2, 3
x = 0
for x in range(x, len(lst)):
    for y in range(x+1, len(lst)):
        if lst[x] > lst[y]:
            temp = lst[x]
            lst[x] = lst[y]
            lst[y] = temp
        print(lst)

print("Now using while loop:")
a = 0
while a < len(lst):
    b = a+1
    while b < len(lst):
        if lst[a] > lst[b]:
            tempo = lst[a]
            lst[a] = lst[b]
            lst[b] = tempo
        b = b+1
    a = a+1
    print(lst)
print(lst)