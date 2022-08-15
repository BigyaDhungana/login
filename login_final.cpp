#include <iostream>
#include <fstream>
#include <string>

using std::string;

void signup();
void login();
bool check_login(string uname,string pswd,string *name);
string separator(string sep);

int i;

int main(){
    string mode;
    std::cout<<"WELCOME"<<std::endl;
    std::cout<<"login or signup?\n->";
    std::cin>>mode;
    if (mode=="login"){
        login();
    }
    else if (mode=="signup"){
        signup();
    }
    else {
        std::cout<<"Invalid"<<std::endl;
    }
}

void signup(){
    string name,username,password,re_password;
    std::cin.ignore();
    std::cout<<"Enter your name:";
    std::getline(std::cin,name);
    std::cout<<"Enter your username:";
    std::cin>>username;
    std::cout<<"Enter your password:";
    std::cin>>password;
    std::cout<<"Re-enter your password:";
    std::cin>>re_password;
    
    if(password==re_password){
        std::ofstream  data_file("data.txt",std::fstream::app);
        data_file<<username<<" "<<password<<" "<<name<<"."<<"\n";
        data_file.close();
        std::cout<<"Sign up successful";
    }
    else{
        std::cout<<"Passwords do not match.Please try again.";
    }    
}

void login(){
    string username,password,name;
    std::cout<<"Enter your username:";
    std::cin>>username;
    std::cout<<"Enter your password:";
    std::cin>>password;
    //checking
    bool isCorrect=check_login(username,password,&name);
    if (isCorrect==true){
        std::cout<<"Login successful"<<std::endl;
        std::cout<<"Welcome "<<name<<std::endl;
    }
    else {
        std::cout<<"Login details do not match"<<std::endl;
    }
    
}

bool check_login(string uname,string pswd,string *name){
    string line,r_username,r_password,f_name,l_name;
    std::ifstream data_file("data.txt");
    while(getline(data_file,line)){
        //std::cout<<line<<std::endl;
        i=0;
        r_username=separator(line);
        r_password=separator(line);
        f_name=separator(line);
        l_name=separator(line);
        
        if (uname==r_username){
            if (pswd==r_password){
                data_file.close();
                *name=f_name+" "+l_name;
                return true;

            }
        }
        
    }
    
    data_file.close();
    return false;
    
}

string separator(string sep){
    string username="";
    do{
        if (sep[i]!=' '){
            username=username+sep[i]; 
        }
        i++;
    }
    while(sep[i]!=' ' && sep[i]!='.');
    return username;
}

