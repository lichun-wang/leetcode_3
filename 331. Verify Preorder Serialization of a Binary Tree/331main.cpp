#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	bool splitString(vector<string> &res, const string src, char c)
	{
		string::size_type pos1, pos2;
		pos1 = 0;
		pos2 = src.find_first_of(c);
		while (pos2 != string::npos)
		{
			res.push_back(src.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
			pos2 = src.find_first_of(c, pos1);
		}

		if (pos2 != src.length())
		{
			res.push_back(src.substr(pos1, src.length() - pos1));
		}
		return true;
	}
	bool isValidSerialization(string preorder) {

		vector<string> pre;
		splitString(pre, preorder, ',');

		if (pre.size() == 0)
			return false;

		for (int i = 0; i< (int)(pre.size()) - 2; i++)
		{
			if (pre[i] != "#" &&pre[i + 1] == "#" && pre[i + 2] == "#")
			{
				pre.erase(pre.begin() + i);
				pre.erase(pre.begin() + i);

				if (i == 0)
					continue;
				else if (i >= 2 && pre[i - 1] == "#")
					i = i - 3;
				else
					i = i - 2;
			
			}
		}
		if (pre.size() == 1 && pre[0] == "#")
			return true;
		else
			return false;
	}
};

int main()
{
	Solution so;
	cout << so.isValidSerialization("9,#,92,#,#");



	system("pause");
	return 0;
}