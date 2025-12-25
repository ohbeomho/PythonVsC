from time import perf_counter_ns
from random import randint


def generate_random_numbers():
    return [randint(0, 9999) for _ in range(1000)]


sum = 0

for k in range(10):
    arr = generate_random_numbers()

    start = perf_counter_ns()

    for i in range(999, 0, -1):
        for j in range(1, i + 1):
            if arr[j - 1] > arr[j]:
                temp = arr[j]
                arr[j] = arr[j - 1]
                arr[j - 1] = temp

    end = perf_counter_ns()

    elapsed_ns = end - start
    elapsed_ms = elapsed_ns / 1000000
    sum += elapsed_ms

    print(f"Iteration #{k + 1}: {elapsed_ns}ns ({elapsed_ms}ms)")

print(f"Average: {sum / 10}ms")
