#include<iostream>
using namespace std;

// class
class student {

    string name;
    // data members private by default (accessible only in the class)
    // to make it public so can be accessed in main function
    public:
    int age;
    bool gender;

    // default constructor
    student () {
        cout << "Default constructor" << endl;
    }

    // copy constructor
    student (student &a) {
        cout << "Copy constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }  

    // Parameterised constructor
    // constructor with one entry
    student(string s) {
        cout << "Parameterised constructor" << endl;
        name = s;
    }

    // Parameterised constructor
    // constructor with all entries
    student(string s, int a, bool g) {
        cout << "Parameterised constructor" << endl;
        name = s;
        age = a;
        gender = g;
    }
    
    // destructor called whenever our objects are destroyed here when we return from main function
    ~student() {
        cout << "Destructor called" << endl;
    }

    // to make use of private data members outside
    // setter
    void setName (string s) {
        name = s;
    }

    // getter
    void getName () {
        cout << name << endl;
    }

    // function inside the class, no need to pass any object
    void printInfo() {
        cout << "Name = ";
        cout << name << endl;
        cout << "Age = ";
        cout << age << endl;
        cout << "Gender = ";
        cout << gender << endl;
    }

    // operator overloading
    // assign something to a particular operator
    bool operator == (student &a) {
        if (name == a.name && age == a.age && gender == a.gender) {
            return true;
        }
        return false;
    }
};

int main() {

    // student arr[3];
    // for (int i = 0; i < 3; i++) {
    //     cout << "Name = ";\
    //     // shows error since name is private in the class
    //     // cin >> arr[i].name; 
    //     // another way to use private data members here
    //     string s;
    //     cin >> s;
    //     arr[i].setName(s);
    //     cout << "Age = ";
    //     cin >> arr[i].age;
    //     cout << "Gender = ";
    //     cin >> arr[i].gender;
    // }
    // for (int i = 0; i < 3; i++) {
    //     arr[i].printInfo();
    // }

    // default constructor
    // student a;

    // constructor with one entry
    // student a("Nikunj");
    // a.getName();
    // // output - Nikunj

    // constructor with all entries
    // student a("Nikunj", 20, 0);
    // a.printInfo();

    // // default copy constructor (we haven't made any copy constructor yet)
    // // "shallow copy" is done where pointers are copied but not their address
    // student a("Nikunj", 20, 0);
    // student b = a;
    // // or student b (a);
    // b.printInfo();

    // our copy constructor
    // "deep copy" is done where pointers and their addresses are both copied
    student a("Nikunj", 20, 0);
    student b = a;
    // or student b (a);
    b.printInfo();

    // operator overloading
    if (b == a) {
        cout << "Same" << endl;
    } else {
        cout << "Not same" << endl;
    }

    return 0;
}