import machine
from machine import Pin, SoftI2C
from i2c_lcd import I2cLcd
from time import sleep
from hcsr04 import HCSR04

# LCD config
I2C_ADDR = 0x27
totalRows = 2
totalColumns = 16

# Initialize I2C for LCD
i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=10000)     
lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)

# LED config
led = Pin(2, Pin.OUT)

# Ultrasonic sensor config
sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)

while True:
    try:
        distance = sensor.distance_cm()
        lcd.clear()
        lcd.move_to(0, 0)
        lcd.putstr("Distance:")
        lcd.move_to(0, 1)
        lcd.putstr(f"{distance:.1f} cm")

        print("Distance:", distance, "cm")

        if distance < 50:
            # Blink LED if distance < 50
            led.on()
            sleep(0.3)
            led.off()
            sleep(0.3)
        else:
            led.off()
            sleep(1)

    except OSError:
        lcd.clear()
        lcd.putstr("Sensor Error")
        print("Sensor Error")
        sleep(1)
