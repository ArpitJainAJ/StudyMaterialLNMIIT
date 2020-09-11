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

#include "Node.h"
#include "N_PDU_m.h"

Define_Module(Node);

void Node::initialize()
{
    address=par("id");
        in=gate("in");
        out=gate("out");

        if(address==1)
        {
            cMessage *msg=new cMessage();
            scheduleAt(0,msg);
        }
    }

    void Node::handleMessage(cMessage *msg)
    {

        if(msg->isSelfMessage())
        {
            N_PDU * npkt = new N_PDU();
            npkt->setId(1);
            npkt->setType("Data");
            npkt->setSourceAdd(1);
            npkt->setDestAdd(2);
            send(npkt,out);
        }
        else
        {
            N_PDU * npkt = check_and_cast <N_PDU *> (msg);
            N_PDU * npkt2 = new N_PDU();
            npkt2->setSourceAdd(npkt->getDestAdd());
            npkt2->setDestAdd(npkt->getSourceAdd());

            if(strcmp(npkt->getType(),"Data")==0)
            {
               npkt2->setId(npkt->getId());
               npkt2->setType("Acknowledgment");
               send(npkt2,out);
            }
            else if (npkt -> getId()< 10)
            {
                npkt2->setId(npkt->getId()+1);
                npkt2->setType("Data");
                send(npkt2,out);
            }
      }
 }
