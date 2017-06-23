#
#  Author: Ganesh Kudva
#  https://www.hackerrank.com/challenges/stockmax/problem
#


for a0 in range(int(input())):
    input()
    
    profit = 0
    maxSoFar = 0
    
    for i in [int(x) for x in input().split()][::-1]:
        if i > maxSoFar:
            maxSoFar = i
        
        profit += maxSoFar - i
            
    print(profit)
