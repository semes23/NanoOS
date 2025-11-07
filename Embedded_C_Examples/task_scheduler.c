/*
 * Simple Task Scheduler
 * 
 * Demonstrates: Priority-based task scheduling (RTOS concept)
 * Relevance: RTOS like ITRON use similar scheduling in embedded systems
 * 
 * Author: [Your Name]
 * Purpose: Show understanding of real-time scheduling concepts
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 5

// Task states
typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_COMPLETED
} TaskState;

// Task structure
typedef struct {
    uint8_t id;
    uint8_t priority;      // 1 = highest, 5 = lowest
    TaskState state;
    char name[30];
} Task;

// Task list
Task task_list[MAX_TASKS];
uint8_t task_count = 0;

// Create a task
void create_task(uint8_t priority, const char* name) {
    if (task_count >= MAX_TASKS) {
        printf("[ERROR] Cannot create more tasks\n");
        return;
    }
    
    task_list[task_count].id = task_count;
    task_list[task_count].priority = priority;
    task_list[task_count].state = TASK_READY;
    snprintf(task_list[task_count].name, 30, "%s", name);
    
    printf("[CREATE] Task #%d: %s (Priority: %d)\n", 
           task_count, name, priority);
    task_count++;
}

// Find highest priority ready task
int8_t find_next_task(void) {
    int8_t next_task = -1;
    uint8_t highest_priority = 255;
    
    for (uint8_t i = 0; i < task_count; i++) {
        if (task_list[i].state == TASK_READY && 
            task_list[i].priority < highest_priority) {
            highest_priority = task_list[i].priority;
            next_task = i;
        }
    }
    
    return next_task;
}

// Execute a task
void execute_task(uint8_t task_id) {
    if (task_id >= task_count) return;
    
    Task *t = &task_list[task_id];
    
    printf("\n[RUNNING] Task #%d: %s (Priority: %d)\n", 
           t->id, t->name, t->priority);
    
    t->state = TASK_RUNNING;
    
    // Simulate task execution
    printf("          Executing...\n");
    
    t->state = TASK_COMPLETED;
    printf("          Completed!\n");
}

// Print scheduler status
void print_status(void) {
    printf("\n--- Scheduler Status ---\n");
    for (uint8_t i = 0; i < task_count; i++) {
        const char* state_str;
        switch (task_list[i].state) {
            case TASK_READY: state_str = "READY"; break;
            case TASK_RUNNING: state_str = "RUNNING"; break;
            case TASK_COMPLETED: state_str = "COMPLETED"; break;
            default: state_str = "UNKNOWN"; break;
        }
        
        printf("  Task #%d [%s] Priority:%d - %s\n", 
               task_list[i].id, state_str, 
               task_list[i].priority, task_list[i].name);
    }
    printf("------------------------\n");
}

int main(void) {
    printf("========================================\n");
    printf("Task Scheduler Demo (RTOS Concept)\n");
    printf("========================================\n\n");
    
    printf("Concept: Priority-based task scheduling\n");
    printf("Application: Real-Time OS (ITRON, FreeRTOS)\n");
    printf("Use Case: Automotive ECU with multiple tasks\n\n");
    
    // Create tasks with different priorities
    printf("[SETUP] Creating tasks...\n");
    create_task(1, "Emergency Brake Sensor");     // Highest priority
    create_task(3, "Engine Control Logic");       // Medium priority
    create_task(2, "Airbag Sensor Monitor");      // High priority
    create_task(5, "Dashboard Update");           // Low priority
    create_task(4, "Diagnostic Logger");          // Medium-low priority
    
    print_status();
    
    // Scheduling loop
    printf("\n[SCHEDULER] Starting task execution:\n");
    printf("=====================================\n");
    
    while (true) {
        int8_t next = find_next_task();
        
        if (next == -1) {
            printf("\n[SCHEDULER] All tasks completed!\n");
            break;
        }
        
        execute_task(next);
    }
    
    print_status();
    
    printf("\n[LEARNING] Key concepts demonstrated:\n");
    printf("  ✓ Priority-based scheduling (like RTOS)\n");
    printf("  ✓ Task state management\n");
    printf("  ✓ Scheduling algorithm implementation\n");
    printf("  ✓ Real-time system concepts\n");
    
    printf("\n[RELEVANCE] This is similar to:\n");
    printf("  - ITRON task scheduling\n");
    printf("  - FreeRTOS priority management\n");
    printf("  - Embedded real-time systems\n");
    
    return 0;
}