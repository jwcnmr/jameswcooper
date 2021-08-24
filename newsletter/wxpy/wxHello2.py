# Import the wxPython package.
import wx

app = wx.App()  # Create an application object.
frm = wx.Frame(None, title="Hello World") # Then a frame.
frm.SetInitialSize((300, 200))
panel = wx.Panel(frm)  # contains all the widgets

# create the label and place it at 20,20
st = wx.StaticText(panel, label="Hello World!")
st.SetPosition((20,20))
frm.Show()  # Show it.

app.MainLoop()