# leetcode-cn




---
## 20190618
* 752.OpenLock 打开转盘锁
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/752.OpenLock/Description.jpg)

因为是从队列的习题集里做到的题，很自然就想到用队列的特性来解决。  
大概解决思路很快就想到了。  
将当前数字的可以变换的所有（8种）情况全部判断加入队列。  
下一步的时候，再依次将刚加进去的情况的下一步情况再加入队列。  
其间通过黑名单方式排除deadends和已经计算过的情况。  
通过这种方式能够计算最早达到目标的步数。  

另外实现字符串“0000”变化的方法getNextMoveList()感觉也比较有意思。  

``` C++
vector<string> getNextMoveList(string strCurrent)
{
	vector<string> vStr;
	for (int i = 0; i < 4; i++)
	{
		string strTemp = strCurrent;
		int iCurrent = strCurrent[i] - '0';

		strTemp[i] = ((iCurrent + 1) % 10) + '0';
		vStr.push_back(strTemp);
		strTemp[i] = ((iCurrent + 10 - 1) % 10) + '0';
		vStr.push_back(strTemp);
	}
	return vStr;
}

int openLock(vector<string>& deadends, string target)
{
	map<string, bool> mapDeadends;
	for (string s : deadends)
	{
		mapDeadends[s] = true;
	}

	string strInit("0000");
	string strEnd("----");
	if (mapDeadends[strInit]) return -1;

	queue<string> qLockNum;
	qLockNum.push(strInit);
	mapDeadends[strInit] = true;
	qLockNum.push(strEnd);

	int num = 1;
	while (!qLockNum.empty())
	{
		string strCurrent = qLockNum.front();
		qLockNum.pop();

		if (strCurrent == strEnd)
		{
			if (qLockNum.empty() || qLockNum.front() == strEnd) break;

			num++;
			qLockNum.push(strEnd);
			continue;
		}

		vector<string> strNextMoveList = getNextMoveList(strCurrent);
		for (string sNext : strNextMoveList)
		{
			if (!mapDeadends[sNext])
			{
				if (sNext == target) return num;
				mapDeadends[sNext] = true;
				qLockNum.push(sNext);
			}
		}
	}
	return -1;
}
``` 





---
## 20190617
* 200.NumIslands 岛屿数量
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/200.NumIslands/Description.jpg)

遍历，当发现这个格子时个新岛的时候，  
把这个岛所有相连的都标记成‘2’。  

``` C++
void checkIsland(vector<vector<char>>& grid, pair<int,int> posStart)
{
	queue<pair<int, int>> q;
	q.push(posStart);

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
		{
			if (grid[p.first][p.second] == '1')
			{
				grid[p.first][p.second] = '2';

				q.push(make_pair(p.first, p.second - 1));
				q.push(make_pair(p.first, p.second + 1));
				q.push(make_pair(p.first - 1, p.second));
				q.push(make_pair(p.first + 1, p.second));
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) 
{
	int iLen_i = grid.size();
	if (iLen_i == 0) return 0;
	int iLen_j = grid[0].size();
	if (iLen_j == 0) return 0;

	int num = 0;
	for (int i = 0; i < iLen_i; i++)
	{
		for (int j = 0; j < iLen_j; j++)
		{
			if (grid[i][j] == '1')
			{
				checkIsland(grid, make_pair(i, j));
				num++;
			}
		}
	}

	return num;
}
``` 


* 622.MyCircularQueue 设计循环队列
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/622.MyCircularQueue/Description.jpg)


使用数组即可，用head和tail两个变量来记录头尾的下标。  
再记录一下size，其他都可以通过计算得到。  
使用%操作，让数组循环起来。  
注意判断isFull的时候，也要用%。  
``` C++
class MyCircularQueue
{
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
	{
		m_size = k > 0 ? k : 0;
		m_pData = new int[k];
		m_head = -1;
		m_tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)
	{
		if (isFull()) return false;

		if (isEmpty())
		{
			m_head = 0;
			m_tail = 0;
			m_pData[m_tail] = value;
		}
		else
		{
			m_tail = (m_tail + 1) % m_size;
			m_pData[m_tail] = value;
		}
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()
	{
		if (isEmpty()) return false;

		if (m_tail == m_head)
		{
			m_head = -1;
			m_tail = -1;
		}
		else
		{
			m_head = (m_head + 1) % m_size;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front()
	{
		if (isEmpty()) return -1;
		return m_pData[m_head];
	}

	/** Get the last item from the queue. */
	int Rear()
	{
		if (isEmpty()) return -1;
		return m_pData[m_tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty()
	{
		return m_head == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull()
	{
		return (m_size == 0 || ((m_tail + 1) % m_size) == m_head);
	}

private:
	int *m_pData;
	int m_head;
	int m_tail;
	int m_size;
};
``` 




