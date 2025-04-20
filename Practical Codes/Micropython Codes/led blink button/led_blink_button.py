from machine import Pin
from time import sleep

led = Pin(2, Pin.OUT)
button = Pin(5, Pin.IN, Pin.PULL_UP)  # Using internal pull-up resistor

led_state = False  # Track LED state

while True:
    if button.value() == 0:  # Button is pressed
        led_state = not led_state  # Toggle LED state
        led.value(led_state)
        sleep(0.3)  # Debounce delay to prevent double toggling
