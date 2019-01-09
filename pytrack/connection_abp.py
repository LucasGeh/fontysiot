from network import LoRa
import socket
import ubinascii
import struct



class Connection:

    def __init__(self,
    dev_addr, nwk_swkey, app_swkey):
        # create an ABP authentication params
        self.Dev_addr = struct.unpack(">l", ubinascii.unhexlify(dev_addr))[0]
        self.Nwk_swkey = ubinascii.unhexlify(nwk_swkey)
        self.App_swkey = ubinascii.unhexlify(app_swkey)
        # Initialise LoRa in LORAWAN mode.
        # Please pick the region that matches where you are using the device:
        # Asia = LoRa.AS923
        # Australia = LoRa.AU915
        # Europe = LoRa.EU868
        # United States = LoRa.US915
        self.Lora = LoRa(mode=LoRa.LORAWAN, region=LoRa.EU868)
        # join a network using ABP
        self.Lora.join(activation=LoRa.ABP, auth=(self.Dev_addr, self.Nwk_swkey, self.App_swkey))
        # create a LoRa socket
        self.Socket = socket.socket(socket.AF_LORA, socket.SOCK_RAW)
        # set the LoRaWAN data rate
        self.Socket.setsockopt(socket.SOL_LORA, socket.SO_DR, 5)

    def setblocking(self, blocking):
        self.Socket.setblocking(blocking)

    def receive(self):
        return self.Socket.recv(64)

    def send(self, coordinates):
        strCoordinates = str(coordinates)
        self.Socket.send(strCoordinates)
