# Import required modules
import network
from machine import Pin
import BlynkLib

# Connect to Wi-Fi network
wifi_ssid = "Crazyyz"
wifi_password = "420420420"

sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
sta_if.connect(wifi_ssid, wifi_password)

while not sta_if.isconnected():
    pass

print("Wi-Fi connected:", sta_if.ifconfig())

# Connect to Blynk server
auth_token = "zg7IvZLdvMWCaWqBa6O3giMPMHPPY4Db"

blynk = BlynkLib.Blynk(auth_token)

# Define pin numbers
led_pin = 2

# Initialize LED pin
led = Pin(led_pin, Pin.OUT)

# Define Blynk virtual pin handlers
@blynk.on("V0")
def v0_handler(value):
    if int(value[0]) == 1:
        led.value(1)
    else:
        led.value(0)

# Start Blynk loop	
while True:
    blynk.run()
