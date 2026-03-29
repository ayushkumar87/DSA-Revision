/*

Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.

Input: [0, 1, 2, 6, 9, 11, 15]
Output: 3

Input: [1, 2, 3, 4, 6, 9, 11, 15]
Output: 0

Input: [0, 1, 2, 3, 4, 5, 6]
Output: 7

*/

class Solution
{
public:
	int findSmallestMissingNumber(vector<int> const &nums)
	{
		// Write your code here...
		int st=0, end=nums.size()-1;
		int idx=0;
		while(st<=end){
			int mid=(st+end)/2;
			
			if(mid<nums[mid]){
				idx=mid;
				end=mid-1;
			}
			else{
				idx=mid+1;
				st=mid+1;
				
			}
		}
		return idx;
	}
};
