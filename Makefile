CPP=g++
CC=gcc

Loop-1:Loop-1.cpp myfloat.hpp
	$(CPP) $< -o $@

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
