#include "solution.hpp"
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> solution::twoSum(std::vector<int> &nums, int target)
{
	std::vector<int> answer;
	int len = nums.size();
	for (int i = 0; i < len - 1; ++i)
		for (int j = i + 1; j < len; ++j)
		{
			int tmp = nums[i] + nums[j];
			if (tmp == target)
			{
				answer.push_back(i);
				answer.push_back(j);
				return answer;
			}
		}
	return answer;
}
