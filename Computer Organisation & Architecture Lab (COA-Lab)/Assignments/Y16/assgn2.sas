1,17,#FALSE#,#FALSE#,"assgn2",0,100,0,48,1,6,998528208
0,0,0,0,0,0
0
0
3
"L0",19
"L1",40
"L2:",10
0,2,"MSF",0,0,0,0,#FALSE#
1,0,"PSH #8",0,0,0,0,#FALSE#
5,2,"CAL $L2:",0,0,0,0,#FALSE#
9,2,"HLT",0,0,0,0,#FALSE#
10,-1,"L2:",0,0,0,0,#FALSE#
10,0,"POP R02",0,0,0,0,#FALSE#
13,0,"MOV #0, R01",0,0,0,0,#FALSE#
19,-1,"L0",0,0,0,0,#FALSE#
19,1,"ADD #1, R01",0,0,0,0,#FALSE#
25,2,"MSF",0,0,0,0,#FALSE#
26,2,"CAL $L1",0,0,0,0,#FALSE#
30,3,"CMP R02, R01",0,0,0,0,#FALSE#
35,2,"JNE $L0",0,0,0,0,#FALSE#
39,2,"RET",0,0,0,0,#FALSE#
40,-1,"L1",0,0,0,0,#FALSE#
40,0,"OUT 24, 0",0,0,0,0,#FALSE#
47,2,"RET",0,0,0,0,#FALSE#
0
0
0
-1