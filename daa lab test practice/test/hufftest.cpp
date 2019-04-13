#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct HeapNode{
  HeapNode *left, *right;
  int freq;
  char data;

  HeapNode(char data, int freq)
  {
    left=NULL;
    right=NULL;
    this->data = data;
    this->freq = freq;
  }
};

struct comp{
  bool operator()(HeapNode *l, HeapNode *r){
    return (l->freq > r->freq);
  }
};

void printcodes(HeapNode *root, string data)
{
  if (!root)
    return;

  if (root->data != '$')
    cout << root->data << ": " << data << "\n";

  printcodes(root->left,data+'0');
  printcodes(root->right,data+'1');

}

void huffmancodes(vector<char> data,
                  vector<int> freq)
{
  HeapNode *top, *right, *left;
  priority_queue<HeapNode*, vector<HeapNode*>, comp> Heap;

  for (int i = 0; i < data.size(); ++i) {
    Heap.push(new HeapNode(data[i],freq[i]));
  }

  while(Heap.size()!=1)
  {
    left = Heap.top();
    Heap.pop();
    right = Heap.top();
    Heap.pop();

    top = new HeapNode('$',left->freq + right->freq);
    top->right=right;
    top->left=left;

    Heap.push(top);
  }

  printcodes(Heap.top(), "");

}

int main()
{
  vector<char> x({ 'a', 'b', 'c', 'd', 'e', 'f' });
  vector<int> c({ 5, 9, 12, 13, 16, 45 });

  huffmancodes(x, c);

  return 0;

}