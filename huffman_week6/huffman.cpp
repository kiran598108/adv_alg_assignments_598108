#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned freq) 
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};


struct Compare 
{
    bool operator()(HuffmanNode* l, HuffmanNode* r) 
    {
        return l->freq > r->freq;
    }
};


void printValues(HuffmanNode* root, string str) 
{
    if (!root) return;

    
    if (root->data != '$') 
    {
        cout << root->data << " : " << str << endl;
    }

    
    printValues(root->left, str + "0");
    printValues(root->right, str + "1");
}


void buildHuffmanTree(string S, vector<int> f) 
{
   
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;
    for (size_t i = 0; i < S.size(); i++) 
    {
        minHeap.push(new HuffmanNode(S[i], f[i]));
    }

   
    while (minHeap.size() > 1) 
    {
        
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        
        HuffmanNode* newNode = new HuffmanNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        
        minHeap.push(newNode);
    }

    
    HuffmanNode* root = minHeap.top();

   
    printValues(root, "");
}

int main() 
{
    string S;
    vector<int> f;
    int n;

   
    cout << "Enter the number of characters: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) 
    {
        char ch;
        int freq;
        cout << "Enter character " << i + 1 << ": ";
        cin >> ch;
        cout << "Enter frequency for " << ch << ": ";
        cin >> freq;
        S.push_back(ch);
        f.push_back(freq);
    }

    
    buildHuffmanTree(S, f);

    return 0;
}