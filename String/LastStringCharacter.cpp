//Method1: Iteration
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    char lastChar = *(str.end() - 1);
    std::cout << "The last character is: " << lastChar << std::endl;
    return 0;
}


//Method2: Using back() method
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    char lastChar = str.back();
    std::cout << "The last character is: " << lastChar << std::endl;
    return 0;
}


//Method3: Indexing
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    char lastChar = str[str.length() - 1];
    std::cout << "The last character is: " << lastChar << std::endl;
    return 0;
}
