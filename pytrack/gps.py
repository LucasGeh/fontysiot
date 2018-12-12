import pycom
from L76GNSS import L76GNSS

class GPS:
    # setups the gps with an object of Pytrack and a timeout
    def __init__(self, py, to):
        # setup GPS
        self.L76 = L76GNSS(py, timeout=to)

    def printGPS(self):
        print(self.L76.coordinates())

    def getCoordinates(self):
        return self.L76.coordinates()

    def hasGPS(self):
        none = '(None, None)'
        coord = self.L76.coordinates()
        if none != str(coord):
            return True
        else:
            return False
