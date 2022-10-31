import turtle
turtle.pen(fillcolor="black", pencolor="red", pensize=10)
sorted(turtle.pen().items())

turtle.forward(100)


penstate=turtle.pen()
turtle.color("yellow", "")
turtle.penup()
sorted(turtle.pen().items())[:3]

turtle.pen(penstate, fillcolor="green")
sorted(turtle.pen().items())[:3]
turtle.done()