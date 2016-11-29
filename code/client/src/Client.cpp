#include <Client.h>


bool Client::updateModule(){
    int request;
    std::cout << "Insert number to verify" << std::endl;
    scanf("%d",&request);
    std::cout << "get_response(request) = " << get_response(request) << std::endl;



    return true;
}

bool Client::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Client")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName += "/rpc";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    requestPortName =  "/";
    requestPortName += getName();
    requestPortName += "/request";

    if (!requestPort.open(requestPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << requestPortName << std::endl;
        return false;
    }
    responsePortName =  "/";
    responsePortName += getName();
    responsePortName += "/response";

    if (!responsePort.open(responsePortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << responsePortName << std::endl;
        return false;
    }

    this->yarp().attachAsClient(rpcPort);

}

bool Client::close() {
    requestPort.close();
    responsePort.close();
    rpcPort.close();
    return true;
}