#include <iostream>

struct Block {
    size_t size;
    Block* next;
};

Block* free_list_head = nullptr;

void* my_malloc(size_t size) {
    Block* current = free_list_head;
    Block* prev = nullptr;

    while (current != nullptr) {
        if (current->size >= size) {
            // Found a suitable block
            if (current->size - size >= sizeof(Block)) {
                // Split the block if there's enough space for a new block header
                Block* new_block = (Block*)((char*)current + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->next = current->next;
                current->size = size;
                current->next = new_block;
            }

            if (prev   == nullptr) {
                free_list_head = current->next;
            } else {
                prev->next = current->next;
            }

            return (void*)((char*)current + sizeof(Block));
        }

        prev = current;
        current = current->next;
    }

    // No suitable block found, request more memory from the system
    // (e.g., using sbrk)
    // ... (implementation for requesting more memory)
}

void my_free(void* ptr) {
    // Convert the pointer to a Block*
    Block* block = (Block*)((char*)ptr - sizeof(Block));

    // Find the block in the free list
    Block* prev = nullptr;
    Block* current = free_list_head;
    while (current != nullptr && current < block) {
        prev = current;
        current = current->next;
    }

    // Coalesce with previous free block
    if (prev != nullptr && prev->next == block) {
        prev->size += block->size;
        block = prev;
    }

    // Coalesce with next free block
    if (block->next != nullptr && (char*)block + block->size == (char*)block->next) {
        block->size += block->next->size;
        block->next = block->next->next;
    }

    // Insert the block into the free list
    block->next = current;
    if (prev == nullptr) {
        free_list_head = block;
    } else {
        prev->next = block;
    }
}