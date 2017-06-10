#include<iostream>
#include<algorithm>
#include <io.h>
#include<vector>
#include<fstream>

using namespace std;



class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();

		if (len1 == 0 || len2 == 0)
			return abs(len1 - len2);

		vector< vector<int>> v(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i <= len1; i++)
		{
			for (int j = 0; j <= len2; j++)
			{
				if (i == 0)
				{
					v[i][j] = j;
					continue;
				}

				if (j == 0)
				{
					v[i][j] = i;
					continue;
				}
				int a1 = v[i - 1][j] + 1;
				int a2 = v[i][j - 1] + 1;
				int a3 = 0;
				if (word1[i-1] == word2[j-1]) //这里注意，是 -1
					a3 = v[i - 1][j - 1];
				else
					a3 = v[i - 1][j - 1] + 1;
				v[i][j] = min(min(a1, a2), a3);
			}
		}

		return  v[len1][len2];
	}
};

int main()
{
	Solution so;
	string w1 = "a";
	string w2 = "ab";
	cout<<so.minDistance(w1,w2);
	return 0;
}