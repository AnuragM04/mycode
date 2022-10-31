
import turtle
import math


def draw_graph(line, width, height):
    label = -10
    width_interval = width/20
    height_interval = height/20
    line.speed(10)

    line.pu()
    line.goto(-width/2, 0)
    line.pd()
    line.forward(width)

    line.pu()
    line.goto(0, height/2)
    line.pd()
    line.right(90)
    line.forward(height)
    line.pu()
    line.goto(0,0)
    line.pd()

    line.pu()
    line.goto(-width/2, 0)
    line.left(90)
    line.pd()

    line.write(label)
    for i in range(0, 20):
        line.pu()
        line.forward(width_interval)
        line.pd()
        label = label + 1
        if label != 0:
            line.write(label)
        
    line.pu()
    line.goto(0, height/2)
    line.forward(5)
    line.right(90)
    line.pd()
    label = -10

    line.write(label)
    for i in range(0, 20):
        line.pu()
        line.forward(height_interval)
        line.pd()
        label = label + 1
        line.write(label)
    
def draw_linear(line, width, height, slope, yinc, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf):
        y = slope*x + yinc
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()

def draw_sin(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf, 6):
        y = 70*math.sin(x)
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()

def draw_cos(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf, 6):
        y = 70*math.cos(x)
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()
        
def draw_tan(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf, 6):
        y = 10*math.tan(x)
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()

def draw_log(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(1, xhalf):
        y = 40*math.log(x)
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()
        

def draw_square(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf):
        y = math.pow(x, 2)/40
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()
            
def draw_cube(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(-xhalf, xhalf):
        y = math.pow(x, 3)/400
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()
            
def draw_exp(line, width, height, color):
    line.pencolor(color)
    xhalf = int(width/2)
    yhalf = int(height/2)
    line.pu()
    for x in range(0, xhalf):
        y = math.exp(x)
        if y > -yhalf and y < yhalf:
            line.goto(x, y)
            line.pd()
            

width = 1024
height = 576
turtle.setup(width+40, height+40)
line = turtle.Turtle()
draw_graph(line, width, height) 
# draw_linear(line, width, height, 4, 100, "red")   
# draw_sin(line, width, height, "blue")
# draw_cos(line, width, height, "green")
# draw_tan(line, width, height, "#ffcc00")
# draw_log(line, width, height, "brown")
# draw_square(line, width, height, "red")
# draw_cube(line, width, height, "violet")
# draw_exp(line, width, height, "indigo")
turtle.done()
