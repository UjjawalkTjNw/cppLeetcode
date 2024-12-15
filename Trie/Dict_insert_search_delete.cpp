//Insertion and search in dictionary:
//-------------------------------------------------------


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
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
        }
        node->isEndOfWord = true;
    }

    // Function to search a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node != nullptr && node->isEndOfWord;
    }
};

int main() {
    Trie trie;
    
    trie.insert("hello");
    trie.insert("world");

    cout << boolalpha; // To print "true" or "false" instead of 1 or 0
    cout << "Search for 'hello': " << trie.search("hello") << endl;
    cout << "Search for 'world': " << trie.search("world") << endl;
    cout << "Search for 'helloworld': " << trie.search("helloworld") << endl;

    return 0;
}


//Deletion in dictionary:
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
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
        }
        node->isEndOfWord = true;
    }

    // Function to search a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node != nullptr && node->isEndOfWord;
    }

    // Function to delete a word from the Trie
    bool remove(TrieNode* node, string word, int depth = 0) {
        if (!node) {
            return false;
        }

        // If we've reached the end of the word
        if (depth == word.size()) {
            // If the word is present, mark it as not end of word
            if (node->isEndOfWord) {
                node->isEndOfWord = false;

                // If the node has no other children, return true to delete it
                return node->children.empty();
            }
            return false;
        }

        char ch = word[depth];
        TrieNode* childNode = node->children[ch];

        // Recursively delete the child
        bool shouldDeleteChild = remove(childNode, word, depth + 1);

        // If true, delete the mapping of the character from the node
        if (shouldDeleteChild) {
            node->children.erase(ch);

            // Return true if the current node has no children and is not end of word
            return node->children.empty() && !node->isEndOfWord;
        }

        return false;
    }

    // Helper function to call remove from the root
    void deleteWord(string word) {
        remove(root, word);
    }
};

int main() {
    Trie trie;
    
    // Insert words
    trie.insert("ab");
    trie.insert("aba");
    trie.insert("bab");
    trie.insert("b");
    trie.insert("abc");
    trie.insert("ab");

    // Perform deletion and search operations
    trie.deleteWord("ba"); // Attempt to delete "ba" (does not exist)
    trie.deleteWord("bab"); // Delete "bab"
    cout << boolalpha;
    cout << "Search for 'bab': " << trie.search("bab") << endl; // Should be false
    trie.deleteWord("abc"); // Delete "abc"
    cout << "Search for 'abc': " << trie.search("abc") << endl; // Should be false
    cout << "Search for 'ab': " << trie.search("ab") << endl;  // Should be true

    return 0;
}


/*dry run of delete code:

Step-by-Step Dry Run:
Initial Call: remove(root, "bab", 0)

node: Root node.

word: "bab".

depth: 0.

Check for Node:

Root node exists, continue.

Check Depth:

depth (0) is not equal to word.size() (3), continue.

Character ch:

ch = word[depth] = word[0] = 'b'.

childNode = node->children['b'].

Recursive Call: remove(childNode, "bab", 1)

node: Node corresponding to 'b'.

depth: 1.

Check for Node:

Node for 'b' exists, continue.

Check Depth:

depth (1) is not equal to word.size() (3), continue.

Character ch:

ch = word[depth] = word[1] = 'a'.

childNode = node->children['a'].

Recursive Call: remove(childNode, "bab", 2)

node: Node corresponding to 'a'.

depth: 2.

Check for Node:

Node for 'a' exists, continue.

Check Depth:

depth (2) is not equal to word.size() (3), continue.

Character ch:

ch = word[depth] = word[2] = 'b'.

childNode = node->children['b'].

Recursive Call: remove(childNode, "bab", 3)

node: Node corresponding to 'b'.

depth: 3.

Check for Node:

Node for 'b' exists, continue.

Check Depth:

depth (3) is equal to word.size() (3).

Check End of Word:

node->isEndOfWord is true.

Set node->isEndOfWord = false.

Check Children:

node->children.empty() is true.

Return true to delete the node.

Back to Previous Call (depth=2):

shouldDeleteChild: true.

ch: 'b'.

node->children.erase('b').

Check if node->children.empty() && !node->isEndOfWord.

Return true.

Back to Previous Call (depth=1):

shouldDeleteChild: true.

ch: 'a'.

node->children.erase('a').

Check if node->children.empty() && !node->isEndOfWord.

Return true.

Back to Previous Call (depth=0):

shouldDeleteChild: true.

ch: 'b'.

node->children.erase('b').

Check if node->children.empty() && !node->isEndOfWord.

Return false because there are other words starting with b in Trie.
*/
