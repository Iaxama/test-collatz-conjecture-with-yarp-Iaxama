//
// Created by miacono on 24/11/16.
//

#ifndef COLLATZ_CONJECTURE_SERVER_H
#define COLLATZ_CONJECTURE_SERVER_H

#include <yarp/os/all.h>
#include <CommInterface.h>

#define PERIOD 1

class Server : public yarp::os::RFModule, public CommInterface{

private:
    yarp::os::BufferedPort<yarp::os::Bottle> requestPort;
    yarp::os::BufferedPort<yarp::os::Bottle> responsePort;
    yarp::os::Port rpcPort;

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();
    double getPeriod();

    //Thrift Methods
    double get_response(const double request);

};

#endif //COLLATZ_CONJECTURE_SERVER_H
