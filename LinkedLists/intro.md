# LinkedList

## 效能分析

Pros

- 新增/刪除只需要改寫 O(1) 個節點的資料內容
- 若是新增開頭的資料，只需要 O(1)
- 資料數量是彈性的，不像陣列需要時常搬動資料
Cons
- 要刪除/新增特定位置的資料，需要 O(N) 的搜尋
- 不支援索引值取值，搜尋需要 O(N)
- 相較於陣列，需要額外空間儲存指標與記憶體位置

## 使用時機

- 資料的總數是浮動的，每次更動都不需要移動資料
- 新增/刪除資料的操作頻繁
- 很少有查詢或走訪資料的需求

## 架構

```cpp
// node
template <typename T>
struct Linked_List{
    T Data;
    Node *Next;
}
// linked_list
template <typename T>
class Linked_List{
    private:
        Node<T> *First;
    public:
        Linked_List();
        void Print_List();
        int Search_List(T);
}
```

## 語法

C 語法

- `指標 = (指標)malloc(空間大小);`
  - 僅配置記憶體空間，不會呼叫建構式
- `free(指標);`
- `指標=0;`

C++ 語法

- `指標 = new 類別{初始化};`
  - 會創造物件實體，並呼叫建構式
- `delete 指標;`
- `指標 = nullptr;`
