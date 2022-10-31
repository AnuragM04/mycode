import turtle

sides = int(input("Enter no.of Sides: "))
length = 50
line = turtle.Turtle()
line.speed(10)
line.color("blue", "cyan")
line.begin_fill()
vertices1 = []
vertices2 = []

for i in range(0, sides):
    vertices1.append(line.pos())
    line.forward(length)
    line.left(360/sides)
    
line.goto(50,50)
for i in range(0, sides):
    vertices2.append(line.pos())
    line.forward(length)
    line.left(360/sides)
    
index = 0
for pos in vertices1:
    line.pu()
    line.goto(pos)
    line.pd()
    line.goto(vertices2[index])
    index += 1

turtle.done()