# Project Instruction

## 文件夹层级

* `problems` 存放所有leetcode-cn题目
  * `problems/two-sum` 使用英文名称作为文件夹名称
    * `problems/two-sum/README.md` 答题文件，使用**工具生成**
    * `problems/two-sum/SOLUTION.cpp` 代码文件，使用**工具生成** 
    * `problems/two-sum/tests.txt` 测试用例文件，使用**工具生成**

* `problemset` 题目索引文件夹，用来保存id和title
  * `problemset/all/README.md` 全部题目的列表文件，使用**工具生成**
  * `hot-100` 热题100的索引，各种类型索引的一种
    * `problemset/hot-100/index.txt` 网站上索引的id数据，手动生成
    * `problemset/hot-100/README.md` 列表文件，根据index.txt的数据，使用**工具生成**

* `contest` 竞赛目录
  * `contest/weekly-contest-156`某个比赛
    * `contest/weekly-contest-156/README.md` 某个比赛的题目列表文件，使用**工具生成**

* `test` 存放测试工程
  * `test/Common` 公共文件
    * `test/Common/Define_IdName.h` 定义id和cpp文件，id和tests.txt的关系，使用**工具生成**
* `test/Test` 测试工程，通过使用`Define_IdName.h`的宏定义，可以include不同的cpp和tests.txt来调试
  
* `README.md` 主页面md文件，使用**工具生成**
* `Solutions.md` 题解列表的md文件，包含所有发布过题解的题目，使用**工具生成**
* `Thanks.md` 致谢的md文件，手动生成
* `Update.md` 更新列表的md文件，使用**工具生成**

## 工具生成的文件列表

1. `README.md` 主页面md文件

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

4. `Update.md` 更新列表的md文件
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
   3. 使用模板自动填写参数的转接调用`_solution_run()`
   4. 单独填写参数的转接调用`_solution_custom()`
   5. 选择使用代码中的字符串测试用例`_get_test_cases_string()`
   6. 选择使用文件测试用例`_get_test_cases_filestream()`
   
7. `problems/英文标题/tests.txt` 测试用例文件
   1. 仅生成空文件
8. `test/Common/Define_IdName.h` 定义id和cpp文件
   1. SOLUTION.cpp的宏
   2. tests.txt的宏
9. `git_commit.bat` 用来提交github的文件

## 自动生成的工具流程

1. 填写题目信息
   1. 选择难度
   2. 是否完成
   3. 获取题目连接
   4. 获取题目id和中文名称
      1. 自动得到id，英文名称，中文名称
      2. 如果是比赛，自动获得比赛名称
   5. 填写题解链接
   6. 获取题目描述
   7. 填写答题的代码
   8. 填写其它的代码
   9.  选择从哪个模板拷贝测试程序的代码和测试用例
2.  点击生成按钮
    1. 更新（`problemset/all/README.md`）文件
    2. 更新（`README.md`）文件
    3. 更新（`Update.md`）文件
    4. 更新（`Solutions.md`）文件
    5. 如果是比赛，创建/更新比赛的(`contest/xxx/README.md`)文件
    6. 更新题目的（`problems/英文标题/README.md`）文件
    7. 拷贝测试代码(`SOLUTION.cpp`)文件
    8. 拷贝测试用例(`tests.txt`)文件
    9. 更新测试程序的宏定义（`test/Common/Define_IdName.h`）文件
    10. 更新测试程序的主文件宏定义（`test/Test/Test.cpp`）文件
3.  更新（`git_commit.bat`）文件

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

## 测试工程的使用
1. 宏定义（`test/Common/Define_IdName.h`）文件  
   由工具生成对应的id和名称的宏定义
   ```C++
   #define SOLUTION_CPP_FOLDER_NAME_ID_1	two-sum
   ```

2. 测试代码(`SOLUTION.cpp`)文件，不同的题目存在不同的文件夹下  
   代码内有由工具生成转接代码
   ```C++
   vector<int> _solution_run(vector<int> &nums, int target)
   {
      return twoSum(nums, target);
   }
   ```
   取消宏定义及其相关代码的注释之后，也可使用自定义的转接代码
   ```C++
   //#define USE_SOLUTION_CUSTOM
   //vector<int> _solution_custom(TestCases &tc)
   //{
   //	vector<int> nums(tc.get<vector<int>>());
   //	int target(tc.get<int>());
   //	return twoSum(nums, target);
   //}
   ```

3. 测试用例(`tests.txt`)文件，和测试代码在同一个文件夹下  
   注释掉宏定义之后可以不使用代码中的测试用例而是用测试用例文件
   
   ```C++
   vector<string> _get_test_cases_string()
   {
      return {
         "[2,7,11,15]",
         "9",
      "[0,1]",
   
         "[2,7,11,15]",
         "18",
         "[1,2]"
      };
}
   
   //#define USE_GET_TEST_CASES_FILESTREAM
   //string _get_test_cases_filestream()
   //{
   //	return "tests_1.txt";
   //}
```
   
4. 测试程序（`test/Test/Test.cpp`）文件  
   通过修改`#include`相关的宏，加载不同的测试代码，然后运行调试
   ```C++
   // 选择测试代码

   // 1.选择使用（本路径的测试代码）
   //#include "Test_1.cpp"
   //#include "Test_2.cpp"
   //#include "Test_3.cpp"
   //#include "Test_4.cpp"
   //#include "Test_5.cpp"

   // 2.或者选择使用（题库中的题，根据编号加载，使用Define_IdName.h中定义的宏）
   // SOLUTION_CPP_FOLDER_NAME_ID_1 ==> 最后的数值是题目编号
   #define ADD_QUOTES(A) #A
   #define SOLUTION_CPP_PATH(name) ADD_QUOTES(../../problems/##name/SOLUTION.cpp)
   #define SOLUTION_CPP_PATH_NAME(name) SOLUTION_CPP_PATH(name)
   #include SOLUTION_CPP_PATH_NAME(SOLUTION_CPP_FOLDER_NAME_ID_1)

   // 3.或者选择使用（题库中的题，根据名字加载）
   // SOLUTION_CPP_PATH(two-sum) ==> 最后的参数是题目名字
   //#define ADD_QUOTES(A) #A
   //#define SOLUTION_CPP_PATH(name) ADD_QUOTES(../../problems/##name/SOLUTION.cpp)
   //#include SOLUTION_CPP_PATH(two-sum)
   ```