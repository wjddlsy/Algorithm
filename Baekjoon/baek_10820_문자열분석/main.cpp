#include <iostream>

using namespace std;

int arr[100][4];
int main() {
    char c;
    int n=0;
    while(c=getchar()){
        if(c>='a' && c<='z') arr[n][0]++;
        else if(c>='A'&&c<='Z') arr[n][1]++;
        else if(c>='0' && c<='9') arr[n][2]++;
        else if(c==' ') arr[n][3]++;
        else if(c=='\n'){
            n++;
        }
        else if(c==EOF)
            break;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}