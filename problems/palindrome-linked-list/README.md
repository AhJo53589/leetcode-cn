# `（简单）` [234.palindrome-linked-list 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

### 题目描述
<p>请判断一个链表是否为回文链表。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2
<strong>输出:</strong> false</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;2-&gt;1
<strong>输出:</strong> true
</pre>

<p><strong>进阶：</strong><br>
你能否用&nbsp;O(n) 时间复杂度和 O(1) 空间复杂度解决此题？</p>





---
### 思路
```
这道题其实是需要考虑链表单双情况的，  
但是可以看到快指针为空时，  
偶数情况slow指针索引为n/2，奇数情况slow指针索引为n/2+1。  
所以逆序的后半段链表，可以直接和head指针开始对比。  
```
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/234.IsPalindrome/Solution.jpg)

### 答题
``` C++
bool isPalindrome(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL)
	{
		slow = slow->next;
		fast = (fast->next != NULL) ? fast->next->next : fast->next;
	}

	ListNode *prev = NULL;
	while (slow != NULL)
	{
		ListNode *tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}

	while (head != NULL && prev != NULL)
	{
		if (head->val != prev->val) return false;

		head = head->next;
		prev = prev->next;
	}
	return true;
}
``` 
