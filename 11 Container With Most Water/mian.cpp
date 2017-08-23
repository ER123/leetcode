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
