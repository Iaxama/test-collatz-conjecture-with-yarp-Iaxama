#include <Server.h>
//#include <server_interface.thrift>

bool Server::updateModule(){
    yarp::os::Bottle* request= requestPort.read(false);
    if (request != NULL){
        double response = get_response(request->get(0).asDouble());
        yarp::os::Bottle &responseBottle = responsePort.prepare();
        responseBottle.clear();
        responseBottle.addDouble(response);
        responsePort.write(false);
    };

    return true;
}

bool Server::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Server")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    //
    std::string outputPortName =  "/";
    outputPortName += getName();

    if (!rpcPort.open(outputPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << outputPortName << std::endl;
        return false;
    }

    std::string requestPortName = "/";
    requestPortName += getName();
    requestPortName += "/request:i";
    if (!requestPort.open(requestPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << requestPortName << std::endl;
        return false;
    }

    std::string responsePortName = "/";
    responsePortName += getName();
    responsePortName += "/response:o";
    if (!responsePort.open(responsePortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << responsePortName << std::endl;
        return false;
    }

    return this->yarp().attachAsServer(rpcPort);

}

bool Server::close() {
    requestPort.close();
    responsePort.close();
    rpcPort.close();
    return true;
}

double Server::getPeriod() {
    return PERIOD;
}

double Server::get_response(const double request)
{

    return request;
}

