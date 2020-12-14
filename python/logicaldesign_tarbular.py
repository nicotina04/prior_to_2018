class MinSet:
    #Definition of minterm class
    size = 1
    ones = 0
    minterm = {}
    binnum = ""
    isRefined = False

    def __init__(self, size, onenums, minterm, bins, combined):
        self.size = size
        self.ones = onenums
        self.minterm = set(minterm)
        self.binnum = bins
        self.isRefined = combined

    def __repr__(self):
        return repr((self.size, self.ones, self.minterm, self.binnum, self.isRefined))

#string to bin
def tobin(bits, contarget):
    temp = bin(contarget)
    temp = temp[2:]
    return temp.rjust(bits, "0")


def validbit(bit1, bit2):
    bit1 = list(bit1)
    bit2 = list(bit2)
    count = 0

    for i in range(len(bit1)):
        if bit1[i] != bit2[i]:
            if bit1[i] == '-' or bit2[i] == '-':
                count += 1
            else:
                count += 1

    return count <= 1

def isbin(ar, binstring):
    for i in range(len(ar)):
        if ar[i].binnum == binstring:
            return i

def refine(bit1, bit2):
    bit1 = list(bit1)
    bit2 = list(bit2)
    refined = ""

    for i in range(len(bit1)):
        if bit1[i] != bit2[i]:
            refined += '-'
        else:
            refined += bit1[i]

    return refined

def looper(target, size):
    length = len(target)

    if length == 1:
        return [target[0]]
    else:
        seed = target[:]
        seed = sorted(seed, key = lambda z : z.ones)

        tablecheck = []
        for i in range(len(seed)):
            first = seed[i].binnum

            for j in range(i, len(seed)):
                if i == j:
                    continue
                else:
                    second = seed[j].binnum
                    if validbit(first, second):
                        strbin = refine(first, second)
                        ones = strbin.count('1')
                        newMinterms = seed[i].minterm | seed[j].minterm

                        if size == len(newMinterms):
                            seed[i].isRefined = True
                            seed[j].isRefined = True

                            index = isbin(tablecheck, strbin)

                            if type(index) == int:
                                tablecheck[index].minterm |= newMinterms
                            else:
                                tablecheck.append(MinSet(size, ones, newMinterms, strbin, False))

        if seed == tablecheck:
            return tablecheck

        all = looper(tablecheck, size * 2)

        for i in range(len(seed)):
            if not seed[i].isRefined:
                all.append(seed[i])

        return all

def getreference(PIS):
    dictreturn = {}
    for i in PIS:
        adder = 0
        for j in range(len(i) - 1, -1, -1):
            if i[j] == '-':
                adder += 10**(len(i) - j - 1)*3
            elif i[j] == '1':
                adder += 10**(len(i) - j - 1)*2
            else:
                adder += 10**(len(i) - j - 1)
        dictreturn[i] = adder
    return dictreturn

def solution(input):
    binrange = int(input[0])
    targets = int(input[1])

    # Construct Size 1 Table
    implicantsTable = []
    for i in range(2, targets + 2):
        Minterm = int(input[i])
        binMinterm = tobin(binrange, Minterm)
        ones = binMinterm.count('1')
        implicantsTable.append(MinSet(1, ones, [Minterm], binMinterm, False))

    PIdata = looper(implicantsTable, 2)

    if len(PIdata) == 1:
        final = ["EPI"]
        for i in range(len(PIdata)):
            final.append(PIdata[i].binnum)
        final += ["NEPI"]
        return final
    else:
        mints = {}
        for minterm in input[2:]:
            mints[int(minterm)] = 0

        for i in range(len(PIdata)):
            mintermset = list(PIdata[i].minterm)
            for j in range(len(mintermset)):
                mints[mintermset[j]] += 1

        EPI = set()

        for e in mints.keys():
            if mints[e] == 1:
                for i in range(len(PIdata)):
                    if e in PIdata[i].minterm: EPI.add(PIdata[i])

        NEPI = set(PIdata) - EPI

        EPI = list(EPI)
        NEPI = list(NEPI)

        EPI = sorted(EPI, key = lambda z : z.ones)
        NEPI = sorted(NEPI, key = lambda z : z.ones)

        final = ["EPI"]
        tempepi = []
        for x in EPI:
            tempepi.append(x.binnum)
        resepi = getreference(tempepi)
        resepi = sorted(resepi.items(), key = lambda x : x[1])

        for x in resepi:
            final.append(x[0])

        final += ["NEPI"]

        tempnepi = []
        for x in NEPI:
            tempnepi.append(x.binnum)

        resnepi = getreference(tempnepi)
        #print(resnepi)
        resnepi = sorted(resnepi.items(), key = lambda y : y[1])


        for x in resnepi:
            final.append(x[0])

        return final

if __name__ == '__main__':
    ars = ["3", "4", "0", "1", "2", "3"]
    solution(ars)


"""
important test vector
4 10 0 1 2 5 6 7 8 9 10 14
4 8 0 1 2 3 4 5 6 7
4 8 4 8 9 10 11 12 14 15
4 7 0 1 2 3 10 11 12
4 16 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
4 11 0 2 3 5 7 8 9 10 11 13 15
4 8 0 1 3 5 6 8 10 15
6 30 0 1 2 3 4 5 6 7 8 16 18 19 20 21 27 28 30 32 36 38 45 47 48 51 54 55 57 59 60 61
Herdson made test vector
4 8 0 3 5 6 7 10 12 13
4 6 5 7 9 11 13 15
4 10 2 3 6 7 8 10 11 12 14 15
5 32 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
5 12 0 1 2 8 9 15 17 21 24 25 27 31
"""