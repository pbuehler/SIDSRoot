 ################################################################################
 #    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    #
 #                                                                              #
 #              This software is distributed under the terms of the             # 
 #         GNU Lesser General Public Licence version 3 (LGPL) version 3,        #  
 #                  copied verbatim in the file "LICENSE"                       #
 ################################################################################
# Create a library called "libFairTestDetector" which includes the source files given in
# the array .
# The extension is already found.  Any number of sources could be listed here.

set(INCLUDE_DIRECTORIES
${BASE_INCLUDE_DIRECTORIES}
${ROOT_INCLUDE_DIR}
${ZMQ_INCLUDE_DIR}
${CMAKE_SOURCE_DIR}/fairmq
${CMAKE_SOURCE_DIR}/base/MQ
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/data
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/MQTask
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/SubTask
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/MQDevice
${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/GUI
)

include_directories(${INCLUDE_DIRECTORIES})


If (Boost_FOUND)
  configure_file( ${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/macro/startEsrSampler.sh.in ${CMAKE_BINARY_DIR}/bin/startEsrSampler.sh )
  configure_file( ${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/macro/startEsrSink.sh.in ${CMAKE_BINARY_DIR}/bin/startEsrSink.sh )
  configure_file( ${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/macro/startPushPull_esr.sh.in ${CMAKE_BINARY_DIR}/bin/startEsrPushPull.sh )
  configure_file( ${CMAKE_SOURCE_DIR}/example/EsrSidsMQ/macro/startVisualAnalysis.sh.in ${CMAKE_BINARY_DIR}/bin/startVisualAnalysis.sh )
EndIf (Boost_FOUND)

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${Boost_LIBRARY_DIRS}
) 

link_directories(${LINK_DIRECTORIES})

Set(SRCS 
    data/EsrSMSEvent.cxx
    data/EsrDecayEvent.cxx
    data/EsrBinDecayEvent.cxx
    data/EsrInjData.cxx
    data/MQconfig.cxx
    SubTask/EsrTree.cxx
    GUI/SidsGui.cxx
    GUI/SidsDecayTxtField.cxx
)

If (Boost_FOUND)
  Set(NO_DICT_SRCS
    MQDevice/EsrSidsSampler.cxx
    MQDevice/EsrFileSink.cxx
    MQTask/EsrSamplerTask.cxx
    #data/FairMQFileSink.cxx
    #data/EsrDecayEvent.cxx
  )
EndIf (Boost_FOUND)

Set(LINKDEF EsrSidsMQLinkDef.h)
Set(LIBRARY_NAME EsrSidsMQ)

If (Boost_FOUND)
  Set(DEPENDENCIES
    Base  FairMQ FairMQSampler boost_thread boost_system boost_serialization boost_filesystem)
EndIf (Boost_FOUND)

GENERATE_LIBRARY()



If (Boost_FOUND)
  Set(Exe_Names
    #EsrMQTestBoost
    EsrMQSamplerBoost
    EsrMQFileSinkBoost
  )

  set(Exe_Source
    #run/runEsrSamplerBoost.cxx
    #run/runEsrSidsTest.cxx
    run/runEsrSampler.cxx
    run/runEsrFileSink.cxx
    )


  List(LENGTH Exe_Names _length)
  Math(EXPR _length ${_length}-1)

  ForEach(_file RANGE 0 ${_length})
    List(GET Exe_Names ${_file} _name)
    List(GET Exe_Source ${_file} _src)
    Set(EXE_NAME ${_name})
    Set(SRCS ${_src})
    Set(DEPENDENCIES EsrSidsMQ)
    GENERATE_EXECUTABLE()
  EndForEach(_file RANGE 0 ${_length})
EndIf (Boost_FOUND)
