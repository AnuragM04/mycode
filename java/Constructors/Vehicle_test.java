class Vehicle
{
    private int v_wheels;
    private int v_doors;
    private float v_power;
    private int v_cylinders;
    private int v_seats;
    private String v_make;
    private String v_fuel;
 
    public Vehicle() {
        System.out.println("Vehicle Default Constructor");
        v_wheels = 1;
        v_doors = 0;
        v_power = 0;
        v_cylinders = 0;
        v_seats = 1;
        v_make = "Unknown";
        v_fuel = "Petrol";
    }

    public Vehicle(String make, int wheels, int doors, float power, int cylinders, int seats, String fuel) {
        System.out.println("Vehicle Custom Constructor");
        v_wheels = wheels;
        v_doors = doors;
        v_power = power;
        v_cylinders = cylinders;
        v_seats = seats;
        v_make = make;
        v_fuel = fuel;
    }

    public Vehicle(String make, int wheels, int doors, String fuel) {
        System.out.println("Vehicle Custom Constructor");
        v_wheels = wheels;
        v_doors = doors;
        v_make = make;
        v_fuel = fuel;
    }

    public int get_wheels() {
        return v_wheels;
    }
    public void set_wheels(int w) {
        v_wheels = w;
    }
    
    public int get_doors() {
        return v_wheels;
    }
    public void set_doors(int d) {
        v_doors = d;
    }
    
    public float get_power() {
        return v_power;
    }
    public void set_power(float p) {
        v_power = p;
    }
    
    public int get_cylinders() {
        return v_cylinders;
    }
    public void set_cylinders(int c) {
        v_cylinders = c;
    }
    
    public int get_seats() {
        return v_seats;
    }
    public void set_seats(int s) {
        v_seats = s;
    }
    
    public String get_make() {
        return v_make;
    }
    public void set_make(String m) {
        v_make = m;
    }

    public void show_details() {
        System.out.println("Vehicle Details: ");
        System.out.println("Make: " + v_make);
        System.out.println("Cylinders: " + v_cylinders);
        System.out.println("Power: " + v_power);
        System.out.println("Doors: " + v_doors);
        System.out.println("Seats: " + v_seats);
    }
}

class Car extends Vehicle
{
    private int c_airbags;

    public Car() {
        System.out.println("Car Default Constructor");
        c_airbags = 1;
    }

    public Car(int airbags) {
        System.out.println("Car Custom Constructor");
        c_airbags = airbags;
    }

    public Car(String make, int wheels, int doors, float power, int cylinders, int seats, String fuel, int airbags) {
        super(make, wheels, doors, power, cylinders, seats, fuel);
        c_airbags = airbags;
    }

    public Car(String make, int wheels, int doors, String fuel, int airbags) {
        super(make, wheels, doors, fuel);
        c_airbags = airbags;
    }

    public int get_airbags() {
        return c_airbags;
    }
    public void set_airbags(int a) {
        c_airbags = a;
    }

    public void show_details() {
        super.show_details();
        System.out.println("Airbags: " + c_airbags);
    }
    public void increase_power() {
        // power = power+10; this isnt going to work as power is private in base class.
        float power = get_power();
        set_power(power+10);
    }
}

class Bus extends Vehicle
{
    private boolean b_entertainment;

    public Bus() {
        System.out.println("Bus Default Constructor");
        b_entertainment = false;
    }
    public Bus(boolean entertainment) {
        System.out.println("Bus Custom Constructor");
        b_entertainment = entertainment;
    }

    public boolean get_entertainment() {
        return b_entertainment;
    }
    public void set_entertainment(boolean e) {
        b_entertainment = e;
    }
    public void show_details() {
        super.show_details();
        System.out.println("Entertainment: " + b_entertainment);
    }
}

class Truck extends Vehicle
{
    private float t_load;

    public Truck() {
        System.out.println("Truck Default Constructor");
        t_load = 1;
    }
    public Truck(float load) {
        System.out.println("Truck Custom Constructor");
        t_load = load;
    }

    public float get_load() {
        return t_load;
    }
    public void set_load(float l) {
        t_load = l;
    }
    public void show_details() {
        super.show_details();
        System.out.println("Load: " + t_load);
    }
}

public class Vehicle_test
{
    void test_vehicle() {
        Vehicle v1 = new Vehicle();
        v1.show_details();
        v1.set_make("BMW");
        v1.set_cylinders(6);
        v1.set_power(350);
        v1.set_doors(2);
        v1.set_wheels(4);
        v1.set_seats(2);        
        v1.show_details();

        Vehicle v2 = new Vehicle("Audi", 4, 4, 250, 6, 4, "Petrol");
        v2.show_details();

        v1 = v2;
        v1.show_details();
    }
    
    void test_cars() {
        Car c1 = new Car();
        c1.show_details();
        Car c2 = new Car(5);
        c2.show_details();


        c1.set_airbags(6);
        c1.set_doors(5);
        c1.set_cylinders(12);
        c1.set_power(500);
        c1.set_seats(4);
        c1.set_wheels(4);
        c1.set_make("Ferrari");
        c1.show_details();
        c1.increase_power();
        c1.show_details();

        Car c3 = new Car("Benz", 4, 4, 450, 6, 4, "Methanol", 4);
        c3.show_details();
        Car c4 = new Car("Lexus", 4, 4, "Diesel", 4);
        c4.show_details();
    }
    
    void test_bus() {
        Bus b1 = new Bus();
        b1.set_doors(1);
        b1.set_cylinders(8);
        b1.set_power(500);
        b1.set_seats(50);
        b1.set_wheels(6);
        b1.set_make("AMG");
        b1.set_entertainment(true);
        b1.show_details();
    }
    
    void test_truck() {
        Truck t1 = new Truck();
        t1.set_load(1000);
        t1.show_details();
    }
    
    public static void main(String[] args)
    {
        Vehicle_test vt = new Vehicle_test();
        // vt.test_vehicle();
        vt.test_cars();
        // vt.test_bus();
    }
}