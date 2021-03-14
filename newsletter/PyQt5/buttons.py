from PyQt5 import QtCore, QtWidgets

if hasattr(QtCore.Qt, 'AA_EnableHighDpiScaling'):
    QtWidgets.QApplication.setAttribute(
        QtCore.Qt.AA_EnableHighDpiScaling, True)

if hasattr(QtCore.Qt, 'AA_UseHighDpiPixmaps'):
    QtWidgets.QApplication.setAttribute(
        QtCore.Qt.AA_UseHighDpiPixmaps, True)
    
class RoleButton(QtWidgets.QRadioButton):
    rindex =0
    roles = ["Lead", "Minr", "Chor"]
    def __init__(self, frame, index):
        super().__init__(frame)
        self.index = index
        self.clicked.connect(self.click)
    def click(self):
        RoleButton.rindex = self.index

class VoiceButton(QtWidgets.QRadioButton):
    vindex = 0
    voices =["Sop", "Alt", "Ten", "Bas"]
    def __init__(self, frame, index):
        super().__init__(frame)
        self.index = index
        self.clicked.connect(self.click)
    def click(self):
        VoiceButton.vindex = self.index

class Mediator():
    def __init__(self, entry: QtWidgets.QLineEdit, list: QtWidgets.QListWidget):
        self.entry = entry
        self.list = list

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

class Connect:

    def createConnection(self, charname: QtWidgets.QLineEdit, namelist: QtWidgets.QListWidget,
                     addButton: QtWidgets.QPushButton, clearButton: QtWidgets.QPushButton):

        self.med = Mediator(charname, namelist)
        addButton.clicked.connect(self.med.addClick)
        clearButton.clicked.connect(self.med.clearClick)


