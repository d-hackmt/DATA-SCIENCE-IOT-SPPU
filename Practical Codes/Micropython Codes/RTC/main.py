from machine import I2C, Pin
from time import sleep
from ds1307 import DS1307

# adress = addr=0x68

i2c_rtc = I2C(0, scl=Pin(22), sda=Pin(21), freq=400000)
rtc = DS1307(i2c_rtc)
# divesh = 100

while True:
    (Y, M, D, day, hr, m, s, p1) = rtc.datetime()
    print("Current Date and Time: {}-{}-{} {}:{}:{}".format(Y, M, D, hr, m, s))
    
    # print("Current Date : {}-{}-{} ".format(Y, M, D ))
    # print("Current Time:  {}:{}:{}".format( hr, m, s))

    # print(f"my number is {divesh}")
    # print("my number is : {}".format(divesh))

    sleep(1)
