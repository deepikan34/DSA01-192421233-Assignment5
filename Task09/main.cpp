#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
class Bill{protected:std::string patient;public:explicit Bill(std::string p):patient(std::move(p)){}virtual ~Bill()noexcept=default;virtual double total()const=0;virtual std::string type()const=0;};
class OP:public Bill{double fee;public:OP(std::string p,double f):Bill(std::move(p)),fee(f){if(f<0)throw std::invalid_argument("negative OP fee");}double total()const override{return fee;}std::string type()const override{return "OP";}};
class TelehealthBill:public Bill{double consultation,platform;public:TelehealthBill(std::string p,double c,double f):Bill(std::move(p)),consultation(c),platform(f){}double total()const override{return consultation+platform;}std::string type()const override{return "TELEHEALTH";}};
class Payer{public:virtual ~Payer()=default;virtual double covered(const Bill&)const=0;};
class SelfPay:public Payer{public:double covered(const Bill&)const override{return 0;}};
class CorporatePayer:public Payer{double rate;public:explicit CorporatePayer(double r):rate(r){}double covered(const Bill&b)const override{return b.total()*rate/100.0;}};
int main(){try{std::vector<std::unique_ptr<Bill>> bills;bills.push_back(std::make_unique<OP>("Ravi",1700));bills.push_back(std::make_unique<TelehealthBill>("Latha",900,100));CorporatePayer corporate(70);SelfPay self;for(const auto&b:bills)std::cout<<b->type()<<" total="<<b->total()<<" corporate="<<corporate.covered(*b)<<" selfpay-covered="<<self.covered(*b)<<'\n';}catch(const std::exception&e){std::cerr<<"Billing failure: "<<e.what()<<'\n';return 1;}catch(...){std::cerr<<"Unknown billing failure\n";return 2;}}
