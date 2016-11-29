// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_ClientInterface
#define YARP_THRIFT_GENERATOR_ClientInterface

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class ClientInterface;


class ClientInterface : public yarp::os::Wire {
public:
  ClientInterface();
  virtual void send_command_via_IDL(const double request);
  virtual void send_command_via_bottle(const double request);
  virtual bool read(yarp::os::ConnectionReader& connection);
  virtual std::vector<std::string> help(const std::string& functionName="--all");
};

#endif
