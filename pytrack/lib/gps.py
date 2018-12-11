import pycom
from L76GNSS import L76GNSS

class GPS:
    def __init__(self, py):
        # setup GPS
        self.L76 = L76GNSS(py, timeout=30)
        while not (self.L76.coordinates() is None):
            self.printGPS()
            print("e")


    def printGPS(self):
        print(self.L76.coordinates())

    def getCoordinates(self):
        return self.L76.coordinates()
