from kivy.app import App
from kivy.core.window import Window
from kivy.uix.floatlayout import FloatLayout


class OneBut(FloatLayout):
	def butclick(self):
		self.ids.toplabel.text='Hello again'

class MainApp(App):
	def build(self):
		Window.size = (300, 200)
		self.load_kv('onebut.kv')
		return OneBut()

MainApp().run()