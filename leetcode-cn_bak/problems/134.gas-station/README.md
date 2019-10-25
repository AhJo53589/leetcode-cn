# `（中等）`  [134.gas-station 加油站](https://leetcode-cn.com/problems/gas-station/)

### 题目描述
<p>在一条环路上有&nbsp;<em>N</em>&nbsp;个加油站，其中第&nbsp;<em>i</em>&nbsp;个加油站有汽油&nbsp;<code>gas[i]</code><em>&nbsp;</em>升。</p>

<p>你有一辆油箱容量无限的的汽车，从第<em> i </em>个加油站开往第<em> i+1&nbsp;</em>个加油站需要消耗汽油&nbsp;<code>cost[i]</code><em>&nbsp;</em>升。你从其中的一个加油站出发，开始时油箱为空。</p>

<p>如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。</p>

<p><strong>说明:</strong>&nbsp;</p>

<ul>
	<li>如果题目有解，该答案即为唯一答案。</li>
	<li>输入数组均为非空数组，且长度相同。</li>
	<li>输入数组中的元素均为非负数。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

<strong>输出:</strong> 3

<strong>解释:
</strong>从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 
gas  = [2,3,4]
cost = [3,4,3]

<strong>输出:</strong> -1

<strong>解释:
</strong>你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。</pre>


---
### 思路
```
```

### 答题
``` C++
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int n = gas.size();
	int f = 0;
	vector<int> fuel(n, 0);
	for (int i = 0; i < n; i++)
	{
		fuel[i] = gas[i] - cost[i];
		f += fuel[i];
	}
	if (f < 0) return -1;

	for (int i = 0; i < n; i++)
	{
		if (fuel[i] < 0) continue;
		f = fuel[i];

		int j = (i + 1) % n;
		while (true)
		{
			f += fuel[j];
			if (f < 0)
			{
				i = j;
				break;
			}

			j = (j + 1) % n;
			if (j == i) return i;
		}
	}
	return -1;
}
```

### 其它
[别人的题解](https://leetcode-cn.com/problems/gas-station/solution/c-jie-jue-ban-fa-by-15091329223/)  
```
首先说一个数学定理：  
如果一个数组的总和非负，那么一定可以找到其中找到一个点开始，累加和一直都是非负的  
```

``` C++
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int total = 0;
	int sum = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		int sub = gas[i] - cost[i];
		total += sub;
		sum += sub;
		if (sum < 0)
		{
			sum = 0;
			start = i + 1;
		}
	}
	
	return total < 0 ? -1 : start;
}
```

