import random

class Word:

    def __init__(self, filename):

        self.words = []
        self.length = 0
        self.ref = 0
        f = open(filename, 'r')
        lines = f.readlines()
        f.close()

        self.count = 0
        for line in lines:
            word = line.rstrip()
            self.words.append(word)
            self.count += 1
            if len(word) > self.length:
                self.length = len(word)

        print('%d words in DB' % self.count)


    def test(self):
        return 'default'


    def randFromDB(self, minLen):

        if minLen >= self.length:
            self.ref = self.length
        else:
            self.ref = minLen

        r = random.randrange(self.count)
        if len(self.words[r]) < self.ref:
            return self.randFromDB(self.ref)
        else:
            return self.words[r]
