#include <iostream>
#include <fstream>

using namespace std;

const int alpha_size = 256;

class node{
public:
    int index;
    node *child[alpha_size]={NULL,};
    node(){
        index = 0;
    }
    node(int index){
        this->index = index;
    }
};

int main(){
    //string text = "mississippi";
    string text = "aaaaaaaaaaaaa";
    ifstream infile;
    infile.open();
    string output = "";
    node root;
    int cur_index = 1;
    for (int i=0;i<alpha_size;i++){
        root.child[i] = new node(cur_index++);
    }
    node* cur_node = &root;
    for (int i=0;i<text.size();i++){
        char c=text[i];
        if(cur_node->child[c] != NULL){
            cur_node = cur_node->child[c];
            continue;
        }
        cout << cur_node->index<<endl;
        output.push_back(((char*)&(cur_node->index))[0]);
        output.push_back(((char*)&(cur_node->index))[1]);
        output.push_back(((char*)&(cur_node->index))[2]);
        output.push_back(((char*)&(cur_node->index))[4]);

        cur_node->child[c] = new node(cur_index++);

        cur_node = root.child[c];    
    }
    if(cur_node != &root){
        cout << cur_node->index<<endl;
        output.push_back(((char*)&(cur_node->index))[0]);
        output.push_back(((char*)&(cur_node->index))[1]);
        output.push_back(((char*)&(cur_node->index))[2]);
        output.push_back(((char*)&(cur_node->index))[4]);
    }
    cout << output <<endl;

    return 0;
}
