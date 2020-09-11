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

module Node
{
    parameters:
        int Nid;

        @display("bgb=253,114");
    gates:
        input in;
        output out;

    submodules:
        NLL: NetworkLinkLayer {
            NLLid = Nid;
            @display("p=67,59");
        }
        DLL: DataLinkLayer {
            DLLid = Nid;
            @display("p=204,59");
        }

    connections:
        NLL.toDLL --> DLL.fromNLL;
        DLL.toNLL --> NLL.fromDLL;
        DLL.toNode --> out;
        in --> DLL.fromNode;
}
