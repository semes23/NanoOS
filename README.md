# Multiprogramming Operating System

A two-phase C++ simulation of a multiprogramming operating system + embedded C examples demonstrating concepts for embedded systems development.

## Project Overview

**Main Project**: Multiprogramming OS simulation in C++  
**Additional**: Embedded C programming examples  
**Duration**: 4 months (Jan-May 2024)  
**Purpose**: Foundation for embedded systems career

## Contents

### 1. Operating System Simulation (C++)

#### Phase 1: Foundation (`Phase - 1/ph1.cpp`)
- Job execution management
- Basic memory allocation
- I/O handling
- Simple scheduling

#### Phase 2: Advanced (`Phase - 2/ph2.cpp`)
- Virtual memory with segmentation
- Error handling (TLE, LLE)
- Advanced scheduling
- Fault tolerance

### 2. Embedded C Examples (`Embedded_C_Examples/`)

Three simple C programs showing embedded concepts:
- **`memory_manager.c`** - Memory management in constrained environments
- **`task_scheduler.c`** - Priority-based scheduling (RTOS concept)
- **`bit_manipulation.c`** - Register control and bit operations

---

## Why This Matters for Embedded Systems

This project + examples demonstrate concepts used in embedded development:

| Concept | My Implementation | Real Embedded Use |
|---------|------------------|-------------------|
| **Memory Management** | Segmentation, allocation | Managing limited MCU RAM |
| **Task Scheduling** | Job scheduler | RTOS task management |
| **Error Handling** | TLE/LLE detection | Watchdog timers, fault recovery |
| **Bit Operations** | Register manipulation | GPIO control, peripheral config |

See **[EMBEDDED_RELEVANCE.md](EMBEDDED_RELEVANCE.md)** for detailed explanation.

---

## How to Run

### Operating System (C++)

**Phase 1**:
```bash
cd "Phase - 1"
g++ ph1.cpp -o ph1.exe
./ph1.exe
```

**Phase 2**:
```bash
cd "Phase - 2"
g++ ph2.cpp -o ph2.exe
./ph2.exe
```

### Embedded C Examples
```bash
cd Embedded_C_Examples

# Memory Manager
gcc memory_manager.c -o memory_manager
./memory_manager

# Task Scheduler
gcc task_scheduler.c -o task_scheduler
./task_scheduler

# Bit Manipulation
gcc bit_manipulation.c -o bit_manipulation
./bit_manipulation
```

---

## Skills Demonstrated

### Programming
✅ **C++** - System-level programming (OS simulation)  
✅ **C** - Embedded-focused examples  
✅ Memory management and optimization  
✅ Algorithm design and implementation  

### Concepts
✅ Operating system fundamentals  
✅ Resource-constrained programming  
✅ Real-time system concepts  
✅ Low-level bit manipulation  

### Approach
✅ Self-directed learning  
✅ Problem-solving ability  
✅ Progressive complexity (Phase 1 → Phase 2)  
✅ Documentation and clarity  

---

## Documentation

- **[EMBEDDED_RELEVANCE.md](EMBEDDED_RELEVANCE.md)** - Connection to embedded systems
- **[Embedded_C_Examples/README.md](Embedded_C_Examples/README.md)** - C programs guide
- **Phase - 1/Documentation - ph -1.docx** - Phase 1 details
- **Phase - 2/Documentation ph-2.pdf** - Phase 2 details
- **Documentation.pdf** - Overall documentation

---

## Career Direction

This project made me interested in **embedded software engineering**. I want to:
- Apply these concepts to real microcontrollers (NXP i.MX, Renesas)
- Learn RTOS development (ITRON)
- Develop drivers (I/O control, communication protocols)


**Current Status**: Strong foundation, ready to learn hardware platforms with guidance

---

## Author

[Tanya Jain]  



## **FINAL PROJECT STRUCTURE**
```
MULTIPROGRAMMING/
├── Phase - 1/
│   ├── ph1.cpp
│   ├── input_Phase1.txt
│   ├── output.txt
│   └── Documentation - ph -1.docx
│
├── Phase - 2/
│   ├── ph2.cpp
│   ├── input_phase2.txt
│   ├── output_phase2.txt
│   └── Documentation ph-2.pdf
│
├── Embedded_C_Examples/              
│   ├── memory_manager.c              
│   ├── task_scheduler.c              
│   ├── bit_manipulation.c            
│   └── README.md                    
│
├── README.md                         
├── EMBEDDED_RELEVANCE.md             
├── Documentation.pdf
└── LICENSE