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
    ;% Auto data (SIL_Raspi_control_panel_P)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_P.INTAB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_P.INTAB3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3498;
	
	  ;% SIL_Raspi_control_panel_P.INTAB4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3500;
	
	  ;% SIL_Raspi_control_panel_P.I2CMasterRead_SampleTime
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4166;
	
	  ;% SIL_Raspi_control_panel_P.StepCount_Y0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4167;
	
	  ;% SIL_Raspi_control_panel_P.Constant1_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 4168;
	
	  ;% SIL_Raspi_control_panel_P.Constant_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 4169;
	
	  ;% SIL_Raspi_control_panel_P.UnitDelay_InitialCondition
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 4170;
	
	  ;% SIL_Raspi_control_panel_P.InitialConditions_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 4171;
	
	  ;% SIL_Raspi_control_panel_P.TmpRTBAtMATLABFunctionInport3_I
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 4173;
	
	  ;% SIL_Raspi_control_panel_P.Constant_Value_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 4174;
	
	  ;% SIL_Raspi_control_panel_P.ProportionalGain_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 4175;
	
	  ;% SIL_Raspi_control_panel_P.TargetAltitudem_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 4176;
	
	  ;% SIL_Raspi_control_panel_P.Constant5_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 4177;
	
	  ;% SIL_Raspi_control_panel_P.Ma07_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 4178;
	
	  ;% SIL_Raspi_control_panel_P.Constant_Value_m
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 4179;
	
	  ;% SIL_Raspi_control_panel_P.StepSize_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 4180;
	
	  ;% SIL_Raspi_control_panel_P.StepFrequency_Amp
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 4181;
	
	  ;% SIL_Raspi_control_panel_P.StepFrequency_Period
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 4182;
	
	  ;% SIL_Raspi_control_panel_P.StepFrequency_Duty
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 4183;
	
	  ;% SIL_Raspi_control_panel_P.StepFrequency_PhaseDelay
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 4184;
	
	  ;% SIL_Raspi_control_panel_P.Constant5_Value_k
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 4185;
	
	  ;% SIL_Raspi_control_panel_P._Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 4186;
	
	  ;% SIL_Raspi_control_panel_P._Value_d
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 4187;
	
	  ;% SIL_Raspi_control_panel_P._Value_k
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 4188;
	
	  ;% SIL_Raspi_control_panel_P.AngleofAirBrakeFlapswhenFullyOp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 4189;
	
	  ;% SIL_Raspi_control_panel_P.Constant_Value_f
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 4190;
	
	  ;% SIL_Raspi_control_panel_P.Constant1_Value_h
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 4191;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_P.TmpRTBAtNANDInport2_InitialCond
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_P.TmpRTBAtORInport2_InitialCondit
	  section.data(2).logicalSrcIdx = 29;
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
    ;% Auto data (SIL_Raspi_control_panel_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_B.InitialConditions
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% SIL_Raspi_control_panel_B.ControlSignaluntisofstepperangl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% SIL_Raspi_control_panel_B.Howfasttostep
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% SIL_Raspi_control_panel_B.Multiply
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% SIL_Raspi_control_panel_B.FlapAngle
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% SIL_Raspi_control_panel_B.zd
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% SIL_Raspi_control_panel_B.sensor_data
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% SIL_Raspi_control_panel_B.Cd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_B.RotaryPositionSensor
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_B.DirectionSignal
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_B.TmpRTBAtNANDInport2
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SIL_Raspi_control_panel_B.TmpRTBAtORInport2
	  section.data(3).logicalSrcIdx = 13;
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
    nTotSects     = 8;
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
    ;% Auto data (SIL_Raspi_control_panel_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.obj_k
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_DW.obj_f
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_DW.TmpRTBAtMATLABFunctionInport3_B
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_DW.ControlSignal_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 3;
	
	  ;% SIL_Raspi_control_panel_DW.StepperSignals_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 4;
	
	  ;% SIL_Raspi_control_panel_DW.FlapAngle_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 6;
	
	  ;% SIL_Raspi_control_panel_DW.Scope_PWORK_g.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.StepCounter_SubsysRanBC
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% SIL_Raspi_control_panel_DW.TmpRTBAtNANDInport2_Buffer0
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SIL_Raspi_control_panel_DW.TmpRTBAtORInport2_Buffer0
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
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


  targMap.checksum0 = 1256614354;
  targMap.checksum1 = 4189558511;
  targMap.checksum2 = 2396174820;
  targMap.checksum3 = 3932632382;

