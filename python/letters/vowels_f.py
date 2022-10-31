word = input("Please enter a string- ")
word = word.lower()
wlen = len(word)
vc = 0
cc = 0
sc = 0
space = 0
vowels = ["a", "e", "i", "o", "u"]
for i in range(0, 5):
    x = 0
    while x >= 0:
        x = word.find(vowels[i], x) #hello
        if x >= 0:
            x += 1
            vc += 1
            print(vowels[i], x) 
            
while space >= 0:
    space = word.find(" ", space)
    if space >= 0:
        space += 1
        sc += 1
cc = wlen - vc - sc
print("This string has ", vc, " vowels ", cc, " consonants ", sc, " spaces ")