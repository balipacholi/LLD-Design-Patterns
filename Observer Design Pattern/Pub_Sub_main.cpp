#include <iostream>
#include <list>
#include <string>

using namespace std;

//Subscriber Interface
class ISubscriber {
    public:
       virtual void notify(std::string message) = 0;
};

class User : public ISubscriber {
    private:
        int userID;
    public:
       User(int userID) {
          this->userID = userID;
       }
    
     //Implementing notify function
     void notify(std::string message) override {
        cout << "User " << userID << "received message: " << message <<endl;
     }

};

class Group {
    private:
        list<ISubscriber*> subscribers;
    public:
        void subscribe (ISubscriber* subscriber){
            subscribers.push_back(subscriber);
        }

        void unsubscribe (ISubscriber* subscriber){
            subscribers.remove(subscriber);
        }

        void notify(std::string message){
            for(auto subsriber : subscribers){
                subsriber->notify(message);
            }
        }
};

int main(){
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);


    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("Hello to all Users!");

    group->unsubscribe(user1);

    group->notify("Hello to remaining Users!");


    return 0;
}