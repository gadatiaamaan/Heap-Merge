#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node class for representing elements in the binary tree
class Node {
public:
    int value;          // Value of the node
    Node *left;         // Pointer to the left child
    Node *right;        // Pointer to the right child

    // Constructor for Node class
    Node(int value, Node *ltree = nullptr, Node *rtree = nullptr) : value(value), left(ltree), right(rtree) {}
};

// Heap class for implementing the binary heap data structure
class Heap {
public:
    // Constructor
    Heap() : root(nullptr) {}

    // Destructor
    ~Heap() { clear(root); }

    // Function to insert a value into the heap
    void insert(int value);

    // Function to merge another heap into this heap
    void merge(Heap &other);

    // Function to extract the minimum value from the heap
    int extractMin();

    // Function to check if the heap is empty
    bool isEmpty() const { return root == nullptr; }

    // Function to convert the heap into a vector
    vector<int> toArray();

private:
    Node *root;     // Pointer to the root of the heap

    // Helper function to merge two heaps
    void merge(Node *&rootA, Node *rootB);

    // Helper function to clear the heap
    void clear(Node *root);
};

// Function to insert a value into the heap
void Heap::insert(int value) {
    Node *newNode = new Node(value);
    merge(root, newNode);
}

// Helper function to merge two heaps
void Heap::merge(Node *&rootA, Node *rootB) {
    if (rootA == nullptr) {
        rootA = rootB;
    } else if (rootB != nullptr) {
        if (rootB->value < rootA->value) {
            swap(rootA, rootB);
        }
        merge(rootA->right, rootB);
        swap(rootA->left, rootA->right);
    }
}

// Function to merge another heap into this heap
void Heap::merge(Heap &other) {
    if (this == &other) {
        return;
    }
    merge(root, other.root);
    other.root = nullptr;
}

// Function to extract the minimum value from the heap
int Heap::extractMin() {
    if (isEmpty()) {
        throw runtime_error("Heap is empty");
    }
    int minValue = root->value;
    Node *oldRoot = root;
    root = nullptr;
    merge(root, oldRoot->left);
    merge(root, oldRoot->right);
    delete oldRoot;
    return minValue;
}

// Helper function to clear the heap
void Heap::clear(Node *root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

// Function to convert the heap into a vector
vector<int> Heap::toArray() {
    vector<int> result;
    stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        result.push_back(current->value);
        current = current->right;
    }

    return result;
}

// Main function
int main() {
    // Arrays representing the elements of two heaps
    int arrayA[] = {4, 19, 8, 27, 20, 12, 43, 15, 25};
    int arrayB[] = {6, 8, 7, 14};

    // Create two heaps
    Heap heapA;
    Heap heapB;

    // Insert elements into heap A
    cout << "Heap A: ";
    for (int value : arrayA) {
        cout << value << " ";
        heapA.insert(value);
    }
    cout << endl;

    // Insert elements into heap B
    cout << "Heap B: ";
    for (int value : arrayB) {
        cout << value << " ";
        heapB.insert(value);
    }
    cout << endl;

    // Merge heap B into heap A
    heapA.merge(heapB);

    // Convert the merged heap to a vector
    vector<int> mergedHeap = heapA.toArray();

    // Output the merged heap
    cout << "Merged Heap: ";
    for (int value : mergedHeap) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
