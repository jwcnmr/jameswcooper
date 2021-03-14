from PyQt5 import QtWidgets
import sys

from PyQt5.QtWidgets import QGridLayout, QApplication, QWidget, QFrame, \
    QListWidget, QLabel, QLineEdit, QHBoxLayout, QPushButton


class RoleButton(QtWidgets.QRadioButton):
    rindex =0
    roles = ["Lead", "Minr", "Chor"]
    def __init__(self,  label, index):
        super().__init__( label)
        self.index = index
        self.clicked.connect(self.click)
    def click(self):
        RoleButton.rindex = self.index

class VoiceButton(QtWidgets.QRadioButton):
    vindex = 0
    voices =["Sop", "Alt", "Ten", "Bas"]
    def __init__(self,  label, index):
        super().__init__(label)
        self.index = index
        self.clicked.connect(self.click)
    def click(self):
        VoiceButton.vindex = self.index

# Mediator class handles interactions
class Mediator():
    def __init__(self, entry: QLineEdit, nlist: QListWidget):
        self.entry = entry
        self.list = nlist

    def addClick(self):
        name = self.entry.text()
        print(name)
        voice = VoiceButton.voices[VoiceButton.vindex]
        role = RoleButton.roles[RoleButton.rindex]
        ltext = voice+" "+role+" - "+name
        self.list.addItem(ltext)
        self.entry.setText("")

    def clearClick(self):
        self.entry.setText("")
        self.list.clear()

class Builder(QWidget):
    def __init__(self, app):
        super().__init__()
        self.app = app
        self.build()

    def build(self):
        self.setGeometry(375, 300, 435, 316)
        self.setWindowTitle('Cast list')
        self.grid = QGridLayout()

        #List of voice types
        self.voiceBox = QFrame()
        self.voiceGrid = QGridLayout()  # in a grid layout

        vs = VoiceButton("Soprano", 0)
        vs.setChecked(True)     # first one is checked
        va = VoiceButton("Alto", 1)
        vt = VoiceButton("Tenor", 2)
        vb = VoiceButton("Bass", 3)
        self.voiceGrid.addWidget(vs, 0, 0)
        self.voiceGrid.addWidget(va, 1, 0)
        self.voiceGrid.addWidget(vt, 2, 0)
        self.voiceGrid.addWidget(vb, 3, 0)
        self.voiceBox.setLayout(self.voiceGrid)
        self.grid.addWidget(self.voiceBox, 0, 0)

        # List of part names
        self.partBox = QFrame()
        self.partGrid = QGridLayout()
        rp = RoleButton("Principal", 0)
        rp.setChecked(True)     # first one is checked
        rm = RoleButton("Minor lead", 1)
        rc = RoleButton("Chorus", 2)
        self.partGrid.addWidget(rp, 0, 0)
        self.partGrid.addWidget(rm, 1, 0)
        self.partGrid.addWidget(rc, 2, 0)
        self.partBox.setLayout(self.partGrid)
        self.grid.addWidget(self.partBox, 0, 1)

        # create listbox
        self.nameList = QListWidget()
        self.grid.addWidget(self.nameList, 0, 2)
        self.grid.setColumnMinimumWidth(2, 275)

        # create Label and entry field
        self.lbl = QLabel("Name: ")
        self.nameField = QLineEdit()
        self.hbox1 = QHBoxLayout()
        self.hbox1.addWidget(self.lbl)
        self.hbox1.addWidget(self.nameField)
        self.grid.addLayout(self.hbox1, 1, 0, 1, 2)

        # create Add and Clear buttons
        self.addButton = QPushButton("Add")
        self.clearButton = QPushButton("Clear")
        self.hbox2 = QHBoxLayout()
        self.hbox2.addStretch(1)
        self.hbox2.addWidget(self.addButton)
        self.hbox2.addWidget(self.clearButton)
        self.hbox2.addStretch(1)
        self.grid.addLayout(self.hbox2, 2, 0, 1, 3)

        self.med = Mediator(self.nameField, self.nameList)
        self.addButton.clicked.connect(self.med.addClick)
        self.clearButton.clicked.connect(self.med.clearClick)

        self.setLayout(self.grid)
        self.show()


def main():
    app = QApplication(sys.argv)
    app.setStyle('Fusion')
    builder = Builder(app)
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
