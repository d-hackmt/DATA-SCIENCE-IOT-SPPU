# import machine
# import time

# trig = machine.Pin(12, machine.Pin.OUT)
# echo = machine.Pin(14, machine.Pin.IN)
# led = machine.Pin(2, machine.Pin.OUT)

# # Set the threshold distance in centimeters
# threshold_distance = 100.0  # Change this value as needed

# while True:
    
#     trig.on()
#     time.sleep_us(10)
#     trig.off()

#     while not echo.value():
#         pass
#     start_time = time.ticks_us()

#     while echo.value():
#         pass
#     end_time = time.ticks_us()

#     pulse_duration = time.ticks_diff(end_time, start_time)
#     distance = pulse_duration * 0.0343 / 2
#     print("Distance: {:.2f} cm".format(distance))

#     if distance < threshold_distance:
#         led.on()
#     else:
#         led.off()

#     time.sleep(1)



from hcsr04 import HCSR04
import machine
from machine import Pin
from time import sleep

led = Pin(26 , Pin.OUT)
# ESP32

sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)
 
while True:
    distance = sensor.distance_cm()
    print('Distance:', distance, 'cm')
    if distance < 50:
        led.on()
    else:
        led.off()
    sleep(1)
