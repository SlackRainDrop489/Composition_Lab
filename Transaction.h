//
// Created by Quinn on 10/3/2025.
//

#ifndef COMPOSITION_LAB_TRANSACTION_H
#define COMPOSITION_LAB_TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;


class Transaction {
	public:
		string type;
		double amount;
		string timestamp;
		Transaction(string type, double amount);
};


#endif //COMPOSITION_LAB_TRANSACTION_H
