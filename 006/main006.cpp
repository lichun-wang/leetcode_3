#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {

		if (s.length() == 0 || numRows == 1)
			return s;

		string result;
		int gap = 2 * (numRows - 1);
		int cols = (s.length() + gap - 1) / gap;

		int i = 0, j = 0;
		for (i = 0; i<numRows - 1; i++)
		{
			if (i < s.length())
				result.push_back(s[i]);

			for (j = 1; j<cols+1; j++)
			{
				if (j*gap - i <s.length())
					result.push_back(s[j * gap - i]);

				if (i == 0)
					continue;

				if (j * gap + i <s.length())
					result.push_back(s[j * gap + i]);
			}
		}
		if (numRows - 1 <s.length())
			result.push_back(s[numRows - 1]);
		for (j = 1; j<cols+1; j++)
		{
			if (j*gap + numRows - 1 <s.length())
				result.push_back(s[j * gap + numRows - 1]);

		}

		return result;
	}
};


int main()
{
	string str = "abcd";
	Solution so;
	string res = so.convert(str, 3);
	return 0;
}
