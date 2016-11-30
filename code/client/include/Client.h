#ifndef COLLATZ_CONJECTURE_CLIENT_H
#define COLLATZ_CONJECTURE_CLIENT_H

#include <yarp/os/all.h>
#include <vocabs.hpp>
class Client : public yarp::os::RFModule{
private:

    yarp::os::Port rpcPort;
    std::string rpcPortName;
    yarp::os::Port requestPort;
    std::string requestPortName;
    yarp::os::Port responsePort;
    std::string responsePortName;
    int testOutcome;
    bool readyToSend;
    void collatz_test(int n, int t);

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();

    //Thrift methods
    void sendRequest();
};

#endif //COLLATZ_CONJECTURE_CLIENT_H
