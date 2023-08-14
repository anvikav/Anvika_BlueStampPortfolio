---
layout: default
---

# The Assistive Smart Jacket: Technology of The Future

| **Engineer** | **School** | **Area of Interest** | **Grade** | 
|:--:|:--:|:--:|:--:|
| Anvika V | Princeton Day School | Computer Engineering | Incoming Senior |

Hello! My name is Anvika and I am a rising high school senior interested in computer engineering! This summer I developed an assistive smart jacket to help the visually impaired community. My journey with assistive technology started with developing an object detection system that offers users sensory feedback about their surroundings. I have since turned that project into a jacket that discretely aids the user navigate a room. There are countless ways to expand on my work and if you find yourself exploring them, reach out to me at anvikavasireddy@gmail.com!

<!--This smart jacket is equipped with an array of sensors that offer intuitive assistance. From built-in object detection to real-time text-to-speech conversion, it is designed to be multi-functional and offer discrete aid while navigating a space.-->

* * *
  
# Object Detection

<p align="center">
<img src="M1.png" alt="Milestone1" width="450"/>
</p>
<p align="center"> 
<font size="1"> Anvika V. 2023 First Milestone [Photograph]. </font>
</p>

  The first step of this project was to develop a system that assists visually-impaired individuals navigate space by alerting the user of objects within a 70cm radius with either haptic or auditive feedback. As the object gets closer to the user, the system responds with more frequent vibrating or buzzing; a toggle switch is used to change between the two types of sensory feedback. Additionally, to establish a visual debugging method, the circuit has a 5mm red LED that lights up harmoniously with the sensors. Next, I will expand this by integrating a Raspberry Pi to translate text into Morse code and attaching it to a jacket to make it wearable.
  
<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/7IKxNl-OvRk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
</div>

### Code

For object detection, I measured the distance  signals from an ultrasonic sensor traveled and converted it into centimeters with the microsecondsToCentimeters() function. The vibrating motor, buzzer, and led would then flicker on and off in response as long as the wave traveled less than 70 cm. The frequency of the pulsing would increase as the object got closer.

