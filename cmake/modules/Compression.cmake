# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

function(use_bundled_zlib SOURCE_DIR BINARY_DIR)
 message("Using bundled zlib")
if (WIN32)
 string(TOLOWER "${CMAKE_BUILD_TYPE}" build_type)
 if (build_type MATCHES relwithdebinfo OR build_type MATCHES release)
 set(BYPRODUCT "thirdparty/zlib-src/zlibstatic.lib")
 else()
 set(BYPRODUCT "thirdparty/zlib-src/zlibstaticd.lib")
 endif()
 else()
 set(BYPRODUCT "thirdparty/zlib-src/libz.a")
  endif()
  ExternalProject_Add(
    zlib-external
    BUILD_IN_SOURCE true
    GIT_REPOSITORY "https://github.com/madler/zlib.git"
    GIT_TAG "cacf7f1d4e3d44d871b605da3b647f07d718623f"  # Version 1.2.11
    SOURCE_DIR "${BINARY_DIR}/thirdparty/zlib-src"
    CMAKE_ARGS  "-DCMAKE_POSITION_INDEPENDENT_CODE=ON"
    			"-D_INSTALL_PREFIX=${BINARY_DIR}/thirdparty/zlib-install"
    BUILD_BYPRODUCTS ${BYPRODUCT}
    INSTALL_COMMAND ""
  )


  add_library(z STATIC IMPORTED)
  set_target_properties(z PROPERTIES IMPORTED_LOCATION "${BINARY_DIR}/${BYPRODUCT}")

  set(ZLIB_BYPRODUCT "${BINARY_DIR}/${BYPRODUCT}" CACHE STRING "" FORCE)
  set(ZLIB_BYPRODUCT_INCLUDE "${BINARY_DIR}/thirdparty/zlib-src/" CACHE STRING "" FORCE)
  set(ZLIB_BIN_DIR "${BINARY_DIR}/thirdparty/zlib-src/" CACHE STRING "" FORCE)

  add_dependencies(z zlib-external)
  set(ZLIB_FOUND "YES" CACHE STRING "" FORCE)
  set(ZLIB_INCLUDE_DIR "${ZLIB_BYPRODUCT_INCLUDE}" CACHE STRING "" FORCE)
  set(ZLIB_INCLUDE_DIRS "${ZLIB_BYPRODUCT_INCLUDE}" CACHE STRING "" FORCE)

  set(ZLIB_LIBRARY "${BINARY_DIR}/${BYPRODUCT}" CACHE STRING "" FORCE)
  set(ZLIB_LIBRARIES "${ZLIB_LIBRARY}" CACHE STRING "" FORCE)
  set(ZLIB_LIBRARY_RELEASE "${ZLIB_LIBRARY}" CACHE STRING "" FORCE)
  set(ZLIB_LIBRARY_DEBUG "${ZLIB_LIBRARY}" CACHE STRING "" FORCE)  
  
endfunction(use_bundled_zlib)