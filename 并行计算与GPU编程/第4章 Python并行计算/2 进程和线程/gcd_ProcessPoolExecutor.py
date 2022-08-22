from concurrent.futures import ProcessPoolExecutor
import time

def gcd(pair):
    # 最大公约数
    a, b = pair
    low = min(a, b)
    for i in range(low, 0, -1):
        if a % i == 0 and b % i == 0:
            return i

numbers = [(1963309, 2265973), (2030677, 3814172), (1551645, 2229620), (2039045, 2020802)]

if __name__ == '__main__':
    sum = 0
    for i in range(20):
        start = time.time()
        pool = ProcessPoolExecutor(max_workers=3)
        results = list(pool.map(gcd, numbers))
        end = time.time()
        sum += end - start

    print(sum/20)        