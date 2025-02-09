#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverseName(const std::string& name) {
    std::istringstream iss(name);
    std::vector<std::string> words;
    std::string word;

    // Split the name into words
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    std::reverse(words.begin(), words.end());

    // Combine the reversed words into a single string
    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        oss << words[i];
        if (i != words.size() - 1) {
            oss << " ";
        }
    }

    return oss.str();
}

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::string reversedName = reverseName(name);
    std::cout << "Reversed name: " << reversedName << std::endl;

    return 0;
}
