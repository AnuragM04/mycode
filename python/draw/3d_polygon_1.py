import turtle

sides = int(input("Enter no.of Sides: "))
length = 20
line = turtle.Turtle()
line.speed(1)
line.color("blue", "cyan")
line.begin_fill()
vertices1 = []


for i in range(0, sides):
    vertices1.append(line.pos())
    line.forward(length)
    line.left(360/sides)

for pos in vertices1:
    line.pu()
    line.goto(pos)
    line.pd()
    line.left(45)    
    line.forward(70)
    line.back(70)
    line.right(45)
    
line.pu()
line.goto(50,50)
line.pd()
for i in range(0, sides):
    line.forward(length)
    line.left(360/sides)
    
# index = 0
# for pos in vertices1:
#     line.pu()
#     line.goto(pos)
#     line.pd()
    
#     index += 1

turtle.done()