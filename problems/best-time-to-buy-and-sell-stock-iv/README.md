# `（困难）` [188.best-time-to-buy-and-sell-stock-iv 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

### 题目描述
<p>给定一个数组，它的第<em> i</em> 个元素是一支给定的股票在第 <em>i </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <strong>k</strong> 笔交易。</p>

<p><strong>注意:</strong>&nbsp;你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [2,4,1], k = 2
<strong>输出:</strong> 2
<strong>解释:</strong> 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [3,2,6,5,0,3], k = 2
<strong>输出:</strong> 7
<strong>解释:</strong> 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
&nbsp;    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
	int maxProfit_k_any(int max_k, vector<int>& prices)
	{
		vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
		for (size_t i = 0; i < prices.size(); i++)
		{
			for (size_t k = max_k; k >= 1; k--)
			{
				if (i == 0)
				{
					dp[i][k][0] = 0;
					dp[i][k][1] = -prices[i];
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[prices.size() - 1][max_k][0];
	}	
	
	int maxProfit_k_inf(vector<int>& prices)
	{
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		for (size_t i = 0; i < prices.size(); i++)
		{
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i]);
		}
		return dp_i_0;
	}

    int maxProfit(int k, vector<int>& prices) 
	{
		return (k > prices.size() / 2) ? maxProfit_k_inf(prices) : maxProfit_k_any(k, prices);
    }
};
```




