#include <Client.h>

bool Client::updateModule(){

    if (autoTrigger)
        sendRequest();
    return true;
}

bool Client::sendRequest() {

    yarp::os::Bottle request;
    yarp::os::Bottle reply;
    request.addVocab(COLLATZ_VOCAB_REQ_ITEM);
    request.addInt(n);

    std::cout << "Sending request " << n << std::endl;
    clientPort.write(request,reply);

    if (reply.size() != 3){
        std::cerr << "Client Side: Unexpected bottle size. Ignoring message." << std::endl;
    }
    if (reply.get(0).asVocab() != COLLATZ_VOCAB_ITEM) {
        std::cerr << "Client side: Incorrect Identifier received. Ignoring message." << std::endl;
        return false;
    }
    n = reply.get(1).asInt();
    t = reply.get(2).asInt();
    std::cout << "Received the pair (" << n << ", " << t << ")" << std::endl;
    double testOutcome = collatz_test(n,t);
    std::cout << "The test outcome is " << testOutcome << std::endl;
    return true;
}

double Client::collatz_test(int n, int t) {

    if (t <= 0) {
        std::cout << "Threshold 0 would not converge. Using 1 instead" << std::endl;
        t = 1;
    }
    while (n > t){
        if (n & 0x01){
            n *=3;
            n++;
        } else {
            n >>= 1;
        }
    }
    return n;
}

bool Client::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("client")).asString();

    std::string id = rf.check("id",yarp::os::Value("a")).asString();
    moduleName += "_";
    moduleName += id;
    std::cout << "moduleName = " << moduleName << std::endl;
    setName(moduleName.c_str());



    rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName += "/commands";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    clientPortName =  "/";
    clientPortName += getName();

    if (!clientPort.open(clientPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << clientPortName << std::endl;
        return false;
    }

    period = 1;
    autoTrigger = false;
    this->yarp().attachAsServer(rpcPort);
    return true;
}

bool Client::close() {
    clientPort.close();
    rpcPort.close();
    return true;
}

double Client::getPeriod() {
    return period;
}

bool Client::autoSendRequest(const double period) {
    autoTrigger = true;
    this->period = period;
}

bool Client::stopSendRequest() {
    autoTrigger = false;
}