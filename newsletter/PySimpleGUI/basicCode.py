import PySimpleGUI as sg

# create layout
layout = [[sg.Text('Add 2 numbers')],
          [sg.Text('Num1: ', size=(5, 1)), sg.InputText()],
          [sg.Text('Num2: ', size=(5, 1)), sg.InputText()],
          [sg.Text('Result: ', size=(6, 1)), sg.Text(size=(5,1))],
          [sg.Button('Add'), sg.Button('Clear')]]
# create the window
window = sg.Window('Adder', layout)

# window event loop is here
quit = False
while not quit:
    event, values = window.read()   # get the event
    quit = (event == None)    # corner 'X' clicked
window.close()      # close window

