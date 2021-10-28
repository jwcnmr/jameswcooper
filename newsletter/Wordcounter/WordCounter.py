""" This program counts each word occurrence in a phrase """

class WordCounter:
    """Contains a word and its frequency"""
    def __init__(self, word, wordArray):
        self.word = word
        self.count = wordArray.count(word)  # count that word’s frequency

class MakeLists():
    """Counts all the words in a sample and
    stores then in a List of WordCounter objects"""
    def __init__(self, phrase):
        self.phrase = phrase

    def buildLists(self):
        """Splits up words, removes suffixes
        and creates a set of words to eliminate duplicates
        and an array of all the words in the phrase"""
        words = self.phrase.split()  # make array of words
        self.warray = []   # array of stripped words
        self.wset = set()  # use set to eliminate dupes
        for w in words:
            w = w.strip().removesuffix(',')  # remove trailing punctuation
            w = w.removesuffix('!').removesuffix('.').lower()
            self.warray.append(w)    # add each word to array
            self.wset.add(w)         # and to set

    def countWords(self):
        """Creates an array of WordCounter objects containing the count
        and sorts them into descending order"""
        self.counts = []
        for w in self.wset:
            wc = WordCounter(w, self.warray)  # count occurrences of each word
            self.counts.append(wc)
        # sort counts into descending order
        self.counts.sort(key=lambda x: x.count, reverse=True)

    def printCounts(self):
        """ print out resulting list """
        for wc in self.counts:
            print(wc.word, wc.count)

class Analyze:
    """This class calls the methods that make the lists
    and counts the words"""
    def doAnalysis(self, phrase):
        self.phrase = phrase
        cWords = MakeLists(self.phrase)  # create MakeLists
        cWords.buildLists()  # build the lists
        cWords.countWords()  # count the words
        cWords.printCounts() # print the results

def main():
    phrase = """
    If you’ll marry me, I’ll dig for you and rake for you!
    If you’ll marry me, I’ll scrub for you and bake for you!
    If you’ll marry me, all others I’ll forsake for you!
    All this will I du, if you marry me!

    If you’ll marry me, I’ll cook for you and brew for you!
    If you’ll marry me, I’ve guineas not a few for you!
    If you’ll marry me, I’ll take you in and du for you!
    All this will I du, if you'll marry me!
    Eh, but I do loike you!
    """

    a = Analyze()               # create the Analyze class
    a.doAnalysis(phrase)        # make the lists and count the words

if __name__ == "__main__":
    main()
