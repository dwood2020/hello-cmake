#include <iostream>
#include "HelloClass.h"

#include "iup/iup.h"


int main(int argc, char** argv) {

    std::cout << "Hello, CMake!" << std::endl;

    // Use the 'hello'-library.
    HelloClass h;
    h.SayHello();

    // now we say hello from IUP
    IupOpen(&argc, &argv);
    IupMessage("Hello IUP", "Hello World from IUP!! :)");
    IupClose();

    return 0;
}
