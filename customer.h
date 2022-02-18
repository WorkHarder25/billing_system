#pragma once
#ifndef CUST_H_
#define CUST_H_

#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct Customer{
	uint32_t acc_num;
	char comp_name[MAX_SIZE];
	char contact_name[MAX_SIZE];
	char contact_num[11];
	uint32_t amt_due;
	uint32_t amt_paid;
	char last_date_paid[MAX_SIZE];

	struct Customer* left;
	struct Customer *right;
};

// funtions
// Setters - can be used to alter accounts as well
void setAccNum(struct Customer *cust, uint32_t num);
void setCompName(struct Customer *cust, char* name);
void setContactName(struct Customer *cust, char* name);
void setContactNum(struct Customer *cust, char* num);
void setAmtDue(struct Customer *cust, uint32_t num);
void setAmtPaid(struct Customer *cust, uint32_t num);
void setLastDatePaid(struct Customer *cust, char* date);

// Getters
uint32_t getAccNum(struct Customer *cust);
char* getCompName(struct Customer *cust);
char* getContactName(struct Customer *cust);
char* getContactNum(struct Customer *cust);
uint32_t getAmtDue(struct Customer *cust);
uint32_t getAmtpaid(struct Customer *cust);
char* getLastDatePaid(struct Customer *cust);

// Gets difference between due and paid
uint32_t getCurrTotal(struct Customer *cust);

// Search
struct Customer* searchByAccNum(struct Customer *root, uint32_t num);
struct Customer* searchByCompName(struct Customer *root, char* name);

// List bills
void printCustBill(struct Customer *cust);
void printAllBill(struct Customer *root);

// Add customer
bool addAcc(struct Customer *root);

// Remove customer
bool removeAcc(struct Customer *root, uint32_t acc);

// Add bill
void addBill(struct Customer *cust, uint32_t num);

// Add paid
void addPaid(struct Customer *cust, uint32_t num);

// Add credit
void rmvBill(struct Customer *cust, uint32_t num);

#endif
