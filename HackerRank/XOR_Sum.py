#
# AUTHOR: Ganesh S Kudva
# https://www.hackerrank.com/challenges/xor-and-sum
#


def getBit(x, i):
        if i<len(x):
                return int(x[i])
        return 0

def calcsumxor(a, b):
        C = 314159
        #C = 1
        REM = 10 ** 9 + 7
        a = a[::-1]
        b = b[::-1]
        p = 1
        n = len(a)
        m = len(b)
        count0 = C
        count1 = 0
        s = 0
        for i in range(max(n, m+C)):
                if getBit(b, i)== 1:
                      count1 += 1
                else:
                      count0 += 1

                if getBit(a, i) == 1:
                        s = (s + (count0 * p) ) % REM
                else:
                        s = (s + (count1 * p) ) % REM

                p = (p*2)%REM

                if i>=C:
                        if getBit(b, i-C) == 0:
                                count0 -= 1
                        else:
                                count1 -= 1
                else:
                        count0 -= 1

                count0 = count0 % REM
                count1 = count1 % REM
                #print s
        return s

if __name__ == "__main__":
        a = raw_input()
        b = raw_input()
        print calcsumxor(a, b)
