#include<iostream>;
#include "Field.h";
#include "PlayerInformations.h";
#include <fstream>; // biblioteka pozwalaj¹ca na zapis i odczyt danych, File Stream
#include <cstdlib>; // ¿eby dzia³a³ exit(0);
#include <string>;
#include <algorithm>;
#include <random>
#include <cstdlib>;
#include <ctime>;
#include "Game.h";

using namespace std;
#define MAX_SIZE 163824512352345;

// start 150 zl

class MonopolyLogic {


public:
	GameGraphic game;
	void createBoard() {

		//Inicjalizacja gry.
		

		//Pêtla gry
		while (game.running())
		{
			game.update();
			game.render();


			srand((unsigned)time(NULL));
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
					if (line[i] == ',') {

						if (index == 0) {
							//field.id = stoi(temporaryStr);
						}
						if (index == 1) {
							replace(temporaryStr.begin(), temporaryStr.end(), '_', ' ');
							field.name = temporaryStr;
						}
						if (index == 2) {
							field.buy = stof(temporaryStr);
						}
						if (index == 3) {
							int indexTemporary = 0;
							string temporaryvalue = "";
							for (std::string::size_type j = 0; j < temporaryStr.size(); ++j) {
								if (temporaryStr[j] == ':') {
									field.earnForBuildingsMoney[indexTemporary] = stof(temporaryvalue);
									indexTemporary = indexTemporary + 1;
									temporaryvalue = "";
								}
								else {
									temporaryvalue = temporaryvalue + temporaryStr[j];
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



						index = index + 1;
						temporaryStr = "";
					}
					else {
						temporaryStr = temporaryStr + line[i];
					}
				}

				field.buildedHouses = 0;
				field.owner = -1;
				field.special = false;
				boardFieldsTemporary[filedIndex] = field;
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
			railroad1.owner = -1;
			railroad1.buy = 20;
			railroad1.earnForBuildingsMoney[1] = 2.5;
			railroad1.earnForBuildingsMoney[2] = 5;
			railroad1.earnForBuildingsMoney[3] = 10;
			railroad1.earnForBuildingsMoney[4] = 20;
			railroad1.id = index;
			railroad1.name = "lotniosk Kraków Balice";
			railroad1.buildedHouses = 0;
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
			dobuleField1.specialType = 4;
			dobuleField1.name = "szansa";
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
			railroad2.owner = -1;
			railroad2.buy = 20;
			railroad2.id = index;
			railroad2.name = "dworzec g³ówny Kraków";
			railroad2.special = true;
			railroad2.earnForBuildingsMoney[1] = 2.5;
			railroad2.earnForBuildingsMoney[2] = 5;
			railroad2.earnForBuildingsMoney[3] = 10;
			railroad2.earnForBuildingsMoney[4] = 20;
			railroad2.buildedHouses = 0;
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
			railroad3.owner = -1;
			railroad3.buy = 20;
			railroad3.id = index;
			railroad3.earnForBuildingsMoney[1] = 2.5;
			railroad3.earnForBuildingsMoney[2] = 5;
			railroad3.earnForBuildingsMoney[3] = 10;
			railroad3.earnForBuildingsMoney[4] = 20;
			railroad3.name = "autobus MPK";
			railroad3.special = true;
			railroad3.buildedHouses = 0;
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
			railroad4.owner = -1;
			railroad4.id = index;
			railroad4.buy = 20;
			railroad4.earnForBuildingsMoney[1] = 2.5;
			railroad4.earnForBuildingsMoney[2] = 5;
			railroad4.earnForBuildingsMoney[3] = 10;
			railroad4.earnForBuildingsMoney[4] = 20;
			railroad4.name = "tramwaj MPK";
			railroad4.special = true;
			railroad4.buildedHouses = 0;
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

			// tu mozesz ja wziac cala

			addPlayers(boardFields);
		}
	}


	void addPlayers(Field* boardFields) {
		int boardPlayersPosition[40][6] = {};
		PlayerInformations players[6] = {};

		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 6; j++) {
				boardPlayersPosition[i][j] = -1;
			}
		}

		int countPlayers = 4;


		for (int i = 0; i < 6	; i++) {
			if (countPlayers > i) {
				PlayerInformations player;
				player.id = i;
				player.money = 150;
				player.position = 1;
				player.name = "player";
				player.stopedRounds = 0;
				player.sittingInJail = false;
				players[i] = player;
				boardPlayersPosition[0][i] = i;
				cout << i << endl;
			}
			else {
				PlayerInformations player;
				player.id = -1;
				players[i] = player;
			}

		}


		startGame(boardPlayersPosition, boardFields, players);
	}

