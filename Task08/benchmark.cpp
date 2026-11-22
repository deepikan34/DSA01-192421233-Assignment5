#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <chrono>
#include <stdexcept>
#include <cstdlib>
struct OP{double consultation,tests; double total()const{return consultation+tests;}};
struct IP{double days,rate,procedure; double total()const{return days*rate+procedure;}};
struct Tagged{int type;double a,b,c;};
using V=std::variant<OP,IP>;
volatile double sink=0;
template<class F> long long timed(F f){auto s=std::chrono::steady_clock::now();sink+=f();return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-s).count();}
int main(int argc,char**argv){std::size_t n=argc>1?std::strtoull(argv[1],nullptr,10):1000000;std::vector<OP> ops;std::vector<IP> ips;std::vector<Tagged> tags;std::vector<V> vars;ops.reserve(n);ips.reserve(n);tags.reserve(n);vars.reserve(n);for(std::size_t i=0;i<n;++i){if(i%2){IP x{3,2500,40000};ips.push_back(x);tags.push_back({1,3,2500,40000});vars.emplace_back(x);}else{OP x{500,1200};ops.push_back(x);tags.push_back({0,500,1200,0});vars.emplace_back(x);}}
 auto tv=timed([&]{double s=0;for(auto&x:ops)s+=x.total();for(auto&x:ips)s+=x.total();return s;});
 auto ts=timed([&]{double s=0;for(auto&x:tags)s+=(x.type==0?x.a+x.b:x.a*x.b+x.c);return s;});
 auto tvar=timed([&]{double s=0;for(auto&x:vars)s+=std::visit([](auto const&v){return v.total();},x);return s;});
 std::cout<<"Bills: "<<n<<"\nVirtual-like typed containers us: "<<tv<<"\nTagged switch us: "<<ts<<"\nstd::variant visit us: "<<tvar<<"\nAll totals are accumulated; sink="<<sink<<"\n";
}
