# AVR128DBXX Controller

![IC AVR128DB48](/img/AVR128DB48_IC_Zoom_image.jpg)

The purpose of this project is to create a serial programmable relay controller (PLC similar). Taking advantage of the Microchip's Technology AVR128DB48 microcontroller characteristics.

The second parallel purpose is to demonstrate the C language bare metal programming for this microcontroller family using the AVR-GCC compiler and the Visual Studio Based IDE: Microchip Studio.

## Current State

As 02/04/2023 the firmware allows the user to change the state of the relays manually using a USART CLI with argumented commands.

**For example:**

`$ ctrl 1,3 -tgl`

All commands must start with the $ sign, then the main command, followed by the selected elements and finally the operations, the above command will toggle the state of the selected relays.

![command line](/img/command_line_capture.png)

## Getting Started

These instructions will guide you to get copy of the project up and running on your local machine for development and testing purposes. 

## **Prerequisites**

### **🔵 Hardware**
![Development hardware](/img/curiosity_nano_assembly.jpg)

The project is developed around the following development boards:

_**Microchip Technology**_
- [AVR128DB48 Curiosity Nano](https://www.microchip.com/en-us/development-tool/EV35L43A)
- [CURIOSITY NANO BASE FOR CLICK BOARDS](https://www.microchip.com/en-us/development-tool/AC164162)

_**MIKROE**_
- [SIGNAL RELAY CLICK](https://www.mikroe.com/signal-relay-click)
- [RTC 9 CLICK](https://www.mikroe.com/rtc-9-click)
- [TEMP&HUM 8 CLICK](https://www.mikroe.com/temp-hum-8-click)


### **🔵 Software**

Requirements for the software and other tools to build.

_**MIKROE**_
- [Microchip Studio 7.0.2594](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio)



## Authors

  - **Ricardo Zamudio**  -
    [JustZeus](https://github.com/JustZeus)



## License

Released under MIT License
## Acknowledgments

  - The code in this Repo is based in the application notes from the engineering team at Microchip Technology.
