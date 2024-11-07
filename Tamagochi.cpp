#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctype.h>
#include "tamagochiPet.h"
using namespace std;

void startWindow ()
{
    cout << "" << endl; 
    cout << "===================" << endl;
    cout << "||   Tamagochi   ||" << endl;
    cout << "===================" << endl;
    cout << "" << endl;
    cout << "===================" << endl;
    cout << "||    Wcisnij    ||" << endl;
    cout << "||   Klawisz 1   ||" << endl;
    cout << "||     Oraz      ||" << endl;
    cout << "||   Zatwierdz   ||" << endl;
    cout << "===================" << endl;
    cout << "" << endl;
}

float alignToMax (float parameter) 
{
    if (parameter > 100) 
    {
        return 100;
    }

    return parameter;
}

float alignToMin(float parameter)
{
    if (parameter < 0)
    {
        return 0;
    }

    return parameter;
}

void mainGame (tamagochiPet pet)
{
    char choooseActionForTamagochi, moneyWorkedInTime;
    float sumOfMoneyWorkedInTime;
    int optionForMoney = 0;
    int optionForAction = 0;
    bool exitToMenu = false;
    bool wasCorrectForAction = false;
    bool wasCorrectForMoney = false;
    while (exitToMenu == false) 
    {
        cout << "Zdrowie: " << pet.healthOfPet << endl;
        cout << "Najedzenie: " << pet.forFoodOfPet << endl;
        cout << "Zaspokojenie zabawy: " << pet.satisfactionFromFunOfPet << endl;
        cout << "Czystosc: " << pet.purityOfPet << endl;
        cout << "Zmeczenie: " << pet.tirednessOfPet << endl;
        cout << "Pieniadze: " << pet.moneyFromWork << endl;

        cout << "" << endl;
        cout << "Wybierz: " << endl;
        cout << "1. Nakarm" << endl << "2. Pobaw sie" << endl << "3. Prysznic" << endl << "4. Pojdz do weterynarza" << endl << "5. Pojdz spac" << endl << "6. Popracuj" << endl << "7. Wroc do menu" << endl;
        cin >> choooseActionForTamagochi;
        do
        {
            if (isalpha(choooseActionForTamagochi))
            {
                cout << "Wprowadzono litere zamiast cyfry" << endl;
                cout << endl;
            }
            else
            {
                optionForAction= (int)choooseActionForTamagochi - 48;
                if (optionForAction < 1 && optionForAction > 7)
                {
                    cout << "Wprowadz poprawna watosc" << endl;
                    cin >> choooseActionForTamagochi;
                }
                else
                {
                    wasCorrectForAction = false;
                }
            }
        } while (wasCorrectForAction);
        
        switch (optionForAction)
        {
        case 1:
            if (pet.forFoodOfPet == 100)
            {
                cout << "Nie możesz nakarmic tamagochi, iz jest najedzony" << endl;
                cout << endl;
            }
            else 
            {
                pet.forFoodOfPet += 20;
                pet.forFoodOfPet = alignToMax(pet.forFoodOfPet);
            }
            system("cls");
            break;
        case 2:
            pet.forFoodOfPet -= 2.5;
            pet.purityOfPet -= 12.5;
            pet.tirednessOfPet += 5;
            if (pet.satisfactionFromFunOfPet == 100)
            {
                cout << "Nie mozesz pobawic sie z tamagochi, iz jest zaspokojony zabawa w pelni" << endl;
                cout << endl;
            }
            else if (pet.tirednessOfPet == 100)
            {
                cout << "Nie możesz pobawic sie z tamagochi, iz jest zmeczony" << endl;
                cout << endl;
            }
            else if (pet.purityOfPet == 100)
            {
                cout << "Nie możesz pobawic sie z tamagochi, iz jest brudny" << endl;
                cout << endl;
            }
            else if (pet.purityOfPet == 0)
            {
                pet.satisfactionFromFunOfPet = 10;
            }
            else
            {
                pet.satisfactionFromFunOfPet += 20;
                
                pet.satisfactionFromFunOfPet = alignToMax(pet.satisfactionFromFunOfPet);

                pet.satisfactionFromFunOfPet = alignToMin(pet.satisfactionFromFunOfPet);
            }
            system("cls");
            break;
        case 3:
            pet.purityOfPet = 100;
            alignToMin(pet.purityOfPet);
            system("cls");
            break;
        case 4:
            pet.moneyFromWork -= 30;
            pet.healthOfPet = 100;
            system("cls");
            break;
        case 5:
            pet.tirednessOfPet = 0;
            system("cls");
            break;
        case 6:
            if (pet.tirednessOfPet == 100)
            {
                cout << "Nie mozesz pracowac, poniewaz jestes zmeczony odpocznij" << endl;
                cout << endl;
            }
            else
            {
                cout << "Wprowadz ile godzin chcesz pracowac: " << endl;
                cin >> moneyWorkedInTime;
                do
                {
                    if (isalpha(moneyWorkedInTime))
                    {
                        cout << "Wprowadzono litere zamiast cyfry" << endl;
                        cout << endl;
                    }
                    else
                    {
                        optionForMoney = (int)moneyWorkedInTime - 48;
                        if (optionForMoney < 0 || optionForMoney > 13)
                        {
                            cout << "Wprowadz poprawna watosc" << endl;
                            cin >> moneyWorkedInTime;
                        }
                        else
                        {
                            wasCorrectForMoney = false;
                        }
                    }
                } while (wasCorrectForAction);
                
                sumOfMoneyWorkedInTime = optionForMoney * 10;
                pet.moneyFromWork += sumOfMoneyWorkedInTime;
                cout << "Zarobiles " << sumOfMoneyWorkedInTime << " pieniedzy." << endl;
                pet.satisfactionFromFunOfPet -= optionForMoney * 8.3;
                pet.tirednessOfPet += optionForMoney *8.3;
                pet.tirednessOfPet = alignToMin(pet.tirednessOfPet);
                pet.satisfactionFromFunOfPet = alignToMin(pet.satisfactionFromFunOfPet);
            }
            system("cls");
            break;
        case 7:
            exitToMenu = true;
            pet.saveChangesToFile();
            system("cls");
            break;
        }
       
        if (pet.satisfactionFromFunOfPet == 0)
        {
            cout << "Pobaw sie z swoim tamagochi" << endl;
            cout << endl;
        }

        if (pet.forFoodOfPet == 0)
        {
            cout << "Nakarm swoje tamagochi" << endl;
            cout << "Jesli tego nie zrobisz, zacznie umierac z glodu" << endl;
            cout << endl;
            pet.healthOfPet = pet.healthOfPet - 5;
        }

        if (pet.forFoodOfPet < 0)
        {
            pet.forFoodOfPet = alignToMin(pet.forFoodOfPet);
        }

        if (pet.healthOfPet == 0)
        {
            cout << "Twoje tamagochi umarlo" << endl;
            cout << "Sproboj jeszcze raz" << endl;
            remove("tamagochi_save.txt");
            exitToMenu = true;
        }

        if (pet.purityOfPet == 0)
        {
            cout << "Twoje tamagochi jest brudne" << endl;
            cout << "otrzymujesz tylko polowe bonusu z zabawy" << endl;
            cout << endl;
        }

        if (pet.purityOfPet < 0)
        {
            pet.purityOfPet = alignToMin(pet.purityOfPet);
        }
        
        if (pet.tirednessOfPet > 100)
        {
            pet.tirednessOfPet = alignToMax(pet.tirednessOfPet);
        }

        if (pet.tirednessOfPet < 0)
        {
            pet.tirednessOfPet = alignToMin(pet.tirednessOfPet);
        }
    }
}

