from network import LoRa
import socket
import ubinascii
import struct
import time


class Connection:

    def __init__(self, app_eui, app_key):
        # create an OTAA authentication parameters
        self.App_eui = ubinascii.unhexlify(app_eui)
        self.App_key = ubinascii.unhexlify(app_key)
        # Initialise LoRa in LORAWAN mode.
        # Please pick the region that matches where you are using the device:
        # Asia = LoRa.AS923
        # Australia = LoRa.AU915
        # Europe = LoRa.EU868
        # United States = LoRa.US915
        self.Lora = LoRa(mode=LoRa.LORAWAN, region=LoRa.EU868)
        # join a network using OTAA (Over the Air Activation)
        self.Lora.join(activation=LoRa.OTAA, auth=(self.App_eui, self.App_key), timeout=0)
        # wait until the module has joined the network
        while not self.Lora.has_joined():
            time.sleep(2.5)
            print('Not yet joined...')

    def setblocking(self, blocking):
        self.Socket.setblocking(blocking)

    def receive(self):
        return self.Socket.recv(64)

    def send(self):
        self.Socket.send(bytes([0x01, 0x02, 0x03]))
