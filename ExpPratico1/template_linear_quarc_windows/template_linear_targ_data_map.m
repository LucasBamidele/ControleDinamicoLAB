  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (template_linear_P)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% template_linear_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% template_linear_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% template_linear_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% template_linear_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% template_linear_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% template_linear_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% template_linear_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% template_linear_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% template_linear_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% template_linear_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% template_linear_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% template_linear_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% template_linear_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% template_linear_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% template_linear_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% template_linear_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% template_linear_P.cartcountstometers_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% template_linear_P.mTomm_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% template_linear_P.HPFderivativefollowedbyaLPF_A
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% template_linear_P.HPFderivativefollowedbyaLPF_C
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% template_linear_P.HPFderivativefollowedbyaLPF_D
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% template_linear_P.SignalGenerator_Amplitude
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% template_linear_P.SignalGenerator_Frequency
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% template_linear_P.RateLimiter_RisingLim
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 24;
	
	  ;% template_linear_P.RateLimiter_FallingLim
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 25;
	
	  ;% template_linear_P.Saturation_UpperSat
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 26;
	
	  ;% template_linear_P.Saturation_LowerSat
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% template_linear_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 3;
	
	  ;% template_linear_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 4;
	
	  ;% template_linear_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 5;
	
	  ;% template_linear_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 6;
	
	  ;% template_linear_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 7;
	
	  ;% template_linear_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 35;
	  section.data(7).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% template_linear_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 8;
	
	  ;% template_linear_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 16;
	
	  ;% template_linear_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 24;
	
	  ;% template_linear_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 32;
	
	  ;% template_linear_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 33;
	
	  ;% template_linear_P.HILReadEncoder_Channels
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 41;
	
	  ;% template_linear_P.HILWriteAnalog_Channels
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% template_linear_P.Constant_Value
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% template_linear_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
	  ;% template_linear_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 2;
	
	  ;% template_linear_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 3;
	
	  ;% template_linear_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 50;
	  section.data(5).dtTransOffset = 4;
	
	  ;% template_linear_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 51;
	  section.data(6).dtTransOffset = 5;
	
	  ;% template_linear_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 52;
	  section.data(7).dtTransOffset = 6;
	
	  ;% template_linear_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 53;
	  section.data(8).dtTransOffset = 7;
	
	  ;% template_linear_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 54;
	  section.data(9).dtTransOffset = 8;
	
	  ;% template_linear_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 55;
	  section.data(10).dtTransOffset = 9;
	
	  ;% template_linear_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 56;
	  section.data(11).dtTransOffset = 10;
	
	  ;% template_linear_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 57;
	  section.data(12).dtTransOffset = 11;
	
	  ;% template_linear_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 58;
	  section.data(13).dtTransOffset = 12;
	
	  ;% template_linear_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 59;
	  section.data(14).dtTransOffset = 13;
	
	  ;% template_linear_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 60;
	  section.data(15).dtTransOffset = 14;
	
	  ;% template_linear_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 61;
	  section.data(16).dtTransOffset = 15;
	
	  ;% template_linear_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 62;
	  section.data(17).dtTransOffset = 16;
	
	  ;% template_linear_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 63;
	  section.data(18).dtTransOffset = 17;
	
	  ;% template_linear_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 64;
	  section.data(19).dtTransOffset = 18;
	
	  ;% template_linear_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 65;
	  section.data(20).dtTransOffset = 19;
	
	  ;% template_linear_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 66;
	  section.data(21).dtTransOffset = 20;
	
	  ;% template_linear_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 67;
	  section.data(22).dtTransOffset = 21;
	
	  ;% template_linear_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 68;
	  section.data(23).dtTransOffset = 22;
	
	  ;% template_linear_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 69;
	  section.data(24).dtTransOffset = 23;
	
	  ;% template_linear_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 70;
	  section.data(25).dtTransOffset = 24;
	
	  ;% template_linear_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 71;
	  section.data(26).dtTransOffset = 25;
	
	  ;% template_linear_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 72;
	  section.data(27).dtTransOffset = 26;
	
	  ;% template_linear_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 73;
	  section.data(28).dtTransOffset = 27;
	
	  ;% template_linear_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 74;
	  section.data(29).dtTransOffset = 28;
	
	  ;% template_linear_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 75;
	  section.data(30).dtTransOffset = 29;
	
	  ;% template_linear_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 76;
	  section.data(31).dtTransOffset = 30;
	
	  ;% template_linear_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 77;
	  section.data(32).dtTransOffset = 31;
	
	  ;% template_linear_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 78;
	  section.data(33).dtTransOffset = 32;
	
	  ;% template_linear_P.HILReadEncoder_Active
	  section.data(34).logicalSrcIdx = 79;
	  section.data(34).dtTransOffset = 33;
	
	  ;% template_linear_P.HILWriteAnalog_Active
	  section.data(35).logicalSrcIdx = 80;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (template_linear_B)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% template_linear_B.mTomm
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_B.HPFderivativefollowedbyaLPF
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% template_linear_B.SignalGenerator
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% template_linear_B.RateLimiter
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% template_linear_B.SwitchControl
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    sectIdxOffset = 1;
    
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
    ;% Auto data (template_linear_DWork)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% template_linear_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% template_linear_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% template_linear_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% template_linear_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% template_linear_DWork.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% template_linear_DWork.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% template_linear_DWork.PrevY
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% template_linear_DWork.LastMajorTime
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_DWork.CartPositionmm_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% template_linear_DWork.CartVelocitymms_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% template_linear_DWork.HILWriteAnalog_PWORK
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% template_linear_DWork.MotorVoltageV_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% template_linear_DWork.ToFile_PWORK.FilePtr
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% template_linear_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 3;
	
	  ;% template_linear_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 11;
	
	  ;% template_linear_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 19;
	
	  ;% template_linear_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 27;
	
	  ;% template_linear_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 35;
	
	  ;% template_linear_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 43;
	
	  ;% template_linear_DWork.HILReadEncoder_Buffer
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% template_linear_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% template_linear_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
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


  targMap.checksum0 = 4167139517;
  targMap.checksum1 = 2819575112;
  targMap.checksum2 = 1575769901;
  targMap.checksum3 = 3072127818;

