string =  input("Enter any string ")
string = string.lower()

slen = len(string)

print("The vowels in the string are at: ")
vowel = 0
consonant = 0
for i in range(0, slen):
    if (string[i] == 'a'):
        print("a:", i)
        vowel += 1
    elif (string[i] == 'e'):
        print("e:", i)
        vowel += 1
    elif (string[i] == 'i'):
        print("i:", i)
        vowel += 1
    elif (string[i] == 'o'):
        print("o:", i)
        vowel += 1
    elif (string[i] == 'u'):
        print("u:", i)
        vowel += 1
    else:
        consonant += 1
        continue
print("This string has ", vowel, " vowels ", consonant, " consonants.")
