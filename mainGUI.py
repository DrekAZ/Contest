#!/usr/bin/python
# -*- Coding: utf-8 -*-

import sys
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QGridLayout, QLabel
class guy(QWidget):
	def __init__(self):
		super().__init__()
		self.initUI()
	
	def initUI(self):
		self.resize(600, 300)
		self.move(300,300)
		self.setWindowTitle('メイン画面')
		
		# button
		self.button = QPushButton('START')
		self.label = QLabel('START OK')
		
		# layout
		self.grid = QGridLayout()
		self.grid.addWidget(self.button, 0, 0, 1, 1)
		self.button.clicked.connect(self.labelShow)
		self.setLayout(self.grid)
		
		self.show()
	def labelShow(self):
		self.grid.addWidget(self.label, 1, 0, 1, 2)

if __name__ == '__main__':
	app = QApplication(sys.argv)
	w = guy()
	sys.exit(app.exec_())