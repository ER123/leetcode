class Solution {
public:
    int romanToInt(string s) {
	std::vector<int> vec;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == 'I')
			vec.push_back(1);
		if (s[i] == 'V')
			vec.push_back(5);
		if (s[i] == 'X')
			vec.push_back(10);
		if (s[i] == 'L')
			vec.push_back(50);
		if (s[i] == 'C')
			vec.push_back(100);
		if (s[i] == 'D')
			vec.push_back(500);
		if (s[i] == 'M')
			vec.push_back(1000);
	}

	int res = 0;
	int i = 0;
	int j = 0;

	while (i < len)
	{
		if (i+1<len)
		{
			j = i + 1;
			if (vec[i] < vec[j])
			{
				vec[j] = vec[j] - vec[i];
				vec[i] = 0;
			}
		}
        res += vec[i];
		i++;
	}

	return res;
    }
};
