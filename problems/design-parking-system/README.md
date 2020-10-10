# `（简单）` [1603.design-parking-system 设计停车系统](https://leetcode-cn.com/problems/design-parking-system/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-36/problems/design-parking-system/)

### 题目描述
<p>请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。</p>

<p>请你实现&nbsp;<code>ParkingSystem</code>&nbsp;类：</p>

<ul>
	<li><code>ParkingSystem(int big, int medium, int small)</code>&nbsp;初始化&nbsp;<code>ParkingSystem</code>&nbsp;类，三个参数分别对应每种停车位的数目。</li>
	<li><code>bool addCar(int carType)</code>&nbsp;检查是否有&nbsp;<code>carType</code>&nbsp;对应的停车位。&nbsp;<code>carType</code>&nbsp;有三种类型：大，中，小，分别用数字&nbsp;<code>1</code>，&nbsp;<code>2</code>&nbsp;和&nbsp;<code>3</code>&nbsp;表示。<strong>一辆车只能停在</strong>&nbsp;<strong>&nbsp;</strong><code>carType</code>&nbsp;对应尺寸的停车位中。如果没有空车位，请返回&nbsp;<code>false</code>&nbsp;，否则将该车停入车位并返回&nbsp;<code>true</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
<strong>输出：</strong>
[null, true, true, false, false]

<strong>解释：</strong>
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // 返回 true ，因为有 1 个空的大车位
parkingSystem.addCar(2); // 返回 true ，因为有 1 个空的中车位
parkingSystem.addCar(3); // 返回 false ，因为没有空的小车位
parkingSystem.addCar(1); // 返回 false ，因为没有空的大车位，唯一一个大车位已经被占据了
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= big, medium, small &lt;= 1000</code></li>
	<li><code>carType</code>&nbsp;取值为&nbsp;<code>1</code>，&nbsp;<code>2</code>&nbsp;或&nbsp;<code>3</code></li>
	<li>最多会调用&nbsp;<code>addCar</code>&nbsp;函数&nbsp;<code>1000</code>&nbsp;次</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        len = vector<int>(3, 0);
        len[0] = big;
        len[1] = medium;
        len[2] = small;
        
        cur = vector<int>(3, 0);
    }
    
    bool addCar(int carType) {
        if (cur[carType - 1] == len[carType - 1]) return false;
        cur[carType - 1]++;
        return true;
    }

private:
    vector<int> len;
    vector<int> cur;
};
```




