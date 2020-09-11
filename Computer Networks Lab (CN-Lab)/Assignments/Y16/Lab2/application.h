#ifndef __LAB2_APPLICATION_H_
#define __LAB2_APPLICATION_H_

#include <omnetpp.h>
#include <Message_m.h>

using namespace omnetpp;

class Application : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int id_a;
    cGate* inG;
    cGate* outG;
    int count;
};

#endif
