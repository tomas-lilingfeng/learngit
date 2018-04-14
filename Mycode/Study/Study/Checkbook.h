#pragma once

#include "checkbook.h"



// checkbook.h - A class for a checkbook

class Checkbook
{
public:
	void setBalance( float amount );
	bool writeCheck( float amount );  // returns false if amount is greater than balance;
									  // otherwise returns true
	void deposit( float amount );
	float getBalance(  );
	float getLastCheck( );
	float getLastDeposit( ); 
private:
	float balance;
	float lastCheck;
	float lastDeposit;
};



