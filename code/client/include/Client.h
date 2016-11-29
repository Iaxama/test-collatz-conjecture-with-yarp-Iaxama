#ifndef COLLATZ_CONJECTURE_CLIENT_H
#define COLLATZ_CONJECTURE_CLIENT_H

#include <yarp/os/all.h>
#include <CommInterface.h>

class Client : public yarp::os::RFModule, public CommInterface{
private:

    yarp::os::Port rpcPort;

public:

    virtual bool updateModule();
    virtual bool configure(yarp::os::ResourceFinder &rf);
    virtual bool close();
};

#endif //COLLATZ_CONJECTURE_CLIENT_H
