# Road Surface Profilometer Project

## Project Description
This project presents the design of a **road surface profilometer**, developed to evaluate **deformations and irregularities** on roadways.  
The firmware located in the `/src` directory enables the **ATtiny85** to communicate with the **VL53L0X distance sensor** using the **I²C protocol**, and then forward the measured data via **SPI** to a **Raspberry Pi**, which is responsible for processing and analyzing the collected information.

## Main Challenge
A key challenge addressed in this project is that the ATtiny85 shares the same pins for both **I²C** and **SPI** communication.  
To overcome this limitation, the SPI protocol was implemented using **standard GPIO pins**, allowing both communication interfaces to coexist within the constraints of the microcontroller.
