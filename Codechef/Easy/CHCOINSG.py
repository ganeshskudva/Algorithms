#
#  Author: Ganesh Kudva
#  https://www.codechef.com/problems/CHCOINSG
#

T = int(raw_input())
for cas in range(T):
  n = int(raw_input())
  print "Misha" if n % 6 == 0 else "Chef"
