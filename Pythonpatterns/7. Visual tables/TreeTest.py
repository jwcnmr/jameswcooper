from tkinter import ttk
from tkinter import *
from tkinter.ttk import *

def buildUI( root):
    root.geometry("400x200")
    tree = Treeview(root)

    #create columns
    tree["columns"]=( "abbrev", "capital", "founded")
    tree.column("#0",width=100,minwidth=100, stretch=NO) #left column is always #0
    tree.column("abbrev", width=50, minwidth=50, stretch=NO)
    tree.column("capital", width=100, minwidth=100, stretch=NO)
    tree.column("founded", width=70, minwidth=60, stretch=NO)

    #create headings
    tree.heading('#0', text='Name')
    tree.heading('abbrev', text='Abbrev')
    tree.heading('capital', text='Capital')
    tree.heading('founded', text='Founded')
    style = ttk.Style()
    style.configure("Treeview.Heading", font=(None, 10, "bold"))

    folderCa= tree.insert("", 1, text="California", values=( "CA", "Sacramento", "1845"))
    #tree.insert("", 1, text="California", values=("CA", "Sacramento", "1845"))
    tree.insert("", 2, text="Kansas", values=( "KS", "Topeka", "1845"))

    tree.insert(folderCa, 3, text="", values=(" ","pop=508,529"))
    tree.pack(side=TOP, fill=X)


def main():
    root = Tk()
    root.geometry("300x200")  # this one is pretty confusing
    buildUI(root)

    root.title("State List")  # title only shows if window is wide enough
    root.mainloop()

###  Here we go  ####
if __name__ == "__main__":
     main()
