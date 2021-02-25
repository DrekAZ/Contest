# coding: utf-8

import sys
from PIL import Image, ImageFont, ImageDraw
import numpy as np
import cv2

cap =cv2.VideoCapture('roomVideo.mp4') # 0:camera 'FileName'

font = cv2.FONT_HERSHEY_SIMPLEX

while ( cap.isOpened() ):
	ret, frame = cap.read() # ret = flag of reading image from camera
	#width, height = frame.size
	
	#gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	
	###
	###
	
	cv2.imshow('frame', gray) # img show
	
	if cv2.waitKey(25) & 0xFF == ord('q'): # waitkey: waiting input from keyboard for 1ms
		break                               # returnValue and 0xff=ASCII then ord(q to ASCII)

cap.release()
cv2.destroyAllWindows()
 