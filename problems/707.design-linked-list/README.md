# `（简单）`  [707.design-linked-list 设计链表](https://leetcode-cn.com/problems/design-linked-list/)

### 题目描述
<p>设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：<code>val</code>&nbsp;和&nbsp;<code>next</code>。<code>val</code>&nbsp;是当前节点的值，<code>next</code>&nbsp;是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。</p>

<p>在链表类中实现这些功能：</p>

<ul>
	<li>get(index)：获取链表中第&nbsp;<code>index</code>&nbsp;个节点的值。如果索引无效，则返回<code>-1</code>。</li>
	<li>addAtHead(val)：在链表的第一个元素之前添加一个值为&nbsp;<code>val</code>&nbsp;的节点。插入后，新节点将成为链表的第一个节点。</li>
	<li>addAtTail(val)：将值为&nbsp;<code>val</code> 的节点追加到链表的最后一个元素。</li>
	<li>addAtIndex(index,val)：在链表中的第&nbsp;<code>index</code>&nbsp;个节点之前添加值为&nbsp;<code>val</code>&nbsp; 的节点。如果&nbsp;<code>index</code>&nbsp;等于链表的长度，则该节点将附加到链表的末尾。如果 <code>index</code> 大于链表长度，则不会插入节点。</li>
	<li>deleteAtIndex(index)：如果索引&nbsp;<code>index</code> 有效，则删除链表中的第&nbsp;<code>index</code> 个节点。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-&gt; 2-&gt; 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-&gt; 3
linkedList.get(1);            //返回3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有值都在&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>操作次数将在&nbsp;&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>请不要使用内置的 LinkedList 库。</li>
</ul>


---
### 思路
```
题目没有说清楚addAtIndex()负数加在开头。  
```

### 答题
``` C++
class MyLinkedList
{
public:
	/** Initialize your data structure here. */
	MyLinkedList()
		: m_pHead(NULL)
		, m_len(0)
	{

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index < 0 || index >= m_len) return -1;

		LinkedLIstNode *pNode = m_pHead;
		while (index-- > 0) pNode = pNode->m_pNext;
		return pNode->m_val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		LinkedLIstNode *pNode = m_pHead;
		m_pHead = new LinkedLIstNode(val, m_pHead);
		m_len++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		LinkedLIstNode *pNode = m_pHead;
		while (pNode->m_pNext != NULL) pNode = pNode->m_pNext;
		pNode->m_pNext = new LinkedLIstNode(val, NULL);
		m_len++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > m_len) return;

		if (index <= 0) addAtHead(val);
		else if (index == m_len) addAtTail(val);
		else
		{
			LinkedLIstNode *pNode = m_pHead;
			while (index-- > 1) pNode = pNode->m_pNext;
			LinkedLIstNode *pNew = new LinkedLIstNode(val, pNode->m_pNext);
			pNode->m_pNext = pNew;
			m_len++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= m_len) return;

		LinkedLIstNode *pNode = m_pHead;
		if (index == 0)
		{
			m_pHead = m_pHead->m_pNext;
			delete pNode;
			m_len--;
		}
		else
		{
			while (index-- > 1) pNode = pNode->m_pNext;
			LinkedLIstNode *pDelete = pNode->m_pNext;
			pNode->m_pNext = pDelete->m_pNext;
			delete pDelete;
			m_len--;
		}
	}

private:
	LinkedLIstNode *m_pHead;
	int m_len;
};
```

### 其它
``` C++
struct DListNode {
    int val;
    DListNode *prev, *next;
    DListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto node = getNode(index);
        return node ? node->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new DListNode(val);
        size_++;
        
        if (head_ == nullptr) 
        {
            tail_ = node;
        } 
        else 
        {
            node->next = head_;
            head_->prev = node;
        }
        head_ = node; 
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = new DListNode(val);
        size_++;
        
        if (tail_ == nullptr) 
        {
            head_ = node;
        } 
        else 
        {
            tail_->next = node;
            node->prev = tail_;
        }
        tail_ = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size_) return;
        if (index == size_) {
            addAtTail(val);
            return;
        }
        
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        
        auto node = new DListNode(val);
        auto next = getNode(index);
        
        node->next = next;
        node->prev = next->prev;
        next->prev->next = node;
        next->prev = node;
        
        size_++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (auto node = getNode(index)) {
            if (node == head_) {
                head_ = head_->next;
                if (head_ != nullptr) head_->prev = nullptr;
                node->next = nullptr;
            }
            
            if (node == tail_) {
                tail_ = tail_->prev;
                if (tail_ != nullptr) tail_->next = nullptr;
                node->prev = nullptr;
            }
            
            if (node->next != nullptr) node->next->prev = node->prev;
            if (node->prev != nullptr) node->prev->next = node->next;

            delete node;
            size_--;
        }
    }
    
private:
    DListNode *getNode(int index) {
        if (index >= size_ || index < 0) return nullptr;
        
        DListNode *node;
        int i;
        
        if (size_ - index - 1 < index)  //后半部分查找
        {
            i = size_ - index - 1;
            node = tail_;
            while (i-- > 0)
            {
                node = node->prev;
            }
        } 
        else //前半部分查找
        {
            i = index;
            node = head_;
            while (i-- > 0)
            {
                node = node->next;
            }
        }
        
        return node;
    }
    
private:
    DListNode *head_;
    DListNode *tail_;
    int size_;
};
```

