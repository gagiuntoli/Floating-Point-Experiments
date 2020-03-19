CPP=g++
CC=gcc

BitRepresentationC: BitRepresentation.c
	$(CC) $< -o $@

BitRepresentation: BitRepresentation.cpp
	$(CPP) $< -o $@

DataModels: DataModels.cpp
	$(CPP) $< -o $@
