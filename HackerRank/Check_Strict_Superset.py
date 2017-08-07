#
#  Author: Ganesh Kudva
#  https://www.hackerrank.com/challenges/py-check-strict-superset
#

a = set(input().split())
print(all(a > set(input().split()) for _ in range(int(input()))))
