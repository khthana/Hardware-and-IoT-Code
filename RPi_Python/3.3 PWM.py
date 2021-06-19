import RPi.GPIO as GPIO 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(24,GPIO.OUT)
blink = GPIO.PWM(24,2)
blink.start(50)
while True:
	pass
