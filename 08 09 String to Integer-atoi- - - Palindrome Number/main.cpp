#include <iostream>
#include <string>

int myatoi(std::string str)
{
	if (str.empty())
		return 0;

	int len = str.length();
	long long res = 0;
	int i = 0;
	int sign = 1;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');

	//if (str[i] == '-' || str[i] == '+')
	//	sign = (str[i++] == '+') ? 1 : -1;

	while (str[i] >= '0' && str[i] <= '9')
	{	
		res = res * 10 + (str[i++] - '0');
		if (res*sign >= INT_MAX) return INT_MAX;
		if (res*sign <= INT_MIN) return INT_MIN;
	}

	res = res*sign;

	return res;
}

bool isPalindromeNum(int x)
{
	if (x < 0)
		return false;
	// Answer1
	//std::string s = std::to_string(x);
	//int len = s.length();
	//int i = len / 2;
	//int j = 0;

	//if (len % 2 == 0)
	//	j = i - 1;
	//else
	//	j = i;
	//while (i >= 0 && j < len)
	//{
	//	if (s[i] == s[j])
	//	{
	//		j++;
	//		i--;
	//	}
	//	else
	//		return false;
	//}
	//return true;

	//Answer2
	//int temp = 1;
	//while (temp <= x / 10)
	//	temp *= 10;
	//while (x>0)
	//{
	//	if (x / temp != x % 10)
	//		return false;
	//	x = (x % temp) / 10;//掐头去尾
	//	temp /= 100;
	//}
	//return true;

	//Answer 3
	int temp = 0;
	while (temp < x)
	{
		temp = temp * 10 + x % 10;
		x /= 10;
	}

	if (x == temp || x == temp / 10)
		return true;
	else
		return false;
}


int main(int argc, char** argv)
{
	//std::cout << "Input string :" << std::endl;
	//std::string s;
	//std::cin >> s;

	//int res = myatoi(s);
	//std::cout << "myatoi result is " << res << std::endl;

	std::cout << "Input s number " << std::endl;
	int x;
	std::cin >> x;
	bool flag = isPalindromeNum(x);
	if (flag)
		std::cout << "Yes" << std::endl;
	else 
		std::cout << "No" << std::endl;
	return 0;
}
