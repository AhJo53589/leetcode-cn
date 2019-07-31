# `（困难）`  [23.merge-k-sorted-lists 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

### 题目描述
<p>合并&nbsp;<em>k&nbsp;</em>个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
[
&nbsp; 1-&gt;4-&gt;5,
&nbsp; 1-&gt;3-&gt;4,
&nbsp; 2-&gt;6
]
<strong>输出:</strong> 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6</pre>


---
### 思路
```
```

### 答题
``` C++
ListNode* mergeKLists(vector<ListNode*>& lists) 
{

	ListNode *pHead = new ListNode(0);
	ListNode *pNode = pHead;
	int len = lists.size();
	int nullCount = 0;
	while (nullCount < len)
	{
		nullCount = 0;
		pair<int, int> minVal = { -1, INT_MAX };
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == nullptr)
			{
				nullCount++;
				continue;
			}
			if (lists[i]->val < minVal.second)
			{
				minVal.first = i;
				minVal.second = lists[i]->val;
			}
		}
		if (minVal.first == -1) continue;
		pNode->next = lists[minVal.first];
		pNode = pNode->next;
		lists[minVal.first] = lists[minVal.first]->next;
	}
	pNode->next = nullptr;
	pNode = pHead->next;
	delete pHead;
	return pNode;
}
```
