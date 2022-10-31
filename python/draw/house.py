import turtle
line = turtle.Turtle()

# Roof
line.fillcolor("#964B00")
line.begin_fill()
line.forward(200)              
line.left(120)
line.forward(200)
line.left(120)
line.forward(200)
line.end_fill()

# House
line.fillcolor("#8B0000")
line.begin_fill()
line.left(30)
line.forward(200)
line.left(90)
line.forward(200)
line.left(90)
line.forward(200)
line.end_fill()

# Movement
line.penup()
line.forward(75)
line.left(90)
line.forward(100)
line.pendown()

# Window
line.fillcolor("#C0C0C0")
line.begin_fill()
line.circle(30)
line.left(90)
line.forward(60)
line.left(180)
line.forward(30)
line.left(90)
line.forward(30)
line.right(180)
line.forward(60)
line.left(180)
line.forward(30)
line.right(90)
line.forward(30)
line.left(180)
line.end_fill()

# Movement
line.penup()
line.forward(150)
line.pendown()

# Door

line.left(90)
line.forward(50)
line.right(90)
line.forward(125)
line.right(90)
line.forward(100)
line.right(90)

# Door Knob
line.fillcolor("#C0C0C0")
line.begin_fill()
line.forward(62)
line.penup()
line.right(90)
line.forward(25)
line.pendown()
line.circle(5)
line.penup()
line.left(180)
line.forward(25)
line.right(90)
line.pendown()
line.forward(63)
line.end_fill()

line.right(90)
line.forward(50)
line.end_fill()

# Movement
line.penup()
line.left(180)
line.forward(100)
line.right(90)
line.forward(50)
line.left(90)
line.pendown()

# Garage
line.fillcolor("#964B00")
line.begin_fill()
line.forward(250)
line.left(90)
line.forward(175)
line.left(90)
line.forward(25)
line.left(90)
line.forward(150)
line.right(90)
line.forward(200)
line.right(90)
line.forward(150)
line.left(90)
line.forward(25)
line.end_fill()

turtle.done()