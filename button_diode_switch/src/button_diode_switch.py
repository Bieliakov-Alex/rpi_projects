import RPi.GPIO as GPIO
import time

ledPin = 11
buttonPin = 12
light = False
button_pressed = False

def setup():
	print('Program is starting...')
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(ledPin, GPIO.OUT)
	GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def loop():
	global light
	global button_pressed
	while True:
		if GPIO.input(buttonPin) == GPIO.LOW:
			time.sleep(0.1)
			if light == False:
				GPIO.output(ledPin, GPIO.HIGH)
				print('led on...')
			else:
				GPIO.output(ledPin, GPIO.LOW)
				print('led off...')
			button_pressed = True
		elif button_pressed == True:
			light = not light
			button_pressed = False

def destroy():
	GPIO.output(ledPin, GPIO.LOW)
	GPIO.cleanup()
	
if __name__ == '__main__':
	setup()
	try:
		loop()
	except KeyboardInterrupt:
		destroy()
