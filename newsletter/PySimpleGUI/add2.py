import PySimpleGUI as sg

class Mediator:
    def __init__(self, window):
        self.window = window

    def addvals(self):
        err=False
        try:
            # get the contents of the two entry fields
            x = float(self.values.get('-val1-'))
            y = float(self.values.get('-val2-'))
            sum = x + y
        except ValueError:
            sg.popup_error("Value error","illegal number")
            err = True

        # update the Result field
        if not err:
          self.window['-sum-'].update(str(sum))

    # process events from buttons
    def doEvent(self, event, values):
        self.values = values
        if event ==None:        # window close
            return True         # this makes 'quit' true
        elif event == 'Add':      # add button
            self.addvals()
            return False
        elif event == 'Clear':    # clear button
            self.window['-val1-'].update('')    # set all to blank
            self.window['-val2-'].update('')
            self.window['-sum-'].update('')
            return False

class Builder:
    # Construct the window layout
    def build(self):
        # abbreviations of properties
        bl: dict={'text_color':'blue'}  # blue labels
        bt: dict={'size':(5,1)}         # button size

        # standard gray background
        sg.theme('Default1')
        layout = [[sg.Text('Add 2 numbers', **bl)],
                  [sg.Text('Num1: ', size=(5, 1), **bl), sg.InputText(key='-val1-')],
                  [sg.Text('Num2: ', size=(5, 1), **bl), sg.InputText(key='-val2-')],
                  [sg.Text('Result: ', size=(6, 1), **bl), sg.Text(size=(5,1), key='-sum-')],
                  # center buttons using an empty label
                  [sg.Text('',size=(3,1)),sg.Button('Add',**bt), sg.Button('Clear',**bt)]]

        window = sg.Window('Adder', layout, size = (200,150),use_ttk_buttons=True)
        sg.set_options(use_ttk_buttons=True)
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