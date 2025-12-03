# STM32F446RE Compiler Optimization Analysis Report

## Project Overview

This report presents a comprehensive analysis of compiler optimization effects on memory utilization for an STM32F446RE bare-metal application developed using STM32 HAL Library.

### Development Environment
- **Microcontroller**: STM32F446RE
- **IDE**: MDK-ARM V5.42.0.0
- **Compiler**: ARM Compiler V6.23
- **Programming Approach**: Bare-metal with HAL Library
- **Memory Specifications**:
  - Flash Memory: 512 KB
  - SRAM: 128 KB

---

## Optimization Results Summary

| Optimization Level | Flash (KB) | Flash (%) | SRAM (Bytes) | SRAM (%) |
| ------------------ | ---------- | --------- | ------------ | -------- |
| **-O0**            | 64.83      | 13.25     | 7672         | 5.85     |
| **-O1**            | 48.50      | 9.47      | 7672         | 5.85     |
| **-O2**            | 55.41      | 10.82%    | 7672         | 5.85     |
| **-O3**            | 56.16      | 10.97     | 7680         | 5.86     |
| **-Ofast**         | 56.16      | 10.97     | 7680         | 5.86     |
| **-Os (balanced)** | 48.02      | 9.38      | 7672         | 5.85     |
| **-Oz (image)**    | 42.61      | 8.32      | 7680         | 5.86     |
| **-Omax**          | 61.31      | 11.98     | 7544         | 5.76     |

---

## Detailed Optimization Level Analysis

### **-O0 (No Optimization)**
**Purpose**: Debugging and development

**Characteristics**:
- No optimization performed
- Direct translation of source code to assembly
- Preserves exact code structure for debugging
- All variables kept in memory
- No code reordering or elimination

**Results**:
- **Flash**: 64.83 KB (13.25%) - Highest memory usage
- **SRAM**: 7672 Bytes (5.85%)

**Best For**: Active development, debugging with breakpoints, step-by-step code analysis

---

### **-O1 (Basic Optimization)**
**Purpose**: Moderate optimization with reasonable compilation time

**Characteristics**:
- Basic optimizations that don't significantly increase compilation time
- Common subexpression elimination
- Simple loop optimizations
- Dead code elimination
- Basic register allocation

**Results**:
- **Flash**: 48.50 KB (9.47%) - 25.2% reduction from -O0
- **SRAM**: 7672 Bytes (5.85%)

**Best For**: Development builds with better performance than -O0, testing phase

---

### **-O2 (Moderate Optimization)**
**Purpose**: Balanced performance optimization

**Characteristics**:
- All -O1 optimizations plus:
- Aggressive loop optimizations (unrolling, fusion)
- Function inlining for small functions
- Instruction scheduling
- Advanced register allocation
- Code motion and hoisting
- May increase code size for performance gains

**Results**:
- **Flash**: 55.41 KB (10.82%) - Larger than -O1 due to inlining
- **SRAM**: 7672 Bytes (5.85%)

**Best For**: Performance-critical applications where Flash space is adequate

---

### **-O3 (Aggressive Optimization)**
**Purpose**: Maximum performance optimization

**Characteristics**:
- All -O2 optimizations plus:
- Aggressive function inlining
- Vectorization (SIMD operations)
- Predictive commoning
- Loop interchange and blocking
- More aggressive code transformations
- Potentially significant code size increase

**Results**:
- **Flash**: 56.16 KB (10.97%) - Slight increase over -O2
- **SRAM**: 7680 Bytes (5.86%)

**Best For**: Performance-critical sections, real-time processing requirements

---

### **-Ofast (Fast Math Optimization)**
**Purpose**: Maximum speed with relaxed standards compliance

**Characteristics**:
- All -O3 optimizations plus:
- Fast math operations (non-IEEE 754 compliant)
- Associative math optimizations
- Finite math assumptions
- No errno setting for math functions
- May sacrifice precision for speed

**Results**:
- **Flash**: 56.16 KB (10.97%) - Identical to -O3 in this case
- **SRAM**: 7680 Bytes (5.86%)

**Best For**: Applications with heavy floating-point calculations where slight precision loss is acceptable

---

### **-Os (Size Optimization - Balanced)**
**Purpose**: Optimize for size while maintaining reasonable performance

