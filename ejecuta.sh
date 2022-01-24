#!/bin/bash

printf "¡AVISO, este script MODIFICA ficheros del CODIGO FUENTE DE NS3!\nAsegúrese de haber configurado las variables del fichero de texto \"myLocalPaths\":\n\t> NS3_PATH: Ruta hasta la carpeta de NS3 que contiene el fichero waf, los directorios src, scratch, ...\n\t> SCRATCH_SUBDIR_NAME: Nombre del subdirectorio donde se almacenará el código dentro de la carpeta scratch de NS3 (vale con utilizar cualquier nombre que no tenga asociado un subdirectorio en dicha carpeta)\n¿Quiere continuar? [Y/N]: "
read
if [[ $REPLY != "Y" ]]
then
	ex it 1
fi


#Init variables
. myLocalPaths
CODE_PATHS="./lib/myPsrLib ./simulateSrc"

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


# Copy NS3 code
cp ./ns3/ipv4-nix-vector-routing.* $NS3_PATH/src/nix-vector-routing/model/
cp ./ns3/onoff-application.cc $NS3_PATH/src/applications/model/


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

mv *.plt $OLD_WD