#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BinaryTree {
    
public:
    string data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(string s){
        data = s;
        left = NULL;
        right = NULL;
    }
    void input(string s);
    void output();
};
void BinaryTree::input(string s){
    if(data == s) return;
    else if(data < s) {
        if( right != NULL ) right->input(s);
        else {
            right = new BinaryTree(s);
        }

    } 
    else if (s < data) {
        if( left != NULL ) left->input(s);
        else {
            left = new BinaryTree(s);
        }
            
    }
}
void BinaryTree::output(){
    if(left == NULL && right == NULL) return;
    cout << "parent : " << data << endl;
    cout << "  child : ";
    if( left != NULL) cout << left->data << " ";
    if( right != NULL) cout << right->data << " ";
    cout << endl;
        
    if(left != NULL) left->output();
    if(right != NULL)right->output();
    return;
}

int main(void){
    string s;
    vector <string> words;
    
    while( cin >> s ){
        words.push_back(s);
    }
    BinaryTree *bt = new BinaryTree(words[0]);

    for(int i=1;i<words.size();i++) {
        bt->input(words[i]);
    }
    
    bt->output();
    
    return 0;
}
