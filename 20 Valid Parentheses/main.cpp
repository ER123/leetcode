class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        int len = s.length();
        if(len%2 == 1)
            return false;
        stack<char> mystack;
        mystack.push(s[0]);
	int i = 1;
	int j = 1;
	while (i < len)
	{
		if (mystack.empty())
		{	
			mystack.push(s[i]);
			++i;
		}
		int temp = s[i] - mystack.top();
		if (temp == 1 || temp == 2)
		{
			mystack.pop();
		}
		else
		{
			mystack.push(s[i]);
		}
		++i;
	}
	if (mystack.empty())
        return true;
    else 
        return false;
    }
};
