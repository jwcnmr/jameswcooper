import sys

from PyQt5.QtWidgets import QWidget, QGroupBox, QGridLayout, QVBoxLayout, QRadioButton, QApplication, QPushButton, \
    QMessageBox, QLineEdit

# The Mediator saves a reference to the entry field
# and copies text into the field when setVoice is called
class Mediator():
    # save the entry field reference
    def setEntry(self, entry):
        self.entry = entry

    # copy the text into the entry field
    def setVoice(self, text):
        self.entry.clear()
        self.entry.insert(text)

# derived Radio button whose click
# tells the mediator to load the rolename text field
class VcRadioButton(QRadioButton):
    def __init__(self, label, title, med):
        super().__init__(label)
        self.title = title  #save the title
        self.med = med      # and copy the Mediator reference
        # connect the button clicks to the comd method
        self.toggled.connect(self.comd) # all 4 call the same onClicked method

    # returns title stored in this class instance
    def getTitle(self):
        return self.title

    # gets the title and puts it in the character entry field
    # using the Mediator
    def comd(self):
        radio = self.sender()   #get the button you clicked
        if radio.isChecked():   # if checked copy the title
            self.med.setVoice(radio.getTitle())



class Builder(QWidget):
    def __init__(self,app):
        super().__init__()
        self.app = app
        self.build()

    def build(self):
        self.setGeometry(300, 300, 100, 100)
        self.setWindowTitle('Voice type')
        grid = QGridLayout()
        # create the entry field
        self.entry = QLineEdit()
        grid.addWidget(self.entry,0,0)

        # Create Mediator and
        # and pass it the entry reference
        self.med = Mediator()
        self.med.setEntry(self.entry)

        # Create s GroupBox for the four radio buttons
        self.voiceBox = QGroupBox("Voice part")
        vcGrid = QGridLayout()

        # create the four radio buttons and labels
        vs = VcRadioButton("S", "Soprano", self.med)
        va = VcRadioButton("A", "Alto", self.med)
        vt = VcRadioButton("T", "Tenor", self.med)
        vb = VcRadioButton("B", "Bass", self.med)
        # and add them to the 2 x 2 grid
        vcGrid.addWidget(vs, 0, 0)
        vcGrid.addWidget(va, 0, 1)
        vcGrid.addWidget(vt, 1, 0)
        vcGrid.addWidget(vb, 1, 1)

        self.voiceBox.setLayout(vcGrid)
        grid.addWidget(self.voiceBox, 1, 0)
        self.setLayout(grid)


        self.show()


def main():
    app = QApplication(sys.argv)
    app.setStyle('Fusion')
    builder =Builder(app)

    sys.exit(app.exec_())


    #mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()