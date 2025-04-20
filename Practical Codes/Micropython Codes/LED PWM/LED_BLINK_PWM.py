from machine import Pin, PWM
from time import sleep

# Set up the LED pin and PWM controller
led_pin = Pin(2, Pin.OUT)  # Replace 2 with the appropriate GPIO pin number for your LED
pwm = PWM(led_pin, freq=1000)  # Set the PWM frequency to 1000Hz (adjust as needed)

# Function to control the brightness of the LED
def set_led_brightness(duty_cycle):
    pwm.duty(duty_cycle)

# Blink the LED with varying brightness levels
def blink_led():
    while True:
        # Increase the brightness
        for duty_cycle in range(0, 1024, 10):  # Step by 10
            set_led_brightness(duty_cycle)
            sleep(0.05)  # Adjust the delay as needed for the desired speed

        # Decrease the brightness
        for duty_cycle in range(1023, -1, -10):  # Step by 10
            set_led_brightness(duty_cycle)
            sleep(0.05)  # Adjust the delay as needed for the desired speed

# Start blinking the LED
blink_led()
