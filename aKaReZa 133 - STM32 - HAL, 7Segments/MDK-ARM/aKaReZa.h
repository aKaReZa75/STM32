/**
 ******************************************************************************
 * @file     aKaReZa.h
 * @brief    Common utility macros and functions for STM32 microcontrollers
 * 
 * @author   Hossein Bagheri
 * @github   https://github.com/aKaReZa75
 * 
 * @note     This header file provides:
 *           - Bit manipulation macros for efficient register operations
 *           - Data type conversion utilities (8-bit to 16-bit and vice versa)
 *           - Mathematical constants and helper functions
 *           - Precise microsecond and millisecond delay functions using SysTick
 * 
 * @note     For complete documentation with examples, visit:
 *           https://github.com/aKaReZa75/STM32
 * 
 * @warning  This library is designed for STM32CubeMX generated projects
 *           using HAL (Hardware Abstraction Layer) library only
 ******************************************************************************
 */
 
#ifndef _aKaReZa_H_
#define _aKaReZa_H_


/* ============================================================================
 *                              PRE-INCLUDE SECTION
 * ============================================================================
 * @note This section is reserved for low-level headers that must be included
 *       before all other headers (e.g., CMSIS or compiler-specific files).
 *       Modify this only if your project requires special preprocessor order.
 * ---------------------------------------------------------------------------- */
#include "main.h"     
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* ============================================================================
 *                               USER INCLUDES
 * ============================================================================
 * @note This section is reserved for user-defined headers.
 *       You can include application-specific headers here, e.g.:
 *       #include "my_peripherals.h"
 *       #include "custom_delay.h"
 * ---------------------------------------------------------------------------- */


/* ============================================================================
 *                        BIT MANIPULATION MACROS
 * ============================================================================
 * Note: These macros support up to 64-bit registers depending on register type
 * ---------------------------------------------------------------------------- */

/* -------------------------------------------------------
 * @brief Set a specific bit in a register
 * @param _Reg: Register or variable (8/16/32/64-bit)
 * @param _Bit: Bit position (0-63 for 64-bit)
 * ------------------------------------------------------- */
#define bitSet(_Reg, _Bit)    ((_Reg) |= (1ULL << (_Bit)))

/* -------------------------------------------------------
 * @brief Clear a specific bit in a register
 * @param _Reg: Register or variable (8/16/32/64-bit)
 * @param _Bit: Bit position (0-63 for 64-bit)
 * ------------------------------------------------------- */
#define bitClear(_Reg, _Bit)  ((_Reg) &= ~(1ULL << (_Bit)))

/* -------------------------------------------------------
 * @brief Toggle a specific bit in a register
 * @param _Reg: Register or variable (8/16/32/64-bit)
 * @param _Bit: Bit position (0-63 for 64-bit)
 * ------------------------------------------------------- */
#define bitToggle(_Reg, _Bit) ((_Reg) ^= (1ULL << (_Bit)))

/* -------------------------------------------------------
 * @brief Change a bit to specific value (0 or 1)
 * @param _Reg: Register or variable (8/16/32/64-bit)
 * @param _Bit: Bit position (0-63 for 64-bit)
 * @param _Value: New bit value (0 or 1)
 * ------------------------------------------------------- */
#define bitChange(_Reg, _Bit, _Value) ((_Value) == 1 ? bitSet(_Reg, _Bit) : bitClear(_Reg, _Bit))

/* -------------------------------------------------------
 * @brief Check the state of a specific bit
 * @param _Reg: Register or variable (8/16/32/64-bit)
 * @param _Bit: Bit position (0-63 for 64-bit)
 * @return 1 if bit is set, 0 if cleared
 * ------------------------------------------------------- */
#define bitCheck(_Reg, _Bit)  (((_Reg) >> (_Bit)) & 0x01U)

/* -------------------------------------------------------
 * @brief Check if a bit is high (set)
 * @param _Reg: Register or variable
 * @param _Bit: Bit position
 * @return 1 if bit is high, 0 otherwise
 * ------------------------------------------------------- */
#define bitCheckHigh(_Reg, _Bit)  (bitCheck(_Reg, _Bit))

/* -------------------------------------------------------
 * @brief Check if a bit is low (cleared)
 * @param _Reg: Register or variable
 * @param _Bit: Bit position
 * @return 1 if bit is low, 0 otherwise
 * ------------------------------------------------------- */
