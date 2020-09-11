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


network layerNetwork
{
    @display("bgb=392,135");
    submodules:
        Node1: Node {
            Nid = 1;
            @display("p=39,69");
        }
        Node2: Node {
            Nid = 2;
            @display("p=333,69");
        }

    connections:
        Node1.out --> Node2.in;
        Node2.out --> Node1.in;
}
