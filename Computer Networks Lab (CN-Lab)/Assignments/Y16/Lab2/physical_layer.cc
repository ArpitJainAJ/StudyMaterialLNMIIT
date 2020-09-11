#include "physical_layer.h"
#include "P_PDU_m.h"
#include "D_PDU_m.h"


Define_Module(Physical_layer);

void Physical_layer::initialize()
{
    inG_P= gate("phy_med_in");
    inG_D = gate("phy_data_in");
    outG_D = gate("phy_data_out");
    outG_P= gate("phy_med_out");
    id_p = par("id_p");
}

void Physical_layer::handleMessage(cMessage *msg)
{

        if (msg->getArrivalGate() == inG_D)
        {
            D_PDU *pkt = check_and_cast<D_PDU*>(msg);
            P_PDU* frame = new P_PDU();
            frame -> encapsulate(pkt);
            send(frame,outG_P);
        }
        else if(msg->getArrivalGate() == inG_P)
        {
            P_PDU* frame = check_and_cast<P_PDU*>(msg);
            send(frame->decapsulate(),outG_D);
        }
}
