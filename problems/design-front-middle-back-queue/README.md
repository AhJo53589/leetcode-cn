# `（中等）` [5560.design-front-middle-back-queue 设计前中后队列](https://leetcode-cn.com/problems/design-front-middle-back-queue/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-40/problems/design-front-middle-back-queue/)

### 题目描述
<div class="question-content default-content">
              <p>请你设计一个队列，支持在前，中，后三个位置的 <code>push</code>&nbsp;和 <code>pop</code>&nbsp;操作。</p>

<p>请你完成&nbsp;<code>FrontMiddleBack</code>&nbsp;类：</p>

<ul>
	<li><code>FrontMiddleBack()</code>&nbsp;初始化队列。</li>
	<li><code>void pushFront(int val)</code> 将&nbsp;<code>val</code>&nbsp;添加到队列的 <strong>最前面</strong>&nbsp;。</li>
	<li><code>void pushMiddle(int val)</code> 将&nbsp;<code>val</code>&nbsp;添加到队列的 <strong>正中间</strong>&nbsp;。</li>
	<li><code>void pushBack(int val)</code>&nbsp;将&nbsp;<code>val</code>&nbsp;添加到队里的 <strong>最后面</strong>&nbsp;。</li>
	<li><code>int popFront()</code>&nbsp;将 <strong>最前面</strong> 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code>&nbsp;。</li>
	<li><code>int popMiddle()</code> 将 <b>正中间</b>&nbsp;的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code>&nbsp;。</li>
	<li><code>int popBack()</code> 将 <strong>最后面</strong> 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code>&nbsp;。</li>
</ul>

<p>请注意当有&nbsp;<strong>两个</strong>&nbsp;中间位置的时候，选择靠前面的位置进行操作。比方说：</p>

<ul>
	<li>将 <code>6</code>&nbsp;添加到&nbsp;<code>[1, 2, 3, 4, 5]</code>&nbsp;的中间位置，结果数组为&nbsp;<code>[1, 2, <strong>6</strong>, 3, 4, 5]</code>&nbsp;。</li>
	<li>从&nbsp;<code>[1, 2, <strong>3</strong>, 4, 5, 6]</code>&nbsp;的中间位置弹出元素，返回&nbsp;<code>3</code>&nbsp;，数组变为&nbsp;<code>[1, 2, 4, 5, 6]</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
<strong>输出：</strong>
[null, null, null, null, null, 1, 3, 4, 2, -1]

<strong>解释：</strong>
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [<strong>1</strong>]
q.pushBack(2);    // [1, <strong>2</strong>]
q.pushMiddle(3);  // [1, <strong>3</strong>, 2]
q.pushMiddle(4);  // [1, <strong>4</strong>, 3, 2]
q.popFront();     // 返回 1 -&gt; [4, 3, 2]
q.popMiddle();    // 返回 3 -&gt; [4, 2]
q.popMiddle();    // 返回 4 -&gt; [2]
q.popBack();      // 返回 2 -&gt; []
q.popFront();     // 返回 -1 -&gt; [] （队列为空）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li>最多调用&nbsp;<code>1000</code>&nbsp;次&nbsp;<code>pushFront</code>，&nbsp;<code>pushMiddle</code>，&nbsp;<code>pushBack</code>，&nbsp;<code>popFront</code>，&nbsp;<code>popMiddle</code>&nbsp;和&nbsp;<code>popBack</code> 。</li>
</ul>

            </div>

---
### 思路
```
```



### 答题
``` C++
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        head.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (head.size() < tail.size()) {
            head.push_back(val);
        }
        else {
            tail.push_front(val);
        }
    }

    void pushBack(int val) {
        tail.push_back(val);
        balance();
    }

    int popFront() {
        if (tail.empty()) return -1;
        if (head.empty()) {
            int ret = tail.front();
            tail.pop_front();
            return ret;
        }

        int ret = head.front();
        head.pop_front();
        balance();
        return ret;
    }

    int popMiddle() {
        if (tail.empty()) return -1;

        if (tail.size() > head.size()) {
            int ret = tail.front();
            tail.pop_front();
            return ret;
        }

        if (head.empty()) return -1;

        int ret = head.back();
        head.pop_back();
        return ret;
    }

    int popBack() {
        if (tail.empty()) return -1;

        int ret = tail.back();
        tail.pop_back();
        balance();
        return ret;
    }

    void balance() {
        if (head.size() > tail.size()) {
            tail.push_front(head.back());
            head.pop_back();
        }
        else if (tail.size() - head.size() == 2) {
            head.push_back(tail.front());
            tail.pop_front();
        }
    }

private:
    deque<int> head;
    deque<int> tail;
};
```




