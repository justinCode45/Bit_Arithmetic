//�ۻs�[�k��V2
//-------------
//�@��:���fޱ
//-------------
//�{�b�i�H�p��t��
//�i�H�p���k�F
//���ؤF�@��32bit���G�i����ܾ�
#include <string>
int adder(int a,int b){
    //���i����[�k��
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
    
    std::cout << "�G�i��=>" << bin << "\n";
    
}
