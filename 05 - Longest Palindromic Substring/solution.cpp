#include "solution.hpp"

std::string Solution::longestPalindrome(std::string s) 
{
	if (s.empty())
		return "";
	if (s.size() == 1)
		return s;

	int start = 0;
	int max = 1;
	std::string result;
	for (int i = 0; i < s.size();)
	{
		if (s.size() - i <= max/2)
			break;

		int k = i, j = i;
		while (j < s.size()-1 && s[j + 1] == s[j])
			++j;

		i = j + 1;
		while (j < s.size()-1 && k > 0 && s[j + 1] == s[k - 1])
		{
			++j;
			--k;
		}

		if (max < j - k + 1)
		{
			start = k;
			max = j - k + 1;
		}
	}
	return s.substr(start,max);
}