# `（简单）` [705.design-hashset 设计哈希集合](https://leetcode-cn.com/problems/design-hashset/)

### 题目描述
<p>不使用任何内建的哈希表库设计一个哈希集合</p>

<p>具体地说，你的设计应该包含以下的功能</p>

<ul>
	<li><code>add(value)</code>：向哈希集合中插入一个值。</li>
	<li><code>contains(value)</code> ：返回哈希集合中是否存在这个值。</li>
	<li><code>remove(value)</code>：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。</li>
</ul>

<p><br>
<strong>示例:</strong></p>

<pre>MyHashSet hashSet = new MyHashSet();
hashSet.add(1); &nbsp; &nbsp; &nbsp; &nbsp; 
hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; 
hashSet.contains(1); &nbsp;&nbsp;&nbsp;// 返回 true
hashSet.contains(3); &nbsp;&nbsp;&nbsp;// 返回 false (未找到)
hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
hashSet.contains(2); &nbsp;&nbsp;&nbsp;// 返回 true
hashSet.remove(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
hashSet.contains(2); &nbsp;&nbsp;&nbsp;// 返回  false (已经被删除)
</pre>

<p><br>
<strong>注意：</strong></p>

<ul>
	<li>所有的值都在&nbsp;<code>[1, 1000000]</code>的范围内。</li>
	<li>操作的总数目在<code>[1, 10000]</code>范围内。</li>
	<li>不要使用内建的哈希集合库。</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
class MyHashSet {
    vector<bool> set;
public:
    /** Initialize your data structure here. */
    //map<int,int> set;
    MyHashSet() {
        set = vector<bool>(1000001,false);
    }

    void add(int key) {
        set[key]=true;
    }

    void remove(int key) {
        set[key]=false;
    }

    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

