#include <stdlib.h>
#include "two-sum.h"


int *getIndexes(int *nums, int len, int target)
{
    int i, j;
    int candidate;
    int complement;
    int *result = (int *)calloc(2, sizeof(int));

    for (i = 0; i < len - 1; i++)
    {
        if (nums[i] >= target)
        {
            continue;
        }
        candidate = nums[i];
        complement = target - candidate;
        for (j = i + 1; j < len; j++)
        {
            if (nums[j] == complement)
            {
                break;
            }
        }
        if (nums[i] + nums[j] == target)
        {
            result[0] = i;
            result[1] = j;
            return result;
        }
    }
    return NULL;
}

