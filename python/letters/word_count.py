sentence = input("Enter a String ")
count = 0

for i in sentence:
    if i == " ":
        count += 1

print("Number of words - ", count)