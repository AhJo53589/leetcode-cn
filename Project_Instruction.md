# Project Instruction

## 功能介绍

* 本解决方案是 [leetcode-cn](https://leetcode-cn.com/) 的 `C++` 做题助手
* 可以方便迅速的将其中的题目和测试用例转移到本地 Visual Studio 工程中编码和调试
  * 绝大部分题目，仅需拷贝入口函数，通过工具生成代码，即可本地运行
  * 包含常用的数据结构，以及相应的序列化反序列化功能
  * 使用相同的用例格式，直接复制用例字符串，即可本地批量运行
  * 可进行简单的判题和显示运行时间
* 在完成题目之后，可以较为方便的收集题目信息，记录答题思路，生成答题笔记
  * 生成题目目录，可按照题目编号查询
  * 记录比赛情况
  * 记录发布的题解

## 文件夹层级

* `problems` 存放所有 leetcode-cn 题目
  * `problems/two-sum` 使用英文名称作为文件夹名称
    * `problems/two-sum/README.md` 题目答题，使用**工具生成**
    * `problems/two-sum/SOLUTION.cpp` 题目代码，使用**工具生成** 
    * `problems/two-sum/tests.txt` 题目用例，使用**工具生成**
* `problemset` 题目索引文件夹，用来保存 id 和 title
  * `problemset/all/README.md` 全部题目的列表文件，使用**工具生成**
  * ~~`hot-100` 热题100 的索引，各种类型索引的一种（功能未完成）~~
    * ~~`problemset/hot-100/index.txt` 网站上索引的 id 数据，手动生成~~
    * ~~`problemset/hot-100/README.md` 列表文件，根据 index.txt 的数据，使用**工具生成**~~
* `contest` 竞赛目录
  * `contest/weekly-contest-156`某个比赛
    * `contest/weekly-contest-156/README.md` 某个比赛的题目列表文件，使用**工具生成**
* `test` 存放测试工程
  * `test/Common` 公共文件
    * `test/Common/Define_IdName.h` 定义 id 和 cpp 文件，id 和 tests.txt 的关系，使用**工具生成**
* `test/Test` 测试工程，通过使用 `Define_IdName.h` 的宏定义，可以 include 不同的 cpp 和 tests.txt 来调试
* `Contest.md` 竞赛 markdown 文件，使用**工具生成**
* `README.md` 主页面 markdown 文件，使用**工具生成**
* `Solutions.md` 题解列表的 markdown 文件，包含所有发布过题解的题目，使用**工具生成**
* `Thanks.md` 致谢的 markdown 文件，手动生成
* `Update.md` 更新列表的 markdown 文件，使用**工具生成**

## 自动生成的工具流程（`leetcode_cpp_helper.exe`）

1. 加载题目
   1. 使用（`Launcher`）分页
   2. 填写题目 id ，在 （`problems`）文件夹下查询是否有此题目
   3. 或者修改临时题库的目录及文件夹名称
   4. 点击按钮加载此题，会更新（`test/Test/Test.cpp`）文件
   5. 测试工程（`test/Leetcode.sln`）开始调试，即可运行答题代码和测试用例

2. 生成题目代码
   1. 使用（`New Cpp`）分页
   2. 修改生成文件的位置
   3. 填写答题代码
   4. 填写函数入口，用来拆分返回值、函数名和各个参数
   5. 填写测试用例
      * 一个完整的用例根据题目不同，包括 1-n 行的输入 和 1 行答案
      * 多个用例中间不含空行
   6. 点击按钮生成，会创建如（`problems_test/0/`）文件夹，和（`SOLUTION.cpp`）文件、（`test.txt`）文件

3. 生成答题文件
   1. 使用（`Generate MD`）分页
   2. 选择难度
   3. 是否已解决
   4. 获取题目连接
   5. 获取题目 id 和中文名称
      * 自动得到 id ，英文名称，中文名称
      * 如果是比赛，自动获得比赛名称
   6. 填写题解链接
   7. 获取题目描述
   8. 填写答题的代码
   9.  填写其它的代码
   10. 确认/修改答题代码所在的临时库中目录
   11. 点击生成按钮
      * 更新（`problemset/all/README.md`）文件
      * 更新（`README.md`）文件
      * 更新（`Update.md`）文件
      * 更新（`Solutions.md`）文件
      * 如果是比赛，创建/更新比赛的(`contest/xxx/README.md`)文件
      * 更新题目的（`problems/英文标题/README.md`）文件
      * 拷贝题目代码(`SOLUTION.cpp`)文件
      * 拷贝题目用例(`tests.txt`)文件
      * 更新测试程序的宏定义（`test/Common/Define_IdName.h`）文件
      * 更新测试程序的主文件宏定义（`test/Test/Test.cpp`）文件
      * 更新（`git_commit.bat`）文件

## 测试工程的使用（`test/Leetcode.sln`）

1. 宏定义（`test/Common/Define_IdName.h`）文件  
   由工具生成对应的 id 和名称的宏定义

   ```C++
   #define SOLUTION_CPP_FOLDER_NAME_ID_1	two-sum
   ```

2. 题目代码(`SOLUTION.cpp`)文件，不同的题目存在不同的文件夹下  
   代码内有由工具生成转接代码

   ```C++
   vector<int> _solution_run(vector<int> &nums, int target)
   {
      //int caseNo = -1;
      //static int caseCnt = 0;
      //if (caseNo != -1 && caseCnt++ != caseNo) return {};

      return twoSum(nums,target);
   }

   //#define USE_SOLUTION_CUSTOM
   //vector<int> _solution_custom(TestCases &tc)
   //{
   //	return {};
   //}
   ```

3. 题目用例(`tests.txt`)文件，和测试代码在同一个文件夹下  
   注释掉宏定义之后可以使用代码中的测试用例函数而不是用测试用例文件

   ```C++
   //#define USE_GET_TEST_CASES_IN_CPP
   //vector<string> _get_test_cases_string()
   //{
   //	return {};
   //}
   ```

4. 测试程序（`test/Test/Test.cpp`）文件  
   通过使用 （`leetcode_cpp_helper.exe`）工具修改  
   或直接修改 `#include` 相关的宏，加载不同的测试代码，然后运行调试

   ```C++
   //////////////////////////////////////////////////////////////////////////
   // 选择题目代码
   #define USE_DEFAULT_INCLUDE

   #ifdef USE_DEFAULT_INCLUDE

   // 1. 选择使用 #题库中的题，根据编号加载，使用 Define_IdName.h 中定义的宏#
   // example: 
   // SOLUTION_CPP_FOLDER_NAME_ID_1 ==> SOLUTION_CPP_FOLDER_NAME_ID_2
   #define SOLUTION_ID						SOLUTION_CPP_FOLDER_NAME_ID_1

   #define ADD_QUOTES(A)					#A
   #define SOLUTION_CPP_PATH(_name)		ADD_QUOTES(../../problems/##_name/SOLUTION.cpp)
   #define SOLUTION_CPP_ID_TO_PATH(_name)	SOLUTION_CPP_PATH(_name)
   #define SOLUTION_CPP_FULL_PATH			SOLUTION_CPP_ID_TO_PATH(SOLUTION_ID)
   #include SOLUTION_CPP_FULL_PATH

   #else

   // 2. 或者选择使用 #指定路径的题目代码#
   #define SOLUTION_CPP_FULL_PATH			"../../problems_test/0/SOLUTION.cpp"
   #include SOLUTION_CPP_FULL_PATH

   #endif
   ```
   
5. 自定义启动代码模板

   51.  一系列传参数调用（146）
	```C++
   // 用例第一行使用字符串作为命令调用一系列操作
   // 第二行为对应参数
	// 第三行是答案字符串
	
	// example:
	// ["LRUCache","put","put","get","put","get","put","get","get","get"]
	// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
	// [null,null,null,1,null,-1,null,-1,3,4]
	
	#define USE_SOLUTION_CUSTOM
	string _solution_custom(TestCases &tc)
	{
		vector<string> sf = tc.get<vector<string>>();
		vector<vector<int>> param = tc.get<vector<vector<int>>>();
	
		string ans = "[";
		LRUCache *obj = nullptr;
		for (size_t i = 0; i < sf.size(); i++)
		{
			if (sf[i] == "LRUCache")
			{
				obj = new LRUCache(param[i][0]);
				ans += "null";
			}
			else if (sf[i] == "get")
			{
				int r = obj->get(param[i][0]);
				ans += to_string(r);
			}
			else if (sf[i] == "put")
			{
				obj->put(param[i][0], param[i][1]);
				ans += "null";
			}
			ans += ",";
		}
		ans.pop_back();
		ans += "]";
		return ans;
	}
	```
	
   52. 环形链表（141）
	```C++
	// 环形链表
	
	#define USE_SOLUTION_CUSTOM
	bool _solution_custom(TestCases &tc)
	{
		string a = tc.get<string>();
		int b = tc.get<int>();
		ListNode *head = StringIntToCycleListNode(a, b);
		return hasCycle(head);
	}
	```
	
   53. 相交链表（160）
	```C++
	// 相交链表
	
	#define USE_SOLUTION_CUSTOM
	string _solution_custom(TestCases &tc)
	{
		string l1 = tc.get<string>();
		string l2 = tc.get<string>();
		int k1 = tc.get<int>();
		int k2 = tc.get<int>();
		ListNode *pA = nullptr;
		ListNode *pB = nullptr;
		StringIntToIntersectionNode(&pA, &pB, l1, l2, k1, k2);
		ListNode *pNode = getIntersectionNode(pA, pB);
		if (pNode == nullptr) return "null";
		return to_string(pNode->val);
	}
	```
	
   54. 特殊处理的 Node.cpp 题目
       * 116
       * 117
       * 133
       * 138
       * 430

---
## 工具生成的文件列表

1. `README.md` 主页面 markdown 文件

   1. 精选题解列表
      * 显示形式：题目信息表格
      * 显示内容：从（`Solutions.md`）手动筛选
   2. 全部题目
      * 完成进度（已完成 / 全部数量）
      * 查看全部，指向（`problemset/all/README.md`）

   3. 赛季列表
      * 显示形式：竞赛信息表格
   4. 竞赛列表
      * 同上

   5. 更新列表
      * 查看全部，指向（`Update.md`）

2. `problemset/all/README.md` 全部题目的列表文件
   1. All
      * 显示形式：题目信息表格

3. `Solutions.md` 题解列表的md文件
   1. All Solutions
      * 显示形式：题目信息表格

4. `Update.md` 更新列表的 markdown 文件
   1. 日期
   2. 题目信息
      * 显示形式：题目信息表格

5. `problems/英文标题/README.md` 答题文件
   1. 标题
      * 显示形式：（难度）id.英文标题 中文标题
   2. 题目描述
      * 显示形式：网页描述
   3. 思路
   4. 答题
   5. 其它
6. `problems/英文标题/SOLUTION.cpp` 代码文件
   1. 答题的代码
   2. 其它的代码，注释
   3. 使用模板自动填写参数的转接调用 `_solution_run()`
   4. 单独填写参数的转接调用 `_solution_custom()`
   5. 选择使用代码中的字符串测试用例 `_get_test_cases_string()`
   6. 选择使用文件测试用例 `_get_test_cases_filestream()`
   
7. `problems/英文标题/tests.txt` 测试用例文件
   1. 仅生成空文件
8. `test/Common/Define_IdName.h` 定义 id 和 cpp 文件
   1. SOLUTION.cpp 的宏
   2. tests.txt 的宏
9. `git_commit.bat` 用来提交 github 的文件

## 显示形式

1. 题目信息表格

|      | #    | 名称    | 题目     | 答题          | 题解         | 难度 |
| ---- | ---- | ------- | ---- | ---- | ---- | ---- |
| √ | 1 | [two-sum](../../problems/two-sum) | [两数之和](../../problems/two-sum/README.md) | [cpp](../../problems/two-sum/SOLUTION.cpp) |  | 简单 |

2. 竞赛信息表格

| 日期      | 名称                                                        | 完成  | 排名       |
| --------- | ----------------------------------------------------------- | ----- | ---------- |
| 2019/9/24 | [2019 力扣杯全国秋季编程大赛](./season/2019-fall/README.md) | 3 / 5 | 220 / 1541 |

3. （难度）id.英文标题 中文标题

`（简单）`  [1.two-sum 两数之和](https://leetcode-cn.com/problems/two-sum/)

