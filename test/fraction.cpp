#include <iostream> 
using namespace std;

//main 函数 
int main(){
    int zi,mu,ini_num = 0;
    int new_beichushu = 0;
    int zhengshu = 0;     //分子，分母 ，余数 
    cin>>zi>>mu;
    new_beichushu = zi;    //被除数为分子 
    int arr[100000],shang[100000];    //临时存储
    for(int i = 0;i<100000;i++){ arr[i] = -1; shang[i] = 0; }    //初始化
    if (mu == 0) {
        cout<<"0.0";
        return 0;
    }
    zhengshu = zi / mu;
    if(zhengshu > 0) {
        new_beichushu = zi % mu;
        if (new_beichushu == 0) {
            cout<<zhengshu<<".0";
            return 0;
        }
    }
    while(new_beichushu != 0 && arr[new_beichushu] == -1) {    //当被除数等于0的时候，表示已经除尽了 
        arr[new_beichushu] = ini_num;    //如果商中出现相同数组下标 ，此处为之后判断做出依据 
        new_beichushu = new_beichushu * 10; //除法规则 
        ini_num++;
        shang[ini_num] = new_beichushu / mu;    //整除存储商 
        new_beichushu = new_beichushu % mu;    //得到余数 
    }
    
    //输出 
    cout<<zhengshu<<".";
    if(new_beichushu != 0){
        for(int i = 1;i<=arr[new_beichushu];i++){ cout<<shang[i]; }
        cout<<"(";
        for(int i=arr[new_beichushu]+1;i<=ini_num;i++){ cout<<shang[i]; }
        cout<<")";
    }
    else{
        for(int i=1;i<=ini_num;i++){ cout<<shang[i]; }
    }
    return 0;
}