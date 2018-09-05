//寻找数组中第三大的数字，时间复杂度为O(n)，使用set保存三个数字，set按照值从小到大排序
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> max3;
        int len_nums = nums.size();
        for (int i =0; i < len_nums; i++){
            max3.insert(nums[i]);
            if(max3.size()>3){
                max3.erase(max3.begin());
            }
        }
        return max3.size() == 3 ? *max3.begin() : *max3.rbegin();
    }
};
