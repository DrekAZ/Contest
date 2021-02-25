import sys
import RPi.GPIO as GPIO
import dht11
import time
import datetime
import threading

GPIO.setwarnings(False)       # 2
GPIO.setmode(GPIO.BCM)
GPIO.cleanup()
# read data using pin 14
instance = dht11.DHT11(pin=4)      # 3

temper = '0'
humidi = '0'
d = 0
cond = True

def f():
    global cond
    time.sleep(1)
    cond = False


def senseL():
    while True:
        print("wwwwwwwww")
        #d = d+1
        result = instance.read()
        if result.is_valid():    # 5
            temper = str(result.temperature)
            humidi = str(result.humidity)
            d = result.humidity
            #break

class GpioOutputPin:
     def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.OUT)
     def on(self):
        GPIO.output(self.pin, GPIO.LOW)
     def off(self):
        GPIO.output(self.pin, GPIO.HIGH)
     def takon(self):
        GPIO.output(self.pin, GPIO.HIGH)
     def takoff(self):
        GPIO.output(self.pin, GPIO.LOW)


# GPIO ports for 8-segment LED pins
TOP = GpioOutputPin(11)
CENTER = GpioOutputPin(18)
BOTTOM = GpioOutputPin(8)
LEFT_UPPER = GpioOutputPin(10)
LEFT_LOWER = GpioOutputPin(7) ### 7777777
RIGHT_UPPER = GpioOutputPin(21)
RIGHT_LOWER = GpioOutputPin(23)
DOT = GpioOutputPin(25)

SET = GpioOutputPin(20)#moter


# GPIO ports for digit pins
DIGITS = (
    GpioOutputPin(22),  # the most left side
    GpioOutputPin(27),
    GpioOutputPin(17),
    GpioOutputPin(24),  # the most right side
)

class SegmentPattern:
    LIGHT_ON = 1
    LIGHT_OFF = 0
    SEGMENTS = [TOP, RIGHT_UPPER, RIGHT_LOWER, BOTTOM,
                LEFT_LOWER, LEFT_UPPER, CENTER, DOT]

    def __init__(self, *lights):
        self.lights = lights

    def display(self, num):
        t = 0
        for segment, light in zip(self.SEGMENTS, self.lights):
            t = t + 1
            if light == self.LIGHT_ON:
                segment.on()
            elif t == 8 and num == 2:
                segment.on()
            else:
                segment.off()


NUMBERS = {
    ' ': SegmentPattern(0, 0, 0, 0, 0, 0, 0, 0),
    '0': SegmentPattern(1, 1, 1, 1, 1, 1, 0, 0),
    '1': SegmentPattern(0, 1, 1, 0, 0, 0, 0, 0),
    '2': SegmentPattern(1, 1, 0, 1, 1, 0, 1, 0),
    '3': SegmentPattern(1, 1, 1, 1, 0, 0, 1, 0),
    '4': SegmentPattern(0, 1, 1, 0, 0, 1, 1, 0),
    '5': SegmentPattern(1, 0, 1, 1, 0, 1, 1, 0),
    '6': SegmentPattern(1, 0, 1, 1, 1, 1, 1, 0),
    '7': SegmentPattern(1, 1, 1, 0, 0, 0, 0, 0),
    '8': SegmentPattern(1, 1, 1, 1, 1, 1, 1, 0),
    '9': SegmentPattern(1, 1, 1, 1, 0, 1, 1, 0),
}

INTERVAL = 0.005

thread1 = threading.Thread(target=senseL)
thread1.start()


f = 0

try:
    while True:
        c = 0
        while cond:
            threadF = threading.Thread(target=f)
            threadF.start()
            for digit, temp in zip(DIGITS, temper):
                #print("%c" % temp)
                #print("%d" % c)
                
                NUMBERS[temp].display(c)
                digit.takon()
                time.sleep(INTERVAL)
                digit.takoff()
                
                if(d == 30 and f == 0):
                    f = 1
                    SET.takon()
                    #time.sleep(0.001)
                    SET.takoff()
                
                c = c + 1
            print("//////////////////////////")
        cond = True
        c = 0
        while cond:
            threadF.start()
            for digit, humid in zip(DIGITS, humidi):
                NUMBERS[humid].display(c)
                digit.takon()
                time.sleep(INTERVAL)
                digit.takoff()
                c = c + 1

finally:
    GPIO.cleanup()
