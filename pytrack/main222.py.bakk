from connection_otaa import Connection
from gps import GPS
import machine
import math
import os
import time
import utime
import gc
import pycom
from machine import RTC
from machine import SD
from L76GNSS import L76GNSS
from pytrack import Pytrack
from LIS2HH12 import LIS2HH12

# conn = Connection('70B3D54991E28406', 'EA460F4C5604238DF72C8520A30F8D47')
# conn.setblocking(True)
# conn.send()
# conn.setblocking(False)
# data = conn.receive()
# print(data)

gc.enable()
# deactivate heartbeat
pycom.heartbeat(False)

# display the reset reason code and the sleep remaining in seconds
# possible values of wakeup reason are:
# WAKE_REASON_ACCELEROMETER = 1
# WAKE_REASON_PUSH_BUTTON = 2
# WAKE_REASON_TIMER = 4
# WAKE_REASON_INT_PIN = 8
print("Wakeup reason: " + str(py.get_wake_reason()) + "; Aproximate sleep remaining: " + str(py.get_sleep_remaining()) + " sec")
time.sleep(0.5)

# enable wakeup source from INT pin
py.setup_int_pin_wake_up(False)

# enable activity and also inactivity interrupts, using the default callback handler
py.setup_int_wake_up(True, True)

acc = LIS2HH12()
# enable the activity/inactivity interrupts
# set the accelereation threshold to 2000mG (2G) and the min duration to 200ms
acc.enable_activity_interrupt(1500, 160)

# check if we were awaken due to activity
if acc.activity():
    pycom.rgbled(0xFF0000)
    coord = l76.coordinates()
    #f.write("{} - {}\n".format(coord, rtc.now()))

    print("{} - {} - {}".format(coord, rtc.now(), gc.mem_free()))
    print("ACTIVITY!")
#    s.send(bytes([0x01, 0x02, 0x03]))
#    s.setblocking(False)
else:
    pycom.rgbled(0x00FF00)  # timer wake-up

# go to sleep for 5 minutes maximum if no accelerometer interrupt happens

# send some data


# make the socket non-blocking
# (because if there's no data received it will block forever...)
# s.setblocking(False)

# get any data received (if any...)
# data = s.recv(64)
# print(data)
