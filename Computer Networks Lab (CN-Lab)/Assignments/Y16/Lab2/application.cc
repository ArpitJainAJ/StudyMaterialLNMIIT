#include "application.h"
#include "A_PDU_m.h"

Define_Module(Application);

void Application::initialize()
{
    inG = gate("app_in");
    outG = gate("app_out");
    id_a = par("id_a");
    count = 1;
    if(id_a == 1)
    {
        cMessage *msg = new cMessage();
        scheduleAt(0,msg);
    }
}

void Application::handleMessage(cMessage *msg)
{

    if(msg->isSelfMessage())
    {
        A_PDU* pkt = new A_PDU();
        pkt -> setId(0);
        pkt -> setType("Data");
        send(pkt, outG);
    }
    else
    {
        A_PDU *pkt = check_and_cast<A_PDU*>(msg);
        if (strcmp(pkt -> getType(),"Data") == 0 )
            {
                pkt->setType("Ack");
                send(pkt,outG);
            }
        else if (strcmp(pkt -> getType(),"Ack") == 0 && pkt->getId() < 9)
        {
                pkt->setId(pkt->getId() + 1);
                pkt -> setType("Data");
                send(pkt, outG);
        }
    }


}
