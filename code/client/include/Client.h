#ifndef COLLATZ_CONJECTURE_CLIENT_H
#define COLLATZ_CONJECTURE_CLIENT_H

#include <yarp/os/all.h>
#include <CommInterface.h>

class Client : public yarp::os::RFModule, public CommInterface{
private:

    yarp::os::Port rpcPort;
    std::string rpcPortName;
    yarp::os::Port requestPort;
    std::string requestPortName;
    yarp::os::Port responsePort;
    std::string responsePortName;

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();

};

#endif //COLLATZ_CONJECTURE_CLIENT_H
