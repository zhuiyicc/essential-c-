#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vec;
bool cmp(const string& a,const string& b){
    return a.length() < b.length();
}
void display(){
    vector<string>::iterator it = vec.begin();
    while(it != vec.end()){
        cout << *it << endl;
        ++it;
    }
}
void solve(char *file){
    fstream in(file,ios_base::in);
    string s;
    char ch;
    while(in.get(ch)){
        if(isalpha(ch) || isalnum(ch)) s += ch;
        else{
            if(!s.empty()) vec.push_back(s);
            s.clear();
        }
    }
    if(!s.empty()){
        s.clear();
    }
    sort(vec.begin(),vec.end(),cmp);
    display();
}
int main(int argc,char ** argv){
    if(argc < 2){
        printf("need a file to read\n");
        return -1;
    }
    solve(argv[1]);
    return 0;
}
