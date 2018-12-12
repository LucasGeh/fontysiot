from gps import GPS
import time
from pytrack import Pytrack
from connection_abp import Connection
from LIS2HH12 import LIS2HH12
import pycom

conn = Connection('260118E1', 'E0646E0CFD8F7DBF45BAC9E01831A2BF', '22539E2D4177D515BB6510F6349F6957')

py = Pytrack()

gps = GPS(py, 120)

while gps.hasGPS() != True:
    gps.printGPS()
    time.sleep(10)

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
    con.setblocking(False)
else:
    # pycom.rgbled(0x00FF00)
    conn.setblocking(True)
    conn.send(gps.getCoordinates())
    conn.setblocking(False)

py.setup_sleep(60)
py.go_to_sleep()
