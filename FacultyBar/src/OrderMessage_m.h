//
// Generated file, do not edit! Created by nedtool 5.5 from OrderMessage.msg.
//

#ifndef __ORDERMESSAGE_M_H
#define __ORDERMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>OrderMessage.msg:2</tt> by nedtool.
 * <pre>
 * message OrderMessage
 * {
 *     bool vipPriority;
 *     double cashierQueueArrivalTime;
 *     double cashierQueueExitTime;
 *     double cashierNodeDepartureTime;
 *     double seatManagerQueueArrivalTime;
 *     double seatManagerQueueExitTime;
 *     double seatManagerNodeDepartureTime;
 * }
 * </pre>
 */
class OrderMessage : public ::omnetpp::cMessage
{
  protected:
    bool vipPriority;
    double cashierQueueArrivalTime;
    double cashierQueueExitTime;
    double cashierNodeDepartureTime;
    double seatManagerQueueArrivalTime;
    double seatManagerQueueExitTime;
    double seatManagerNodeDepartureTime;

  private:
    void copy(const OrderMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const OrderMessage&);

  public:
    OrderMessage(const char *name=nullptr, short kind=0);
    OrderMessage(const OrderMessage& other);
    virtual ~OrderMessage();
    OrderMessage& operator=(const OrderMessage& other);
    virtual OrderMessage *dup() const override {return new OrderMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getVipPriority() const;
    virtual void setVipPriority(bool vipPriority);
    virtual double getCashierQueueArrivalTime() const;
    virtual void setCashierQueueArrivalTime(double cashierQueueArrivalTime);
    virtual double getCashierQueueExitTime() const;
    virtual void setCashierQueueExitTime(double cashierQueueExitTime);
    virtual double getCashierNodeDepartureTime() const;
    virtual void setCashierNodeDepartureTime(double cashierNodeDepartureTime);
    virtual double getSeatManagerQueueArrivalTime() const;
    virtual void setSeatManagerQueueArrivalTime(double seatManagerQueueArrivalTime);
    virtual double getSeatManagerQueueExitTime() const;
    virtual void setSeatManagerQueueExitTime(double seatManagerQueueExitTime);
    virtual double getSeatManagerNodeDepartureTime() const;
    virtual void setSeatManagerNodeDepartureTime(double seatManagerNodeDepartureTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const OrderMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, OrderMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __ORDERMESSAGE_M_H

