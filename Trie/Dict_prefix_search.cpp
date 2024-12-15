#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int pc; // Prefix count

    TrieNode() {
        isEndOfWord = false;
        pc = 0;
    }
};

// Trie
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->pc++; // Increment prefix count for each character in the word
        }
        node->isEndOfWord = true;
    }

    // Function to search a prefix in the Trie
    int prefixSearch(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return 0; // Prefix not found
            }
            node = node->children[ch];
        }
        return node->pc; // Return the prefix count
    }
};

int main() {
    Trie trie;

    // Insert words
    trie.insert("abac");
    trie.insert("abaa");
    trie.insert("abab");
    trie.insert("aabb");
    trie.insert("aabc");

    // Perform prefix searches
    cout << "Prefix 'ab': " << trie.prefixSearch("ab") << endl;
    cout << "Prefix 'aba': " << trie.prefixSearch("aba") << endl;
    cout << "Prefix 'abaa': " << trie.prefixSearch("abaa") << endl;
    cout << "Prefix 'ac': " << trie.prefixSearch("ac") << endl;
    cout << "Prefix 'aa': " << trie.prefixSearch("aa") << endl;

    return 0;
}
