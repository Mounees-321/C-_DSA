#include <iostream>
#include <cstdlib>  // For system function

int main() {
    std::cout << "Running Python script from C++..." << std::endl;
    
    // Replace "python_script.py" with the path to your Python script
    system("python3 python_script.py");

    std::cout << "Python script execution complete." << std::endl;
    
    return 0;
}
