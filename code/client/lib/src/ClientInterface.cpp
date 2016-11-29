// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <ClientInterface.h>
#include <yarp/os/idl/WireTypes.h>



class ClientInterface_send_command_via_IDL : public yarp::os::Portable {
public:
  double request;
  void init(const double request);
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ClientInterface_send_command_via_bottle : public yarp::os::Portable {
public:
  double request;
  void init(const double request);
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

bool ClientInterface_send_command_via_IDL::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(5)) return false;
  if (!writer.writeTag("send_command_via_IDL",1,4)) return false;
  if (!writer.writeDouble(request)) return false;
  return true;
}

bool ClientInterface_send_command_via_IDL::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ClientInterface_send_command_via_IDL::init(const double request) {
  this->request = request;
}

bool ClientInterface_send_command_via_bottle::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(5)) return false;
  if (!writer.writeTag("send_command_via_bottle",1,4)) return false;
  if (!writer.writeDouble(request)) return false;
  return true;
}

bool ClientInterface_send_command_via_bottle::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ClientInterface_send_command_via_bottle::init(const double request) {
  this->request = request;
}

ClientInterface::ClientInterface() {
  yarp().setOwner(*this);
}
void ClientInterface::send_command_via_IDL(const double request) {
  ClientInterface_send_command_via_IDL helper;
  helper.init(request);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ClientInterface::send_command_via_IDL(const double request)");
  }
  yarp().write(helper,helper);
}
void ClientInterface::send_command_via_bottle(const double request) {
  ClientInterface_send_command_via_bottle helper;
  helper.init(request);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ClientInterface::send_command_via_bottle(const double request)");
  }
  yarp().write(helper,helper);
}

bool ClientInterface::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  bool direct = (tag=="__direct__");
  if (direct) tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "send_command_via_IDL") {
      double request;
      if (!reader.readDouble(request)) {
        reader.fail();
        return false;
      }
      send_command_via_IDL(request);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "send_command_via_bottle") {
      double request;
      if (!reader.readDouble(request)) {
        reader.fail();
        return false;
      }
      send_command_via_bottle(request);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "help") {
      std::string functionName;
      if (!reader.readString(functionName)) {
        functionName = "--all";
      }
      std::vector<std::string> _return=help(functionName);
      yarp::os::idl::WireWriter writer(reader);
        if (!writer.isNull()) {
          if (!writer.writeListHeader(2)) return false;
          if (!writer.writeTag("many",1, 0)) return false;
          if (!writer.writeListBegin(BOTTLE_TAG_INT, static_cast<uint32_t>(_return.size()))) return false;
          std::vector<std::string> ::iterator _iterHelp;
          for (_iterHelp = _return.begin(); _iterHelp != _return.end(); ++_iterHelp)
          {
            if (!writer.writeString(*_iterHelp)) return false;
           }
          if (!writer.writeListEnd()) return false;
        }
      reader.accept();
      return true;
    }
    if (reader.noMore()) { reader.fail(); return false; }
    yarp::os::ConstString next_tag = reader.readTag();
    if (next_tag=="") break;
    tag = tag + "_" + next_tag;
  }
  return false;
}

std::vector<std::string> ClientInterface::help(const std::string& functionName) {
  bool showAll=(functionName=="--all");
  std::vector<std::string> helpString;
  if(showAll) {
    helpString.push_back("*** Available commands:");
    helpString.push_back("send_command_via_IDL");
    helpString.push_back("send_command_via_bottle");
    helpString.push_back("help");
  }
  else {
    if (functionName=="send_command_via_IDL") {
      helpString.push_back("void send_command_via_IDL(const double request) ");
    }
    if (functionName=="send_command_via_bottle") {
      helpString.push_back("void send_command_via_bottle(const double request) ");
    }
    if (functionName=="help") {
      helpString.push_back("std::vector<std::string> help(const std::string& functionName=\"--all\")");
      helpString.push_back("Return list of available commands, or help message for a specific function");
      helpString.push_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
      helpString.push_back("@return list of strings (one string per line)");
    }
  }
  if ( helpString.empty()) helpString.push_back("Command not found");
  return helpString;
}


