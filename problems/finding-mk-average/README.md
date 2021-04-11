# `（困难）` [5729.finding-mk-average 求出 MK 平均值](https://leetcode-cn.com/problems/finding-mk-average/)

[contest](https://leetcode-cn.com/contest/weekly-contest-236/problems/finding-mk-average/)

### 题目描述
<div class="notranslate"><p>给你两个整数&nbsp;<code>m</code>&nbsp;和&nbsp;<code>k</code>&nbsp;，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 <b>MK 平均值</b>&nbsp;。</p>

<p><strong>MK 平均值</strong>&nbsp;按照如下步骤计算：</p>

<ol>
	<li>如果数据流中的整数少于 <code>m</code>&nbsp;个，<strong>MK 平均值</strong>&nbsp;为 <code>-1</code>&nbsp;，否则将数据流中最后 <code>m</code>&nbsp;个元素拷贝到一个独立的容器中。</li>
	<li>从这个容器中删除最小的 <code>k</code>&nbsp;个数和最大的 <code>k</code>&nbsp;个数。</li>
	<li>计算剩余元素的平均值，并 <strong>向下取整到最近的整数</strong>&nbsp;。</li>
</ol>

<p>请你实现&nbsp;<code>MKAverage</code>&nbsp;类：</p>

<ul>
	<li><code>MKAverage(int m, int k)</code>&nbsp;用一个空的数据流和两个整数 <code>m</code>&nbsp;和 <code>k</code>&nbsp;初始化&nbsp;<strong>MKAverage</strong>&nbsp;对象。</li>
	<li><code>void addElement(int num)</code>&nbsp;往数据流中插入一个新的元素&nbsp;<code>num</code>&nbsp;。</li>
	<li><code>int calculateMKAverage()</code>&nbsp;对当前的数据流计算并返回 <strong>MK 平均数</strong>&nbsp;，结果需 <strong>向下取整到最近的整数</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
<strong>输出：</strong>
[null, null, null, -1, null, 3, null, null, null, 5]

<strong>解释：</strong>
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 <code>[3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // </code>删除最小以及最大的 1 个元素后，容器为 <code>[5]<code>
                          // </code>[5] 的平均值等于 5/1 = 5 ，故返回 5<code>
</code></code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k*2 &lt; m</code></li>
	<li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li><code>addElement</code> 与&nbsp;<code>calculateMKAverage</code>&nbsp;总操作次数不超过 <code>10<sup>5</sup></code> 次。</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class MKAverage {
public:
    MKAverage(int _m, int _k) : m(_m), k(_k) {

    }

    void addElement(int num) {
        que.push(num);

        if (!isReady) {
            Init(num);
            return;
        }
        
        add(num);
        remove(que.front());
        que.pop();
    }

    int calculateMKAverage() {
        if (isReady) {
            int ans = sum / (m - 2 * k);
        }
        return (!isReady) ? -1 : sum / (m - 2 * k);
    }

private:
    void Init(int num) {
        data.push_back(num);
        if (data.size() == m) {
            sort(data.begin(), data.end());
            for (int i = 0; i < data.size(); i++) {
                if (i < k) {
                    set_low.insert(data[i]);
                }
                else if (i < m - k) {
                    set_mid.insert(data[i]);
                    sum += data[i];
                }
                else {
                    set_high.insert(data[i]);
                }
            }
            isReady = true;
        }
    }

    void add(int num) {
        if (*set_low.rbegin() > num) {
            int e = *set_low.rbegin();
            moveNum(set_low, e, set_mid);
            sum += e;

            set_low.insert(num);
        }
        else if (*set_high.begin() < num) {
            int e = *set_high.begin();
            moveNum(set_high, e, set_mid);
            sum += e;

            set_high.insert(num);
        }
        else {
            set_mid.insert(num);
            sum += num;
        }
    }

    void remove(int num) {
        if (set_mid.find(num) != set_mid.end()) {
            set_mid.erase(set_mid.find(num));
            sum -= num;
        }
        else if (set_low.find(num) != set_low.end()) {
            set_low.erase(set_low.find(num));
            int e = *set_mid.begin();
            moveNum(set_mid, e, set_low);
            sum -= e;
        }
        else {
            set_high.erase(set_high.find(num));
            int e = *set_mid.rbegin();
            moveNum(set_mid, e, set_high);
            sum -= e;
        }
    }

    void moveNum(multiset<int>& a_set, int a, multiset<int>& b_set) {
        b_set.insert(a);
        a_set.erase(a_set.find(a));
    }

private:
    int m;
    int k;

    bool isReady = false;

    queue<int> que;
    vector<int> data;
    multiset<int> set_low;
    multiset<int> set_mid;
    multiset<int> set_high;
    long long sum = 0;
};
```




