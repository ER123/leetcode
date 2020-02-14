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

ListNode* solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
		ListNode *resultList;
		resultList = (ListNode*)malloc(sizeof(ListNode));
		resultList->next = NULL;

		ListNode *r = resultList;

		ListNode *current1 = l1->next;
		ListNode *current2 = l2->next;
		int iscarry = 0;
		int tmpVal = 0;

		//while (current1 != NULL && current2 != NULL)
		//{
		//	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//	tmpVal = (current1->val + current2->val + iscarry) % 10;
		//	if ((current1->val + current2->val + iscarry) / 10)
		//		iscarry = 1;
		//	else
		//		iscarry = 0;
		//	p->val = tmpVal;
		//	r->next = p;
		//	r = p;
		//	current1 = current1->next;
		//	current2 = current2->next;
		//}
		//while (current1 != NULL)
		//{
		//	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//	p->val = (current1->val + iscarry) % 10;
		//	r->next = p;
		//	r = p;
		//	r->next = new ListNode((current1->val + iscarry) % 10);
		//	current1 = current1->next;
		//	if (current1 == NULL && iscarry == 1)
		//		r->next = new ListNode(1);
		//	else
		//		iscarry = (current1->val + iscarry) / 10;
		//}
		//while (current2 != NULL)
		//{
		//	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//	p->val = (current2->val + iscarry) % 10;
		//	r->next = p;
		//	r = p;
		//	current2 = current2->next;
		//	if (current2 == NULL && iscarry == 1)
		//		r->next = new ListNode(1);
		//	else
		//		iscarry = (current2->val + iscarry) / 10;
		//}
		//if (iscarry)
		//{
		//	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//	p->val = iscarry;
		//	r->next = p;
		//	r = p;
		//}
		//r->next = NULL;
		//return resultList;

		while (current1!=NULL||current2!=NULL)
		{
			tmpVal /= 10;
			if (current1 != NULL)
			{
				tmpVal += current1->val;
				current1 = current1->next;
			}
			if (current2 != NULL)
			{
				tmpVal += current2->val;
				current2 = current2->next;
			}
			r->next = new ListNode(tmpVal % 10);
			r = r->next;
		}
		if (tmpVal / 10 == 1)
			r->next = new ListNode(1);
		return resultList;
}

ListNode* solution::input(ListNode *l)//Head insert
{
	l = (ListNode *)malloc(sizeof(ListNode));
	l->next = NULL;

	int val;
	cin >> val;
	while (val != -1)
	{
		ListNode *p = (ListNode *)malloc(sizeof(ListNode));
		p->val = val;
		p->next = l->next;
		l->next = p;
		cin >> val;
	}
	return l;
}

int solution::lengthOfLongestSubstring(std::string s)
{
	vector<int> dict(256, -1);
	int maxLen = 1, start = -1;
	for (int i = 0; i < s.length(); ++i)
	{
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;

	//vector<int> letter;
	//int len = s.length();
	//for (int i = 0; i < len; ++i)
	//{
	//	letter.push_back(s[i]);
	//}
	//int max = 0;
	//int num = 1;
	//int firstplace = 0;
	//int firstplaceTmp = 0;
	//for (int i = 0; i < len; ++i)
	//{
	//	for (int j = firstplace; j < i; ++j)
	//	{
	//		if (letter[i] == letter[j])
	//		{
	//			num = 1;
	//			if (letter[i] == letter[i - 1])
	//				firstplaceTmp = i;
	//			else
	//				firstplaceTmp = j + 1;
	//		}
	//		else	
	//			num++;
	//	}
	//	firstplace = firstplaceTmp;
	//	
	//	if (num > max)
	//		max = num;
	//	num = 1;
	//}
	//
	//return max;
}

double solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	if (m > n)
	{
		swap(m, n);
		swap(nums1, nums2);
	}
	if (n == 0)
		return -1;

	int imin = 0;
	int imax = m;
	int half_len = (n + m + 1) / 2;
	int max_left, min_right;

	while (imin <= imax)
	{
		int i = (imin + imax) / 2;
		int j = half_len - i;

		if (i<m && nums2[j - 1] > nums1[i])
			imin = i + 1;

		else if (i > 0 && nums1[i - 1] > nums2[j])
			imax = i - 1;
		else
		{
			if (i == 0)
				max_left = nums2[j - 1];
			else if (j == 0)
				max_left = nums1[i - 1];
			else
				max_left = max(nums1[i - 1], nums2[j - 1]);

			if ((m + n) % 2 == 1)
				return max_left;

			if (i == m)
				min_right = nums2[j];
			else if (j == n)
				min_right = nums1[i];
			else
				min_right = min(nums1[i], nums2[j]);
			
			return (max_left + min_right) / 2.0;

		}
	}
	return 0;
}