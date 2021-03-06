# 2016级徐特立学院数据结构

[TOC]

## 线性表

## 栈和队列

### 7. 表达式求值(1)

​	在用C语言写不通之后用C++用了好久一气呵成，虽然很慢，但是理解得十分透彻。

- 悬而未决的疑问

  如何优雅地规避如

  > 30(/3+3)+4

  这样的表达式呢？

###8. 中缀表达式转后缀表达式

​	最后一个用例永远过不了，不知道是不是7中括号的问题，待解决。

###选作2 表达式求值(2)

​	一次过！但是还是有点儿粗心，掌握了C++的基本用法，感觉很爽。

​	后期需要补一些笔记……

###11. 判断出栈序列

#### 原理

​	**出栈序列中，元素i之后所有比i小的元素间必须是降序排列的。**

#### 延伸

- [卡塔兰数](https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0)
- [文章1](https://blog.csdn.net/cqnuztq/article/details/8769762)
- [文章2](http://www.cnblogs.com/wuyuegb2312/p/3016878.html#suggestion)
- https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/02.01.html

###13. 稀疏矩阵的乘法运算

#### 思想

​	M×N时，先把N转置

###[选作4 飞机场调度](http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68428)

#### 分析

​	这个题不算复杂，但需要用到的变量很多，我分别定义了一个Runway的结构（多跑道可共用此结构）和计算时间（降落和起飞）的结构。总体思想是，用队列存储飞机序号，先进先出，Runway中设remain_time变量，若分配新的飞机上跑道，则赋值为降落/起飞相应所需时间，然后每分钟自减，此项为0时跑道为空。

#### 反思

- 提交过程中出的第一个错是因为在判断循环结束时，用起飞队列空&&降落队列空来判断循环结束，但实际上会出现队列空但跑道上还有飞机的情况。

- 第二个次修改是针对最小用例，对代码的健壮性做了修改，完善了一些除数为0的情况。

- 最后一次修改实际上并不是我自己发现了问题，而是查到一篇博客，给出了好几个用例，其中我发现我在做循环结束的条件判定时还是出了问题，没考虑一开始两队列就是空的情况，于是做了一点小的修改，用flag来记录输入是否给出了结束的命令，若无，即使队列非空，循环也继续进行。

- > `"%\n"` is not a valid format specifier. If you need the `%` character to be part of the output you need to use `"%%"`.

  %应该写成%%，同理，\应该写成\\\\.

#### 代码

#### 参考链接

- [Unknown conversion types in this program I'm meant to compile](https://stackoverflow.com/questions/13455020/unknown-conversion-types-in-this-program-im-meant-to-compile)
- [飞机场调度](http://whtald.blog.163.com/blog/static/40077073200936102352394/)

## 树

###14&15. 二叉树的[建立、基本操作](http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68456)、[还原](http://online.bit.edu.cn/moodle/mod/programming/view.php?id=68457)、遍历

#### 还原二叉树

-  根据层次遍历还原
  - 先用一个队列存储遍历的输入序列raw，依次从队头读取。
  - 建立一个存储二叉树结点的指针队列tree，初始化时先入队一个结点，data值是raw的队头结点。
  - tree出队一个元素node\*，raw出队两个元素，分别为node\*的左右子树（第二步判断队列是否为空），添加指针后 ，这两个元素入队。
  - 循环，直到两队列均为空。
-  前序+中序
-  后序+中序

####基本操作

- 凹入法表示（并计算层数）
  - 递归，但是函数需要两个参数，其中一个是层数，每执行一次就自增。
  - 函数中包含两个递归函数——先输出当前结点的data，然后分别对当前结点的左右子树各递归一次，若cur->left/right == NULL，则停止当前路径的递归
- 先序遍历
  - 除了不计算层数，其余和凹入法相同
- 中序遍历
  - 先做左子树递归，输出当前结点，右子树递归。
- 后序遍历
  - 先做左右子树递归，再输出当前结点
- 非递归的方法遍历
  - 用栈存取走过的路径，但是很难计算层数
- 计算叶子节点数量
  - 同样也是递归，目标是每个节点左右子树的返回值之和，其中，当结点的左右子树都为空时返回1，即为1个叶节点，依次递归。
- 叶子结点互换
  - 递归，先互换，然后对左右子树递归


- 广度优先遍历 BFS （层次遍历）
  - 基本就是层次遍历还原的逆运算，用一个队列，出队一个元素，入队它的左右孩子结点，直到孩子为空。

#### 参考链接

- [阿修罗道的CSDN博客](https://blog.csdn.net/fansongy/article/details/6798278)
- [yanerhao的CSDN博客](https://blog.csdn.net/yanerhao/article/details/45175943)

### 20. 树的建立和基本操作

#### 综述

​	居然在五一假期没做出来，半个月后才想起来补一下。这个题难点主要在于广义表转树，其他还没什么。

​	输入：(a,(b,(c),(d)),(f,(g),(h),(i))) 

####思路

首先，用孩子-兄弟结构表示树，也就是把树转化成二叉树，这样好写，也通用。

1. 构建一个栈，一个当前指针，然后依次遍历输入字符串
2. 当当前字符为'('时，当前指针指向栈顶元素
3. 当当前字符为字母时，顺着当前指针，加一个结点（如有左孩子，就顺着左孩子的右孩子一直往下找到头，也就是放在兄弟结点的最后一个上；如无，就直接加在左孩子上）
4. 当前字符为')'时，出栈，到上一层的父节点上

## 图

------

##参考资料

- 《数据结构（C语言版）》 严蔚敏 吴伟明 编著 清华大学出版社
- 《数据结构（C语言版）》
