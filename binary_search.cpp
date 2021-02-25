#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "MT.h"

#define N 5000000
using namespace std;

class BinaryTree {
public:
    long data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(long s){
        data = s;
        left = NULL;
        right = NULL;
    }
    void input(long s);
    void output();
    int search(long s);
};
void BinaryTree::input(long s){
    if(data == s) return;
    else if(data < s) {
        if( right != NULL ) right->input(s);
        else {
            right = new BinaryTree(s);
        }
    } 
    else if (s <= data) {
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
int BinaryTree::search(long s){
    int sw = 0;
    if(data == s) return 1;
    if(left == NULL && right == NULL) return 0;
    
    if(left != NULL && s <= data) sw = left->search(s);
    if(right != NULL && data < s) sw = right->search(s);
    return sw;
}

int main(void){
    vector<long> data;
    clock_t tm1 = clock();
    int search_count = 0;
    
    init_genrand((unsigned)time(NULL));
    
    for (long i1 = 0; i1 < N; i1++) {
	    data.push_back( genrand_int31() );
	  }
    BinaryTree *bt = new BinaryTree(data[0]);

    for(long i=1;i<data.size();i++) {
        bt->input(data[i]);
    }
    
    //bt->output();
    
    clock_t tm2 = clock();
		printf("保存： %d ms\n", (int)(tm2-tm1));
		// データの探索
		for (long i=0; i<data.size(); i++) {
		  if(i%50 == 0 && search_count < 100000) {
  			int sw = bt->search( data[i] );
	  		if (sw == 0) {
		  		printf("***error*** データが見つからない！\n");
			  	exit(1);
			  }
			  search_count ++;
			}
		}
		clock_t tm3 = clock();
		printf("探索： %d ms\n", (int)(tm3-tm2));
	
	delete bt;
	return 0;
}