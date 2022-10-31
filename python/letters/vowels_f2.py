word = input("Please enter a string- ")
word = word.lower()
wlen = len(word)
vowel = 0
consonant = 0
x = 0
    
while x >= 0:
    x = word.find("a", x) #hello
    if x >= 0:
        x += 1
        vowel += 1
        print("a:", x) 
x = 0
while x >= 0:
    x = word.find("e", x)
    if x >= 0:
        x += 1
        vowel += 1
        print("e:", x)
x = 0
while x >= 0:
    x = word.find("i", x)
    if x >= 0:
        x += 1
        vowel += 1
        print("i:", x )
x = 0
while x >= 0:
    x = word.find("o", x)
    if x >= 0:
        x += 1
        vowel += 1
        print("o:", x)
x = 0
while x >= 0:
    x = word.find("u", x)
    if x >= 0:
        x += 1
        vowel += 1
        print("u:", x)
consonant = wlen - vowel