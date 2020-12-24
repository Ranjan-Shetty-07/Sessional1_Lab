#include <stdio.h>
#include <stdlib.h>
#include "MMB.h"
#include<assert.h>
#include<stdint.h>
#include "appConstants.h"
#include<string.h>

void test(){
    Bank newBank = new_bank();
    assert(newBank.cust_count == 0000);

    Customer *newCust = new_customer("Ranjan",23,"jnbdk23",2,12323443,1000);
    assert(strcmp( newCust->name , "Ranjan") == 0);

    add_customer(&newCust , &newBank);
    assert(newBank.cust_count == 1);

    TransStatus *status;
    *status = credit(newCust , 200);
    assert(status->balance == 1800);

}
int main()
{
    printf("Hello world!\n");
    test();
    return 0;
}
