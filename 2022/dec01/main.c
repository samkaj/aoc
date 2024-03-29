#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP_SIZE 3

int max(int n, int m)
{
    if (n > m)
        return n;
    return m;
}

int min(int n, int m)
{
    if (n < m)
        return n;
    return m;
}

void add(int nums[], int n, int arrsize)
{
    int zeroes = 0;
    for (int i = 0; i < arrsize; ++i)
        if (nums[i] == 0)
            zeroes++;

    if (zeroes > 0)
        nums[arrsize - zeroes] = n;
    else 
    {
        int smallest_index = 0;
        int small = nums[smallest_index];
        for (int i = 0; i < arrsize; i++)
        {
            if (small != min(small, nums[i])) 
            {
                smallest_index = i;
                small = nums[i];
            }
        }
        nums[smallest_index] = max(nums[smallest_index], n);
    }
}

int sum(int nums[], int arrsize)
{
    int sum = 0;
    for (int i = 0; i < arrsize; i++)
        sum += nums[i];
    return sum;
}

int main(void)
{
    FILE *file = fopen("input.txt", "r");
    if (!file)
        return -1;

    int top[TOP_SIZE];
    char line[10];
    int curr, high = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strcmp(line, "\n"))
        {
            curr += atoi(line);
        }
        else
        {
            high = max(curr, high); // part one
            add(top, curr, 3);         // part two
            curr = 0;
        }
    }

    fclose(file);

    printf("Part 1: %d\n", max(curr, high));
    printf("Part 2: %d\n", sum(top, TOP_SIZE));
    return 0;
}
