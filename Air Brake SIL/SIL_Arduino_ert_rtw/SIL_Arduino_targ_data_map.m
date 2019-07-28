  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (SIL_Arduino_P)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% SIL_Arduino_P.INTAB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_P.INTAB3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3498;
	
	  ;% SIL_Arduino_P.INTAB4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3500;
	
	  ;% SIL_Arduino_P.AnalogInput_SampleTime
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4166;
	
	  ;% SIL_Arduino_P.InitialConditions_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4167;
	
	  ;% SIL_Arduino_P.TmpRTBAtMATLABFunctionInport3_I
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 4169;
	
	  ;% SIL_Arduino_P.Constant_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 4170;
	
	  ;% SIL_Arduino_P.ProportionalGain_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 4171;
	
	  ;% SIL_Arduino_P.Constant1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 4172;
	
	  ;% SIL_Arduino_P.Constant5_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 4173;
	
	  ;% SIL_Arduino_P.Ma07_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 4174;
	
	  ;% SIL_Arduino_P.Constant1_Value_o
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 4175;
	
	  ;% SIL_Arduino_P.Constant_Value_k
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 4176;
	
	  ;% SIL_Arduino_P.StepSize_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 4177;
	
	  ;% SIL_Arduino_P.StepFrequency_Amp
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 4178;
	
	  ;% SIL_Arduino_P.StepFrequency_Period
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 4179;
	
	  ;% SIL_Arduino_P.StepFrequency_Duty
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 4180;
	
	  ;% SIL_Arduino_P.StepFrequency_PhaseDelay
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 4181;
	
	  ;% SIL_Arduino_P.Constant5_Value_k
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 4182;
	
	  ;% SIL_Arduino_P._Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 4183;
	
	  ;% SIL_Arduino_P._Value_b
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 4184;
	
	  ;% SIL_Arduino_P._Value_j
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 4185;
	
	  ;% SIL_Arduino_P.AngleofAirBrakeFlapswhenFullyOp
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 4186;
	
	  ;% SIL_Arduino_P.Constant_Value_l
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 4187;
	
	  ;% SIL_Arduino_P.Constant1_Value_j
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 4188;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Arduino_P.TmpRTBAtNANDInport2_InitialCond
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_P.TmpRTBAtORInport2_InitialCondit
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (SIL_Arduino_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% SIL_Arduino_B.InitialConditions
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% SIL_Arduino_B.ControlSignaluntisofstepperangl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% SIL_Arduino_B.Howfasttostep
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% SIL_Arduino_B.Multiply
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% SIL_Arduino_B.FlapAngle
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% SIL_Arduino_B.zd
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% SIL_Arduino_B.sensor_data
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% SIL_Arduino_B.Cd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Arduino_B.RotaryPositionSensor
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% SIL_Arduino_B.DirectionSignal
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_B.TmpRTBAtNANDInport2
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SIL_Arduino_B.TmpRTBAtORInport2
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    sectIdxOffset = 3;
    
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
    ;% Auto data (SIL_Arduino_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.obj_j
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_DW.obj_k
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.TmpRTBAtMATLABFunctionInport3_B
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_DW.ControlSignal_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 3;
	
	  ;% SIL_Arduino_DW.StepperSignals_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 4;
	
	  ;% SIL_Arduino_DW.Scope3_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 6;
	
	  ;% SIL_Arduino_DW.Scope_PWORK_f.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Arduino_DW.TmpRTBAtNANDInport2_Buffer0
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Arduino_DW.TmpRTBAtORInport2_Buffer0
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
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


  targMap.checksum0 = 1773523283;
  targMap.checksum1 = 1771735041;
  targMap.checksum2 = 2860520602;
  targMap.checksum3 = 526453331;

