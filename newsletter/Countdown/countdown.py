import time
from HmsSimple import Hms
"""Simple program to count down hours, minutes, seconds
Makes use of the Hms class to compute them from seconds
"""
def main():
    entry = input("Enter hours, minutes, seconds:")
    hms = Hms(entry)
    if hms.error:
        print (hms.errorMessage)
    else:
        while hms.totalSeconds > 0 :
            h,m,s = hms.makeHms()
            print(f'{h:02}:{m:02}:{s:02}')
            time.sleep(1)
if __name__ == '__main__':
    main()

