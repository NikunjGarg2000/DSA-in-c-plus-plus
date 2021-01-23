#include<iostream>
using namespace std;

// Compile Time Polymorphism
// function overloading
class FunctionOverloading {

    public:
    void fun () {
        cout << "I am a function with no arguments." << endl;
    }

    void fun (int i) {
        cout << "I am a function with int argument." << endl;
    }

    void fun (double d) {
        cout << "I am a function with double argument." << endl;
    }

};

// operator overloading
// solving complex number
class OperatorOverloading {

    private:
    int real, imag;

    public:
    OperatorOverloading() {}
    OperatorOverloading(int r, int i) {
        real = r;
        imag = i;
    }

    OperatorOverloading operator + (OperatorOverloading const &obj) {
        OperatorOverloading complex;
        complex.real = real + obj.real;
        complex.imag = imag + obj.imag;
        return complex;
    }

    void display() {
        cout << real << " + i" << imag;
    }

};

// Run Time Polymorphism
// virtual keyword
class Base {
    public:
    virtual void print() {
        cout << "This is base class's print function." << endl;
    }
    virtual void display() {
        cout << "This is base class's display function." << endl;
    }
};

class Derived : public Base {
    public:
    void print() {
        cout << "This is derived class's print function." << endl;
    }
    void display() {
        cout << "This is derived class's display function." << endl;
    }
};

int main() {

    // // function overloading
    // FunctionOverloading F;
    // F.fun();
    // F.fun(1);
    // F.fun(1.2);

    // // operator overloading
    OperatorOverloading a(3, 2), b(3,5);
    OperatorOverloading c = a + b;
    c.display();

    // virtual keyword
    // Base *baseptr;
    // Derived d;
    // baseptr = &d;

    // baseptr -> print();  // arr operator used since it's a pointer
    // baseptr -> display();
    
    return 0;
}