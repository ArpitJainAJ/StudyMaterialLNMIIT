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

#ifndef __LAB4_NODE_H_
#define __LAB4_NODE_H_

#include <omnetpp.h>
#include <map>

using namespace omnetpp;
using namespace std;

/**
 * TODO - Generated class
 */
class Node : public cSimpleModule
{
protected:

    cGate* inG;
    cGate* outG;
    int id;
    int src;
    int dest;
    int nop;
    cGate* in1;
    cGate* in2;
    cGate* in3;
    cGate* out1;
    cGate* out2;
    cGate* out3;

    map<int ,cGate*> rTable;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
