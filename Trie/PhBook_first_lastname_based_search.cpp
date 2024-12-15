//Way1:

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<string> contacts;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string key, string contactInfo) {
        TrieNode* node = root;
        for (char ch : key) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->contacts.push_back(contactInfo);
    }

    vector<string> search(string key) {
        TrieNode* node = root;
        for (char ch : key) {
            if (node->children.find(ch) == node->children.end()) {
                return {}; // Empty vector if key not found
            }
            node = node->children[ch];
        }
        return node->contacts;
    }
};

class PhoneBook {
private:
    Trie firstNameTrie;
    Trie lastNameTrie;

public:
    void addContact(string firstName, string lastName, string contactInfo) {
        firstNameTrie.insert(firstName, contactInfo);
        lastNameTrie.insert(lastName, contactInfo);
    }

    vector<string> searchByFirstName(string firstName) {
        return firstNameTrie.search(firstName);
    }

    vector<string> searchByLastName(string lastName) {
        return lastNameTrie.search(lastName);
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.addContact("Alice", "Smith", "Alice Smith, 1234567890");
    phoneBook.addContact("Bob", "Johnson", "Bob Johnson, 0987654321");
    phoneBook.addContact("Charlie", "Brown", "Charlie Brown, 5555555555");

    vector<string> results = phoneBook.searchByFirstName("Alice");
    cout << "Search by first name 'Alice':" << endl;
    for (const string& result : results) {
        cout << result << endl;
    }

    results = phoneBook.searchByLastName("Brown");
    cout << "Search by last name 'Brown':" << endl;
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}





