cmake_minimum_required(VERSION 3.0)
project(ICPC2)

set(CMAKE_CXX_STANDARD 26)

# Function to create a valid CMake target name from a file path
function(create_target_name file_path target_name_out)
    # Remove the directory part and extension from the file path
    get_filename_component(file_name_we ${file_path} NAME_WE)

    # Replace directory separators with a valid character (underscore)
    string(REPLACE "/" "_" valid_target_name ${file_path})

    # Ensure the target name starts with a character
    string(REGEX REPLACE "^([0-9])" "n\\1" valid_target_name ${valid_target_name})

    # Ensure we do not have double underscores which can happen if there were periods
    string(REPLACE ".." "_" valid_target_name ${valid_target_name})
    string(REPLACE "__" "_" valid_target_name ${valid_target_name})

    # Remove any remaining invalid characters (non-alphanumeric)
    string(REGEX REPLACE "[^a-zA-Z0-9_]" "" valid_target_name ${valid_target_name})

    # Set the output variable
    set(${target_name_out} "${valid_target_name}" PARENT_SCOPE)
endfunction()

# Recursively find all .cpp files in the src directory
file(GLOB_RECURSE ALL_CPP_SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Create a unique target executable for each source file
foreach(SOURCE_FILE ${ALL_CPP_SRCS})
    # Create a valid target name based on the file path
    create_target_name(${SOURCE_FILE} TARGET_NAME)
    message(STATUS "Adding target: ${TARGET_NAME} for source file: ${SOURCE_FILE}")
    add_executable(${TARGET_NAME} ${SOURCE_FILE} "src/readinput.h")
    # Specify where the executable should be placed
    set_target_properties(${TARGET_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${TARGET_NAME}")
endforeach()
