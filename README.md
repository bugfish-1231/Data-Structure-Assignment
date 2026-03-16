# Data-Structure-Assignment
CS203A home assignment

# 資料結構作業一：佇列模擬堆疊 (Queue-to-Stack Simulation)

## 1. 題目要求
**目標**：使用兩個佇列 (Queue) 實作堆疊 (Stack) 功能。
**限制**：禁止使用 C++ STL 等標準函式庫 。
**功能**：需包含 `push`, `pop`, `top`, `empty` 等操作 。
**輸入**：讀取 `hw1_input.txt` 檔案。
**輸出**：標準輸出 (Standard Output)。

## 2. 演算法設計
本實作採用 **Push** 策略，確保 Stack 的 Top 元素始終位於主佇列的隊首。

### 時間複雜度 
| 操作 | 時間複雜度 | 說明 |
| :--- | :--- | :--- |
| **Push** | $O(n)$ | 需將現有 $n$ 個元素移動至另一個佇列再移回 |
| **Pop** | $O(1)$ | 直接從隊首移除元素 |
| **Top** | $O(1)$ | 直接讀取隊首元素 |
| **Empty** | $O(1)$ | 檢查佇列是否為空 |

## 測資
- TEST1

| 指令 (hw1_input.txt) | 預期標準輸出 |
| :--: | :--: |
| push 1  |   |
| push 2  |   |
| push 3  |   |
|   pop   | 3 |
| push 4  |   |
|   top   | 4 |
|   pop   | 4 |
|   top   | 2 |
|   pop   | 2 |
|   pop   | 1 |
|  empty  | T |
| push 100|   |
|   top   |100|
|   pop   |100|
|  empty  | T |
|   exit  |   |

- TEST2
| 指令 (hw1_input.txt) | 預期標準輸出 |
| :--: | :--: |
|  empty  | T |
| push 77 |   |
|   top   | 77|
|   pop   | 77|
|  empty  | T |
| push 10 |   |
| push 20 |   |
| push 30 |   |
| push 40 |   |
| push 50 |   |
|   pop   | 50|
|   pop   | 50|
|   top   | 30|
| push 60 |   |
| push 70 |   |
|   top   | 70|
|   pop   | 70|
|   pop   | 60|
|   pop   | 30|
|  empty  | F |
|   pop   | 20|
|   top   | 10|
|   pop   | 10|
|  empty  | T |
|   exit  |   |