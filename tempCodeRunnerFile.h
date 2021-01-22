    struct Node
    {
        char c;
        int freq;
        Node *left;  // Pointer to left child
        Node *right; // Pointer to right child
        Node() : left(nullptr), right(nullptr) {}
        Node(char ch, int f) : c(ch), freq(f), left(nullptr), right(nullptr) {}       // Constructor to initialize node
        Node(char ch, int f, Node *l, Node *r) : c(ch), freq(f), left(l), right(r) {} // Constructor to initialize node
    };