---
## 20190603
* 13.RomanToInt 罗马数字转整数
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/13.RomanToInt/Description.jpg)


``` C++
int romanToInt(string s)
{
	int result = 0;
	map<char, int> luomab;
	luomab.insert(map<char, int>::value_type('I', 1));
	luomab.insert(map<char, int>::value_type('V', 5));
	luomab.insert(map<char, int>::value_type('X', 10));
	luomab.insert(map<char, int>::value_type('L', 50));
	luomab.insert(map<char, int>::value_type('C', 100));
	luomab.insert(map<char, int>::value_type('D', 500));
	luomab.insert(map<char, int>::value_type('M', 1000));

	for (int i = 0; i < s.length(); i++)
	{
		if (luomab[s[i]] >= luomab[s[i + 1]])
		{
			result += luomab[s[i]];
		}
		else
		{
			result += (luomab[s[i + 1]] - luomab[s[i]]);
			i++;
		}
	}
	return result;
}
``` 


* 326.IsPowerOfThree 3的幂
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/326.IsPowerOfThree/Description.jpg)


``` C++
bool isPowerOfThree(int n)
{
	return n > 0 && 1162261467 % n == 0;
}
``` 





---
## 20190528
* 204.CountPrimes 计数质数
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/204.CountPrimes/Description.jpg)


``` C++
int countPrimes(int n) 
{
	if (n < 3) return 0;

	vector<bool> primeFlag(n);
	primeFlag[2] = true;
	for (long long i = 3; i < n; i += 2)
	{
		primeFlag[i] = true; // 所有奇数标为true，偶数为false
	}
	for (long long i = 3; i < n; i++)
	{
		if (primeFlag[i])
		{
			int cnt = 2;
			while (cnt * i < n)
			{
				// 把i的倍数标为false（因为它们是合数）
				primeFlag[cnt * i] = false;
				cnt++;
			}
		}
	}

	int cnt = 1;
	for (long long i = 3; i < n; i += 2)
	{
		if (primeFlag[i])
		{
			//cout << cnt << ' ' << i << endl;
			cnt++;
		}
	}
	return cnt;
}
``` 


* 412.FizzBuzz Fizz Buzz
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/412.FizzBuzz/Description.jpg)


``` C++
vector<string> fizzBuzz(int n)
{
	vector<string> str;
	for (int i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			str.push_back("FizzBuzz");
		}
		else if (i % 5 == 0)
		{
			str.push_back("Buzz");
		}
		else if (i % 3 == 0)
		{
			str.push_back("Fizz");
		}
		else
		{
			str.push_back(to_string(i));
		}
	}
	return str;
}
``` 





---
## 20190527
* 155.MinStack 最小栈
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/155.MinStack/Description.jpg)

代码写很多，又不好调试。  
考的点又不难。  

想要实现快速查找getMin,  
就push的时候存一下。  

``` C++
void push(int x) 
{
	if (cur == NULL) 
	{
		cur = new Node(x);
		head->next = cur;
		cur->pre = head;
		cur->curMin = x;
	}
	else 
	{
		cur->next = new Node(x);
		cur->next->pre = cur;
		cur = cur->next;
		cur->curMin = min(cur->pre->curMin, x);
	}
}

int getMin()
{
	return cur->curMin;
}
``` 


* 384.Shuffle 打乱数组
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/384.Shuffle/Description.jpg)


``` C++
class Solution 
{
public:
	Solution(vector<int>& nums) : m_nums(nums)
	{
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return m_nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
	{
		vector<int> ans = m_nums;
		for (int i = 1; i < ans.size(); i++)
		{
			swap(ans[rand() % (i + 1)], ans[i]);
		}
		return ans;
	}

private:
	vector<int> m_nums;
};
``` 




---
## 20190526
* 198.Rob 打家劫舍
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/198.Rob/Description.jpg)

这道题上周五下班前没有做完，  
周日晚上想想这周结束之前还是应该把它完成。  

做完之后提交可能有bug，显示我战胜了100%的用户。  
很开心！  
算法也是纯自己研究的，  
就第一次写了个题解（已被选为精选题解），分享一下。  


根据这道题的条件特点：  
__如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警__  
（即相邻的数字不能同时作为最终求和的有效数字）。  

