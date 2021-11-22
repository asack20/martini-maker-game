#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=FrameworkSource/ES_CheckEvents.c FrameworkSource/ES_DeferRecall.c FrameworkSource/ES_Framework.c FrameworkSource/ES_LookupTables.c FrameworkSource/ES_Port.c FrameworkSource/ES_PostList.c FrameworkSource/ES_Queue.c FrameworkSource/ES_Timers.c FrameworkSource/terminal.c FrameworkSource/circular_buffer_no_modulo_threadsafe.c FrameworkSource/dbprintf.c HALs/FontStuff.c HALs/PIC32_SPI_HAL.c HALs/PIC32PortHAL.c HALs/PWM_PIC32.c HALs/PIC32_AD_Lib.c HALs/DM_Display_2.c HALs/DM_Display.c ProjectSource/EventCheckers.c ProjectSource/main.c Services/ClockService.c Services/DoorService.c Services/GameMain.c Services/HapticService.c Services/ShakeService.c Services/StartButtonService.c PourService/AnalogChecker.c PourService/PourService.c Services/AddIngredientsHelperService.c Services/P2PComm.c MainDisplay/DisplayFSM.c MainDisplay/MainDisplayService.c TestHarnesses/TestGameMain.c TestHarnesses/TestDistanceSensor.c TestHarnesses/TestShakeService.c TestHarnesses/ServoTest.c TestHarnesses/TestP2PService.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o ${OBJECTDIR}/FrameworkSource/ES_Framework.o ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o ${OBJECTDIR}/FrameworkSource/ES_Port.o ${OBJECTDIR}/FrameworkSource/ES_PostList.o ${OBJECTDIR}/FrameworkSource/ES_Queue.o ${OBJECTDIR}/FrameworkSource/ES_Timers.o ${OBJECTDIR}/FrameworkSource/terminal.o ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o ${OBJECTDIR}/FrameworkSource/dbprintf.o ${OBJECTDIR}/HALs/FontStuff.o ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o ${OBJECTDIR}/HALs/PIC32PortHAL.o ${OBJECTDIR}/HALs/PWM_PIC32.o ${OBJECTDIR}/HALs/PIC32_AD_Lib.o ${OBJECTDIR}/HALs/DM_Display_2.o ${OBJECTDIR}/HALs/DM_Display.o ${OBJECTDIR}/ProjectSource/EventCheckers.o ${OBJECTDIR}/ProjectSource/main.o ${OBJECTDIR}/Services/ClockService.o ${OBJECTDIR}/Services/DoorService.o ${OBJECTDIR}/Services/GameMain.o ${OBJECTDIR}/Services/HapticService.o ${OBJECTDIR}/Services/ShakeService.o ${OBJECTDIR}/Services/StartButtonService.o ${OBJECTDIR}/PourService/AnalogChecker.o ${OBJECTDIR}/PourService/PourService.o ${OBJECTDIR}/Services/AddIngredientsHelperService.o ${OBJECTDIR}/Services/P2PComm.o ${OBJECTDIR}/MainDisplay/DisplayFSM.o ${OBJECTDIR}/MainDisplay/MainDisplayService.o ${OBJECTDIR}/TestHarnesses/TestGameMain.o ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o ${OBJECTDIR}/TestHarnesses/TestShakeService.o ${OBJECTDIR}/TestHarnesses/ServoTest.o ${OBJECTDIR}/TestHarnesses/TestP2PService.o
POSSIBLE_DEPFILES=${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o.d ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o.d ${OBJECTDIR}/FrameworkSource/ES_Framework.o.d ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o.d ${OBJECTDIR}/FrameworkSource/ES_Port.o.d ${OBJECTDIR}/FrameworkSource/ES_PostList.o.d ${OBJECTDIR}/FrameworkSource/ES_Queue.o.d ${OBJECTDIR}/FrameworkSource/ES_Timers.o.d ${OBJECTDIR}/FrameworkSource/terminal.o.d ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o.d ${OBJECTDIR}/FrameworkSource/dbprintf.o.d ${OBJECTDIR}/HALs/FontStuff.o.d ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o.d ${OBJECTDIR}/HALs/PIC32PortHAL.o.d ${OBJECTDIR}/HALs/PWM_PIC32.o.d ${OBJECTDIR}/HALs/PIC32_AD_Lib.o.d ${OBJECTDIR}/HALs/DM_Display_2.o.d ${OBJECTDIR}/HALs/DM_Display.o.d ${OBJECTDIR}/ProjectSource/EventCheckers.o.d ${OBJECTDIR}/ProjectSource/main.o.d ${OBJECTDIR}/Services/ClockService.o.d ${OBJECTDIR}/Services/DoorService.o.d ${OBJECTDIR}/Services/GameMain.o.d ${OBJECTDIR}/Services/HapticService.o.d ${OBJECTDIR}/Services/ShakeService.o.d ${OBJECTDIR}/Services/StartButtonService.o.d ${OBJECTDIR}/PourService/AnalogChecker.o.d ${OBJECTDIR}/PourService/PourService.o.d ${OBJECTDIR}/Services/AddIngredientsHelperService.o.d ${OBJECTDIR}/Services/P2PComm.o.d ${OBJECTDIR}/MainDisplay/DisplayFSM.o.d ${OBJECTDIR}/MainDisplay/MainDisplayService.o.d ${OBJECTDIR}/TestHarnesses/TestGameMain.o.d ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o.d ${OBJECTDIR}/TestHarnesses/TestShakeService.o.d ${OBJECTDIR}/TestHarnesses/ServoTest.o.d ${OBJECTDIR}/TestHarnesses/TestP2PService.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o ${OBJECTDIR}/FrameworkSource/ES_Framework.o ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o ${OBJECTDIR}/FrameworkSource/ES_Port.o ${OBJECTDIR}/FrameworkSource/ES_PostList.o ${OBJECTDIR}/FrameworkSource/ES_Queue.o ${OBJECTDIR}/FrameworkSource/ES_Timers.o ${OBJECTDIR}/FrameworkSource/terminal.o ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o ${OBJECTDIR}/FrameworkSource/dbprintf.o ${OBJECTDIR}/HALs/FontStuff.o ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o ${OBJECTDIR}/HALs/PIC32PortHAL.o ${OBJECTDIR}/HALs/PWM_PIC32.o ${OBJECTDIR}/HALs/PIC32_AD_Lib.o ${OBJECTDIR}/HALs/DM_Display_2.o ${OBJECTDIR}/HALs/DM_Display.o ${OBJECTDIR}/ProjectSource/EventCheckers.o ${OBJECTDIR}/ProjectSource/main.o ${OBJECTDIR}/Services/ClockService.o ${OBJECTDIR}/Services/DoorService.o ${OBJECTDIR}/Services/GameMain.o ${OBJECTDIR}/Services/HapticService.o ${OBJECTDIR}/Services/ShakeService.o ${OBJECTDIR}/Services/StartButtonService.o ${OBJECTDIR}/PourService/AnalogChecker.o ${OBJECTDIR}/PourService/PourService.o ${OBJECTDIR}/Services/AddIngredientsHelperService.o ${OBJECTDIR}/Services/P2PComm.o ${OBJECTDIR}/MainDisplay/DisplayFSM.o ${OBJECTDIR}/MainDisplay/MainDisplayService.o ${OBJECTDIR}/TestHarnesses/TestGameMain.o ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o ${OBJECTDIR}/TestHarnesses/TestShakeService.o ${OBJECTDIR}/TestHarnesses/ServoTest.o ${OBJECTDIR}/TestHarnesses/TestP2PService.o

# Source Files
SOURCEFILES=FrameworkSource/ES_CheckEvents.c FrameworkSource/ES_DeferRecall.c FrameworkSource/ES_Framework.c FrameworkSource/ES_LookupTables.c FrameworkSource/ES_Port.c FrameworkSource/ES_PostList.c FrameworkSource/ES_Queue.c FrameworkSource/ES_Timers.c FrameworkSource/terminal.c FrameworkSource/circular_buffer_no_modulo_threadsafe.c FrameworkSource/dbprintf.c HALs/FontStuff.c HALs/PIC32_SPI_HAL.c HALs/PIC32PortHAL.c HALs/PWM_PIC32.c HALs/PIC32_AD_Lib.c HALs/DM_Display_2.c HALs/DM_Display.c ProjectSource/EventCheckers.c ProjectSource/main.c Services/ClockService.c Services/DoorService.c Services/GameMain.c Services/HapticService.c Services/ShakeService.c Services/StartButtonService.c PourService/AnalogChecker.c PourService/PourService.c Services/AddIngredientsHelperService.c Services/P2PComm.c MainDisplay/DisplayFSM.c MainDisplay/MainDisplayService.c TestHarnesses/TestGameMain.c TestHarnesses/TestDistanceSensor.c TestHarnesses/TestShakeService.c TestHarnesses/ServoTest.c TestHarnesses/TestP2PService.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX170F256B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o: FrameworkSource/ES_CheckEvents.c  .generated_files/flags/default/2809e4bbc19abea2989629b3e604c526ed947b23 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o FrameworkSource/ES_CheckEvents.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o: FrameworkSource/ES_DeferRecall.c  .generated_files/flags/default/f013c0ee74fffdc04e1df1d3503bcf1655b28c41 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o FrameworkSource/ES_DeferRecall.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Framework.o: FrameworkSource/ES_Framework.c  .generated_files/flags/default/c432a0d89c89ffaabfe62718a1f02b26b08fd6a3 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Framework.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Framework.o FrameworkSource/ES_Framework.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_LookupTables.o: FrameworkSource/ES_LookupTables.c  .generated_files/flags/default/9f9a397fe5d55205f243ee2dbcd476031dfec48 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_LookupTables.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o FrameworkSource/ES_LookupTables.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Port.o: FrameworkSource/ES_Port.c  .generated_files/flags/default/a8499ef826e2dc948d5214bae22f16bda2a6a9a5 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Port.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Port.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Port.o FrameworkSource/ES_Port.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_PostList.o: FrameworkSource/ES_PostList.c  .generated_files/flags/default/f010d350e8e7dbc4587a03497ffbb55719d5aded .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_PostList.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_PostList.o FrameworkSource/ES_PostList.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Queue.o: FrameworkSource/ES_Queue.c  .generated_files/flags/default/f1662cee99bf10bdd9effb0f4a3b9cb7f357be2d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Queue.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Queue.o FrameworkSource/ES_Queue.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Timers.o: FrameworkSource/ES_Timers.c  .generated_files/flags/default/333ca07e37f443f8c0298523c9514b96d3e56c04 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Timers.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Timers.o FrameworkSource/ES_Timers.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/terminal.o: FrameworkSource/terminal.c  .generated_files/flags/default/a747d926af12c06fdb87bbd27d810af2d5f683fc .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/terminal.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/terminal.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/terminal.o.d" -o ${OBJECTDIR}/FrameworkSource/terminal.o FrameworkSource/terminal.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o: FrameworkSource/circular_buffer_no_modulo_threadsafe.c  .generated_files/flags/default/34534995bbc3bee7959e85e3ea7f8e215b5be9d4 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o.d" -o ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o FrameworkSource/circular_buffer_no_modulo_threadsafe.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/dbprintf.o: FrameworkSource/dbprintf.c  .generated_files/flags/default/4a741b4a703f6b7f4b7eab63938b79076b2f73a0 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/dbprintf.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/dbprintf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/dbprintf.o.d" -o ${OBJECTDIR}/FrameworkSource/dbprintf.o FrameworkSource/dbprintf.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/FontStuff.o: HALs/FontStuff.c  .generated_files/flags/default/3d4670d8bc6638cfe27af012d3a08ab07cf0788b .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/FontStuff.o.d 
	@${RM} ${OBJECTDIR}/HALs/FontStuff.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/FontStuff.o.d" -o ${OBJECTDIR}/HALs/FontStuff.o HALs/FontStuff.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32_SPI_HAL.o: HALs/PIC32_SPI_HAL.c  .generated_files/flags/default/58afbe30c30ae2694117e2c7ac4e88cc585bbbb5 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32_SPI_HAL.o.d" -o ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o HALs/PIC32_SPI_HAL.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32PortHAL.o: HALs/PIC32PortHAL.c  .generated_files/flags/default/974f0d4886dba8629010a2fd215e675c10ced6f3 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32PortHAL.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32PortHAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32PortHAL.o.d" -o ${OBJECTDIR}/HALs/PIC32PortHAL.o HALs/PIC32PortHAL.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PWM_PIC32.o: HALs/PWM_PIC32.c  .generated_files/flags/default/3030acbab5c16b6757a61a132db274e2a61c6e0c .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PWM_PIC32.o.d 
	@${RM} ${OBJECTDIR}/HALs/PWM_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PWM_PIC32.o.d" -o ${OBJECTDIR}/HALs/PWM_PIC32.o HALs/PWM_PIC32.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32_AD_Lib.o: HALs/PIC32_AD_Lib.c  .generated_files/flags/default/dfa55f10c299b4e4a4bdbf3aa245838b84e87f59 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32_AD_Lib.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32_AD_Lib.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32_AD_Lib.o.d" -o ${OBJECTDIR}/HALs/PIC32_AD_Lib.o HALs/PIC32_AD_Lib.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/DM_Display_2.o: HALs/DM_Display_2.c  .generated_files/flags/default/8927a08ab6f97b58e7b7fb18a143b76096cd0a97 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/DM_Display_2.o.d 
	@${RM} ${OBJECTDIR}/HALs/DM_Display_2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/DM_Display_2.o.d" -o ${OBJECTDIR}/HALs/DM_Display_2.o HALs/DM_Display_2.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/DM_Display.o: HALs/DM_Display.c  .generated_files/flags/default/21576e17eebbac6cbb24cb0cde3d0112044b50c1 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/DM_Display.o.d 
	@${RM} ${OBJECTDIR}/HALs/DM_Display.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/DM_Display.o.d" -o ${OBJECTDIR}/HALs/DM_Display.o HALs/DM_Display.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ProjectSource/EventCheckers.o: ProjectSource/EventCheckers.c  .generated_files/flags/default/8cd7b9f09825c354d50436939856f5f9d70f83f .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/ProjectSource" 
	@${RM} ${OBJECTDIR}/ProjectSource/EventCheckers.o.d 
	@${RM} ${OBJECTDIR}/ProjectSource/EventCheckers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/ProjectSource/EventCheckers.o.d" -o ${OBJECTDIR}/ProjectSource/EventCheckers.o ProjectSource/EventCheckers.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ProjectSource/main.o: ProjectSource/main.c  .generated_files/flags/default/9ccbdf7fd5af2b62cd315990e3edca21bd931dcc .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/ProjectSource" 
	@${RM} ${OBJECTDIR}/ProjectSource/main.o.d 
	@${RM} ${OBJECTDIR}/ProjectSource/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/ProjectSource/main.o.d" -o ${OBJECTDIR}/ProjectSource/main.o ProjectSource/main.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/ClockService.o: Services/ClockService.c  .generated_files/flags/default/3f0bab3e5401fdc59130d6f53dbdb80ff1176f23 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/ClockService.o.d 
	@${RM} ${OBJECTDIR}/Services/ClockService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/ClockService.o.d" -o ${OBJECTDIR}/Services/ClockService.o Services/ClockService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/DoorService.o: Services/DoorService.c  .generated_files/flags/default/6b23c7afb316cac42beae497d4ea0bcc6a267bd9 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/DoorService.o.d 
	@${RM} ${OBJECTDIR}/Services/DoorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/DoorService.o.d" -o ${OBJECTDIR}/Services/DoorService.o Services/DoorService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/GameMain.o: Services/GameMain.c  .generated_files/flags/default/4e4ca43ad764c971bdc26b0ededd79971e5bbda4 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/GameMain.o.d 
	@${RM} ${OBJECTDIR}/Services/GameMain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/GameMain.o.d" -o ${OBJECTDIR}/Services/GameMain.o Services/GameMain.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/HapticService.o: Services/HapticService.c  .generated_files/flags/default/cf55f873c9ae4cc1c82b867ed4fc746337715c8b .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/HapticService.o.d 
	@${RM} ${OBJECTDIR}/Services/HapticService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/HapticService.o.d" -o ${OBJECTDIR}/Services/HapticService.o Services/HapticService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/ShakeService.o: Services/ShakeService.c  .generated_files/flags/default/c927d5a668c1396c6fe76480f909978db8be3578 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/ShakeService.o.d 
	@${RM} ${OBJECTDIR}/Services/ShakeService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/ShakeService.o.d" -o ${OBJECTDIR}/Services/ShakeService.o Services/ShakeService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/StartButtonService.o: Services/StartButtonService.c  .generated_files/flags/default/10b7b5de437286b4c97965d076863b193287d7b8 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/StartButtonService.o.d 
	@${RM} ${OBJECTDIR}/Services/StartButtonService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/StartButtonService.o.d" -o ${OBJECTDIR}/Services/StartButtonService.o Services/StartButtonService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PourService/AnalogChecker.o: PourService/AnalogChecker.c  .generated_files/flags/default/bbda82a15cfeb059ccdef535573d97db9953950d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/PourService" 
	@${RM} ${OBJECTDIR}/PourService/AnalogChecker.o.d 
	@${RM} ${OBJECTDIR}/PourService/AnalogChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/PourService/AnalogChecker.o.d" -o ${OBJECTDIR}/PourService/AnalogChecker.o PourService/AnalogChecker.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PourService/PourService.o: PourService/PourService.c  .generated_files/flags/default/b790acb77f69a00a37dd3a6fbb91651d16d61211 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/PourService" 
	@${RM} ${OBJECTDIR}/PourService/PourService.o.d 
	@${RM} ${OBJECTDIR}/PourService/PourService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/PourService/PourService.o.d" -o ${OBJECTDIR}/PourService/PourService.o PourService/PourService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/AddIngredientsHelperService.o: Services/AddIngredientsHelperService.c  .generated_files/flags/default/d4a07c66249a2e817247ec39c3a703b7fdc1ca99 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/AddIngredientsHelperService.o.d 
	@${RM} ${OBJECTDIR}/Services/AddIngredientsHelperService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/AddIngredientsHelperService.o.d" -o ${OBJECTDIR}/Services/AddIngredientsHelperService.o Services/AddIngredientsHelperService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/P2PComm.o: Services/P2PComm.c  .generated_files/flags/default/fa487c1c028d569daa2d31dfa0a0b90d596ad2d1 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/P2PComm.o.d 
	@${RM} ${OBJECTDIR}/Services/P2PComm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/P2PComm.o.d" -o ${OBJECTDIR}/Services/P2PComm.o Services/P2PComm.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainDisplay/DisplayFSM.o: MainDisplay/DisplayFSM.c  .generated_files/flags/default/84ab777b4b103f312e4dc9ce1f392abcea22a0ff .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/MainDisplay" 
	@${RM} ${OBJECTDIR}/MainDisplay/DisplayFSM.o.d 
	@${RM} ${OBJECTDIR}/MainDisplay/DisplayFSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/MainDisplay/DisplayFSM.o.d" -o ${OBJECTDIR}/MainDisplay/DisplayFSM.o MainDisplay/DisplayFSM.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainDisplay/MainDisplayService.o: MainDisplay/MainDisplayService.c  .generated_files/flags/default/8255a63e66f128204b7da90ae1c388ed93769cfa .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/MainDisplay" 
	@${RM} ${OBJECTDIR}/MainDisplay/MainDisplayService.o.d 
	@${RM} ${OBJECTDIR}/MainDisplay/MainDisplayService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/MainDisplay/MainDisplayService.o.d" -o ${OBJECTDIR}/MainDisplay/MainDisplayService.o MainDisplay/MainDisplayService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestGameMain.o: TestHarnesses/TestGameMain.c  .generated_files/flags/default/aa896195532a0d3b74c6c1f695d5531b540acc08 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestGameMain.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestGameMain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestGameMain.o.d" -o ${OBJECTDIR}/TestHarnesses/TestGameMain.o TestHarnesses/TestGameMain.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o: TestHarnesses/TestDistanceSensor.c  .generated_files/flags/default/83fa91e6ae772ab50337c5a575ea84ad00aee1ca .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o.d" -o ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o TestHarnesses/TestDistanceSensor.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestShakeService.o: TestHarnesses/TestShakeService.c  .generated_files/flags/default/accfe92d2885f346acbb7679dfda3cc6efcb72c1 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestShakeService.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestShakeService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestShakeService.o.d" -o ${OBJECTDIR}/TestHarnesses/TestShakeService.o TestHarnesses/TestShakeService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/ServoTest.o: TestHarnesses/ServoTest.c  .generated_files/flags/default/f5d1a075b71dd2072b06589a1bcf8ff51179b7ec .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/ServoTest.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/ServoTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/ServoTest.o.d" -o ${OBJECTDIR}/TestHarnesses/ServoTest.o TestHarnesses/ServoTest.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestP2PService.o: TestHarnesses/TestP2PService.c  .generated_files/flags/default/1b0322d45b0416f88026127ed220d3af9e4b1519 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestP2PService.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestP2PService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestP2PService.o.d" -o ${OBJECTDIR}/TestHarnesses/TestP2PService.o TestHarnesses/TestP2PService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o: FrameworkSource/ES_CheckEvents.c  .generated_files/flags/default/8b188bd79be316b11294b06484bbfdef721eae87 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_CheckEvents.o FrameworkSource/ES_CheckEvents.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o: FrameworkSource/ES_DeferRecall.c  .generated_files/flags/default/afab9c95b03058a858370c47c87cbbbf83cac172 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_DeferRecall.o FrameworkSource/ES_DeferRecall.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Framework.o: FrameworkSource/ES_Framework.c  .generated_files/flags/default/2336dac67175e35f3d5447c2531ef7436e4e74e2 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Framework.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Framework.o FrameworkSource/ES_Framework.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_LookupTables.o: FrameworkSource/ES_LookupTables.c  .generated_files/flags/default/668ab280e754b7e7f64ee6745dad32479bc19d3d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_LookupTables.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_LookupTables.o FrameworkSource/ES_LookupTables.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Port.o: FrameworkSource/ES_Port.c  .generated_files/flags/default/dd120339f7fe250178311b3c8dd1c9f075a5f237 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Port.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Port.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Port.o FrameworkSource/ES_Port.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_PostList.o: FrameworkSource/ES_PostList.c  .generated_files/flags/default/60803bd1de3f4efc305263fb17d547d29740b204 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_PostList.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_PostList.o FrameworkSource/ES_PostList.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Queue.o: FrameworkSource/ES_Queue.c  .generated_files/flags/default/178b32de0d02f29acd710b8c81a1b549e281c8d0 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Queue.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Queue.o FrameworkSource/ES_Queue.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/ES_Timers.o: FrameworkSource/ES_Timers.c  .generated_files/flags/default/51f491c40cd4c4536655e18d3a75f2246d9e815f .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/ES_Timers.o.d" -o ${OBJECTDIR}/FrameworkSource/ES_Timers.o FrameworkSource/ES_Timers.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/terminal.o: FrameworkSource/terminal.c  .generated_files/flags/default/f7d5a12d1cb61e0eb2b0b17386c98908947a089 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/terminal.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/terminal.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/terminal.o.d" -o ${OBJECTDIR}/FrameworkSource/terminal.o FrameworkSource/terminal.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o: FrameworkSource/circular_buffer_no_modulo_threadsafe.c  .generated_files/flags/default/c77a54000c2b2d4a8dacc71543cfb8af8fbb377f .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o.d" -o ${OBJECTDIR}/FrameworkSource/circular_buffer_no_modulo_threadsafe.o FrameworkSource/circular_buffer_no_modulo_threadsafe.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FrameworkSource/dbprintf.o: FrameworkSource/dbprintf.c  .generated_files/flags/default/c9560b2a98cff9aa04c5589e6819638a48dbaef6 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/FrameworkSource" 
	@${RM} ${OBJECTDIR}/FrameworkSource/dbprintf.o.d 
	@${RM} ${OBJECTDIR}/FrameworkSource/dbprintf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/FrameworkSource/dbprintf.o.d" -o ${OBJECTDIR}/FrameworkSource/dbprintf.o FrameworkSource/dbprintf.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/FontStuff.o: HALs/FontStuff.c  .generated_files/flags/default/27b5529a50f174f1fe2da598caebdf1634b4c3a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/FontStuff.o.d 
	@${RM} ${OBJECTDIR}/HALs/FontStuff.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/FontStuff.o.d" -o ${OBJECTDIR}/HALs/FontStuff.o HALs/FontStuff.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32_SPI_HAL.o: HALs/PIC32_SPI_HAL.c  .generated_files/flags/default/fb571392be9406125a847c825830aacc38dc965d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32_SPI_HAL.o.d" -o ${OBJECTDIR}/HALs/PIC32_SPI_HAL.o HALs/PIC32_SPI_HAL.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32PortHAL.o: HALs/PIC32PortHAL.c  .generated_files/flags/default/9e1321142365e65bf9cc5388631fc133a66e5459 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32PortHAL.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32PortHAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32PortHAL.o.d" -o ${OBJECTDIR}/HALs/PIC32PortHAL.o HALs/PIC32PortHAL.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PWM_PIC32.o: HALs/PWM_PIC32.c  .generated_files/flags/default/363307b147816197b075973fb8cf46a679f0ddfc .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PWM_PIC32.o.d 
	@${RM} ${OBJECTDIR}/HALs/PWM_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PWM_PIC32.o.d" -o ${OBJECTDIR}/HALs/PWM_PIC32.o HALs/PWM_PIC32.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/PIC32_AD_Lib.o: HALs/PIC32_AD_Lib.c  .generated_files/flags/default/dd93088b1b161f330b7e8a8f836235b293bbc466 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/PIC32_AD_Lib.o.d 
	@${RM} ${OBJECTDIR}/HALs/PIC32_AD_Lib.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/PIC32_AD_Lib.o.d" -o ${OBJECTDIR}/HALs/PIC32_AD_Lib.o HALs/PIC32_AD_Lib.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/DM_Display_2.o: HALs/DM_Display_2.c  .generated_files/flags/default/58f7b5661ae1f8611aaa54f3d6446761c0da275d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/DM_Display_2.o.d 
	@${RM} ${OBJECTDIR}/HALs/DM_Display_2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/DM_Display_2.o.d" -o ${OBJECTDIR}/HALs/DM_Display_2.o HALs/DM_Display_2.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HALs/DM_Display.o: HALs/DM_Display.c  .generated_files/flags/default/da0fefd47e47abd8cbdaba31eb905cb1e53ad41f .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/HALs" 
	@${RM} ${OBJECTDIR}/HALs/DM_Display.o.d 
	@${RM} ${OBJECTDIR}/HALs/DM_Display.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/HALs/DM_Display.o.d" -o ${OBJECTDIR}/HALs/DM_Display.o HALs/DM_Display.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ProjectSource/EventCheckers.o: ProjectSource/EventCheckers.c  .generated_files/flags/default/a7317225116953307210016413181ae9bc05726f .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/ProjectSource" 
	@${RM} ${OBJECTDIR}/ProjectSource/EventCheckers.o.d 
	@${RM} ${OBJECTDIR}/ProjectSource/EventCheckers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/ProjectSource/EventCheckers.o.d" -o ${OBJECTDIR}/ProjectSource/EventCheckers.o ProjectSource/EventCheckers.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ProjectSource/main.o: ProjectSource/main.c  .generated_files/flags/default/28eace0dea253be13025e7f4009ebc25f9673ab8 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/ProjectSource" 
	@${RM} ${OBJECTDIR}/ProjectSource/main.o.d 
	@${RM} ${OBJECTDIR}/ProjectSource/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/ProjectSource/main.o.d" -o ${OBJECTDIR}/ProjectSource/main.o ProjectSource/main.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/ClockService.o: Services/ClockService.c  .generated_files/flags/default/c40f2a3e3029495bc9f629489e1f803fae35c9d5 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/ClockService.o.d 
	@${RM} ${OBJECTDIR}/Services/ClockService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/ClockService.o.d" -o ${OBJECTDIR}/Services/ClockService.o Services/ClockService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/DoorService.o: Services/DoorService.c  .generated_files/flags/default/8c181b76ef3952f8dde57519eddeb6b412f6a54 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/DoorService.o.d 
	@${RM} ${OBJECTDIR}/Services/DoorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/DoorService.o.d" -o ${OBJECTDIR}/Services/DoorService.o Services/DoorService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/GameMain.o: Services/GameMain.c  .generated_files/flags/default/fc37858149a344c818618d739ec50264381121e2 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/GameMain.o.d 
	@${RM} ${OBJECTDIR}/Services/GameMain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/GameMain.o.d" -o ${OBJECTDIR}/Services/GameMain.o Services/GameMain.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/HapticService.o: Services/HapticService.c  .generated_files/flags/default/f61b9644366cc99128329572ed788da5ea31172c .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/HapticService.o.d 
	@${RM} ${OBJECTDIR}/Services/HapticService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/HapticService.o.d" -o ${OBJECTDIR}/Services/HapticService.o Services/HapticService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/ShakeService.o: Services/ShakeService.c  .generated_files/flags/default/3c71768f9f75cf66f3edb91df03b9aee27d0bdb .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/ShakeService.o.d 
	@${RM} ${OBJECTDIR}/Services/ShakeService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/ShakeService.o.d" -o ${OBJECTDIR}/Services/ShakeService.o Services/ShakeService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/StartButtonService.o: Services/StartButtonService.c  .generated_files/flags/default/c48b531b4a6a3248adbf11d5be1fef7475538142 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/StartButtonService.o.d 
	@${RM} ${OBJECTDIR}/Services/StartButtonService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/StartButtonService.o.d" -o ${OBJECTDIR}/Services/StartButtonService.o Services/StartButtonService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PourService/AnalogChecker.o: PourService/AnalogChecker.c  .generated_files/flags/default/1f129dfd2f54927763faaae931634ecffcf759be .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/PourService" 
	@${RM} ${OBJECTDIR}/PourService/AnalogChecker.o.d 
	@${RM} ${OBJECTDIR}/PourService/AnalogChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/PourService/AnalogChecker.o.d" -o ${OBJECTDIR}/PourService/AnalogChecker.o PourService/AnalogChecker.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PourService/PourService.o: PourService/PourService.c  .generated_files/flags/default/8b0a0d62b8fd9c6357b88c2ebc213b16ffe8666c .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/PourService" 
	@${RM} ${OBJECTDIR}/PourService/PourService.o.d 
	@${RM} ${OBJECTDIR}/PourService/PourService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/PourService/PourService.o.d" -o ${OBJECTDIR}/PourService/PourService.o PourService/PourService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/AddIngredientsHelperService.o: Services/AddIngredientsHelperService.c  .generated_files/flags/default/34474fba46b94d524b1d7ff3b34f4ee5d9b530d8 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/AddIngredientsHelperService.o.d 
	@${RM} ${OBJECTDIR}/Services/AddIngredientsHelperService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/AddIngredientsHelperService.o.d" -o ${OBJECTDIR}/Services/AddIngredientsHelperService.o Services/AddIngredientsHelperService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Services/P2PComm.o: Services/P2PComm.c  .generated_files/flags/default/45598b02e8f9da16b2a3594ac837b9de5486fb8d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/Services" 
	@${RM} ${OBJECTDIR}/Services/P2PComm.o.d 
	@${RM} ${OBJECTDIR}/Services/P2PComm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/Services/P2PComm.o.d" -o ${OBJECTDIR}/Services/P2PComm.o Services/P2PComm.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainDisplay/DisplayFSM.o: MainDisplay/DisplayFSM.c  .generated_files/flags/default/e6bff1aa745f4c7c52fb639dd30b4d8b939fbed2 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/MainDisplay" 
	@${RM} ${OBJECTDIR}/MainDisplay/DisplayFSM.o.d 
	@${RM} ${OBJECTDIR}/MainDisplay/DisplayFSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/MainDisplay/DisplayFSM.o.d" -o ${OBJECTDIR}/MainDisplay/DisplayFSM.o MainDisplay/DisplayFSM.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainDisplay/MainDisplayService.o: MainDisplay/MainDisplayService.c  .generated_files/flags/default/d73b3b3a32da682a3df804e62fd40bb486bceb65 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/MainDisplay" 
	@${RM} ${OBJECTDIR}/MainDisplay/MainDisplayService.o.d 
	@${RM} ${OBJECTDIR}/MainDisplay/MainDisplayService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/MainDisplay/MainDisplayService.o.d" -o ${OBJECTDIR}/MainDisplay/MainDisplayService.o MainDisplay/MainDisplayService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestGameMain.o: TestHarnesses/TestGameMain.c  .generated_files/flags/default/2ea6cfcfab52bb7ebd055f6280bc6a3ac313ae6d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestGameMain.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestGameMain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestGameMain.o.d" -o ${OBJECTDIR}/TestHarnesses/TestGameMain.o TestHarnesses/TestGameMain.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o: TestHarnesses/TestDistanceSensor.c  .generated_files/flags/default/423a83040b24a25ecc9cdf6ca8329aca8f68e37a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o.d" -o ${OBJECTDIR}/TestHarnesses/TestDistanceSensor.o TestHarnesses/TestDistanceSensor.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestShakeService.o: TestHarnesses/TestShakeService.c  .generated_files/flags/default/679ca0d9be9d3cc7d1b09a9730a61868b904722d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestShakeService.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestShakeService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestShakeService.o.d" -o ${OBJECTDIR}/TestHarnesses/TestShakeService.o TestHarnesses/TestShakeService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/ServoTest.o: TestHarnesses/ServoTest.c  .generated_files/flags/default/c84918fff574f733b4a8ae770e58b127b56c290 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/ServoTest.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/ServoTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/ServoTest.o.d" -o ${OBJECTDIR}/TestHarnesses/ServoTest.o TestHarnesses/ServoTest.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TestHarnesses/TestP2PService.o: TestHarnesses/TestP2PService.c  .generated_files/flags/default/adb05e55fe02223f94cb69ba82227381cbae39c3 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/TestHarnesses" 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestP2PService.o.d 
	@${RM} ${OBJECTDIR}/TestHarnesses/TestP2PService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"FrameworkHeaders" -I"ProjectHeaders" -fno-common -MP -MMD -MF "${OBJECTDIR}/TestHarnesses/TestP2PService.o.d" -o ${OBJECTDIR}/TestHarnesses/TestP2PService.o TestHarnesses/TestP2PService.c   -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -relaxed-math -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default
