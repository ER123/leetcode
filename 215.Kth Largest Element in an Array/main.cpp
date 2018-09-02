//计算一个数组中第K大的数字，重复的也算上，方法一，完全快排，取第K个值；方法二：利用快排只需排到前面K个数字有序即可；方法三：堆排序，维护堆，适合大规模数据。
//方法二，只将前K个数字有序排列
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lens_nums = nums.size();
        return help(nums, 0, lens_nums-1, k);
    }
    int help(vector<int>& nums, int left, int right, int k){
        int m = partation(nums, left, right);//前后排序的基准
        if (k == m-left+1) 
            return nums[m];
        else if(k < m-left+1)//K在基准左边，只需对左边有序排序
            return help(nums, left, m-1, k);
        else                //K在基准右边对左边排序后，在对右边小于K的部分排序
            return help(nums, m+1, right, k-(m-left+1));
    }
    int partation(vector<int>& nums, int left, int right){
        int temp = nums[left];
        while(left < right){
            while(left < right && nums[right] <= temp){
                right--;
            }
            if(left < right){
                nums[left] = nums[right];
            }
                
            while(left < right && nums[left] > temp){
                left++;
            }
            if(left < right){
                nums[right] = nums[left];
            }
            
        }
        nums[left] = temp;
        return left;
    }
};
