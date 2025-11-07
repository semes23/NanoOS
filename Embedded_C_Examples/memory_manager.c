/*
 * Simple Memory Manager for Embedded Systems
 * 
 * Demonstrates: Memory allocation in resource-constrained environments
 * Relevance: Embedded systems have limited RAM (32MB-192MB typical)
 * 
 * Author: [Your Name]
 * Purpose: Show understanding of embedded memory management concepts
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE 256  // Simulating limited embedded RAM

// Memory block structure
typedef struct {
    uint16_t size;
    bool is_allocated;
} MemoryBlock;

// Simulated embedded memory pool
uint8_t memory_pool[MEMORY_SIZE];
MemoryBlock memory_map[10];  // Simple memory tracking
uint8_t block_count = 0;

// Initialize memory manager
void init_memory(void) {
    block_count = 0;
    printf("[INIT] Memory Manager initialized: %d bytes available\n", MEMORY_SIZE);
}

// Allocate memory (like embedded malloc)
void* allocate_memory(uint16_t size) {
    if (block_count >= 10) {
        printf("[ERROR] Too many allocations\n");
        return NULL;
    }
    
    // Calculate total allocated
    uint16_t total_allocated = 0;
    for (uint8_t i = 0; i < block_count; i++) {
        if (memory_map[i].is_allocated) {
            total_allocated += memory_map[i].size;
        }
    }
    
    if (total_allocated + size > MEMORY_SIZE) {
        printf("[ERROR] Out of memory! Requested: %d bytes, Available: %d bytes\n", 
               size, MEMORY_SIZE - total_allocated);
        return NULL;
    }
    
    // Allocate
    memory_map[block_count].size = size;
    memory_map[block_count].is_allocated = true;
    
    printf("[ALLOC] Allocated %d bytes (Block #%d)\n", size, block_count);
    block_count++;
    
    return &memory_pool[total_allocated];
}

// Free memory
void free_memory(uint8_t block_id) {
    if (block_id < block_count && memory_map[block_id].is_allocated) {
        memory_map[block_id].is_allocated = false;
        printf("[FREE] Freed block #%d (%d bytes)\n", 
               block_id, memory_map[block_id].size);
    }
}

// Print memory status
void print_memory_status(void) {
    uint16_t allocated = 0;
    uint16_t free = MEMORY_SIZE;
    
    printf("\n--- Memory Status ---\n");
    for (uint8_t i = 0; i < block_count; i++) {
        if (memory_map[i].is_allocated) {
            allocated += memory_map[i].size;
            printf("  Block #%d: %d bytes [ALLOCATED]\n", i, memory_map[i].size);
        } else {
            printf("  Block #%d: %d bytes [FREE]\n", i, memory_map[i].size);
        }
    }
    
    free = MEMORY_SIZE - allocated;
    printf("\nTotal Memory: %d bytes\n", MEMORY_SIZE);
    printf("Allocated: %d bytes (%.1f%%)\n", allocated, (allocated * 100.0) / MEMORY_SIZE);
    printf("Free: %d bytes (%.1f%%)\n", free, (free * 100.0) / MEMORY_SIZE);
    printf("--------------------\n\n");
}

int main(void) {
    printf("========================================\n");
    printf("Embedded Memory Manager Demo\n");
    printf("========================================\n\n");
    
    printf("Concept: Managing limited RAM in microcontrollers\n");
    printf("Application: Automotive ECUs, Industrial Controllers\n\n");
    
    init_memory();
    
    // Simulate embedded system allocations
    printf("\n[SCENARIO] Simulating embedded system memory usage:\n\n");
    
    allocate_memory(64);   // Sensor data buffer
    allocate_memory(32);   // Communication buffer
    allocate_memory(128);  // Display buffer
    
    print_memory_status();
    
    // Free communication buffer
    free_memory(1);
    
    print_memory_status();
    
    // Try to allocate more than available
    printf("[TEST] Attempting to allocate 150 bytes (should fail):\n");
    allocate_memory(150);
    
    printf("\n[LEARNING] Key concepts demonstrated:\n");
    printf("  ✓ Memory allocation in constrained environments\n");
    printf("  ✓ Tracking memory usage\n");
    printf("  ✓ Handling out-of-memory conditions\n");
    printf("  ✓ Efficient resource management\n");
    
    return 0;
}