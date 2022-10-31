import turtle
line = turtle.Turtle()

line.pencolor("#ff0000")
line.fillcolor("#0000ff")
line.begin_fill()
line.left(70)
for i in range(5):
    line.forward(300)
    line.right(144)
line.end_fill()

turtle.done()