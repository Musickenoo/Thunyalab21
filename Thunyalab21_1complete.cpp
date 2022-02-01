#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
    Rect Rat;
    if((R1.x+R1.w) -R2.x >0 ){
        Rat.x = R2.x;
        Rat.w = ((R1.x +R1.w) - R2.x);
        if((R1.x + R1.w) > (R2.x + R2.w)){
           Rat.x = R2.x;
           Rat.w = R2.w;
        }
    }
    else if((R1.x+R1.w) -R2.x <= 0 ){
        Rat.x = 0;
        Rat.w = 0;
    }

    if(R2.y - (R1.y - R1.h) > 0 ){
        Rat.y = R1.y;
        Rat.h = R1.y - (R2.y - R2.h);
        if((R1.y - R1.h) < (R2.y - R2.h) && R1.y > R2.y){
           Rat.y = R2.y;
           Rat.h = R2.h;
        }
    }
    else if(R1.x+R1.w -R2.x <= 0 ){
        Rat.y = 0;
        Rat.h = 0;
    }
    return Rat.w*Rat.h;
}
int main(){
    Rect R1 = {-1,2,6.9,9.6};
    Rect R2 = {0,0,1.2,2.5};
    cout << overlap(R1,R2);
    return 0;
}