#include "solution.hpp"
#include <iostream>

int main(int argv, char** argc)
{
	Solution solu;
	std::string s;
	std::cin >> s;
	std::string res = solu.longestPalindrome(s);
	std::cout << res << std::endl;

	return 0;
}
