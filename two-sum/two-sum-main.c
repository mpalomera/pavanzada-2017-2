#include <stdio.h>
#include "two-sum.h"

int main()
{
    int nums[] = {2, 7, 11, 15};
    int len = 4;
    int target = 9;
    int *result = getIndexes(nums, len, target);
    printf("");
    if (result != NULL && (nums[result[0]] + nums[result[1]] == target))
    {
        printf("Works!!\n");
    }
    else
    {
        printf(":(\n");
    }
}