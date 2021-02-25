#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

def closeEvent(self, event):
	driver.close()

def main():
	options = Options()
	options.add_argument('--headless')
	options.add_argument('--disable-gpu')
	driver = webdriver.Chrome(chrome_options=options)
	driver.get("https://auctions.yahoo.co.jp/closedsearch/closedsearch?auccat=2084039759&b=51&n=50&select=3") # low high average!
	tagList = driver.find_element_by_class("range")
	prace = tagList.find_elements_by_tag_name("a")
	print(prace[0])
	print(prace[1])
	print(prace[2])
	
	
if __name__ == '__main__':
	main()