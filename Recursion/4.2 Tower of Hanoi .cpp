#include <iostream>
using namespace std;

void towerOfHanoi(int n,char from,char use,char to){

    if(n==1){
        cout<<n<<" : "<<from<<" --> "<<to<<endl;
        return;
    }

    towerOfHanoi(n-1,from, to, use);

    cout<<n<<" : "<<from<<" --> "<<to<<endl;

    towerOfHanoi(n-1,use, from, to);

}

int main(){
    int n;
    cout<<"enter ring: ";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}
