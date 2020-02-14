class Solution {
public:
    int maxArea(vector<int>& height) {
  int maxnum = 0;
	int start = 0;
	int end = height.size() - 1;
	while (start < end)
	{
		int temp = 0;

		if (height[start] > height[end])
		{
			temp = height[end] * (end - start);
			end--;
		}
		else
		{
			temp = height[start] * (end - start);
			start++;
		}

		if (temp > maxnum)
			maxnum = temp;
	}
	return maxnum;
    }
};

//int maxArea(vector<int>& height) {
//    int water = 0;
//    int i = 0, j = height.size() - 1;
//    while (i < j) {
//        int h = min(height[i], height[j]);
//        water = max(water, (j - i) * h);
//        while (height[i] <= h && i < j) i++;
//        while (height[j] <= h && i < j) j--;
//    }
//    return water;
//}
