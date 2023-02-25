#include <string>
#include <iostream>
using namespace std;

string reverse(const string& str,int i=0){
    return i< str.length()?reverse(str,++i)+ str[i]:"";
}


string decode(string& str,int i=0,int index=0){
    if(i>=str.length())
        return str;
    if(str[i]=='(')
        index=i;
    else if(str[i]==')'){
        int range=i-index;
        string reversed=reverse(str.substr(index+1,range-1));
        str=str.substr(0,index)+reversed+str.substr(index+range+1,str.length()-index-range-1);
        return decode(str);
    }
    return decode(str,++i,index);
}

int main3(){
    string test;
    while (test != "N") {
        cin >> test;
        cout << decode(test) << endl;
    }
    return 0;
}