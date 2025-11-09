name = input("\nEnter the name of search file: ")
file_name = "C:/Users/ANURAG/Dev/mycode/python/Projects/Char_search/%s" % (name)
file = open(file_name, "rb")
char1 = input("Enter the character to search in File: ")

count = 1
while True:
    char2 = file.readline()
    if char2 == b'':
        print("File has reached EOF")
        break
    elif char1 in str(char2):
        print("Character - '%s' is found at line - %d" % (char1, count))
        print("Character found in line: \"%s\"" % (char2))
    count += 1