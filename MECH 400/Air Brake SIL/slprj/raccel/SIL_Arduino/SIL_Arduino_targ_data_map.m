  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% rtP.INTAB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.INTAB3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3498;
	
	  ;% rtP.INTAB4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3500;
	
	  ;% rtP.PIDController_D
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4166;
	
	  ;% rtP.PIDController_I
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4167;
	
	  ;% rtP.PIDController_InitialConditionForFilter
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 4168;
	
	  ;% rtP.PIDController_InitialConditionForIntegrator
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 4169;
	
	  ;% rtP.PIDController_N
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 4170;
	
	  ;% rtP.PIDController_P
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 4171;
	
	  ;% rtP.StepCount_Y0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 4172;
	
	  ;% rtP.Constant1_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 4173;
	
	  ;% rtP.Constant_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 4174;
	
	  ;% rtP.UnitDelay_InitialCondition
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 4175;
	
	  ;% rtP.Constant1_Value_mq0yqq5e0x
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 4176;
	
	  ;% rtP.Constant5_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 4177;
	
	  ;% rtP.Constant_Value_e5cors3m1f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 4178;
	
	  ;% rtP.Memory_InitialCondition
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 4191;
	
	  ;% rtP.Constant1_Value_oqyl4nphju
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 4192;
	
	  ;% rtP.Constant_Value_knfpzjs1ar
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 4193;
	
	  ;% rtP.AngleofAirBrakeFlapswhenFullyOpendegrees_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 4194;
	
	  ;% rtP.Constant_Value_ldchjia2i4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 4195;
	
	  ;% rtP.Constant1_Value_jsld3gr050
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 4196;
	
	  ;% rtP.StepSize_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 4197;
	
	  ;% rtP.StepFrequency_Amp
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 4198;
	
	  ;% rtP.StepFrequency_Period
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 4199;
	
	  ;% rtP.StepFrequency_Duty
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 4200;
	
	  ;% rtP.StepFrequency_PhaseDelay
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 4201;
	
	  ;% rtP.Constant5_Value_kpkyenjwdq
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 4202;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtB.ahkiafeoia
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.dffpum05ns
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 13;
	
	  ;% rtB.iustumvjtp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 26;
	
	  ;% rtB.ej1lofn5r4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% rtB.n5ewebaudy
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% rtB.gq1bt1ao5w
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% rtB.m1vxg5gqae
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtB.gx0or0kr3s
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% rtB.lwp5elo2wh
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% rtB.k0zs1ouug5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% rtB.fziqurelun
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% rtB.ec3lzwjpul
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% rtB.pgtzcj3xlg
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 36;
	
	  ;% rtB.p5nx0ha0gn
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37;
	
	  ;% rtB.i3wfi0zs3s
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 38;
	
	  ;% rtB.d22mgk2nk4
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 39;
	
	  ;% rtB.oeuf2hmy0o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 40;
	
	  ;% rtB.gvuqr1jt0i
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 53;
	
	  ;% rtB.cc1cd5zhlf
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 57;
	
	  ;% rtB.flslv0y4cj
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 58;
	
	  ;% rtB.l0euqgxhm0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.a0thuhlkvf
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.nu2anqwsoh
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bnnyzhf4hd
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.moxilmktys
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.kxv5tb5r11
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.lyitfitoch.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jcuwij5dpk.AQHandles
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.hrqoqhtymu.AQHandles
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.fa1rhasmp4.AQHandles
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.iq00tkmc3j.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.egyz1gl0dl.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.caeszugdbc.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtDW.k53fkqd2g2.AQHandles
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.ig2uo5piti
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.av0mpygxcu
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.ix0gnlc2nc
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hef1fu14qj
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.kijlfweplt
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.fwrbx3e2f1
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gld15yigj5
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.em2vdfypg1
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2887184815;
  targMap.checksum1 = 2526773862;
  targMap.checksum2 = 209535582;
  targMap.checksum3 = 2430258776;

