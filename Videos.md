# Videos
In this document, you will find brief descriptions for each video.  
These summaries provide an overview of the topics covered in each video, allowing you to quickly and easily understand the content presented.  
The purpose of these short descriptions is to give a clear and concise understanding of each video's subject matter.

> [!IMPORTANT]
In this section, only **STM32**-related videos are available. These videos are generally divided into two main categories:
>
> 1. **General Concepts and Basics:**  
   This part includes videos that provide foundational knowledge and general principles of microcontrollers. Videos in this category typically begin with the word *`Microcontroller`*.
>      - **Example:** In the video "*aKaReZa 45 - Microcontroller, Interrupts*", the overall functionality and applications of interrupts across different types of microcontrollers are explained. This helps build a solid understanding of the interrupt mechanism before diving into specific implementations.  
>    
> 2. **Microcontroller-Specific Implementations:**  
    "This part focuses on detailed setups, configurations, and practical demonstrations tailored to a specific microcontroller.  
    Videos in this category are identified by keywords related to specific microcontroller families such as *`AVR`*, *`STM32`*, *`STM8`*, *`ESP8266`*, *`ESP32`*, and *`PIC`*.
>      - **Example for STM32:** In the video "*aKaReZa 101 - STM32, Introduction - PART A*", you'll get a clear and structured introduction to **STM32 microcontrollers**. It explains the **STM32 naming convention**, **ARM Cortex-M architecture**, and key models like the `STM32F103C8T6`. The video also compares **different programmers**, explores **bootloader techniques**, and introduces tools used in STM32 development. It’s a perfect starting point for anyone looking to enter the world of STM32 programming.

> [!NOTE]
> 1. It is strongly advised to first watch the general concept videos (identified by the keyword *`Microcontroller`*) to build a solid theoretical foundation. 
> 2. Once you have a good understanding, proceed to the microcontroller-specific videos (identified by their respective keywords such as *`AVR`*, *`STM32`*, etc.) to see how these concepts are applied in practice.  

