################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /opt/ti/ccsv5/tools/compiler/c2000_6.1.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
-l"rts2800_fpu32_fast_supplement.lib" \
-l"rts2800_fpu32.lib" \
"./HR_C_Port/sqrt.obj" \
"./HR_C_Port/rt_nonfinite.obj" \
"./HR_C_Port/rtGetNaN.obj" \
"./HR_C_Port/rtGetInf.obj" \
"./HR_C_Port/plus.obj" \
"./HR_C_Port/minus.obj" \
"./HR_C_Port/mean.obj" \
"./HR_C_Port/max.obj" \
"./HR_C_Port/heart_rate_official_cport_terminate.obj" \
"./HR_C_Port/heart_rate_official_cport_rtwutil.obj" \
"./HR_C_Port/heart_rate_official_cport_initialize.obj" \
"./HR_C_Port/heart_rate_official_cport.obj" \
"./HR_C_Port/conv.obj" \
"./HR_C_Port/abs.obj" \
"./adr_main.obj" \
"./F2806x_usDelay.obj" \
"./F2806x_SysCtrl.obj" \
"./F2806x_PieVect.obj" \
"./F2806x_PieCtrl.obj" \
"./F2806x_I2C.obj" \
"./F2806x_GlobalVariableDefs.obj" \
"./F2806x_EPwm.obj" \
"./F2806x_DefaultIsr.obj" \
"./F2806x_CodeStartBranch.obj" \
"./F2806x_CSMPasswords.obj" \
"./F2806x_Adc.obj" \
-l"IQmath_fpu32.lib" \
"/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/cmd/F28069.cmd" \
"/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_headers/cmd/F2806x_Headers_nonBIOS.cmd" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include HR_C_Port/subdir_vars.mk
-include subdir_rules.mk
-include HR_C_Port/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Example_2806xFlash.out

# Tool invocations
Example_2806xFlash.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data -z --stack_size=0x200 -m"Example_2806xFlash.map" --warn_sections -i"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/lib" -i"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" -i"/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/lib" -i"/home/adrian/controlSUITE/libs/math/IQmath/v15c/lib" -i"/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/lib" --reread_libs --priority --verbose_diagnostics --issue_remarks --entry_point=code_start --rom_model -o "Example_2806xFlash.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "Example_2806xFlash.out"
	-$(RM) "F2806x_Adc.pp" "F2806x_DefaultIsr.pp" "F2806x_EPwm.pp" "F2806x_GlobalVariableDefs.pp" "F2806x_I2C.pp" "F2806x_PieCtrl.pp" "F2806x_PieVect.pp" "F2806x_SysCtrl.pp" "adr_main.pp" "HR_C_Port/abs.pp" "HR_C_Port/conv.pp" "HR_C_Port/heart_rate_official_cport.pp" "HR_C_Port/heart_rate_official_cport_initialize.pp" "HR_C_Port/heart_rate_official_cport_rtwutil.pp" "HR_C_Port/heart_rate_official_cport_terminate.pp" "HR_C_Port/max.pp" "HR_C_Port/mean.pp" "HR_C_Port/minus.pp" "HR_C_Port/plus.pp" "HR_C_Port/rtGetInf.pp" "HR_C_Port/rtGetNaN.pp" "HR_C_Port/rt_nonfinite.pp" "HR_C_Port/sqrt.pp" 
	-$(RM) "F2806x_Adc.obj" "F2806x_CSMPasswords.obj" "F2806x_CodeStartBranch.obj" "F2806x_DefaultIsr.obj" "F2806x_EPwm.obj" "F2806x_GlobalVariableDefs.obj" "F2806x_I2C.obj" "F2806x_PieCtrl.obj" "F2806x_PieVect.obj" "F2806x_SysCtrl.obj" "F2806x_usDelay.obj" "adr_main.obj" "HR_C_Port/abs.obj" "HR_C_Port/conv.obj" "HR_C_Port/heart_rate_official_cport.obj" "HR_C_Port/heart_rate_official_cport_initialize.obj" "HR_C_Port/heart_rate_official_cport_rtwutil.obj" "HR_C_Port/heart_rate_official_cport_terminate.obj" "HR_C_Port/max.obj" "HR_C_Port/mean.obj" "HR_C_Port/minus.obj" "HR_C_Port/plus.obj" "HR_C_Port/rtGetInf.obj" "HR_C_Port/rtGetNaN.obj" "HR_C_Port/rt_nonfinite.obj" "HR_C_Port/sqrt.obj" 
	-$(RM) "F2806x_CSMPasswords.pp" "F2806x_CodeStartBranch.pp" "F2806x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
