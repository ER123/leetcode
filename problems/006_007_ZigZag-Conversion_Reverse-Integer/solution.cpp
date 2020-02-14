#include "solution.hpp"
#include <vector>

//std::string Solution::convert(std::string s, int numRows)
//{
//	if (numRows == 1)
//	{
//		return s;
//	}
//	int len = s.length();
//	std::string result{""};
//	std::vector<std::string> resBuffer(numRows, "" );
//	int i = 0;
//	while (i < len)
//	{
//		for (int j = 0; j < numRows && i < len; ++j)
//		{
//			resBuffer[j].push_back(s[i++]);
//		}
//		for (int j = numRows - 2; j >= 1 && i < len; --j)
//		{
//			resBuffer[j].push_back(s[i++]);
//		}
//	}
//	for (std::string s1:resBuffer)
//	{
//		result += s1;
//	}
//	return result;
//}

std::string Solution::convert(std::string s, int numRows)
{
	if (numRows == 1)
	{
		return s;
	}
	std::string result;
	int len = s.length();
	int step1, step2;
	for (int i = 0; i < numRows; ++i)
	{
		int pos = i;
		step1 = (numRows - i - 1) * 2;
		step2 = i * 2;
		if (pos < len)
			result += s[pos];
		while (true)
		{
			pos += step1;
			if (pos >= len)
				break;
			if (step1)
				result += s[pos];

			pos += step2;
			if (pos >= len)
				break;
			if (step2)
				result += s[pos];
		}
	}
	return result;

}


int Solution::resver_intger(int x)
{
	long long r = 0;  ///very solw!!!
	while (x)
	{
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r < std::numeric_limits<int>::min() || r > std::numeric_limits<int>::max() ? 0 : r;

}