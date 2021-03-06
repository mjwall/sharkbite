/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef GCMonitorService_H
#define GCMonitorService_H

#include <thrift/TDispatchProcessor.h>
#include "gc_types.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace gc { namespace thrift {

class GCMonitorServiceIf {
 public:
  virtual ~GCMonitorServiceIf() {}
  virtual void getStatus(GCStatus& _return, const  ::org::apache::accumulo::core::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
};

class GCMonitorServiceIfFactory {
 public:
  typedef GCMonitorServiceIf Handler;

  virtual ~GCMonitorServiceIfFactory() {}

  virtual GCMonitorServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(GCMonitorServiceIf* /* handler */) = 0;
};

class GCMonitorServiceIfSingletonFactory : virtual public GCMonitorServiceIfFactory {
 public:
  GCMonitorServiceIfSingletonFactory(const std::shared_ptr<GCMonitorServiceIf>& iface) : iface_(iface) {}
  virtual ~GCMonitorServiceIfSingletonFactory() {}

  virtual GCMonitorServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(GCMonitorServiceIf* /* handler */) {}

 protected:
  std::shared_ptr<GCMonitorServiceIf> iface_;
};

class GCMonitorServiceNull : virtual public GCMonitorServiceIf {
 public:
  virtual ~GCMonitorServiceNull() {}
  void getStatus(GCStatus& /* _return */, const  ::org::apache::accumulo::core::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
};

typedef struct _GCMonitorService_getStatus_args__isset {
  _GCMonitorService_getStatus_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _GCMonitorService_getStatus_args__isset;

class GCMonitorService_getStatus_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  GCMonitorService_getStatus_args(const GCMonitorService_getStatus_args&);
  GCMonitorService_getStatus_args& operator=(const GCMonitorService_getStatus_args&);
  GCMonitorService_getStatus_args() {
  }

  virtual ~GCMonitorService_getStatus_args() throw();
   ::org::apache::accumulo::core::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _GCMonitorService_getStatus_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::core::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const GCMonitorService_getStatus_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const GCMonitorService_getStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GCMonitorService_getStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const GCMonitorService_getStatus_args& obj);
};


class GCMonitorService_getStatus_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~GCMonitorService_getStatus_pargs() throw();
  const  ::org::apache::accumulo::core::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const GCMonitorService_getStatus_pargs& obj);
};

typedef struct _GCMonitorService_getStatus_result__isset {
  _GCMonitorService_getStatus_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _GCMonitorService_getStatus_result__isset;

class GCMonitorService_getStatus_result {
 public:

  static const char* ascii_fingerprint; // = "A48AD5E83025A02E276DC55D13EDD8B8";
  static const uint8_t binary_fingerprint[16]; // = {0xA4,0x8A,0xD5,0xE8,0x30,0x25,0xA0,0x2E,0x27,0x6D,0xC5,0x5D,0x13,0xED,0xD8,0xB8};

  GCMonitorService_getStatus_result(const GCMonitorService_getStatus_result&);
  GCMonitorService_getStatus_result& operator=(const GCMonitorService_getStatus_result&);
  GCMonitorService_getStatus_result() {
  }

  virtual ~GCMonitorService_getStatus_result() throw();
  GCStatus success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _GCMonitorService_getStatus_result__isset __isset;

  void __set_success(const GCStatus& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const GCMonitorService_getStatus_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const GCMonitorService_getStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GCMonitorService_getStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const GCMonitorService_getStatus_result& obj);
};

typedef struct _GCMonitorService_getStatus_presult__isset {
  _GCMonitorService_getStatus_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _GCMonitorService_getStatus_presult__isset;

class GCMonitorService_getStatus_presult {
 public:

  static const char* ascii_fingerprint; // = "A48AD5E83025A02E276DC55D13EDD8B8";
  static const uint8_t binary_fingerprint[16]; // = {0xA4,0x8A,0xD5,0xE8,0x30,0x25,0xA0,0x2E,0x27,0x6D,0xC5,0x5D,0x13,0xED,0xD8,0xB8};


  virtual ~GCMonitorService_getStatus_presult() throw();
  GCStatus* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _GCMonitorService_getStatus_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const GCMonitorService_getStatus_presult& obj);
};

class GCMonitorServiceClient : virtual public GCMonitorServiceIf {
 public:
  GCMonitorServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  GCMonitorServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getStatus(GCStatus& _return, const  ::org::apache::accumulo::core::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getStatus(const  ::org::apache::accumulo::core::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getStatus(GCStatus& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class GCMonitorServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  std::shared_ptr<GCMonitorServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (GCMonitorServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  GCMonitorServiceProcessor(std::shared_ptr<GCMonitorServiceIf> iface) :
    iface_(iface) {
    processMap_["getStatus"] = &GCMonitorServiceProcessor::process_getStatus;
  }

  virtual ~GCMonitorServiceProcessor() {}
};

class GCMonitorServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  GCMonitorServiceProcessorFactory(const ::std::shared_ptr< GCMonitorServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< GCMonitorServiceIfFactory > handlerFactory_;
};

class GCMonitorServiceMultiface : virtual public GCMonitorServiceIf {
 public:
  GCMonitorServiceMultiface(std::vector<std::shared_ptr<GCMonitorServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~GCMonitorServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<GCMonitorServiceIf> > ifaces_;
  GCMonitorServiceMultiface() {}
  void add(std::shared_ptr<GCMonitorServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getStatus(GCStatus& _return, const  ::org::apache::accumulo::core::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getStatus(_return, tinfo, credentials);
    }
    ifaces_[i]->getStatus(_return, tinfo, credentials);
    return;
  }

};

}}}}}} // namespace

#endif
