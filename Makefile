CPP=g++

DataModels: DataModels.cpp
	$(CPP) $< -o $@
