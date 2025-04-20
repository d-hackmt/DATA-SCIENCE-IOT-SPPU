import machine
import time

# Set the GPIO pin number for PWM
servo_pin = machine.Pin(13 )

# Create a PWM object with a frequency of 50 Hz (standard for servo motors)
pwm = machine.PWM(servo_pin, freq=50)

# Function to move the servo to a specific angle
def move_servo(angle):
    duty_cycle = int((angle / 180) * 102) + 26
    pwm.duty(duty_cycle)

try:
    while True:
        # Move the servo to 0 degrees (minimum position)
        move_servo(0)
        time.sleep(1)

        # Move the servo to 180 degrees (maximum position)
        move_servo(180)
        time.sleep(1)
        

except KeyboardInterrupt:
    # When you stop the program, make sure to deinitialize PWM
    pwm.deinit()
