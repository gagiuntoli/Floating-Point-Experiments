CPP=g++
CC=gcc

LittleOrBigEndian: LittleOrBigEndian.cpp
	$(CPP) $< -o $@

ScanfPrintf: ScanfPrintf.c
	$(CC) $< -o $@

BitRepresentationC: BitRepresentation.c
	$(CC) $< -o $@

BitRepresentation: BitRepresentation.cpp
	$(CPP) $< -o $@

DataModels: DataModels.cpp
	$(CPP) $< -o $@
