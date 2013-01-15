MATLAB="/usr/local/MATLAB/R2011b"
Arch=glnx86
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/iventio/.matlab/R2011b"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for heart_rate_official_cport" > heart_rate_official_cport_mex.mki
echo "CC=$CC" >> heart_rate_official_cport_mex.mki
echo "CFLAGS=$CFLAGS" >> heart_rate_official_cport_mex.mki
echo "CLIBS=$CLIBS" >> heart_rate_official_cport_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> heart_rate_official_cport_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> heart_rate_official_cport_mex.mki
echo "CXX=$CXX" >> heart_rate_official_cport_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> heart_rate_official_cport_mex.mki
echo "CXXLIBS=$CXXLIBS" >> heart_rate_official_cport_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> heart_rate_official_cport_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> heart_rate_official_cport_mex.mki
echo "LD=$LD" >> heart_rate_official_cport_mex.mki
echo "LDFLAGS=$LDFLAGS" >> heart_rate_official_cport_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> heart_rate_official_cport_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> heart_rate_official_cport_mex.mki
echo "Arch=$Arch" >> heart_rate_official_cport_mex.mki
echo OMPFLAGS= >> heart_rate_official_cport_mex.mki
echo OMPLINKFLAGS= >> heart_rate_official_cport_mex.mki
echo "EMC_COMPILER=unix" >> heart_rate_official_cport_mex.mki
echo "EMC_CONFIG=optim" >> heart_rate_official_cport_mex.mki
"/usr/local/MATLAB/R2011b/bin/glnx86/gmake" -B -f heart_rate_official_cport_mex.mk
