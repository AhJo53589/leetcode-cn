# `（中等）` [739.daily-temperatures 每日温度](https://leetcode-cn.com/problems/daily-temperatures/)

### 题目描述
<p>根据每日 <code>气温</code> 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用&nbsp;<code>0</code> 来代替。</p>

<p>例如，给定一个列表&nbsp;<code>temperatures = [73, 74, 75, 71, 69, 72, 76, 73]</code>，你的输出应该是&nbsp;<code>[1, 1, 4, 2, 1, 1, 0, 0]</code>。</p>

<p><strong>提示：</strong><code>气温</code> 列表长度的范围是&nbsp;<code>[1, 30000]</code>。每个气温的值的均为华氏度，都是在&nbsp;<code>[30, 100]</code>&nbsp;范围内的整数。</p>





---
### 思路
``` 
```


### 答题
``` C++
vector<int> dailyTemperatures(vector<int>& T)
{
	vector<int> days(T.size());
	stack<int> s;
	for (int i = 0; i < T.size(); i++)
	{
		while (!s.empty() && T[s.top()] < T[i])
		{
			days[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	return days;
}
``` 
