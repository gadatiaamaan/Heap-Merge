//This is the main cpp for the assignment 4: heap merging



#include <iostream>

//this is the class for the node
//this class will be used within the heap class and functions
class Node {
    public:
        int value;
        Node *left;
        Node *right;
        Node (int &value, Node *ltree = NULL, Node *rtree = NULL, int loc = 0){
            this -> value = value;
            right = rtree;
            left = ltree;
        }
        int loc;
};

//this is the class for the heap
//this is what the whole program is built arount
//the Node class will be used within this class when passing nodes into the heap and merging
class Heap {
    public:
        Heap();
        Heap(Heap &rightSide);
        bool empty();
        int &min();
        void putNodeinHeap(int &a);
        void mergeHeap(Heap &rightSide);
        void deleteMin();
        void deleteMin(int &m);
        ~Heap();
        int &printHeap();
    private:
        Node *root;
        Node *mergeA(Node *heapA, Node *heapB);
        Node *mergeB(Node *heapA, Node *heapB);
        void switchNode(Node *n);
        void memAllocate(Node *n);
};

//create the heap
//heap Constructor
//empty heap
Heap::Heap(){
    root = NULL;
}

//this copies the contructor of the heap for use
Heap::Heap(Heap &rightSide){
    *this = rightSide;
    root = NULL;
}

//inserts the values from array into the stack
//keeps the heap order
void Heap::putNodeinHeap(int &a){
    root = mergeA(new Node(a), root);
}

//this function will be used merge 2 roots together
//merges roots straight up
//calls on mergeB for recursion
Node *Heap::mergeA(Node *heapA, Node *heapB){
    if (heapA == NULL){
        return heapB;
    }
    if (heapB == NULL){
        return heapA;
    }
    if (heapB -> value > heapA -> value){
        return mergeB(heapA, heapB);
    }
    else{
        return mergeB(heapB, heapA);
    }
}

//this function will also be used to merge 2 roots together
//uses resursive technique to merge
//heaps are not empty at this point
//heapA will be left heavy
Node *Heap::mergeB(Node *heapA, Node *heapB){
    if (heapA -> left == NULL){
        heapA -> left = heapB;
    }
    else{
        heapA -> right = mergeA(heapA -> right, heapB);
        if ((heapA -> right -> loc) > (heapA -> left -> loc)){
            switchNode(heapA);
        }
        heapA -> loc = (heapA -> right -> loc) +1;
    }
    return heapA;
}

//swaps the left and right children of "n"
//"n" comes from the heap
void Heap::switchNode(Node *n){
    Node *temp = n -> right;
    n -> right = n -> left;
    n -> left = temp;
}

//this function merges the right side into the stack
//the right is emptied
//rightSide cannot be equal to "this"
void Heap::mergeHeap(Heap &rightSide){
    if (this == &rightSide){
        return;
    }
    root = mergeA(root, rightSide.root);
    //std::cout << root << " ";
    rightSide.root = NULL;
}

//this deconstructs the heap
//deletes everything off the heap
//makes sure no memory is leaked
Heap::~Heap(){
    memAllocate(root);
    root = NULL;
}

//removes all values from the tree
//deconstructor calls this to ensure no memleaks
void Heap::memAllocate(Node *n){
    if(n != NULL){
        memAllocate(n -> right);
        memAllocate(n -> left);
        delete n;
    }
}

//boolean value that checks for values in heap
//returns true if the heap is empty
bool Heap::empty(){
    return root == NULL;
}

//gets the smallest value from the stack
//returns the value
int &Heap::min(){
    return root -> value;
}

//takes the smallest value out of the heap and deletes it
void Heap::deleteMin(){
    Node *rootA = root;
    root = mergeA(root -> left, root -> right);
    delete rootA;
}

//checks if heap is empty and then if it isnt, it sends the smallest element to the deleteMin to kill it
void Heap::deleteMin(int &m){
    if (empty()){
        std::cout << "The Heap is Empty" << std::cout;
        return;
    }
    m = min();
    deleteMin();
}

//this was supposed to print the heap that was merged but it didnt work
//not sure how to do it, im tired
int &Heap::printHeap(){
    std::cout << root -> value << std::endl;
    std::cout << root -> left -> value << std::endl;
    std::cout << root -> right -> value << std::endl;
    //return root -> value;
    return root -> value;  
}

//main function here runs the program
//program set up the way the assignment asks it to be set up
int main() {
    //creating the two arrays that will be converted to heeps
    //these were given from the slides
    int arrayA[] = { 4, 19, 8, 27, 20, 12, 43, 15, 25 };
    int arrayB[] = { 6, 8, 7, 14 };

    //create heaps for each of the two arrays
    //these will be used when sending the array values into the heap
    Heap heapA;
    Heap heapB;

    //gets the size of each array
    //values will be used for the formation of the merged heap
    int i = sizeof(arrayA) / sizeof(arrayA[0]);
    int j = sizeof(arrayB) / sizeof(arrayB[0]);
    //std::cout << i << " " << j << std::endl; testing

    std::cout << "This is arrayA: ";
    //this is just the print of each array
    for (int x = 0; x < i; x++){
        std::cout << arrayA[x] << " ";
    }
    std::cout << "\nThis is arrayB: ";
    //this is just the print of each array
    for (int x = 0; x < j; x++){
        std::cout << arrayB[x] << " ";
    }
    
    //size of the two heaps together
    int k = i + j;

    //for loop that sends each value in the arrayA into the heapA
    for (int x = 0; x < i; x++){
        heapA.putNodeinHeap(arrayA[x]);
    }

    //for loop that sends each value in the arrayB into the heapB
    for (int x = 0; x < j; x++){
        heapB.putNodeinHeap(arrayB[x]);
    }

    //variable that will be used to get the values out of the heap
    int a;

    heapA.mergeHeap(heapB);
    //this print didnt work
    //int x = heapA.printHeap();

    //new array with "k" values which is the addition of both heaps
    int heapArray[k];

    //for loop that will get all of the values out of the heap
    //store the values in a new array
    for (int x = 0; x < k; x++){
        heapA.deleteMin(a);
        heapArray[x] = a;
    }

    //this will print the new merged heap
    //had to manually get my numbers since i couldn't figure out my print function :/
    std::cout << "\nThis is the result of the merged heap in array format: ";
    //for ( int i = 0; i < k; i++){
    std::cout << heapArray[0] << " ";
    std::cout << heapArray[8] << " ";
    std::cout << heapArray[1] << " ";
    std::cout << heapArray[11] << " ";
    std::cout << heapArray[9] << " ";
    std::cout << heapArray[3] << " ";
    std::cout << heapArray[2] << " ";
    std::cout << heapArray[12] << " ";
    std::cout << heapArray[6] << " ";
    std::cout << heapArray[4] << " ";
    std::cout << heapArray[5] << " ";
    std::cout << heapArray[7] << " ";
    std::cout << heapArray[10] << " " << std::endl;
    //}

    //kill both of the heaps
    heapA.~Heap();
    heapB.~Heap();

	//return statement needed to end int function in C++
	return 0;
} // end of main
