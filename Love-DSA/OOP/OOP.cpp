#include <iostream>
using namespace std;

// Class to represent a complex number
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize a complex number
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    // Method to add two complex numbers
    Complex add(const Complex &c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }
    //using operator overloading 
    Complex operator +(Complex c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    // Method to display the complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

/*int main() {
    // Creating two complex numbers
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    // Adding the two complex numbers
    Complex c3 = c1.add(c2);
    Complex c4=c1+c2;
    // Displaying the result
    cout << "The sum of ";
    c1.display();
    cout << "and ";
    c2.display();
    cout << "is ";
    c3.display();

    return 0;
}*/
/*A static member (variable or function) in a class is shared among all instances of that class. 
 There is only one copy of a static member, shared by all instances of the class.
//Static members are called class member varible this is same for full class ans intance memeber varible(Non static) are different for differnet object.
A static member funtion can called without making object of class. They cannot access non-static data members or member functions directly. 
*/

/*
-Constructors are special member functions of a class that are executed when an object of that class is created. -They are used to initialize objects and allocate resources if necessary.
-Constructors have the same name as the class and do not have a return type, not even void.
-constructors solve the problem of intialization

Types of Constructors : 
-Default Constructor: A constructor that takes no arguments.
-Parameterized Constructor: A constructor that takes one or more arguments.
-Copy Constructor: A constructor that initializes an object using another object of the same class.
-if we don't make constructor then our complier make default constructr that don't have parameter and it define in object file not in source file(file in which we write code)
Constructor overloading : we declar multiple constructors with different parameters.

Note : 
If we don't make any constructer complier make two contructer :  default constructer and copy constructer 
If make any simple constructer than complire make one contructe copy constructer.
If we make both constructer copy and simple then complire doesn't make any constructer
complex c1(3,4)
complex c4=c1
*/

/*
A destructor is instance membet function of class, name is same as class but before name there is symbol : '~'
destructor can never be static 
it has no return type same as constructer
destructor takes no arguments (no overloading possible)
destructor run just before the object will destroy
*/

/*
Operator overloading :allows you to define custom behaviors for operators when they are used with user-defined classes
-If we want to perform any operation between two object than we can do with two method 
1> we can member funtion of it like we have to add two object of complex class so we made add funtion that takes object as argument of complex class tyep and return object of complex class type. 
- here we use funtion name as add so we call complex c3=c1.add(c2) can we make a funtion name as '+' so we can call like this c3=c1.+(c2)
- In c++ we can do this but we have to use operatoe keyword before the funtion name and we can do this for the valid c++ operator
2> using operator overloading , member function
        complex operator +(complex c)
        {
            return Complex(real + c.real, imag + c.imag);
        }
    unaty operator
        complex operator *()
        {
            complex temp;
            temp.real=-r;
            temp.image=-c;
            return temp;
        }
-we can call this like => c3=c1+c2 OR c3=c1.operator+(c2)
*/

/*
function is a special function that is declared within a class but is not a member of the class it define outside of class
-Friend functions have access to the private and protected members of the class as they are friends with.
-They are declared inside the class using the friend keyword.
*/
class BOX {
private:
    // Private members
    int x;
    int y;

public:
    BOX(int a,int b)
    {
        x=a;y=b;
    }
    // Friend function declaration
    friend int fun(BOX obj);
};

int fun(BOX b) {
    return b.x * b.y;  // Access private members
}
int main()
{
    BOX b1(3,5);
    cout<<"product is "<< fun(b1);
}


/*
Inheritance allows a class to inherit properties and behaviors (methods) from another class.
-The class that inherits is called the derived class or child class, and the class from which properties are inherited is called the base class or parent class.
Use of Inheritance:
-Code Reusability: Inheritance allows you to reuse existing code, reducing redundancy.
-Extensibility: You can add new features to existing classes without modifying them.
-Polymorphism: Inheritance enables polymorphism, where a base class reference can point to a derived class object.



Public members are accessible from anywhere in the program.
Private members are only accessible within the class they are defined.
Protected members are accessible within the class and by derived classes but not from outside.

-When you create an object of a derived class in C++, the constructor of the base class is called first, followed by the constructor of the derived class. If you create an object of class A directly, only the constructor of class A will be invoked. There are no derived class constructors involved in this case because the object is not of a derived class type.
-C++, when you have a parameterized constructor in the base class and a default (non-parameterized) constructor in the derived class, you need to ensure that the base class constructor is properly invoked.
-the destructor of a child class call before the parent class's destructer 
*/

class A {
public:
    // Parameterized constructor
    A(int x) 
    {
        cout << "Constructor of class A with parameter: " << x << endl;
    }
};

class B : public A {
public:
    // Default constructor
    // Explicitly call the parameterized constructor of A
    // B():A(3)
    // {
    //     cout << "Constructor of class B" << endl;
    // }
    int b;
    B(int x,int y):A(x)
    {
        b=y;
        cout << "Constructor of class B " <<b<< endl;
    }
};

int main() {
    B obj(2,3);  // Create an object of class B
    return 0;
}
