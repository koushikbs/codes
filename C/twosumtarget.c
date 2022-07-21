#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    int idx1 = 0;
    int idx2 = 0;
    int* result = NULL;
    int found = 0;
    int val = 0;
    int nextval = 0;
    int j = 0;

    if (nums == NULL || numsSize == 0 || numsSize < 2 || numsSize > 10000)
    {
        printf("Invalid input.\n");
        *returnSize = 0;
        return NULL;
    }
    if (target < pow(-10, 9) || target > pow(10, 9))
    {
        printf("Invalid target received.\n");
        *returnSize = 0;
        return NULL;
    }
    result = (int*)malloc(sizeof(int)*2);    
    if (!result)
    {
        printf("Malloc failed.\n");
        *returnSize = 0;
        return NULL;
    }
    for (i = 0; i < numsSize; i++)
    {
        val = *(nums+i);
        if (val < pow(-10, 9) || val > pow(10, 9)) 
        {
            printf("Invalid array value input (i-loop).\n");
            *returnSize = 0;
            free(result);
            return NULL;
        }
        //printf("val=%d.\n", val);
        idx1 = i;
        nextval = target - val;
        //printf("target = %d.\n", nextval); 
        found = 0; 
        j = 0;
        for (j = 0; j < numsSize; j++)
        {
            if (*(nums+j) < pow(-10, 9) || *(nums+j) > pow(10, 9))
            {
                printf("Invalid array value input (j-loop).\n");
                *returnSize = 0;
                free(result);
                return NULL;
            }

            //printf("j = %d.\n", *(nums+j));
            if (nextval == *(nums+j) && i != j)
            {
                found = 1;     
                break;
            }
        } 
        if (found)
        {
            idx2 = j;
            //*(result) = idx1;
            result[0] = idx1;
            result[1] = idx2;
            //*(result) = idx2;
            //printf("idx: %d, %d.\n", idx1, idx2);
            //printf("ind: %d, %d.\n", *(result), *(result+1));
            *returnSize = 2;
            break;
        }
            
    }
    return result;  
     
}
int main(void)
{
    int* ret = NULL;
    int nums[5] = {-1,-2,-3,-4,-5}; 
    int numsSize = sizeof(nums)/sizeof(int);
    int returnSize = 0;
    int target = -3;
    //printf("numsSize = %d.\n", numsSize);
    ret = twoSum(nums, numsSize, target, &returnSize);
    
    if (ret != NULL && returnSize !=0)
    {
        printf("Indices: %d, %d.\n", *(ret), *(ret+1));
        printf("return size: %d.\n", returnSize);
    }
    else
    {
        printf("Invalid target.\n");
        return -1;
    }
    if (ret)
    {
        free(ret);
        ret = NULL;
    }
    return 0;
}

