set(TARGET "mypth2")

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/${TARGET}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/${TARGET}/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/src/${TARGET}")

# Bin
set(BIN "${TARGET}")
add_executable(${BIN} ${SOURCES} ${HEADERS})

set_target_properties(${BIN} PROPERTIES OUTPUT_NAME "${TARGET}")

