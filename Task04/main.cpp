#include <iostream>
#include <stdexcept>
#include <string>
class BillingError:public std::runtime_error{public:using std::runtime_error::runtime_error;};
class InvalidChargeError:public BillingError{public:using BillingError::BillingError;};
class ClaimError:public BillingError{public:using BillingError::BillingError;};
class UnknownPackageError:public BillingError{public:using BillingError::BillingError;};
class MissingPatientError:public BillingError{public:using BillingError::BillingError;};
void validateCharge(double x){if(x<0)throw InvalidChargeError("negative charge");}
int main(){for(double x:{100.0,-5.0})try{validateCharge(x);std::cout<<"valid\n";}catch(const BillingError& e){std::cout<<"billing error: "<<e.what()<<'\n';}}
