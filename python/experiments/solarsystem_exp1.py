import turtle
import math

def move_orbit(tur, radius, angle, draw_orbit):
    y = math.sin(angle)*radius
    x = math.cos(angle)*radius
    if draw_orbit == True:
        tur.pd()
    else:
        tur.pu()
    tur.setpos(x, y)
    tur.pd()    
    
def draw_orbit(tur, orbit, color):
    tur.pu()
    tur.setpos(0, -orbit) 
    tur.pd()
    tur.color(color)  
    tur.circle(orbit)
    
def get_orbit_course(tur, radius, x):
    y = math.sqrt(radius**2 - x**2)
    return y     

def get_orbit_course_xpos(radius, angle):
    y = math.sin(angle)*radius
    return y
    
def get_orbit_course_ypos(radius, angle):
    x = math.cos(angle)*radius
    return x

   
# creating the screen
width = 1024
height = 576

sc = turtle.Screen()
  
# setup the screen size
sc.setup(width, height)
  
# set the background color
sc.bgcolor("black")
tur = turtle.Turtle()
tur.speed(10)
# add the sun
# sunwidth = 100
# tur.pu()
# tur.setpos(0,-sunwidth)  
# tur.pd()
# tur.color("red", "yellow")
# tur.begin_fill()
# tur.circle(sunwidth) 
# tur.end_fill()

# add the orbital lines

# draw_orbit(tur, 150, "red") 
# draw_orbit(tur, 200, "orange")
# draw_orbit(tur, 250, "green")
# draw_orbit(tur, 300, "blue")
# draw_orbit(tur, 350, "pink")
# draw_orbit(tur, 400, "white")
# draw_orbit(tur, 450, "purple")
# draw_orbit(tur, 500, "indigo")

# for x in range(-200, 200):
#     y = get_orbit_course(tur, 200, x)
#     tur.color("yellow")
#     tur.goto(x, y)

# for x in range(-200, 200):
#     y = get_orbit_course(tur, 200, x)
#     tur.color("yellow")
#     tur.goto(-x, -y)
  
for angle in range(0, 360):
    x = get_orbit_course_xpos(200, math.radians(angle))
    y = get_orbit_course_ypos(200, math.radians(angle))
    tur.color("yellow")
    tur.goto(x,y)
    
    
turtle.done()