**Characteristics**:
- Enables most -O2 optimizations except those that increase code size
- Disables aggressive inlining
- Prefers smaller instruction sequences
- Optimizes for code density
- Maintains good performance balance

**Results**:
- **Flash**: 48.02 KB (9.38%) - Best balance of size and performance
- **SRAM**: 7672 Bytes (5.85%)

**Best For**: Production builds for most embedded applications, balanced approach

---

### **-Oz (Size Optimization - Image Size)**
**Purpose**: Maximum code size reduction

**Characteristics**:
- More aggressive than -Os in size reduction
- Minimizes code size even at performance cost
- Reduced or disabled inlining
- Prefers function calls over code duplication
- Optimizes for smallest binary size
- May use slower but smaller instruction sequences

**Results**:
- **Flash**: 42.61 KB (8.32%) - **Smallest Flash footprint** (34.3% reduction from -O0)
- **SRAM**: 7680 Bytes (5.86%)

**Best For**: Flash-constrained devices, bootloaders, space-critical applications

---

### **-Omax (Maximum Optimization)**
**Purpose**: ARM Compiler-specific maximum optimization

**Characteristics**:
- ARM-specific maximum optimization level
- Combines aggressive performance and size optimizations
- Advanced ARM architecture-specific optimizations
- Link-time optimization (LTO) if enabled
- May perform inter-procedural analysis
- Longer compilation times

**Results**:
- **Flash**: 61.31 KB (11.98%)
- **SRAM**: 7544 Bytes (5.76%) - **Lowest SRAM usage**

**Best For**: Production builds requiring both performance and ARM-specific optimizations


## Visual Analysis

### Flash Memory Usage Comparison

```
┌─────────────────────────────────────────────────────────────────────┐
│                    Flash Memory Usage by Optimization               │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  70 KB ┤                                                            │
│        │                                                            │
│  65 KB ┤  ████████████████                                          │
│        │  █ -O0: 64.83KB █                                          │
│  60 KB ┤  ████████████████     ██████████████                       │
│        │                       █ -Omax: 61.31█                      │
│  55 KB ┤                       ██████████████  ████████  ████████   │
│        │                                       █ -O2:  █  █ -O3:  █ │
│  50 KB ┤            ██████     ████████████    █55.41KB█  █56.16KB█ │
│        │            █-O1: █    █ -Os:48.02█    ████████  ████████   │
│  45 KB ┤            █48.5K█    ████████████    █-Ofast:56.16KB█     │
│        │            ██████                                          │
│  40 KB ┤                          ████████                          │
│        │                          █ -Oz: █                          │
│  35 KB ┤                          █42.61K█                          │
│        │                          ████████                          │
│  30 KB ┤                                                            │
│        └────┴─────┴─────┴─────┴─────┴─────┴─────┴─────────────────│
│         -O0  -O1   -Os   -Oz   -O2   -O3  -Ofast -Omax             │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### Flash Usage Ranking (Smallest to Largest)

```
1. -Oz (image size)     ███████████████████████████ 42.61 KB  ⭐ Smallest
2. -Os (balanced)       ████████████████████████████████ 48.02 KB
3. -O1                  ████████████████████████████████ 48.50 KB
4. -O2                  █████████████████████████████████████ 55.41 KB
5. -O3                  ██████████████████████████████████████ 56.16 KB
6. -Ofast               ██████████████████████████████████████ 56.16 KB
7. -Omax                ████████████████████████████████████████ 61.31 KB
8. -O0 (no opt)         ██████████████████████████████████████████████ 64.83 KB
```

### SRAM Usage Comparison

```
SRAM Usage: 7544 - 7680 Bytes (Very Stable)

7700 B ┤
       │
7680 B ┤        ████  ████  ████
       │        █-Oz█  █-O3█  █Oft█
7672 B ┤  ████  ████  ████  ████  ████  ████
       │  █-O0█  █-O1█  █-Os█  █-O2█
7544 B ┤                                 ████
       │                                 █Omx█
7500 B ┤                                 ████
       └──┴────┴────┴────┴────┴────┴────┴────
         -O0  -O1  -Os  -Oz  -O2  -O3  Oft Omx

