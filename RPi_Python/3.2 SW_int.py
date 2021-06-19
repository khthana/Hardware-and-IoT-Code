import RPi.GPIO as GPIO 
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

input_pin = 21

def button_pressed(channel):
	GPIO.output(24,1)
	time.sleep(1)
	GPIO.output(24,0)
	time.sleep(1)

GPIO.setup(24,GPIO.OUT)
GPIO.setup(input_pin,GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(input_pin, GPIO.RISING, callback=button_pressed, bouncetime=300)
while(1):
	pass
