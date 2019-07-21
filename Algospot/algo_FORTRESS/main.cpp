#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x[100], y[100], r[100];
struct TreeNode{
    vector<TreeNode*> children;
};

int longest;

//root를 루트로하는 서브트리의 높이 반환
int height(TreeNode *root){
    vector<int> heights;
    for(int i=0; i<root->children.size(); ++i){
        heights.push_back(height(root->children[i]));
    }
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    if(heights.size()>=2){
        longest=max(longest, 2+heights[heights.size()-2]+heights[heights.size()-1]);
    }
    return heights.back()+1;
}

int solve(TreeNode* root){
    longest=0;
    int h=height(root);
    return max(longest, h);
}

bool isInclude(int root, int ch){
    if(r[root]>r[ch]){
        int dist1=(y[root]-y[ch])*(y[root]-y[ch])+(x[root]-x[ch])*(x[root]-x[ch]);
        int dist2=(r[root]-r[ch])*(r[root]-r[ch]);
        if(dist1<dist2)
            return true;
    }
    return false;
}
bool isChild(int root, int ch){
    if(!isInclude(root, ch))
        return false;
    for(int i=0; i<N; ++i){
        if(i!=root && i!=ch && isInclude(root, i) && isInclude(i, ch))
            return false;
    }
    return true;
}
TreeNode *getTree(int root){
    TreeNode *ret=new TreeNode();
    for(int ch=0; ch<N; ++ch){
        if(isChild(root, ch))
            ret->children.push_back(getTree(ch));
    }
    return ret;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N;
        for(int i=0; i<N; ++i){
            cin>>x[i]>>y[i]>>r[i];
        }
        TreeNode *root=getTree(0);
        cout<<solve(root)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}