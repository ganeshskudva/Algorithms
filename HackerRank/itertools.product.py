#
# AUTHOR: Ganesh S Kudva
# https://www.hackerrank.com/challenges/itertools-product/problem
#

from itertools import product
A = map(int,raw_input().split())
B = map(int,raw_input().split())
A.sort()
B.sort()

ans = [A,B]
AxB = list(product(*ans))

for i in AxB:
	print i,
