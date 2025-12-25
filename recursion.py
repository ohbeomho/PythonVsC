from time import perf_counter_ns
import sys

# 재귀 깊이 제한 설정
sys.setrecursionlimit(100000)


def getSum(n):
    if n == 1:
        return 1
    return n + getSum(n - 1)


sum = 0

for i in range(10):
    start = perf_counter_ns()

    result = getSum(10000)

    end = perf_counter_ns()

    elapsed_ns = end - start
    elapsed_ms = elapsed_ns / 1000000
    sum += elapsed_ms

    print(f"Iteration #{i + 1} {elapsed_ns}ns ({elapsed_ms}ms)")

print(f"Average: {sum / 10}ms")
