# BB Bandit mini tank
BB Bandit is an open source mini tank with automated target acquisition using pixy cam and various off the shelf parts. 

<img width="1400" height="1050" alt="bykuexsa" src="https://github.com/user-attachments/assets/fb357c19-f186-42a7-89cc-c8b6ba519553" />

The frame of BB Bandit is composed mostly of laser cut particle board but features a 3D printed magazine and barrel (files included). BB Bandit can be trained to identify certain targets based on the hue of a pixel. Once a certain hue is trained, a region growing algorithm is used to estimate the region of space the target takes up in the image. Once a target is identified, BB Bandit will aim the barrel at it. From there, the flywheels spin up and the firing mechanism loads a ball into the chamber where it is then pushed into the flywheels launching it out of the barrel. 
