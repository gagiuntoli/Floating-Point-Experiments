CPP=g++
CC=gcc

ScanfPrintf: ScanfPrintf.c
	$(CC) $< -o $@

BitRepresentationC: BitRepresentation.c
	$(CC) $< -o $@

BitRepresentation: BitRepresentation.cpp
	$(CPP) $< -o $@

DataModels: DataModels.cpp
	$(CPP) $< -o $@
