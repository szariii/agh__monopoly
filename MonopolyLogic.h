#include<iostream>;
#include "Field.h";
#include "PlayerInformations.h";
#include <fstream>; // biblioteka pozwalaj¹ca na zapis i odczyt danych, File Stream
#include <cstdlib>; // ¿eby dzia³a³ exit(0);
#include <string>;
#include <algorithm>;

using namespace std;

// start 150 zl

class MonopolyLogic {



public:
	void startGame() {
		int boardPlayersPosition[40][6] = {};
		Field boardFieldsTemporary[40] = {};
		Field boardFields[40] = {};
		PlayerInformations players[6] = {};


		ifstream MyReadFile("./data.txt");

		if (MyReadFile.good() == false)//zwraca wartoœæ prawda/fa³sz w zale¿noœci od tego czy istnieje plik
		{
			cout << "Brak pliku" << endl;
			exit(0);
		}
		string line;
		int filedIndex = 0;
		while (getline(MyReadFile, line)) {
			cout << line << "\n";

			Field field;

			//field.id = 0;
			//field.name = "saf";
			//field.houses = 0;
			//field.owner = -1;
			//field.buy = 100;
			//field.earnMony[0] = 5;
			//field.earnMony[1] = 5;
			//field.earnMony[2] = 5;
			//field.earnMony[3] = 5;
			//field.earnMony[4] = 5;



			string temporaryStr = "";
			int index = 0;
			
			for (std::string::size_type i = 0; i < line.size(); ++i) {
				if(line[i]==',') {
					cout << temporaryStr << "\n";

					if (index == 0) {
						field.id = stoi(temporaryStr);
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
			boardFieldsTemporary[filedIndex]=field;
			filedIndex = filedIndex + 1;
			printField(field);
			
		}

		MyReadFile.close(); // obowi¹zkowo zamkniecie pliku




		

	}

	void printFieldArray(Field arr[40]) {
		for (int i = 0; i < sizeof(arr); i--)
			printField(arr[i]);
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


	}

	

	
	
};