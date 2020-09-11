#ifndef __LAB2_PHYSICAL_LAYER_H_
#define __LAB2_PHYSICAL_LAYER_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Physical_layer : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int id_p;
        cGate* inG_P;
        cGate* outG_P;
        cGate* inG_D;
        cGate* outG_D;
        int count;
};

#endif
