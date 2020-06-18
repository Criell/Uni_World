#include "Individual.h"

Individual::Individual(){}

Individual::Individual(std::string binary){
	binaryString = binary;
}

Individual::Individual(int length){
	for (int i = 0; i < length; i++){
		binaryString = binaryString + '0';
	}
}

int Individual::getBit(int pos){

	if ((pos < 0)||(pos > binaryString.length())){
		return -1;
	}
	else if (binaryString[pos] == '0'){
		return 0;
	}
	else if (binaryString[pos] == '1'){
		return 1;
	}
}

std::string Individual::getString(){
		return binaryString;
}

void Individual::setString(std::string newbinary){
	binaryString = newbinary;
}

void Individual::flipBit(int pos){
	if (binaryString[pos]=='0'){
		binaryString[pos]='1';
	}
	else {
		binaryString[pos]='0';
	}
}

int Individual::getMaxOnes(){
	int count = 0, temp = 0;
	for (int i = 0; i < binaryString.length(); i++){
		if (binaryString[i]=='1'){
			temp = temp + 1;
		}
		else{
			count = temp;
			temp = 0;
		}
	}

	if (temp != 0) {count = temp;}

	return count;
}

int Individual::getLength(){
	return binaryString.length();
}

Individual::~Individual(){}
