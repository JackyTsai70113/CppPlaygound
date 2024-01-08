#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
    char character;
    int counts;
    Node *left;
    Node *right;
};

class Compare
{
public:
    bool operator()(Node *n1, Node *n2)
    {
        return n1->counts > n2->counts;
    }
};

class Huffman_Tree
{
private:
    unordered_map<char, string> encode_map;
    unordered_map<string, char> decode_map;
    priority_queue<Node *, vector<Node *>, Compare> all_nodes;
    Node *Pop_Node();
    void Clear_Queue();

public:
    Node *root_node;
    Huffman_Tree();
    void Insert(char, int);
    void Input_String(string);
    void Build_Huffman_Tree();
    void Print_Code_Table();
    void Print_Frequency_Table();
    void Traversal(Node *, queue<char>);
    string Encode(string);
    string Decode(string);
};

Node *Huffman_Tree::Pop_Node()
{
    if (all_nodes.empty())
        return nullptr;
    Node *tmp = all_nodes.top();
    all_nodes.pop();
    return tmp;
}

Huffman_Tree::Huffman_Tree()
{
    root_node = nullptr;
}

void Huffman_Tree::Clear_Queue()
{
    cout << "Start to clear priority queue in this Huffman Tree." << endl;
    while (!all_nodes.empty())
    {
        Node *node = all_nodes.top();
        cout << "Char: " << node->character << ", Counts:" << node->counts << endl;
    }
}

void Huffman_Tree::Insert(char c, int frequency)
{
    all_nodes.push(new Node{c, frequency, nullptr, nullptr});
}

void Huffman_Tree::Input_String(string str)
{
    unordered_map<char, int> map;
    for (auto c : str)
    {
        map[c] = map.count(c) ? map[c] + 1 : 1;
    }
    for (pair<char, int> p : map)
    {
        char c = p.first;
        int frequency = p.second;
        all_nodes.push(new Node{c, frequency, nullptr, nullptr});
    }
}

void Huffman_Tree::Build_Huffman_Tree()
{
    while (!all_nodes.empty())
    {
        Node *first = Pop_Node();
        if (all_nodes.empty())
        {
            root_node = first;
            return;
        }
        Node *second = Pop_Node();
        int sum = first->counts + second->counts;
        all_nodes.push(new Node{'\0', sum, first, second});
    }
}

void Huffman_Tree::Print_Code_Table()
{
    if (root_node == nullptr)
    {
        cout << "This Huffman Tree is empty!" << endl;
        return;
    }
    queue<char> route;
    Traversal(root_node, route);
}

void Huffman_Tree::Print_Frequency_Table()
{
    priority_queue<Node *, vector<Node *>, Compare> temp;
    while (!all_nodes.empty())
    {
        auto node = Pop_Node();
        cout << "Character: " << node->character << ", Counts: " << node->counts << endl;
        temp.push(node);
    }
    while (!temp.empty())
    {
        auto node = temp.top();
        all_nodes.push(node);
        temp.pop();
    }
}

void Huffman_Tree::Traversal(Node *cur, queue<char> route)
{
    if (cur->left == cur->right)
    {
        string code;
        cout << "Character: " << cur->character << ", Counts: " << cur->counts;
        cout << ", Code: ";
        while (!route.empty())
        {
            char c = route.front();
            route.pop();
            cout << c;
            code = code + c;
        }
        cout << endl;
        encode_map[cur->character] = code;
        decode_map[code] = cur->character;
        return;
    }
    auto left_route = route;
    left_route.push('0');
    Traversal(cur->left, left_route);
    auto right_route = route;
    right_route.push('1');
    Traversal(cur->right, right_route);
}

string Huffman_Tree::Encode(string str)
{
    string result;
    for (auto c : str)
    {
        result = result + encode_map[c];
    }
    return result;
}

string Huffman_Tree::Decode(string str)
{
    string result;
    for (int l = 0, r = 0; r < str.size(); r++)
    {
        string temp = str.substr(l, r - l + 1);
        if (decode_map.count(temp))
        {
            result = result + decode_map[temp];
            l = r + 1;
        }
    }
    return result;
}