这个条件如果精简掉其他内容，很容易让人联想到奇偶数。这个解法就是从这点出发。  
  

设置两个变量，sumOdd和sumEven分别对数组的奇数和偶数元素求和。  
最后比较这两个和谁更大，谁就是最优解。  
至少在下面这个例子里，这么做是成功的了。  

|  Index  | [0] | [1] | [2] | [3] |
|---------|---|---|---|---|
| nums    | 1 | 2 | 3 | 4 |
| sumEven | 1 | 1 | 4 | 4 |
| sumOdd  | 0 | 2 | 2 | 6 |

接下来要解决的就是最优解不是纯奇数和或者偶数和的情况。  
这种情况下，最优解可能前半段出现在这边，后半段出现在另一边。  
那么只要找到一个时机，当这一段的最优解没有另一边好时，就复制对面的最优解过来。  

举个例子：  

|  Index  | [0] | [1] | [2] | [3] | [4] |
|---------|---|---|---|---|-----|
| nums    | 1 | 3 | 1 | 3 | 100 |
| sumEven | 1 | 1 | 2 | 2 => 3 |     |
| sumOdd  | 0 | 3 | 3 |   |     |

当偶数和（奇偶指的数组下标）加到第二个 1 之后，发现还不如奇数和一个 3 大，就应该将对面的3复制过来替换掉自己的 2。  

|  Index  |  [0] | [1] | [2] | [3] | [4] |
|---------|---|---|---|---|-----|
| nums    | 1 | 3 | 1 | 3 | 100 |
| sumEven | 1 | 1 | 2 | 3 | 103 |
| sumOdd  | 0 | 3 | 3 | 6 | 6   |

继续计算后得到最优解。  

完成。  



``` C++
int rob(vector<int>& nums) 
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumEven += nums[i];
			sumEven = max(sumOdd, sumEven);
		}
		else
		{
			sumOdd += nums[i];
			sumOdd = max(sumOdd, sumEven);
		}
	}
	return max(sumOdd, sumEven);
}
``` 




然后，学习了别人的动态规划方法。  
就感觉和我的方法很微妙的不同。
  
``` C++
int rob(vector<int>& nums) 
{
	// 动态规划
	if (nums.size() == 0) return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);
	nums[2] = nums[0] + nums[2];
	if (nums.size() == 3)
		return max(nums[1], nums[2]);
	for (int i = 3; i < nums.size(); i++)
	{
		nums[i] = max(nums[i - 2] + nums[i], nums[i] + nums[i - 3]);
	}
	return max(nums[nums.size() - 1], nums[nums.size() - 2]);
}
``` 


---
## 20190524
* 53.MaxSubArray 最大子序和
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/53.MaxSubArray/Description.jpg)

就是昨天终于认定这个题要用分治法了，  
照着书上伪代码写完，发现  
别人的代码好简单。  

``` C++
int maxSubArrayCross(vector<int> &nums, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= 0; i--)
	{
		sum += nums[i];
		left_sum = max(left_sum, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += nums[i];
		right_sum = max(right_sum, sum);
	}
	return left_sum + right_sum;
}

int maxSubArraySide(vector<int>& nums, int low, int high)
{
	if (low == high) return nums[low];

	int _Mid = low + (high - low) / 2;
	int left_sum = maxSubArraySide(nums, low, _Mid);
	int right_sum = maxSubArraySide(nums, _Mid + 1, high);
	int cross_sum = maxSubArrayCross(nums, low, _Mid, high);

	return max(left_sum, max(right_sum, cross_sum));
}

int maxSubArray(vector<int>& nums)
{
	// 分治法
	int low = 0;
	int high = nums.size() - 1;
	return maxSubArraySide(nums, low, high);
}
``` 


``` C++
int maxSubArray(vector<int>& nums)
{
	//法1：复杂度为O(n)的解法
	int res = INT_MIN, sum = 0;
	for (int n : nums) {
		sum = max(n, sum + n);
		res = max(sum, res);
	}
	return res;
}
``` 




---
## 20190523
* 121.MaxProfit 买卖股票的最佳时机
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/121.MaxProfit/Description.jpg)

终于看会了算法导论上是怎么做的，  
但是觉得太麻烦，   
还是抄了一个简单的方法。  
结果下一道题还是要用那个方法。  

``` C++
int maxProfit(vector<int>& prices)
{
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		maxProfit = max(maxProfit, prices[i] - minPrice);
	}
	return maxProfit;
}
``` 


