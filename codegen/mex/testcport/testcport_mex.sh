MATLAB="/usr/local/MATLAB/R2011b"
Arch=glnx86
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/iventio/.matlab/R2011b"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for testcport" > testcport_mex.mki
echo "CC=$CC" >> testcport_mex.mki
echo "CFLAGS=$CFLAGS" >> testcport_mex.mki
echo "CLIBS=$CLIBS" >> testcport_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> testcport_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> testcport_mex.mki
echo "CXX=$CXX" >> testcport_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> testcport_mex.mki
echo "CXXLIBS=$CXXLIBS" >> testcport_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> testcport_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> testcport_mex.mki
echo "LD=$LD" >> testcport_mex.mki
echo "LDFLAGS=$LDFLAGS" >> testcport_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> testcport_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> testcport_mex.mki
echo "Arch=$Arch" >> testcport_mex.mki
echo OMPFLAGS= >> testcport_mex.mki
echo OMPLINKFLAGS= >> testcport_mex.mki
echo "EMC_COMPILER=unix" >> testcport_mex.mki
echo "EMC_CONFIG=optim" >> testcport_mex.mki
"/usr/local/MATLAB/R2011b/bin/glnx86/gmake" -B -f testcport_mex.mk
