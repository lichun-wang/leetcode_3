#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		
		string answer = "";

		if (strs.size() == 0)
			return answer;

		int shortestLength = strs[0].length() ;
		bool isSame;
		for (int i = 1; i < strs.size(); i++)
		{
			if (shortestLength > strs[i].length())
			{
				shortestLength = strs[i].length();
			}
		}

		for (int i = 0; i < shortestLength; i++)
		{
			isSame = true;
			for (int j = 1; j < strs.size(); j++)
			{
				isSame = isSame & (strs[j][i] == strs[0][i]);
			}

			if (isSame)
				answer.push_back(strs[0][i]);
			else
				break;
		}

		return answer;
	}
};

int main()
{
	Solution so;
	vector<string> ss;
	ss.push_back("aca");
	ss.push_back("cba");
//	ss.push_back("");
	cout<<so.longestCommonPrefix(ss)<<endl;
	int a;
	cin >> a;
	return 0;
}