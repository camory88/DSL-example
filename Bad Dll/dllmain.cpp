#include "dllmain.h"
#include <iostream>

void HackedFunction()
{
    std::cout << "Bad DLL Loaded :)" << std::endl;
}

void HelloWorld() {
    std::cout << "Hello from the DLL!" << std::endl;
    HackedFunction();
    HackedFunction();
    HackedFunction();
    HackedFunction();

}
