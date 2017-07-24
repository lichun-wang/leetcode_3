#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {

		if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
			return true;

		if (s1.length() + s2.length() != s3.length())
			return false;

		vector<vector<int> > res(s1.length() + 1, vector<int>(s2.length() + 1, false));

		bool first = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == s3[i] && first == true)
				res[i+1][0] = 1;
			else
			{
				first = false;
				res[i+1][0] = 0;
			}

		}

		first = true;
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] == s3[i] && first == true)
				res[0][i+1] = 1;
			else
			{
				first = false;
				res[0][i+1] = 0;
			}

		}

		if (res[0][1] == 1 || res[1][0] == 1)
			res[0][0] = 1;
		else
			res[0][0] = 0;


		for (int i = 1; i <= s1.length(); i++)
		{
			for (int j = 1; j<= s2.length(); j++)
			{
				res[i][j] = (res[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					(res[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}

		return res[s1.length()][s2.length()];
	}
};
int main()
{
	string s1("a");
	string s2("b");
	string s3("ab");
	Solution so;
	cout<< so.isInterleave(s1, s2, s3)<<endl;
	system("pause");
	return 0;
}