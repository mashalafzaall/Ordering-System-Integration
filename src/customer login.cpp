#include <iostream>
#include <fstream>
using namespace std;
int main(){
     ifstream in("orders.txt");   // Open the file orders.txt for reading

    int customerpass,itemnum,quantity,bill;
    string cutomeruser;// Variable to store customer username

    while(in>>cutomeruser>>customerpass>>itemnum>>quantity>>bill){
    cout<<" "<<cutomeruser<<" "<<customerpass<<" "<<itemnum<<" "<<quantity<<" "<<bill<<endl;
    }
   in.close();
    return 0;
}
