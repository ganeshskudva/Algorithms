import sys
from collections import OrderedDict

with open(sys.argv[1], 'r') as input:
    test_cases = input.read().strip().splitlines()

for test in test_cases:
    words = test.split()
    for word in words:
        print "".join(OrderedDict.fromkeys(word)),
    print
