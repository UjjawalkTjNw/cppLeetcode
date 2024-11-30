#include <iostream>
#include <cstdlib>
#include <cstring>

struct Block {
    size_t size;
    bool free;
    Block* next;
};

Block* freeList = nullptr;

void* my_malloc(size_t size) {
    Block* block;
    if (freeList == nullptr) {
        block = (Block*)std::malloc(size + sizeof(Block));
        block->size = size;
        block->free = false;
        block->next = nullptr;
    } else {
        // Find a free block
        Block* current = freeList;
        Block* previous = nullptr;
        while (current != nullptr && !(current->free && current->size >= size)) {
            previous = current;
            current = current->next;
        }
        if (current != nullptr) {
            current->free = false;
            block = current;
        } else {
            block = (Block*)std::malloc(size + sizeof(Block));
            block->size = size;
            block->free = false;
            block->next = nullptr;
            previous->next = block;
        }
    }
    return (void*)(block + 1);
}

void my_free(void* ptr) {
    if (ptr == nullptr) return;

    Block* block = (Block*)ptr - 1;
    block->free = true;

    // Coalescing adjacent free blocks (optional)
    Block* current = freeList;
    while (current != nullptr) {
        if (current->free && current->next != nullptr && current->next->free) {
            current->size += current->next->size + sizeof(Block);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

int main() {
    int* ptr = (int*)my_malloc(10 * sizeof(int));
    std::strcpy((char*)ptr, "Hello");
    std::cout << (char*)ptr << std::endl;
    my_free(ptr);
    return 0;
}
