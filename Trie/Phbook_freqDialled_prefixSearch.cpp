//The max heap maintain max at top, so if u need to two dialled it will give you those two that we achieve by using k in bwlow code


#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    string number;
    int prefixCount; // Add this property to store the prefix count
    

    TrieNode() {
        isEndOfWord = false;
        prefixCount = 0; // Initialize prefix count to 0
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string name, string number) {
        TrieNode* node = root;
        for (char ch : name) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->number = number;
    }

    string search(string name) {
        TrieNode* node = root;
        for (char ch : name) {
            if (node->children.find(ch) == node->children.end()) {
                return "Contact not found";
            }
            node = node->children[ch];
        }
        if (node != nullptr && node->isEndOfWord) {
            return node->number;
        }
        return "Contact not found";
    }
    int prefixSearch(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return 0; // Prefix not found
            }
            node = node->children[ch];
        }
        return node->prefixCount; // Return the prefix count
    }
};

class FrequentDialed {
private:
    unordered_map<string, int> dialCount;
    priority_queue<pair<int, string>> maxHeap;

public:
    void dial(string name) {
        dialCount[name]++;
        maxHeap.push({dialCount[name], name});
    }

    vector<string> getTopFrequentDialed(int k) {
        vector<string> topK;
        priority_queue<pair<int, string>> tempHeap = maxHeap;

        while (k-- > 0 && !tempHeap.empty()) {
            topK.push_back(tempHeap.top().second);
            tempHeap.pop();
        }
        return topK;
    }
};

int main() {
    Trie phoneBook;
    phoneBook.insert("Alice", "1234567890");
    phoneBook.insert("Bob", "0987654321");
    phoneBook.insert("Charlie", "5555555555");

    cout << "Searching for Bob's number: " << phoneBook.search("Bob") << endl;

    FrequentDialed freqDialed;
    freqDialed.dial("Alice");
    freqDialed.dial("Bob");
    freqDialed.dial("Alice");
    freqDialed.dial("Charlie");
    freqDialed.dial("Bob");
    freqDialed.dial("Alice");

    vector<string> topFrequent = freqDialed.getTopFrequentDialed(2);

    cout << "Top frequently dialed contacts:" << endl;
    for (string name : topFrequent) {
        cout << name << endl;
    }

    cout << "Number of contacts with prefix 'Ali': " << phoneBook.prefixSearch("Ali") << endl;
    cout << "Number of contacts with prefix 'Bo': " << phoneBook.prefixSearch("Bo") << endl;
    cout << "Number of contacts with prefix 'Ca': " << phoneBook.prefixSearch("Ca") << endl;


    return 0;
}


/*Dry run frequtly dialled part:
Steps for Dry Run with k = 2
Initialization:

We create an empty vector topK to store the top k frequent contacts.

We create a temporary heap tempHeap by copying maxHeap.

Initial State of tempHeap:

After all dials, maxHeap contains: [(3, "Alice"), (2, "Bob"), (1, "Charlie"), (2, "Alice")].

tempHeap is a copy of maxHeap.

First iteration of the while loop (k = 2):

Check if k > 0 and tempHeap is not empty. Both conditions are true.

Top of tempHeap: (3, "Alice").

Push "Alice" into topK.

Pop the top element (3, "Alice") from tempHeap.

State after first iteration:

topK: ["Alice"].

tempHeap: [(2, "Bob"), (2, "Alice"), (1, "Charlie")].

Decrease k to 1.

Second iteration of the while loop (k = 1):

Check if k > 0 and tempHeap is not empty. Both conditions are true.

Top of tempHeap: (2, "Bob").

Push "Bob" into topK.

Pop the top element (2, "Bob") from tempHeap.

State after second iteration:

topK: ["Alice", "Bob"].

tempHeap: [(2, "Alice"), (1, "Charlie")].

Decrease k to 0.

End of while loop:

The loop terminates because k is now 0.

Return: The function returns the topK vector, which contains ["Alice", "Bob"].



//After dial 5 of bob:
       2
     (Alice)
      /    \
    2        1
   (Bob)  (Charlie)
  /
 1
(Bob)


//after dial 6 of alice:
       3
     (Alice)
      /    \
    2        1
   (Bob)  (Charlie)
  /  \
2     1
(Alice) (Bob)

*/