Variation: Only 136 bytes (1.8%) across all optimization levels
```

### Performance vs Size Trade-off

```
                    ↑ Performance
                    │
        -Ofast ●────┼──── -O3
                    │
         -O2 ●      │
                    │
         -Omax ●    │
                    │
                    │     ● -O1
    ────────────────┼──────────────────────→ Code Size
                    │          ● -Os
                    │              ● -Oz
                    │
         -O0 ●      │
                    │
                    ↓
```

---

## Key Findings and Recommendations

### Flash Memory Analysis

1. **Largest Impact**: -O0 to -O1 transition saves 16.33 KB (25.2% reduction)
2. **Best for Size**: **-Oz** achieves the smallest footprint at 42.61 KB
3. **Best Balance**: **-Os** provides excellent size reduction (48.02 KB) with good performance
4. **Performance vs Size**: -O2/-O3 increase size compared to -O1 due to aggressive inlining

### SRAM Analysis

- SRAM usage remains relatively stable across optimization levels (7544-7680 bytes)
- Variation of only 136 bytes (1.8%) across all levels
- **-Omax** shows the lowest SRAM usage at 7544 bytes
- Optimization primarily affects code generation rather than data allocation

### Recommendations by Use Case

| Use Case | Recommended Optimization | Rationale |
|----------|-------------------------|-----------|
| **Production Embedded System** | **-Os** | Best size/performance balance |
| **Flash-Constrained Device** | **-Oz** | Minimum Flash usage |
| **Performance-Critical Application** | **-O3** | Maximum execution speed |
| **Active Development** | **-O0** | Best debugging experience |
| **Testing/QA Builds** | **-O1** | Reasonable performance with faster compilation |
| **DSP/Math-Heavy Application** | **-Ofast** | Optimized floating-point operations |
| **Production with ARM-Specific Needs** | **-Omax** | ARM architecture optimizations |

---

## Conclusion

For the STM32F446RE application analyzed:

- **-Oz** is recommended for production if Flash space is a primary concern, offering 34.3% savings compared to unoptimized code
- **-Os** provides the best overall balance for typical embedded applications
- **-O0** should be used exclusively for debugging
- **-O3/-Ofast** should be considered when performance is critical and Flash space permits
- SRAM impact is minimal across all optimization levels, making Flash optimization the primary consideration

The choice of optimization level should balance project requirements for code size, execution speed, debuggability, and development phase.

---

### ⚠️ Important Note: Manual Optimization Approach

> **Personal Development Practice:**  
> In my development workflow, I deliberately keep compiler optimizations **disabled** (using -O0) during both development and production phases. This approach provides several critical advantages:
>
> **Rationale:**
> - **Full Control Over Code Execution Flow**: Maintaining complete visibility and control over how the code executes, without unexpected compiler transformations
> - **Predictable Behavior**: Ensuring the program behaves exactly as written, with no hidden optimizations that could introduce subtle bugs
> - **Manual Optimization**: Performing targeted, controlled optimizations at the source code level where needed, rather than relying on automated compiler optimizations
> - **Deterministic Debugging**: Guaranteeing that the debugger shows exactly what's executing, with no instruction reordering or code elimination
> - **Safety-Critical Applications**: Essential for automotive, medical devices, industrial control systems, and other safety-critical domains where:
>   - Code behavior must be fully deterministic and traceable
>   - Certification standards (ISO 26262, IEC 62304, DO-178C) often require documented and verifiable code behavior
>   - Compiler optimizations can introduce non-deterministic timing or behavior that's difficult to validate
>   - Every instruction must be accountable and auditable
>
> **When This Approach is Recommended:**
> - Safety-critical systems (automotive ECUs, medical devices, aviation systems)
> - Systems requiring formal verification or certification
> - Real-time systems where timing predictability is paramount
> - Projects where code maintainability and debuggability outweigh size/speed concerns
> - Applications where the additional Flash/RAM usage is acceptable
>
> **Trade-offs to Consider:**
> - Larger Flash footprint (~52% increase: 64.83KB vs 42.61KB)
> - Potentially slower execution speed
> - Higher power consumption in some scenarios
> - May not be feasible for extremely resource-constrained devices
>
> While compiler optimizations are powerful and well-tested, this manual control approach ensures maximum reliability, traceability, and safety in mission-critical embedded systems. The choice between compiler optimization and manual control should be driven by project requirements, safety standards, and resource constraints.


# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).
  
# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
