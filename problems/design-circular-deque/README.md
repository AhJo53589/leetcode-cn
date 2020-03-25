# `（中等）` [641.design-circular-deque 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)

### 题目描述
<p>设计实现双端队列。<br>
你的实现需要支持以下操作：</p>

<ul>
	<li>MyCircularDeque(k)：构造函数,双端队列的大小为k。</li>
	<li>insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。</li>
	<li>insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。</li>
	<li>deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。</li>
	<li>deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。</li>
	<li>getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。</li>
	<li>getRear()：获得双端队列的最后一个元素。&nbsp;如果双端队列为空，返回 -1。</li>
	<li>isEmpty()：检查双端队列是否为空。</li>
	<li>isFull()：检查双端队列是否满了。</li>
</ul>

<p><strong>示例：</strong></p>

<pre>MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
&nbsp;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有值的范围为 [1, 1000]</li>
	<li>操作次数的范围为 [1, 1000]</li>
	<li>请不要使用内置的双端队列库。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
		data = vector<int>(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
		if (isFull()) return false;
		ptrStart = (data.size() + ptrStart - 1) % data.size();
		data[ptrStart] = value;
		emptyFlag = false;
		return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[ptrEnd] = value;
		ptrEnd = (ptrEnd + 1) % data.size();
        emptyFlag = false;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
		if (isEmpty()) return false;
		ptrStart = (ptrStart + 1) % data.size();
		emptyFlag = (ptrStart == ptrEnd);
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
		ptrEnd = (data.size() + ptrEnd - 1) % data.size();
        emptyFlag = (ptrStart == ptrEnd);
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
		return data[ptrStart];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
		return data[(data.size() + ptrEnd - 1) % data.size()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
		return emptyFlag;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
		return !emptyFlag && ptrEnd == ptrStart;
    }

private:
	vector<int> data;
	int ptrStart = 0;
	int ptrEnd = 0;
	bool emptyFlag = true;
};
```




