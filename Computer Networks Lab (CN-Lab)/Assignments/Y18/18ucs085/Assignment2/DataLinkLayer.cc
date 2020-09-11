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

#include "DataLinkLayer.h"
#include "DN_PDU_m.h"
#include "N_PDU_m.h"

Define_Module(DataLinkLayer);

void DataLinkLayer::initialize()
{
    // TODO - Generated method body
    address=par("DLLid");
    fromNLL=gate("fromNLL");
    toNLL=gate("toNLL");
    fromNode=gate("fromNode");
    toNode=gate("toNode");
}

void DataLinkLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg -> getArrivalGate()==fromNLL)
    {
        N_PDU * npkt = check_and_cast <N_PDU *> (msg);
        DN_PDU * dnpkt2 = new DN_PDU();
        dnpkt2 -> setType(npkt->getType());
        dnpkt2 -> setMod(npkt->getMid()%2);
        dnpkt2 -> encapsulate(npkt);
        send(dnpkt2,toNode);
    }
    else if(msg -> getArrivalGate()==fromNode)
    {
        DN_PDU * dnpkt = check_and_cast <DN_PDU *> (msg);
        N_PDU * npkt2 = new N_PDU();
        dnpkt -> decapsulate();
        if(strcmp(dnpkt->getType(),"Acknowledgment")==0)
        {
            delete(dnpkt);
        }
        else if(strcmp(dnpkt->getType(),"Data")==0)
        {
            npkt2 -> setType(dnpkt->getType());
            //dnpkt2 -> decapsulate();
            send(npkt2,toNLL);
            DN_PDU * dnpkt3 =  new DN_PDU;
            dnpkt3 -> setType("Acknowledgment");
            dnpkt3 -> setMod(npkt2 -> getMid()%2);
            send(dnpkt3,toNode);
        }
    }
}
