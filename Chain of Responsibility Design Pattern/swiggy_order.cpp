#include <iostream>

using namespace std;

class OrderHandler
{
protected:
    OrderHandler *nextHandler;

public:
    OrderHandler(OrderHandler *nextHandler) : nextHandler(nextHandler) {}
    virtual void processOrder(const string &order) = 0;
};

class OrderValidationHandler : public OrderHandler
{
public:
    OrderValidationHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {}
    void processOrder(const string &order)
    {
        cout << " Validation order: " << order << endl;

        if (nextHandler)
        {
            nextHandler->processOrder(order);
        }
    }
    ~OrderValidationHandler()
    {
        cout << "Validation handler dtor called" << endl;
    }
};

class PaymentProcessingHandler : public OrderHandler
{
public:
    PaymentProcessingHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {}
    void processOrder(const string &order)
    {
        cout << " Payment processing order: " << order << endl;

        if (nextHandler)
        {
            nextHandler->processOrder(order);
        }
    }
    ~PaymentProcessingHandler()
    {
        cout << "Payment Processing dtor called" << endl;
    }
};

class OrderTrackingHandler : public OrderHandler
{
public:
    OrderTrackingHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {}
    void processOrder(const string &order)
    {
        cout << "Order tracking order: " << order << endl;

        if (nextHandler)
        {
            nextHandler->processOrder(order);
        }
    }
    ~OrderTrackingHandler()
    {
        cout << "Order tracking dtor called" << endl;
    }
};

int main()
{

    // creating a chain of responsibility

    OrderHandler *orderProcessingChain = new OrderValidationHandler(new PaymentProcessingHandler(new OrderTrackingHandler(nullptr)));

    string order = "Pizza";
    orderProcessingChain->processOrder(order);

    return 0;
}
