<h1>Digital Thermometer</h1>

This project displays real time temperature data.

I was originally inspired by circuit art on instagram to make a device that was more asthetic using brass rod to make the physical connections. The alternative motivation was that my apartment does not have a digital thermometer. 

<img src='https://lh3.googleusercontent.com/BQAatViSDg6Xe5bStlQCquC0nRSNGjbFQP8l6Q-zMrRMkjRLxdxZrqLgaYsEfV7nFklTrxYw9iGJxMiJvHqfNfJANmRVA5L_4kiuv-FShwmIjbCt2AEXxMfw8uTGWvNy62yPS4HqAw=w2400'></img>

<img src='https://lh3.googleusercontent.com/dbB3LsV8lkE1Hzcck7ufakl-gNzr1LAdklztoFNnXku45ENKYvh2_tCMBG2IUIdFQqBb6IQSTMMb44Kv3LdBO5o1Doy54_mhobKJ7E2FYdLb0ESMFNbX2PhbpQiy1g5NPEb-_T1--w=w2400'></img>

## Materials

- Arduino Pro Micro ( 5v )
- 7 Segment Display ( Common Cathode )
- DHT-11 Temperature & Humidity Sensor
- Resistors ( 1 kOhm & 330 Ohm )
- 0.8mm Brass Rod
- BC549 NPN Transistors

## Schematic 

I originally planned on using an Arduino Nano and the CNT-5 sensor, however, I went with the Arduino Micro Pro and DHT-11 for size and accuracy.   

##### Arduino Micro Pro & DHT-11


<div style='display: flex; justify-content: center;'>
<img width='90%' src='https://lh3.googleusercontent.com/oO8j4DHwO8NHK7utaHeO_7fnyfLCzsE8r5ZpZ72otXHg-707LKqIVLOOZrJhJAEJoJEII4FZI8rWFRER3kh2kUnYmyFqo7-wBhA47ab-MvHwO2JKlFJBtyqLaF22irBDUTJTo9AGTQ=w2400'></img>
</div>

##### Arduino Nano & CNT-5

<img src='https://lh3.googleusercontent.com/oO8j4DHwO8NHK7utaHeO_7fnyfLCzsE8r5ZpZ72otXHg-707LKqIVLOOZrJhJAEJoJEII4FZI8rWFRER3kh2kUnYmyFqo7-wBhA47ab-MvHwO2JKlFJBtyqLaF22irBDUTJTo9AGTQ=w2400'></img>

## Code

I originally planned on implementing the SevSeg Arduino Library, but I decided to create my own simple function calls. 

##### [DHT-11.ino](/DHT-11/DHT-11.ino)

This file was written to test the functionallity of the DHT-11 sensor. Real-time temperature and humidity are printed to the serial monitor in 2 second intervals.

##### [7-Segment-Display.ino](/7-Segment-Display/7-Segment-Display.ino)

This file was is the driver to the seven segment display. The functions progress from correlating toggling pins, to toggling numbers, to taking displaying a float and correlating unit of temperature. Initialization functions were also put in place to ensure proper display functionallity on boot-up. The function <tt>displayValue()</tt> utilizes <tt>dpIndex()</tt> to find the proper decimal point placement within the display, and <tt>flicker()</tt>, which handles the constant flickering of the different digits to display the float. 

##### [Temperature-Display.ino](/Temperature-Display/Temperature-Display.ino)

Temperature-Display is the culmative file which incorperates the functionallity of both prior files. On boot-up, the initialization sequence begins, then the device begins to display temperatures, refreshing about every 5 seconds.

## Media

<img src='https://lh3.googleusercontent.com/WpkUmcQCBiBPZ3Aw7rBWUhWvZ9lXk1xEOTqnkkR7jBo9exBuwDruCXEZAL7IP-r8ffpxJu1mrHFH60F3m0O-soAHLbxunl8WQyn8cmkxc7L40f3FNW2Msgok-7mcXjtpGQrKm-dqsQ=w2400'></img>

<img src='https://lh3.googleusercontent.com/tehtcbZO7UF3cDOmMy7hpLM3JLYLlMYTESGI4jQmw4aEnBMhLghLMY0yJZO0pemJi_s_oXn-RULgwa-IWljLCJtp8b7Dg5YLtHo5letMHSxYuMcsdAKnNr9Xf-NeJEPYLWgCXMVS0g=w2400'></img>