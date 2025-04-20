import machine
from machine import RTC

# Initialize the RTC module
rtc = RTC()

# Read and print the current date and time
current_datetime = rtc.datetime()
print("Current Date and Time:", current_datetime)
