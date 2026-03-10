// int removeDuplicates(int * nums,int numsSize)
// {
//     if(numsSize==0)
//     return 0;
//     int k=1;
//     for(int i=1;i<numsSize;i++)
//     {
//         if(nums[i]!=nums[i-1])
//         {
//             nums[k]=nums[i];
//             k++;
        
//         }
//     }
//      return k;
// }
#include<stdlib.h>
#include<stdio.h>
int compareInt(const void *a,const void *b)
{
    return*(int*)a-*(int*)b;

}
int**threeSum(int*nums,int numsSize,int*returnSize,int**returnColumnSizes)
{
    int cap=32;
    int**result=(int**)malloc(sizeof(int*)*cap);
    int*cols=(int*)malloc(sizeof(int)*cap);
    int *triplet;
    int sum,target,count;
    int i,left,right;

    qsort(nums,numsSize,sizeof(int),compareInt);
    count=0;
    for(i=0;i<numsSize-2;i++)
    {
        if(nums[i]>0)
        {
            break;
        }
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        target=-nums[i];
        left=i+1;
        right=numsSize-1;
        while(left<right)
        {
            sum=nums[left]+nums[right];
            if(sum>target){
                right--;

            }
            else if(sum<target)
            {
                left++;

            }
            else{
                triplet=(int*)malloc(sizeof(int)*3);
                triplet[0]=nums[i];
                triplet[1]=nums[left];
                triplet[2]=nums[right];
                result[count]=triplet;
                cols[count]=3;
                count++;
                if(count==cap)
                {
                    cap=cap*2;
                    result=(int**)realloc(result,sizeof(int*)*cap);
                    cols=(int*)realloc(cols,sizeof(int)*cap);
                }
                left++;
                right--;
                while(left<right&&nums[left]==nums[left-1])
                {
                    left++;
                }
                while(left<right&&nums[right]==nums[right+1])
                {
                    right--;
                }
            }
        }
    }
    *returnSize=count;
    *returnColumnSizes=cols;
    return result;
}