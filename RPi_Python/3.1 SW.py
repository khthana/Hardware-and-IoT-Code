import RPi.GPIO as GPIO 
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

input_pin = 21

GPIO.setup(24,GPIO.OUT)
GPIO.setup(input_pin,GPIO.IN, pull_up_down=GPIO.PUD_UP)

'''
while(1):
	state = GPIO.input(input_pin)
	if (state == GPIO.HIGH):
		print ("Button Pressed")
	else:
		print ("Button OK")
	time.sleep(0.5)
'''

while(1):
	GPIO.wait_for_edge(input_pin,GPIO.FALLING)
	print ("Button OK")
	GPIO.output(24,1)
	time.sleep(1)
	GPIO.output(24,0)
	time.sleep(1)
	
