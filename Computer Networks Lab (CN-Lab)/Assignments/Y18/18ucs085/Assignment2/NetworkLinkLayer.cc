//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "NetworkLinkLayer.h"
#include "N_PDU_m.h"
#include "DN_PDU_m.h"

Define_Module(NetworkLinkLayer);

void NetworkLinkLayer::initialize()
{
    // TODO - Generated method body
    address=par("NLLid");
    fromDLL=gate("fromDLL");
    toDLL=gate("toDLL");

    if(address==1)
    {
        counter=10;
        cMessage *msg=new cMessage();
        scheduleAt(0,msg);
    }
}

void NetworkLinkLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    //static int i=0;
    if(msg->isSelfMessage())
    {
        N_PDU * npkt = new N_PDU();
        //npkt->setMid(1+i);
        npkt->setMid(11-counter);
        npkt->setType("Data");
        npkt->setSourceAdd(1);
        npkt->setDestAdd(2);
        //if(i<10)
        if(counter>0)
        {
            counter--;
            //WATCH(counter);
            //i++;
            send(npkt,toDLL);
            cMessage *msg2=new cMessage();
            scheduleAt(SimTime()+250,msg2);
        }
    }
    else if(msg -> getArrivalGate() == fromDLL)
    {
        /*N_PDU * npkt = check_and_cast <N_PDU *> (msg);
        N_PDU * npkt2 = new N_PDU();
        npkt2->setSourceAdd(npkt->getDestAdd());
        npkt2->setDestAdd(npkt->getSourceAdd());
        if(strcmp(npkt->getType(),"Acknowledgment")==0)
        {
            npkt2->setMid(npkt->getMid()+1);
            npkt2->setType("Data");
            send(npkt2,toDLL);
            delete(npkt);
        }
        else if(strcmp(npkt->getType(),"Data")==0)
        {
           npkt2->setMid(npkt->getMid());
           npkt2->setType("Acknowledgment");
           send(npkt2,toDLL);
           delete(npkt);
        }*/
        delete(msg);
    }
}
