#!/bin/python3

import sys


print(sum([1 for x,y in zip(input(), 'SOS'*100) if x != y]))
