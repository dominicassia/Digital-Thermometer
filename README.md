<h1>Digital Thermometer</h1>

This project displays real time temperature data.

I was originally inspired by circuit art on instagram to make a device that was more asthetic using brass rod to make the physical connections. The alternative motivation was that my apartment does not have a digital thermometer. 
<div style='display: flex; justify-content: center;'>
<img width='75%' src='https://lh3.googleusercontent.com/BQAatViSDg6Xe5bStlQCquC0nRSNGjbFQP8l6Q-zMrRMkjRLxdxZrqLgaYsEfV7nFklTrxYw9iGJxMiJvHqfNfJANmRVA5L_4kiuv-FShwmIjbCt2AEXxMfw8uTGWvNy62yPS4HqAw=w2400'></img>
</div>

<h2>Materials</h2>

- Arduino Pro Micro ( 5v )
- 7 Segment Display ( Common Cathode )
- DHT-11 Temperature & Humidity Sensor
- Resistors ( 1 kOhm & 330 Ohm )
- 0.8mm Brass Rod

<h2>Schematic</h2>

I originally planned on using an Arduino Nano and the CNT-5 sensor, however, I went with the Arduino Micro Pro and DHT-11 for size and accuracy.   

<h5 style='margin-left: 20px;'>
Arduino Micro Pro & DHT-11
</h5>

<div style='display: flex; justify-content: center;'>
<img width='90%' src='https://lh3.googleusercontent.com/oO8j4DHwO8NHK7utaHeO_7fnyfLCzsE8r5ZpZ72otXHg-707LKqIVLOOZrJhJAEJoJEII4FZI8rWFRER3kh2kUnYmyFqo7-wBhA47ab-MvHwO2JKlFJBtyqLaF22irBDUTJTo9AGTQ=w2400'></img>
</div>

<h5 style='margin-left: 20px;'>
Arduino Nano & CNT-5
</h5>

<div style='display: flex; justify-content: center;'>
<img width='90%' src='https://lh3.googleusercontent.com/oO8j4DHwO8NHK7utaHeO_7fnyfLCzsE8r5ZpZ72otXHg-707LKqIVLOOZrJhJAEJoJEII4FZI8rWFRER3kh2kUnYmyFqo7-wBhA47ab-MvHwO2JKlFJBtyqLaF22irBDUTJTo9AGTQ=w2400'></img>
</div>

<h2>Code</h2>

I originally planned on implementing the SevSeg Arduino Library, but I decided to create my own simple function calls. 

<h5><a style='color: inherit; margin-left: 20px;' src='https://github.com/dominicassia/Digital-Thermometer/blob/main/DHT-11/DHT-11.ino'>
DHT-11.ino
</a></h5>

<p style='margin-left: 20px;'>
This file was written to test the functionallity of the DHT-11 sensor. Real-time temperature and humidity are printed to the serial monitor in 2 second intervals.
</p> 

<h5><a style='color: inherit; margin-left: 20px;' src='https://github.com/dominicassia/Digital-Thermometer/blob/main/7-Segment-Display/7-Segment-Display.ino'>
7-Segment-Display.ino
</a></h5>

<p style='margin-left: 20px;'>
This file was is the driver to the seven segment display. The functions progress from correlating toggling pins, to toggling numbers, to taking displaying a float and correlating unit of temperature. Initialization functions were also put in place to ensure proper display functionallity on boot-up. The function displayValue() utilizes dpIndex() to find the proper decimal point placement within the display, and flicker(), which handles the constant flickering of the different digits to display the float. 
</p> 

<h5><a style='color: inherit; margin-left: 20px;' src='https://github.com/dominicassia/Digital-Thermometer/blob/main/Temperature-Display/Temperature-Display.ino'>
Temperature-Display.ino
</a></h5>

<p style='margin-left: 20px;'>
Temperature-Display is the culmative file which incorperates the functionallity of both prior files. On boot-up, the initialization sequence begins, then the device begins to display temperatures, refreshing about every 5 seconds.
</p> 
