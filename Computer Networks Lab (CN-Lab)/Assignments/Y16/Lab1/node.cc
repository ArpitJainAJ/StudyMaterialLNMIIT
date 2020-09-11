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

#include "node.h"
#include "pack_m.h"

Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body
    gin=gate("in");
    gout=gate("out");
    nid=par("id");
    if(nid==1){
        cMessage* msg = new cMessage();
        scheduleAt(0,msg);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if(msg -> isSelfMessage()){
       // cMessage* data = new cMessage;
        Pack* pkt = new Pack();
        pkt -> setPid(0);
        pkt -> setType("Data");
        send(pkt,gout);
    }

    else{
        //cMessage *msg = new cMessage;
        Pack *pkt = check_and_cast<Pack*>(msg);
        if(strcmp (pkt -> getType(),"Data")==0)
        {
            pkt->setType("Ack");
            send(pkt,gout);
        }
        else if (strcmp(pkt -> getType(),"Ack") == 0 && pkt->getPid() < 9){
            pkt->setPid(pkt->getPid() + 1);
            pkt -> setType("Data");
            send(pkt, gout);
        }
    }
}


