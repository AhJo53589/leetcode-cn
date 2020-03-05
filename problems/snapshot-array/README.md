# `（中等）` [1146.snapshot-array 快照数组](https://leetcode-cn.com/problems/snapshot-array/)

### 题目描述
<p>实现支持下列接口的「快照数组」-&nbsp;SnapshotArray：</p>

<ul>
	<li><code>SnapshotArray(int length)</code>&nbsp;- 初始化一个与指定长度相等的 类数组 的数据结构。<strong>初始时，每个元素都等于</strong><strong>&nbsp;0</strong>。</li>
	<li><code>void set(index, val)</code>&nbsp;- 会将指定索引&nbsp;<code>index</code>&nbsp;处的元素设置为&nbsp;<code>val</code>。</li>
	<li><code>int snap()</code>&nbsp;- 获取该数组的快照，并返回快照的编号&nbsp;<code>snap_id</code>（快照号是调用&nbsp;<code>snap()</code>&nbsp;的总次数减去&nbsp;<code>1</code>）。</li>
	<li><code>int get(index, snap_id)</code>&nbsp;- 根据指定的&nbsp;<code>snap_id</code>&nbsp;选择快照，并返回该快照指定索引 <code>index</code>&nbsp;的值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>["SnapshotArray","set","snap","set","get"]
     [[3],[0,5],[],[0,6],[0,0]]
<strong>输出：</strong>[null,null,0,null,5]
<strong>解释：
</strong>SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= length&nbsp;<= 50000</code></li>
	<li>题目最多进行<code>50000</code> 次<code>set</code>，<code>snap</code>，和&nbsp;<code>get</code>的调用 。</li>
	<li><code>0 <= index&nbsp;<&nbsp;length</code></li>
	<li><code>0 <=&nbsp;snap_id <&nbsp;</code>我们调用&nbsp;<code>snap()</code>&nbsp;的总次数</li>
	<li><code>0 <=&nbsp;val <= 10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class SnapshotArray {
public:
    SnapshotArray(int length) {

    }
    
    void set(int index, int val) {
		record[index][snap_times] = val;
    }
    
    int snap() {
		return snap_times++;
    }
    
    int get(int index, int snap_id) {
		return record[index].lower_bound(snap_id)->second;
    }

private:
	unordered_map<int, map<int, int, greater<int>>> record;
	int snap_times = 0;
};
```




