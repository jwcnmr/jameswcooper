
import matplotlib.pyplot as plt

x=[10,50,100,150,250]     #list of x-values
y=[20,40,90,120,190]      #list of y-values

fig, ax = plt.subplots()  #create an axis instance
ax.plot(x, y, marker="o", label="first")   #plot the x-y data
#new plot with dashed line and x-marker
ax.plot([20,40,160,180],[40, 60,80,100], marker="x",
        ls="--", label="second")
ax.legend()

plt.show()


