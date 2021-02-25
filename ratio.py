# coding: utf-8

import sys
from PIL import Image, ImageFont, ImageDraw
import numpy as np
import cv2

#if __name__ == '__main__':

img = cv2.imread( '2017.png', 0)

#img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

charset = [['0','1','!','2','\"','3','#','4','$','5','%','6','&','7','\'','8','(','9',')','-','=','^','~','\\'],
						['|','q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P','@','`','['],
						['{','a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L',';','+',':','*',']'],
						['}','z','Z','x','X','c','C','v','V','b','B','n','N','m','M',',','<','.','>','/','?','_']]

height = (img.shape[0]/5)
width = (img.shape[1]/24)

height = np.ceil(height) #83  418/5
width = np.ceil(width)   #42  1024/24

lt = 0 # left
tp = 0 # top
b = 83
r = 42
lis = [ [] for i in range(4) ]


for i in range(4):
	for j in range(24):
		img2 = img[tp:tp+83, lt:r]
		num = cv2.countNonZero(img2)
		lis[i].append( round (num/(83*42) *100, 2 ) )
		lt += 42
		r += 42
	tp += 83
	b += 83
	lt = 0
	r = 42

for i in range(4):
	for j in range(24):
		print(str(lis[i][j]) +  "__" + charset[i][j] + "\n")


#print(lis)
#cv2.imwrite('win.jpg', img2)
#cv2.waitKey()
#cv2.destroyAllWindows()

#cv2.imwrite("test.png", img2)

CHAR_LIST[min(int(np.mean(image[int(i * cell_height):min(int((i + 1) * cell_height), height),
                                          int(j * cell_width):min(int((j + 1) * cell_width),
                                                                  width)]) * num_chars / 255), num_chars - 1)])