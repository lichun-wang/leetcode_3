#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {

		int answer = 0;
		char ss = s[0];
		int val = charToint( ss );
		answer += val;

		for (int i = 1; i < s.length(); i++)
		{
			char left = s[i - 1];
			char right = s[i];
			int val_1 = charToint(right);
			int val_2 = charToint(left);

			if ( val_1 > val_2 )
			{
				answer = answer + val_1 - 2 * val_2;
			}
			else{
				answer = answer + val_1;
			}
		}
		return answer;
	}
	int charToint(char aa)
	{
	
		int val = 0;
		switch (aa)
		{
		  case 'I': val = 1; break;
		  case 'V': val = 5; break;
		  case 'X': val = 10; break;
		  case 'L': val = 50; break;
		  case 'C': val = 100; break;
		  case 'D': val = 500; break;
		  case 'M': val = 1000; break;
		  default: val = 0;
		}
		return val;
	}
};

int main()
{
	Solution so;
	string ss = "MMMCC";
	cout<<so.romanToInt(ss);
	int a;
	cin >> a;
	return 0;
}