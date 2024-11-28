void* malloc(size_t size) {
    // Allocate extra memory for metadata
    void* allocated_memory = system_malloc(size + sizeof(size_t));
    // Store size in the metadata
    *((size_t*)allocated_memory) = size;
    // Return the memory address just past the metadata
    return (void*)((size_t*)allocated_memory + 1);
}

void free(void* ptr) {
    if (ptr == NULL) return;
    // Get the address of the metadata
    size_t* metadata = (size_t*)ptr - 1;
    // Get the size from the metadata
    size_t size = *metadata;
    // Use the size to properly deallocate the memory
    system_free(metadata, size);
}
