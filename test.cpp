#include <iostream>
using namespace std;
// class Base {
// public:
//     virtual void show() {
//         std::cout << "Base class" << std::endl;
//     }
// };

// class Derived : public Base {
// public:
//     void show() override {
//         std::cout << "Derived class" << std::endl;
//     }
// };

int main() {

    //test 1
    Base* basePtr = new derivedPtr.();  // Base object, not Derived!
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr)
        derivedPtr->show();  // Safe call, only happens if the cast was valid
    else
        std::cout << "Invalid downcast" << std::endl;  // Safe handling



    // delete basePtr;
    // return 0;


    //test 2 : 
    // const int number = 5;
    // // Pointer to a const int
    // const int* ptr = &number; // this will be modified to 10 using const cat

    // // int* nonConstPtr = ptr; if we use this
    // // instead of without using const_cast
    // // we will get error of invalid conversion
    // int* nonConstPtr = const_cast<int*>(ptr);
    // *nonConstPtr = 10;
    // std::cout << "Modified number: " << *nonConstPtr << " "<< *ptr;
    // return 0;


    //test 3 :
    // int number = 40;
    // Store the address of number in numberPointer
    // int* numberPointer = &number;

    // // Reinterpreting the pointer as a char pointer
    // char* charPointer
    //     = reinterpret_cast<char*>(numberPointer);

    // // Printing the memory addresses and values
    // cout << "Integer Address: " << numberPointer << endl;
    // cout << "Char Address: "
    //      << reinterpret_cast<void*>(charPointer)  << endl;
    //‘charPointer’ reinterpret_cast<void*> is used to bypass the type-checking mechanism 
    //of C++ and allow the pointer to be printed as a generic memory address 
    //without any type-specific interpretation.

}
