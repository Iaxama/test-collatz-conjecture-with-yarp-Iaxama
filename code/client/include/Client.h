#ifndef COLLATZ_CONJECTURE_CLIENT_H
#define COLLATZ_CONJECTURE_CLIENT_H

#include <yarp/os/all.h>
#include <vocabs.hpp>
#include <ClientIDLInterface.h>
class Client : public yarp::os::RFModule, ClientIDLInterface{
private:

    yarp::os::Port rpcPort;
    std::string rpcPortName;
    yarp::os::RpcClient clientPort;
    std::string clientPortName;
    int testOutcome;
    int n;
    int t;
    void collatz_test(int n, int t);

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();

    //Thrift methods
    void sendRequest();
};

#endif //COLLATZ_CONJECTURE_CLIENT_H
