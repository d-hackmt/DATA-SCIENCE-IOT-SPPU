import machine
from machine import Pin, SoftI2C
from i2c_lcd import I2cLcd
from time import sleep

I2C_ADDR = 0x27
totalRows = 2
totalColumns = 16

#initializing the I2C method for ESP32
i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=10000)     

lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)

while True:
    lcd.move_to(3 , 0)
    lcd.putstr("CRAZY BTECH")
    sleep(2)
    lcd.clear()