void menuOfGame (tamagochiPet pet)
{
    char  chooseOption, areYouSureToExit;
    int option = 0, optionToExit = 0;
    bool exit = false;
    bool wasCorrect = false;
    bool wasCorrectToExit = false;
    while (exit == false) // menu
    {
        pet.loadChangesFromFile();
        cout << "" << endl;
        cout << "Wybierz: " << endl;
        cout << "1. Nazywanie swojego tamagochi" << endl << "2. Aktualne informacje o tamagochi" << endl << "3. Gdzie znajduje sie zapis gry" << endl << "4. Graj" << endl;
        cout << "5. Wyjscie z gry" << endl;
        cout << "Wprowadz: ";
        cin >> chooseOption;
        do
        {
            if (isalpha(chooseOption))
            {
                cout << "Wprowadzono litere zamiast cyfry" << endl;
                cout << endl;
            }
            else
            {
                option = (int) chooseOption - 48;
                if (option < 1 && option > 5)
                {
                    cout << "Wprowadz poprawna watosc" << endl;
                    cin >> chooseOption;
                }
                else
                {
                    wasCorrect = false;
                }
            }
        } while (wasCorrect);

        switch (option)
        {
        case 1:
            system("cls"); //change name of tamagochi
            cout << "---!!!--->ZAMIAST SPACJI UZYWAJ MYSLNIKA<---!!!---" << endl;
            cout << "            Zmien dane tamagochi:           " << endl;
            pet.changeInfoOfPet();
            pet.saveChangesToFile();
            break;
        case 2:
            system("cls"); //show infos of tamagochi
            cout << "Aktualne info o tamagochi: " << endl;
            pet.displayInfoOfPet();
            break;
        case 3:
            system("cls"); //where game is saved
            cout << "Zapis gry znajduje sie w miejscu uruchomienia gry" << endl;
            break;
        case 4:
            system("cls");
            mainGame(pet);
            pet.loadChangesFromFile();
            break;
        case 5: //exit from game
            cout << "Czy aby napewno chcesz wyjsc z gry?" << endl;
            cout << "1. Tak " << "                                   " << "2. Nie " << endl;
            cin >> areYouSureToExit;
            do
            {
                if (isalpha(areYouSureToExit))
                {
                    cout << "Wprowadzono litere zamiast cyfry" << endl;
                    cout << endl;
                }
                else
                {
                    optionToExit = (int)areYouSureToExit - 48;
                    if (optionToExit < 1 && optionToExit > 2)
                    {
                        cout << "Wprowadz poprawna watosc" << endl;
                        cin >> areYouSureToExit;
                    }
                    else
                    {
                        wasCorrectToExit = false;
                    }
                }
            } while (wasCorrectToExit);
            
            switch (optionToExit)
            {
            case 1:
                exit = true;
                pet.saveChangesToFile();
                break;
            case 2:
                exit = false;
                break;
            }
            system("cls");
            break;
        }
    }
}

int main()
{
    char buttonForNextPattern;
    tamagochiPet pet;
    startWindow();
    cin >> buttonForNextPattern;
    while (buttonForNextPattern != '1')
    {
        cout << "Wprowadz poprawna watosc" << endl;
        cin >> buttonForNextPattern;
    }
    system("cls");
    menuOfGame(pet);
}