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
#include "Pkt_m.h"

Define_Module(Node);

void Node::initialize()
{

    int id=par("id");
    int src=par("src");
    int dest=par("dest");
    int nop=par("nop");
    in1 = gate("in1");
    in2 = gate("in2");
    in3 = gate("in3");
    out1 = gate("out1");
    out2 = gate("out2");
    out3 = gate("out3");

    if(id == 1)
    {
        rTable[2]=out1;
        rTable[3]=out2;
        rTable[4]=out3;
        rTable[5]=out2;
    }
    else if(id == 2)
    {
        rTable[1]=out1;
        rTable[3]=out2;
        rTable[4]=out1;
        rTable[5]=out3;
    }
    else if(id == 3)
    {
        rTable[1]=out3;
        rTable[2]=out1;
        rTable[4]=out3;
        rTable[5]=out2;
    }
    else if(id == 4)
    {
        rTable[1]=out1;
        rTable[2]=out1;
        rTable[3]=out1;
        rTable[5]=out1;
    }
    else if(id == 5)
    {
        rTable[1]=out1;
        rTable[2]=out2;
        rTable[3]=out1;
        rTable[4]=out1;
    }
    if (id == src)
    {
        Pkt *pkt = new Pkt();
        pkt->setType("Self");
        pkt->setSrc(src);
        pkt->setDest(dest);
        pkt->setId(0);
        scheduleAt(0,pkt);

    }
}

void Node::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        Pkt *p=check_and_cast<Pkt*>(msg);
        Pkt *n=new Pkt();
        n->setType("Data");
        n->setId(p->getId()+1);
        n->setSrc(src);
        n->setDest(dest);
        send(n,rTable[p->getDest()]);

    }
    else
       {
           Pkt *p=check_and_cast<Pkt*>(msg);

           if(id==p->getDest())
           {
               if(strcmp(p->getType(),"Data")==0)
               {
                   Pkt *n=new Pkt();
                   n->setType("Ack");
                   n->setSrc(p->getDest());
                   n->setDest(p->getSrc());
                   n->setId(p->getId());
                   send(n,rTable[n->getDest()]);

               }
               else
               {
                   EV<<"NO "<<p->getId()<<"\n";
                   if(p->getId()>=nop)
                       return;
                   else
                   {
                       Pkt *n=new Pkt();
                       n->setType("Data");
                       n->setId(p->getId()+1);
                       n->setSrc(p->getDest());
                       n->setDest(p->getSrc());
                       send(n,rTable[n->getDest()]);

                   }
               }
           }
           else
           {
               send(p,rTable[p->getDest()]);

           }
       }
}
