#include <iostream>
#include <fstream>
using namespace std;
int main(){
  // Declare variables to store file and user login data
    string fileuser,inputuser;
    int filepass,inputpass;
    bool found=false;
  // Open employee.txt file to read stored usernames and passwords
    ifstream file("employee.txt");
if(!file){
        cout<<"Error opening file";
        return 0;
    }
    cout<<"EMPLOYEE LOGIN"<<endl;
    cout<<"Enter your username: ";
    cin>>inputuser;
    cout<<"Enter your password: ";
    cin>>inputpass;
    while(file>>fileuser>>filepass){
    if (inputuser==fileuser && inputpass==filepass){
    found=true;
        break; 
    }
}return 0;
}
