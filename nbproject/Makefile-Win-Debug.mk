#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=
CCC=
CXX=
FC=
AS=

# Macros
CND_PLATFORM=Cygwin_4.x-Linux-x86
CND_CONF=Win-Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ConnectionPool.o \
	${OBJECTDIR}/src/Connection.o \
	${OBJECTDIR}/src/DataBuffer.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Win-Debug.mk dist/Win-Debug/Cygwin_4.x-Linux-x86/libmini-net.a

dist/Win-Debug/Cygwin_4.x-Linux-x86/libmini-net.a: ${OBJECTFILES}
	${MKDIR} -p dist/Win-Debug/Cygwin_4.x-Linux-x86
	${RM} dist/Win-Debug/Cygwin_4.x-Linux-x86/libmini-net.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmini-net.a ${OBJECTFILES} 
	$(RANLIB) dist/Win-Debug/Cygwin_4.x-Linux-x86/libmini-net.a

${OBJECTDIR}/src/ConnectionPool.o: src/ConnectionPool.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ConnectionPool.o src/ConnectionPool.cpp

${OBJECTDIR}/src/Connection.o: src/Connection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Connection.o src/Connection.cpp

${OBJECTDIR}/src/DataBuffer.o: src/DataBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/DataBuffer.o src/DataBuffer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Win-Debug
	${RM} dist/Win-Debug/Cygwin_4.x-Linux-x86/libmini-net.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