---
## 20190522
* 70.ClimbStairs 爬楼梯
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/70.ClimbStairs/Description.jpg)

做到动态规划了，又跑去磕算法导论。  
虽然没完全看懂，但总算没白看。  
根据自己的理解做出来这道入门题了。  

``` C++
int climbStairs(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int s1 = 1;
	int s2 = 2;
	int ret = 0;
	for (int i = 3; i <= n; i++)
	{
		ret = s1 + s2;
		s1 = s2;
		s2 = ret;
	}
	return ret;
}
``` 
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/70.ClimbStairs/Solution.jpg)




---
## 20190516
* 102.LevelOrder 二叉树的层次遍历
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/102.LevelOrder/Description.jpg)


``` C++
vector<vector<int>> levelOrder(TreeNode* root) // 4ms
{
	vector<vector<int> >res;
	if (root == NULL)
		return res;
	queue<TreeNode*> que;
	TreeNode*p;
	que.push(root);
	int level = 0;
	while (!que.empty()) 
	{
		res.push_back(vector<int>());
		int len = que.size();
		while (len--)
		{
			p = que.front();
			que.pop();
			res[level].push_back(p->val);
			if (p->left) que.push(p->left);
			if (p->right) que.push(p->right);
		}
		level++;
	}
	return res;
}
``` 

* 108.SortedArrayToBST 将有序数组转换为二叉搜索树
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/108.SortedArrayToBST/Description.jpg)

就很迷，我这20ms的代码和8ms的代码基本一样。  

这道题基本上就是二分查找法的应用了。  

``` C++
TreeNode* sortedArrayToBST(vector<int>& nums, size_t _First, size_t _Last) 
{
	if (_Last <= _First) return NULL;

	size_t _Mid = _First + (_Last - _First) / 2;
	TreeNode *pNode = new TreeNode(nums[_Mid]);
	TreeNode *pLeft = sortedArrayToBST(nums, _First, _Mid);
	TreeNode *pRight = sortedArrayToBST(nums, _Mid + 1, _Last);
	pNode->left = pLeft;
	pNode->right = pRight;
	return pNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	size_t _First = 0;
	size_t _Last = nums.size();
	if (_Last == 0) return NULL;

	return sortedArrayToBST(nums, _First, _Last);
}
``` 


---
## 20190515
* 101.IsSymmetric 对称二叉树
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/101.IsSymmetric/Description.jpg)

终于之前的凑活用的初始化initTree遇到了bug。  
无法区分0和null，  
重新写了字符串方法来初始化。  

这道题本身，用之前的queue方法可以解决。  
看了题解，镜像的方式也不错，代码看着真简洁。  
分享别人mirror的方法。


``` C++
// mirror
bool mirror(TreeNode *l, TreeNode *r)
{
	if (!l && !r) return true;
	if (!l && r) return false;
	if (l && !r) return false;
	if (l->val != r->val) return false;
	return mirror(l->left, r->right) && mirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root)  // 4ms
{
	if (!root) return true;
	return mirror(root->left, root->right);
}
// end
``` 


---
## 20190514
* 98.IsValidBST 验证二叉搜索树
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/98.IsValidBST/Description.jpg)

额，这道题知道要用中序遍历。  
然后状态不好各种边界什么的  
提交错了8次！  
用别人的用例来弥补自己考虑不周了。  
 
12ms，98%，总算安慰了一下。

``` C++
bool Inorder(TreeNode *root, int &val, bool &bFirstVal)
{
	if (root == NULL) return true;

	if (!Inorder(root->left, val, bFirstVal)) return false;

	if (!bFirstVal)
	{
		if (!(val < root->val)) return false;
	}
	else
	{
		bFirstVal = false;
	}
	val = root->val;

	if (!Inorder(root->right, val, bFirstVal)) return false;
	return true;
}

bool isValidBST(TreeNode* root)	// 12 ms
{
	int val = 0;
	bool bFirstVal = true;
	return Inorder(root, val, bFirstVal);
}

``` 





---
## 20190513
* 104.MaxDepth 二叉树的最大深度
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/104.MaxDepth/Description.jpg)

额，这道题写初始化函数和输出函数写了1个多小时，  
还因为把queue用错了vector调试了一会儿，  
再现了vector因为push_back，  
扩大内存而导致iter失效的问题。  

然后maxDepth写了1分钟，一次过。

``` C++
int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
``` 



---
## 20190511
* 28.StrStr 实现strStr() 
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/28.StrStr/Description.jpg)


