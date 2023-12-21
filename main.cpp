#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class temp{
    string username,password,email;
    string searchname,searchpass,searchemail;
    fstream storage_file;

    public:
    void login();
    void signup();
    void forgot_password();
};


int main(){
    char choice;

    cout<<"/----------------------------------------------/"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Sign-Up"<<endl;
    cout<<"3. Forgot Password"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"/----------------------------------------------/"<<endl<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    temp obj;

    switch(choice){
        case '1':
            obj.login();
        break;

        case '2':
            obj.signup();
        break;

        case '3':
            obj.forgot_password();
        break;

        case '4':
            return 0;
        break;

        default:
        cout<<"Invalid Selection!!"<<endl;
    }

    return 0;
}

void temp::signup(){
    cout<<"/-------------------Sign-Up-------------------/"<<endl;
    cout<<"Enter your Email: ";
    getline(cin,email);
    cout<<"Enter your username: ";
    getline(cin,username);
    cout<<"Enter your password: ";
    getline(cin,password);

    storage_file.open("loginData.txt", ios::out | ios::app );
    storage_file<<email<<'*'<<username<<'*'<<password<<endl;
    storage_file.close();

    cout<<endl<<"Account created successfully..!!"<<endl<<endl;

}

void temp::login(){
    cout<<"/---------------------Login----------------------/"<<endl;
    cout<<"Enter the username:";
    getline(cin,searchname);
    cout<<"Enter the password:";
    getline(cin,searchpass);

    storage_file.open("loginData.txt", ios::in );
    getline(storage_file,email,'*');
    getline(storage_file,username,'*');
    getline(storage_file,password,'\n');

    while(!storage_file.eof()){
        if(username==searchname){
            if(password==searchpass){
                cout<<endl<<"Login is successful...!!"<<endl;
                cout<<"Username: "<<username<<endl;
                cout<<"Email: "<<email<<endl<<endl;
                return;
            }
            else{
                cout<<endl<<"Password is incorrect..!!"<<endl<<endl;
                return;
            }
        }
        getline(storage_file,email,'*');
        getline(storage_file,username,'*');
        getline(storage_file,password,'\n');
    }
    storage_file.close();
    cout<<endl<<"You don't have an account..!!  Please Sign-Up.."<<endl<<endl;
}

void temp:: forgot_password(){
    cout<<"Enter your user name: ";
    getline(cin,searchname);
    cout<<"Enter your email address: ";
    getline(cin,searchemail);

    storage_file.open("loginData.txt", ios::in );
    getline(storage_file,email,'*');
    getline(storage_file,username,'*');
    getline(storage_file,password,'\n');

    while(!storage_file.eof()){
        if(username==searchname){
            if(email==searchemail){
                cout<<"Your password is: "<<password<<endl;
                return;
            }
        }
        getline(storage_file,email,'*');
        getline(storage_file,username,'*');
        getline(storage_file,password,'\n');
    }
    storage_file.close();

    cout<<endl<<"You don't have an account..!!  Please Sign-Up.."<<endl<<endl;

}