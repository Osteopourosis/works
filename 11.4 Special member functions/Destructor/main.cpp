// include the input/output library
#include <iostream>

// define a class named SomeClass
class SomeClass{

public:

    // define a constructor that takes an int parameter and initializes the id member variable with it
    SomeClass(int idinput) : id(idinput) {
        // print a message to the standard output stream indicating that an object with this id has been instantiated
        std::cout << "object with id " << id << " instantiated" << std::endl;
    }

    // define a destructor that prints a message to the standard output stream indicating that an object with this id is going out of scope
    ~SomeClass(){
        std::cout << "object with id " << id << " going out of scope" << std::endl;
    }

private:

    // declare a private member variable named id of type int
    int id;

};

// define a function named f that creates a local object of type SomeClass with id 1 and then returns
void f(){
    SomeClass s(1);
}

// define the main function that runs when the program starts
int main(){
    // create a local object of type SomeClass with id 2
    SomeClass s(2);

    // declare a pointer to an object of type SomeClass named sp
    SomeClass* sp;

    // allocate memory for an object of type SomeClass on the heap and assign its address to sp; pass 3 as the argument for the constructor
    sp = new SomeClass(3);

    // call the function f which creates another local object of type SomeClass with id 1 and then destroys it when it returns
    f();

    // deallocate the memory pointed by sp and invoke the destructor for the object with id 3
    delete sp;
}