	void startGame(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players) {
		int startingPlayer = rollDice()-1;
		PlayerInformations currentPlayer;
		int currentPlayerId;

		for (int i = 0; i < 6; i++) {
			if (i + startingPlayer < 6) {
				if (players[startingPlayer + i].id != -1) {
					currentPlayer = players[startingPlayer + i];
					currentPlayerId = players[startingPlayer + i].id;
				}
			}
			else {
				if (players[startingPlayer + i - 6].id != -1) {
					currentPlayer = players[startingPlayer - 6 + i];
					currentPlayerId = players[startingPlayer + i].id;
				}
			}

		}

		printPlayersInformations(currentPlayer);
		startPlayerTurn(boardPlayersPosition, boardFields, players, currentPlayer);
	}

	void startPlayerTurn(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer) {
		if (currentPlayer.stopedRounds > 0) {
			if (currentPlayer.sittingInJail == true) {

			}
			else {
				cout << "Pauzujesz t¹ kolejkê. Zosta³o: "<< players[currentPlayer.id].stopedRounds - 1<<endl;
				players[currentPlayer.id].stopedRounds = players[currentPlayer.id].stopedRounds - 1;
				nextPlayer(boardPlayersPosition, boardFields, players, currentPlayer);

			}
		}
		else {
			cout << "Rzuæ kostk¹ graczu o ID: " << currentPlayer.id << endl;
			int firstDice = rollDice();
			int secondDice = rollDice();
			cout << "pierwsza kostka: " << firstDice << endl;
			cout << "druga kostka: " << secondDice << endl;
			int playerPosition;
			for (int i = 0; i < 40; i++) {
				if (boardPlayersPosition[i][currentPlayer.id] == currentPlayer.id) {
					playerPosition = i;
					boardPlayersPosition[i][currentPlayer.id] = -1;
				}
			}
			int nextPosition = findPlayerPositionMovingForward(playerPosition, firstDice + secondDice);
			cout << "rolled fields: " << firstDice + secondDice << endl;
			cout << "nextPosition: " << nextPosition << endl;

			//Ruszanie gracza
			game.movePlayer(currentPlayer.id, nextPosition);
			game.render();
			
			boardPlayersPosition[nextPosition][currentPlayer.id] = currentPlayer.id;
			//printPlayersPlaces(boardPlayersPosition);
			if (firstDice == secondDice) {
				checkField(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, true);
			}
			else {
				checkField(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);

			}

			//nextPlayer(boardPlayersPosition, boardFields, players, currentPlayer);
		}



	}

	void checkField(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet) {
		cout << "before" << endl;
		cout << "id gracza: " << currentPlayer.id << endl;
		printField(boardFields[nextPosition]);
		printPlayersInformations(players[currentPlayer.id]);
		Field sittingField = boardFields[nextPosition];
		bool stillPlaying = true;
		if (sittingField.special) {
			if(sittingField.specialType==1){
				//studencki ciezki zywot
				hardLife(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
				stillPlaying = false;
			}
			else if (sittingField.specialType == 2) {
				//oplata za warunek - 200
				loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet,20);
				stillPlaying = false;
			}
			else if (sittingField.specialType == 3) {
				//railway
				railway(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
				stillPlaying = false;
			}else if(sittingField.specialType == 4){
				//szansa
				chance(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
				stillPlaying = false;
			}else if(sittingField.specialType == 7){
				//wiezeinie
				goToJail(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false, 3);
				stillPlaying = false;
			}else if(sittingField.specialType == 8){
				//oplata za warunek - 100
				loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, 10);
				stillPlaying = false;
			}
		}
		else {
			if (sittingField.owner != -1) {
				if (sittingField.owner != currentPlayer.id) {
					float cost = sittingField.earnForBuildingsMoney[sittingField.buildedHouses];
					if (currentPlayer.money >= cost) {
						currentPlayer.money = currentPlayer.money - cost;
						players[currentPlayer.id].money = players[currentPlayer.id].money - cost;
						players[sittingField.owner].money = players[sittingField.owner].money + cost;

					}
					else {
						notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, cost, sittingField.owner);
						stillPlaying = false;
					}
				}

			}
			else {
				if (currentPlayer.money > sittingField.buy) {
					cout << "Would you like to buy(true/false)? It cost: " << sittingField.buy << endl;
					string buy;
					cin >> buy;
					if (buy == "true") {
						boardFields[nextPosition].owner = currentPlayer.id;
						currentPlayer.money = currentPlayer.money - sittingField.buy;
						players[currentPlayer.id].money = players[currentPlayer.id].money - sittingField.buy;
					}
					game.setFieldColor(nextPosition, currentPlayer.id);
					game.render();
				}
			}

		}
		if (stillPlaying) {
			cout << "after" << endl;
			printField(boardFields[nextPosition]);
			printPlayersInformations(players[currentPlayer.id]);
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
		}


	}

