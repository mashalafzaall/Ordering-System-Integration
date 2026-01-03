#include <iostream>
#include <fstream>
using namespace std;
//Employee login authenication with order viewing after successful login
int EmployeeLoginAndViewingOrders() {
    string fileuser,inputuser;
    int filepass,inputpass;
    bool found=false;
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
}
if (found) {
    cout<<"Login successfull"<<endl;
    cout<<"Showing the order list as follow:"<<endl;
     ifstream in("orders.txt");
    int customerpass,itemnum,quantity,bill;
    string cutomeruser;
    while(in>>cutomeruser>>customerpass>>itemnum>>quantity>>bill){
    cout<<" "<<cutomeruser<<" "<<customerpass<<" "<<itemnum<<" "<<quantity<<" "<<bill<<endl;
    }
   in.close();
}
    else{
    cout<<"Login unsuccessfull";
    }
    return 0;
}
//Customer registration integrated with menu based ordering system
int CustomerRegistrationAndOrderingSystem(){
     int customerpass;
    string customeruser;
    cout<<"Enter your username: ";
    cin>>customeruser;
    cout<<"Enter your password: ";
    cin>>customerpass;
    ofstream file("customer.txt",ios::app);
    file<<customeruser<<" "<<customerpass<<" "<<endl;
    file.close();
    cout<<"Registration successful"<<endl;
    int itemnum,quantity,bill;
    int  totalbill=0;
    char choice;
    ofstream out("orders.txt",ios::app);
    do{
        cout<<"The menu is as follow: "<<endl;
    cout<<"1.Burger  Rs.500"<<endl;
     cout<<"2.Pizza  Rs.1500"<<endl;
      cout<<"3.Brownie  Rs.250"<<endl;
       cout<<"4.Wings  Rs.700"<<endl;
        cout<<"5.Icecream  Rs.300\nEnter the item number you want to order: ";
        cin>>itemnum;
        cout<<"Enter the quantity of item you ordered: ";
        cin>>quantity;
    if (itemnum==1){
        bill=(500*quantity);
    }
    else if (itemnum==2){
        bill=(1500*quantity);
    }
    else if (itemnum==3){
        bill=(250*quantity);
    }
    else if (itemnum==4){
        bill=(700*quantity);
    }
    else if (itemnum==5){
        bill=(300*quantity);
    }
    else {
        cout<<"invalid item number";
        return 0;
    }
    totalbill = totalbill+bill;
    out<<" "<<customeruser<<" "<<customerpass<<" "<<itemnum<<" "<<quantity<<" "<<" "<<bill<<endl;
    cout<<"Your one item bill is:Rs "<<bill<<endl;
    cout<<"Do you want to order another item(y/n): ";
    cin>>choice;
    } while(choice== 'y' || choice== 'Y' );
    out.close();
    cout<<"Your total amount to pay is:Rs "<<totalbill<<endl;
    cout<<"Thank you for ordering"<<endl;
    return 0;
}          
int main(){
    int choice;
    cout<<"Ordering system"<<endl;
    cout<<"1.Employee login and viewing ordering list"<<endl;
    cout<<"2.Customer registration and ordering system"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        EmployeeLoginAndViewingOrders();
        break;
        case 2: 
        CustomerRegistrationAndOrderingSystem();
        break;
        case 3: 
        cout<<"Thank You"<<endl;
        break;
        default:
        cout<<"Invalid choice entered"<<endl;
    }
    return 0;
}
