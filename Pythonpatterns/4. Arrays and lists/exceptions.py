"""Illustrates using exceptions"""
try:
    f = open("shrubbery", "r")
except FileNotFoundError:
    print("Can''t find that file")

x = 5.63
y = 0

try:
    z = x/y
except ZeroDivisionError:
    print("Division by zero!")
else:
    print("result=",z)