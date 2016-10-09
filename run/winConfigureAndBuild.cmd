
@ECHO OFF

SET RUN_DIR="%CD%"

IF EXIST _build GOTO NOWINDIR
mkdir _build
:NOWINDIR

cd _build
cmake -DNEW_PROJECT="" -DCMAKE_INSTALL_PREFIX=%RUN_DIR% ..\..
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" /m LBSetup.sln
cd ..
