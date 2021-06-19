import RPi.GPIO as GPIO 
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

pin_set = [24,25,26]

for pin in pin_set:
	GPIO.setup(pin,GPIO.OUT)
	GPIO.output(pin,False)

while True:
	for pin in pin_set:
		GPIO.output(pin,GPIO.HIGH)
		time.sleep(1)
		GPIO.output(pin,GPIO.LOW)
