i, j, k = [int(x) for x in input().split()]
beautifulDays = [1 for day in range(i, j+1) if (day - int(str(day)[::-1])) % k == 0]
print(sum(beautifulDays))
