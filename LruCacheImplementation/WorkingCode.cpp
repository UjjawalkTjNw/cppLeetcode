#include <iostream>
#include <unordered_map>

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node* node = map[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (map.size() == capacity) {
                Node* node = tail->prev;
                map.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            map[key] = node;
            insertAfterHead(node);
        }
    }
};

int main() {
    LRUCache lruCache(4);
    
    lruCache.put(2, 6);
    lruCache.put(4, 7);
    lruCache.put(8, 11);
    lruCache.put(7,10);
    std::cout << lruCache.get(2) << std::endl; // Output: 6
    std::cout << lruCache.get(8) << std::endl; // Output: 11
    lruCache.put(5, 6);
    std::cout << lruCache.get(4) << std::endl; //output -1 becos(4,7) got evicted
    std::cout << lruCache.get(7) << std::endl; // Output 10
    lruCache.put(5, 7);
    std::cout << lruCache.get(5) << std::endl; // Output: 7

    return 0;
}
