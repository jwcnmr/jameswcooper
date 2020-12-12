"""Plots bar graph and semi log plot"""
import matplotlib.pyplot as plt

#bar graph
fig, ax = plt.subplots()  #create an axis instance
names = ["apples", "oranges","plums"]
values = [70, 30, 12]
ax.set(ylabel="fruit count")
ax.bar(names, values)      #plot the x-y data

#semi log y plot
fig, ax1 = plt.subplots()  #create an axis instance
x=[10,50,100,150,200]       #list of x-values
y=[0.1,1,10,100, 1000]      #list of y-values
ax1.semilogy(x,y, marker="o")

plt.show()
