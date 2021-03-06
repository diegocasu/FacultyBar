//
// Generated file, do not edit! Created by nedtool 5.5 from OrderMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "OrderMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(OrderMessage)

OrderMessage::OrderMessage(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->vipPriority = false;
    this->cashierQueueArrivalTime = 0;
    this->cashierQueueExitTime = 0;
    this->cashierNodeDepartureTime = 0;
    this->seatManagerQueueArrivalTime = 0;
    this->seatManagerQueueExitTime = 0;
    this->seatManagerNodeDepartureTime = 0;
}

OrderMessage::OrderMessage(const OrderMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

OrderMessage::~OrderMessage()
{
}

OrderMessage& OrderMessage::operator=(const OrderMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void OrderMessage::copy(const OrderMessage& other)
{
    this->vipPriority = other.vipPriority;
    this->cashierQueueArrivalTime = other.cashierQueueArrivalTime;
    this->cashierQueueExitTime = other.cashierQueueExitTime;
    this->cashierNodeDepartureTime = other.cashierNodeDepartureTime;
    this->seatManagerQueueArrivalTime = other.seatManagerQueueArrivalTime;
    this->seatManagerQueueExitTime = other.seatManagerQueueExitTime;
    this->seatManagerNodeDepartureTime = other.seatManagerNodeDepartureTime;
}

void OrderMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->vipPriority);
    doParsimPacking(b,this->cashierQueueArrivalTime);
    doParsimPacking(b,this->cashierQueueExitTime);
    doParsimPacking(b,this->cashierNodeDepartureTime);
    doParsimPacking(b,this->seatManagerQueueArrivalTime);
    doParsimPacking(b,this->seatManagerQueueExitTime);
    doParsimPacking(b,this->seatManagerNodeDepartureTime);
}

void OrderMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->vipPriority);
    doParsimUnpacking(b,this->cashierQueueArrivalTime);
    doParsimUnpacking(b,this->cashierQueueExitTime);
    doParsimUnpacking(b,this->cashierNodeDepartureTime);
    doParsimUnpacking(b,this->seatManagerQueueArrivalTime);
    doParsimUnpacking(b,this->seatManagerQueueExitTime);
    doParsimUnpacking(b,this->seatManagerNodeDepartureTime);
}

bool OrderMessage::getVipPriority() const
{
    return this->vipPriority;
}

void OrderMessage::setVipPriority(bool vipPriority)
{
    this->vipPriority = vipPriority;
}

::omnetpp::simtime_t OrderMessage::getCashierQueueArrivalTime() const
{
    return this->cashierQueueArrivalTime;
}

void OrderMessage::setCashierQueueArrivalTime(::omnetpp::simtime_t cashierQueueArrivalTime)
{
    this->cashierQueueArrivalTime = cashierQueueArrivalTime;
}

::omnetpp::simtime_t OrderMessage::getCashierQueueExitTime() const
{
    return this->cashierQueueExitTime;
}

void OrderMessage::setCashierQueueExitTime(::omnetpp::simtime_t cashierQueueExitTime)
{
    this->cashierQueueExitTime = cashierQueueExitTime;
}

::omnetpp::simtime_t OrderMessage::getCashierNodeDepartureTime() const
{
    return this->cashierNodeDepartureTime;
}

void OrderMessage::setCashierNodeDepartureTime(::omnetpp::simtime_t cashierNodeDepartureTime)
{
    this->cashierNodeDepartureTime = cashierNodeDepartureTime;
}

::omnetpp::simtime_t OrderMessage::getSeatManagerQueueArrivalTime() const
{
    return this->seatManagerQueueArrivalTime;
}

void OrderMessage::setSeatManagerQueueArrivalTime(::omnetpp::simtime_t seatManagerQueueArrivalTime)
{
    this->seatManagerQueueArrivalTime = seatManagerQueueArrivalTime;
}

::omnetpp::simtime_t OrderMessage::getSeatManagerQueueExitTime() const
{
    return this->seatManagerQueueExitTime;
}

void OrderMessage::setSeatManagerQueueExitTime(::omnetpp::simtime_t seatManagerQueueExitTime)
{
    this->seatManagerQueueExitTime = seatManagerQueueExitTime;
}

::omnetpp::simtime_t OrderMessage::getSeatManagerNodeDepartureTime() const
{
    return this->seatManagerNodeDepartureTime;
}

void OrderMessage::setSeatManagerNodeDepartureTime(::omnetpp::simtime_t seatManagerNodeDepartureTime)
{
    this->seatManagerNodeDepartureTime = seatManagerNodeDepartureTime;
}

class OrderMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OrderMessageDescriptor();
    virtual ~OrderMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OrderMessageDescriptor)

OrderMessageDescriptor::OrderMessageDescriptor() : omnetpp::cClassDescriptor("OrderMessage", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

OrderMessageDescriptor::~OrderMessageDescriptor()
{
    delete[] propertynames;
}

bool OrderMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OrderMessage *>(obj)!=nullptr;
}

const char **OrderMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OrderMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OrderMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OrderMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OrderMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vipPriority",
        "cashierQueueArrivalTime",
        "cashierQueueExitTime",
        "cashierNodeDepartureTime",
        "seatManagerQueueArrivalTime",
        "seatManagerQueueExitTime",
        "seatManagerNodeDepartureTime",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OrderMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vipPriority")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cashierQueueArrivalTime")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "cashierQueueExitTime")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "cashierNodeDepartureTime")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "seatManagerQueueArrivalTime")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "seatManagerQueueExitTime")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "seatManagerNodeDepartureTime")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OrderMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OrderMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OrderMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OrderMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OrderMessage *pp = (OrderMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OrderMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OrderMessage *pp = (OrderMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OrderMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OrderMessage *pp = (OrderMessage *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getVipPriority());
        case 1: return simtime2string(pp->getCashierQueueArrivalTime());
        case 2: return simtime2string(pp->getCashierQueueExitTime());
        case 3: return simtime2string(pp->getCashierNodeDepartureTime());
        case 4: return simtime2string(pp->getSeatManagerQueueArrivalTime());
        case 5: return simtime2string(pp->getSeatManagerQueueExitTime());
        case 6: return simtime2string(pp->getSeatManagerNodeDepartureTime());
        default: return "";
    }
}

bool OrderMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OrderMessage *pp = (OrderMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setVipPriority(string2bool(value)); return true;
        case 1: pp->setCashierQueueArrivalTime(string2simtime(value)); return true;
        case 2: pp->setCashierQueueExitTime(string2simtime(value)); return true;
        case 3: pp->setCashierNodeDepartureTime(string2simtime(value)); return true;
        case 4: pp->setSeatManagerQueueArrivalTime(string2simtime(value)); return true;
        case 5: pp->setSeatManagerQueueExitTime(string2simtime(value)); return true;
        case 6: pp->setSeatManagerNodeDepartureTime(string2simtime(value)); return true;
        default: return false;
    }
}

const char *OrderMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OrderMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OrderMessage *pp = (OrderMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


