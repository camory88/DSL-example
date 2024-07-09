#include <iostream>
#include <windows.h>

// Define a function pointer type for the function in the DLL
typedef void (*HelloWorldFunc)();

int main() {
    // Load the DLL
    HMODULE hModule = LoadLibrary(TEXT("App Dll.dll"));
    if (!hModule) {
        std::cerr << "Could not load the DLL" << std::endl;
        return 1;
    }

    // Get the function address
    HelloWorldFunc helloWorld = (HelloWorldFunc)GetProcAddress(hModule, "HelloWorld");
    if (!helloWorld) {
        std::cerr << "Could not find the function in the DLL" << std::endl;
        FreeLibrary(hModule);
        return 1;
    }

    // Call the function
    helloWorld();

    Sleep(10000);
    // Free the DLL module
    FreeLibrary(hModule);
    return 0;
}
