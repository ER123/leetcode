#include <iostream>
#include <string>
#include "solution.hpp"

int main()
{
	//std::string s;
	//std::cout << "Input string s:" << std::endl;
	//std::cin >> s;

	//std::cout << "Input nRows:" << std::endl;
	//int nRows;
	//std::cin >> nRows;

	//Solution solu;
	//std::string result = solu.convert(s,nRows);
	//std::cout << result << std::endl;

	std::cout << "Input a number :" << std::endl;
	int n;
	std::cin >> n;
	Solution solu;
	int res = solu.resver_intger(n);
	std::cout << "result = " << res << std::endl;

	return 0;
}