``` C++
int strStr(string haystack, string needle)
{
	if (needle == "") return 0;

	for (int i = 0; i < haystack.size(); i++)
	{
		for (int j = 0; j < needle.size(); j++)
		{
			if (i + j == haystack.size()) return -1;
			if (haystack[i + j] != needle[j]) break;
			if (j == needle.size() - 1) return i;
		}
	}
	return -1;
}
``` 

* 38.CountAndSay 报数
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/38.CountAndSay/Description.jpg)

纠结了半天的居然是怎么int转string。

``` C++
string countAndSay(int n) 
{
	if (n <= 0 || n > 30) return "";

	if (n == 1) return "1";

	string str = countAndSay(n - 1);
	string strCount;
	size_t i = 0;
	while (i < str.size())
	{
		size_t j = 1;
		while (str[i] == str[i + j])
		{
			j++;
		}
		strCount += to_string(j);
		strCount += str[i];
		i += j;
	}
	return strCount;
}
``` 


---
## 20190510
* 8.MyAtoi 字符串转换整数 (atoi)  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/8.MyAtoi/Description.jpg)


还是分享别人的吧

``` C++
int myAtoi(string str) 
{
	int i = 0;
	int res = 0;
	int rev = 1;
	int num = 0;
	while (i < str.length() && str.at(i) == ' ')    // 吃掉空格
		i++;
	if (i < str.length() && str.at(i) == '-')       // 判断正负数
	{
		rev = -1;
		i++;
	}
	else if (i < str.length() && str.at(i) == '+')
		i++;
	while (i < str.length() && isdigit(str.at(i)))
	{
		num = str.at(i++) - '0';
		res = (long)res * 10 + num;                   // num是个位
		if (res % 10 != num)                    // 判断是否溢出的方式
			return rev > 0 ? INT_MAX : INT_MIN;
	}

	return rev * res;
}
``` 



---
## 20190506
* 125.IsPalindrome 验证回文串  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/125.IsPalindrome/Description.jpg)


``` C++
bool isPalindrome(string s)
{
	if (s.size() == 0) return true;

	string t = getCleanString(s);
	int len = t.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (t[i] != t[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
``` 



* 242.IsAnagram 有效的字母异位词  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/242.IsAnagram/Description.jpg)


``` C++
bool isAnagram(string s, string t)
{
	if (s.size() != t.size()) return false;

	vector<int> charCount_s(26, 0);
	vector<int> charCount_t(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount_s[s[i] - 'a'] ++;
		charCount_t[t[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (charCount_s[i] != charCount_t[i])
		{
			return false;
		}
	}
	return true;
}
``` 





---
## 20190505
* 387.FirstUniqChar 字符串中的第一个唯一字符  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/387.FirstUniqChar/Description.jpg)


``` C++
int firstUniqChar(string s)
{
	vector<int> charCount(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount[s[i] - 'a'] ++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (charCount[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1; 
}
``` 



---
## 20190503
* 7.Reverse 整数反转  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/7.Reverse/Description.jpg)


``` C++
int reverse(int x)
{
	int result = 0;
	while (x != 0)
	{
		if (result > INT_MAX / 10 || result < INT_MIN / 10)
		{
			return 0;
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}
``` 


---
## 20190429
* 141.HasCycle 环形链表  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/141.HasCycle/Description.jpg)


``` C++
bool hasCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL) return false;
		slow = slow->next;
		fast = fast->next;

		if (slow == fast) return true;
	}
	return false;
}
``` 
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/141.HasCycle/Solution.jpg)


* 278.FirstBadVersion 第一个错误的版本  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/278.FirstBadVersion/Description.jpg)

使用二分查找。  

``` C++
int firstBadVersion(int n) 
{
	int low = 1; 
	int high = n;
	
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (isBadVersion(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}
``` 


---
## 20190428
* 234.IsPalindrome 回文链表  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/234.IsPalindrome/Description.jpg)

这道题其实是需要考虑链表单双情况的，  
但是可以看到快指针为空时，  
偶数情况slow指针索引为n/2，奇数情况slow指针索引为n/2+1。  
所以逆序的后半段链表，可以直接和head指针开始对比。  

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
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/234.IsPalindrome/Solution.jpg)



---
## 20190426
* 19.RemoveNthFromEnd 删除链表的倒数第N个节点  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/19.RemoveNthFromEnd/Description.jpg)

这道题按照进阶要求，一次遍历出结果。  
事后看了下评论，大家管这种叫快慢指针。  
只是我比较纠结大家为啥都不调用delete()

