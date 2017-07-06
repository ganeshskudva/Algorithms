#
#  Author: Ganesh Kudva
#  https://www.hackerrank.com/challenges/two-characters/problem
#

import sys
#sys.stdin=open("in","r")
n=int(raw_input())
s=raw_input()
assert s.isalpha()
ans=0
for i in range(0,26):
    for j in range(0,26):
        if i==j:
            continue
        p1 = i
        p2 = j
        flag = 1
        l = 0
        for c in s:
            if ord(c)-ord('a')!=p1 and ord(c)-ord('a')!=p2:
                continue
            if ord(c)-ord('a') == p1:
                l = l + 1
                p1,p2 = p2,p1
            else:
                flag = 0
        if flag == 1 and l>1:
            ans=max(ans,l)

print ans
