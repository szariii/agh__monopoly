#include<iostream>;
#include "Field.h";
#include "PlayerInformations.h";
#include <fstream>; // biblioteka pozwalaj¹ca na zapis i odczyt danych, File Stream
#include <cstdlib>; // ¿eby dzia³a³ exit(0);
#include <string>;
#include <algorithm>;

using namespace std;
#define MAX_SIZE 163824512352345;

// start 150 zl

class MonopolyLogic {


public:
	void startGame() {
		Field boardFieldsTemporary[40] = {};
		Field boardFields[40] = {};


		ifstream MyReadFile("./data.txt");

		if (MyReadFile.good() == false)//zwraca wartoœæ prawda/fa³sz w zale¿noœci od tego czy istnieje plik
		{
			cout << "Brak pliku" << endl;
			exit(0);
		}
		string line;
		int filedIndex = 0;
		while (getline(MyReadFile, line)) {
			
			Field field;


			string temporaryStr = "";
			int index = 0;
			
			for (std::string::size_type i = 0; i < line.size(); ++i) {
				if(line[i]==',') {

					if (index == 0) {
						//field.id = stoi(temporaryStr);
					}
					if (index == 1) {
						replace(temporaryStr.begin(), temporaryStr.end(), '_', ' ');
						field.name = temporaryStr;
					}
					if(index==2){
						field.buy = stof(temporaryStr);
					}
					if(index==3){
						int indexTemporary = 0;
						string temporaryvalue = "";
						for(std::string::size_type j = 0; j < temporaryStr.size(); ++j){
							if (temporaryStr[j] == ':') {
								field.earnForBuildingsMony[indexTemporary] = stof(temporaryvalue);
								indexTemporary = indexTemporary + 1;
								temporaryvalue = "";
							}
							else {
								temporaryvalue = temporaryvalue +temporaryStr[j];
							}
						}
					}
					if (index == 4) {
						field.type = stoi(temporaryStr);
					}
					if (index == 5) {
						field.housePrice = stof(temporaryStr);
					}
					if (index == 6) {
						replace(temporaryStr.begin(), temporaryStr.end(), '_', ' ');
						field.description = temporaryStr;
					}




					index = index+1;
					temporaryStr = "";
				}
				else {
					temporaryStr = temporaryStr + line[i];
				}
			}

			field.buildedHouses = 0;
			field.owner = -1;
			field.special = false;
			boardFieldsTemporary[filedIndex]=field;
			filedIndex = filedIndex + 1;
			
		}

		MyReadFile.close(); // obowi¹zkowo zamkniecie pliku
		

		int index = 0;
		int commonFieldIndex = 0;

		Field start;
		start.id = index;
		start.name = "Start - Biblioteka AGH";
		start.special = true;
		start.specialType = 0;
		boardFields[index] = start;
		index = index + 1;

		Field commonField1 = boardFieldsTemporary[commonFieldIndex];
		commonField1.id = index;
		boardFields[index] = commonField1;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field chest1;
		chest1.id = index;
		chest1.special = true;
		chest1.specialType = 1;
		chest1.name = "Studenta ciê¿ki ¿ywot";
		boardFields[index] = chest1;
		index = index + 1;


		Field commonField2 = boardFieldsTemporary[commonFieldIndex];
		commonField2.id = index;
		boardFields[index] = commonField2;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field incomeTax;
		incomeTax.id = index;
		incomeTax.name = "Op³ata za warunek";
		incomeTax.special = true;
		incomeTax.specialType = 2;
		boardFields[index] = incomeTax;
		index = index + 1;


		Field railroad1;
		railroad1.id = index;
		railroad1.name = "Railiwaa";
		railroad1.special = true;
		railroad1.specialType = 3;
		boardFields[index] = railroad1;
		index = index + 1;

		Field commonField3 = boardFieldsTemporary[commonFieldIndex];
		commonField3.id = index;
		boardFields[index] = commonField3;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field chance1;
		chance1.id = index;
		chance1.special = true;
		chance1.specialType = 4;
		chance1.name = "Szansa";
		boardFields[index] = chance1;
		index = index + 1;

		Field commonField4 = boardFieldsTemporary[commonFieldIndex];
		commonField4.id = index;
		boardFields[index] = commonField4;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field commonField5 = boardFieldsTemporary[commonFieldIndex];
		commonField5.id = index;
		boardFields[index] = commonField5;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field jail;
		jail.id = index;
		jail.special = true;
		jail.specialType = 5;
		jail.name = "Sala Pana Pszczo³y";
		boardFields[index] = jail;
		index = index + 1;

		Field commonField6 = boardFieldsTemporary[commonFieldIndex];
		commonField6.id = index;
		boardFields[index] = commonField6;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field dobuleField1;
		dobuleField1.id = index;
		dobuleField1.special = true;
		dobuleField1.specialType = 6;
		dobuleField1.name = "dobleField1";
		boardFields[index] = dobuleField1;
		index = index + 1;

		Field commonField7 = boardFieldsTemporary[commonFieldIndex];
		commonField7.id = index;
		boardFields[index] = commonField7;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field commonField8 = boardFieldsTemporary[commonFieldIndex];
		commonField8.id = index;
		boardFields[index] = commonField8;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field railroad2;
		railroad2.id = index;
		railroad2.name = "Railiwaa";
		railroad2.special = true;
		railroad2.specialType = 3;
		boardFields[index] = railroad2;
		index = index + 1;

		Field commonField9 = boardFieldsTemporary[commonFieldIndex];
		commonField9.id = index;
		boardFields[index] = commonField9;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field chest2;
		chest2.id = index;
		chest2.special = true;
		chest2.specialType = 1;
		chest2.name = "Studenta ciê¿ki ¿ywot";
		boardFields[index] = chest2;
		index = index + 1;

		Field commonField10 = boardFieldsTemporary[commonFieldIndex];
		commonField10.id = index;
		boardFields[index] = commonField10;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field commonField11 = boardFieldsTemporary[commonFieldIndex];
		commonField11.id = index;
		boardFields[index] = commonField11;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field parking;
		parking.id = index;
		parking.special = true;
		parking.specialType = 5;
		parking.name = "Parking";
		boardFields[index] = parking;
		index = index + 1;

		Field commonField12 = boardFieldsTemporary[commonFieldIndex];
		commonField12.id = index;
		boardFields[index] = commonField12;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field chance2;
		chance2.id = index;
		chance2.special = true;
		chance2.specialType = 4;
		chance2.name = "Szansa";
		boardFields[index] = chance2;
		index = index + 1;

		Field commonField13 = boardFieldsTemporary[commonFieldIndex];
		commonField13.id = index;
		boardFields[index] = commonField13;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field commonField14 = boardFieldsTemporary[commonFieldIndex];
		commonField14.id = index;
		boardFields[index] = commonField14;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field railroad3;
		railroad3.id = index;
		railroad3.name = "Railiwaa";
		railroad3.special = true;
		railroad3.specialType = 3;
		boardFields[index] = railroad3;
		index = index + 1;

		Field commonField15 = boardFieldsTemporary[commonFieldIndex];
		commonField15.id = index;
		boardFields[index] = commonField15;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;


		Field commonField16 = boardFieldsTemporary[commonFieldIndex];
		commonField16.id = index;
		boardFields[index] = commonField16;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field dobuleField2;
		dobuleField2.id = index;
		dobuleField2.special = true;
		dobuleField2.specialType = 6;
		dobuleField2.name = "dobleField1";
		boardFields[index] = dobuleField2;
		index = index + 1;

		Field commonField17 = boardFieldsTemporary[commonFieldIndex];
		commonField17.id = index;
		boardFields[index] = commonField17;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field goToJail;
		goToJail.id = index;
		goToJail.special = true;
		goToJail.specialType = 7;
		goToJail.name = "IdŸ do wiêzienia";
		boardFields[index] = goToJail;
		index = index + 1;

		Field commonField18 = boardFieldsTemporary[commonFieldIndex];
		commonField18.id = index;
		boardFields[index] = commonField18;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field commonField19 = boardFieldsTemporary[commonFieldIndex];
		commonField19.id = index;
		boardFields[index] = commonField19;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field chest3;
		chest3.id = index;
		chest3.special = true;
		chest3.specialType = 1;
		chest3.name = "Studenta ciê¿ki ¿ywot";
		boardFields[index] = chest3;
		index = index + 1;

		Field commonField20 = boardFieldsTemporary[commonFieldIndex];
		commonField20.id = index;
		boardFields[index] = commonField20;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field railroad4;
		railroad4.id = index;
		railroad4.name = "Railiwaa";
		railroad4.special = true;
		railroad4.specialType = 3;
		boardFields[index] = railroad4;
		index = index + 1;

		Field chance4;
		chance4.id = index;
		chance4.special = true;
		chance4.specialType = 4;
		chance4.name = "Szansa";
		boardFields[index] = chance4;
		index = index + 1;


		Field commonField21 = boardFieldsTemporary[commonFieldIndex];
		commonField21.id = index;
		boardFields[index] = commonField21;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		Field incomeTax2;
		incomeTax2.id = index;
		incomeTax2.name = "Op³ata za warunek";
		incomeTax2.special = true;
		incomeTax2.specialType = 8;
		boardFields[index] = incomeTax2;
		index = index + 1;

		Field commonField22 = boardFieldsTemporary[commonFieldIndex];
		commonField22.id = index;
		boardFields[index] = commonField22;
		index = index + 1;
		commonFieldIndex = commonFieldIndex + 1;

		addPlayers(boardFields);

	}

	
	void addPlayers(Field* boardFields){
		int boardPlayersPosition[40][6] = {};
		PlayerInformations players[6] = {};

		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 6; j++) {
				boardPlayersPosition[i][j] = -1;
			}
		}


		for(int i=0;i<6;i++){
			PlayerInformations player;
			player.id = i;
			player.money = 150;
			player.position = 0;
			players[i] = player;
			boardPlayersPosition[0][i] = i;
			cout << i << endl;
		}

		cout << boardPlayersPosition[0][2];

		printPlayersPlaces(boardPlayersPosition);

	}



	void printPlayersPlaces(int boardPlayersPosition[][6]) {
		cout << endl;
		for (int i = 0; i < 40; i++) {
			cout << i << ": ";
			for (int j = 0; j < 6; j++) {
				cout << boardPlayersPosition[i][j];
			}
			cout << endl;
		}

	}

	void printFieldArray(Field* arr, int size ) {
		cout << "size: " << size << endl;
		for (int i = 0; i < size; i++) {
			printField(arr[i]);
		}

	}

	void printField(Field field ){
		cout << "id: " <<field.id;
		cout << " name: " << field.name;
		cout << " owner: " << field.owner;
		cout << " buildedHouses: " << field.buildedHouses;
		cout << " house[0]: " << field.earnForBuildingsMony[0];
		cout << " house[1]: " << field.earnForBuildingsMony[1];
		cout << " house[2]: " << field.earnForBuildingsMony[2];
		cout << " house[3]: " << field.earnForBuildingsMony[3];
		cout << " house[4]: " << field.earnForBuildingsMony[4];
		cout << " house[4]: " << field.earnForBuildingsMony[4];
		cout << " buy: " << field.buy;
		cout << " type: " << field.type;
		cout << " housePrice: " << field.housePrice;
		cout << " description: " << field.description;
		cout << " special: " << field.special;
		cout << " specialType: " << field.specialType <<endl;


	}

	

	
	
};