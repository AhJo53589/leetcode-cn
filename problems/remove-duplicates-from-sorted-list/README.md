# `（简单）` [83.remove-duplicates-from-sorted-list 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

### 题目描述
<p>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 1->1->2
<strong>输出:</strong> 1->2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 1->1->2->3->3
<strong>输出:</strong> 1->2->3</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
	{
		ListNode* pRet = head;
		ListNode* pNode = head;
		while (pNode != nullptr && pNode->next != nullptr)
		{
			if (pNode->val == pNode->next->val)
			{
				pNode->next = pNode->next->next;
			}
			else
			{
                pNode = pNode->next;
			}
		}
		return pRet;
    }
};
```




