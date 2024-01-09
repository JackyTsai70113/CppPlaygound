#include "Huffman_Tree.h"
#include <iostream>

using namespace std;

void Max_Heapify(int *data, int root, int len)
{
    //              5(root)
    // 10(largest)               3

    //              10(root)
    // 5(largest)               3
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int largest = root;

    if (left < len && data[left] > data[largest])
    {
        largest = left;
    }

    if (right < len && data[right] > data[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        // Swap data[root] and data[largest]
        int tmp = data[root];
        data[root] = data[largest];
        data[largest] = tmp;
        Max_Heapify(data, largest, len);
    }
}

void Min_Heapify(int *data, int root, int len)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int smallest = root;

    if (left < len && data[left] < data[smallest])
    {
        smallest = left;
    }

    if (right < len && data[right] < data[smallest])
    {
        smallest = right;
    }

    if (smallest != root)
    {
        // Swap data[root] and data[smallest]
        int tmp = data[root];
        data[root] = data[smallest];
        data[smallest] = tmp;
        Min_Heapify(data, smallest, len);
    }
}

void Build_Max_Heap(int *data, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        Max_Heapify(data, i, len);
    }
}

void Build_Min_Heap(int *data, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        Min_Heapify(data, i, len);
    }
}

void Print_Array(int *data, int len)
{
    cout << "Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Heap_Sort(int *data, int len)
{
    // Step 1: Make max heap
    Build_Max_Heap(data, len);

    for (int i = len - 1; i > 0; i--)
    {
        // Step 2: Swap data[i] and data[0]
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        // Step 3: Max heapify again
        Max_Heapify(data, 0, i);
    }
}

void Test_Heapify()
{
    int data[] = {5, 4, 2, 7, 8, 6, 3, 9, 1};
    cout << "Before Heapify...." << endl;
    Print_Array(data, 9);
    cout << "After Max-Heapify...." << endl;
    Build_Max_Heap(data, 9);
    Print_Array(data, 9);

    int data2[] = {5, 4, 2, 7, 8, 6, 3, 9, 1};
    cout << "After Min-Heapify...." << endl;
    Build_Min_Heap(data2, 9);
    Print_Array(data2, 9);

    cout << "After Heap Sort...." << endl;
    Heap_Sort(data, 9);
    Print_Array(data, 9);
}

void Test_Huffman_Tree()
{
    Huffman_Tree code;
    code.Insert('A', 67);
    code.Insert('B', 152);
    code.Insert('C', 92);
    code.Insert('D', 263);
    code.Insert('E', 128);
    code.Insert('F', 86);
    code.Insert('G', 20);
    code.Insert('H', 36);
    code.Build_Huffman_Tree();
    code.Print_Code_Table();
}

void Test_Huffman_Tree2()
{
    string input = "AAAACAABDBAABDCBAADAA";
    Huffman_Tree huffman;
    huffman.Input_String(input);
    cout << "Start to print the frequency table of " << input << endl;
    huffman.Print_Frequency_Table();
    huffman.Build_Huffman_Tree();
    cout << "Print the code table..." << endl;
    huffman.Print_Code_Table();
    string encode = huffman.Encode(input);
    cout << "Print encode of " << input << ": " << encode << endl;
    cout << "Print decode of " << encode << ": " << huffman.Decode(encode) << endl;
}

int main()
{
    // Test_Heapify();
    // Test_Huffman_Tree();
    Test_Huffman_Tree2();
    return 0;
}