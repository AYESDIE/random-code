#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct MinHeapNode
{
  char data;
  unsigned freq;
  MinHeapNode* left;
  MinHeapNode* right;

  MinHeapNode(char data, unsigned freq)
  {
    left = NULL;
    right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

struct compare{
  bool operator()(MinHeapNode *l, MinHeapNode *r)
  {
    return (l->freq > r->freq);
  }
};

void printCodes(MinHeapNode* root, string str)
{
  if (!root)
    return;

  if (root->data != '$')
    cout << root->data << ": " << str << "\n";

  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char> data,
                  vector<int> freq)
{
  MinHeapNode *left, *right, *top;

  priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

  for (int i = 0; i < data.size(); ++i) {
    minHeap.push(new MinHeapNode(data[i],freq[i]));
  }

  while (minHeap.size() != 1)
  {
    left = minHeap.top();
    minHeap.pop();
    right = minHeap.top();
    minHeap.pop();

    top = new MinHeapNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    minHeap.push(top);
  }

  printCodes(minHeap.top(), "");
}

int main()
{
  vector<char> x({ 'a', 'b', 'c', 'd', 'e', 'f' });
  vector<int> c({ 5, 9, 12, 13, 16, 45 });

  HuffmanCodes(x, c);

  return 0;
}

