import RPi.GPIO as GPIO

buzzerPin = 11
buttonPin = 12


def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(buzzerPin, GPIO.OUT)
    GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)


def loop():
    while True:
        if GPIO.input(buttonPin) == GPIO.LOW:
            GPIO.output(buzzerPin, GPIO.HIGH)
            print('buzzer turned on >>>')
        else:
            GPIO.output(buzzerPin, GPIO.LOW)
            print('buzzer turned off <<<')


def destroy():
    GPIO.cleanup()


if __name__ == '__main__':
    print('Program is starting...')
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        destroy()
