
#include <iostream>
#include <string>
#include <sstream>

// Function to count 'is' based on the boolean flag
int countIs(const std::string &text, const std::string &word, bool separateWord) {
    int count = 0;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        if (separateWord) {
            if (token == word) {
                count++;
            }
        } else {
            if (token.length() == 4 && token.find(word) != std::string::npos) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::string text = "This is my island of love and it is meant for kids of 10 years.";
    std::string word = "is";
    std::cout << "Count of 'is' in 4-letter words: " << countIs(text, word, false) << std::endl;
    std::cout << "Count of 'is' as a separate word: " << countIs(text, word, true) << std::endl;
    return 0;
}





### Using `strcmp`:


#include <iostream>
#include <cstring>
#include <sstream>

// Function to count 'is' based on the boolean flag using strcmp
int countIsUsingStrcmp(const std::string &text, const std::string &word, bool separateWord) {
    int count = 0;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        if (separateWord) {
            if (strcmp(token.c_str(), word.c_str()) == 0) {
                count++;
            }
        } else {
            if (token.length() == 4 && token.find(word) != std::string::npos) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::string text = "This is my island of love and it is meant for kids of 10 years.";
    std::string word = "is";
    std::cout << "Count of 'is' in 4-letter words using strcmp: " << countIsUsingStrcmp(text, word, false) << std::endl;
    std::cout << "Count of 'is' as a separate word using strcmp: " << countIsUsingStrcmp(text, word, true) << std::endl;
    return 0;
}





### Using `hashmap`:

#include <iostream>
#include <unordered_map>
#include <sstream>

// Function to count 'is' based on the boolean flag using hashmap
int countIsUsingHashmap(const std::string &text, const std::string &word, bool separateWord) {
    int count = 0;
    std::unordered_map<std::string, int> wordCount;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        wordCount[token]++;
    }
    if (separateWord) {
        count = wordCount[word];
    } else {
        for (const auto &entry : wordCount) {
            if (entry.first.length() == 4 && entry.first.find(word) != std::string::npos) {
                count += entry.second;
            }
        }
    }
    return count;
}

int main() {
    std::string text = "This is my island of love and it is meant for kids of 10 years.";
    std::string word = "is";
    std::cout << "Count of 'is' in 4-letter words using hashmap: " << countIsUsingHashmap(text, word, false) << std::endl;
    std::cout << "Count of 'is' as a separate word using hashmap: " << countIsUsingHashmap(text, word, true) << std::endl;
    return 0;
}


