#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
template<typename _TP>
struct odd_even:public binary_function<_TP,_TP,bool>
{
    bool operator()(const _TP& x,const _TP& y)const
    { return x % 2 == y; }
};
template<typename InputIterator,typename OutputIterator,typename ElementType,
                    typename Comp>
OutputIterator filter(InputIterator first,InputIterator last,OutputIterator at,ElementType elem,Comp pred)
{
    while((first = find_if(first,last,bind2nd(pred,elem)))!=last)
    {
        *at++ = *first++;
    }
    return at;
}
template<typename ElemType,typename InputIterator>
void writeToFile(InputIterator first,InputIterator last,char *file){
    ofstream outfile(file);
    ostream_iterator<ElemType> out(outfile," ");
    copy(first,last,out);
}
int main(int argc,char ** argv)
{
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    vector<int> vec;
    copy(is,eof,back_inserter(vec));
    vector<int> at;
    filter(vec.begin(),vec.end(),back_inserter(at),1,odd_even<int>());
    writeToFile<int>(at.begin(),at.end(),argv[1]);
    at.clear();
    filter(vec.begin(),vec.end(),back_inserter(at),0,odd_even<int>());
     writeToFile<int>(at.begin(),at.end(),argv[2]);
      at.clear();
    return 0;
}
