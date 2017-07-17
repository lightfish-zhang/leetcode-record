## 题目

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

example:

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

## 思路

### 思路１，简单,时间复杂度O(n^2)

- 最简单想到的方法是，遍历数组，数组的元素设为`num`，获得`target-num`的值，嵌套遍历数组以查看该值是否存在数组`nums`中，若存在，则返回这两个值的下标值，否则外层遍历继续。
- 该思路存在两次循环,时间复杂度为O(n^2),空间上只要分配返回值的大小`sizeof(int)*2`,空间复杂度为O(1)

### 思路２, 时间复杂度为O(n)

- 从思路１吸取经验，每次都需要获得`target-num`的值都需要检查是否存在，思路1是使用遍历，直觉优化点在这一次遍历上
- 其实`target-num`的值与`num`都存在数组中，都需要寻找对方，这里可以优化，如果第一个元素找不到对方，那就把第一个元素放置在可以快速判断存在性的表中，那第二个元素来找就可以了，这就需要效率高的方法判断对方是否存在了
- 使用一个表存储遍历过的元素以及下标，可以使用O(1)时间复杂度来判断存储的元素是否存在，决定使用哈希表
- 时间复杂度为O(n)*O(1)=O(n)，空间上，需要一个表存储遍历过的元素，最大值为`numsSize`,空间复杂度为O(k)