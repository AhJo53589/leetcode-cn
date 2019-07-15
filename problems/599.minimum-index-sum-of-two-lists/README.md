# `（简单）`  [599.minimum-index-sum-of-two-lists 两个列表的最小索引总和](https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/)

### 题目描述
<p>假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。</p>

<p>你需要帮助他们用<strong>最少的索引和</strong>找出他们<strong>共同喜爱的餐厅</strong>。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
<strong>输出:</strong> ["Shogun"]
<strong>解释:</strong> 他们唯一共同喜爱的餐厅是“Shogun”。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
<strong>输出:</strong> ["Shogun"]
<strong>解释:</strong> 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
</pre>

<p><strong>提示:</strong></p>

<ol>
	<li>两个列表的长度范围都在&nbsp;[1, 1000]内。</li>
	<li>两个列表中的字符串的长度将在[1，30]的范围内。</li>
	<li>下标从0开始，到列表的长度减1。</li>
	<li>两个列表都没有重复的元素。</li>
</ol>


---
### 思路
```
```

### 答题
``` C++
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
	unordered_map<string, int> restIndex;
	unordered_set<string> restList2;
	for (int i = 0; i < list1.size(); i++)
	{
		restIndex[list1[i]] = i;
	}
	for (int i = 0; i < list2.size(); i++)
	{
		if (!restIndex.count(list2[i])) continue;
		restList2.insert(list2[i]);
		restIndex[list2[i]] += i;
	}

	int rIndex = INT_MAX;
	vector<string> rst;
	for (auto r : restIndex)
	{
		if (!restList2.count(r.first)) continue;
		if (r.second == rIndex)
		{
			rst.push_back(r.first);
		}
		else if (r.second < rIndex)
		{
			rIndex = r.second;
			rst.clear();
			rst.push_back(r.first);
		}
	}
	return rst;
}
```
