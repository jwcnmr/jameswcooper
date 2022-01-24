import threading
import tkinter as tk
from tkinter import CENTER, LEFT,END, mainloop, messagebox
from tkinter.ttk import Button, Label, Entry
import time
from Hms import Hms


# abstract DButton class contains the comd method
class DButton(Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, width=6, command=self.comd, **kwargs)

    def comd(self): pass


# Mediator handles communication between the entriy fields,
# button and count labels
class Mediator():
    def __init__(self, root):
        self.root = root
        self.stopRequest = False

    def setEntries(self, hr, mn, sc):
        self.hrEntry = hr
        self.mnEntry = mn
        self.secEntry = sc

    def setDispLabels(self, hr, min, sec):
        self.hrDisp = hr
        self.minDisp = min
        self.secDisp = sec

    # count starts here by fetching the entry field values
    # if there is an error the hms error variable is set and
    # the error message is shown from the hms errorMessage
    def startCount(self):
        entry = self.hrEntry.get() + ',' + self.mnEntry.get() + "," + self.secEntry.get()
        hms = Hms(entry)
        if hms.error:
            messagebox.showerror('Error', hms.errorMessage)
        else:
            x = threading.Thread(target = self.doCount, args=(1,hms, self))
            x.start()

    def doCount(self, *args):
        hms = args[1]
        med = args[2]
        while hms.totalSeconds > 0 and not med.stopRequest:
            h, m, s = hms.makeHms()
            self.hrDisp.configure(text=f'{h:02}:')
            self.minDisp.configure(text=f'{m:02}:')
            self.secDisp.configure(text=f'{s:02}')
            self.root.update()  # updates screen before sleep
            time.sleep(1)

    def clearFields(self):
        self.hrDisp.configure(text='00')
        self.minDisp.configure(text='00')
        self.secDisp.configure(text='00')
        self.hrEntry.delete(0,END)
        self.mnEntry.delete(0, END)
        self.secEntry.delete(0,END)
        self.stopRequest =  False



# derived blue label
class BlueLabel(Label):
    def __init__(self, root, lbtext, **kwargs):
        super().__init__(root, text=lbtext, justify=CENTER, foreground='blue')


# count labels have a larger font
class CountLabel(Label):
    def __init__(self, root, tkFont=None, **kwargs):
        super().__init__(root, text='00', justify=LEFT, borderwidth=2, relief="ridge")
        self.config(font=('Helvetica bold', 26))


# the Start button launches the count down
class StartButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text='Start')
        self.med = med

    def comd(self):
        self.med.startCount()

class StopButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text='Stop')
        self.med = med
        self.root = root

    def comd(self):
        print('stopping')
        self.med.stopRequest = True

class ClearButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text='Clear')
        self.med = med
        self.root = root

    def comd(self):
        self.med.clearFields()

# builds the UI for the count down clock
class Builder():

    def build(self):
        root = tk.Tk()
        self.root = root
        self.root.geometry("250x150")

        # top row are labels for the entry fields
        hrLabel = BlueLabel(root, "Hours").grid(row=0, column=0)
        minLabel = BlueLabel(root, "Minutes").grid(row=0, column=1)
        secLabel = BlueLabel(root, "Seconds").grid(row=0, column=2)

        # second row contains the 3 entry fields
        hrEntry = Entry(root, width=8, justify=CENTER)
        hrEntry.grid(row=1, column=0, padx=10)
        minEntry = Entry(root, width=8, justify=CENTER)
        minEntry.grid(row=1, column=1, padx=10)
        secEntry = Entry(root, width=8, justify=CENTER)
        secEntry.grid(row=1, column=2, padx=10)

        med = Mediator(root)
        med.setEntries(hrEntry, minEntry, secEntry)

        # start button is in the third row
        clearButton = ClearButton(root, med)
        clearButton.grid(row=2, column=0, pady=10)
        startButton = StartButton(root, med)
        startButton.grid(row=2, column=1, pady=1)
        stopButton = StopButton(root, med)
        stopButton.grid(row=2, column = 2, pady=1)

        # the large bordered labels are for the count down clock
        hrDisp = CountLabel(root, "")
        hrDisp.grid(row=3, column=0, pady=10)
        minDisp = CountLabel(root, "")
        minDisp.grid(row=3, column=1, pady=10)
        secDisp = CountLabel(root, "")
        secDisp.grid(row=3, column=2, pady=10)

        med.setDispLabels(hrDisp, minDisp, secDisp)

        mainloop()


def main():
    bld = Builder()
    bld.build()


# starts here
if __name__ == '__main__':
    main()