class Hms:
    # split coma separated entry into hours, mins, secs
    def __init__(self, entry):
        tarray = entry.split(',')
        self.errorMessage = ""
        try:
            hours = int(tarray[0])      # get the 3 arguments
            minutes = int(tarray[1])
            seconds = int(tarray[2])
            self.error = False
            self.totalSeconds = hours * 3600 + minutes * 60 + seconds
        except Exception as inst:
            self.error = True           # set the error flag
            self.errorMessage = inst.args # save the error message

    # calculate hours, mins, secs from totalSeconds
    # and return as tuple
    # and decrement the totalSeconds
    def makeHms(self):
        # compute hours, with seconds as remainder
        h = divmod(self.totalSeconds, 3600)
        self.hrs = h[0]
        # compute minutes with seconds as remainder
        s = divmod(h[1], 60)
        self.secs = s[1]  # seconds
        self.mins = s[0]  # minutes
        self.totalSeconds -= 1  # decrease count here
        # return h,m,s tuple
        return self.hrs, self.mins, self.secs
