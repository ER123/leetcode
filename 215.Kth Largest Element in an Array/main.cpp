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
//方法三：首先对前K个数构建一个小顶堆，再跟之后的值比较，如果大于堆顶将堆顶替换，调整堆，如果小于堆顶继续；
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> Kmax;
        Kmax.resize(k);
        for(int i = 0; i < k; i++){
            Kmax[i] = nums[i];
        }
        HeapBulid(Kmax, k);
        int len_nums = nums.size();
        for (int i = k; i < len_nums; i++){
            if(nums[i] < Kmax[0])
                continue;
            Kmax[0] = nums[i];
            AdjustHeap(Kmax, 0,k);
        }
        return Kmax[0];
    }
    void HeapBulid(vector<int>& Kmax, int k){
        for(int i = k/2 - 1; i >= 0; i--){
            AdjustHeap(Kmax, i, k);
        }
    }
    void AdjustHeap(vector<int>& Kmax, int i, int k){
        int left = i*2+1;
        int right = i*2+2;
        int min = i;
        if(left < k && Kmax[left] < Kmax[min]){
            min = left;
        }
        if(right < k && Kmax[right] < Kmax[min]){
            min = right;
        }
        if(min != i){
            int temp = Kmax[min];
            Kmax[min] = Kmax[i];
            Kmax[i] = temp;
            AdjustHeap(Kmax, min, k);
        }
    }
};
