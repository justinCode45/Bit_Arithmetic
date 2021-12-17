//自製位元四則運算V4
//-------------
//作者:陳柏瑄
//-------------
#include <iostream>
using namespace std;

int adder(int a, int b);
int subtractor (int a,int b);
int multiplier( int a,int b);
int division(int a,int b);
void show_binary( int dec ,int bit);


//32bit全加法器
//計算範圍: 32bit 整數
int adder(int a,int b){
    if(b==1){
        //單純加1 
        int m=1;
        while(a&m){
            a=a^m;
            m<<=1;
        }
        a = a^m;
        return a;
    }
    int ans=0;
    int power=0;
    int cin=0;
    while (power<32 ){
        int am =a&1;
        int bm =b&1;
        if ((am^bm^cin)!=0){
            ans=(ans|(1<<power));
        }
        cin= (am&bm|(am^bm)&cin);
        a>>=1;
        b>>=1;
        int m=1;
        while(power&m){
            power=power^m;
            m<<=1;
        }
        power = power^m;
    }
    return ans;
}
//減法器a-b
//計算範圍: 32bit 整數
int subtractor (int a,int b){
    b=adder((~b),1);
    int ans=adder(a,b);
    return ans;
}
//乘法器
//計算範圍: 32bit 整數
int multiplier( int m,int r){
//採用Booth's multiplication algorithm
//參考資料https://www.rlacollege.edu.in/pdf/computer/wk1online-boothsalg.pdf
    int ans[2];
    int pLBS=0;
    ans[0]=0;
    ans[1]=r;
    for(int i=0 ;i<32 ;i=adder(i,1)){
        if(pLBS!=(ans[1]&1)){
            if(pLBS==0){
                ans[0]=subtractor(ans[0],m);
            }else{
                ans[0]=adder(ans[0],m);
            }
        }
        pLBS=ans[1]&1;
        ans[1]>>=1;
        if(ans[0]&1){
           ans[1]=(ans[1]|(1<<31));
        }else{
            ans[1]=(ans[1]&~(1<<31));
        }
        ans[0]>>=1;
    }
    return ans[1];
}


//除法器
//a/b
int division(int a,int b){
    int q_singed =(a>0&&b>0)||(a<0&&b<0)? 0:1;
    a= a>0? a :adder((~a),1);
    b= b>0? b :adder((~b),1);
    int ans=0;
    while(a>0){
        a=subtractor(a,b);
        if(a<0){
            break;
        }
        ans=adder(ans,1);
    }
    if(q_singed){
        ans=adder((~ans),1);
    }
    return ans;
}
//模除
//a%b
int modulo(int a,int b){
    int n=division(a,b);
    int r= subtractor(a,multiplier(b,n));
    return r;
}


//二進為顯示器 
//dec:目標數字
//bit:位元數
void show_binary( int dec ,int bit){  
    string bin;
    for(int i=0 ;i<bit;i++ ) {
        if(dec%2==0) bin.insert( bin.begin( ), '0' );
        else bin.insert( bin.begin( ), '1' );    
        dec >>= 1;
    }
    cout  << bin ;    
}

