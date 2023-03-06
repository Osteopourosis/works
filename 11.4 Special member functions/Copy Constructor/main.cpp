#include <iostream> // include a header file that provides input/output functionality

class SomeClass{ // define a class called SomeClass

public: // declare public members of the class

    SomeClass(int idinput) : id(idinput) { // define a constructor that takes an int parameter and initializes the id attribute with it
        std::cout << "object with id " << id << " instantiated (constructor)" << std::endl; // print a message to the standard output stream
    }

    // define a copy constructor that takes a const reference to an object of the same class and copies its id attribute
    SomeClass(const SomeClass& ins) : id(ins.id) {
        std::cout << "object with id " << id << " instantiated (copy constructor)" << std::endl; // print a message to the standard output stream
    }

    int get_id() const { // define a getter method that returns the value of the id attribute
        return id;
    }

private: // declare private members of the class

    int id; // declare an int attribute called id

};

// define a function that takes an object of SomeClass by value and prints "f1"
void f1(SomeClass s){
    std::cout << "f1" << std::endl;
}

// define a function that takes an object of SomeClass by reference and prints "f2"
void f2(const SomeClass& s){
    std::cout << "f2" << std::endl;
}

int main(){ // define the main function where the program starts execution
    SomeClass s1(1); // create an object of SomeClass using the constructor with 1 as its argument

    SomeClass s2(s1); // create another object of SomeClass using the copy constructor with s1 as its argument

    f1(s1); // call f1 with s1 as its argument
    f2(s1); // call f2 with s1 as its argument

    std::cout << "s1: " << s1.get_id() << std::endl; // print "s1: " followed by s1's id value
    std::cout << "s2: " << s2.get_id() << std::endl; // print "s2: " followed by s2's id value
}