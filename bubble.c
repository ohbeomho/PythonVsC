#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ll long long

void generateRandomNumbers(int *dest, int len)
{
    for (int i = 0; i < len; i++)
        dest[i] = rand() % 10000;
}

int main()
{
    // 완전한 무작위를 위해 시드 값을 코드가 실행될 때의 시간으로 설정
    srand(time(NULL));

    double sum = 0;
    int arr[1000];

    struct timespec start, end;

    for (int k = 0; k < 10; k++)
    {
        generateRandomNumbers(arr, 1000);

        timespec_get(&start, TIME_UTC);

        for (int i = 999; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                if (arr[j - 1] > arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
        }

        timespec_get(&end, TIME_UTC);

        // Calculate the difference in nanoseconds
        // Convert seconds to nanoseconds and add the nanosecond part
        ll elapsed_ns = (ll)(end.tv_sec - start.tv_sec) * 1000000000LL +
                        (ll)(end.tv_nsec - start.tv_nsec);
        double elapsed_ms = elapsed_ns / 1000000.0;
        sum += elapsed_ms;

        printf("Iteration #%d: %lldns (%lfms)\n", k + 1, elapsed_ns, elapsed_ms);
    }

    printf("Average: %lfms", sum / 10);

    return 0;
}
