//
//  main.cpp
//  baek_2448
//
//  Created by 윤정인 on 2018. 6. 26..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

char arr[3072][6144]; // 배열에 넣어서 출력하기..
char star[3][5]={ {' ',' ', '*', ' ', ' '} ,
    {' ','*',' ','*', ' '},
    {'*','*','*','*','*'}
};

void basic(int n){
    
    
    for (int i=0; i<3; ++i){
        for(int k=0; k<n; ++k){
            std::cout << " ";
        }
        for (int j=0; j<5; ++j){
            std::cout << star[i][j];
            for(int l=n; l>0; l/=2){
                std::cout<<" ";
            }
            std::cout << star[i][j];
        }
        std::cout<< std::endl;
        
        
    }
}
void print(int n, int x, int y){
    
    if(n==3){
        arr[y][x]='*';
        arr[y+1][x-1]='*';
        arr[y+1][x+1]='*';
        arr[y+2][x-2]='*';
        arr[y+2][x-1]='*';
        arr[y+2][x]='*';
        arr[y+2][x+1]='*';
        arr[y+2][x+2]='*';
        return;
        
    }
    
    print(n/2, x, y);
    print(n/2, x-(n/2), y+(n/2));
    print(n/2, x+(n/2), y+(n/2));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<2*n; j++){
            if (j==2*n-1)
                arr[i][j]='\0';
            else
                arr[i][j]=' ';
        }
    }
    
    print(n, n-1, 0);
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<2*n-1; j++){
            std::cout << arr[i][j];
        }
        std::cout<<std::endl;
    }
    
}
