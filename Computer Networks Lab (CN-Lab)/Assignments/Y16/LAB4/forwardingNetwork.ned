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

network ForwardingNetwork
{
    submodules:
        NodeA: Node{id = 1;};
        NodeB: Node{id = 2;};
        NodeC: Node{id = 3;};
        NodeD: Node{id = 4;};
        NodeE: Node{id = 5;};
        
    connections allowunconnected:
        NodeA.out1 --> {  delay = 500ms; } --> NodeB.in1;
        NodeA.out2 --> {  delay = 200ms; } --> NodeC.in1;
        NodeA.out3 --> {  delay = 300ms; } --> NodeD.in1;
        NodeB.out1 --> {  delay = 500ms; } --> NodeA.in3;
        NodeB.out2 --> {  delay = 400ms; } --> NodeC.in2;
        NodeB.out3 --> {  delay = 300ms; } --> NodeE.in2;
        NodeC.out1 --> {  delay = 400ms; } --> NodeB.in2;
        NodeC.out2 --> {  delay = 400ms; } --> NodeE.in1;
        NodeC.out3 --> {  delay = 200ms; } --> NodeA.in1;
        NodeD.out1 --> {  delay = 300ms; } --> NodeA.in2;
        NodeE.out1 --> {  delay = 400ms; } --> NodeC.in3;
        NodeE.out2 --> {  delay = 300ms; } --> NodeB.in3;
        
}
