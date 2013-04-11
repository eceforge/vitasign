################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F2806x_Adc.obj: ../F2806x_Adc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_Adc.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_CSMPasswords.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_CSMPasswords.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_CSMPasswords.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_CodeStartBranch.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_CodeStartBranch.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_CodeStartBranch.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_DefaultIsr.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_DefaultIsr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_DefaultIsr.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_EPwm.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_EPwm.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_EPwm.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_GlobalVariableDefs.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_headers/source/F2806x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_GlobalVariableDefs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_I2C.obj: ../F2806x_I2C.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_I2C.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_PieCtrl.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_PieCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_PieCtrl.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_PieVect.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_PieVect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_PieVect.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_SysCtrl.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_SysCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_SysCtrl.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_usDelay.obj: /home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2806x/v135/F2806x_common/source/F2806x_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="F2806x_usDelay.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

adr_main.obj: ../adr_main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/opt/ti/xdais_7_21_01_07/packages/ti/xdais" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_headers/include" --include_path="/home/adrian/controlSUITE/device_support/f2806x/v135/F2806x_common/include" --include_path="/home/adrian/controlSUITE/libs/math/IQmath/v15c/include" --include_path="/home/adrian/controlSUITE/libs/math/FPUfastRTS/V100/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="adr_main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


