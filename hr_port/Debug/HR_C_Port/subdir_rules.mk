################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
HR_C_Port/abs.obj: ../HR_C_Port/abs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/abs.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/conv.obj: ../HR_C_Port/conv.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/conv.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/heart_rate_official_cport.obj: ../HR_C_Port/heart_rate_official_cport.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/heart_rate_official_cport.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/heart_rate_official_cport_initialize.obj: ../HR_C_Port/heart_rate_official_cport_initialize.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/heart_rate_official_cport_initialize.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/heart_rate_official_cport_rtwutil.obj: ../HR_C_Port/heart_rate_official_cport_rtwutil.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/heart_rate_official_cport_rtwutil.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/heart_rate_official_cport_terminate.obj: ../HR_C_Port/heart_rate_official_cport_terminate.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/heart_rate_official_cport_terminate.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/max.obj: ../HR_C_Port/max.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/max.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/mean.obj: ../HR_C_Port/mean.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/mean.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/minus.obj: ../HR_C_Port/minus.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/minus.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/plus.obj: ../HR_C_Port/plus.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/plus.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/rtGetInf.obj: ../HR_C_Port/rtGetInf.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/rtGetInf.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/rtGetNaN.obj: ../HR_C_Port/rtGetNaN.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/rtGetNaN.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/rt_nonfinite.obj: ../HR_C_Port/rt_nonfinite.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/rt_nonfinite.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HR_C_Port/sqrt.obj: ../HR_C_Port/sqrt.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="/opt/ti/ccsv5/tools/compiler/c2000_6.1.0/include" --include_path="/packages/ti/xdais" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="/home/adrian/.wine/drive_c/ti/controlSUITE/libs/math/IQmath/v15c/include" --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --issue_remarks --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="HR_C_Port/sqrt.pp" --obj_directory="HR_C_Port" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


