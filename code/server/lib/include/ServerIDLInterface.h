// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_ServerIDLInterface
#define YARP_THRIFT_GENERATOR_ServerIDLInterface

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class ServerIDLInterface;


class ServerIDLInterface : public yarp::os::Wire {
public:
  ServerIDLInterface();
  virtual void start();
  virtual void stop();
  virtual void pause();
  virtual void printFIFO();
  virtual void emptyFIFO();
  virtual bool read(yarp::os::ConnectionReader& connection);
  virtual std::vector<std::string> help(const std::string& functionName="--all");
};

#endif
