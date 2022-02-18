#pragma once
#ifndef CUST_H_
#define CUST_H_

#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct _Customer {
	uint32_t acc_num;
	char comp_name[MAX_SIZE];
	char contact_name[MAX_SIZE];
	char contact_num[11];
	uint32_t amt_due;
	uint32_t amt_paid;
	char last_date_paid[MAX_SIZE];

	struct Customer* left;
	struct Customer* right;
}Customer;

// funtions
// add bill, add paid, add credit
// alt account
// Setters
void setAccNum(uint32_t num);
void setCompName(char* name);
void setContactName(char* name);
void setContactNum(char* num);
void setAmtDue(uint32_t num);
void setAmtPaid(uint32_t num);
void setLastDatePaid(char* date);

// Getters
uint32_t getAccNum();
char* getCompName();
char* getContactName();
char* getContactNum();
uint32_t getAmtDue();
uint32_t getAmtpaid();
char* getLastDatePaid();

// Gets difference between due and paid
uint32_t getCurrTotal();

// Search
struct Customer* searchByAccNum(struct Customer* root, uint32_t num);
struct Customer* searchByCompName(struct Customer* root, char* name);

// List bills
void printCustBill(struct Customer* cust);
void printAllBill(struct Customer* root);

// Add customer
bool addAcc(struct Customer* root);

// Remove customer
bool removeAcc(struct Customer* root, uint32_t acc);

// Add bill
void addBill(uint32_t num);

// Add paid
void addPaid(uint32_t num);
#endif