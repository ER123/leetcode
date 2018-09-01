class Solution {
public:
//当前元素与要删除的元素相等时，交换到数组最后，减少数组长度，并且在下一步检查交换后的元素是否要删除。时间复杂度O(n)
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] == val){
                nums[i] = nums[n-1];//与最后元素交换，i的值不变，用来检查交换后的元素值
                n--;//数组长度减少
            }
            else
                i++;//元素通过检查
        }
        return n;
    }
};

class Solution {
public:
//设置两个指针，快指针在前面寻找不等于删除元素的值，快指针找到的元素替换为慢指针指向的要删除的元素
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        if (nums.size() == 1){
            if(nums[0] == val)
                return 0;
            else
                return 1;
        }
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val){
                continue;
            }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};
