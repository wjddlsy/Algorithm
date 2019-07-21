#include <iostream>
#include <vector>
#include <deque>

using namespace std;

string gears[1001];
//int gears[4][8];
int starts[1001]={0, };


int T;
void rotate_left(int num, int dir){
    if(num<1)
        return;

    int rotated_gear = (starts[num]+6)%8;
    int left_gear = (starts[num-1]+2)%8;

    if(gears[num][rotated_gear]==gears[num-1][left_gear])
        return;


    rotate_left(num-1, dir*-1);

    if(dir==-1) { //반시계
        starts[num - 1] = (starts[num - 1] + 1) % 8;
    } else{
        starts[num-1]=(starts[num-1]+7)%8;
    }

}


void rotate_right(int num, int dir){
    if(num>=T-1)
        return;

    int rotated_gear = (starts[num]+2)%8;
    int right_gear = (starts[num+1]+6)%8;

    if(gears[num][rotated_gear]==gears[num+1][right_gear])
        return;


    rotate_right(num+1, dir*-1);

    if(dir==-1) {
        starts[num + 1] = (starts[num + 1] + 1) % 8;
    } else{
        starts[num+1]=(starts[num+1]+7)%8;
    }


}

int main() {
    cin >> T;
    for(int i=0; i<T; ++i){
       cin>>gears[i];
    }

    int k, num, dir;
    cin>>k;
    for(int i=0; i<k; ++i){
        cin>>num>>dir;
        num--;

        rotate_left(num, dir*-1);
        rotate_right(num,dir*-1);
        if(dir==-1) {
            starts[num] = (starts[num] + 1) % 8;
        } else{
            starts[num]=(starts[num]+7)%8;
        }
    }

    int ret=0;
    int factor=1;
    for(int i=0; i<T; ++i){
        if(gears[i][starts[i]]=='1'){
            //ret+=(factor);
            ret++;
        }
        factor*=2;
    }

    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}