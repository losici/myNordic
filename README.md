# myNordic

Getting started with nRF Connect SDK.
The exercises are taken from The Nordic Developer Academy and they might be slightly different from the course.
Link: https://academy.nordicsemi.com/lessons/lesson-1-nrf-connect-sdk-introduction/

## Hardware & Software
- nRF52840
- v2.x.x

## Practical stuff

1. Create a new application --> freestanding
1. Add a build configuration --> choose the board ID where to flash the application to
1. check the connected device tab (JLINK)
1. from action view click Flash

## Architecture
- Zephyr RTOS is an open-source real-time operating system for connected and resource-constrained embedded devices. It includes a scheduler that ensures predictable/deterministic execution patterns and abstracts out the timing requirements. It also comes with a rich set of fundamental libraries and middleware that simplifies development.

Internally, the nRF Connect SDK code is organized into four main repositories:

1. nrf – Application & Connectivity Protocols (Nordic)
1. nrfxlib – Peripheral Drivers and Stacks (Nordic)
1. Zephyr – RTOS & Board configuration (open source)
1. MCUBoot – Secure Bootloader (open source)

Kconfig generates definitions that configure the whole system, for example which wireless protocol or which libraries to use. Devicetree describes the hardware. CMake then uses the information from Kconfig and the devicetree to generate build files, which Ninja (comparable to make) will use to build the program. The GCC compiler system is used to create the executables.


### Device Tree
It is a construct, a hierarchical data structure, used by Zephyr RTOS which describes the nRF Connect Hardware in a structured and modular way. It is the equivalent of an header files for other systems.
The devicetree uses nodes connected together and each node contains a set of properties. The human-readable text format is called DTS (DeviceTree Source).

### Device Driver Model
In order to interact with a hardware peripheral or a system block, we need to use a device driver (or driver for short), which is software that deals with the low-level details of configuring the hardware the way we want. In the nRF Connect SDK, the driver implementation is highly decoupled from its API. This basically means that we are able to switch out the low-level driver implementation without modifying the application because we can use the same generic API.
Device drivers which are present on all supported board configurations are listed below.
1.  Interrupt controller: This device driver is used by the kernel’s interrupt management subsystem.
1. Timer: This device driver is used by the kernel’s system clock and hardware clock subsystem.
1. Serial communication: This device driver is used by the kernel’s system console subsystem.
1. Entropy: This device driver provides a source of entropy numbers for the random number generator subsystem.

### GPIO
To interact with the General-Purpose Input/Output (GPIO) peripheral, we can use the generic API <drivers/gpio.h>, which provides user-friendly functions to interact with GPIO peripherals.
