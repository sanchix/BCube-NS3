#!/bin/bash

#Init variables
. myLocalPaths

FULL_SCRATCH_PATH="$NS3_PATH/scratch/$SCRATCH_SUBDIR_NAME"

# Create and prepare ns3 folders
if [[ ! -d $FULL_SCRATCH_PATH ]]
then
	echo Creating folder $FULL_SCRATCH_PATH
	mkdir $FULL_SCRATCH_PATH
fi

rm -rf $FULL_SCRATCH_PATH/*


# Copy code
for CODE_PATH in $CODE_PATHS
do
	echo Copying code from $CODE_PATH
	cp $CODE_PATH/*.h $FULL_SCRATCH_PATH
	cp $CODE_PATH/*.cc $FULL_SCRATCH_PATH
done


# Execute
OLD_WD=$PWD
cd $NS3_PATH

if [[ $1 == "-c" ]]
then
	echo CONARG
	./captura.sh "NS_LOG='$NS_LOG' ./waf --run '$SCRATCH_SUBDIR_NAME $2'" &> $OLD_WD/captura.txt
else
	echo SINARG
	./waf --run "$SCRATCH_SUBDIR_NAME $1"
fi

mv Trabajo.plt $OLD_WD