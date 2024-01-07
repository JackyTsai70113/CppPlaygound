# BinaryTree

## 分類

- 斜曲二元樹(Skewed binary tree)
  - 沒有某一側的子節點，相當於 linked list
  - 左斜曲(Left-skewed)二元樹
  - 右斜曲(Right-skewed)二元樹
- 嚴格二元樹(Strictly binary tree)
  - n1 = 0, 分岔度1的節點個數為0
- 完滿二元樹(Full binary tree)
  - 每個 non-leaf node 都有兩個 child Node
  - 所有 leaf node 的 level 都相同
  - 最大階層 h 的完滿二元樹，節點為 2^h-1 個
- 完整二元樹(Complete binary tree)
  - 節點依序排列是連續，沒有空缺
  - 次序由上至下，由左至右
  - 最大階層 h 的完整二元樹，2^(h-1)-1 < 節點個數 <= 2^h-1

## 二元樹表示法

- 陣列
  - 適合完滿二元樹，完整二元樹
  - 斜曲二元樹時浪費大量空間
  - 索引值 k 的節點
    - left child: 索引值 2*k+1
    - right child: 索引值 2*k+2
    - parent: 索引值 floor((k-1)/2)

      ```mermaid
      graph TD
      A-0 --> B-1
      A-0 --> C-2
      B-1 --> D-3
      B-1 --> E-4
      C-2 --> F-5
      C-2 --> G-6
      ```

- 鏈結串列
  - 適合斜曲二元樹
  - 節點內容
    - 資料內容
    - 左節點指標
    - 右節點指標
    - (父節點指標)
  - n 個節點的二元樹的空間浪費率
    - n-1 是有使用的指標樹
    - 無用的指標/指標總數: (2n-(n-1)) / (2n) = (n+1)/(2n)

## 二元樹的尋訪

- Predecessor
  - 該節點的前一個節點
  - 如果左子樹不為空
    - 找左子樹的 right most
  - 如果左子樹為空
    - 找該節點的 Ancestor Node
    - 且該節點在 Ancesotr 的右子樹

- Successor
  - 該節點的後一個節點
  - 如果右子樹不為空
    - 找右子樹的 left most
  - 如果右子樹為空
    - 找該節點的 Ancestor Node
    - 且該節點在 Ancesotr 的左子樹

## 二元樹的刪除

- 依據刪除的節點種類分成三種狀況
  - 沒有任何子節點
    - 直接刪除即可
  - 有一個子節點
    - 把該節點的位置以其子節點替代
  - 有兩個子節點
    - 刪除後，找尋節點來替代
    - 從其右子樹找最小的(Successor) 或是左子樹找最大的(Predecessor)

## 一般樹化為二元樹

- 將兄弟節點們用平行線連結
- 只保留每個節點中最左邊的連結
- 右邊的兄弟節點順時針轉 45 度

  ```mermaid
      flowchart TD
      %% B connect to H
      A --> B 
      %% H connect to C
      A --> H
      A --> C
      %% D connect to E
      B --> D
      B --> E
      %% F connect to G
      C --> F
      C --> G

      A' --> B'
      B' --> D'
      D' --> E'
      B' --> H'
      H' --> C'
      C' --> F'
      F' --> G'
  ```
