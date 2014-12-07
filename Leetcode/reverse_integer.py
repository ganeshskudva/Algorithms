class Solution:
    # @return an integer
    def reverse(self, x):
                if x < 0:
                   x = x * -1
                   return (-1 * int(str(x)[::-1]))
                else:
                   return int(str(x)[::-1])
        
