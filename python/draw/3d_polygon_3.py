import turtle

sides = int(input("Enter no.of Sides: "))
length = 100
line = turtle.Turtle()
line.speed(1)
line.color("blue", "cyan")
line.begin_fill()
vertices1 = []


for i in range(0, sides):
    vertices1.append(line.pos())
    line.forward(length)
    line.left(360/sides)
    
line.pu()
line.goto(50,50)
line.pd()
for i in range(0, sides):
    pos = line.pos()
    line.pu()
    line.setpos(vertices1[i])
    line.pd()
    line.goto(pos)
    line.forward(length)
    line.left(360/sides)
    
# index = 0
# for pos in vertices1:
#     line.pu()
#     line.goto(pos)
#     line.pd()
    
#     index += 1

turtle.done()