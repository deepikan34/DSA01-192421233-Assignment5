#include <iostream>
#include <memory>
#include <string>
class Bill { public: virtual ~Bill()=default; virtual double total() const=0; virtual std::string type() const=0; };
class OP : public Bill { double amount; public: explicit OP(double a):amount(a){} double total()const override{return amount;} std::string type()const override{return "OP";} };
class Payer { public: virtual ~Payer()=default; virtual double amountCovered(const Bill&)const=0; };
class SelfPay:public Payer { public: double amountCovered(const Bill&)const override{return 0;} };
class Insurance:public Payer { double limit,copay; public: Insurance(double l,double c):limit(l),copay(c){} double amountCovered(const Bill& b)const override{return std::min(limit,b.total()*(1.0-copay/100.0));} };
class GovernmentScheme:public Payer { double opPackage; public: explicit GovernmentScheme(double p):opPackage(p){} double amountCovered(const Bill& b)const override{return b.type()=="OP"?std::min(opPackage,b.total()):0;} };
class CorporatePayer:public Payer { double rate; public: explicit CorporatePayer(double r):rate(r){} double amountCovered(const Bill& b)const override{return b.total()*rate/100.0;} };
int main(){ OP bill(5000); SelfPay self; Insurance ins(4000,20); GovernmentScheme gov(3000); CorporatePayer corp(70); std::cout<<"SelfPay covered: "<<self.amountCovered(bill)<<'\n'<<"Insurance covered: "<<ins.amountCovered(bill)<<'\n'<<"Government covered: "<<gov.amountCovered(bill)<<'\n'<<"Corporate covered: "<<corp.amountCovered(bill)<<'\n'; }
