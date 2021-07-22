from SwimClasses import TimedFinalEvent, PrelimEvent
import sys

class Builder():

    def build(self):
        dist=1
        while dist > 0:
            dist = int(input('Enter 1 for 100, 5 for 500 or 0 to quit: '))
            if dist==1 or dist ==5:
                self.evselect(dist)

    # seed selected event
    def evselect(self, dist):
        # there are only two swimmer files
        # We read in one or the other

        if dist == 5 :
            event = TimedFinalEvent("500free.txt", 6)
        elif dist ==1:
            event = PrelimEvent("100free.txt", 6)

        seeding = event.getSeeding()    #factory here
        swmrs= seeding.getSwimmers()    #do one sort of seeding or the other

        #print swimmer list in seeded order
        for sw in swmrs:
           print(f'{sw.heat:3}{sw.lane:3} {sw.getName():20}{sw.age:3} {sw.seedtime:9}')

# -----main begins here----
def main():
    builder = Builder()
    builder.build()

###  Here we go  ####
if __name__ == "__main__":
    main()