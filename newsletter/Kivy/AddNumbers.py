from kivy.app import App
from kivy.core.window import Window
from kivy.uix.boxlayout import BoxLayout

class AddNums(BoxLayout):
	def build(self):
		self.title = "Add two numbers"
		Window.size = (300, 200)
		self.load_kv('AddNumbers.kv')

	# Add click event
	def bclick(self):
		val1= float(self.ids.frnum.text)
		val2 = float(self.ids.secnum.text)
		self.ids.sumlabel.text = "Sum is: "+ str(val1+val2)

	# Clear button click event
	def cclick(self):
		self.ids.frnum.text = ''
		self.ids.secnum.text = ''
		self.ids.sumlabel.text =''

class MainApp(App):
	def build(self):
		Window.size = (300, 200)
		self.load_kv('AddNumbers.kv')
		return AddNums()

MainApp().run()