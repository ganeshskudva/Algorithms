for _ in range(int(input().strip())):
    n = int(input().strip()) 
    n2 = 2 * n
    maxSum = 0
    
    matrix = [0] * n2
    for i in range(n2):
        matrix[i] = [int(x) for x in input().strip().split(' ')]
    
    for i in range(n):
        for j in range(n):
            maxSum += max([matrix[i][j], \
            	matrix[i][n2-1-j], \
            	matrix[n2-1-i][j], \
            	matrix[n2-1-i][n2-1-j]])
                   
    print (maxSum)
