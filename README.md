
# Petalinux-based CoDesign with Cordic
In previous projects, the hardware accelerator part was designed with the CORDIC IP and a design that transfers the results to the computer with the ZYNQ processor. </br>
[Cordic-based CoDesign](https://github.com/iremkalkanli/Cordic-based-CoDesign) </br>
Petalinux was installed on the ZYNQ processor this time. With the c code written in the operating system, it is possible to get input and output from the computer. </br>
### Screenshot of Petaliunx Building Screen
![Petalinux building]( )
In addition, a GUI has been developed for the computer part of the system.
### GUI
![GUI]( )
## Results

The project was developed on the PYNQ Z2 development board with ZYNQ architecture. </br>
### PYNQ Z2

![PYNQ Z2](https://www.mouser.com.tr/images/marketingid/2019/microsites/175239797/DFRobot_PYNQ-Z2_BL.png)

A project has been carried out in which Xilinx's CORDIC (COordinate Rotation DIgital Computer) IP is used as a hardware accelerator and the processor transfers the computational load to the hardware accelerator. After this hardware design was prepared by PL, data was transferred from the Petalinux environment and it was observed that it worked correctly.
### The Output

![Output]( )
## Contributors
- [@ozlemcali](https://www.github.com/ozlemcali) design, development and documentation.

  
