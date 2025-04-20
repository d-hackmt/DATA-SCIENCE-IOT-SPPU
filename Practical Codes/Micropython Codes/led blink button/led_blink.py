from machine import Pin
from time import sleep

# Set the LED pin (commonly GPIO 2 on ESP8266, GPIO 25 on Raspberry Pi Pico)
led = Pin(2, Pin.OUT)

while True:
    led.value(1)  # Turn LED on
    sleep(0.5)    # Wait 0.5 seconds
    led.value(0)  # Turn LED off
    sleep(0.5)    # Wait 0.5 seconds
