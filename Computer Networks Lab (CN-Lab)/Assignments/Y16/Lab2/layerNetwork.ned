network LayerNetwork
{
    submodules:
        Node1: Node{id = 1;};
        Node2: Node{id = 2;};
        //tic: Delay_channel {
        //    parameters:
        //        @display("i=,cyan"); // do not change the icon (first arg of i=) just colorize it
        //}
        //toc: Delay_channel {
        //    parameters:
        //        @display("i=,gold"); // here too
        //}
        
    connections:
        Node1.out --> {  delay = 200ms; } --> Node2.in;
        Node2.out --> {  delay = 200ms; } --> Node1.in;
        //toc.delay_med_out --> Node1.med_in;        
        //tic.delay_med_out --> Node2.med_in;
        
        //tic.out --> {  delay = 100ms; } --> toc.in;
        //tic.in <-- {  delay = 100ms; } <-- toc.out;
}
