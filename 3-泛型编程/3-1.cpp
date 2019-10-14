#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
map<string,int> ma;
set<string> se;
void insertToMap(const string& s){
    if(s.empty() || se.find(s) != se.end()) return;
    ++ma[s];
}
void display(){
    map<string,int>::iterator it = ma.begin();
    while(it != ma.end()){
        cout << it->first << ": " << it->second << endl;
        ++it;
    }
}
void solve(char *file){
    se.insert("a"),se.insert("an"),se.insert("or"),se.insert("the"),
    se.insert("and"),se.insert("but");
    fstream in(file,ios_base::in);
    string s;
    stringstream str(in);
    char ch;
    while(in.get(ch)){
        if(isalpha(ch) || isalnum(ch)) s += ch;
        else{
            insertToMap(s);
            s.clear();
        }
    }
    if(!s.empty()){
        insertToMap(s);
        s.clear();
    }
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