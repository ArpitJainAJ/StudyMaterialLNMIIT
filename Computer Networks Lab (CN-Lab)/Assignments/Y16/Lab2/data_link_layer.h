#ifndef __LAB2_DATA_LINK_LAYER_H_
#define __LAB2_DATA_LINK_LAYER_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Data_link_layer : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int id_d;
    cGate* inG_A;
    cGate* outG_A;
    cGate* inG_D;
    cGate* outG_D;
    int count;
};

#endif
