# python pyboard.py --device COM6 -f cp main.py :

import array
import time
import rp2
# from machine import Pin, SoftI2C, PWM
# from ssd1306 import SSD1306_I2C
from machine import Pin, SoftSPI, PWM

from ST7735 import TFT
from sysfont import sysfont

PIN_NUM = 22
BRIGHTNESS = 0.2
NUM_LEDS = 64
# i2c = SoftI2C(scl=Pin(9), sda=Pin(8))
# oled = SSD1306_I2C(128, 64, i2c)
spi = SoftSPI(baudrate=2000000, polarity=0, phase=0, sck=Pin(2), mosi=Pin(1), miso=Pin(12))
oled = TFT(spi, 0, 3, 4)
oled.initb2()
oled.rgb(True)
pwm = PWM(Pin(5, Pin.OUT))
pwm.deinit()  # Turn off sound on init


# print('I2C Address: ' + hex(i2c.scan()[0]).upper())
# oled.fill(0)
# oled.text('HI THERE', 0, 0)
# oled.show()


@rp2.asm_pio(sideset_init=rp2.PIO.OUT_LOW, out_shiftdir=rp2.PIO.SHIFT_LEFT, autopull=True, pull_thresh=24)
def ws2812():
    """
    ARM 32 assembly LED NeoPixel driver function
    """
    T1 = 2
    T2 = 5
    T3 = 3
    wrap_target()
    label("bitloop")
    _ = out(x, 1).side(0)[T3 - 1]
    _ = jmp(not_x, "do_zero").side(1)[T1 - 1]
    _ = jmp("bitloop").side(1)[T2 - 1]
    label("do_zero")
    _ = nop().side(0)[T2 - 1]
    wrap()


# Create the StateMachine with the ws2812 program, outputting on Pin(22)
sm = rp2.StateMachine(0, ws2812, freq=8_000_000, sideset_base=Pin(22))

# Start the StateMachine, it will wait for data on its FIFO
sm.active(1)

# Display a pattern on the LEDs via an array of LED RGB values
ar = array.array("I", [0 for _ in range(NUM_LEDS)])

# Cycle colors
for i in range(4 * NUM_LEDS):
    for j in range(NUM_LEDS):
        r = j * 100 // (NUM_LEDS - 1)
        b = 100 - j * 100 // (NUM_LEDS - 1)
        if j != i % NUM_LEDS:
            r >>= 3
            b >>= 3
        ar[j] = r << 16 | b
    sm.put(ar, 8)
    time.sleep_ms(50)

# Fade out
for i in range(24):
    for j in range(NUM_LEDS):
        ar[j] >>= 1
    sm.put(ar, 8)
    time.sleep_ms(50)

oled.fill(TFT.BLACK)
oled.text((5, 5), 'Hello World', TFT.WHITE, sysfont, 1)