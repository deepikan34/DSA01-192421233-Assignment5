#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(std::string p) : patient(std::move(p)) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
    void print() const { std::cout << type() << ' ' << patient << ": " << total() << '\n'; }
};
class OutPatientBill : public Bill {
    double consultation, tests;
public:
    OutPatientBill(std::string p,double c,double t):Bill(std::move(p)),consultation(c),tests(t){}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OP"; }
};
class InPatientBill : public Bill {
    int days; double perDay, procedure, medicines;
public:
    InPatientBill(std::string p,int d,double r,double proc,double med):Bill(std::move(p)),days(d),perDay(r),procedure(proc),medicines(med){}
    double total() const override { return days*perDay + procedure + medicines; }
    std::string type() const override { return "IP"; }
};
class DayCareBill : public Bill {
    double packagePrice;
public:
    DayCareBill(std::string p,double price):Bill(std::move(p)),packagePrice(price){}
    double total() const override { return packagePrice; }
    std::string type() const override { return "DAYCARE"; }
};
class EmergencyBill : public Bill {
    double base; int minutes; double perMinute;
public:
    EmergencyBill(std::string p,double b,int m,double r):Bill(std::move(p)),base(b),minutes(m),perMinute(r){}
    double total() const override { return base + minutes*perMinute; }
    std::string type() const override { return "ER"; }
};
int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatientBill>("Ravi",500,1200));
    bills.push_back(std::make_unique<InPatientBill>("Meena",3,2500,40000,1500));
    bills.push_back(std::make_unique<DayCareBill>("Asha",18000));
    bills.push_back(std::make_unique<EmergencyBill>("Kumar",2000,30,100));
    double sum=0;
    for (const auto& b:bills) { b->print(); sum+=b->total(); }
    std::cout << "Day total: " << sum << '\n';
}