``` C++
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL || n == 0) return NULL;
	if (head->next == NULL) return NULL;

	ListNode *pTemp = head;
	ListNode *pDeletePrev = head;
	ListNode *pDelete = NULL;
	while (n > 0)
	{
		pTemp = pTemp->next;
		--n;
	}
	if (pTemp == NULL)
	{
		pDelete = head;
		head = head->next;
		delete(pDelete);
		return head;
	}
	while (pTemp->next != NULL)
	{
		pTemp = pTemp->next;
		pDeletePrev = pDeletePrev->next;
	}
	pDelete = pDeletePrev->next;
	pDeletePrev->next = pDelete->next;
	delete(pDelete);
	return head;
}
``` 

* 21.MergeTwoLists 合并两个有序链表  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/21.MergeTwoLists/Description.jpg)


``` C++
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode *pHead = NULL;
	ListNode *pNode = NULL;

	if (l1->val < l2->val)
	{
		pHead = l1;
		l1 = l1->next;
	}
	else
	{
		pHead = l2;
		l2 = l2->next;
	}
	pNode = pHead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			pNode->next = l1;
			l1 = l1->next;
		}
		else
		{
			pNode->next = l2;
			l2 = l2->next;
		}
		pNode = pNode->next;
	}
	pNode->next = l1 ? l1 : l2;
	// 	if (l1 != NULL)
	// 	{
	// 		pNode->next = l1;
	// 	}
	// 	if (l2 != NULL)
	// 	{
	// 		pNode->next = l2;
	// 	}
	return pHead;
}
``` 

* 237.DeleteNode 删除链表中的节点  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/237.DeleteNode/Description.jpg)

这道题比较迷，一开始没看懂题。  
还说为啥不给head。  
后来才知道传进来的node就是要删的node。  
反而很简单。

``` C++
void deleteNode(ListNode *node)
{
	ListNode *pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete(pNext);
	pNext = NULL;
}
``` 

* 344.ReverseString 反转字符串  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/344.ReverseString/Description.jpg)

这道题真的简单，我用手机写的。  
手机写代码感觉很神奇。

``` C++
void reverseString(vector<char>& s)
 {
	int iLen = s.size();
	for (int i = 0; i < iLen/2; i++)
	{
		swap(s[i], s[iLen-i-1]);
	}
}
``` 


---
## 20190425
* 1.TwoSum 两数之和  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/1.TwoSum/Description.jpg)


``` C++
vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> sum;
	vector<int> rst;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum.find(target - nums[i]) != sum.end())
		{
			rst.push_back(sum[target - nums[i]]);
			rst.push_back(i);
			break;
		}
		else
		{
			sum[nums[i]] = i;
		}
	}
	return rst;
}
``` 

* 36.IsValidSudoku 有效的数独  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/36.IsValidSudoku/Description.jpg)


``` C++
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(board[i])) return false;
	}

	vector<char> grid[9];
	for (int i = 0; i < 9; i++)
	{
		vector<char> line;
		for (int j = 0; j < 9; j++)
		{
			line.push_back(board[j][i]);

			// 把81宫格合并成9宫格
			int k = i / 3 + j / 3 * 3;
			grid[k].push_back(board[i][j]);
		}
		if (checkDuplicate(line)) return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(grid[i])) return false;
	}

	return true;
}
``` 

* 48.Rotate 旋转图像  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/48.Rotate/Description.jpg)


这道题一看就感觉没思路，学习了别人写的，这个方法比较好理解。  
先沿着对角线翻转一次，  
再按中线翻转一次。  

想了想还是应该调用旋转公式的，  
回头补习一下。  

``` C++
//firstly exchange elements by diagonal, then exchange elements by mid-line.
void rotate(vector<vector<int>>& matrix)
{
	int temp;
	int end = matrix.size() - 1;
	float mid_line = end / 2;
	for (int i = 0; i <= end; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (int i = 0; i <= end; i++)
	{
		for (int j = 0; j <= mid_line; j++)
		{
			swap(matrix[i][j], matrix[i][end - j]);
		}
	}
}
``` 


* 66.PlusOne 加一  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/66.PlusOne/Description.jpg)

``` C++
vector<int> plusOne(vector<int>& digits)
{
	if (digits.size() == 0) return digits;

	int i = digits.size() - 1;
	int bUpFlag = 1;
	while (i >= 0 && bUpFlag > 0)
	{
		digits[i] += bUpFlag;
		bUpFlag--;
		if (digits[i] > 9)
		{
			bUpFlag += digits[i] / 10;
			digits[i] %= 10;
		}
		i--;
	}
	if (bUpFlag > 0)
	{
		digits.insert(digits.begin(), bUpFlag);
	}
	return digits;
}
``` 


