/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef trace_TYPES_V2H
#define trace_TYPES_V2H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace org { namespace apache { namespace accumulov2 { namespace core { namespace trace { namespace thrift {

class TInfo;

typedef struct _TInfo__isset {
  _TInfo__isset() : traceId(false), parentId(false) {}
  bool traceId :1;
  bool parentId :1;
} _TInfo__isset;

class TInfo : public virtual ::apache::thrift::TBase {
 public:

  TInfo(const TInfo&);
  TInfo& operator=(const TInfo&);
  TInfo() : traceId(0), parentId(0) {
  }

  virtual ~TInfo() throw();
  int64_t traceId;
  int64_t parentId;

  _TInfo__isset __isset;

  void __set_traceId(const int64_t val);

  void __set_parentId(const int64_t val);

  bool operator == (const TInfo & rhs) const
  {
    if (!(traceId == rhs.traceId))
      return false;
    if (!(parentId == rhs.parentId))
      return false;
    return true;
  }
  bool operator != (const TInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TInfo &a, TInfo &b);

std::ostream& operator<<(std::ostream& out, const TInfo& obj);

}}}}}} // namespace

#endif
