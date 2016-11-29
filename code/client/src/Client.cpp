#include <Client.h>


bool Client::updateModule(){
    return true;
}

bool Client::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Client")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    std::string rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName += "/rpc";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    this->yarp().attachAsClient(rpcPort);
}

bool Client::close() {

    rpcPort.close();
    return true;
}