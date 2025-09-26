import machine
from machine import Pin, SoftI2C , I2C
from i2c_lcd import I2cLcd
from time import sleep
from ds1307 import DS1307

I2C_ADDR = 0x27
totalRows = 2
totalColumns = 16

i2c_rtc = I2C(0, scl=Pin(22), sda=Pin(21), freq=400000)
rtc = DS1307(i2c_rtc)

# Initializing the I2C method for ESP32
i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=10000)     
lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)

while True:
    # Read the current date and time from the RTC
    (Y, M, D, _, hr, m, s, _) = rtc.datetime()
    
    # Format the date and time as strings
    date_str = "{:04}-{:02}-{:02}".format(Y, M, D)
    time_str = "{:02}:{:02}:{:02}".format(hr, m, s)
    
    # Clear the LCD and display the date in the first line and time in the second line
    lcd.clear()
    lcd.move_to(0, 0)
    lcd.putstr("Date:")
    lcd.move_to(5, 0)
    lcd.putstr(date_str)
    lcd.move_to(0, 1)
    lcd.putstr("Time:")
    lcd.move_to(5, 1)
    lcd.putstr(time_str)
    sleep(1)
