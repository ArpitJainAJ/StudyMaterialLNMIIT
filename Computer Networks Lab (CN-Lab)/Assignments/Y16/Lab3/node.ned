module Node
{
    parameters:
        int id;
        
    gates:
        input in;
        output out;
        //input med_in;
        //output med_out;
        
    submodules:
        application:Application{id_a = id;};
        data_link_layer: Data_link_layer{id_d = id;};
        physical_layer: Physical_layer{id_p = id;};
            
    connections:
        application.app_out --> data_link_layer.data_app_in;
        data_link_layer.data_app_out --> application.app_in;
        data_link_layer.data_phy_out  --> {  delay = 200ms; } --> physical_layer.phy_data_in;
        physical_layer.phy_data_out --> data_link_layer.data_phy_in;
        physical_layer.phy_med_out --> out;
        in --> physical_layer.phy_med_in;
        
}
