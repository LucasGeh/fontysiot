from gps import GPS
import time
from pytrack import Pytrack
from connection_otaa import Connection
from LIS2HH12 import LIS2HH12
import pycom

conn = Connection('70B3D57ED0015419', 'CA137963FA80E48A44B17973DED1977A')

py = Pytrack()

gps = GPS(py, 120)
counter = 0
while counter < 20:
    if gps.hasGPS() == True:
        break
    else:
        time.sleep(2)
        gps.printGPS()
        counter+=1

gps.printGPS()

print("Wakeup reason: " + str(py.get_wake_reason()) + "; Aproximate sleep remaining: " + str(py.get_sleep_remaining()) + " sec")
time.sleep(0.5)

# enable wakeup source from INT pin
py.setup_int_pin_wake_up(False)

# enable activity and also inactivity interrupts, using the default callback handler
py.setup_int_wake_up(True, True)

acc = LIS2HH12()
# enable the activity/inactivity interrupts
# set the accelereation threshold to 2000mG (2G) and the min duration to 200ms
acc.enable_activity_interrupt(2000, 300)

if acc.activity():
    # pycom.rgbled(0xFF0000)
    conn.setblocking(True)
    conn.send(gps.getCoordinates())
    conn.setblocking(False)
else:
    # pycom.rgbled(0x00FF00)
    conn.setblocking(True)
    conn.send(gps.getCoordinates())
    conn.setblocking(False)

py.setup_sleep(60)
py.go_to_sleep()
