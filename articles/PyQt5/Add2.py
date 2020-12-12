"""
Adds two numbers in entry fields using tje PyQt5 widgets
"""
import sys
from PyQt5 import Qt
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *


class Builder(QWidget):
    def __init__(self, app):
        super().__init__()
        self.app = app

    # Click event: if both are legal numbers
    # adds them together and puts sum in lower label
    # otherwise show an error messagebox
    def doAddition(self):
        try:
            val1 = float(self.num1.text())
            val2 = float(self.num2.text())
            sum = val1 + val2
            self.sumLabel.setText("The sum is: "+ str(sum))
        except:
            msgbox = QMessageBox()
            msgbox.setText("Values must be numbers")
            msgbox.exec_() #display the message


    # creates the widgets in the window
    # send sets up the click event
    def build(self):
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Add 2 numbers')
        self.vbox = QVBoxLayout()
        # all labels will be blue
        self.setStyleSheet("QLabel { color : blue; }")

        topmesg= QLabel("Enter two numbers to add")
        topmesg.setAlignment(Qt.AlignLeft)
        self.vbox.addWidget(topmesg)

        # sets labels and entry fields
        l1box = QHBoxLayout()
        l1box.addWidget(QLabel("Num1:"))
        self.num1 = QLineEdit()
        l1box.addWidget(self.num1)
        self.vbox.addLayout(l1box)

        l2box = QHBoxLayout()
        l2box.addWidget(QLabel("Num2:"))
        self.num2 = QLineEdit()
        l2box.addWidget(self.num2)
        self.vbox.addLayout(l2box)

        # Add button
        hLayout = QHBoxLayout()
        self.calcButton =QPushButton("Add")
        hLayout.addStretch(1)
        hLayout.addWidget(self.calcButton)
        hLayout.addStretch(2)
        self.vbox.addLayout(hLayout)
        self.calcButton.clicked.connect(self.doAddition)

        # bottom lebel, where sum appears
        self.sumLabel = QLabel("Sum")
        self.vbox.addWidget(self.sumLabel)
        self.sumLabel.setAlignment(Qt.AlignCenter)

        self.setLayout(self.vbox)
        self.show()

def main():
    app = QApplication(sys.argv)
    builder =Builder(app)
    builder.build()
    sys.exit(app.exec_())


###  Here we go  ####
if __name__ == "__main__":
    main()