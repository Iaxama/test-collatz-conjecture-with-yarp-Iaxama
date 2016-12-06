#ifndef COLLATZ_CONJECTURE_CLIENT_H
#define COLLATZ_CONJECTURE_CLIENT_H

#include <yarp/os/all.h>
#include <vocabs.hpp>
#include <ClientIDLInterface.h>
class Client : public yarp::os::RFModule, ClientIDLInterface{
private:

    yarp::os::RpcServer commandPort;
    std::string commandPortName;
    yarp::os::RpcClient clientPort;
    std::string clientPortName;
    int n;
    int t;
    bool autoTrigger;
    double period;
    double collatz_test(int n, int t);

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();
    double getPeriod();

    //Thrift methods
    bool sendRequest();
    bool autoSendRequest(double period);
    bool stopSendRequest();
};

#endif //COLLATZ_CONJECTURE_CLIENT_H
