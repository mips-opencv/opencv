set(CMAKE_SYSTEM_PROCESSOR mips64r6el)
set(GCC_COMPILER_VERSION "" CACHE STRING "GCC Compiler version")
set(GNU_MACHINE "mipsisa64r6el-linux-gnuabi64" CACHE STRING "GNU compiler triple")
include("${CMAKE_CURRENT_LIST_DIR}/mips.toolchain.cmake")
