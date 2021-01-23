"""
Adds two numbers in entry fields using the PyQt5 widgets
"""
import sys
from PyQt5 import Qt
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

# Mediator handles button, label and entry fields
class Mediator():
    # save entry fields
    def setFields(self,n1, n2):
        self.num1 = n1
        self.num2 = n2

    # save Sum label
    def setLabel(self, lb):
        self.sumLabel = lb

    # Add button is clicked
    def addClick(self):
        try:
            val1 = float(self.num1.text())
            val2 = float(self.num2.text())
            sum = val1 + val2
            self.sumLabel.setText("The sum is: " + str(sum))
        except:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Conversion error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText("Values must be numbers")
            msgbox.exec_()  # display the message

# abstract DButton class
class DButton(QPushButton):
    def __init__(self, text):
        super().__init__(text)
        # connect click event
        self.clicked.connect(self.comd)
    def comd(self):
        pass

# Add button is derived from QPushButton
class AddButton(DButton):
    def __init__(self, med):
        super().__init__("Add")
        self.med = med

    # called when button clicked
    def comd(self):
        self.med.addClick()

# Builds user interface
class Builder(QWidget):
    def __init__(self):
        super().__init__()

    # creates the widgets in the window
    # send sets up the click event
    def build(self):
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Add 2 numbers')

        # all labels will be blue
        self.setStyleSheet("QLabel {color : blue; }")

        # create outer vbox
        self.vbox = QVBoxLayout()
        topmesg= QLabel("Enter two numbers to add")
        topmesg.setAlignment(Qt.AlignLeft)
        self.vbox.addWidget(topmesg)

        # sets first label and entry field
        l1box = QHBoxLayout()
        l1box.addWidget(QLabel("Num1:"))
        self.num1 = QLineEdit()
        l1box.addWidget(self.num1)
        self.vbox.addLayout(l1box)

        # second label and entry field
        l2box = QHBoxLayout()
        l2box.addWidget(QLabel("Num2:"))
        self.num2 = QLineEdit()
        l2box.addWidget(self.num2)
        self.vbox.addLayout(l2box)

        # create Mediator and set fields
        self.med= Mediator()
        self.med.setFields(self.num1, self.num2)

        # Add button
        # Surround Add button with 2 stretch fillers
        hLayout = QHBoxLayout()
        self.calcButton =AddButton(self.med)
        hLayout.addStretch(1)
        hLayout.addWidget(self.calcButton)
        hLayout.addStretch(1)
        self.vbox.addLayout(hLayout)

        # bottom label, where sum appears
        self.sumLabel = QLabel("Sum")
        self.vbox.addWidget(self.sumLabel)
        self.sumLabel.setAlignment(Qt.AlignCenter)
        self.med.setLabel(self.sumLabel)

        # set the vbox as the main layout object
        self.setLayout(self.vbox)
        self.show()     # wait for user input

def main():
    # start the PyQt engine
    app = QApplication(sys.argv)
    builder =Builder()  #build the UI
    builder.build()
    sys.exit(app.exec_())

###  Here we go  ####
if __name__ == "__main__":
    main()