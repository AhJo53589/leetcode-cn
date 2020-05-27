# `（简单）` [933.number-of-recent-calls 最近的请求次数](https://leetcode-cn.com/problems/number-of-recent-calls/)

### 题目描述
<p>写一个&nbsp;<code>RecentCounter</code>&nbsp;类来计算最近的请求。</p>

<p>它只有一个方法：<code>ping(int t)</code>，其中&nbsp;<code>t</code>&nbsp;代表以毫秒为单位的某个时间。</p>

<p>返回从 3000 毫秒前到现在的&nbsp;<code>ping</code>&nbsp;数。</p>

<p>任何处于&nbsp;<code>[t - 3000, t]</code>&nbsp;时间范围之内的 <code>ping</code>&nbsp;都将会被计算在内，包括当前（指 <code>t</code>&nbsp;时刻）的 <code>ping</code>。</p>

<p>保证每次对 <code>ping</code> 的调用都使用比之前更大的 <code>t</code> 值。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
<strong>输出：</strong>[null,1,2,3,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>每个测试用例最多调用&nbsp;<code>10000</code>&nbsp;次&nbsp;<code>ping</code>。</li>
	<li>每个测试用例会使用严格递增的 <code>t</code> 值来调用&nbsp;<code>ping</code>。</li>
	<li>每次调用 <code>ping</code>&nbsp;都有&nbsp;<code>1 <= t <= 10^9</code>。</li>
</ol>

<p>&nbsp;</p>


---
### 思路
```
```



### 答题
``` C++
class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        record.push(t);
        while (!record.empty() && record.front() + 3000 < t) {
            record.pop();
        }
        return record.size();
    }

private:
    queue<int> record;
};
```




