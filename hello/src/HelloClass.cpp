#include "HelloClass.h"
#include <iostream>


HelloClass::HelloClass() { }


HelloClass::~HelloClass() { }


void HelloClass::SayHello(void) const {
    std::cout << "Hello from HelloClass instance!!!" << std::endl;
}