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
    //There are two cases either freelist is having no free block of memory or it has

    if (freeList == nullptr) { // Freelist points to head of list, so if it is empty that means free List is empty
        //means it does not have any free block
        block = (Block*)std::malloc(size + sizeof(Block)); // memory allocation, size +sizeof(block) done to 
        //accomodate meta data also: sizeof(block) for metadata, size for actual data
        block->size = size; //initialise size of block
        block->free = false; //mark block is not free(currently in use)
        block->next = nullptr; //Point next to null indicating this is only block and there is no other block 
        //in list yet
    } else {
        // FreeList has free block of memory
        Block* current = freeList;
        Block* previous = nullptr;
        while (current != nullptr && !(current->free && current->size >= size)) {
            //current iterates till it become null and it keep checking if that block is free 
            // and block size(current->size) is enough to accomodate requested memory size(size)
            previous = current;
            current = current->next;
        }
        //after while loop end , we have two cases
        //case1: free block of memory found
        //case 2: free block of memory is not found
        if (current != nullptr) { //case 1
            current->free = false; //mark block is not free(currently in use)
            block = current;
        } else { //case 2
            block = (Block*)std::malloc(size + sizeof(Block));
            block->size = size;
            block->free = false;
            block->next = nullptr;
            previous->next = block;
        }
    }
    return (void*)(block + 1);
    //here we wrote block+1 because:
    //block is a pointer to the beginning of the allocated memory block, which includes the Block metadata.
    //block + 1 increments the pointer by the size of one Block. This moves the pointer past the metadata to the 
    //actual user data portion of the memory block.

    //Since block is a pointer to Block, adding 1 to block advances the pointer by the size of one Block structure, 
    //effectively skipping over the metadata.
}

void my_free(void* ptr) {
    if (ptr == nullptr) return; //If ptr is nullptr, the function returns immediately and does nothing.

    Block* block = (Block*)ptr - 1; //(Block*)ptr casts the user data pointer to a Block* pointer.
    //Subtracting 1 from this pointer ((Block*)ptr - 1) moves the pointer back to the start of the Block metadata. 
    //This step is crucial because it accesses the metadata associated with the user data.
    block->free = true; //This indicates allocated block of memory is free

    // Coalescing(come together) adjacent free blocks (optional)
    //The purpose of coalescing free blocks is to reduce fragmentation by merging adjacent free blocks into a 
    //single larger block. This makes larger contiguous blocks of memory available for future allocations.
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
