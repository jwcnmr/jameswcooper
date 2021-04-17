from kivy import Config
from kivy.app import App
from kivy.core.window import Window


class MainApp(App):
	def build(self):
		self.title = "Calculator"
		Window.size = (250, 300)
		self.load_kv('calc.kv')
	def getEntry(self):
		return self.root.ids.calctext.text
	def setEntry(self, val):
		self.root.ids.calctext.text = val
	def numClick(self, val):
		cString = self.getEntry()
		self.setEntry(cString + val)

	# calculate the result of the expression
	# in the text field
	def calcClick(self):
		try:
			cString = self.getEntry()
			result = eval(cString)
		except:
			self.setEntry("Syntax error")
		else:
			self.setEntry(str(result))

	def clearEntry(self):
		self.root.ids.calctext.text = ""
	def chgSign(self):
		lbstring = self.getEntry()
		sign = lbstring[0:1]  # get first char
		if sign.isnumeric():
			lbstring = " "+lbstring
			sign=" "
		if sign == "-":
			sign = " "
		elif sign==" ":
			sign = "-"
		else:
			lbstring = sign + lbstring
		lbstring = sign + lbstring[1:]  # append new sign to rest
		self.setEntry(lbstring)

MainApp().run()