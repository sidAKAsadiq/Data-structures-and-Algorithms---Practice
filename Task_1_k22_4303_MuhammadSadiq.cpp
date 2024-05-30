#include "Implementation_of_set_details.cpp"
#include "Implementation_of_print_details.cpp"
#include "class_Bank_account.h"
main(){
Bank_account b(100);
b.debit();
b.credit();
b.transaction();
b.transaction();
}