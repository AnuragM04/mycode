name = input("What's your name? ")
age = int(input("What's your age? "))
school = input("What's your school? ")
if age >= 65:
    print(name + " you are " + str(age) + " years old, " + "studied at " + school)
    print("You're Ancient!")
    print("Stay fit")
elif age >18:
    print(name + " you are " + str(age) + " years old, " + "studying at " + school)
    print("You're an Adult!")
elif age == 18:
    print(name + " you are " + str(age) + " years old, " + "studying at " + school)
    print("You're an Adult!")
    print("Welcome rookie")
elif age >= 12:
    print(name + " you are " + str(age) + " years old, " + "studying at " + school)
    print("Your'e a Teenager")
elif age > 2:
    print("You're a Toddler!")
elif age >= 0:
    print("You're a Baby!")
    print("Drink pleanty of milk")