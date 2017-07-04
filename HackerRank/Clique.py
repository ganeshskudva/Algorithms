#
#  Author: Ganesh Kudva
#  https://www.hackerrank.com/challenges/clique/problem
#


import math

def computeMaxE(r, n):
    #some magic here o.o, upperbound of edges with r-clique, as opposed to upperbound
    # of edges without (r+1)-clique
    g1 = n%r;
    g2 = r - g1;
    sz1 = n/r + 1;
    sz2 = n/r;
    ret = g1*sz1*g2*sz2 + g1*(g1-1)*sz1*sz1/2 + g2*(g2-1)*sz2*sz2/2;
    return ret;

import math

ncases = input()

for i in range(ncases):
    N,E = [int(x) for x in raw_input().split(" ")]
    low = 1; high = N + 1; mid = (high + low)/2
    while (high > low + 1):
        if computeMaxE(mid, N) < 1.0*E:
            low = mid; mid = (high + low)/2
        else:
            high = mid; mid = (high + low)/2
    print high
