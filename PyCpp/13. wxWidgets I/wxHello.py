# Import the wxPython package.
import wx

app = wx.App()  # Create an application object.
frm = wx.Frame(None, title="Hello World") # Then a frame.
frm.SetInitialSize((250, 200))  #et the size
frm.Show()  # Show it.

# Start the event loop.
app.MainLoop()