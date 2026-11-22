#include <iostream>
#include <chrono>
#include <stdexcept>
#include <vector>
#include <cstdlib>
volatile long long sinkCount=0;
template<class F> long long measure(F f){auto a=std::chrono::steady_clock::now();f();return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-a).count();}
int main(int argc,char**argv){int n=argc>1?std::atoi(argv[1]):1000000;for(int pct:{0,1,50}){std::vector<int> values(n,100);for(int i=0;i<n*pct/100;++i)values[i]=-1;auto rc=measure([&]{long long ok=0;for(int x:values){if(x<0)continue;++ok;}sinkCount+=ok;});auto ex=measure([&]{long long ok=0;for(int x:values){try{if(x<0)throw std::invalid_argument("bad");++ok;}catch(const std::invalid_argument&){} }sinkCount+=ok;});std::cout<<pct<<"% invalid: return-code us="<<rc<<", exception us="<<ex<<'\n';}}
