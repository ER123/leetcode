#include <vector>
#include <string>
#include "struct.hpp"

class solution{
public:
	std::vector<int> twoSum(std::vector<int>&, int);
	
	ListNode* input(ListNode* l);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	int lengthOfLongestSubstring(std::string s);

	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
};