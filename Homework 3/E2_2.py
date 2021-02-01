from random import random
from time import perf_counter
N = 10000
number = 0.0
start = perf_counter()
for i in range(1, N+1):
    x, y = random(), random()
    dist = x ** 2 + y ** 2
    if dist <= 1.0:
        number = number + 1
pi = 4 * (number/N)
print("圆周率值为: {}".format(pi))
print("运行时间是: {:.5f}s".format(perf_counter() - start))