* 283.MoveZeroes 移动零  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/283.MoveZeroes/Description.jpg)

``` C++
void moveZeroes(vector<int>& nums) 
{
	int iLen = nums.size();
	int j = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (nums[i] != 0)
		{
			if (i != j)
			{
				swap(nums[i], nums[j]);
			}
			++j;
		}
	}
}
``` 


* 350.Intersect 两个数组的交集 II  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/350.Intersect/Description.jpg)

``` C++
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0; 
	int j = 0;
	vector<int> nums;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else if (nums1[i] > nums2[j])
		{
			j++;
		}
		else
		{
			nums.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return nums;
}
``` 

---
## 20190424
* 189.Rotate 旋转数组  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/189.Rotate/Description.jpg)

这道简单的题，看到要求使用空间复杂度为 O(1) 的原地算法。  
就规避了使用公共算法，额外的数组等。  
想着想着就感觉走上了歪路。  
不过幸好突破了最后的难关，让这条小路顺利抵达终点。  

思路和代码：  
我就想不管k是几，就让后面的数一口气先交换获得最终结果。  
然后剩下的被交换的乱七八糟的数字，再找规律。
万幸最后找到了规律，感觉还不错。  

``` C++
void rotate(vector<int>& nums, int k)	// 28ms
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}
		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}
``` 
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/189.Rotate/Solution.jpg)



另外分享一下看到的超简洁的思路
``` C++
void rotate(vector<int>& nums, int k)	// 12ms
{
	k = k >= nums.size() ? k - nums.size() : k;
	if (k)
	{
		reverse(nums.begin(), nums.end() - k);
		reverse(nums.end() - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
}
```

* 217.ContainsDuplicate 存在重复元素  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/217.ContainsDuplicate/Description.jpg)

这道题前两天面试官现场问我的，  
当时我说先排序，再判断相邻两个数字是否相同。  
面试官还问可不可以不排序，  
我就又说用map记录一下。  
结果测试速度最快的就是先排序那个方法。  

``` C++
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}
```



---
## 20190423
* 122.MaxProfit 买卖股票的最佳时机 II  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/122.MaxProfit/Description.jpg)

``` C++
int maxProfit(vector<int>& prices)	// 12ms
{
	if (prices.size() < 2) return 0;

	int iLen = prices.size();
	int iMaxValue = 0;
	int high = prices[iLen - 1];
	int low = high;
	int j = iLen - 2;
	while (j >= 0)
	{
		if (high < prices[j])
		{
			if (low < high)
			{
				iMaxValue += high - low;
			}
			high = prices[j];
			low = high;
		}
		else
		{
			if (prices[j] < low)
			{
				low = prices[j];
			}
			else
			{
				iMaxValue += high - low;
				high = prices[j];
				low = high;
			}
		}
		j--;
	}
	if (low < high)
	{
		iMaxValue += high - low;
	}
	return iMaxValue;
}
```  

看了第一的算法，感觉智商被爆了。  
研究了两个小时，还画了草稿，总算有点感觉要明白了。  
想不通的原因，是虽然我的代码提交，结果对了，  
但是我并没有把题目的内在的规律摸清楚，  
有点连蒙带猜的感觉。  
仔细想了想，核心思路其实一样的，只是我每一步都交代的特别仔细。  
而大佬的算法可以将可能无用的东西先吃进去，  
然后在内部消化取舍。  
这样循环执行过程就非常的简洁，非常犀利。  

``` C++
int maxProfit(vector<int>& prices)	// 4ms
{
	if (prices.size() < 2)return 0;
	int hold = -prices[0], unhold = 0;
	for (int i = 1; i < prices.size(); ++i) {
		int tmp = hold;
		hold = max(hold, unhold - prices[i]);
		unhold = max(unhold, tmp + prices[i]);
	}
	return unhold;
}
```  

草稿分析了一下这个算法：  
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/122.MaxProfit/Solution.jpg)


* 50.MyPow  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/50.MyPow/Description.jpg)

``` C++
double myPow(double x, int n)	// 4ms
{
	switch (n)
	{
	case -1:
		return 1 / x;
	case 0:
		return 1.0;
	case 1:
		return x;
	case 2:
		return x * x;
	}

	return myPow(myPow(x, 2), n / 2) * myPow(x, n % 2);
}
```

