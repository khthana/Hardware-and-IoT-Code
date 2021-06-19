import RPi.GPIO as GPIO 
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

pin1 = 24
pin2 = 25
pin3 = 26 

GPIO.setup(pin1,GPIO.OUT)
GPIO.setup(pin2,GPIO.OUT)
GPIO.setup(pin3,GPIO.OUT)

GPIO.output(pin1,False)
GPIO.output(pin2,False)
GPIO.output(pin3,False)

while True:
	GPIO.output(pin1,GPIO.HIGH)
	time.sleep(1)
	GPIO.output(pin1,GPIO.LOW)
	GPIO.output(pin2,GPIO.HIGH)
	time.sleep(1)
	GPIO.output(pin2,GPIO.LOW)	
	GPIO.output(pin3,GPIO.HIGH)
	time.sleep(1)
	GPIO.output(pin3,GPIO.LOW)
