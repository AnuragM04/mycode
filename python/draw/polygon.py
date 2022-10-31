import turtle

width = 1024
height = 576
sides = int(input("Enter no.of Sides: "))
length = 150

sc = turtle.Screen()
sc.setup(width, height)

line = turtle.Turtle()
line.speed(10)
line.pu()
line.goto(0, 200)
line.pd()
for i in range(0, sides):
    line.forward(length)
    line.right(360/sides)
    
turtle.done()