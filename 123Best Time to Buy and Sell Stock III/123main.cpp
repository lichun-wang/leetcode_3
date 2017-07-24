/*123. Best Time to Buy and Sell Stock ||*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*�ⷨһ������121��˼·��ѭ�����ֱ����ǰһ���Լ���һ�ε����ֵ��Ȼ�������ͣ��õ����
          ���Ǵ˷������㸴�ӶȱȽϴ󣬳�ʱ��*/
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int n = prices.size();
//		if (n <= 1)
//			return 0;
//
//		int max = 0;
//		for (int i = 1; i < n; i++)
//		{
//			int max1 = findMaxProfit(prices, 0, i);
//			int max2 = findMaxProfit(prices, i, n - 1);
//			if (max1 + max2 > max)
//				max = max1 + max2;
//		}
//		return max;
//	}
//
//	int findMaxProfit(vector<int> prices, int start, int end)
//	{
//		if (end <= start)
//			return 0;
//		int MaxSum = 0;
//		int min = prices[start];
//		for (int i = start+1; i <= end; i++)
//		{
//			if (min > prices[i])
//				min = prices[i];
//			int profit = prices[i] - min;
//			if (profit > MaxSum)
//				MaxSum = profit;
//		}
//		return MaxSum;
//	}
//};


/*�ⷨ�����ο�http://blog.csdn.net/u012501459/article/details/46514309
          ���������飬�ֱ𱣴�ǰһ�Σ���һ�ε����ֵ��Ȼ�������Ӧ��ӣ�ʡʱ
		  �����ܺã�ֵ�÷�˼*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
			return 0;
		int *maxProfit1 = new int[n];
		int *maxProfit2 = new int[n];
		int min = prices[0];
		maxProfit1[0] = 0;
		for (int i = 1; i < n; i++)  //�����������
		{
			if (prices[i] < min)
				min = prices[i];
			maxProfit1[i] = max(prices[i] - min, maxProfit1[i - 1]);
		}

		int maxL = prices[n-1];
		maxProfit2[n-1] = 0;
		for (int i = n - 2; i >= 0; i--)
		{
			if (prices[i] > maxL)
				maxL = prices[i];
			maxProfit2[i] = max(maxL - prices[i], maxProfit2[i + 1]);
		}

		int maxSum = 0;
		for (int i = 0; i < n; i++)
		{
			if (maxProfit1[i] + maxProfit2[i] > maxSum)
				maxSum = maxProfit1[i] + maxProfit2[i];
		}
		return maxSum;

	}

	
};



int main()
{
	Solution so;
	int aa[6] = { 2,1,2,0,1 };
	vector<int> nums(aa, aa + 5);
	cout << so.maxProfit(nums) << endl;
	system("pause");
	return 0;
}