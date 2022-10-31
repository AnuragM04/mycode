import turtle

width = 1024
height = 576
sc = turtle.Screen()
sc.setup(width, height)

line = turtle.Turtle()
line.speed(1)
line.color("blue", "cyan")
line.begin_fill()
for i in range(0, 4):
    line.forward(100)
    line.left(90)

line.goto(50,50)
for i in range(0, 4):
    line.forward(100)
    line.left(90)
    
line.goto(150,50)
line.goto(100,0)

line.goto(100,100)
line.goto(150,150)

line.goto(50, 150)
line.goto(0,100)

line.end_fill()
turtle.done()