	void hardLife(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet){
		int randomAction = rollDice()-1; //random
		if (randomAction == 0) {
			cout << "W nocy twojemu wyk³adowcy zala³o pokój przez gniazdko elektryczne, i musi odespaæ - idziesz 2 pola do przodu";
			int next = findPlayerPositionMovingForward(nextPosition, 2);
			boardPlayersPosition[nextPosition][currentPlayer.id] = -1;
			boardPlayersPosition[next][currentPlayer.id] = currentPlayer.id;
			checkField(boardPlayersPosition, boardFields, players, currentPlayer, next, doublet);
			game.movePlayer(currentPlayer.id, next);
			game.render();
		}
		if(randomAction==1){
			cout << "Trafi³eœ na wyk³ad profesora Migasa – stoisz nastêpn¹ turê" <<endl;
			players[currentPlayer.id].stopedRounds = players[currentPlayer.id].stopedRounds + 1;
			endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);
		}
		if (randomAction == 2) {
			cout << "Zosta³eœ z³apany przy próbie przemycenia w³asnego alkoholu do Studia. Idziesz na 2 tury do wiêzienia " << endl;
			goToJail(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false, 2);
			game.movePlayer(currentPlayer.id, 90);
			game.render();
		}
		if (randomAction == 3) {
			cout << "Spotka³eœ pani¹ mgr. In¿ Mariê Grzelak. Co prawda nie ruszasz siê z miejsca ale za to masz lepszy humor." << endl;
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
		}
		if (randomAction == 4) {
			cout << "Twoja strona z niepopularnymi opiniami dotycz¹cymi dziekana okaza³a siê byæ publiczna. Stoisz dwie kolejki " << endl;
			players[currentPlayer.id].stopedRounds = players[currentPlayer.id].stopedRounds + 2;
			endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);
		}
		if (randomAction == 5) {
			cout << "W akademiku zamaraz³y rury z wod¹. Stoisz nastepn¹ kolejkê (Nie pójdziesz przecie¿ na zajêcia nieœwie¿y) " <<endl;
			players[currentPlayer.id].stopedRounds = players[currentPlayer.id].stopedRounds + 1;
			endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);
		}
	}


	void chance(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet){
		int randomAction = rollDice()-1; //random
		if (randomAction == 0) {
			cout << "Podczas nape³niania dmuchanego jacuzzi zala³eœ pokój w akademiku: Kara 10zl" << endl;
			loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet,10);
		}
		if (randomAction == 1) {
			cout << "Piêkna Kelnerka w Mekongu wyda³a ci 5zl za du¿o, s¹ twoje " << endl;
			players[currentPlayer.id].money = players[currentPlayer.id].money + 5;
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

		}
		if (randomAction == 2) {
			cout << "Zosta³eœ z³apany bez biletu w autobusie - zaplac 10zl mandatu" << endl;
			loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, 10);
		}
		if (randomAction == 3) {
			cout << "Udzielasz korepetycji synowi kole¿anki twojej mamy - pobierz 10" << endl;
			players[currentPlayer.id].money = players[currentPlayer.id].money + 10;
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

		}
		if (randomAction == 4) {
			cout << "Op³ata za pokój w akademiku - zap³aæ 20zl " << endl;
			loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, 20);
		}
		if (randomAction == 5) {
			cout << "Zebra³eœ astronomiczn¹ iloœæ ¿appsów - pobierz 10zl" << endl;
			loseMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, 10);
		}
	}


	void railway(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet){
		Field sittingField = boardFields[nextPosition];

		if (sittingField.owner != -1) {
			if (sittingField.owner != currentPlayer.id) {

				int sittingFieldOwnerRailways = 0;
				if(boardFields[5].owner==sittingField.owner){
					sittingFieldOwnerRailways = sittingFieldOwnerRailways + 1;
				}
				if (boardFields[15].owner == sittingField.owner) {
					sittingFieldOwnerRailways = sittingFieldOwnerRailways + 1;
				}
				if (boardFields[25].owner == sittingField.owner) {
					sittingFieldOwnerRailways = sittingFieldOwnerRailways + 1;
				}
				if (boardFields[35].owner == sittingField.owner) {
					sittingFieldOwnerRailways = sittingFieldOwnerRailways + 1;
				}


				float cost = sittingField.earnForBuildingsMoney[sittingFieldOwnerRailways];
				if (currentPlayer.money >= cost) {
					currentPlayer.money = currentPlayer.money - cost;
					players[currentPlayer.id].money = players[currentPlayer.id].money - cost;
					players[sittingField.owner].money = players[sittingField.owner].money + cost;

					nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

				}
				else {
					notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, cost, sittingField.owner);
				}
			}
			else {
				nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

			}

		}
		else {
			if (currentPlayer.money > sittingField.buy) {
				cout << "Would you like to buy(true/false)? It cost: " << sittingField.buy << endl;
				string buy;
				cin >> buy;
				if (buy == "true") {
					boardFields[nextPosition].owner = currentPlayer.id;
					currentPlayer.money = currentPlayer.money - sittingField.buy;
					players[currentPlayer.id].money = players[currentPlayer.id].money - sittingField.buy;
					game.setFieldColor(nextPosition, currentPlayer.id);
					game.render();
				}



			}
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

		}
	}



	void goToJail(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet, int stopedRounds){
		for (int i = 0; i < 40; i++) {
			if (boardPlayersPosition[i][currentPlayer.id] == currentPlayer.id) {
				boardPlayersPosition[i][currentPlayer.id] = -1;
			}
			else if (i == 10) {
				boardPlayersPosition[i][currentPlayer.id] = currentPlayer.id;
			}
		}
		players[currentPlayer.id].stopedRounds = stopedRounds;
		endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);

	}


	void loseMoney(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet, int money){
		if(players[currentPlayer.id].money > money){
			players[currentPlayer.id].money = players[currentPlayer.id].money - money;
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
		}
		else {
			notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, money, -1);
		}
	}

	void notEnoughtMoney(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet,float money, int ownerId) {
		cout << "cena: " << money<<endl;
		if (players[currentPlayer.id].money < money) {
			cout << "Co chcesz zrobiæ?" << endl;
			cout << "1) Sprzedaj pola" << endl;
			cout << "2) Sprzedaj apartamenty/hotele" << endl;
			cout << "3) Poddaj sie" << endl;

			int choosenAction;
			cin >> choosenAction;

			switch (choosenAction)
			{
			case 1:
				houseAction(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, true, true,money, ownerId);
				break;
			case 2:
				sellField(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, true, money, ownerId);
				break;
			case 3:
				endGame(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
				break;
			default:
				notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, money, ownerId);
				break;
			}

		}
		else {
			cout << "Weszlo w wyjscie"<<endl;
			if (ownerId != -1) {
				players[ownerId].money = players[ownerId].money + money;
			}
				players[currentPlayer.id].money = players[currentPlayer.id].money - money;
			
			
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

		}


	}

	void endGame(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet) {
		for (int i = 0; i < 40; i++) {
			if (boardFields[i].owner == currentPlayer.id) {
				boardFields[i].owner = -1;
			}
			if (boardPlayersPosition[i][currentPlayer.id] == currentPlayer.id) {
				boardPlayersPosition[i][currentPlayer.id] = -1;
			}
		}
		players[currentPlayer.id].id = -1;
		
		endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, false);

	}

	void nextplayerActions(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet) {
		cout << "Co chcesz zrobiæ?" << endl;
		cout << "1) Buduj apartamenty/hotele" << endl;
		cout << "2) Sprzedaj apartamenty/hotele" << endl;
		cout << "3) Sprzedaj pola" << endl;
		if (doublet) {
			cout << "4) Rzuæ ponownie (doublet)" << endl;
		}
		else {
			cout << "4) Zakoñcz turê" << endl;
		}

		printPlayersInformations(players[currentPlayer.id]);

		int choosenAction;

		/*void przycisk1(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, false, false, 0, 0) {
			houseAction(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, false, false, 0, 0)
		}*/
		cin >> choosenAction;

		switch (choosenAction)
		{
		case 1:
			houseAction(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet,false, false, 0 ,0);
			break;
		case 2:
			houseAction(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, true, false,0,0);
			break;
		case 3:
			sellField(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, false,0,0);
			break;
		case 4:
			endCurrentMove(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);
			break;
		default:
			nextplayerActions(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet);

			break;
		}


	}

	void houseAction(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet, bool destroy,bool notEnoughtMoneyBool, int money,int ownerId) {
		Field playerFields[40] = {};
		Field possibleBuildingFields[40] = {};
		int currentIndex = 0;
		for (int i = 0; i < 40; i++) {
			if (boardFields[i].owner == currentPlayer.id && boardFields[i].special == false) {
				playerFields[currentIndex] = boardFields[i];
				currentIndex = currentIndex + 1;

			}
			possibleBuildingFields[i].id = -1;
		}

		

		int possibleFieldsTypes[8] = {};
		for (int i = 0; i < 8; i++) {
			possibleFieldsTypes[i] = -1;
		}

		for (int i = 1; i < 9; i++) {
			int countIndex = 0;
			for (int j = 0; j < 40; j++) {
				if (playerFields[j].type == i) {
					countIndex = countIndex + 1;
				}
			}

			if (i == 1 || i == 8) {
				if (countIndex == 2) {
					possibleFieldsTypes[i - 1] = i;
				}
			}
			else {
				if (countIndex == 3) {
					possibleFieldsTypes[i - 1] = i;
				}
			}

			// 1 8
		};

		int arrayWithId[40] = {};
		for (int i = 0; i < 40; i++) {
			arrayWithId[i] = -1;
		}
		int indexTemporary = 0;

		if (destroy) {
			cout << "Mo¿liwe pola do zburzenia domków: " << endl;
		}
		else {
			cout << "Mo¿liwe pola do budowy domków" << endl;
		}

		for (int i = 0; i < 9; i++) {
			if (possibleFieldsTypes[i] == i + 1) {
				Field temporaryArray[3] = {};
				for (int i = 0; i < 3; i++) {
					temporaryArray[i].id = -1;
				}
				int currentArrayIndex = 0;
				int maxHouses = -1;
				int minHouses = -1;
				for (int j = 0; j < 40; j++) {
					if (boardFields[j].type == i+1 ) {
						temporaryArray[currentArrayIndex] = boardFields[j];
						
						if (currentArrayIndex == 0) {
							maxHouses = boardFields[j].buildedHouses;
							minHouses = boardFields[j].buildedHouses;
						}
						else {
							if (boardFields[j].buildedHouses > maxHouses) {
								maxHouses = boardFields[j].buildedHouses;
							}
							if (boardFields[j].buildedHouses < minHouses) {
								minHouses = boardFields[j].buildedHouses;
							}
						}
						currentArrayIndex = currentArrayIndex + 1;
					}
				}

				if (destroy) {
					for (int i = 0; i < 3; i++) {
						if(maxHouses!=0){
							if (temporaryArray[i].id != -1 && temporaryArray[i].buildedHouses == maxHouses) {
								cout << temporaryArray[i].id << ") " << temporaryArray[i].name << " który ma " << temporaryArray[i].buildedHouses << " za " << temporaryArray[i].housePrice;
								arrayWithId[indexTemporary] = temporaryArray[i].id;
							}
						}


					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						if (minHouses != 5) {
							if (temporaryArray[i].id != -1 && temporaryArray[i].buildedHouses == minHouses) {
								cout << "weszlo w wypis"<<endl;
								cout << temporaryArray[i].id << ") " << temporaryArray[i].name << " ktory ma " << temporaryArray[i].buildedHouses << " za " << temporaryArray[i].housePrice <<endl;
								arrayWithId[indexTemporary] = temporaryArray[i].id;
								indexTemporary = indexTemporary + 1;
							}
						}


					}
				}



			}
		}

		cout << "40) Anuluj" << endl;
		int selectdValue;
		bool exitFlag = true;
		bool choosenAction = true;
		while (exitFlag)
		{
			cout << "Wybierz id z poœród podanych" <<endl;
			
			cin >> selectdValue;

			for (int i = 0; i < 40; i++) {
				if (arrayWithId[i] == selectdValue) {
					exitFlag = false;
				}
			}

			if (selectdValue == 40) {
				exitFlag = false;
				choosenAction = false;
			}
		}
		if(choosenAction){
			if (destroy) {
				players[currentPlayer.id].money = players[currentPlayer.id].money + boardFields[selectdValue].housePrice;
				boardFields[selectdValue].buildedHouses = boardFields[selectdValue].buildedHouses - 1;
			}
			else {
				if (players[currentPlayer.id].money >= boardFields[selectdValue].housePrice) {
					players[currentPlayer.id].money = players[currentPlayer.id].money - boardFields[selectdValue].housePrice;
					boardFields[selectdValue].buildedHouses = boardFields[selectdValue].buildedHouses + 1;
				}
				else {
					cout << "Jesteœ za biedny" << endl;
				}
			}
		}

		if (notEnoughtMoneyBool) {
			notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, money, ownerId);
		}
		else {
			nextplayerActions(boardPlayersPosition, boardFields, players, players[currentPlayer.id], nextPosition, doublet);

		}
	}

	void sellField(int boardPlayersPosition[][6], Field* boardFields, PlayerInformations* players, PlayerInformations currentPlayer, int nextPosition, bool doublet, bool notEnoughtMoneyBool, int money, int ownerId){
		Field playerFields[40] = {};
		Field possibleBuildingFields[40] = {};
		int typesWithBuildings[8] = {};
		int sellingFieldsId[40] = {};

		
		for (int i = 0; i < 40; i++) {
			playerFields[i].id = -1;
			sellingFieldsId[i] = -1;
		}

		for(int i =0; i<8;i++){
			typesWithBuildings[i] = -1;
		}

		int currentIndex = 0;

		for (int i = 0; i < 40; i++) {
			if (boardFields[i].owner == currentPlayer.id) {
				playerFields[currentIndex] = boardFields[i];
				currentIndex = currentIndex + 1;
				if (boardFields[i].buildedHouses != 0) {
					typesWithBuildings[boardFields[i].type] = typesWithBuildings[boardFields[i].type];
				}
			}
		}

		currentIndex = 0;

		for (int i = 0; i < 40; i++) {
			if (playerFields[i].id != -1) {
				for (int j = 0; j < 8; j++) {
					if (playerFields[i].type == typesWithBuildings[j]) {
						playerFields[i].id = -1;
					}
				}
			}
		}

		cout << "Mo¿liwe pola do sprzedania" << endl;


		for (int i = 0; i < 40; i++) {
			if(playerFields[i].id != -1){
				cout << playerFields[i].id << ") " << playerFields[i].name <<" za " << playerFields[i].buy << endl;
				sellingFieldsId[i] = playerFields[i].id;
			}
		}

		cout << "40) Anuluj" << endl;
		int selectdValue;
		bool exitFlag = true;
		bool choosenAction = true;
		while (exitFlag)
		{
			cout << "Wybierz id z poœród podanych" << endl;

			cin >> selectdValue;

			for (int i = 0; i < 40; i++) {
				if (playerFields[i].id == selectdValue) {
					exitFlag = false;
				}
			}

			if (selectdValue == 40) {
				exitFlag = false;
				choosenAction = false;
			}
		}

		if (choosenAction) {
				players[currentPlayer.id].money = players[currentPlayer.id].money + boardFields[selectdValue].buy;
				boardFields[selectdValue].owner = -1;
				game.setFieldColor(selectdValue, -1);
				game.render();
		}
		
		if (notEnoughtMoneyBool) {
			notEnoughtMoney(boardPlayersPosition, boardFields, players, currentPlayer, nextPosition, doublet, money, ownerId);

		}
		else {
			nextplayerActions(boardPlayersPosition, boardFields, players, players[currentPlayer.id], nextPosition, doublet);

		}




	}



		void endCurrentMove(int boardPlayersPosition[][6], Field * boardFields, PlayerInformations * players, PlayerInformations currentPlayer, int nextPosition, bool doublet) {
			if (doublet) {
				startPlayerTurn(boardPlayersPosition, boardFields, players, players[currentPlayer.id]);
			}
			else {
				nextPlayer(boardPlayersPosition, boardFields, players, currentPlayer);

			}
		}



		int findPlayerPositionMovingForward(int startingPosition, int movingFields) {
			if (startingPosition + movingFields < 40) {
				return startingPosition + movingFields;
			}
			else {
				int placesToStart = 40 - startingPosition;
				int remainingPlaces = movingFields - placesToStart;
				return remainingPlaces;
			}
		}

		void nextPlayer(int boardPlayersPosition[][6], Field * boardFields, PlayerInformations * players, PlayerInformations currentPlayer) {
			PlayerInformations nextPlayer;
			bool nextPlayerIsChoosen = false;
			bool endGame = true;
			for (int i = 0; i < 6; i++) {
				if (currentPlayer.id+1 + i >= 6) {
					if (players[currentPlayer.id + 1 + i - 6].id != -1) {
						if (!nextPlayerIsChoosen) {
							nextPlayer =players[currentPlayer.id + 1 + i - 6];
							nextPlayerIsChoosen = true;
						}
						else {
							endGame = false;
						}
					}
				}
				else {
					if (players[currentPlayer.id + 1 + i].id != -1) {
						if (!nextPlayerIsChoosen) {
							nextPlayer = players[currentPlayer.id + 1 + i];
							nextPlayerIsChoosen = true;
						}
						else {
							endGame = false;
						}
					}
				}
			}

			if (!endGame) {
				string test;
				cout << "Zakoñcz turê";
				cin >> test;
				cout << nextPlayer.id << endl;
				startPlayerTurn(boardPlayersPosition, boardFields, players, nextPlayer);
			}
			else {
				cout << "Wygra³ gracz o ID: " << nextPlayer.id << endl;
			}


		}




		int rollDice() {
			
			return (1 + (rand() % 6));
		}

		void printPlayersInformationsArray(PlayerInformations * players) {
			for (int i = 0; i < 6; i++) {
				printPlayersInformations(players[i]);
			}
		}

		void printPlayersInformations(PlayerInformations player) {
			cout << "id: " << player.id << endl;
			cout << "name: " << player.name << endl;
			cout << "money: " << player.money << endl;
			cout << "position: " << player.position << endl;
			cout << "stopedRounds: " << player.stopedRounds << endl;
			cout << "sittingInJail: " << player.sittingInJail << endl;
		}




		void printPlayersPlaces(int boardPlayersPosition[][6]) {
			cout << endl;
			for (int i = 0; i < 40; i++) {
				cout << i << ": ";
				for (int j = 0; j < 6; j++) {
					cout << " " << boardPlayersPosition[i][j] << " ";
				}
				cout << endl;
			}

		}

		void printFieldArray(Field * arr, int size) {
			cout << "size: " << size << endl;
			for (int i = 0; i < size; i++) {
				printField(arr[i]);
			}

		}

		void printField(Field field) {
			cout << "id: " << field.id;
			cout << " name: " << field.name;
			cout << " owner: " << field.owner;
			cout << " buildedHouses: " << field.buildedHouses;
			cout << " house[0]: " << field.earnForBuildingsMoney[0];
			cout << " house[1]: " << field.earnForBuildingsMoney[1];
			cout << " house[2]: " << field.earnForBuildingsMoney[2];
			cout << " house[3]: " << field.earnForBuildingsMoney[3];
			cout << " house[4]: " << field.earnForBuildingsMoney[4];
			cout << " house[4]: " << field.earnForBuildingsMoney[4];
			cout << " buy: " << field.buy;
			cout << " type: " << field.type;
			cout << " housePrice: " << field.housePrice;
			cout << " description: " << field.description;
			cout << " special: " << field.special;
			cout << " specialType: " << field.specialType << endl;


		}





	
};