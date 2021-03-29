""" illustration of parsing command line args"""
import sys, argparse
def main():

    # create ArgumentParser for -f and -d
    parser = argparse.ArgumentParser()
    parser.add_argument('-f',  help='filename')
    parser.add_argument('-d',  help='delete (yes or no)')

    args = parser.parse_args()
    print(args)
    print(args.f)
    print(args.d)




###  Here we go  ####
if __name__ == "__main__":
    main()
