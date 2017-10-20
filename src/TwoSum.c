#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *result = malloc(2 * sizeof(int));
    int i;
    int j;
    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < numsSize; j++)
        {
            if (i != j && nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int nums[] = {3, 2, 4};
    int target = 6;
    int *result = twoSum(nums, sizeof(nums) / sizeof(int), target);
    printf("[%d, %d]\n", result[0], result[1]);
}
