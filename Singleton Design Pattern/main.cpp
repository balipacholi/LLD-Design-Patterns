#include <iostream>

using namespace std;

class PaymentGatewayManager
{
private:
	// define constructor as private so that no one can create object of it.
	PaymentGatewayManager()
	{
		cout << "Payment Gateway manager Initializd" << endl;
	}

	// create a private static instance variable of the class
	static PaymentGatewayManager *instance;

	// Add mutex lock so that no 2 threads in mutithreading environment can create the singleton instance at the same time.
	static mutex mtx;

public:
	// create a public static method to get the instance of the class
	static PaymentGatewayManager *getInstance()
	{
		if (instance == nullptr)
		{ // as locks are expensive operations Hence, adding double nullptr check
			mtx.lock();
			if (instance == nullptr)
			{
				instance = new PaymentGatewayManager();
			}
			mtx.unlock();
		}
		return instance;
	}

	void processPayment(double amount)
	{
		cout << "Processing payment of $" << amount << " " << "through the payment gateway" << endl;
	}
};

// as it is static no need to create object of it
PaymentGatewayManager *PaymentGatewayManager::instance = NULL;

mutex PaymentGatewayManager::mtx;

int main()
{
	PaymentGatewayManager *pgm = PaymentGatewayManager::getInstance();
	pgm->processPayment(100);

	PaymentGatewayManager *pgm1 = PaymentGatewayManager::getInstance();

	// check if both the instance are the same, as instance should only be instatiated once.
	if (pgm == pgm1)
	{
		cout << "both instance is same" << endl;
	}
	else
	{
		cout << "Singleton Design Pattern is not working correctly" << endl;
	}

	return 0;
}