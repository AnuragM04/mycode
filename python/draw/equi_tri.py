import turtle
line = turtle.Turtle()
line.pencolor("#ff0000")
line.fillcolor("#ff0000")
line.begin_fill()

#   or we can use this 
#   line.forward(200)              
#   line.left(120)
#   line.forward(200)
#   line.left(120)
#   line.forward(200)

line.left(60)             
line.forward(200)
line.right(120)
line.forward(200)
line.right(120)
line.forward(200)

line.end_fill()
turtle.done()