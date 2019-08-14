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
    ;% Auto data (SIL_Raspi_P)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% SIL_Raspi_P.INTAB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_P.INTAB3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3498;
	
	  ;% SIL_Raspi_P.INTAB4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3500;
	
	  ;% SIL_Raspi_P.StepCount_Y0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4166;
	
	  ;% SIL_Raspi_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4167;
	
	  ;% SIL_Raspi_P.Constant_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 4168;
	
	  ;% SIL_Raspi_P.UnitDelay_InitialCondition
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 4169;
	
	  ;% SIL_Raspi_P.InitialConditions_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 4170;
	
	  ;% SIL_Raspi_P.Memory_InitialCondition
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 4172;
	
	  ;% SIL_Raspi_P.Constant_Value_o
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 4173;
	
	  ;% SIL_Raspi_P.ProportionalGain_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 4174;
	
	  ;% SIL_Raspi_P.Constant1_Value_m
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 4175;
	
	  ;% SIL_Raspi_P.Constant5_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 4176;
	
	  ;% SIL_Raspi_P.Ma07_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 4177;
	
	  ;% SIL_Raspi_P.Constant_Value_k
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 4178;
	
	  ;% SIL_Raspi_P.AngleofAirBrakeFlapswhenFullyOp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 4179;
	
	  ;% SIL_Raspi_P.Constant_Value_l
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 4180;
	
	  ;% SIL_Raspi_P.Constant1_Value_j
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 4181;
	
	  ;% SIL_Raspi_P.StepSize_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 4182;
	
	  ;% SIL_Raspi_P.StepFrequency_Amp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 4183;
	
	  ;% SIL_Raspi_P.StepFrequency_Period
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 4184;
	
	  ;% SIL_Raspi_P.StepFrequency_Duty
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 4185;
	
	  ;% SIL_Raspi_P.StepFrequency_PhaseDelay
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 4186;
	
	  ;% SIL_Raspi_P.Constant5_Value_k
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 4187;
	
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
    ;% Auto data (SIL_Raspi_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% SIL_Raspi_B.InitialConditions
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_B.Memory
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% SIL_Raspi_B.ControlSignaluntisofstepperangl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% SIL_Raspi_B.Howfasttostep
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% SIL_Raspi_B.Multiply
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% SIL_Raspi_B.zd
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% SIL_Raspi_B.sensor_data
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% SIL_Raspi_B.Cd
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% SIL_Raspi_B.flap_angle
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% SIL_Raspi_B.UnitDelay
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% SIL_Raspi_B.DirectionSignal
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_B.GreaterThan
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SIL_Raspi_B.LessThan
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
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
    nTotSects     = 5;
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
    ;% Auto data (SIL_Raspi_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Raspi_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% SIL_Raspi_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_DW.ControlSignal_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 3;
	
	  ;% SIL_Raspi_DW.StepperSignals_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 4;
	
	  ;% SIL_Raspi_DW.FlapAngle_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_DW.StepCounter_SubsysRanBC
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 2069649503;
  targMap.checksum1 = 1276412655;
  targMap.checksum2 = 1662340380;
  targMap.checksum3 = 164005924;

