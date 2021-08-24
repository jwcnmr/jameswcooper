import wx
from dataclasses import dataclass

# abstract Button class
class ComdButton(wx.Button):
    def __init__(self, panel, label):
        super().__init__(panel, label = label)
        self.Bind(wx.EVT_BUTTON, self.comd)

    # filled in later in derived classes
    def comd(self, e): pass

# derived label class- all labels are blue
class BlueLabel(wx.StaticText):
    def __init__(self, panel,sz, text:str):
        super().__init__(panel,  label= text,
                                size=wx.DefaultSize, style=0)
        font = wx.Font(sz, wx.DECORATIVE, wx.NORMAL, wx.NORMAL)

        self.SetFont(font)
        self.SetForegroundColour('blue')

# The Mediator handles the button, entry field and label interactions
@dataclass
class Mediator():
    num1: wx.TextCtrl
    num2: wx.TextCtrl
    result: BlueLabel

    # the addition is carried out here
    def addClicked(self):
        try:
            value1 = float(self.num1.GetValue())
            value2 = float(self.num2.GetValue())
            self.result.SetLabel("The sum is: " + str(value1 + value2))
        except ValueError:
            self.result.SetLabel("Not numbers")

    # clear the fields
    def clearClicked(self):
        self.result.SetLabel('')
        self.num1.SetValue('')
        self.num2.SetValue('')

# Add button derived from DButton
class AddButton(ComdButton):
    def __init__(self, panel, med):
        super().__init__(panel, "Add")
        self.med = med

    # called by base class
    def comd(self, e):
        self.med.addClicked()

# clear Button clears the entyr fields and the result
class ClearButton(ComdButton):
    def __init__(self, panel, med):
        super().__init__(panel, "Clear")
        self.med = med

# called by base class
    def comd(self, e):
        self.med.clearClicked()

# Main program is in this class
class AddFrame(wx.Frame):
    def __init__(self):
        super().__init__(parent=None, title='Addition')
        self.SetInitialSize((300,200))
        panel = wx.Panel(self)  # contains all the widgets
        gbSizer = wx.GridBagSizer(5,3) # here is the layout

        # Top row is the label
        topLabel = BlueLabel(panel,12, "Add two numbers")
        gbSizer.Add(topLabel, (0,0), wx.GBSpan(1,3), wx.ALIGN_CENTER)

        # first label and entry field
        n1label = BlueLabel(panel,10, "Num1: ")
        gbSizer.Add(n1label, (1,1),)
        self.num1 = wx.TextCtrl(panel)
        gbSizer.Add(self.num1, (1,2))

        # second label and entry field
        n2label = BlueLabel(panel,10, "Num2: ")
        gbSizer.Add(n2label, (2, 1))
        self.num2 = wx.TextCtrl(panel)
        gbSizer.Add(self.num2, (2, 2))

        self.sumLabel = BlueLabel(panel,12, "The sum is")
        gbSizer.Add(self.sumLabel, (4,1))

        # create the Mediator to handle the interactions
        med = Mediator(self.num1, self.num2, self.sumLabel)

        # create the two buttons
        addBtn = AddButton(panel, med)
        gbSizer.Add(addBtn, (3,1))

        clrBtn = ClearButton(panel, med)
        gbSizer.Add(clrBtn, (3, 2))
        panel.SetSizer(gbSizer)

        # Show the window
        self.Show()

# program starts here
if __name__ == '__main__':
    app = wx.App()
    frame = AddFrame()
    app.MainLoop()