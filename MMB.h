#ifndef MMB_H_INCLUDED
#define MMB_H_INCLUDED
#include<stdint.h>
#include"appConstants.h"

typedef struct _bank_ Bank;
typedef struct _customer_ Customer;
typedef struct _trans_stauts_ TransStatus;

struct _customer_{
    char name[NAME_LEN];
    int8_t age;
    char pan[PAN_LEN];
    int8_t acc_type;
    uint32_t phone_no;
    int32_t init_deposit;
    char acc_no[ACC_LEN];
    int8_t credit_count;
    int8_t debit_count;
};

struct _bank_{
    Customer cust[BANK_SIZE];
    int32_t cust_count;
    int32_t sb_count;
    int32_t student_count;
    int32_t joint_count;
    int32_t salary_count;
    int32_t curr_count;
};



struct _trans_stauts_{
    int32_t balance;
    char status[50];
};

Bank new_bank();
Customer* new_customer(char name[],int8_t age,char pan[],int8_t acc_type,uint32_t phone_no,int32_t init_deposit);
void add_customer(Customer *cust,Bank *bank);
TransStatus credit(Customer *cust , int32_t amount);
TransStatus debit(Customer *cust , int32_t amount);
TransStatus balance(Customer *cust );
int32_t count_credit(Customer *cust );
int32_t count_debit(Customer *cust);

int32_t cust_count(Bank *bank);
int32_t cust_count_type(Bank *bank , int8_t acc_type);


#endif // MMB_H_INCLUDED