```c++
  void loop()
  {
    long duration, cm; //Variables for wave duration and wave distance   
    digitalWrite(pingTrigPin, LOW); //Confirming that the trigPin is clear   
    delayMicroseconds(2);
    digitalWrite(pingTrigPin, HIGH); //Generating a wave by setting trigPin to HIGH for 5 microseconds and then back to low
    delayMicroseconds(5);
    digitalWrite(pingTrigPin, LOW);
    duration = pulseIn(pingEchoPin, HIGH); //Storing the travel time is variable duration
    cm = microsecondsToCentimeters(duration); //Converting to distance   
    if(cm<=70 && cm>0) //Makes the light blink faster when the distance is smaller --> starts blinking at 70cm
    {
      int d= map(cm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      digitalWrite(buz, HIGH); //Turning light on for .1 second  
      delay(100);
      digitalWrite(buz, LOW); //Turning light off 
      delay(d); //Waiting for a time that corresponds to the variable cm
    }
  }
 
```
[Full Code](https://github.com/anvikav/Anvika_BlueStampPortfolio/blob/main/Project%20Code/objectDetection.ino)


### Schematics

<p align="center">
<img src="S1.png" alt="Schematic1" width="450"/>
</p>
<p align="center">
<font size="1"> Anvika. 2023 First Milestone Schematic [Tinkercad Circuit Diagram]. </font>
</p>

### Bill of Materials
<font size="1"> Prices as of August 2023 </font>

| **Part** | **Quantity** | **Note** | **Unit Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Arduino Micro | 1 | Microcontroller | $24.90 | <a href="https://store-usa.arduino.cc/products/arduino-micro?selectedStore=us"> Arduino </a> |
| Ultrasonic Sensor | 1 | Object Detection | $3.95 | <a href="https://www.digikey.com/en/products/detail/adafruit-industries-llc/3942/9658069?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_High%20ROAS%20Categories&utm_term=&utm_content=&gclid=Cj0KCQjwoeemBhCfARIsADR2QCvdct9ZQj4tz0uKaFE7A8b9jxVh9Svgka9okB9HelglRaPaI8nZRfUaAtbZEALw_wcB"> Digikey </a> |
| Vibrating Motor | 1 | Haptic Feedback | $1.90 | <a href="https://www.digikey.com/en/products/detail/seeed-technology-co.,-ltd/316040001/5487672?utm_adgroup=Seeed%20Technology%20Co.%2C%20LTD.&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_DK%2BSupplier_Tier%201%20-%20Block%202&utm_term=&utm_content=Seeed%20Technology%20Co.%2C%20LTD.&gclid=Cj0KCQjwoeemBhCfARIsADR2QCtoECYhEt77AOmON02Ffdc9PCfrDuJbs5MAgV3U6VQzc4a4WhZQ-90aAk4zEALw_wcB"> DigiKey </a> |
| Buzzer | 1 | Auditive Feedback | $.70 | <a href="https://www.amazon.com/mxuteuk-Electronic-Computers-Printers-Components/dp/B07VK1GJ9X/"> Amazon </a> |
| 5mm Red LED | 1 | Visual Troubleshooting  | $0.45 | <a href="https://www.sparkfun.com/products/9590"> SparkFun </a> |
| Slide Switch | 1 | Selecting Haptic of Auditive Feedback  | $0.27 | <a href="https://www.amazon.com/HiLetgo-SS-12D00-Toggle-Switch-Vertical/dp/B07RTJDW27/"> Amazon </a> |
| 220Ω Resistor | 1 | Limiting Current to LED | $0.44 | <a href="https://www.mcmaster.com/1348N356/"> McMaster-Carr </a> |
| Breadboard | 1 | Intial Circuit Base | $4.95 | <a href="https://www.adafruit.com/product/64"> Adafruit </a> |
| Male-to-Female Jumper Wires | 1 | Connecting Wires | $2.10 | <a href="https://www.digikey.com/en/products/detail/sparkfun-electronics/PRT-12794/5993859?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_High%20ROAS%20Categories&utm_term=&utm_content=&gclid=Cj0KCQjwoeemBhCfARIsADR2QCtyZU8zjUzIar3x82ijXdVH7xfaRfGgUX5U579Ti4dJXUiiGk269uQaAoPhEALw_wcB"> DigiKey </a> |
| Breadboard Jumper Wires | 1 | Connecting Wires | $11.99 | <a href="https://www.amazon.com/AUSTOR-Lengths-Assorted-Preformed-Breadboard/dp/B07CJYSL2T/ref=asc_df_B07CJYSL2T/?tag=hyprod-20&linkCode=df0&hvadid=312209999515&hvpos=&hvnetw=g&hvrand=3356264878582093939&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9004018&hvtargid=pla-569895146522&psc=1"> Amazon </a> | 

# Text-to-Speech Conversion

<!--<div align="center">
<iframe width="560" height="315" src="[https://www.youtube.com/embed/y3VAmNlER5Y](https://prezi.com/v/view/DcSKiovgZVgT32lMbmLB/)" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
</div>-->

  The first modification I implemented started from the idea of a text-to-braille translator. I planned to use Raspberry Pi OpenCV to read text and then have an Arduino Micro convert it onto a homemade braille display. However, the idea of this display opened a Pandora's box of technical challenges. The display had to be small enough to be portable and lightweight, but I couldn't sacrifice the amount of text translated at a time. While researching I found professors at the University of Michigan who were developing technology that would be perfect for this project. 

[Michigan Engineering Microfluidics Braille Tablets](https://news.engin.umich.edu/2015/12/bringing-braille-back-with-better-display-technology/)
  
  The Braille tablets are a huge step in the right direction for assistive technology but I decided I wanted to focus on a modification someone could more readily recreate at home. So instead, I repurposed the vibrating motor from the object detection to convert text into Morse code. 

### Code for Morse Code Translator

To translate the text, I modified a program created by Arduino Education. The section below shows how the program deciphers which letter to translate into Morse code. It starts by receiving the user-entered text character by character and then decides whether it is a lowercase or uppercase letter, number, or space. From there, the appropriate Morse code sequence is outputted by pulsing the vibrating motor.

```c++
void loop() 
{
  char ch;
  if (Serial.available())
  {
    ch = Serial.read(); // read a single letter if (ch >= 'a' && ch <= 'z')
    Serial.print(ch);
    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z') 
    {
      flashSequence(letters[ch - 'A']); 
    }
    else if (ch >= '0' && ch <= '9') 
    {
      flashSequence(numbers[ch - '0']); 
    }
    else if (ch == ' ') 
    {
      delay(dotDelay * 4);
    }
  }
}  
```
 [Full Code](https://github.com/anvikav/Anvika_BlueStampPortfolio/blob/main/Project%20Code/morseCodeInitial.ino)

  Later, I realized that Morse code, like Braille, is not an accessible method of communication; as a matter of fact, only 1% of the population can understand Morse code. So, to complete this milestone, I decided to shift gears to a text-to-speech translator and control it entirely with a Raspberry Pi. 

  Unlike the Arduino Micro, a simple microcontroller, the Raspberry Pi is a full-fledged computer with the processing power to convert live text into speech. I used a small Pi camera with a meter-long ribbon cable and earbuds with a headphone jack. 
  
  The first step was connecting my Pi to my computer remotely. I encountered a setback when my computer had trouble connecting to my Pi through a VNC Server and lagged noticeably when I would SSH into it. After days of troubleshooting, I decided to reflash my Pi's SD card and connect through a monitor.
  
  Once I established a strong connection to the Pi, I started working on live text recognition using Python. I soon faced the issue of dealing with blurry photos that the Pi was unable to read. By manually adjusting the focus of the camera and going through several rounds of testing, I successfully converted text into speech. 

  For the software portion of the converter, I used the PiTextReader software developed by 
Russell Grokett.

<!--<p align="center">
<img src=" " alt="Text-Speech" width="450"/>
</p>-->

### Bill of Materials
<font size="1"> Prices as of August 2023 </font>

| **Part** | **Quantity** | **Note** | **Unit Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Raspberry Pi 4 Model B (2 GB) | 1 | Computer | $45.00 | <a href="https://www.sparkfun.com/products/15446?src=raspberrypi"> SparkFun </a> |
| Micro HDMI to HDMI Cable | 1 | Raspberry Pi-to-Monitor Connection | $4.95 | <a href="https://www.canakit.com/official-micro-hdmi-to-hdmi-cable.html?defpid=4651"> CanaKit </a> |
| SanDisk 32GB Class 10 MicroSD Card | 1 | Recommended SanDisk Raspberry Pi Class 10 MicroSD Cards | $11.95	| <a href="https://www.canakit.com/raspberry-pi-sd-card-noobs.html"> CanaKit </a> |
| USB Card Reader Dongle | 1 | Dongle for Writing Card| $2.95 | <a href="https://www.pishop.us/product/usb-2-0-keychain-micro-sd-card-reader/"> PiShop </a> |
| Raspberry Pi 15W Power Supply | 1 | USB-C Power Adapter Only Compatible with Raspberry Pi 4B. | $8.00 | <a href="https://www.pishop.us/product/raspberry-pi-15w-power-supply-us-white/?src=raspberrypi"> PiShop </a> |
| Dell Wireless Keyboard and Mouse | 1 | Controlling Raspberry Pi with Monitor| $22.99 | <a href="https://www.dell.com/en-us/shop/dell-wireless-keyboard-and-mouse-km3322w/apd/580-akcw/pc-accessories?gacd=9684992-1102-5761040-266906002-0&dgc=ST&SA360CID=71700000111444217&&gad=1&gclid=Cj0KCQjwoeemBhCfARIsADR2QCtNJDhPG3VlS3W_CHoraPY3sirmL0CxNIjIDA69lD_xslhN6LpRpkUaAoviEALw_wcB&gclsrc=aw.ds"> Dell </a> |
| Raspberry Pi Camera Module V2 | 1 | Camera | $25.00 | <a href="https://www.sparkfun.com/products/14028?src=raspberrypi"> SparkFun </a> |
| Flex Cable for Raspberry Pi Camera or Display - 1 meter | 1 | Cable to Connect Camera and Raspberry Pi | $3.95 | <a href="https://www.adafruit.com/product/2143"> Adafruit </a> |
| Earbuds | 1 | Speech | $9.04 | <a href="https://www.amazon.com/AmazonBasics-Ear-Headphones-Mic-Black/dp/B07HH1QSLB/ref=asc_df_B07HH1QSLB/?tag=hyprod-20&linkCode=df0&hvadid=311990496852&hvpos=&hvnetw=g&hvrand=16437474883593717386&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9004018&hvtargid=pla-625745103730&th=1"> Amazon</a> |

# Jacket Integration  

  Before beginning the process of attaching the two systems to the jacket, I made a circuit diagram on Tinkercad for the object detection system and breadboarded it:
  
<p align="center">
<img src="s2.png" alt="Schematic2" width="450"/>
</p>
<p align="center">
<font size="1"> Anvika. 2023 Second Milestone Schematics [Tinkercad Circuit Diagram]. </font>
</p> 

<p align="center">
<img src="m21.png" alt="Milestone2" width="450"/>
</p>
<p align="center">
<font size="1"> Anvika. 2023 Second Milestone [Photograph]. </font>
</p>


The final step before stitching the electronics onto the jacket was powering the object detection with a battery pack:

<p align="center">
<img src="m23.png" alt="BatteryPack" width="450"/>
</p>
<p align="center">
<font size="1"> Anvika. 2023 Object Detection with Battery [Photograph]. </font>
</p> 


### Schematics Part 3

<p align="center">
<img src="s3.png" alt="Schematic3" width="450"/>
</p>
<p align="center">
<font size="1"> Anvika. 2023 _Third Milestone Schematics_ [Digital Drawing]. </font>
</p> 





