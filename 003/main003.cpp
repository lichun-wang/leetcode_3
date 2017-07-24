#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;
		string singleStr;

		int maxSize = 0;
		vector<int >size;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			for (int j = i; j < length; j++)
			{

				if (singleStr.find(s[j])  == -1)
					singleStr.append(s,j,1);
				else
					break;
			}

			if (maxSize < singleStr.length())
				maxSize = singleStr.length();

			singleStr.clear();
		}


		return maxSize;
	}
};



int  main()
{
	string ss = "pwwkew";
	Solution so;
	int aa = so.lengthOfLongestSubstring(ss);
	return 0;
}