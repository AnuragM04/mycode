import turtle
draw = turtle.Turtle()
draw.speed(10)
colors = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"]
rainbow_width = 200
raingbow_gap = rainbow_width/7
draw.left(90)
for i in range(0, 7):
    color = colors[i]
    radius = rainbow_width - raingbow_gap*i
    draw.pu()
    draw.setpos(rainbow_width/2 - raingbow_gap*i, 0)
    draw.pd()
    draw.fillcolor(color)
    draw.begin_fill()
    draw.circle(radius, 180)
    draw.right(radius*2)
    draw.seth(90)
    draw.end_fill()

turtle.done()