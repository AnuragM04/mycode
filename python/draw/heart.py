import turtle

width = 1024
height = 576
sc = turtle.Screen()
sc.setup(width, height)
heart = turtle.Turtle()
heart.speed(1)

heart.color("blue", "red")
heart.begin_fill()
heart.left(140)
heart.forward(180)
heart.circle(-90, 200)
heart.setheading(60)
heart.circle(-90, 200)
heart.forward(180)
heart.hideturtle()
heart.end_fill()

turtle.done()