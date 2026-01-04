#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string fileuser,inputuser;
    int filepass,inputpass;
    bool found=false;
  // Open employee file for reading
    ifstream file("employee.txt");
if(!file){
        cout<<"Error opening file";
        return 0;
    }
    cout<<"EMPLOYEE LOGIN"<<endl;
    // Take username and password from user
    cout<<"Enter your username: ";
    cin>>inputuser;
    cout<<"Enter your password: ";
    cin>>inputpass;
    // Compare input credentials with file data
    while(file>>fileuser>>filepass){
    if (inputuser==fileuser && inputpass==filepass){
    found=true;
        break; 
        // stops the loop immediately
    }
}return 0;
}
