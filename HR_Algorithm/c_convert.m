cfg = coder.config('lib');
hw_cfg = coder.HardwareImplementation;
hw_cfg.TargetHWDeviceType='Texas Instruments->C2000';
hw_cfg.ProdHWDeviceType='Texas Instruments->C2000';
hw_cfg.TargetHWDeviceType='Texas Instruments->C2000';
cfg.HardwareImplementation = hw_cfg;
cfg.CCompilerOptimization = 'on';
cfg.InlineStackLimit = 1000;
cfg.StackUsageMax = 1000;