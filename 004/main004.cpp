#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	 	 
		int nums1size = nums1.size();
		int nums2size = nums2.size();

		int allsize = nums1size + nums2size;
		int midNum = ( allsize  +  1) / 2 + 1;

		int i = 0;
		int j = 0;
		int count = 0;

		int num1 = 0;
		int num2 = 0;

		vector<int > results;

		for (i = 0, j = 0 ; i < nums1size && j < nums2size && count < midNum ; count++ )
		{
			num1 = nums1[i];
			num2 = nums2[j];

			if (num1 > num2)
			{
				results.push_back(num2);
				j++;
			}
			else if (num1 < num2)
			{
				results.push_back(num1);
				i++;
			}
			else
			{
				results.push_back(num1);
				results.push_back(num1);
				i++;
				j++;
				count++;
			}

		}

		if (count < midNum)
		{
			if (i == nums1size)
			{
				for (;j<nums2size&&count < midNum; count++)
				{
					num2 = nums2[j];
					results.push_back(num2);
					j++;
				}
			}
			else if (j == nums2size)
			{
				for (; i<nums1size&&count < midNum; count++)
				{
					num1 = nums1[i];
					results.push_back(num1);
					i++;
				}

			}
		}

		float answer = 0;
		if (allsize % 2 == 1)
			answer = results[allsize / 2];
		else
			answer = (results[allsize / 2] + results[allsize / 2 - 1]) * 1.0 / 2;

		return answer;

	}
};

int main()
{
	vector<int > a;
	vector<int > b;
	a.push_back(1);
	a.push_back(2);
	//a.push_back(3);
	//a.push_back(4);

	b.push_back(1);
	b.push_back(2);



	Solution so;
	float ss = so.findMedianSortedArrays(b, a);


	return 0;
}