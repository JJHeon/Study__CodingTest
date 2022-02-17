#include <iostream>

int main(int argc, char** argv) {
    int iz;

    std::cout << "Hello CMake!" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    std::cout << "Finished!" << std::endl;

    return 0;
}