# 22. Write a program to take different percentages from user and draw them as pie chart

import turtle
import random

def get_data():
    data = {}
    print("Enter student data:")
    total = 0
    data["engineering"] = int(input("Engineering: "))
    total += data["engineering"]
    data["medicine"] = int(input("Medicine: "))
    total += data["medicine"]
    data["accounting"] = int(input("Accounting: "))
    total += data["accounting"]
    data["business"] = int(input("Business: "))
    total += data["business"]
    data["teaching"] = int(input("Teaching: "))
    total += data["teaching"]
    data["diploma"] = int(input("Diploma: "))   
    total += data["diploma"] 
    data["total"] = total 
    return data

def draw_pie_chart(data):
    pie_width = 400
    turtle.colormode(255)
    tur = turtle.Turtle()
    tur.speed(1)
    total = data["total"]
    # colors = ["red", "blue", "violet", "yellow", "green", "pink", "brown"]
    # col = 0
    tur.goto(pie_width/2, 0)
    pos = tur.pos()
    tur.seth(90)
    for key in data:
        if key == "total":
            continue
        tur.fillcolor(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
        # tur.fillcolor(colors[col])
        student = data[key]
        percentage = (student*100)/total
        angle = (student*360)/total
        tur.begin_fill()
        tur.setpos(pos)
        tur.circle(pie_width/2, angle)
        pos = tur.pos()
        tur.goto(0, 0)
        tur.end_fill() 
        # col += 1 
    tur.hideturtle()

data = get_data()
draw_pie_chart(data)

turtle.done()