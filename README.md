# Learning C and Data structure in BIT

[TOC]

## 关于这个Repo

## 我的学习之路

## 感谢

​	在这里要感谢[Strawberry](https://github.com/Straw-Breeze)、[Psycho](https://github.com/psycholsc)、[Felinae](https://github.com/felinae98)在我学习过程中给予我的帮助，解答了我很多疑问，学到了一些小技巧，使我在刚开始接触C和C++时少走了很多弯路。也感谢[Miamiao](https://github.com/miamia0)送给我的黑书《数据结构(C语言版)》。

## 简单的笔记

​	位于根目录下的Notes文件夹。

## 疑问

- 数组作为函数参数

  - 一维数组

    ```c++
    void test(int * a)
    test(a);
    ```

  - 二维数组

    ```c++
    void test(int *a)
    test(*a)
    ```

    而且在test函数内部还需要以一位数组的形式调用a，如a[i*x+j]

- 二元队列

  ```c++
  queue<pair<int, int>> tmp;
  tmp.push(make_pair(1,2));
  int a = tmp.front().first;
  ```

- 乐学22题的输入问题

- Delete_vowel的超时问题

- ```
  struct node{
      char data;
      child * head;
  }tree;
  struct child{
      node * find;
      child * next;
  };
  ```

- 定义结构的默认值

- 函数传参，传指针，传地址

- ​