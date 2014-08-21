set(INCLUDE_DIRECTORIES
${BASE_INCLUDE_DIRECTORIES}
${ROOT_INCLUDE_DIR}
${ZMQ_INCLUDE_DIR}
${CUBA_INCLUDE_DIR}
${BAT_INCLUDE_DIR}
#${CMAKE_SOURCE_DIR}/example/BayesianAnalysis
#${CMAKE_SOURCE_DIR}/example/BayesianAnalysis/src
#${CMAKE_SOURCE_DIR}/example/BayesianAnalysis/src/model
#${CMAKE_SOURCE_DIR}/example/BayesianAnalysis/src/macro
#${CMAKE_SOURCE_DIR}/example/BayesianAnalysis/src/data
)
include_directories(${INCLUDE_DIRECTORIES})
set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${Boost_LIBRARY_DIRS}
) 

# todo : migrate bayesian code here