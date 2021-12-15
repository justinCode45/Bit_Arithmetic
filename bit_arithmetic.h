//自製加法器V2
//-------------
//作者:陳柏瑄
//-------------
//現在可以計算負數
//可以計算減法了
//(32bit以內)
//附贈了一個32bit有號數的二進制顯示器
#include <string>
int adder(int a,int b){
    //串行進位全加法器
    int ans=0;
    int cin=0;
    int power=0;
    
    while (power<32 ){
        int am =a%2>0 ? a%2 :-a%2;
        int bm =b%2>0 ? b%2 :-b%2;
        
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

void show_binary( int dec )
{
    
    
    std::string bin;
    
    for(int i=0 ;i<32;i++ ) {
        if( dec % 2 == 0 ) bin.insert( bin.begin( ), '0' );
        else bin.insert( bin.begin( ), '1' );
        
        dec >>= 1;
    }
    
    std::cout << "二進位=>" << bin << "\n";
    
}
