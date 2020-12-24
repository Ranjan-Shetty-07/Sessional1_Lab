#include<stdlib.h>
#include<stdint.h>
#include "appConstants.h"
#include "MMB.h"
#include <string.h>

Bank new_bank(){
    Bank b1 = {{0},0000,0,0,0,0,0};
    return b1;
}

Customer*  new_customer(char name[],int8_t age,char pan[],int8_t acc_type,uint32_t phone_no,int32_t init_deposit ){
    Customer *new_cust ;
    strcpy (new_cust->name , name);
    new_cust->age = age;
    strcpy(new_cust->pan,pan);
    new_cust->acc_type = acc_type;
    new_cust->phone_no = phone_no;
    new_cust->init_deposit = init_deposit;
    new_cust->acc_no[12] = 0;
    new_cust->credit_count = 0;
    new_cust->debit_count = 0;
    return new_cust;
}

void add_customer(Customer *cust,Bank *bank){

    //cust->acc_no[ACC_LEN] = strcat(strcat("110001","0") , strcat((char)cust->acc_type,(char)bank->cust_count) );

    bank->cust_count++;
    bank->cust[bank->cust_count] = *cust;

    switch(cust->acc_type){
    case SB:
        bank->sb_count++;
        break;
    case CURR:
        bank->curr_count++;
        break;
    case SALARY:
        bank->salary_count++;
        break;
    case JOINT:
        bank->joint_count++;
        break;
    case STUD:
        bank->student_count++;
        break;
    default:
        break;

    }
}

TransStatus credit(Customer *cust , int32_t amount){

    TransStatus *status;
    printf("HEre %d",cust->init_deposit);
    cust->init_deposit = cust->init_deposit + amount;

    status->balance = cust->init_deposit;
    status->status[S_LEN] = "OK";
    return *status;
}

TransStatus debit(Customer *cust , int32_t amount){
    TransStatus *status;
    if(cust->acc_type == STUD && cust->debit_count <= 10){
        if(cust->init_deposit >= amount){
            cust->init_deposit = cust->init_deposit - amount;
            status->balance = cust->init_deposit;
            status->status[S_LEN] = "OK";
            cust->debit_count++;
            return  *status;
        }
        else{
            status->balance = cust->init_deposit;
            status->status[S_LEN] = "Insufficent Balance";
            return  *status;
        }
    }
    else{
        if(cust->acc_type != STUD && cust->debit_count <= 5){
                if(cust->init_deposit >=2000 && cust->init_deposit >= amount ){
                    cust->init_deposit = cust->init_deposit - amount;
                    status->balance = cust->init_deposit;
                    status->status[S_LEN] = "OK";
                    cust->debit_count++;
                    return  *status;
                }
                else{
                    cust->init_deposit = cust->init_deposit - 1000;
                    status->balance = cust->init_deposit;
                    status->status[S_LEN] = "Insufficent Balance";
                    return  *status;
                }
            }
        status->balance = cust->init_deposit;
        status->status[S_LEN] = "Transaction count Exceeds";
        return  *status;
    }
}

TransStatus balance(Customer *cust ){
    TransStatus *status;
    status->balance = cust->init_deposit;
    status->status[S_LEN] ="OK";
    return *status;
}
int32_t count_credit(Customer *cust ){
    return cust->credit_count;
}
int32_t count_debit(Customer *cust){
    return cust->debit_count;
}
int32_t cust_count(Bank *bank){
    return bank->cust_count;
}
int32_t cust_count_type(Bank *bank,int8_t acc_type){
    switch(acc_type){
    case SB:
        return bank->sb_count;
        break;
    case CURR:
        return bank->curr_count;
        break;
    case SALARY:
       return bank->salary_count;
        break;
    case JOINT:
        return bank->joint_count;
        break;
    case STUD:
        return bank->student_count;
        break;
    default:
        break;
}

}

