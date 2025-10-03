//
// Created by Quinn on 10/3/2025.
//

#include <iostream>
#include <ctime>
#include <chrono>

#include "Transaction.h"

Transaction::Transaction(string newType, double newAmount) {
	// This will make a new Transaction object and it will get the current system time and date and set that to the timestamp
	type = newType;
	amount = newAmount;

	chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	time_t time_now = chrono::system_clock::to_time_t(now);
	tm* local_tm = localtime(&time_now);
	char buffer[80];
	strftime(
		buffer,
		sizeof(buffer),
		"%m/%d/%Y %I:%M %p",
		local_tm
	);

	timestamp = buffer;
}