* 88.Merge 合并两个有序数组  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/88.Merge/Description.jpg)

``` C++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int k = m + n;

	while (k > 0)
	{
		k -= 1;
		if (m > 0 && n > 0)
		{
			if (nums1[m - 1] < nums2[n - 1])
			{
				nums1[k] = nums2[n - 1];
				n -= 1;
			}
			else
			{
				nums1[k] = nums1[m - 1];
				m -= 1;
			}
		}
		else if (m == 0 && n != 0)
		{
			nums1[k] = nums2[n - 1];
			n -= 1;
		}
		else if (m != 0 && n == 0)
		{
			break;
			//nums1[k] = nums1[m - 1];
			//m -= 1;
		}
	}
}
```

---
## 20190422
* 26.RemoveDuplicates 删除排序数组中的重复项  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/26.RemoveDuplicates/Description.jpg)

别人写的这个代码，感觉比较精简。
``` C++
int removeDuplicates(vector<int>& nums)		// 20ms
{
	if (nums.size() == 0) return 0;
	auto i = 0;
	auto j = 0;
	while (j < nums.size()) 
	{
		if (nums[i] == nums[j]) j++;
		else nums[++i] = nums[j];
	}
	return i + 1;
}
```

* 136.SingleNumber 只出现一次的数字  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/136.SingleNumber/Description.jpg)

来LeetCode做的第一道题，打开了新世界的大门。  
重新学了一遍异或。
``` C++
int singleNumber(vector<int>& nums)
{
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}
```

* 169.MajorityElement 求众数  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/169.MajorityElement/Description.jpg)

感觉思路和上面那道题有点像。  
有意思的地方是，当计数回到0的时候，就可以放弃他，换一个新数了。  
这只有众数的特点才能这么写的算法。  

``` C++
int majorityElement(vector<int>& nums)
{
	int res = 0, cnt = 0;
	for (int num : nums) 
	{
		if (cnt == 0) 
		{ 
			res = num;
			++cnt; 
		}
		else
		{
			(num == res) ? ++cnt : --cnt;
		}
	}
	return res;
}
```

* 206.ReverseList 反转链表  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/206.ReverseList/Description.jpg)

这道题之前就做过。  

``` C++
ListNode* ReverseIteratively(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		// get the next node, and save it at pNext
		ListNode* pNext = pNode->m_pNext;
		// reverse the linkage between nodes
		pNode->m_pNext = pPrev;

		// move forward on the the list
		pPrev = pNode;
		pNode = pNext;
	}
	pReversedHead = pPrev;
	return pReversedHead;
}
```

> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/206.ReverseList/Solution.jpg)


* 240.SearchMatrix 搜索二维矩阵 II 
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/240.SearchMatrix/Description.jpg)

这道题做了好久。  
结果还是因为没有搞清楚矩阵的数学特点。  
下面的代码写的很符合特点。  

``` C++
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int r = matrix.size();
	if (r == 0) return false;

	int c = matrix[0].size();
	for (int i = 0, j = c - 1; i<r && j>-1;)
	{
		if (target < matrix[i][j])
		{
			j--;
		}
		else if (target > matrix[i][j])
		{
			i++;
		}
		else
		{
			return true;
		}
	}
	return false;
}
```

---
## 20190419

这两天开始做leetcode，随便选了一个2018算法的习题集，然后有5道热身题，做完真是大开眼界，同时也被虐的很惨。

前面几道题都很打击我，不过还好脆脆来开导我，保住了信心。  

前几道就光在题目上思考，结果最后看别人答案都是从数学角度出发。  
然后今天做最后一道题，终于也朝着数学的方向思考，估计想了2个多小时。  
没想到修正了几次思路之后，就找到钥匙啦。
做完之后显示击败了99.35%的用户，开心啊。  

* 887.SuperEggDrop 鸡蛋掉落
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Description.jpg)

解题思路，从【已知N层楼，K个蛋，求最小必要行动次数T】  
变成【已知K个蛋，求T次行动可以判断的楼层数>N】


``` C++
int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动iTime次，计算能判断多少层

	// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (iTime == 1) return 2;	

	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出iTime + 1层	
	if (K == 1) return iTime + 1;	

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层
	// + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1)
	 + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int iTime = 0;
	int iMaxCoverage = 0;
	do
	{
		++iTime;
		iMaxCoverage = calcMaximumCoverage(iTime, K);
	} while (iMaxCoverage < N + 1);
	return iTime;
}
```

草稿：  
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Solution.jpg)
> Solution2.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Solution2.jpg)