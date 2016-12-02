// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_ClientIDLInterface
#define YARP_THRIFT_GENERATOR_ClientIDLInterface

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class ClientIDLInterface;


class ClientIDLInterface : public yarp::os::Wire {
public:
  ClientIDLInterface();
  virtual void sendRequest();
  virtual bool read(yarp::os::ConnectionReader& connection);
  virtual std::vector<std::string> help(const std::string& functionName="--all");
};

#endif
