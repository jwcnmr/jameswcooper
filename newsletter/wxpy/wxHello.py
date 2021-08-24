# Import the wxPython package.
import wx

app = wx.App()  # Create an application object.
frm = wx.Frame(None, title="Hello World") # Then a frame.
frm.Show()  # Show it.

# Start the event loop.
app.MainLoop()