> [!TIP]  
> - The prerequisites for each video are clearly mentioned at the beginning of the respective video.  
> - For a complete and organized list of all fundamental topics along with their detailed explanations, visit:  
>    -  [Microcontroller Fundamental Videos](https://github.com/aKaReZa75/Microcontroller/Videos.md)


```plaintext
📁 STM32 Microcontrollers
│
├── Fundamental
│   ├── [aKaReZa 101 - Introduction - PART A]
│   │     ├─ Overview — STMicroelectronics, ARM, Cortex classifications.
│   │     ├─ STM32 Naming — Series breakdown and STM32F103C8T6 intro.
│   │     ├─ Programmers — Types and usage.
│   │     └─ Bootloader — Programming methods explained.
│   │
│   └── [aKaReZa 103 - Introduction - PART B]
│         ├─ Tools — MCU Finder, STLink Utility, Cube Programmer/CLI.
│         ├─ Monitors — STM Studio, Cube Monitor, Cube Power.
│         ├─ IDEs — CubeMX, CubeIDE hands-on.
│         ├─ Code Layers — CMSIS, HAL, LL, SPL comparison.
│         ├─ Hardware — Minimum requirements and pin compatibility.
│         └─ STLINK-V3 MiniE — Setup tips and use cases.
│
├── Hands-on STM32
│   ├── [aKaReZa 115 - First Project - PART A]
│   │     ├─ Hardware — Overview and setup.
│   │     ├─ CubeMX — Project creation and System Core config.
│   │     ├─ Clock Tree — Precise configuration.
│   │     ├─ Project Manager — Navigation and settings.
│   │     ├─ Packages — Cube and Keil DFP (online/offline).
│   │     └─ Code Gen — Modes and structure.
│   │
│   ├── [aKaReZa 118 - First Project - PART B]
│   │     ├─ Compilation — Building and reviewing output files.
│   │     ├─ Programming — Flashing via hardware programmer.
│   │     ├─ Debugging — Register inspection and `printf` usage.
│   │     ├─ Monitoring — STM Studio for live variable tracking.
│   │     ├─ Simulation — Proteus-based STM32 testing.
│   │     └─ Tips — CubeMX refinements and runtime insights.
│   │
│   └── [aKaReZa 121 - First Project - PART C]
│         ├─ Keil IDE — Logic Analyzer, Simulator, advanced tips.
│         ├─ Export — Variable logging and external analysis.
│         ├─ CubeProgrammer — Flashing and memory inspection.
│         ├─ CubeMX — Advanced configuration tips.
│         ├─ Clock — HSI calibration and HSI vs HSE comparison.
│         └─ ST-Link — Interface setup and usage.
│
├── GPIO (General Purpose Input Output)
│   └── [aKaReZa 126 - STM32, HAL, GPIO]
│       ├─ GPIO — Concept and importance in STM32.
│       ├─ Modes — Input, Output, Alternate Function, Analog.
│       ├─ CubeMX — New project creation and pin config.
│       ├─ MX_GPIO_Init() — Function review and initialization logic.
│       ├─ HAL Functions — WritePin, TogglePin, ReadPin usage.
│       ├─ Timing — HAL_Delay() for delays and troubleshooting.
│       └─ Speed — GPIO Speed concept and performance impact.
│
└── Display Interfaces
    └── Alphanumeric LCD
        └── [aKaReZa 130 - STM32 - HAL, aLCD]
            ├─ Project — Creating a new STM32 project.
            ├─ GPIO — Pin configuration for LCD connection.
            ├─ Header — Rewriting aKaReZa.h for STM32.
            ├─ Refactor — Adapting LCD functions to HAL.
            ├─ API — Core LCD functions overview.
            ├─ Performance — Techniques to boost display speed.
            └─ Repository — STM32-compatible alcd library usage.
```

<table style="border-collapse: collapse;">
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/e1PLfSNC_FE">aKaReZa 101 – STM32, Introduction - PART A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Explore the fundamentals of STM32 microcontrollers, their architecture, and naming conventions. This video covers STMicroelectronics, ARM technology, Cortex-M series, STM32F103C8T6, various programmers, and bootloader methods—perfect for beginners starting their STM32 programming journey.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/e1PLfSNC_FE">
        <img src="https://img.youtube.com/vi/e1PLfSNC_FE/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 101 – STM32, Introduction - PART A Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/OK6pVpMzP64">aKaReZa 103 – STM32, Introduction - PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Dive deeper into STM32 microcontrollers with essential software tools. This video covers MCU Finder, STLink Utility, Cube Programmer, CubeMX, CubeIDE, and coding layers like CMSIS, HAL, LL, and SPL. Learn about bootloader programming, minimum hardware requirements, and pin compatibility for STM32 projects.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/OK6pVpMzP64">
        <img src="https://img.youtube.com/vi/OK6pVpMzP64/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 103 – STM32, Introduction - PART B Thumbnail"/>
      </a>
    </td>
  </tr>   

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/E2W5Y3cPvDQ">aKaReZa 115 – STM32, First Project - PART A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Kickstart your STM32 journey by setting up your first bare project. This video covers hardware overview, STM32CubeMX configuration, clock tree setup, Cube Package and Keil DFP installation (online/offline), and code generation modes—perfect for building a solid foundation in STM32 development.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/E2W5Y3cPvDQ">
        <img src="https://img.youtube.com/vi/E2W5Y3cPvDQ/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 115 – STM32, First Project - PART A Thumbnail"/>
      </a>
    </td>
  </tr>  

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/AEv270zCDno">aKaReZa 118 – STM32, First Project - PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Transition from setup to hands-on testing in your STM32 project. This video walks through compilation, flashing, debugging with <code>printf</code>, real-time variable monitoring via STM Studio, and Proteus simulation. Ideal for developers ready to validate and analyze their STM32 applications with precision.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/AEv270zCDno">
        <img src="https://img.youtube.com/vi/AEv270zCDno/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 118 – STM32, First Project - PART B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/E4TNTPMgJMo">aKaReZa 121 – STM32, First Project - PART C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Dive into STM32 development tools with this hands-on guide. Learn to use Keil’s Logic Analyzer and Simulator, export variables for external analysis, flash and inspect memory with STM32CubeProgrammer, calibrate HSI, compare HSI vs. HSE, and master the ST-Link interface—perfect for refining and debugging your STM32 applications.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/E4TNTPMgJMo">
        <img src="https://img.youtube.com/vi/E4TNTPMgJMo/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 121 – STM32, First Project - PART C Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr style="background-color: #f9f9f9;">
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/rTIU0vWZKQs">aKaReZa 126 – STM32, HAL, GPIO</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Master the fundamentals of GPIO configuration in STM32 using the HAL Library. This episode walks through pin setup in <strong>Input, Output, Alternate Function, and Analog modes</strong>, project creation in STM32CubeMX, and practical use of HAL functions like <code>HAL_GPIO_WritePin()</code>, <code>HAL_GPIO_TogglePin()</code>, and <code>HAL_GPIO_ReadPin()</code>. You’ll also learn about timing with <code>HAL_Delay()</code>, troubleshooting common issues, and understanding <strong>GPIO Speed</strong> for performance optimization—an essential foundation for any STM32 project.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/rTIU0vWZKQs">
        <img src="https://img.youtube.com/vi/rTIU0vWZKQs/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 126 – STM32, HAL, GPIO Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr style="background-color: #f9f9f9;">
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/XsrOL4_7Ywc">aKaReZa 130 – STM32, HAL, aLCD</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Bridge AVR and STM32 environments by adapting the <strong>aLCD library</strong> for STM32 using the HAL framework. This tutorial guides you through <strong>creating a new STM32 project</strong>, <strong>configuring GPIO pins</strong>, and <strong>rewriting the shared header file aKaReZa.h</strong>. You’ll also learn to <strong>refactor LCD functions for HAL</strong>, understand the <strong>core LCD API</strong>, and apply <strong>performance optimization techniques</strong>. Finally, the episode introduces the <strong>STM32-compatible alcd repository</strong>—a practical resource for reusing and enhancing LCD code across platforms.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/XsrOL4_7Ywc">
        <img src="https://img.youtube.com/vi/XsrOL4_7Ywc/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 130 – STM32, HAL, aLCD Thumbnail"/>
      </a>
    </td>
  </tr>
  
</table>

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
