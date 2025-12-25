#include <stdio.h>
#include <time.h>

#define ll long long

int getSum(int n)
{
    if (n == 1)
        return 1;
    return n + getSum(n - 1);
}

int main()
{
    double sum = 0;

    struct timespec start, end;

    for (int i = 0; i < 10; i++)
    {
        timespec_get(&start, TIME_UTC);
        int result = getSum(10000);
        timespec_get(&end, TIME_UTC);

        ll elapsed_ns = (ll)(end.tv_sec - start.tv_sec) * 1000000000ll +
                        (ll)(end.tv_nsec - start.tv_nsec);
        double elapsed_ms = elapsed_ns / 1000000.0;
        sum += elapsed_ms;

        printf("Iteration #%d: %lldns (%lfms)\n", i + 1, elapsed_ns, elapsed_ms);
    }

    printf("Average: %lfms", sum / 10);

    return 0;
}