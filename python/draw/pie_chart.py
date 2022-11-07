import turtle
import time

def get_data():
    data = {}
    print("Enter student data:")
    total = 0
    data["engineering"] = int(input("Engineering: "))
    total += data["engineering"]
    data["medicine"] = int(input("Medicine: "))
    total += data["medicine"]
    # data["accounting"] = int(input("Accounting: "))
    # total += data["accounting"]
    # data["business"] = int(input("Business: "))
    # total += data["business"]
    # data["teaching"] = int(input("Teaching: "))
    # total += data["teaching"]
    # data["diploma"] = int(input("Diploma: "))   
    # total += data["diploma"] 
    data["total"] = total 
    return data

def draw_pie_chart(data):
    pie_width = 200
    tur = turtle.Turtle()
    tur.speed(1)
    total = data["total"]
    colors = ["red", "blue", "violet", "yellow", "green", "pink", "brown"]
    col = 0
    tur.goto(pie_width/2, 0)
    tur.seth(90)
    for key in data:
        if key == "total":
            continue
        student = data[key]
        percentage = (student*100)/total
        angle = (student*360)/total
        tur.fillcolor(colors[col])
        pos = tur.pos()
        tur.begin_fill()
        tur.circle(pie_width/2, angle)
        tur.goto(0, 0)
        tur.setpos(pos)
        time.sleep(1)
        tur.end_fill() 
        col += 1   
    
data = get_data()
draw_pie_chart(data)
turtle.done()