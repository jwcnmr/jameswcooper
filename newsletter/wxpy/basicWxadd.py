import wx

# Main frame
class AddFrame(wx.Frame):
    def __init__(self):
        super().__init__(parent=None, title='Addition')
        self.SetInitialSize((300, 200))
        panel = wx.Panel(self)  # contains all the widgets
        gbSizer = wx.GridBagSizer(5, 3)  # here is the layout

        # Top row is the label spanning cell 1 and 2
        topLabel = wx.StaticText(panel, label="Add two numbers",
                                size=wx.DefaultSize, style=0)
        gbSizer.Add(topLabel, (0, 0), wx.GBSpan(1, 3), wx.ALIGN_CENTER)

        # first label and entry field
        n1label = wx.StaticText(panel, label="Num1: ", size=wx.DefaultSize, style=0)
        gbSizer.Add(n1label, (1, 1), )
        self.num1 = wx.TextCtrl(panel)
        gbSizer.Add(self.num1, (1, 2))

        # second label and entry field
        n2label = wx.StaticText(panel, label="Num2: ", size=wx.DefaultSize, style=0)
        gbSizer.Add(n2label, (2, 1))
        self.num2 = wx.TextCtrl(panel)
        gbSizer.Add(self.num2, (2, 2))

        # sum goes here
        self.sumLabel = wx.StaticText(panel, label= "The sum is", size=wx.DefaultSize, style=0)
        gbSizer.Add(self.sumLabel, (3, 1))

        # create the two buttons
        # add button
        addBtn = wx.Button(panel, label='Add')
        addBtn.Bind(wx.EVT_BUTTON, self.addClicked)
        gbSizer.Add(addBtn, (4, 1))

        # clear button
        clrBtn = wx.Button(panel, label='Clear')
        clrBtn.Bind(wx.EVT_BUTTON, self.clearClicked)
        gbSizer.Add(clrBtn, (4, 2))
        panel.SetSizer(gbSizer) # set the sizer into the panel

        # Show the window
        self.Show()

    def addClicked(self, e):
        try:
            value1 = float(self.num1.GetValue())
            value2 = float(self.num2.GetValue())
            self.sumLabel.SetLabel("The sum is: " + str(value1 + value2))
        except ValueError:
            self.sumLabel.SetLabel("Not numbers")

        # clear the fields
    def clearClicked(self, e):
        self.sumLabel.SetLabel('')
        self.num1.SetValue('')
        self.num2.SetValue('')


# program starts here
if __name__ == '__main__':
    app = wx.App()
    frame = AddFrame()
    app.MainLoop()