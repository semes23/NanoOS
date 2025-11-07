/*
 * Bit Manipulation for Embedded Systems
 * 
 * Demonstrates: Bit-level operations used in embedded programming
 * Relevance: Register manipulation, flag management, communication protocols
 * 
 * Author: [Your Name]
 * Purpose: Show understanding of low-level embedded programming
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Bit manipulation macros (commonly used in embedded C)
#define SET_BIT(reg, bit)       ((reg) |= (1U << (bit)))
#define CLEAR_BIT(reg, bit)     ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit)    ((reg) ^= (1U << (bit)))
#define READ_BIT(reg, bit)      (((reg) >> (bit)) & 1U)

// Print binary representation
void print_binary(uint8_t value) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 4) printf(" ");  // Space for readability
    }
}

// Print register with bit positions
void print_register(uint8_t value, const char* label) {
    printf("%s: ", label);
    print_binary(value);
    printf(" (0x%02X, %d)\n", value, value);
}

int main(void) {
    printf("========================================\n");
    printf("Bit Manipulation for Embedded Systems\n");
    printf("========================================\n\n");
    
    printf("Concept: Bit-level operations for register control\n");
    printf("Application: Microcontroller programming, driver development\n\n");
    
    // Example 1: Control Register Simulation
    printf("[EXAMPLE 1] Simulating Control Register\n");
    printf("Bit 7-4: Reserved, Bit 3: Enable, Bit 2: Mode, Bit 1-0: Status\n\n");
    
    uint8_t control_reg = 0x00;
    
    printf("Initial state:\n");
    print_register(control_reg, "Control Reg");
    
    printf("\nSetting Enable bit (bit 3):\n");
    SET_BIT(control_reg, 3);
    print_register(control_reg, "Control Reg");
    
    printf("\nSetting Mode bit (bit 2):\n");
    SET_BIT(control_reg, 2);
    print_register(control_reg, "Control Reg");
    
    printf("\nSetting Status bits (bits 0-1):\n");
    SET_BIT(control_reg, 0);
    SET_BIT(control_reg, 1);
    print_register(control_reg, "Control Reg");
    
    printf("\nClearing Mode bit (bit 2):\n");
    CLEAR_BIT(control_reg, 2);
    print_register(control_reg, "Control Reg");
    
    // Example 2: Status Flags
    printf("\n\n[EXAMPLE 2] Status Flags Management\n");
    printf("Bit 7: Error, Bit 6: Ready, Bit 5: Busy, Bit 4: Complete\n\n");
    
    uint8_t status_reg = 0x00;
    
    printf("Setting Ready flag:\n");
    SET_BIT(status_reg, 6);
    print_register(status_reg, "Status Reg ");
    
    printf("\nSetting Busy flag:\n");
    SET_BIT(status_reg, 5);
    print_register(status_reg, "Status Reg ");
    
    printf("\nClearing Busy, Setting Complete:\n");
    CLEAR_BIT(status_reg, 5);
    SET_BIT(status_reg, 4);
    print_register(status_reg, "Status Reg ");
    
    printf("\nChecking if Ready flag is set: %s\n", 
           READ_BIT(status_reg, 6) ? "YES" : "NO");
    
    // Example 3: Multiple Bit Operations
    printf("\n\n[EXAMPLE 3] Configuration Register\n");
    printf("Setting multiple configuration bits\n\n");
    
    uint8_t config_reg = 0x00;
    
    printf("Initial:\n");
    print_register(config_reg, "Config Reg ");
    
    printf("\nSetting bits 7, 5, 3, 1:\n");
    SET_BIT(config_reg, 7);
    SET_BIT(config_reg, 5);
    SET_BIT(config_reg, 3);
    SET_BIT(config_reg, 1);
    print_register(config_reg, "Config Reg ");
    
    printf("\nToggling bit 5:\n");
    TOGGLE_BIT(config_reg, 5);
    print_register(config_reg, "Config Reg ");
    
    printf("\nToggling bit 5 again:\n");
    TOGGLE_BIT(config_reg, 5);
    print_register(config_reg, "Config Reg ");
    
    // Example 4: Practical Application
    printf("\n\n[EXAMPLE 4] Practical - Communication Protocol Flags\n");
    printf("Simulating UART status register\n\n");
    
    uint8_t uart_status = 0x00;
    
    // Bit definitions
    #define TX_COMPLETE  7
    #define RX_READY     6
    #define PARITY_ERROR 5
    #define FRAME_ERROR  4
    
    printf("Receiving data...\n");
    SET_BIT(uart_status, RX_READY);
    print_register(uart_status, "UART Status");
    
    printf("\nTransmitting data...\n");
    SET_BIT(uart_status, TX_COMPLETE);
    print_register(uart_status, "UART Status");
    
    printf("\nParity error detected!\n");
    SET_BIT(uart_status, PARITY_ERROR);
    print_register(uart_status, "UART Status");
    
    printf("\nClearing error flags...\n");
    CLEAR_BIT(uart_status, PARITY_ERROR);
    print_register(uart_status, "UART Status");
    
    // Summary
    printf("\n\n[LEARNING] Key concepts demonstrated:\n");
    printf("  ✓ Bit manipulation using macros\n");
    printf("  ✓ Register control (like microcontroller registers)\n");
    printf("  ✓ Flag management\n");
    printf("  ✓ Low-level programming techniques\n");
    
    printf("\n[RELEVANCE] These operations are used in:\n");
    printf("  - GPIO control (setting pins HIGH/LOW)\n");
    printf("  - Peripheral configuration\n");
    printf("  - Communication protocol implementation (UART, SPI, I2C)\n");
    printf("  - Interrupt flag management\n");
    printf("  - Driver development\n");
    
    printf("\n[PLATFORMS] Applicable to:\n");
    printf("  - NXP i.MX series microcontrollers\n");
    printf("  - Renesas RZ/A1, SH, RL78, RX series\n");
    printf("  - Any embedded system with register-based control\n");
    
    return 0;
}