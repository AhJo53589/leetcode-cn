# `（困难）` [354.russian-doll-envelopes 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)

### 题目描述
<p>给定一些标记了宽度和高度的信封，宽度和高度以整数对形式&nbsp;<code>(w, h)</code>&nbsp;出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。</p>

<p>请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。</p>

<p><strong>说明:</strong><br>
不允许旋转信封。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> envelopes = <code>[[5,4],[6,4],[6,7],[2,3]]</code>
<strong>输出:</strong> 3 
<strong>解释:</strong> 最多信封的个数为 <code>3, 组合为: </code>[2,3] =&gt; [5,4] =&gt; [6,7]。
</pre>


---
### 思路
```
真的是一道困难的题，死磕了一天。

前面排序处理总算是对的。
先按照w来排序，如果w相同，h按照从大到小排序。
排序的作用是将w固定好，将2维问题简化成1维问题。

后半部分我使用的是“最长上升子序列”的思路来解题的，
虽然用例都通过了，但是我从原理上分析，隐隐的感觉可能会有一些情况不能通过。
对比别人的代码，后半部分的处理逻辑上就非常清晰。
但是看起来好像跟我的算法本质又一样的。
可能我还需要再想一想。

更新：
今天通过自己手动跑了一遍针对用例，彻底捋清楚了。
算法是没问题的。
详情查看发布的题解。  

[[1,1],[2,2],[3,3],[10,10],[11,11],[12,5],[12,4],[13,5],[20,6]]

```

[发布的题解](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/354-by-ikaruga/)

### 答题
``` C++
int maxEnvelopes(vector<vector<int>>& envelopes)
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	vector<int> vec;
	for (int i = 0; i < envelopes.size(); i++)
	{
		int h = envelopes[i][1];
		if (vec.empty() || h > vec.back())
		{
			vec.push_back(h);
		}

		for (int j = 0; j < vec.size(); j++)
		{
			if (h <= vec[j])
			{
				vec[j] = h;
				break;
			}
		}
	}

	return vec.size();
}
```


### 其它
```
别人的代码，前面排序跟我是一样的。
后面算数量的时候思路明确。
使用lower_bound二分查找，返回的是数组中大于等于的第一个值。
然后记录长度，并max更新ans。
```
``` C++
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) 
	{
		return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
	});

	int ans = 0;
	vector<int> vec(envelopes.size(), INT_MAX);
	for (auto &e : envelopes) 
	{
		auto it = lower_bound(vec.begin(), vec.end(), e[1]);
		*it = e[1];
		ans = max(ans, int(it - vec.begin()));
	}
	return ans + 1;
}
```