#define bitCheckLow(_Reg, _Bit)   (!bitCheck(_Reg, _Bit))

/* -------------------------------------------------------
 * @brief Wait until a bit becomes high
 * @param _Reg: Register or variable
 * @param _Bit: Bit position
 * @warning This is a blocking operation
 * ------------------------------------------------------- */
#define bitWaitHigh(_Reg, _Bit)   while(bitCheckLow(_Reg, _Bit))

/* -------------------------------------------------------
 * @brief Wait until a bit becomes low
 * @param _Reg: Register or variable
 * @param _Bit: Bit position
 * @warning This is a blocking operation
 * ------------------------------------------------------- */
#define bitWaitLow(_Reg, _Bit)    while(bitCheckHigh(_Reg, _Bit))

/* -------------------------------------------------------
 * @brief Shift register left by N positions
 * @param _Reg: Register or variable
 * @param _Pos: Number of positions to shift
 * ------------------------------------------------------- */
#define bitShiftLeft(_Reg, _Pos)  ((_Reg) = (_Reg) << (_Pos))

/* -------------------------------------------------------
 * @brief Shift register right by N positions
 * @param _Reg: Register or variable
 * @param _Pos: Number of positions to shift
 * ------------------------------------------------------- */
#define bitShiftRight(_Reg, _Pos) ((_Reg) = (_Reg) >> (_Pos))


/* ============================================================================
 *                         MATHEMATICAL MACROS
 * ============================================================================ */

/* -------------------------------------------------------
 * @brief Compare two floating-point numbers with tolerance
 * @param a: First number
 * @param b: Second number
 * @param epsilon: Tolerance value (e.g., 0.0001)
 * @return true if numbers are equal within epsilon range
 * ------------------------------------------------------- */
#define Float_IsEqual(a, b, epsilon)  ((MATH_Abs((a) - (b))) <= (epsilon))

/* -------------------------------------------------------
 * @brief Mathematical constant PI (p)
 * ------------------------------------------------------- */
#define MATH_Const_PI  3.14159265358979

/* -------------------------------------------------------
 * @brief Mathematical constant E (Euler's number)
 * ------------------------------------------------------- */
#define MATH_Const_E   2.71828182845904

/* -------------------------------------------------------
 * @brief Calculate absolute value
 * @param x: Input value
 * @return Absolute value of x
 * ------------------------------------------------------- */
#define MATH_Abs(x)    (((x) < 0) ? -(x) : (x))


/* ============================================================================
 *                           DELAY FUNCTIONS
 * ============================================================================
 * @note These functions use SysTick timer for accurate delays
 * @note SystemCoreClock is configured to 64MHz
 * ---------------------------------------------------------------------------- */

/* -------------------------------------------------------
 * @brief Provides microsecond delay using SysTick timer
 * @param us: Delay duration in microseconds
 * @retval None
 * @note Inline function for minimal overhead
 *       Maximum delay depends on SysTick configuration
 *       For 64MHz clock: max ~268ms per call
 * ------------------------------------------------------- */
static inline void delay_us(uint32_t us)
{
	uint32_t ticks = (SystemCoreClock / 1000000U) * us;
	uint32_t start = SysTick->VAL;
	uint32_t reload = SysTick->LOAD + 1U;
	uint32_t elapsed = 0;
	
	while (elapsed < ticks)
	{
		uint32_t now = SysTick->VAL;
		if (start >= now) 
		{
			elapsed += (start - now);      
		} 
		else 
		{
			elapsed += (start + (reload - now)); 
		};
		start = now;
	};
};

/* -------------------------------------------------------
 * @brief Provides millisecond delay using SysTick timer
 * @param ms: Delay duration in milliseconds
 * @retval None
 * @note Inline function for minimal overhead
 *       Independent implementation, does not call delay_us()
 * ------------------------------------------------------- */
static inline void delay_ms(uint32_t ms)
{
	uint32_t ticks = (SystemCoreClock / 1000U) * ms;
	uint32_t start = SysTick->VAL;
	uint32_t reload = SysTick->LOAD + 1U;
	uint32_t elapsed = 0;
	
	while (elapsed < ticks)
	{
		uint32_t now = SysTick->VAL;
		if (start >= now) 
		{
			elapsed += (start - now);      
		} 
		else 
		{
			elapsed += (start + (reload - now)); 
		};
		start = now;
	};
};

#endif