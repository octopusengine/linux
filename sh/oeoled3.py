import RPi.GPIO as GPIO
import time

import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306
#
import sys

# print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)
arg1 = str(sys.argv[1])
arg2 = str(sys.argv[2])
arg3 = str(sys.argv[3])

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

# Raspberry Pi pin configuration:
RST = None

# 128x64 display with hardware I2C:
fontPath="/usr/share/fonts/truetype/ttf-dejavu/DejaVuSans.ttf"
sans16 = ImageFont.truetype(fontPath, 16)
fontPath="/usr/share/fonts/truetype/ttf-dejavu/DejaVuSans-Bold.ttf"
sans16b = ImageFont.truetype(fontPath, 16)

disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)
leftD = 0
topD = 7
displEn = True

def doOLEDiko(obrName):
  obr = pygame.image.load("iko/"+obrName)
  for x in range(128):
    for y in range(16):
         col = obr.get_at((x,y))
         if col[0]>7:
           draw.point((x,y),fill=0)
         else:
           draw.point((x,y),fill=255)
  disp.image(image)
  disp.display()

def doInfo3(text1,text2,text3):
  global dislpEn
  if displEn:
    #draw.rectangle((0,15,width,55), outline=0, fill=0)
    draw.text((leftD, topD),text1,  font=sans16, fill=255)
    draw.text((leftD, topD+19),text2,  font=sans16, fill=255)
    draw.text((leftD, topD+38),text3,  font=sans16, fill=255)
    disp.image(image)
    disp.display()
  else:
    print("Displ." + text1 + " # " + text2)

# -----------------------------------------------------Initialize library.
print("oled2 - start")
disp.begin()

# Clear display.
disp.clear()
disp.display()

# Create blank image for drawing.
# Make sure to create image with mode '1' for 1-bit color.
width = disp.width
height = disp.height
image = Image.new('1', (width, height))

# Get drawing object to draw on image.
draw = ImageDraw.Draw(image)

#draw.polygon([(20, 20), (30, 2), (40, 20)], outline=255, fill=0)
#disp.image(image)
#disp.display()
#time.sleep(3)

#doInfoBig12("octopusengine.org","192.168.0.208")
#doInfoBig12(arg1,arg2)
doInfo3(arg1,arg2,arg3)


