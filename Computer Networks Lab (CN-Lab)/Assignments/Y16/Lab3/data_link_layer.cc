#include "data_link_layer.h"
#include <A_PDU_m.h>
#include <D_PDU_m.h>
Define_Module(Data_link_layer);

void Data_link_layer::initialize()
{
        inG_A= gate("data_app_in");
        inG_D = gate("data_phy_in");
        outG_D = gate("data_phy_out");
        outG_A= gate("data_app_out");
        id_d = par("id_d");
}

void Data_link_layer::handleMessage(cMessage *msg)
{

    if (msg->getArrivalGate() == inG_A )
    {
        A_PDU *pkt = check_and_cast<A_PDU*>(msg);
        D_PDU* frame = new D_PDU();
        frame -> encapsulate(pkt);
        send(frame,outG_D);
    }
    else if(msg->getArrivalGate() == inG_D)
    {
        D_PDU* frame = check_and_cast<D_PDU*>(msg);
        if(strcmp(frame->getType(),"d_Ack") == 0)
        {
            delete msg;
        }
        else
        {
            send(frame->decapsulate(),outG_A);
            D_PDU* frame1 = new D_PDU();
            frame1 -> setId(0);
            frame1 -> setType("d_Ack");
            send(frame1, outG_D);
        }

    }
}
