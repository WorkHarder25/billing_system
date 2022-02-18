#include "customer.h"
#include <string.h>

// Setters - can be used to alter accounts as well
void setAccNum(struct Customer *cust, uint32_t num)
{
	cust->acc_num = num;
}

void setCompName(struct Customer *cust, char* name)
{
	strcpy(cust->comp_name, name);
}

void setContactName(struct Customer* cust, char* name)
{
	strcpy(cust->contact_name, name);
}

void setContactNum(struct Customer* cust, char* num)
{
	strcpy(cust->contact_num ,num);
}

void setAmtDue(struct Customer* cust, uint32_t num)
{
	cust->amt_due = num;
}

void setAmtPaid(struct Customer* cust, uint32_t num)
{
	cust->amt_paid = num;
}

void setLastDatePaid(struct Customer* cust, char* date)
{
	strcpy(cust->last_date_paid, date);
}

// Getters
uint32_t getAccNum(struct Customer* cust)
{
	return cust->acc_num;
}

char* getCompName(struct Customer* cust)
{
	return cust->comp_name;
}

char* getContactName(struct Customer* cust)
{
	return cust->contact_name;
}

char* getContactNum(struct Customer* cust)
{
	return cust->contact_num;
}

uint32_t getAmtDue(struct Customer* cust)
{
	return cust->amt_due;
}

uint32_t getAmtpaid(struct Customer* cust)
{
	return cust->amt_paid;
}

char* getLastDatePaid(struct Customer* cust)
{
	return cust->last_date_paid;
}

// Gets difference between due and paid
uint32_t getCurrTotal(struct Customer* cust)
{
	return cust->amt_due - cust->amt_paid;
}

// Search
struct Customer* searchByAccNum(struct Customer* root, uint32_t num)
{
	// tree is orginized by acc num
	if (root == NULL || root->acc_num == num)
		return root;

	if (root->acc_num < num)
		return searchByAccNum(root->right, num);

	return searchByAccNum(root->left, num);

}

struct Customer* searchByCompName(struct Customer* root, char* name)
{
	// Since tree is orginized by acc num, use in-order traversal to search by name
	if (root == NULL || !strcmp(root->comp_name, name))
		return root;

	searchByCompName(root->left, name);
	searchByCompName(root->right, name);

}

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
