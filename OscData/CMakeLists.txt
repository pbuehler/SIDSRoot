 # Create a library called "libOscData" 

set(INCLUDE_DIRECTORIES
${ROOT_INCLUDE_DIR} 
${BASE_INCLUDE_DIRECTORIES}
${CMAKE_SOURCE_DIR}/OscData
)

include_directories( ${INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
${CMAKE_SOURCE_DIR}/OscData

)
 
link_directories( ${LINK_DIRECTORIES})

set(SRCS
OscStack.cxx 
OscMCTrack.cxx
)

Set(HEADERS )
Set(LINKDEF MCStackLinkDef.h)
Set(LIBRARY_NAME OscData)
Set(DEPENDENCIES Base EG Physics Cint Core)

GENERATE_LIBRARY()

