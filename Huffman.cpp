// To implement Huffman Encoding for data compression using a Greedy Algorithm

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;

// 🧱 Node structure for Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

// 🧩 Comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// 🧠 Recursive function to build Huffman codes
void buildCode(Node* root, string s, unordered_map<char, string> &codes) {
    if (!root) return;

    if (!root->left && !root->right)
        codes[root->ch] = s;

    buildCode(root->left, s + "0", codes);
    buildCode(root->right, s + "1", codes);
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    // Step 1️⃣: Count frequency of each character (excluding spaces)
    unordered_map<char, int> freq;
    for (char c : text) {
        if (c != ' ') freq[c]++;
    }

    cout << "\nCharacter frequencies (excluding spaces):\n";
    for (auto &p : freq) {
        cout << p.first << " : " << p.second << " times" << endl;
    }

    // Step 2️⃣: Build Huffman Tree using min-heap (priority_queue)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto &p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node(left, right);
        pq.push(parent);
    }

    Node* root = pq.top();

    // Step 3️⃣: Generate Huffman codes
    unordered_map<char, string> codes;
    buildCode(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (auto &p : codes) {
        cout << p.first << " : " << p.second << endl;
    }

    // Step 4️⃣: Encode the input text
    string encoded = "";
    for (char c : text) {
        if (c != ' ')
            encoded += codes[c];
    }

    cout << "\nEncoded string (grouped 8 bits):\n";
    for (int i = 0; i < encoded.length(); i++) {
        cout << encoded[i];
        if ((i + 1) % 8 == 0) cout << " ";
    }
    cout << endl;

    return 0;
}
