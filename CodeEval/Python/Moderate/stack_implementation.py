import sys


if __name__ == '__main__':
    with open(sys.argv[1]) as f:
        for line in f:
            if line.strip():
                stack = list(map(int, line.split()))
                
                for i in range(len(stack)):
                    x = stack.pop()
                    
                    if i % 2 == 0:
                        print x,
                print()
