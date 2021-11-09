import time
from HmsSimple import Hms
"""Simple program to count down hours, minutes, seconds
Makes use of the Hms class to compute them from seconds
"""
def main():
    # get the keyboard input
    entry = input("Enter hours, minutes, seconds:")
    hms = Hms(entry)    # convert to seconds inside HMS

    while hms.totalSeconds > 0 :
        h,m,s = hms.makeHms()   # get the current values and print them out each second
        print(f'{h:02}:{m:02}:{s:02}')
        time.sleep(1)
if __name__ == '__main__':
    main()

