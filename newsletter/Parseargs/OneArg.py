import sys
"""Get one argument from the command line and print it out"""
def main():
    if len(sys.argv)>1:
        datafile = sys.argv[1]
        print (sys.argv[1])
    else:
        datafile =""

    # print all of the command line args
    print (sys.argv[1:])

###  Here we go  ####
if __name__ == "__main__":
    main()