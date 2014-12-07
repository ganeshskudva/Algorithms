import sys

def check_substr(strA, strB):
                 for i in strA:
                     if i in strB:
                        return "Yes"
                 return "No"

with open(sys.argv[1], 'r') as input:
    test_cases = input.read().strip().splitlines()

num = int(test_cases[0])
i   = 1

while (i < num*2):
               strA = test_cases[i]
               i = i + 1
               strB = test_cases[i]
               i = i + 1
               print check_substr(strA, strB)
