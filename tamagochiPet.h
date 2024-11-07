#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class tamagochiPet
{
protected:
	string nameOfPet;
	string whatKinfOfPetIs;
	string breedOfPet;
public:
	float healthOfPet;
	double forFoodOfPet;
	float satisfactionFromFunOfPet;
	float purityOfPet;
	float moneyFromWork;
	float tirednessOfPet;

	tamagochiPet()
	{
		this->nameOfPet = "Zwierze";
		this->whatKinfOfPetIs = "Nieznane";
		this->breedOfPet = "Nieznana";
		this->healthOfPet = 100;
		this->forFoodOfPet = 50;
		this->satisfactionFromFunOfPet = 10;
		this->purityOfPet = 100;
		this->tirednessOfPet = 0;
		this->moneyFromWork = 70;
	}

	void displayInfoOfPet()
	{
		cout << "Imie: " << this->nameOfPet << endl << "Co to jest za zwierze: " << this->whatKinfOfPetIs << endl << "Rasa zwierzecia: " << this->breedOfPet << endl;
		cout << "Zdrowie zwierzaka wynosi: " << this->healthOfPet << endl << "Najedzenie wynosi: " << this->forFoodOfPet << endl << "Zaspokojenie zabawy wynosi: " << this->satisfactionFromFunOfPet << endl;
		cout << "Czystosc zwierzaka wynosi: " << this->purityOfPet << endl << "Zmeczenie: " << this->tirednessOfPet << endl << "Pieniadze: " << this->moneyFromWork << endl;
	}

	void changeInfoOfPet()
	{
		cin.ignore();
		cout << "            Wprowadz imie: ";
		getline(cin, this->nameOfPet);
		cout << "            Wprowadz co to za zwierze: ";
		getline(cin,this->whatKinfOfPetIs);
		cout << "            Wprowadz rase: ";
		getline(cin,this->breedOfPet);
	}

	void saveChangesToFile()
	{
		ofstream save;
		save.open("tamagochi_save.txt");
		save << this->nameOfPet << endl;
		save << this->whatKinfOfPetIs << endl;
		save << this->breedOfPet << endl;
		save << this->healthOfPet << endl;
		save << this->forFoodOfPet << endl;
		save << this->satisfactionFromFunOfPet << endl;
		save << this->purityOfPet << endl;
		save << this->tirednessOfPet << endl;
		save << this->moneyFromWork << endl;
		save.close();
	}
	
	void loadChangesFromFile()
	{
		ifstream load;
		load.open("tamagochi_save.txt");
		if (load.is_open())
		{
			load >> this->nameOfPet;
			load >> this->whatKinfOfPetIs;
			load >> this->breedOfPet;
			load >> this->healthOfPet;
			load >> this->forFoodOfPet;
			load >> this->satisfactionFromFunOfPet;
			load >> this->purityOfPet;
			load >> this->tirednessOfPet;
			load >> this->moneyFromWork;
			load.close();
		}
		else
		{
			cout << "Nie udalo sie otworzyc pliku lub nie isnieje" << endl;
		}
	}
};