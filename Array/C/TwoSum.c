/*
TwoSum LeetCode

Time complexity of O(n^2)
Space complexity of O(1) as we are iterating through the array once and only storing 2 integers.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}
