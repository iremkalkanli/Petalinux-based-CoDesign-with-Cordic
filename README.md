
# Petalinux-based CoDesign with Cordic
In previous projects, the hardware accelerator part was designed with the CORDIC IP and a design that transfers the results to the computer with the ZYNQ processor. </br>
[Cordic-based CoDesign](https://github.com/iremkalkanli/Cordic-based-CoDesign) </br>
Petalinux was installed on the ZYNQ processor this time. With the c code written in the operating system, it is possible to get input from petalinux. </br>
### Screenshot of Petaliunx Building Screen
![Petalinux building](https://github.com/iremkalkanli/Petalinux-Tabanli-Cordic-HW-SW-CoDesign/blob/f517dda8ebd39c4d2c37300122ffe7c3156ec884/Readme%20photos/petalinux%20kurumu.png)
In addition, a GUI has been developed for the computer part of the system.
### GUI
![GUI](https://github.com/iremkalkanli/Petalinux-Tabanli-Cordic-HW-SW-CoDesign/blob/f517dda8ebd39c4d2c37300122ffe7c3156ec884/Readme%20photos/GUI-first.png)
## Results

The project was developed on the PYNQ Z2 development board with ZYNQ architecture. </br>
### PYNQ Z2

![PYNQ Z2](https://live.staticflickr.com/65535/47819083172_92655fe932_b.jpg)

A project has been carried out in which Xilinx's CORDIC (COordinate Rotation DIgital Computer) IP is used as a hardware accelerator and the processor transfers the computational load to the hardware accelerator. After this hardware design was prepared by PL, data was transferred from the Petalinux environment and it was observed that it worked correctly.
### The Output

![Output](https://github.com/iremkalkanli/Petalinux-Tabanli-Cordic-HW-SW-CoDesign/blob/f517dda8ebd39c4d2c37300122ffe7c3156ec884/Readme%20photos/GUI.png)
## Contributors
- [@ozlemcali](https://www.github.com/ozlemcali) design, development and documentation.

  
