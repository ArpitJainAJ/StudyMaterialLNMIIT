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

#ifndef __ASSIGNMENT2_DATALINKLAYER_H_
#define __ASSIGNMENT2_DATALINKLAYER_H_

#include <omnetpp.h>
#include "DN_PDU_m.h"
#include "N_PDU_m.h"
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class DataLinkLayer : public cSimpleModule
{
    private:
        cMessage *timeoutEvent;
    protected:
        int address;
        cGate *fromNode;
        cGate *fromNLL;
        cGate *toNode;
        cGate *toNLL;
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void SendCopyOfDNPDU(DN_PDU* copymsg);
};

#endif
