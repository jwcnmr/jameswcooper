import random
import tkinter as tk
from tkinter import *
from tkinter import messagebox
import tkinter.ttk as ttk
import tkinter.font as tkfont

from tkinter import *
from tkinter.ttk import *


class BingoCol():
    def __init__(self, name, min, max):
        self.name = name
        bset=set()
        while len(bset) < 5:
            i = random.randint(min,max)
            bset.add(i)
        self.bara = list(bset)
        random.shuffle(self.bara)

    def getRowval(self, i):
         return str(self.bara[i])

class NBingoCol(BingoCol):
    def __init__(self, name, min,max):
        super().__init__(name,min,max)
    def getRowval(self, i):
        if(i==2):
            return "Free"
        else:
            return str(self.bara[i])

class Builder():
    def build(self):
        cols = []
        cols.append(BingoCol("B", 1, 15))
        cols.append(BingoCol("I", 16, 30))
        cols.append(NBingoCol("N", 31, 45))
        cols.append(BingoCol("G", 46, 60))
        cols.append(BingoCol("O", 61, 75))


        root = tk.Tk()
        root.geometry("300x200")
        root.title("Bingo")
        style = ttk.Style()
        style.theme_use('alt')

        style.configure("Treeview.Heading", font=(None, 25, "bold"), background='#c7c7c7', foreground='blue', )
        style = ttk.Style()
        style.configure("mystyle.Treeview", highlightthickness=0, bd=0,
                        font=('Calibri', 25))  # Modify the font of the body
        style.configure("mystyle.Treeview", rowheight=30, font=('Calibri', 20))  # Modify the font of th


        tree = Treeview(root, style='mystyle.Treeview')
        tree['columns']=('B','I','N','G','O')   #column names
        # column sizes
        tree.column('#0', width=1, minwidth=1, stretch=NO)
        tree.column('B', width=60, minwidth=50, stretch=NO, anchor=CENTER)
        tree.column('I', width=60, minwidth=50, stretch=NO, anchor=CENTER)
        tree.column('N', width=60, minwidth=50, stretch=NO, anchor=CENTER)
        tree.column('G', width=60, minwidth=50, stretch=NO, anchor=CENTER)
        tree.column('O', width=60, minwidth=50, stretch=NO, anchor=CENTER)

        tree.heading('B',text='B')
        tree.heading('I', text='I')
        tree.heading('N', text='N')
        tree.heading('G', text='G')
        tree.heading('O', text='O')

        for i in range(0, 5):
            rowval=""
            a=[]
            for r in cols:
                a.append(r.getRowval(i))
            tree.insert("", 'end', text="", values=(a))


        tree.pack()

        mainloop()




def main():
    bld =Builder()
    bld.build()


# starts here
if __name__ == '__main__':
    main()