#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;
		set<char> str_set;
		int maxLength = 0;//记录最长的无重复字符串长度

		int i, j;
		for (i=0,j = 0; i<s.length() && j < s.length(); )
		{
			if (str_set.find(s[j]) == str_set.end())
			{
				str_set.insert(s[j]);
				j++;
			}
			else
			{
				maxLength = max(maxLength, (int)str_set.size());
				str_set.erase(s[i]);
				i++;

			}
		}
		maxLength = max(maxLength, (int)str_set.size());
		return maxLength;
	}
};

int main()
{
	
	string str = "aab";
	Solution so;
	cout<<so.lengthOfLongestSubstring(str)<<endl;
	
	return 0;
}