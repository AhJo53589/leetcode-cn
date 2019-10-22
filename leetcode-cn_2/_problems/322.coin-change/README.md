# `（中等）`  [322.coin-change 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

### 题目描述
<p>给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回&nbsp;<code>-1</code>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入: </strong>coins = <code>[1, 2, 5]</code>, amount = <code>11</code>
<strong>输出: </strong><code>3</code> 
<strong>解释:</strong> 11 = 5 + 5 + 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>coins = <code>[2]</code>, amount = <code>3</code>
<strong>输出: </strong>-1</pre>

<p><strong>说明</strong>:<br>
你可以认为每种硬币的数量是无限的。</p>


---
### 思路
```
先写了第一种，dfs+贪心+回溯+剪枝，但是最后有一点写乱了，超时了。
然后换了个思路写了第二种，直接通过次数迭代，虽然很慢，但是过了。
回过头来看别人的代码，发现跟我第一种写的几乎一样。
照着改了改，就过了。
功亏一篑很遗憾。
```

### 答题
``` C++
void coinChange(vector<int>& coins, int amount, int c_index, int count, int &ans)
{
	if (amount == 0)
	{
		ans = min(ans, count);
		return;
	}
	if (c_index == coins.size()) return;

	for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
	{
		coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
	}
}

int coinChange(vector<int>& coins, int amount)
{
	if (amount == 0) return 0;
	sort(coins.rbegin(), coins.rend());
	int ans = INT_MAX;
	coinChange(coins, amount, 0, 0, ans);
	return ans == INT_MAX ? -1 : ans;
}
```

### 其它
``` C++
int coinChange(vector<int>& coins, int amount)
{
	if (amount == 0) return 0;
	sort(coins.begin(), coins.end());
	vector<int> _in;
	vector<int> _out;
	unordered_set<int> _set;

	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i] == amount) return 1;
		if (coins[i] > amount) continue;
		_in.push_back(coins[i]);
		_set.insert(coins[i]);
	}
	int k = 2;
	while (!_in.empty())
	{
		bool bOverFlag = true;
		for (auto &a : _in)
		{
			for (auto &c : coins)
			{
				if (a + c == amount) return k;
				if (a + c > amount)
				{
					if (bOverFlag) return -1;
					continue;
				}
				bOverFlag = false;
				if (_set.count(a + c)) continue;
				_out.push_back(a + c);
				_set.insert(a + c);
			}
		}
		k++;
		_in.swap(_out);
		_out.clear();
	}
	return -1;
}
```

