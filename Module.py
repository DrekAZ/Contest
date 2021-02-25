#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys
#from tkinter import *
from tkinter import Tk, ttk
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

#file input output pricehikaku change 

#def __init__(self):
options = Options()
options.add_argument('--headless')
options.add_argument('--disable-gpu')
driver = webdriver.Chrome(chrome_options=options)
#driver.get('https://www.google.com')
#print(driver.page_source)

class ListApp(ttk.Frame):
	def __init__(self, master=None):
		super().__init__(master)
		
def main():
	root = Tk()
	root.title(u"TITLE")
	root.geometry("500x500")
	la = ttk.Label(root, text="form")
	la.grid()
	form = ttk.Entry(root)#border
	form.bind('<Return>', lambda e: input(form) )
	# lambda ev: la.configure(text='Clicked left mouse button'
	form.grid()
	root.mainloop() # main
	
def input(self):
	driver.get(self.get())
	#print(driver.page_source)
	#print (driver.find_element_by_class_name("a-size-large")) # classでの指定
	title = driver.find_element_by_id("productTitle")
	img = driver.find_element_by_tag_name('image')
	prace = driver.find_element_by_tag_name('')
	
	setItem(obj.text, img.png, )
	#driver.find_element_by_id("id")  idでの指定
	#driver.find_element_by_xpath("xpath")  xpathでの指定
	#https://www.amazon.co.jp/%E4%B8%8B%E7%94%BA%E3%83%AD%E3%82%B1%E3%83%83%E3%83%88-%E3%83%A4%E3%82%BF%E3%82%AC%E3%83%A9%E3%82%B9-%E6%B1%A0%E4%BA%95%E6%88%B8-%E6%BD%A4/dp/409386523X/ref=sr_1_4?m=AN1VRQENFRJN5&s=books&ie=UTF8&qid=1543887164&sr=1-4

def closeEvent(self, event):
	driver.close()

def setItem(self, item):
	l1 = ttk.Label(root, self)
	l1.grid()
	


#driver.get(str)
if __name__ == '__main__':
	main()

#driver.close()
