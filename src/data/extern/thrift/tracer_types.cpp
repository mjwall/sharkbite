/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "data/extern/thrift/tracer_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace org { namespace apache { namespace accumulo { namespace tracer { namespace thrift {


Annotation::~Annotation() throw() {
}


void Annotation::__set_time(const int64_t val) {
  this->time = val;
}

void Annotation::__set_msg(const std::string& val) {
  this->msg = val;
}

uint32_t Annotation::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Annotation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Annotation");

  xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Annotation &a, Annotation &b) {
  using ::std::swap;
  swap(a.time, b.time);
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

Annotation::Annotation(const Annotation& other0) {
  time = other0.time;
  msg = other0.msg;
  __isset = other0.__isset;
}
Annotation& Annotation::operator=(const Annotation& other1) {
  time = other1.time;
  msg = other1.msg;
  __isset = other1.__isset;
  return *this;
}
void Annotation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Annotation(";
  out << "time=" << to_string(time);
  out << ", " << "msg=" << to_string(msg);
  out << ")";
}


RemoteSpan::~RemoteSpan() throw() {
}


void RemoteSpan::__set_sender(const std::string& val) {
  this->sender = val;
}

void RemoteSpan::__set_svc(const std::string& val) {
  this->svc = val;
}

void RemoteSpan::__set_traceId(const int64_t val) {
  this->traceId = val;
}

void RemoteSpan::__set_spanId(const int64_t val) {
  this->spanId = val;
}

void RemoteSpan::__set_parentId(const int64_t val) {
  this->parentId = val;
}

void RemoteSpan::__set_start(const int64_t val) {
  this->start = val;
}

void RemoteSpan::__set_stop(const int64_t val) {
  this->stop = val;
}

void RemoteSpan::__set_description(const std::string& val) {
  this->description = val;
}

void RemoteSpan::__set_data(const std::map<std::string, std::string> & val) {
  this->data = val;
}

void RemoteSpan::__set_annotations(const std::vector<Annotation> & val) {
  this->annotations = val;
}

void RemoteSpan::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RemoteSpan(";
  out << "sender=" << sender;
  out << ", " << "svc=" << svc;
  out << ")";
}

uint32_t RemoteSpan::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sender);
          this->__isset.sender = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->svc);
          this->__isset.svc = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->traceId);
          this->__isset.traceId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->spanId);
          this->__isset.spanId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->parentId);
          this->__isset.parentId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->start);
          this->__isset.start = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->stop);
          this->__isset.stop = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->data.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _ktype3;
            ::apache::thrift::protocol::TType _vtype4;
            xfer += iprot->readMapBegin(_ktype3, _vtype4, _size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              std::string _key7;
              xfer += iprot->readString(_key7);
              std::string& _val8 = this->data[_key7];
              xfer += iprot->readString(_val8);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->annotations.clear();
            uint32_t _size9;
            ::apache::thrift::protocol::TType _etype12;
            xfer += iprot->readListBegin(_etype12, _size9);
            this->annotations.resize(_size9);
            uint32_t _i13;
            for (_i13 = 0; _i13 < _size9; ++_i13)
            {
              xfer += this->annotations[_i13].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.annotations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RemoteSpan::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RemoteSpan");

  xfer += oprot->writeFieldBegin("sender", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->sender);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("svc", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->svc);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("traceId", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->traceId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("spanId", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->spanId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("parentId", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->parentId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("start", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->start);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("stop", ::apache::thrift::protocol::T_I64, 7);
  xfer += oprot->writeI64(this->stop);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_MAP, 9);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->data.size()));
    std::map<std::string, std::string> ::const_iterator _iter14;
    for (_iter14 = this->data.begin(); _iter14 != this->data.end(); ++_iter14)
    {
      xfer += oprot->writeString(_iter14->first);
      xfer += oprot->writeString(_iter14->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("annotations", ::apache::thrift::protocol::T_LIST, 10);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->annotations.size()));
    std::vector<Annotation> ::const_iterator _iter15;
    for (_iter15 = this->annotations.begin(); _iter15 != this->annotations.end(); ++_iter15)
    {
      xfer += (*_iter15).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RemoteSpan &a, RemoteSpan &b) {
  using ::std::swap;
  swap(a.sender, b.sender);
  swap(a.svc, b.svc);
  swap(a.traceId, b.traceId);
  swap(a.spanId, b.spanId);
  swap(a.parentId, b.parentId);
  swap(a.start, b.start);
  swap(a.stop, b.stop);
  swap(a.description, b.description);
  swap(a.data, b.data);
  swap(a.annotations, b.annotations);
  swap(a.__isset, b.__isset);
}

}}}}} // namespace