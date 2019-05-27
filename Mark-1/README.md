# Mark 1

## Description

Implemented a code in C & Assembly to perform the following functalities:
1. Blinking the 8 LEDs in **4** different patterns.
2. Changing the speed that the LEDs blink at. Added **3** different speeds.

### 1. Blinking the 8 LEDs in 4 different patterns
Whenever the pushbutton is pressed, the system should change modes, starting with mode 1, then
2, then 3, then 4, and then back to 1.
#### Mode 1
The LEDs blink one after another from left to right, then repeat from the left.

<img width="350" alt="Capture3" src="https://user-images.githubusercontent.com/40522456/58441659-ad812700-80b1-11e9-9651-dc351736d427.PNG">

#### Mode 2
The LEDs blink one after another from right to left, then repeat from the right.

<img width="350" alt="Capture4" src="https://user-images.githubusercontent.com/40522456/58441673-cc7fb900-80b1-11e9-916d-a01e932b798e.PNG">

#### Mode 3
 The LEDs blink back and forth.

<img width="350" alt="Capture5" src="https://user-images.githubusercontent.com/40522456/58441679-e15c4c80-80b1-11e9-8276-38f589ca7562.PNG">

#### Mode 4
The LEDs blink on and off all together.

<img width="350" alt="Capture6" src="https://user-images.githubusercontent.com/40522456/58441725-3c8e3f00-80b2-11e9-9f4c-d56ae6104557.PNG">

### 2. Changing the speed that the LEDs blink at. Added 3 different speeds
The LEDS blink at 3 different speed, **1 Hz**, **4 Hz**, and **0.5 Hz**. The LPC1768 board runs at a clock speed of **12 MHz**. This is very fast, and it's hard to see the LEDs blinking. Therefore, a slow clock should be generated.
#### Generating a Slow Clock
We need to calculate the Terminal Count (TC) to generate our slow clock. The **Counter TC** signal is generated when the counter reaches its terminal count. It is an internal signal. To calculate the TC needed, the forumula can be used below:

<img width="500" alt="LED" src="https://user-images.githubusercontent.com/40522456/58441999-d6ef8200-80b4-11e9-8e0f-f15cbbaef018.PNG">

where:
* `Clock Speed of the Board(Hz)` is the speed of the LPC1768 which is 12 MHz.
* `Slow Clock(Hz)` is the speed of the slow clock. 
* `TC needed` is the number of **Terminal Counts (TC)** to generate a slow clock. 
    - To generate **1 Hz**, **12000000 TC** are needed.
    - To generate **4 Hz**, **3000000 TC** are needed.
    - To generate **0.5 Hz**, **24000000 TC** are needed.

## Video of the project
The video will be uploaded **soon**.



