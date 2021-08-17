import PySimpleGUI as sg

class Mediator:
    def __init__(self, window):
        self.window = window

    def addvals(self):
        # get the contents of the two entry fields
        x = float(self.values.get('-val1-'))
        y = float(self.values.get('-val2-'))
        sum = x + y
        # update the Result field
        self.window['-sum-'].update(str(sum))

    # process events from buttons
    def doEvent(self, event, values):
        self.values = values
        if event == None:       # window close
            return True         # this makes 'quit' true
        elif event == 'Add':    # add button
            self.addvals()
            return False
        elif event == 'Clear':  # clear button
            self.window['-val1-'].update('')    # set all to blank
            self.window['-val2-'].update('')
            self.window['-sum-'].update('')
            return False

class Builder:
    # Construct the window layout
    def build(self):
        # standard gray background
        sg.theme('Default1')
        layout = [[sg.Text('Add 2 numbers')],
                  [sg.Text('Num1: ', size=(5, 1)), sg.InputText(key='-val1-')],
                  [sg.Text('Num2: ', size=(5, 1)), sg.InputText(key='-val2-')],
                  [sg.Text('Result: ', size=(6, 1)), sg.Text(size=(5,1), key='-sum-')],
                  [sg.Button('Add'), sg.Button('Clear')]]

        window = sg.Window('Adder', layout, size = (200,150))
        med = Mediator(window)

        # window event loop is here
        quit = False
        while not quit:
            event, values = window.read()   # get the event
            quit = med.doEvent(event, values)   # and process it
        window.close()      # close window if 'X' clicked

def main():
    bld = Builder()     #builld the UI
    bld.build()
# starts here
if __name__ == '__main__':
    main()