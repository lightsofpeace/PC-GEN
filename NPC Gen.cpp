///========================================Dungeons&Dragons: NPC and Character Generator========================================
///                            "Dungeons&Dragons: NPC and Character Generator" is unofficial Fan
///                                Content permitted under the Fan Content Policy. Not
///                            approved/endorsed by Wizards. Portions of the materials used are
///                              property of Wizards of the Coast. ©Wizards of the Coast LLC.
///                                         --<>--<>--<>--<>--<>--<>--<>--<>--
///                              <<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>
///                                         --<>--<>--<>--<>--<>--<>--<>--<>--
///                "Dungeons&Dragons: NPC and Character Generator" Originally Created by Lightsofpeace on 12/06/18.
///                                        Current Version 2.24.7 as of 03/13/2020
///========================================Dungeons&Dragons: NPC and Character Generator========================================
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

//NPC basics
string Race;
string Class;
string SubClass;
bool subclass = false;
string FightingStyle;
bool fightingstyle = false;
int Level;
string Alignment;
string Background;


//NPC stats
int proficiencyBonus;

unsigned int Str;
int strMod;
int Athletics;
unsigned int Dex;
int dexMod;
int Acrobatics;
int SleightOfHand;
int Stealth;
unsigned int Con;
int conMod;
unsigned int Int;
int intMod;
int Arcana;
int History;
int Investigation;
int Nature;
int Religion;
unsigned int Wis;
int wisMod;
int AnimalHandling;
int Insight;
int Medicine;
int Perception;
int Survival;
unsigned int Cha;
int chaMod;
int Deception;
int Intimidation;
int Performance;
int Persuasion;

int Initiative;
int Speed;
int swimSpeed;
int flightSpeed;
unsigned int HP;
unsigned int AC;
unsigned int spellAtk;
unsigned int spellDC;
vector<string> availableFeats;
vector<string> languages;
int LVL1slots;
int LVL2slots;
int LVL3slots;
int LVL4slots;
int LVL5slots;
int LVL6slots;
int LVL7slots;
int LVL8slots;
int LVL9slots;
int spellsknown;
int cantripsknown;
string ideals;
string bonds;
string flaws;

//userOption chooses if random or not
char userOption;
//vector for the NPCs feats
vector<string> userFeats;
//vector for NPC Proficiencies
vector<string> userProficiencies;
//functions
string RaceRandomizer();

string ClassRandomizer();

string AlignmentRandomizer(const string& Race, const string& Class);

void BackgroundRandomizer();

int LevelRandomizer();

void StatRandomizer(unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha);

void SkillRandomizer(int& strMod,int& dexMod,int& conMod,int& intMod, int& wisMod, int& chaMod);

void RacialBonusAndSubRace(string& Race, unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha);

void SubClassRandomizer(const string Class, const int Level, string& SubClass, string& FightingStyle, bool& subclass, bool& fightingstyle);

void IncreaseOrFeat(const int Level, unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha, vector<string>& availableFeats, vector<string>& userFeats);

void StatModifiers(const unsigned  int Str,const unsigned int Dex,const unsigned  int Con,const unsigned  int Int,const unsigned int Wis,const unsigned  int Cha, int& strMod, int& dexMod, int& conMod, int& intMod, int& wisMod, int& chaMod);

void CalcualteHP(const string Class, const int conMod, const int Level, unsigned int& HP);

void CalcualteAC(unsigned int& AC, const int dexMod);

void CalculateInitiative(int& Initiative, const int dexMod);

void CalcualteSpellAtk(const string Class, const int intMod, const int wisMod, const int chaMod, unsigned int& spellAtk);

void CalcualteDC(const unsigned int spellAtk, unsigned int& spellDC);

void SetSpeed (const string& Race, int& Speed, int& swimSpeed, int& flightSpeed);

void setProficiencies(vector<string>& userProficiencies);

void SetSlots (int& LVL1slots, int& LVL2slots, int& LVL3slots, int& LVL4slots ,int& LVL5slots, int& LVL6slots, int& LVL7slots, int& LVL8slots, int& LVL9slots);

void SpellsKnown (const int& Level, const string& SubClass, const string& Class, int& spellsknown, int& cantripsknown);

void DisplayCharacter (const int& passivePerception);

void setTraits(const string& Alignment, string& ideals, string& bonds, string& flaws);

void setLanguages();

int main(){
    ///Disclaimer
    cout << "========================================Dungeons&Dragons: NPC and Character Generator========================================" << endl;
    cout << "                            \"Dungeons&Dragons: NPC and Character Generator\" is unofficial Fan" << endl;
    cout << "                                Content permitted under the Fan Content Policy. Not" << endl;
    cout << "                            approved/endorsed by Wizards. Portions of the materials used are" << endl;
    cout << "                              property of Wizards of the Coast. ©Wizards of the Coast LLC." << endl;
    cout << "                                             --<>--<>--<>--<>-+-<>--<>--<>--<>--" << endl;
    cout << "                              <<>><<>><<>><<>><<>><<>><<>><<>>+<<>><<>><<>><<>><<>><<>><<>>" << endl;
    cout << "                                             --<>--<>--<>--<>-+-<>--<>--<>--<>--" << endl;
    cout << "                \"Dungeons&Dragons: NPC and Character Generator\" Originally Created by Lightsofpeace on 12/06/18." << endl;
    cout << "                                        Current Version 2.4.7 as of 02/16/2020" << endl;
    cout << "========================================Dungeons&Dragons: NPC and Character Generator========================================" << endl;

        //seed rand()
    srand(time(0));
    char loopYN = 'Y';
    while (loopYN == 'Y'){
        cout << "loopYN = " << loopYN << endl;
        //choose race
        Race = RaceRandomizer();
        //choose class
        Class = ClassRandomizer();
        //choose level
        Level = LevelRandomizer();
        //randomize alignment
        Alignment = AlignmentRandomizer(Race, Class);
        //randomize background
        BackgroundRandomizer();
        //randomize traits
        setTraits(Alignment, ideals, bonds, flaws);
        //randomize stats
        StatRandomizer(Str, Dex, Con, Int, Wis, Cha);
        //apply racial bonuses & randomize subrace
        RacialBonusAndSubRace(Race, Str, Dex, Con, Int, Wis, Cha);
        //randomize subclass
        SubClassRandomizer(Class, Level, SubClass, FightingStyle, subclass, fightingstyle);
        //determine stat increase or random feat
        IncreaseOrFeat(Level, Str, Dex, Con, Int, Wis, Cha, availableFeats, userFeats );
        //determine mods
        StatModifiers(Str, Dex, Con, Int, Wis, Cha, strMod, dexMod, conMod, intMod, wisMod, chaMod);
        //determine skills
        SkillRandomizer(strMod, dexMod, conMod, intMod, wisMod, chaMod);
        //calculate Initiative
        CalculateInitiative(Initiative, dexMod);
        //calculate HP
        CalcualteHP(Class, conMod, Level, HP);
        //calculate AC
        CalcualteAC(AC, dexMod);
        //calculate Spell Attack
        CalcualteSpellAtk(Class, intMod, wisMod, chaMod, spellAtk);
        //Calculate Spell DC
        CalcualteDC(spellAtk, spellDC);
        //Calculate Speed
        SetSpeed (Race, Speed, swimSpeed, flightSpeed);
        //Add character proficiencies
        setProficiencies(userProficiencies);
        //Passive Perception
        int passivePerception = wisMod + 10;
        //Set Spell Slots
        SetSlots (LVL1slots, LVL2slots, LVL3slots, LVL4slots , LVL5slots, LVL6slots, LVL7slots, LVL8slots, LVL9slots);
        //Set Spells Known
        SpellsKnown (Level, SubClass, Class, spellsknown, cantripsknown);

        //display chatacter
        cout << Race << ", ";
            if (fightingstyle == true ){
                cout << FightingStyle;
            }
            if (subclass == true ){
                cout << SubClass;
            }
            cout << "";
            cout << Class << ", " << "Level " << Level << endl << Alignment << ", " << Background << endl;
            cout << HP << " HP, " << AC <<" AC, " << Initiative << " Initiative, " << passivePerception << " Passive Perception, " << proficiencyBonus << " Proficiency Bonus" << endl;
            cout << Speed << " Speed, " << swimSpeed << " Swim Speed, " << flightSpeed << " Flight Speed" << endl;
            cout << "Strength:" << endl;
            cout << "Score: " << Str << " Mod: " << strMod << endl;
            cout << "Athletics: " << Athletics << endl;

            cout << "Dexterity:" << endl;
            cout << "Score: " << Dex << " Mod: " << dexMod << endl;
            cout << "Acrobatics: " << Acrobatics << ", Sleight of Hand: " << SleightOfHand << ", Stealth: " << Stealth << endl;

            cout << "Constitution:" << endl;
            cout << "Score: " << Con << " Mod: " << conMod << endl;

            cout << "Intelligence:" << endl;
            cout << "Score: " << Int << " Mod: " << intMod << endl;
            cout << "Arcana: " << Arcana << ", History: " << History << ", Investigation: " << Investigation << ", Nature: " << Nature << ", Religion: " << Religion << endl;

            cout << "Wisdom:" << endl;
            cout << "Score: " << Wis << " Mod: " << wisMod << endl;
            cout << "Animal Handling: " << AnimalHandling << ", Insight:" << Insight << ", Medicine: " << Medicine << ", Perception: " << Perception << ", Survival: " << Survival << endl;

            cout << "Charisma:" << endl;
            cout << "Score: " << Cha << " Mod: " << chaMod << endl;
            cout << "Deception: " << Deception << ", Intimidation: " << Intimidation << ", Performance: " << Performance << ", Persuasion: " << Persuasion << endl;

            cout << "Spell Attack: " << spellAtk << endl;
            cout << "Spell DC: " << spellDC << endl;

            cout << "Ideals: " << ideals << endl;
            cout << "Bonds: " << bonds << endl;
            cout << "Flaws: " << flaws << endl;

            cout << "Feats: ";
            for (unsigned int i=0; i < userFeats.size(); ++i){
                if(i == userFeats.size() - 1){
                    cout << userFeats.at(i) << " ";
                }
                else{
                    cout << userFeats.at(i) << ", ";
                }
            }
            cout << endl;
            cout << "Proficiencies: ";
            for (unsigned int i=0; i < userProficiencies.size(); ++i){
                if(i == userProficiencies.size() - 1){
                    cout << userProficiencies.at(i) << " ";
                }
                else{
                    cout << userProficiencies.at(i) << ", ";
                }
            }
            cout << endl;

            if ((Class == "Bard") || (Class == "Cleric") || (Class == "Druid") || (SubClass == "Eldritch Knight ") || (Class == "Paladin") || (SubClass == "Arcane Trickster ") || (Class == "Ranger") || (Class == "Sorcerer") || (Class == "Warlock") || (Class == "Wizard")){
                cout << "Spell Slots: " << endl;
                cout << "LVL 1: " << LVL1slots << ", " << "LVL 2: " << LVL2slots << ", " << "LVL 3: " << LVL3slots << ", " << "LVL 4: " << LVL4slots << ", " << "LVL 5: " << LVL5slots << ", " << "LVL 6: " << LVL6slots << ", " << "LVL 7: " << LVL7slots << ", " << "LVL 8: " << LVL8slots << ", " << "LVL 9: " << LVL9slots << endl;

                cout << "Spells Known: " << endl;
                if (cantripsknown == 69){
                    cout << "Cantrips: See Rules";
                }
                else {
                    cout << "Cantrips: " << cantripsknown;
                }
                if (spellsknown == 69){
                    cout << ", Spells: See Rules" << endl;
                }
                else {
                    cout << ", Spells: " << spellsknown << endl;
                }
            }

        DisplayCharacter (passivePerception);

        cout << "Generate Another NPC?" << endl << "enter Y or N (Capital Letters)" << endl;
        cin.ignore();
        cin.clear();
        cin >> loopYN;
    }

return 0;
}


string RaceRandomizer(){
cout << "Randomize Race?" << endl << "enter Y or N (Capital Letters)" << endl;
        cin >> userOption;
        if (userOption == 'Y'){
            //31 random races
            int randRace = 1 + rand() % 31;
            if (randRace == 1){
                Race = "Aarakocra";
            }
            if (randRace == 2){
                Race = "Aasimar";
            }
            if (randRace == 3){
                Race = "Animal-Hybrid";
            }
            if (randRace == 4){
                Race = "Bugbear";
            }
            if (randRace == 5){
                Race = "Centaur";
            }
            if (randRace == 6){
                Race = "Dragonborn";
            }
            if (randRace == 7){
                Race = "Dwarf";
            }
            if (randRace == 8){
                Race = "Loxodon";
            }
            if (randRace == 9){
                Race = "Elf";
            }
            if (randRace == 10){
                Race = "Firbolg";
            }
            if (randRace == 11){
                Race = "Genasi";
            }
            if (randRace == 12){
                Race = "Gith";
            }
            if (randRace == 13){
                Race = "Gnome";
            }
            if (randRace == 14){
                Race = "Goblin";
            }
            if (randRace == 15){
                Race = "Goliath";
            }
            if (randRace == 16){
                Race = "Half-Elf";
            }
            if (randRace == 17){
                Race = "Half-Orc";
            }
            if (randRace == 18){
                Race = "Halfling";
            }
            if (randRace == 19){
                Race = "Hobgoblin";
            }
            if (randRace == 20){
                Race = "Human";
            }
            if (randRace == 21){
                Race = "Kenku";
            }
            if (randRace == 22){
                Race = "Kobold";
            }
            if (randRace == 23){
                Race = "Lizardfolk";
            }
            if (randRace == 24){
                Race = "Minotaur";
            }
            if (randRace == 25){
                Race = "Orc";
            }
            if (randRace == 26){
                Race = "Yuan-ti";
            }
            if (randRace == 27){
                Race = "Tabaxi";
            }
            if (randRace == 28){
                Race = "Tiefling";
            }
            if (randRace == 29){
                Race = "Triton";
            }
            if (randRace == 30){
                Race = "Tortle";
            }
            if (randRace == 31){
                Race = "Vedalken";
            }
        }
        else if (userOption == 'N'){
            cout << "Enter Race or Help for list of Races" << endl;
            cin >> Race;
            while (Race == "Help"){
                cout << "The available Races are: Aarakocra, Aasimar, Animal-Hybrid, Bugbear, Centaur, Dragonborn, Dwarf, Loxodon, Elf, Firblog, Genasi, Gith, Gnome, Goblin, Goliath, Half-Elf, Half-Orc, Halfling, Hobgoblin, Human, Kenku, Kobold, Lizardfolk, Minotaur, Orc, Yuan-ti, Tabaxi, Tiefling, Triton, Tortle, Vedalken" << endl;
                cin >> Race;
            }
            while ((Race != "Aarakocra") && (Race != "Aasimar") && (Race != "Animal-Hybrid") && (Race != "Bugbear") && (Race != "Centaur") && (Race != "Dragonborn") && (Race != "Dwarf") && (Race != "Loxodon") && (Race != "Elf") && (Race != "Firblog") && (Race != "Genasi") && (Race != "Gith") && (Race != "Gnome") && (Race != "Goblin") && (Race != "Goliath") && (Race != "Half-Elf") && (Race != "Half-Orc") && (Race != "Halfling") && (Race != "Hobgoblin") && (Race != "Human") && (Race != "Kenku") && (Race != "Kobold") && (Race != "Lizardfolk") && (Race != "Minotaur") && (Race != "Orc") && (Race != "Yuan-ti") && (Race != "Tabaxi") && (Race != "Tiefling") && (Race != "Triton") && (Race != "Tortle") && (Race != "Vedalken") && (Race != "Help")){
                cout << "Sorry, that is not an available Race, please check spelling and letter case. Remember the first letter must be Capitalized" << endl;
                cin >> Race;
            }
        }
return Race;
}

string ClassRandomizer(){
	cout << "Randomize Class?" << endl
			 << "enter Y or N (Capital Letters)" << endl;
	cin >> userOption;
	if (userOption == 'Y'){
			//12 random classes
	int randClass = 1 + rand() % 12;
			if (randClass == 1){
				Class = "Barbarian";
			}
			if (randClass == 2){
				Class = "Bard";
			}
			if (randClass == 3){
				Class = "Cleric";
			}
			if (randClass == 4){
				Class = "Druid";
			}
			if (randClass == 5){
				Class = "Fighter";
			}
			if (randClass == 6){
				Class = "Monk";
			}
			if (randClass == 7){
				Class = "Paladin";
			}
			if (randClass == 8){
				Class = "Ranger";
			}
			if (randClass == 9){
				Class = "Rogue";
			}
			if (randClass == 10){
				Class = "Sorcerer";
			}
			if (randClass == 11){
				Class = "Warlock";
			}
			if (randClass == 12){
				Class = "Wizard";
			}
		}
		else if (userOption == 'N'){
			cout << "Enter Class or Help for list of Classes" << endl;
			cin >> Class;
			while (Class == "Help"){
				cout << "The available Races are: Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, Wizard" << endl;
				cin >> Class;
			}
			while ((Class != "Bard") && (Class != "Barbarian") && (Class != "Cleric") && (Class != "Druid") && (Class != "Fighter") && (Class != "Monk") && (Class != "Paladin") && (Class != "Ranger") && (Class != "Rogue") && (Class != "Sorcerer") && (Class != "Warlock") && (Class != "Wizard") && (Class != "Help")){
				cout << "Sorry, that is not an available Class, please check spelling and letter case. Remember the first letter must be Capitalized" << endl;
				cin >> Class;
			}
		}
		return Class;
}

string AlignmentRandomizer(const string& Race, const string& Class){
    cout << "Randomize Alignment?" << endl << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if (userOption == 'Y'){
        int randAlignment = 1 + rand() % 9;
        if (randAlignment == 1){
            Alignment = "Lawful-Good";
        }
        if (randAlignment == 2){
            Alignment = "Neutral-Good";
        }
        if (randAlignment == 3){
            Alignment = "Chaotic-Good";
        }
        if (randAlignment == 4){
            Alignment = "Lawful-Neutral";
        }
        if (randAlignment == 5){
            Alignment = "True-Neutral";
        }
        if (randAlignment == 6){
            Alignment = "Chaotic-Neutral";
        }
        if (randAlignment == 7){
            Alignment = "Lawful-Evil";
        }
        if (randAlignment == 8){
            Alignment = "Neutral-Evil";
        }
        if (randAlignment == 9){
            Alignment = "Chaotic-Evil";
        }
    }
    else if (userOption == 'N'){
        cout << "Pseudo-Randomize based on Class and Race?" << endl;
        cin >> userOption;
        if (userOption == 'Y'){
            if (Class == "Barbarian"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
            }
            if (Class == "Bard"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
                if (randNum == 3){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Cleric"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Neutral-";
                }
                if (randNum == 2){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Druid"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Neutral-";
                }
                if (randNum == 2){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Fighter"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
                if (randNum == 3){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Monk"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Neutral-";
                }
                if (randNum == 2){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Paladin"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Ranger"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Neutral-";
                }
                if (randNum == 2){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Rogue"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
                if (randNum == 3){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Sorcerer"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
            }
            if (Class == "Warlock"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Lawful-";
                }
            }
            if (Class == "Wizard"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = "Chaotic-";
                }
                if (randNum == 2){
                    Alignment = "Neutral-";
                }
                if (randNum == 3){
                    Alignment = "Lawful-";
                }
            }

            if (Race == "Aarakocra"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Aasimar"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Animal-Hybrid"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Bugbear"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Centaur"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Dragonborn"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Dwarf"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Loxodon"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Elf"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Firbolg"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Genasi"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Gith"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Gnome"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Goblin"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Goliath"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Half-Elf"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Half-Orc"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Halfling"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Hobgoblin"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Human"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Kenku"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
            }
            if (Race == "Kobold"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Lizardfolk"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Minotaur"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Orc"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Yuan-Ti"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Tabaxi"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Tiefling"){
                int randNum = 1 + rand() % 2;
                if (randNum == 1){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Evil";
                }
            }
            if (Race == "Triton"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Tortle"){
                int randNum = 1 + rand() % 1;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
            }
            if (Race == "Vedalken"){
                int randNum = 1 + rand() % 3;
                if (randNum == 1){
                    Alignment = Alignment + "Good";
                }
                if (randNum == 2){
                    Alignment = Alignment + "Neutral";
                }
                if (randNum == 3){
                    Alignment = Alignment + "Evil";
                }
            }
        }
        else if (userOption == 'N'){
            cout << "Enter Alignment or Help for list of Alignments" << endl;
            cin >> Alignment;
            while (Alignment == "Help"){
                cout << "The available Alignments are: Lawful-Good, Neutral-Good, Chaotic-Good, Lawful-Neutral, True-Neutral, Chaotic-Neutral, Lawful-Evil, Neutral-Evil, Chaotic-Evil" << endl;
                cin >> Alignment;
            }
            while ((Alignment != "Lawful-Good") && (Alignment != "Neutral-Good") && (Alignment != "Chaotic-Good") && (Alignment != "Lawful-Neutral") && (Alignment != "True-Neutral") && (Alignment != "Chaotic-Neutral") && (Alignment != "Lawful-Evil") && (Alignment != "Neutral-Evil") && (Alignment != "Chaotic-Evil") && (Alignment != "Help")){
                cout << "Sorry, that is not an available Alignment, Please check Spelling and Letter case. Remember the first letter of each word must be Capitalized" << endl;
                cin >> Alignment;
            }
        }
    }
    if (Alignment == "Neutral Neutral"){
        Alignment = "True Neutral";
    }
    return Alignment;
}

int LevelRandomizer(){
	cout << "Randomize Level?" << endl
			 << "enter Y or N (Capital Letters)" << endl;
		cin >> userOption;
		if (userOption == 'Y'){
			//20 random classes
			Level = 1 + rand() % 20;
		}
		else if (userOption == 'N'){
			cout << "Enter Level" << endl;
			cin >> Level;
			while (Level > 20){
				cout << "Level is too high. Please choose a level between 1 and 20." << endl;
				cin >> Level;
			}
			while (Level < 1){
				cout << "Level is too low. Please choose a level between 1 and 20." << endl;
				cin >> Level;
			}
		}
		return Level;
}

void StatRandomizer(unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha){
    cout << "Randomize Stats?" << endl
    << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if (userOption == 'Y'){
		Str = 9 + rand() % 10;
		Dex = 9 + rand() % 10;
		Con = 9 + rand() % 10;
		Int = 9 + rand() % 10;
		Wis = 9 + rand() % 10;
		Cha = 9 + rand() % 10;
    }
    else if (userOption == 'N'){
        cout << "Enter Strength stat (No higher than 18)" << endl;
        cin >> Str;
        while (Str > 18){
            cout << "Enter Strength stat (No higher than 18)" << endl;
            cin >> Str;
        }
        cout << "Enter Dexterity stat (No higher than 18)" << endl;
        cin >> Dex;
        while (Dex > 18){
            cout << "Enter Dexterity stat (No higher than 18)" << endl;
            cin >> Dex;
        }
        cout << "Enter Constitution stat (No higher than 18)" << endl;
        cin >> Con;
        while (Con > 18){
            cout << "Enter Constitution stat (No higher than 18)" << endl;
            cin >> Con;
        }
        cout << "Enter Intelligence stat (No higher than 18)" << endl;
        cin >> Int;
        while (Int > 18){
            cout << "Enter Intelligence stat (No higher than 18)" << endl;
            cin >> Int;
        }
        cout << "Enter Wisdom stat (No higher than 18)" << endl;
        cin >> Wis;
        while (Wis > 18){
            cout << "Enter Wisdom stat (No higher than 18)" << endl;
            cin >> Wis;
        }
        cout << "Enter Charisma stat (No higher than 18)" << endl;
        cin >> Cha;
        while (Cha > 18){
            cout << "Enter Charisma stat (No higher than 18)" << endl;
            cin >> Cha;
        }
    }
}

void SetSlots (int& LVL1slots, int& LVL2slots, int& LVL3slots, int& LVL4slots ,int& LVL5slots, int& LVL6slots, int& LVL7slots, int& LVL8slots, int& LVL9slots){
    if (Class == "Bard"){
        if(Level == 1){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 2;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
    if (Class == "Cleric"){
        if(Level == 1){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 2;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
    if (Class == "Druid"){
        if(Level == 1){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 2;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
    if (SubClass == "Eldritch Knight "){
        if(Level == 1){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
    }
    if (Class == "Paladin"){
        if(Level == 1){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
    }
    if (Class == "Ranger"){
        if(Level == 1){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
    }
    if (SubClass == "Arcane Trickster "){
        if(Level == 1){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 0;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
    }
    if (Class == "Sorcerer"){
        if(Level == 1){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 2;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
    if (Class == "Warlock"){
        if(Level == 1){
            LVL1slots = 1;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 4;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 4;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 4;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 2;
            LVL2slots = 2;
            LVL3slots = 2;
            LVL4slots = 2;
            LVL5slots = 4;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
    if (Class == "Wizard"){
        if(Level == 1){
            LVL1slots = 2;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 2){
            LVL1slots = 3;
            LVL2slots = 0;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 3){
            LVL1slots = 4;
            LVL2slots = 2;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 4){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 0;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 5){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 2;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 6){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 0;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 7){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 1;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 8){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 2;
            LVL5slots = 0;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 9){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 1;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 10){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 0;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 11){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 12){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 0;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 13){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 0;
            LVL9slots = 0;
        }
        if(Level == 14){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 15){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 16){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 0;
        }
        if(Level == 17){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 2;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 18){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 1;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 19){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 1;
            LVL8slots = 1;
            LVL9slots = 1;
        }
        if(Level == 20){
            LVL1slots = 4;
            LVL2slots = 3;
            LVL3slots = 3;
            LVL4slots = 3;
            LVL5slots = 3;
            LVL6slots = 2;
            LVL7slots = 2;
            LVL8slots = 1;
            LVL9slots = 1;
        }
    }
}

void BackgroundRandomizer(){
    cout << "Randomize Background?" << endl << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if(userOption == 'Y'){
        int randBG = 1 + rand() % 36;
        if (randBG == 1){
            Background = "Acolyte";
        }
        if (randBG == 2){
            Background = "Tribe Member";
        }
        if (randBG == 3){
            Background = "Charlatan";
        }
        if (randBG == 4){
            Background = "City Watch";
        }
        if (randBG == 5){
            Background = "Clan Crafter";
        }
        if (randBG == 6){
            Background = "Cloistered Scholar";
        }
        if (randBG == 7){
            Background = "Courtier";
        }
        if (randBG == 8){
            Background = "Criminal";
        }
        if (randBG == 9){
            Background = "Entertainer";
        }
        if (randBG == 10){
            Background = "Faction Agent";
        }
        if (randBG == 11){
            Background = "Far Traveler";
        }
        if (randBG == 12){
            Background = "Folk Hero";
        }
        if (randBG == 13){
            Background = "Guild Artisan";
        }
        if (randBG == 14){
            Background = "Guild Member - Harmony";
        }
        if (randBG == 15){
            Background = "Guild Member - Justice";
        }
        if (randBG == 16){
            Background = "Guild Member - Law";
        }
        if (randBG == 17){
            Background = "Guild Member - Mayhem";
        }
        if (randBG == 18){
            Background = "Guild Member - Mutation";
        }
        if (randBG == 19){
            Background = "Guild Member - Spycraft";
        }
        if (randBG == 20){
            Background = "Guild Member - Swarm";
        }
        if (randBG == 21){
            Background = "Guild Member - Technology";
        }
        if (randBG == 22){
            Background = "Guild Member - Wealth";
        }
        if (randBG == 23){
            Background = "Guild Member - Wild";
        }
        if (randBG == 24){
            Background = "Haunted one";
        }
        if (randBG == 25){
            Background = "Hermit";
        }
        if (randBG == 26){
            Background = "Inheritor";
        }
        if (randBG == 27){
            Background = "Knight";
        }
        if (randBG == 28){
            Background = "Mercenary Veteran";
        }
        if (randBG == 29){
            Background = "Noble";
        }
        if (randBG == 30){
            Background = "Outlander";
        }
        if (randBG == 31){
            Background = "Port City Noble";
        }
        if (randBG == 32){
            Background = "Sage";
        }
        if (randBG == 33){
            Background = "Sailor";
        }
        if (randBG == 34){
            Background = "Soldier";
        }
        if (randBG == 35){
            Background = "Urban Bounty Hunter";
        }
        if (randBG == 36){
            Background = "Urchin";
        }
    }
    else if(userOption == 'N'){
        cout << "Enter Background or Help for list of Backgrounds" << endl;
        cin.ignore();
        getline (cin, Background);
        while ((Background != "Acolyte") && (Background != "Tribe Member") && (Background != "Charlatan") && (Background != "City Watch") && (Background != "Clan Crafter") && (Background != "Cloistered Scholar") && (Background != "Courtier") && (Background != "Criminal") && (Background != "Entertainer") && (Background != "Faction Agent") && (Background != "Far Traveler") && (Background != "Folk Hero") && (Background != "Guild Artisan") && (Background != "Guild Member - Harmony") && (Background != "Guild Member - Justice") && (Background != "Guild Member - Law") && (Background != "Guild Member - Mayhem") && (Background != "Guild Member - Mutation") && (Background != "Guild Member - Spycraft") && (Background != "Guild Member - Swarm") && (Background != "Guild Member - Technology") && (Background != "Guild Member - Wealth") && (Background != "Guild Member - Wild") && (Background != "Haunted One") && (Background != "Hermit") && (Background != "Inheritor") && (Background != "Knight") && (Background != "Mercenary Veteran") && (Background != "Noble") && (Background != "Outlander") && (Background != "Port City Noble") && (Background != "Sage") && (Background != "Sailor") && (Background != "Soldier") && (Background != "Urban Bounty Hunter") && (Background != "Urchin") && (Background != "Help")){
            cout << "Sorry, that is not an available Background, please check spelling and letter case. Remember the first letter must be Capitalized" << endl;
            getline (cin, Background);
        }
        while (Background == "Help"){
            cout << "The available Backgrounds are: Acolyte, Tribe Member, Charlatan, City Watch, Clan Crafter, Cloistered Scholar, Courtier, Criminal, Entertainer, Faction Agent, Far Traveler, Folk Hero, Guild Artisan, Guild Member - Harmony, Guild Member - Justice, Guild Member - Law, Guild Member - Mayhem, Guild Member - Mutation, Guild Member - Spycraft, Guild Member - Swarm, Guild Member - Technology, Guild Member - Wealth, Guild Member - Wild, Haunted One, Hermit, Inheritor, Knight, Mercenary Veteran, Noble, Outlander, Port City Noble, Sage, Sailor, Soldier, Urban Bounty Hunter, Urchin" << endl;
            getline (cin, Background);
        }
    }
}

void setProficiencies(vector<string>& userProficiencies){
    //class proficiencies
    if (Class == "Barbarian"){
        userProficiencies.push_back ("Str");
        userProficiencies.push_back ("Con");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Medium Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Martial Weapons");
    }
    if (Class == "Bard"){
        userProficiencies.push_back ("Dex");
        userProficiencies.push_back ("Cha");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Hand Crossbows");
        userProficiencies.push_back ("Long Swords");
        userProficiencies.push_back ("Rapiers");
        userProficiencies.push_back ("Short Swords");
    }
    if (Class == "Cleric"){
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Cha");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Medium Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Simple Weapons");
    }
    if (Class == "Druid"){
        userProficiencies.push_back ("Int");
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Medium Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Clubs");
        userProficiencies.push_back ("Daggers");
        userProficiencies.push_back ("Darts");
        userProficiencies.push_back ("Javelins");
        userProficiencies.push_back ("Maces");
        userProficiencies.push_back ("Quarterstaffs");
        userProficiencies.push_back ("Scimitars");
        userProficiencies.push_back ("Sickles");
        userProficiencies.push_back ("Slings");
        userProficiencies.push_back ("Spears");
    }
    if (Class == "Fighter"){
        userProficiencies.push_back ("Str");
        userProficiencies.push_back ("Con");
        userProficiencies.push_back ("All Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Martial Weapons");
    }
    if (Class == "Monk"){
        userProficiencies.push_back ("Dex");
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Short Swords");
    }
    if (Class == "Paladin"){
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Cha");
        userProficiencies.push_back ("All Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Martial Weapons");
    }
    if (Class == "Ranger"){
        userProficiencies.push_back ("Str");
        userProficiencies.push_back ("Dex");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Medium Armor");
        userProficiencies.push_back ("Shields");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Martial Weapons");
    }
    if (Class == "Rogue"){
        userProficiencies.push_back ("Dex");
        userProficiencies.push_back ("Int");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Simple Weapons");
        userProficiencies.push_back ("Hand Crossbows");
        userProficiencies.push_back ("Long Swords");
        userProficiencies.push_back ("Rapiers");
        userProficiencies.push_back ("Short Swords");
    }
    if (Class == "Sorcerer"){
        userProficiencies.push_back ("Cha");
        userProficiencies.push_back ("Con");
        userProficiencies.push_back ("Daggers");
        userProficiencies.push_back ("Darts");
        userProficiencies.push_back ("Slings");
        userProficiencies.push_back ("Quarterstaffs");
        userProficiencies.push_back ("Light Crossbows");
    }
    if (Class == "Warlock"){
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Cha");
        userProficiencies.push_back ("Light Armor");
        userProficiencies.push_back ("Simple Weapons");
    }
    if (Class == "Wizard"){
        userProficiencies.push_back ("Int");
        userProficiencies.push_back ("Wis");
        userProficiencies.push_back ("Daggers");
        userProficiencies.push_back ("Darts");
        userProficiencies.push_back ("Slings");
        userProficiencies.push_back ("Quarterstaffs");
        userProficiencies.push_back ("Light Crossbows");
    }
    //background proficiencies
    int randNum;
    if (Background == "Acolyte"){
        userProficiencies.push_back ("Insight");
        userProficiencies.push_back ("Religion");
    }
    if (Background == "Tribe Member"){
        userProficiencies.push_back ("Strength");
        userProficiencies.push_back ("Survival");
        randNum = 1 + rand() % 18;
        if (randNum == 1){
            userProficiencies.push_back ("Alchemist Supplies");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Brewer's Supplies");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Calligrafer's Supplies");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Carpenter's Tools");
        }
        if (randNum == 5){
            userProficiencies.push_back ("Cartographer's Tools");
        }
        if (randNum == 6){
            userProficiencies.push_back ("Cobbler's Tools");
        }
        if (randNum == 7){
            userProficiencies.push_back ("Cook's Utensils");
        }
        if (randNum == 8){
            userProficiencies.push_back ("Glassblower's Tools");
        }
        if (randNum == 9){
            userProficiencies.push_back ("Jeweler's Tools");
        }
        if (randNum == 10){
            userProficiencies.push_back ("Leatherworker's Tools");
        }
        if (randNum == 11){
            userProficiencies.push_back ("Mason's Tools");
        }
        if (randNum == 12){
            userProficiencies.push_back ("Painter's Supplies");
        }
        if (randNum == 13){
            userProficiencies.push_back ("Potter's Tools");
        }
        if (randNum == 14){
            userProficiencies.push_back ("Smith's Tools");
        }
        if (randNum == 15){
            userProficiencies.push_back ("Tinker's Tools");
        }
        if (randNum == 16){
            userProficiencies.push_back ("Weaver's Tools");
        }
        if (randNum == 17){
            userProficiencies.push_back ("Woodcarver's Tools");
        }
        if (randNum == 18){
            userProficiencies.push_back ("Instrument");
        }
    }
    if (Background == "Charlatan"){
        userProficiencies.push_back ("Deception");
        userProficiencies.push_back ("Sleight of Hand");
        userProficiencies.push_back ("Disguise Kit");
        userProficiencies.push_back ("Forgery Kit");
    }
    if (Background == "City Watch"){
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Insight");
    }
    if (Background == "Clan Crafter"){
        userProficiencies.push_back ("History");
        userProficiencies.push_back ("Insight");
        randNum = 1 + rand() % 17;
        if (randNum == 1){
            userProficiencies.push_back ("Alchemist Supplies");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Brewer's Supplies");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Calligrafer's Supplies");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Carpenter's Tools");
        }
        if (randNum == 5){
            userProficiencies.push_back ("Cartographer's Tools");
        }
        if (randNum == 6){
            userProficiencies.push_back ("Cobbler's Tools");
        }
        if (randNum == 7){
            userProficiencies.push_back ("Cook's Utensils");
        }
        if (randNum == 8){
            userProficiencies.push_back ("Glassblower's Tools");
        }
        if (randNum == 9){
            userProficiencies.push_back ("Jeweler's Tools");
        }
        if (randNum == 10){
            userProficiencies.push_back ("Leatherworker's Tools");
        }
        if (randNum == 11){
            userProficiencies.push_back ("Mason's Tools");
        }
        if (randNum == 12){
            userProficiencies.push_back ("Painter's Supplies");
        }
        if (randNum == 13){
            userProficiencies.push_back ("Potter's Tools");
        }
        if (randNum == 14){
            userProficiencies.push_back ("Smith's Tools");
        }
        if (randNum == 15){
            userProficiencies.push_back ("Tinker's Tools");
        }
        if (randNum == 16){
            userProficiencies.push_back ("Weaver's Tools");
        }
        if (randNum == 17){
            userProficiencies.push_back ("Woodcarver's Tools");
        }
    }
    if (Background == "Cloistered Scholar"){
        userProficiencies.push_back ("History");
        randNum = 1 + rand() % 3;
        if (randNum == 1){
            userProficiencies.push_back ("Arcana");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Nature");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Religion");
        }
    }
    if (Background == "Courtier"){
        userProficiencies.push_back ("Insight");
        userProficiencies.push_back ("Perception");
    }
    if (Background == "Criminal"){
        userProficiencies.push_back ("Deception");
        userProficiencies.push_back ("Stealth");
        userProficiencies.push_back ("Gaming Set");
        userProficiencies.push_back ("Thieves Tools");
    }
    if (Background == "Entertainer"){
        userProficiencies.push_back ("Acrobatics");
        userProficiencies.push_back ("Performance");
        userProficiencies.push_back ("Disguise Kit");
        userProficiencies.push_back ("Instrument");
    }
    if (Background == "Faction Agent"){
        userProficiencies.push_back ("Insight");
        randNum = 1 + rand() % 14;
        if (randNum == 1){
            userProficiencies.push_back ("Arcana");
        }
        if (randNum == 2){
            userProficiencies.push_back ("History");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Investigation");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Nature");
        }
        if (randNum == 5){
            userProficiencies.push_back ("Religion");
        }
        if (randNum == 6){
            userProficiencies.push_back ("Animal Handling");
        }
        if (randNum == 7){
            userProficiencies.push_back ("Insight");
        }
        if (randNum == 8){
            userProficiencies.push_back ("Medicine");
        }
        if (randNum == 9){
            userProficiencies.push_back ("Perception");
        }
        if (randNum == 10){
            userProficiencies.push_back ("Survival");
        }
        if (randNum == 11){
            userProficiencies.push_back ("Deception");
        }
        if (randNum == 12){
            userProficiencies.push_back ("Intimidation");
        }
        if (randNum == 13){
            userProficiencies.push_back ("Performance");
        }
        if (randNum == 14){
            userProficiencies.push_back ("Persuasion");
        }
    }
    if (Background == "Far Traveler"){
        userProficiencies.push_back ("Insight");
        userProficiencies.push_back ("Perception");
        randNum = 1 + rand() % 2;
        if (randNum == 1){
            userProficiencies.push_back ("Instrument");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Gaming Set");
        }
    }
    if (Background == "Folk Hero"){
        userProficiencies.push_back ("Animal Handling");
        userProficiencies.push_back ("Survival");
        userProficiencies.push_back ("Land Vehicles");
        randNum = 1 + rand() % 17;
        if (randNum == 1){
            userProficiencies.push_back ("Alchemist Supplies");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Brewer's Supplies");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Calligrafer's Supplies");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Carpenter's Tools");
        }
        if (randNum == 5){
            userProficiencies.push_back ("Cartographer's Tools");
        }
        if (randNum == 6){
            userProficiencies.push_back ("Cobbler's Tools");
        }
        if (randNum == 7){
            userProficiencies.push_back ("Cook's Utensils");
        }
        if (randNum == 8){
            userProficiencies.push_back ("Glassblower's Tools");
        }
        if (randNum == 9){
            userProficiencies.push_back ("Jeweler's Tools");
        }
        if (randNum == 10){
            userProficiencies.push_back ("Leatherworker's Tools");
        }
        if (randNum == 11){
            userProficiencies.push_back ("Mason's Tools");
        }
        if (randNum == 12){
            userProficiencies.push_back ("Painter's Supplies");
        }
        if (randNum == 13){
            userProficiencies.push_back ("Potter's Tools");
        }
        if (randNum == 14){
            userProficiencies.push_back ("Smith's Tools");
        }
        if (randNum == 15){
            userProficiencies.push_back ("Tinker's Tools");
        }
        if (randNum == 16){
            userProficiencies.push_back ("Weaver's Tools");
        }
        if (randNum == 17){
            userProficiencies.push_back ("Woodcarver's Tools");
        }

    }
    if (Background == "Guild Artisan"){
        userProficiencies.push_back ("Insight");
        userProficiencies.push_back ("Persuasion");
        randNum = 1 + rand() % 17;
        if (randNum == 1){
            userProficiencies.push_back ("Alchemist Supplies");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Brewer's Supplies");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Calligrafer's Supplies");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Carpenter's Tools");
        }
        if (randNum == 5){
            userProficiencies.push_back ("Cartographer's Tools");
        }
        if (randNum == 6){
            userProficiencies.push_back ("Cobbler's Tools");
        }
        if (randNum == 7){
            userProficiencies.push_back ("Cook's Utensils");
        }
        if (randNum == 8){
            userProficiencies.push_back ("Glassblower's Tools");
        }
        if (randNum == 9){
            userProficiencies.push_back ("Jeweler's Tools");
        }
        if (randNum == 10){
            userProficiencies.push_back ("Leatherworker's Tools");
        }
        if (randNum == 11){
            userProficiencies.push_back ("Mason's Tools");
        }
        if (randNum == 12){
            userProficiencies.push_back ("Painter's Supplies");
        }
        if (randNum == 13){
            userProficiencies.push_back ("Potter's Tools");
        }
        if (randNum == 14){
            userProficiencies.push_back ("Smith's Tools");
        }
        if (randNum == 15){
            userProficiencies.push_back ("Tinker's Tools");
        }
        if (randNum == 16){
            userProficiencies.push_back ("Weaver's Tools");
        }
        if (randNum == 17){
            userProficiencies.push_back ("Woodcarver's Tools");
        }
    }
    if (Background == "Guild Member - Harmony"){ //Selesnya Conclave
        userProficiencies.push_back ("Nature");
        userProficiencies.push_back ("Persuasion");
    }
    if (Background == "Guild Member - Justice"){ //Boros Legion
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Intimidation");
    }
    if (Background == "Guild Member - Law"){ //Azoruis Senate
        userProficiencies.push_back ("Insight");
        userProficiencies.push_back ("Intimidation");
    }
    if (Background == "Guild Member - Mayhem"){ //Cult of Rakdos
        userProficiencies.push_back ("Acrobatics");
        userProficiencies.push_back ("Performance");
    }
    if (Background == "Guild Member - Mutation"){ //Simic Combine
        userProficiencies.push_back ("Arcana");
        userProficiencies.push_back ("Medicine");
    }
    if (Background == "Guild Member - Spycraft"){ //House Dimir
        userProficiencies.push_back ("Deception");
        userProficiencies.push_back ("Stealth");
    }
    if (Background == "Guild Member - Swarm"){ //Golgari Swarm
        userProficiencies.push_back ("Nature");
        userProficiencies.push_back ("Survival");
    }
    if (Background == "Guild Member - Technology"){ //Izzet League
        userProficiencies.push_back ("Arcana");
        userProficiencies.push_back ("Investigation");
    }
    if (Background == "Guild Member - Wealth"){ //Orzhov Syndicate
        userProficiencies.push_back ("Intimidation");
        userProficiencies.push_back ("Religion");
    }
    if (Background == "Guild Member - Wild"){ //Gruul Clan
        userProficiencies.push_back ("Animal Handling");
        userProficiencies.push_back ("Athletics");
    }
    if (Background == "Haunted One"){
        vector<string> HavailableProficiencies;
        HavailableProficiencies.push_back ("Arcana");
        HavailableProficiencies.push_back ("Investigation");
        HavailableProficiencies.push_back ("Religion");
        HavailableProficiencies.push_back ("Survival");
        for (unsigned int i = 0; i <= 2; ++i){
            int randProf = 1 + rand() % 4;
            while (HavailableProficiencies.at(randProf) == "Taken"){
                randProf = 1 + rand() % 4;
            }
            userProficiencies.push_back (HavailableProficiencies.at(randProf));
            HavailableProficiencies.at(randProf) = "Taken";
            }
    }
    if (Background == "Hermit"){
        userProficiencies.push_back ("Medicine");
        userProficiencies.push_back ("Religion");
        userProficiencies.push_back ("Herbalism Kit");
    }
    if (Background == "Inheritor"){
        userProficiencies.push_back ("Survival");
        randNum = 1 + rand() % 3;
        if (randNum == 1){
            userProficiencies.push_back ("Arcana");
        }
        if (randNum == 2){
            userProficiencies.push_back ("History");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Religion");
        }
        userProficiencies.push_back ("Gaming Set");
        userProficiencies.push_back ("Instrument");
    }
    if (Background == "Knight"){
        userProficiencies.push_back ("Persuasion");
        randNum = 1 + rand() % 4;
        if (randNum == 1){
            userProficiencies.push_back ("Arcana");
        }
        if (randNum == 2){
            userProficiencies.push_back ("History");
        }
        if (randNum == 3){
            userProficiencies.push_back ("Nature");
        }
        if (randNum == 4){
            userProficiencies.push_back ("Religion");
        }
        randNum = 1 + rand() % 2;
        if (randNum ==  1){
            userProficiencies.push_back ("Gaming Set");
        }
        if (randNum ==  2){
            userProficiencies.push_back ("Instrument");
        }
    }
    if (Background == "Mercenary Veteran"){
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Persuasion");
        userProficiencies.push_back ("Gaming Set");
        userProficiencies.push_back ("Land Vehicles");
    }
    if (Background == "Noble"){
        userProficiencies.push_back ("History");
        userProficiencies.push_back ("Persuasion");
        userProficiencies.push_back ("Gaming Set");
    }
    if (Background == "Outlander"){
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Persuasion");
        userProficiencies.push_back ("Musical Instrument");
    }
    if (Background == "Port City Noble"){
        userProficiencies.push_back ("History");
        userProficiencies.push_back ("Persuasion");
        randNum = 1 + rand() % 2;
        if (randNum == 1){
            userProficiencies.push_back ("Gaming Set");
        }
        if (randNum == 2){
            userProficiencies.push_back ("Instrument");
        }
    }
    if (Background == "Sage"){
        userProficiencies.push_back ("Arcana");
        userProficiencies.push_back ("History");
    }
    if (Background == "Sailor"){
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Perception");
        userProficiencies.push_back ("Navigation Tools");
        userProficiencies.push_back ("Water Vehicles");
    }
    if (Background == "Soldier"){
        userProficiencies.push_back ("Athletics");
        userProficiencies.push_back ("Intimidation");
        userProficiencies.push_back ("Gaming Set");
        userProficiencies.push_back ("Land Vehicles");
    }
    if (Background == "Urban Bounty Hunter"){
        vector<string> UavailableProficiencies;
        UavailableProficiencies.push_back ("Deception");
        UavailableProficiencies.push_back ("Insight");
        UavailableProficiencies.push_back ("Persuasion");
        UavailableProficiencies.push_back ("Stealth");
        for (unsigned int i = 0; i <= 2; ++i){
            int randProf = 1 + rand() % 4;
            while (UavailableProficiencies.at(randProf) == "Taken"){
                randProf = 1 + rand() % 4;
            }
            userProficiencies.push_back (UavailableProficiencies.at(randProf));
            UavailableProficiencies.at(randProf) = "Taken";
        }
        vector<string> availableTools;
        availableTools.push_back ("Gaming Set");
        availableTools.push_back ("Instrument");
        availableTools.push_back ("Thief's Tools");
        for (unsigned int i = 0; i <= 2; ++i){
            int randProf = 1 + rand() % 3;
            while (availableTools.at(randProf) == "Taken"){
                randProf = 1 + rand() % 3;
            }
            userProficiencies.push_back (availableTools.at(randProf));
            availableTools.at(randProf) = "Taken";
        }
    }
    if (Background == "Urchin"){
        userProficiencies.push_back ("Sleight of Hand");
        userProficiencies.push_back ("Stealth");
        userProficiencies.push_back ("Disguise Kit");
        userProficiencies.push_back ("Thief's Tools");
    }

}

void RacialBonusAndSubRace(string& Race, unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha){
	int randSubRace;
	if (Race == "Aasimar"){
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Fallen Aasimar";
				Str = Str + 1;
				Cha = Cha + 2;
			}
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Protector Aasimar";
				Wis = Wis + 1;
				Cha = Cha + 2;
			}
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Fallen Aasimar";
				Con = Con + 1;
				Cha = Cha + 2;
			}
		}

		if (Race == "Animal-Hybrid"){
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Avian Animal-Hybrid";
			}
			else if (randSubRace == 2){
				Race = "Mammal Animal-Hybrid";
			}
			else if (randSubRace == 3){
				Race = "Aquatic Animal-Hybrid";
			}
			Con = Con + 2;
			Cha = Cha + 1;
			}
		if (Race == "Bugbear"){
			Str = Str + 2;
			Dex = Dex + 1;
		}
		if (Race == "Centaur"){
			Str = Str + 2;
			Wis = Wis + 1;
		}
		if (Race == "Dragonborn"){
			randSubRace = 1 + rand() % 10;
			if (randSubRace == 1){
				Race = "Black Dragonborn";
			}
			if (randSubRace == 2){
				Race = "Blue Dragonborn";
			}
			if (randSubRace == 3){
				Race = "Brass Dragonborn";
			}
			if (randSubRace == 4){
				Race = "Bronze Dragonborn";
			}
			if (randSubRace == 5){
				Race = "Copper Dragonborn";
			}
			if (randSubRace == 6){
				Race = "Gold Dragonborn";
			}
			if (randSubRace == 7){
				Race = "Green Dragonborn";
			}
			if (randSubRace == 8){
				Race = "Red Dragonborn";
			}
			if (randSubRace == 9){
				Race = "Silver Dragonborn";
			}
			if (randSubRace == 10){
				Race = "White Dragonborn";
			}
			Str = Str + 2;
			Cha = Cha + 1;
		}
		if (Race == "Dwarf"){
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Gray Dwarf";
				Str = Str + 1;
				Con = Con + 2;
			}
			if (randSubRace == 2){
				Race = "Hill Dwarf";
				Wis = Wis + 1;
				Con = Con + 2;
			}
			if (randSubRace == 3){
				Race = "Mountain Dwarf";
				Str = Str + 3;
				Con = Con + 2;
			}
		}
		if (Race == "Loxodon"){
			Wis = Wis + 1;
			Con = Con + 2;
		}
		if (Race == "Elf"){
			randSubRace = 1 + rand() % 5;
			if (randSubRace == 1){
				Race = "Dark Elf";
				Dex = Dex + 2;
				Cha = Cha + 1;
			}
			if (randSubRace == 2){
				Race = "High Elf";
				Dex = Dex + 2;
				Int = Int + 1;
			}
			if (randSubRace == 3){
				Race = "Sea Elf";
				Dex = Dex + 2;
				Con = Con + 1;
			}
			if (randSubRace == 4){
				Race = "Shadow Elf";
				Dex = Dex + 2;
				Con = Con + 1;
			}
			if (randSubRace == 5){
				Race = "Wood Elf";
				Dex = Dex + 2;
				Wis = Wis + 1;
			}
		}
		if (Race == "Firbolg"){
			Wis = Wis + 2;
			Str = Str + 1;
		}
		if (Race == "Genasi"){
			randSubRace = 1 + rand() % 4;
			if (randSubRace == 1){
				Race = "Air Genasi";
				Dex = Dex + 1;
				Con = Con + 2;
			}
			if (randSubRace == 2){
				Race = "Earth Genasi";
				Str = Str + 1;
				Con = Con + 2;
			}
			if (randSubRace == 3){
				Race = "Fire Genasi";
				Int = Int + 1;
				Con = Con + 2;
			}
			if (randSubRace == 4){
				Race = "Water Genasi";
				Wis = Wis + 1;
				Con = Con + 2;
			}
		}
		if (Race == "Gith"){
			randSubRace = 1 + rand() % 2;
			if (randSubRace == 1){
				Race = "Githyanki";
				Str = Str + 2;
				Int = Int + 1;
			}
			if (randSubRace == 2){
				Race = "Githzerai";
				Wis = Wis + 2;
				Int = Int + 1;
			}
		}
		if (Race == "Gnome"){
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Deep Gnome";
				Dex = Dex + 1;
				Int = Int + 2;
			}
			if (randSubRace == 2){
				Race = "Forest Gnome";
				Dex = Dex + 1;
				Int = Int + 2;
			}
			if (randSubRace == 3){
				Race = "Rock Gnome";
				Con = Con + 1;
				Int = Int + 2;
			}
		}
		if (Race == "Goblin"){
			Con = Con + 1;
			Dex = Dex + 2;
		}
		if (Race == "Goliath"){
			Str = Str + 2;
			Con = Con + 1;
		}
		if (Race == "Half-Elf"){
			Cha = Cha + 2;
			Dex = Dex + 1;
			Con = Con + 1;
		}
		if (Race == "Half-Orc"){
			Con = Con + 1;
			Str = Str + 2;
		}
		if (Race == "Halfling"){
			randSubRace = 1 + rand() % 3;
			if (randSubRace == 1){
				Race = "Ghastly Halfling";
				Dex = Dex + 2;
				Wis = Wis + 1;
			}
			if (randSubRace == 2){
				Race = "Lightfoot Halfling";
				Dex = Dex + 2;
				Cha = Cha + 1;
			}
			if (randSubRace == 3){
				Race = "Stout Halfling";
				Dex = Dex + 2;
				Con = Con + 1;
			}
		}
		if (Race == "Hobgoblin"){
			Con = Con + 2;
			Int = Int + 1;
		}
		if (Race == "Human"){
			Str = Str + 1;
			Dex = Dex + 1;
			Con = Con + 1;
			Int = Int + 1;
			Wis = Wis + 1;
			Cha = Cha + 1;
		}
		if (Race == "Kenku"){
			Dex = Dex + 2;
			Wis = Wis + 1;
		}
		if (Race == "Kobold"){
			Str = Str - 2;
			Dex = Dex + 2;
		}
		if (Race == "Lizardfolk"){
			Con = Con + 2;
			Wis = Wis + 1;
		}
		if (Race == "Minotaur"){
			Str = Str + 2;
			Con = Con + 1;
		}
		if (Race == "Orc"){
			Con = Con + 1;
			Str = Str + 2;
			Int = Int - 2;
		}
		if (Race == "Yuan-Ti"){
			Int = Int + 1;
			Cha = Cha + 2;
		}
		if (Race == "Tabaxi"){
			Dex = Dex + 2;
			Cha = Cha + 1;
		}
		if (Race == "Tiefling"){
			randSubRace = 1 + rand() % 12;
			if (randSubRace == 1){
				Race = "Tiefling";
				Int = Int + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 2){
				randSubRace = 1 + rand() % 3;
				if (randSubRace == 1){
					Race = "Feral Tielfing";
				}
				if (randSubRace == 2){
					Race = "Enchanting Tielfing";
				}
				if (randSubRace == 3){
					Race = "Burning Tielfing";
				}
				Int = Int + 1;
				Dex = Dex + 2;
			}
			if (randSubRace == 3){
				Race = "Winged Tiefling";
				Int = Int + 1;
				Dex = Dex + 2;
			}
			if (randSubRace == 4){
				Race = "Baal Tiefling";
				Int = Int + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 5){
				Race = "Disp Tiefling";
				Dex = Dex + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 6){
				Race = "Fier Tiefling";
				Wis = Wis + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 7){
				Race = "Glas Tiefling";
				Dex = Dex + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 8){
				Race = "Levi Tiefling";
				Con = Con + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 9){
				Race = "Mamm Tiefling";
				Int = Int + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 10){
				Race = "Meph Tiefling";
				Int = Int + 1;
				Cha = Cha + 2;
			}
			if (randSubRace == 11){
				Race = "Zari Tiefling";
				Str = Str + 1;
				Cha = Cha + 2;
			}
		}
		if (Race == "Triton"){
			Str = Str + 1;
			Con = Con + 1;
			Cha = Cha + 1;
		}
		if (Race == "Turtle"){
			Str = Str + 2;
			Wis = Wis + 1;
		}
		if (Race == "Vedalken"){
			Wis = Wis + 1;
			Int = Int + 2;
		}
}

void SubClassRandomizer(const string Class, const int Level, string& SubClass, string& FightingStyle, bool& subclass, bool& fightingstyle){
	int randSubClass;
		if ((Class == "Barbarian") && (Level >= 3)){
			randSubClass = 1 + rand() % 7;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Ancestral Guardian ";
				}
			if (randSubClass == 2){
				SubClass = "Battlerager ";
			}
			if (randSubClass == 3){
				SubClass = "Berserker ";
			}
			if (randSubClass == 4){
				SubClass = "Storm Herald ";
			}
			if (randSubClass == 5){
				SubClass = "Totem ";
			}
			if (randSubClass == 6){
				SubClass = "Zealot ";
			}
			if (randSubClass == 7){
				SubClass = "Skald ";
			}
		}
		if ((Class == "Bard") && (Level >= 3)){
			randSubClass = 1 + rand() % 5;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Glamour ";
			}
			if (randSubClass == 2){
				SubClass = "Lore ";
			}
			if (randSubClass == 3){
				SubClass = "Swords ";
			}
			if (randSubClass == 4){
				SubClass = "Valor ";
			}
			if (randSubClass == 5){
				SubClass = "Whispers ";
			}
		}
		if (Class == "Cleric"){
			randSubClass = 1 + rand() % 12;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Arcana ";
			}
			if (randSubClass == 2){
				SubClass = "Death ";
			}
			if (randSubClass == 3){
				SubClass = "Forge ";
			}
			if (randSubClass == 4){
				SubClass = "Grave ";
			}
			if (randSubClass == 5){
				SubClass = "Knowledge ";
			}
			if (randSubClass == 6){
				SubClass = "Life ";
			}
			if (randSubClass == 7){
				SubClass = "Light ";
			}
			if (randSubClass == 8){
				SubClass = "Nature ";
			}
			if (randSubClass == 9){
				SubClass = "Order ";
			}
			if (randSubClass == 10){
				SubClass = "Tempest ";
			}
			if (randSubClass == 11){
				SubClass = "Trickery ";
			}
			if (randSubClass == 12){
				SubClass = "War ";
			}
		}
		if ((Class == "Druid") && (Level >= 2)){
			randSubClass = 1 + rand() % 5;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Dreams ";
			}
			if (randSubClass == 2){
				SubClass = "Land ";
			}
			if (randSubClass == 3){
				SubClass = "Moon ";
			}
			if (randSubClass == 4){
				SubClass = "Shepherd ";
			}
			if (randSubClass == 5){
				SubClass = "Spores ";
			}
		}
		if (Class == "Fighter"){
			randSubClass = 1 + rand() % 7;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Arcane Archer ";
			}
			if (randSubClass == 2){
				SubClass = "Battle Master ";
			}
			if (randSubClass == 3){
				SubClass = "Cavalier ";
			}
			if (randSubClass == 4){
				SubClass = "Champion ";
			}
			if (randSubClass == 5){
				SubClass = "Eldritch Knight ";
			}
			if (randSubClass == 6){
				SubClass = "Knight ";
			}
			if (randSubClass == 7){
				SubClass = "Samurai ";
			}
		}
			//Fighter Fighting Style
	if ((Class.find ("Fighter") != string::npos) && (Level >= 1)){
		int randFightingStyle;
		randFightingStyle = 1 + rand() % 6;
		fightingstyle = true;
			if (randFightingStyle == 1){
				FightingStyle = "Archery ";
			}
			if (randFightingStyle == 2){
				FightingStyle = "Defence ";
			}
			if (randFightingStyle == 3){
				FightingStyle = "Dueling ";
			}
			if (randFightingStyle == 4){
				FightingStyle = "Great Weapon Fighting ";
			}
			if (randFightingStyle == 5){
				FightingStyle = "Protection ";
			}
			if (randFightingStyle == 6){
				FightingStyle = "Two-Weapon Fighting ";
			}
		}
		if ((Class == "Monk") && (Level >= 3)){
			randSubClass = 1 + rand() % 7;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Death ";
			}
			if (randSubClass == 2){
				SubClass = "Drunken Master ";
			}
			if (randSubClass == 3){
				SubClass = "Elements ";
			}
			if (randSubClass == 4){
				SubClass = "Open Hand ";
			}
			if (randSubClass == 5){
				SubClass = "Kensei ";
			}
			if (randSubClass == 6){
				SubClass = "Sun Soul ";
			}
			if (randSubClass == 7){
				SubClass = "Shadow ";
			}
		}
		if ((Class == "Paladin") && (Level >= 3)){
			randSubClass = 1 + rand() % 7;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Ancient Oath ";
			}
			if (randSubClass == 2){
				SubClass = "Conquest Oath ";
			}
			if (randSubClass == 3){
				SubClass = "Crown Oath ";
			}
			if (randSubClass == 4){
				SubClass = "Devotion Oath ";
			}
			if (randSubClass == 5){
				SubClass = "Oath Breaker ";
			}
			if (randSubClass == 6){
				SubClass = "Redemption ";
			}
			if (randSubClass == 7){
				SubClass = "Vengeance ";
			}
		}
			//Paladin Fighting Style
	if ((Class.find ("Paladin") != string::npos) && (Level >= 2)){
		int randFightingStyle;
		randFightingStyle = 1 + rand() % 4;
		fightingstyle = true;
			if (randFightingStyle == 1){
				FightingStyle = "Defence ";
			}
			if (randFightingStyle == 2){
				FightingStyle = "Dueling ";
			}
			if (randFightingStyle == 3){
				FightingStyle = "Great Weapon Fighting ";
			}
			if (randFightingStyle == 4){
				FightingStyle = "Protection ";
			}
		}
		if ((Class == "Ranger") && (Level >= 3)){
			randSubClass = 1 + rand() % 5;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Beast Master ";
			}
			if (randSubClass == 2){
				SubClass = "Gloom ";
			}
			if (randSubClass == 3){
				SubClass = "Horizon ";
			}
			if (randSubClass == 4){
				SubClass = "Hunter ";
			}
			if (randSubClass == 5){
				SubClass = "Monster Slayer ";
			}
		}
			//Ranger Fighting Style
	if ((Class.find ("Ranger") != string::npos) && (Level >= 2)){
		int randFightingStyle;
		randFightingStyle = 1 + rand() % 6;
		fightingstyle = true;
			if (randFightingStyle == 1){
				FightingStyle = "Archery ";
			}
			if (randFightingStyle == 2){
				FightingStyle = "Defence ";
			}
			if (randFightingStyle == 3){
				FightingStyle = "Dueling ";
			}
			if (randFightingStyle == 6){
				FightingStyle = "Two-Weapon Fighting ";
			}
		}
		if ((Class == "Rogue") && (Level >= 3)){
			randSubClass = 1 + rand() % 7;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Arcane Trickster ";
			}
			if (randSubClass == 2){
				SubClass = "Assassin ";
			}
			if (randSubClass == 3){
				SubClass = "Inquisitive ";
			}
			if (randSubClass == 4){
				SubClass = "Mastermind ";
			}
			if (randSubClass == 5){
				SubClass = "Scout ";
			}
			if (randSubClass == 6){
				SubClass = "Swashbuckler ";
			}
			if (randSubClass == 7){
				SubClass ="Thief ";
			}
		}
		if (Class == "Sorcerer"){
			randSubClass = 1 + rand() % 5;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Divine ";
			}
			if (randSubClass == 2){
				SubClass = "Draconic ";
			}
			if (randSubClass == 3){
				SubClass = "Shadow ";
			}
			if (randSubClass == 4){
				SubClass = "Storm ";
			}
			if (randSubClass == 5){
				SubClass = "Wild Magic ";
			}
		}
		if (Class == "Warlock"){
			randSubClass = 1 + rand() % 6;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Archfey ";
			}
			if (randSubClass == 2){
				SubClass = "Celestial ";
			}
			if (randSubClass == 3){
				SubClass = "Fiend ";
			}
			if (randSubClass == 4){
				SubClass = "Hexblade ";
			}
			if (randSubClass == 5){
				SubClass = "Old One ";
			}
			if (randSubClass == 6){
				SubClass = "Undead ";
			}
		}
		if ((Class == "Wizard") && (Level >= 2)){
			randSubClass = 1 + rand() % 10;
			subclass = true;
			if (randSubClass == 1){
				SubClass = "Abjuration ";
			}
			if (randSubClass == 2){
				SubClass = "Blade ";
			}
			if (randSubClass == 3){
				SubClass = "Conjuration ";
			}
			if (randSubClass == 4){
				SubClass = "Divination ";
			}
			if (randSubClass == 5){
				SubClass = "Enchantment ";
			}
			if (randSubClass == 6){
				SubClass = "Evocation ";
			}
			if (randSubClass == 7){
				SubClass = "Illusion ";
			}
			if (randSubClass == 8){
				SubClass = "Necrancy ";
			}
			if (randSubClass == 9){
				SubClass = "Transmutation ";
			}
			if (randSubClass == 10){
				SubClass = "War ";
			}
		}
}

void IncreaseOrFeat(const int Level, unsigned int& Str, unsigned int& Dex, unsigned int& Con, unsigned int& Int, unsigned int& Wis, unsigned int& Cha, vector<string>& availableFeats, vector<string>& userFeats){
	if (Level >= 4){
	for (unsigned int i = 0; i < (Level / 4); ++i){
		int increaseOrFeat = 1 + rand() % 3;
	if (increaseOrFeat <= 2){
			int randStat1 = 1+ rand() % 6;
			if (randStat1 == 1){
				Str = Str + 2;
			}
			if (randStat1 == 2){
				Dex = Dex + 2;
			}
			if (randStat1 == 3){
				Con = Con + 2;
			}
			if (randStat1 == 4){
				Int = Int + 2;
			}
			if (randStat1 == 5){
				Wis = Wis + 2;
			}
			if (randStat1 == 6){
				Cha = Cha + 2;
			}
		int randStat2 = 1+ rand() % 5;
		//str in stat 1
		if (randStat1 == 1){
			if (randStat2 == 1){
				Dex = Dex + 2;
			}
			if (randStat2 == 2){
				Con = Con + 2;
			}
			if (randStat2 == 3){
				Int = Int + 2;
			}
			if (randStat2 == 4){
				Wis = Wis + 2;
			}
			if (randStat2 == 5){
				Cha = Cha + 2;
			}
		}
		//dex in stat 1
		if (randStat1 == 2){
			if (randStat2 == 1){
				Str = Str + 2;
			}
			if (randStat2 == 2){
				Con = Con + 2;
			}
			if (randStat2 == 3){
				Int = Int + 2;
			}
			if (randStat2 == 4){
				Wis = Wis + 2;
			}
			if (randStat2 == 5){
				Cha = Cha + 2;
			}
		}
		//con in stat 1
		if (randStat1 == 3){
			if (randStat2 == 1){
				Str = Str + 2;
			}
			if (randStat2 == 2){
				Dex = Dex + 2;
			}
			if (randStat2 == 3){
				Int = Int + 2;
			}
			if (randStat2 == 4){
				Wis = Wis + 2;
			}
			if (randStat2 == 5){
				Cha = Cha + 2;
			}
		}
		//int in stat 1
		if (randStat1 == 4){
			if (randStat2 == 1){
				Str = Str + 2;
			}
			if (randStat2 == 2){
				Dex = Dex + 2;
			}
			if (randStat2 == 3){
				Con = Con + 2;
			}
			if (randStat2 == 4){
				Wis = Wis + 2;
			}
			if (randStat2 == 5){
				Cha = Cha + 2;
			}
		}
		//wis in stat 1
		if (randStat1 == 5){
			if (randStat2 == 1){
				Str = Str + 2;
			}
			if (randStat2 == 2){
				Dex = Dex + 2;
			}
			if (randStat2 == 3){
				Con = Con + 2;
			}
			if (randStat2 == 4){
				Int = Int + 2;
			}
			if (randStat2 == 5){
				Cha = Cha + 2;
			}
		}
		//cha in stat 1
		if (randStat1 == 6){
			if (randStat2 == 1){
				Str = Str + 2;
			}
			if (randStat2 == 2){
				Dex = Dex + 2;
			}
			if (randStat2 == 3){
				Con = Con + 2;
			}
			if (randStat2 == 4){
				Int = Int + 2;
			}
			if (randStat2 == 5){
				Wis = Wis + 2;
			}
		}
	}
if (increaseOrFeat == 3){
	availableFeats.push_back ("Actor");
	availableFeats.push_back ("Athlete");
	availableFeats.push_back ("Alert");
	availableFeats.push_back ("Charger");
	availableFeats.push_back  ("Dual Wielder");
	 availableFeats.push_back ("Dungeon Delver");
	availableFeats.push_back   ("Durable");
	availableFeats.push_back  ("Great Weapon Master");
	availableFeats.push_back  ("Healer");
	availableFeats.push_back ("Keen Mind");
	availableFeats.push_back  ("Linguist");
	availableFeats.push_back  ("Lucky");
	availableFeats.push_back ("Mage Slayer");
	availableFeats.push_back ("Magic Initiate");
	availableFeats.push_back ("Martial Adept");
	availableFeats.push_back ("Mobile");
	availableFeats.push_back ("Mounted Combatant");
	availableFeats.push_back ("Observant");
	availableFeats.push_back ("Resilient");
	availableFeats.push_back ("Savage");
	availableFeats.push_back ("Attacker");
	availableFeats.push_back ("Sentinel");
	availableFeats.push_back ("Sharpshooter");
	availableFeats.push_back ("Skilled");
	availableFeats.push_back ("Tough");
	availableFeats.push_back ("Crossbow Expert");
	availableFeats.push_back ("Polearm Master");
	availableFeats.push_back ("Shield Master");
	availableFeats.push_back ("Traven Brawler");
	availableFeats.push_back ("Weapon Master");
	availableFeats.push_back ("Lightly Armored");
	if (((Int >= 1) || (Wis>=1)) && ((Class == "Bard") || (Class == "Cleric") || (Class == "Druid") || (Class == "Paladin") || (Class == "Ranger") || (Class == "Sorcerer") || (Class == "Warlock") || (Class == "Wizard") || (SubClass == "Arcane Trickster "))){
	availableFeats.push_back ("Elemental Adept");
		availableFeats.push_back ("Spell Sniper");
		availableFeats.push_back ("War Caster");
	}
	if (Dex >= 13){
		availableFeats.push_back ("Defensive Duelist");
		availableFeats.push_back ("Skulker");
	}
	if (Str >= 13){
		availableFeats.push_back ("Grappler");
	}
	if (Cha >= 13){
		availableFeats.push_back ("Inspiring Leader");
	}
	if (((Int >= 13) || (Wis>=13)) && ((Class == "Bard") || (Class == "Cleric") || (Class == "Druid") || (Class == "Paladin") || (Class == "Ranger") || (Class == "Sorcerer") || (Class == "Warlock") || (Class == "Wizard") || (SubClass == "Arcane Trickster "))){
		availableFeats.push_back ("Ritual Caster");
	}
		int randFeat = 1 + rand() % (availableFeats.size());
		while (availableFeats.at(randFeat) == "Taken"){
			randFeat = 1 + rand() % (availableFeats.size());
		}
		userFeats.push_back (availableFeats.at(randFeat));
		availableFeats.at(randFeat) = "Taken";
}
}
if (userFeats.size() <= 0){
	userFeats.push_back("None");
}
}
}

void StatModifiers(const unsigned  int Str,const unsigned int Dex,const unsigned  int Con,const unsigned  int Int,const unsigned int Wis,const unsigned  int Cha, int& strMod, int& dexMod, int& conMod, int& intMod, int& wisMod, int& chaMod){
	if ((Str == 8) || (Str == 9)){
			strMod = -1;
		}
		if ((Str == 10) || (Str == 11)){
			strMod = 0;
		}
		if ((Str == 12) || (Str == 13)){
			strMod = 1;
		}
		if ((Str == 14) || (Str == 15))
		{
			strMod = 2;
		}
		if ((Str == 16) || (Str == 17)){
			strMod = 3;
		}
		if ((Str == 18) || (Str == 19)){
			strMod = 4;
		}
		if ((Str == 20) || (Str == 21)){
			strMod = 5;
		}
		if ((Str == 22) || (Str == 23)){
			strMod = 6;
		}
		if ((Str == 24) || (Str == 25)){
			strMod = 7;
		}
		if ((Str == 26) || (Str == 27)){
			strMod = 8;
		}
		if ((Str == 28) || (Str == 29)){
			strMod = 9;
		}
		if (Str == 30){
			strMod = 10;
		}


		if ((Dex == 8) || (Dex == 9)){
			dexMod = -1;
		}
		if ((Dex == 10) || (Dex == 11)){
			dexMod = 0;
		}
		if ((Dex == 12) || (Dex == 13)){
			dexMod = 1;
		}
		if ((Dex == 14) || (Dex == 15)){
			dexMod = 2;
		}
		if ((Dex == 16) || (Dex == 17)){
			dexMod = 3;
		}
		if ((Dex == 18) || (Dex == 19)){
			dexMod = 4;
		}
		if ((Dex == 20) || (Dex == 21)){
			dexMod = 5;
		}
		if ((Dex == 22) || (Dex == 23)){
			dexMod = 6;
		}
		if ((Dex == 24) || (Dex == 25)){
			dexMod = 7;
		}
		if ((Dex == 26) || (Dex == 27)){
			dexMod = 8;
		}
		if ((Dex == 28) || (Dex == 29)){
			dexMod = 9;
		}
		if (Dex == 30){
			dexMod = 10;
		}

		if ((Con == 8) || (Con == 9)){
			conMod = -1;
		}
		if ((Con == 10) || (Con == 11)){
			conMod = 0;
		}
		if ((Con == 12) || (Con == 13)){
			conMod = 1;
		}
		if ((Con == 14) || (Con == 15)){
			conMod = 2;
		}
		if ((Con == 16) || (Con == 17)){
			conMod = 3;
		}
		if ((Con == 18) || (Con == 19)){
			conMod = 4;
		}
		if ((Con == 20) || (Con == 21)){
			conMod = 5;
		}
		if ((Con == 22) || (Con == 23)){
			conMod = 6;
		}
		if ((Con == 24) || (Con == 25)){
			conMod = 7;
		}
		if ((Con == 26) || (Con == 27)){
			conMod = 8;
		}
		if ((Con == 28) || (Con == 29)){
			conMod = 9;
		}
		if (Con == 30){
			conMod = 10;
		}

		if ((Int == 8) || (Int == 9)){
			intMod = -1;
		}
		if ((Int == 10) || (Int == 11)){
			intMod = 0;
		}
		if ((Int == 12) || (Int == 13)){
			intMod = 1;
		}
		if ((Int == 14) || (Int == 15)){
			intMod = 2;
		}
		if ((Int == 16) || (Int == 17)){
			intMod = 3;
		}
		if ((Int == 18) || (Int == 19)){
			intMod = 4;
		}
		if ((Int == 20) || (Int == 21)){
			intMod = 5;
		}
		if ((Int == 22) || (Int == 23)){
			intMod = 6;
		}
		if ((Int == 24) || (Int == 25)){
			intMod = 7;
		}
		if ((Int == 26) || (Int == 27)){
			intMod = 8;
		}
		if ((Int == 28) || (Int == 29)){
			intMod = 9;
		}
		if (Int == 30){
			intMod = 10;
		}

		if ((Wis == 8) || (Wis == 9)){
			wisMod = -1;
		}
		if ((Wis == 10) || (Wis == 11)){
			wisMod = 0;
		}
		if ((Wis == 12) || (Wis == 13)){
			wisMod = 1;
		}
		if ((Wis == 14) || (Wis == 15)){
			wisMod = 2;
		}
		if ((Wis == 16) || (Wis == 17)){
			wisMod = 3;
		}
		if ((Wis == 18) || (Wis == 19)){
			wisMod = 4;
		}
		if ((Wis == 20) || (Wis == 21)){
			wisMod = 5;
		}
		if ((Wis == 22) || (Wis == 23)){
			wisMod = 6;
		}
		if ((Wis == 24) || (Wis == 25)){
			wisMod = 7;
		}
		if ((Wis == 26) || (Wis == 27)){
			wisMod = 8;
		}
		if ((Wis == 28) || (Wis == 29)){
			wisMod = 9;
		}
		if (Wis == 30){
			wisMod = 10;
		}

		if ((Cha == 8) || (Cha == 9)){
			chaMod = -1;
		}
		if ((Cha == 10) || (Cha == 11)){
			chaMod = 0;
		}
		if ((Cha == 12) || (Cha == 13)){
			chaMod = 1;
		}
		if ((Cha == 14) || (Cha == 15)){
			chaMod = 2;
		}
		if ((Cha == 16) || (Cha == 17)){
			chaMod = 3;
		}
		if ((Cha == 18) || (Cha == 19)){
			chaMod = 4;
		}
		if ((Cha == 20) || (Cha == 21)){
			chaMod = 5;
		}
		if ((Cha == 22) || (Cha == 23)){
			chaMod = 6;
		}
		if ((Cha == 24) || (Cha == 25)){
			chaMod = 7;
		}
		if ((Cha == 26) || (Cha == 27)){
			chaMod = 8;
		}
		if ((Cha == 28) || (Cha == 29)){
			chaMod = 9;
		}
		if (Cha == 30){
			chaMod = 10;
		}
}

void SkillRandomizer(int& strMod,int& dexMod,int& conMod,int& intMod, int& wisMod, int& chaMod){
    if ((Level == 1)||(Level == 2)||(Level == 3)||(Level == 4)){
        proficiencyBonus = 2;
    }
    else if ((Level == 5)||(Level == 6)||(Level == 7)||(Level == 8)){
        proficiencyBonus = 3;
    }
    else if ((Level == 9)||(Level == 10)||(Level == 11)||(Level == 12)){
        proficiencyBonus = 4;
    }
    else if ((Level == 13)||(Level == 14)||(Level == 15)||(Level == 16)){
        proficiencyBonus = 5;
    }
    else if ((Level == 17)||(Level == 18)||(Level == 19)||(Level == 20)){
        proficiencyBonus = 6;
    }
    cout << "Randomize Skills?" << endl << "enter Y or N (Capital Letters)" << endl;
    char YNSKILLS;
    cin >> YNSKILLS;
    if (YNSKILLS == 'Y'){
        if (Class == "Barbarian"){
            int randSkill01 = 1 + rand() % 6;
            int randSkill02 = 1 + rand() % 6;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 6;
            }
            if (randSkill01 == 1){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Survival = wisMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Survival = wisMod + proficiencyBonus;
            }
        }
        if (Class == "Bard"){
            int randSkill01 = 1 + rand() % 18;
            int randSkill02 = 1 + rand() % 18;
            int randSkill03 = 1 + rand() % 18;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 18;
            }
            while ((randSkill03 == randSkill01)||(randSkill03 == randSkill02)){
                randSkill03 = 1 + rand() % 18;
            }
            if (randSkill01 == 1){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill01 == 8){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill01 == 9){
                Religion = intMod + proficiencyBonus;
            }
            if (randSkill01 == 10){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 11){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 12){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 13){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 14){
                Survival = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 15){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 16){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 17){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 18){
                Persuasion = chaMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill02 == 8){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill02 == 9){
                Religion = intMod + proficiencyBonus;
            }
            if (randSkill02 == 10){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 11){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 12){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 13){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 14){
                Survival = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 15){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 16){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 17){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 18){
                Persuasion = chaMod + proficiencyBonus;
            }

            if (randSkill03 == 1){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill03 == 2){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 3){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 4){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 5){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill03 == 6){
                History = intMod + proficiencyBonus;
            }
            if (randSkill03 == 7){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill03 == 8){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill03 == 9){
                Religion = intMod + proficiencyBonus;
            }
            if (randSkill03 == 10){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 11){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 12){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 13){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 14){
                Survival = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 15){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 16){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 17){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 18){
                Persuasion = chaMod + proficiencyBonus;
            }
        }
        if(Class == "Cleric"){
            int randSkill01 = 1 + rand() % 5;
            int randSkill02 = 1 + rand() % 5;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 5;
            }
            if (randSkill01 == 1){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Religion = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Religion = intMod + proficiencyBonus;
            }
        }
        if(Class == "Druid"){
            int randSkill01 = 1 + rand() % 8;
            int randSkill02 = 1 + rand() % 8;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 8;
            }
            if (randSkill01 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Medicine = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Religion = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 8){
                Survival = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Medicine = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Religion = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 8){
                Survival = intMod + proficiencyBonus;
            }
        }
        if (Class == "Fighter"){
            int randSkill01 = 1 + rand() % 8;
            int randSkill02 = 1 + rand() % 8;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 8;
            }
            if (randSkill01 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 8){
                Survival = wisMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 8){
                Survival = intMod + proficiencyBonus;
            }
        }
        if (Class == "Monk"){
            int randSkill01 = 1 + rand() % 6;
            int randSkill02 = 1 + rand() % 6;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 6;
            }
            if (randSkill01 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Religion = intMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Stealth = dexMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Religion = intMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Stealth = dexMod + proficiencyBonus;
            }
        }
        if (Class == "Paladin"){
            int randSkill01 = 1 + rand() % 6;
            int randSkill02 = 1 + rand() % 6;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 6;
            }
            if (randSkill01 == 1){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Religion = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Religion = intMod + proficiencyBonus;
            }
        }
        if (Class == "Ranger"){
            int randSkill01 = 1 + rand() % 8;
            int randSkill02 = 1 + rand() % 8;
            int randSkill03 = 1 + rand() % 8;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 8;
            }
            while ((randSkill03 == randSkill01)||(randSkill03 == randSkill02)){
                randSkill03 = 1 + rand() % 8;
            }
            if (randSkill01 == 1){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 8){
                Survival = wisMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 8){
                Survival = wisMod + proficiencyBonus;
            }

            if (randSkill03 == 1){
                AnimalHandling = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill03 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 4){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill03 == 5){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill03 == 6){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 7){
                Stealth = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 8){
                Survival = wisMod + proficiencyBonus;
            }
        }
        if (Class == "Rogue"){
            int randSkill01 = 1 + rand() % 11;
            int randSkill02 = 1 + rand() % 11;
            int randSkill03 = 1 + rand() % 11;
            int randSkill04 = 1 + rand() % 11;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 11;
            }
            while ((randSkill03 == randSkill01)||(randSkill03 == randSkill02)){
                randSkill03 = 1 + rand() % 11;
            }
            while ((randSkill04 == randSkill01)||(randSkill04 == randSkill02)||(randSkill04 == randSkill03)){
                randSkill04 = 1 + rand() % 11;
            }
            if (randSkill01 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 8){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 9){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 10){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill01 == 11){
                Stealth = dexMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 8){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 9){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 10){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill02 == 11){
                Stealth = dexMod + proficiencyBonus;
            }

            if (randSkill03 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill03 == 3){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 5){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 6){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill03 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill03 == 8){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 9){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill03 == 10){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill03 == 11){
                Stealth = dexMod + proficiencyBonus;
            }

            if (randSkill04 == 1){
                Acrobatics = dexMod + proficiencyBonus;
            }
            if (randSkill04 == 2){
                Athletics = strMod + proficiencyBonus;
            }
            if (randSkill04 == 3){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill04 == 4){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill04 == 5){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill04 == 6){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill04 == 7){
                Perception = wisMod + proficiencyBonus;
            }
            if (randSkill04 == 8){
                Performance = chaMod + proficiencyBonus;
            }
            if (randSkill04 == 9){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill04 == 10){
                SleightOfHand = dexMod + proficiencyBonus;
            }
            if (randSkill04 == 11){
                Stealth = dexMod + proficiencyBonus;
            }
        }
        if (Class == "Sorcerer"){
            int randSkill01 = 1 + rand() % 6;
            int randSkill02 = 1 + rand() % 6;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 6;
            }
            if (randSkill01 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Religion = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Persuasion = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Religion = intMod + proficiencyBonus;
            }
        }
        if (Class == "Warlock"){
            int randSkill01 = 1 + rand() % 7;
            int randSkill02 = 1 + rand() % 7;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 7;
            }
            if (randSkill01 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill01 == 7){
                Religion = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                Deception = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Intimidation = chaMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Nature = intMod + proficiencyBonus;
            }
            if (randSkill02 == 7){
                Religion = intMod + proficiencyBonus;
            }
        }
        if (Class == "Wizard"){
            int randSkill01 = 1 + rand() % 6;
            int randSkill02 = 1 + rand() % 6;
            while (randSkill02 == randSkill01){
                randSkill02 = 1 + rand() % 6;
            }
            if (randSkill01 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill01 == 2){
                History = intMod + proficiencyBonus;
            }
            if (randSkill01 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 4){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill01 == 5){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill01 == 6){
                Religion = intMod + proficiencyBonus;
            }

            if (randSkill02 == 1){
                Arcana = intMod + proficiencyBonus;
            }
            if (randSkill02 == 2){
                History = intMod + proficiencyBonus;
            }
            if (randSkill02 == 3){
                Insight = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 4){
                Investigation = intMod + proficiencyBonus;
            }
            if (randSkill02 == 5){
                Medicine = wisMod + proficiencyBonus;
            }
            if (randSkill02 == 6){
                Religion = intMod + proficiencyBonus;
            }
        }
    }
    else{
        if (Class == "Barbarian"){
            cout << "Barbarians can choose 2 skills from: Animal Handling, Athletics, Intimidation, Nature, Perception, and Survival" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Animal Handling")&&(randSkill01 != "Athletics")&&(randSkill01 != "Intimidation")&&(randSkill01 != "Nature")&&(randSkill01 != "Perception")&&(randSkill01 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Animal Handling"){
                AnimalHandling = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            getline(cin, randSkill02);
            while ((randSkill02 != "Animal Handling")&&(randSkill02 != "Athletics")&&(randSkill02 != "Intimidation")&&(randSkill02 != "Nature")&&(randSkill02 != "Perception")&&(randSkill02 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill02 == "Animal Handling"){
                AnimalHandling = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
        }
        if (Class == "Bard"){
            cout << "Bards can choose 3 skills from: Athletics, Acrobatics, Sleight of Hand, Stealth, Arcana, History, Investigation, Nature, Religion, Animal Handling, Insight, Medicine, Perception, Survival, Deception, Intimidation, Performance, and Persuasion" << endl;
            cout << "Enter skill 1 of 3" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Acrobatics")&&(randSkill01 != "Sleight of Hand")&&(randSkill01 != "Stealth")&&(randSkill01 != "Arcana")&&(randSkill01 != "History")&&(randSkill01 != "Investigation")&&(randSkill01 != "Nature")&&(randSkill01 != "Religion")&&(randSkill01 != "Animal Handling")&&(randSkill01 != "Insight")&&(randSkill01 != "Medicine")&&(randSkill01 != "Perception")&&(randSkill01 != "Survival")&&(randSkill01 != "Deception")&&(randSkill01 != "Intimidation")&&(randSkill01 != "Performance")&&(randSkill01 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 3" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Acrobatics")&&(randSkill02 != "Sleight of Hand")&&(randSkill02 != "Stealth")&&(randSkill02 != "Arcana")&&(randSkill02 != "History")&&(randSkill02 != "Investigation")&&(randSkill02 != "Nature")&&(randSkill02 != "Religion")&&(randSkill02 != "Animal Handling")&&(randSkill02 != "Insight")&&(randSkill02 != "Medicine")&&(randSkill02 != "Perception")&&(randSkill02 != "Survival")&&(randSkill02 != "Deception")&&(randSkill02 != "Intimidation")&&(randSkill02 != "Performance")&&(randSkill02 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 3 of 3" << endl;
            string randSkill03;
            cin.ignore();
            getline(cin, randSkill03);
            while ((randSkill03 != "Athletics")&&(randSkill03 != "Acrobatics")&&(randSkill03 != "Sleight of Hand")&&(randSkill03 != "Stealth")&&(randSkill03 != "Arcana")&&(randSkill03 != "History")&&(randSkill03 != "Investigation")&&(randSkill03 != "Nature")&&(randSkill03 != "Religion")&&(randSkill03 != "Animal Handling")&&(randSkill03 != "Insight")&&(randSkill03 != "Medicine")&&(randSkill03 != "Perception")&&(randSkill03 != "Survival")&&(randSkill03 != "Deception")&&(randSkill03 != "Intimidation")&&(randSkill03 != "Performance")&&(randSkill03 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill03);
            }
            if(randSkill03 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill03 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill03 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
        }
        if(Class == "Cleric"){
            cout << "Clerics can choose 2 skills from: History, Religion, Insight, Medicine, and Persuasion" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "History")&&(randSkill01 != "Religion")&&(randSkill01 != "Insight")&&(randSkill01 != "Medicine")&&(randSkill01 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "History")&&(randSkill02 != "Religion")&&(randSkill02 != "Insight")&&(randSkill02 != "Medicine")&&(randSkill02 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
        }
        if(Class == "Druid"){
            cout << "Druids can choose 2 skills from: Arcana, Nature, Religion, Animal Handling, Insight, Medicine, Perception, and Survival" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Arcana")&&(randSkill01 != "Nature")&&(randSkill01 != "Religion")&&(randSkill01 != "Animal Handling")&&(randSkill01 != "Insight")&&(randSkill01 != "Medicine")&&(randSkill01 != "Perception")&&(randSkill01 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Arcana")&&(randSkill02 != "Nature")&&(randSkill02 != "Religion")&&(randSkill02 != "Animal Handling")&&(randSkill02 != "Insight")&&(randSkill02 != "Medicine")&&(randSkill02 != "Perception")&&(randSkill02 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
        }
        if (Class == "Fighter"){
            cout << "Fighters can choose 2 skills from: Athletics, Acrobatics, History, Animal Handling, Insight, Perception, Survival, and Intimidation" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Acrobatics")&&(randSkill01 != "History")&&(randSkill01 != "Animal Handling")&&(randSkill01 != "Insight")&&(randSkill01 != "Perception")&&(randSkill01 != "Survival")&&(randSkill01 != "Intimidation")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Acrobatics")&&(randSkill02 != "History")&&(randSkill02 != "Animal Handling")&&(randSkill02 != "Insight")&&(randSkill02 != "Perception")&&(randSkill02 != "Survival")&&(randSkill02 != "Intimidation")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
        }
        if (Class == "Monk"){
            cout << "Bards can choose 2 skills from: Athletics, Acrobatics, Stealth, History, Religion, and Insight" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Acrobatics")&&(randSkill01 != "Stealth")&&(randSkill01 != "History")&&(randSkill01 != "Religion")&&(randSkill01 != "Insight")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Acrobatics")&&(randSkill02 != "Stealth")&&(randSkill02 != "History")&&(randSkill02 != "Religion")&&(randSkill02 != "Insight")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
        }
        if (Class == "Paladin"){
            cout << "Paladin can choose 2 skills from: Athletics, Religion, Insight, Medicine, Intimidation, and Persuasion" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Religion")&&(randSkill01 != "Insight")&&(randSkill01 != "Medicine")&&(randSkill01 != "Intimidation")&&(randSkill01 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Religion")&&(randSkill02 != "Insight")&&(randSkill02 != "Medicine")&&(randSkill02 != "Intimidation")&&(randSkill02 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
        }
        if (Class == "Ranger"){
            cout << "Rangers can choose 3 skills from: Athletics, Stealth, Investigation, Nature, Animal Handling, Insight, Perception, and Survival" << endl;
            cout << "Enter skill 1 of 3" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Stealth")&&(randSkill01 != "Investigation")&&(randSkill01 != "Nature")&&(randSkill01 != "Animal Handling")&&(randSkill01 != "Insight")&&(randSkill01 != "Perception")&&(randSkill01 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }cout << "Enter skill 2 of 3" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Stealth")&&(randSkill02 != "Investigation")&&(randSkill02 != "Nature")&&(randSkill02 != "Animal Handling")&&(randSkill02 != "Insight")&&(randSkill02 != "Perception")&&(randSkill02 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
            cout << "Enter skill 3 of 3" << endl;
            string randSkill03;
            cin.ignore();
            getline(cin, randSkill03);
            while ((randSkill03 != "Athletics")&&(randSkill03 != "Stealth")&&(randSkill03 != "Investigation")&&(randSkill03 != "Nature")&&(randSkill03 != "Animal Handling")&&(randSkill03 != "Insight")&&(randSkill03 != "Perception")&&(randSkill03 != "Survival")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill03);
            }
            if(randSkill03 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill03 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Animal Handling"){
                Nature = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Survival"){
                Survival = proficiencyBonus + wisMod;
            }
        }
        if (Class == "Rogue"){
            cout << "Rogues can choose 4 skills from: Athletics, Acrobatics, Sleight of Hand, Stealth, Investigation, Insight, Perception, Deception, Intimidation, Performance, and Persuasion" << endl;
            cout << "Enter skill 1 of 4" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Athletics")&&(randSkill01 != "Acrobatics")&&(randSkill01 != "Sleight of Hand")&&(randSkill01 != "Stealth")&&(randSkill01 != "Investigation")&&(randSkill01 != "Insight")&&(randSkill01 != "Perception")&&(randSkill01 != "Deception")&&(randSkill01 != "Intimidation")&&(randSkill01 != "Performance")&&(randSkill01 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill01 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill01 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 4" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Athletics")&&(randSkill02 != "Acrobatics")&&(randSkill02 != "Sleight of Hand")&&(randSkill02 != "Stealth")&&(randSkill02 != "Investigation")&&(randSkill02 != "Insight")&&(randSkill02 != "Perception")&&(randSkill02 != "Deception")&&(randSkill02 != "Intimidation")&&(randSkill02 != "Performance")&&(randSkill02 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill02 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill02 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 3 of 4" << endl;
            string randSkill03;
            cin.ignore();
            getline(cin, randSkill03);
            while ((randSkill03 != "Athletics")&&(randSkill03 != "Acrobatics")&&(randSkill03 != "Sleight of Hand")&&(randSkill03 != "Stealth")&&(randSkill03 != "Investigation")&&(randSkill03 != "Insight")&&(randSkill03 != "Perception")&&(randSkill03 != "Deception")&&(randSkill03 != "Intimidation")&&(randSkill03 != "Performance")&&(randSkill03 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill03);
            }
            if(randSkill03 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill03 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill03 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill03 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill03 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill03 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 4 of 4" << endl;
            string randSkill04;
            cin.ignore();
            getline(cin, randSkill04);
            while ((randSkill04 != "Athletics")&&(randSkill04 != "Acrobatics")&&(randSkill04 != "Sleight of Hand")&&(randSkill04 != "Stealth")&&(randSkill04 != "Investigation")&&(randSkill04 != "Insight")&&(randSkill04 != "Perception")&&(randSkill04 != "Deception")&&(randSkill04 != "Intimidation")&&(randSkill04 != "Performance")&&(randSkill04 != "Persuasion")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill04);
            }
            if(randSkill04 == "Athletics"){
                Athletics = proficiencyBonus + strMod;
            }
            if(randSkill04 == "Acrobatics"){
                Acrobatics = proficiencyBonus + dexMod;
            }
            if(randSkill04 == "Sleight of Hand"){
                SleightOfHand = proficiencyBonus + dexMod;
            }
            if(randSkill04 == "Stealth"){
                Stealth = proficiencyBonus + dexMod;
            }
            if(randSkill04 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill04 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill04 == "Perception"){
                Perception = proficiencyBonus + wisMod;
            }
            if(randSkill04 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill04 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill04 == "Performance"){
                Performance = proficiencyBonus + chaMod;
            }
            if(randSkill04 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
        }
        if (Class == "Sorcerer"){
            //6 skill, 2 choices randSkill01
            cout << "Sorcerers can choose 2 skills from: Arcana, Religion, Insight, Deception, Intimidation, and Persuasion" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while (((randSkill01 != "Arcana")&&(randSkill01 != "Religion")&&(randSkill01 != "Insight")&&(randSkill01 != "Deception")&&(randSkill01 != "Intimidation")&&(randSkill01 != "Persuasion"))){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while (((randSkill02 != "Arcana")&&(randSkill02 != "Religion")&&(randSkill02 != "Insight")&&(randSkill02 != "Deception")&&(randSkill02 != "Intimidation")&&(randSkill02 != "Persuasion"))){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Persuasion"){
                Persuasion = proficiencyBonus + chaMod;
            }
        }
        if (Class == "Warlock"){
            cout << "Warlocks can choose 2 skills from: Arcana, History, Investigation, Nature, Religion, Deception, and Intimidation" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Arcana")&&(randSkill01 != "History")&&(randSkill01 != "Investigation")&&(randSkill01 != "Nature")&&(randSkill01 != "Religion")&&(randSkill01 != "Deception")&&(randSkill01 != "Intimidation")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill01 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Arcana")&&(randSkill02 != "History")&&(randSkill02 != "Investigation")&&(randSkill02 != "Nature")&&(randSkill02 != "Religion")&&(randSkill02 != "Deception")&&(randSkill02 != "Intimidation")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Nature"){
                Nature = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Deception"){
                Deception = proficiencyBonus + chaMod;
            }
            if(randSkill02 == "Intimidation"){
                Intimidation = proficiencyBonus + chaMod;
            }
        }
        if (Class == "Wizard"){
            //6 skills, 2 choices randSkill01
            cout << "Wizards can choose 2 skills from: Arcana, History, Investigation, Religion, Insight, and Medicine" << endl;
            cout << "Enter skill 1 of 2" << endl;
            string randSkill01;
            cin.ignore();
            getline(cin, randSkill01);
            while ((randSkill01 != "Arcana")&&(randSkill01 != "History")&&(randSkill01 != "Investigation")&&(randSkill01 != "Religion")&&(randSkill01 != "Insight")&&(randSkill01 != "Medicine")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill01);
            }
            if(randSkill01 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill01 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill01 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill01 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
            cout << "Enter skill 2 of 2" << endl;
            string randSkill02;
            cin.ignore();
            getline(cin, randSkill02);
            while ((randSkill02 != "Arcana")&&(randSkill02 != "History")&&(randSkill02 != "Investigation")&&(randSkill02 != "Religion")&&(randSkill02 != "Insight")&&(randSkill02 != "Medicine")){
                cout << "Invalid Skill, please check spelling" << endl;
                getline(cin, randSkill02);
            }
            if(randSkill02 == "Arcana"){
                Arcana = proficiencyBonus + intMod;
            }
            if(randSkill02 == "History"){
                History = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Investigation"){
                Investigation = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Religion"){
                Religion = proficiencyBonus + intMod;
            }
            if(randSkill02 == "Insight"){
                Insight = proficiencyBonus + wisMod;
            }
            if(randSkill02 == "Medicine"){
                Medicine = proficiencyBonus + wisMod;
            }
        }
    }
}

void CalcualteHP(const string Class, const int conMod, const int Level, unsigned int& HP){
	if (Class == "Barbarian"){
			HP = conMod + ((10 + (rand() % 13)) * Level);
		}

		if (Class == "Bard"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Cleric"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Druid"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Fighter"){
			HP = conMod + ((10 + (rand() % 11)) * Level);
		}

		if (Class == "Monk"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Paladin"){
			HP = conMod + ((10 + (rand() % 11)) * Level);
		}

		if (Class == "Ranger"){
			HP = conMod + ((10 + (rand() % 11)) * Level);
		}

		if (Class == "Rogue"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Sorcerer"){
			HP = conMod + ((10 + (rand() % 7)) * Level);
		}

		if (Class == "Warlock"){
			HP = conMod + ((10 + (rand() % 9)) * Level);
		}

		if (Class == "Wizard"){
			HP = conMod + ((10 + (rand() % 7)) * Level);
		}
}

void CalcualteAC(unsigned int& AC, const int dexMod){
	AC = 10 + dexMod;
}

void CalculateInitiative(int& Initiative, const int dexMod){
	Initiative = dexMod;
}

void CalcualteSpellAtk(const string Class, const int intMod, const int wisMod, const int chaMod, unsigned int& spellAtk){
	if ((Class == "Sorcerer") || (Class == "Bard") || (Class == "Warlock") || (Class == "Paladin")){
			spellAtk = chaMod + 2;
		}
		else if ((Class == "Wizard") || (Class == "Rogue") || (Class == "Fighter") || (Class == "Barbarian")){
			spellAtk = intMod + 2;
		}
		else if ((Class == "Druid") || (Class == "Cleric") || (Class == "Ranger") || (Class == "Monk")){
			spellAtk = wisMod + 2;
		}
		else{
			spellAtk = intMod + 2;
		}
}

void CalcualteDC(const unsigned int spellAtk, unsigned int& spellDC){
	spellDC = spellAtk + 8;
}


void SetSpeed (const string& Race, int& Speed, int& swimSpeed, int& flightSpeed){
    if (Race.find ("Aarakocra") != string::npos){
        Speed = 25;
        swimSpeed = 17;
        flightSpeed = 50;
    }
    if (Race.find ("Aasimar") != string::npos){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Avian")){
        Speed = 25;
        swimSpeed = 17;
        flightSpeed = 30;
    }
    if (Race.find ("Mammal")){
        Speed = 40;
        swimSpeed = 20;
        flightSpeed = 0;
    }
    if (Race.find ("Aquatic")){
        Speed = 25;
        swimSpeed = 30;
        flightSpeed = 0;
    }
    if (Race.find ("Bugbear") != string::npos){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Centaur"){
        Speed = 50;
        swimSpeed = 20;
        flightSpeed = 0;
    }
    if (Race.find ("Dragonborn") != string::npos){
        Speed = 30;
        swimSpeed = 0;
        flightSpeed = 0;
    }
    if (Race.find ("Dwarf") != string::npos){
        Speed = 25;
        swimSpeed = 17;
        flightSpeed = 0;
    }
    if (Race == "Loxodon"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Elf") != string::npos){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Drow"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Firbolg"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Genasi") != string::npos){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Gith") != string::npos){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Gnome") != string::npos){
        Speed = 25;
        swimSpeed = 17;
        flightSpeed = 0;
    }
    if (Race == "Goblin"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Goliath"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Half-Elf"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Half-Orc"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Halfling") != string::npos){
        Speed = 25;
        swimSpeed = 17;
        flightSpeed = 0;
    }
    if (Race == "Hobgoblin"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Human"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Kenku"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 5;
    }
    if (Race == "Kobold"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Lizardfolk"){
        Speed = 30;
        swimSpeed = 30;
        flightSpeed = 0;
    }
    if (Race == "Minotaur"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Orc"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Yuan-Ti"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race == "Tabaxi"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
    if (Race.find ("Tiefling") != string::npos){
        if(Race.find ("Winged") != string::npos){
            Speed = 30;
            swimSpeed = 15;
            flightSpeed = 15;
        }
        else {
            Speed = 30;
            swimSpeed = 15;
            flightSpeed = 0;
        }
    }
    if (Race == "Triton"){
        Speed = 30;
        swimSpeed = 30;
        flightSpeed = 0;
    }
    if (Race == "Tortle"){
        Speed = 25;
        swimSpeed = 30;
        flightSpeed = 0;
    }
    if (Race == "Vedalken"){
        Speed = 30;
        swimSpeed = 15;
        flightSpeed = 0;
    }
}

void SpellsKnown (const int& Level, const string& SubClass, const string& Class, int& spellsknown, int& cantripsknown){
    if (Level == 1){
        if (Class == "Bard"){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 2;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 0;
            spellsknown = 0;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 0;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 0;
            spellsknown = 0;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 4;
            spellsknown = 2;
        }
        if (Class == "Warlock"){
            cantripsknown = 2;
            spellsknown = 2;
        }
        if (Class == "Wizard"){
            cantripsknown = 3;
            spellsknown = 69;
        }
    }
    if (Level == 2){
        if (Class == "Bard"){
            cantripsknown = 2;
            spellsknown = 5;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 2;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 0;
            spellsknown = 0;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 2;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 0;
            spellsknown = 0;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 4;
            spellsknown = 3;
        }
        if (Class == "Warlock"){
            cantripsknown = 2;
            spellsknown = 3;
        }
        if (Class == "Wizard"){
            cantripsknown = 3;
            spellsknown = 69;
        }
    }
    if (Level == 3){
        if (Class == "Bard"){
            cantripsknown = 2;
            spellsknown = 6;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 2;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 3;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 3;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 3;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 4;
            spellsknown = 4;
        }
        if (Class == "Warlock"){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Wizard"){
            cantripsknown = 3;
            spellsknown = 69;
        }
    }
    if (Level == 4){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 7;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 3;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 3;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 5;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 5;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 5){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 4;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 6;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 6;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 6){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 9;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 4;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 4;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 7;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 7;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 7){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 5;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 4;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 5;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 8;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 8){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 6;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 5;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 6;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 9;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 9;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 9){
        if (Class == "Bard"){
            cantripsknown = 3;
            spellsknown = 12;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 3;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 2;
            spellsknown = 6;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 5;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 2;
            spellsknown = 6;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 5;
            spellsknown = 10;
        }
        if (Class == "Warlock"){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Wizard"){
            cantripsknown = 4;
            spellsknown = 69;
        }
    }
    if (Level == 10){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 14;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 7;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 6;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 7;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 11;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 10;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 11){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 15;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 7;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 12;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 11;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 12){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 15;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 7;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 8;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 12;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 11;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 13){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 16;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 9;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 8;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 9;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 13;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 12;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 14){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 18;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 8;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 13;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 12;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 15){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 19;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 9;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 10;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 14;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 13;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 16){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 19;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 9;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 14;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 13;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 17){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 20;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 10;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 15;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 14;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 18){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 22;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 10;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 11;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 15;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 14;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 19){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 22;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 12;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Ranger"){
            cantripsknown = 0;
            spellsknown = 11;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 12;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 15;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 15;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
    if (Level == 20){
        if (Class == "Bard"){
            cantripsknown = 4;
            spellsknown = 22;
        }
        if (Class == "Cleric"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (Class == "Druid"){
            cantripsknown = 4;
            spellsknown = 69;
        }
        if (SubClass == "Eldritch Knight "){
            cantripsknown = 3;
            spellsknown = 13;
        }
        if (Class == "Paladin"){
            cantripsknown = 69;
            spellsknown = 69;
        }
        if (SubClass == "Ranger"){
            cantripsknown = 0;
            spellsknown = 11;
        }
        if (SubClass == "Arcane Trickster "){
            cantripsknown = 3;
            spellsknown = 13;
        }
        if (Class == "Sorcerer"){
            cantripsknown = 6;
            spellsknown = 15;
        }
        if (Class == "Warlock"){
            cantripsknown = 4;
            spellsknown = 15;
        }
        if (Class == "Wizard"){
            cantripsknown = 5;
            spellsknown = 69;
        }
    }
}

void DisplayCharacter (const int& passivePerception){

    cout << "Would you like to print your character?" << endl << "enter Y or N (Capital Letters)" << endl;
    char displayLoop;
    cin >> displayLoop;
    while(displayLoop == 'Y'){
        string filename;
    cout << "Enter the name of the output file: " << endl << "Use _ instead of spaces" << endl;
    cin >> filename;
    filename += ".txt";
    std::ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        cout << "Error opening " << filename << endl;
        exit (1);
    }
    fout << Race << ", ";
		if (fightingstyle == true ){
			fout << FightingStyle;
		}
		if (subclass == true ){
			fout << SubClass;
		}
		fout << "";
		fout << Class << ", " << "Level " << Level << endl << Alignment << ", " << Background << endl;
		fout << HP << " HP, " << AC <<" AC, " << Initiative << " Initiative, " << passivePerception << " Passive Perception, " << endl;
		fout << Speed << " Speed, " << swimSpeed << " Swim Speed, " << flightSpeed << " Flight Speed" << endl;
        fout << "Strength:" << endl;
        fout << "Score: " << Str << " Mod: " << strMod << endl;
        fout << "Athletics: " << Athletics << endl;

        fout << "Dexterity:" << endl;
        fout << "Score: " << Dex << " Mod: " << dexMod << endl;
        fout << "Acrobatics: " << Acrobatics << ", Sleight of Hand: " << SleightOfHand << ", Stealth: " << Stealth << endl;

        fout << "Constitution:" << endl;
        fout << "Score: " << Con << " Mod: " << conMod << endl;

        fout << "Intelligence:" << endl;
        fout << "Score: " << Int << " Mod: " << intMod << endl;
        fout << "Animal Handling: " << AnimalHandling << ", Insight:" << Insight << ", Medicine: " << Medicine << ", Perception: " << Perception << ", Survival: " << Survival << endl;

        fout << "Wisdom:" << endl;
        fout << "Score: " << Wis << " Mod: " << wisMod << endl;
        fout << "Arcana: " << Arcana << ", History: " << History << ", Investigation: " << Investigation << ", Nature: " << Nature << ", Religion: " << Religion << endl;

        fout << "Charisma:" << endl;
        fout << "Score: " << Cha << " Mod: " << chaMod << endl;
        fout << "Deception: " << Deception << ", Intimidation: " << Intimidation << ", Performance: " << Performance << ", Persuasion: " << Persuasion << endl;

		fout << "Spell Attack: " << spellAtk << endl;
		fout << "Spell DC: " << spellDC << endl;

		fout << "Feats: ";
		for (unsigned int i=0; i < userFeats.size(); ++i){
            if (userFeats.size() == 0){
                fout << "none" << endl;
            }
            else if (i == userFeats.size() - 1){
                fout << userFeats.at(i) << " ";
            }
            else{
                fout << userFeats.at(i) << ", ";
            }
        }
        fout << endl;
        fout << "Proficiencies: ";
		for (unsigned int i=0; i < userProficiencies.size(); ++i){
            if(i == userProficiencies.size() - 1){
                fout << userProficiencies.at(i) << " ";
            }
            else{
                fout << userProficiencies.at(i) << ", ";
            }
        }
        fout << endl;

        if ((Class == "Bard") || (Class == "Cleric") || (Class == "Druid") || (SubClass == "Eldritch Knight ") || (Class == "Paladin") || (SubClass == "Arcane Trickster ") || (Class == "Ranger") || (Class == "Sorcerer") || (Class == "Warlock") || (Class == "Wizard")){
            fout << "Spell Slots: " << endl;
            fout << "LVL 1: " << LVL1slots << ", " << "LVL 2: " << LVL2slots << ", " << "LVL 3: " << LVL3slots << ", " << "LVL 4: " << LVL4slots << ", " << "LVL 5: " << LVL5slots << ", " << "LVL 6: " << LVL6slots << ", " << "LVL 7: " << LVL7slots << ", " << "LVL 8: " << LVL8slots << ", " << "LVL 9: " << LVL9slots << endl;

            fout << "Spells Known: " << endl;
            if (cantripsknown == 69){
                fout << "Cantrips: See Rules";
            }
            else {
                fout << "Cantrips: " << cantripsknown;
            }
            if (spellsknown == 69){
                fout << ", Spells: See Rules" << endl;
            }
            else {
                fout << ", Spells: " << spellsknown << endl;
            }
        }
    displayLoop = 'N';
    fout.close();
    }
}

void setTraits(const string& Alignment, string& ideals, string& bonds, string& flaws){
    ///Bonds
    cout << "Randomize Bonds?" << endl << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if (userOption == 'Y'){
        int randBond = 1 + rand() % 78;
        if (randBond == 1){
            bonds = "I would die to recover an ancient artifact of my faith that was lost long ago.";
        }
        if (randBond == 2){
            bonds = "I will someday get revenge on the corrupt temple hierarchy who branded me a heretic.";
        }
        if (randBond == 3){
            bonds = "I owe me life to the priest who took me in when my parents died.";
        }
        if (randBond == 4){
            bonds = "Everything I do is for the common people.";
        }
        if (randBond == 5){
            bonds = "I will do anything to protect the temple where I served.";
        }
        if (randBond == 6){
            bonds = "I seek to preserve a sacred text that my enemies consider heretical and seek to destroy.";
        }
        if (randBond == 7){
            bonds = "I fleeced the wrong person and must work to ensure that this individual never crosses paths with me or those I care about.";
        }
        if (randBond == 8){
            bonds = "I owe everything to my mentor--a horrible person who's probably rotting in jail somewhere.";
        }
        if (randBond == 9){
            bonds = "Somewhere out there I have a child who doesn't know me. I'm making the world better for him or her.";
        }
        if (randBond == 10){
            bonds = "I come from a noble family, and one day I'll reclaim my lands and title from those who stole them from me.";
        }
        if (randBond == 11){
            bonds = "A powerful person killed someone I love. Some day soon, I'll have my revenge.";
        }
        if (randBond == 12){
            bonds = "I swindled and ruined a person who didn't deserve it. I seek to atone for my misdeeds but might never be able to forgive myself.";
        }
        if (randBond == 13){
            bonds = "I'm trying to pay off an old debt I owe to a generous benefactor.";
        }
        if (randBond == 14){
            bonds = "My ill-gotten gains go to support my family.";
        }
        if (randBond == 15){
            bonds = "Something important was taken from me, and I aim to steal it back.";
        }
        if (randBond == 16){
            bonds = "I will become the greatest thief that ever lived.";
        }
        if (randBond == 17){
            bonds = "I'm guilty of a terrible crime. I hope I can redeem myself for it.";
        }
        if (randBond == 18){
            bonds = "Someone I loved died because of a mistake I made. That will never happen again.";
        }
        if (randBond == 19){
            bonds = "My instrument is my most treasured possession, and it reminds me of someone I love.";
        }
        if (randBond == 20){
            bonds = "Someone stole my precious instrument, and someday I'll get it back.";
        }
        if (randBond == 21){
            bonds = "I want to be famous, whatever it takes.";
        }
        if (randBond == 22){
            bonds = "I idolize a hero of the old tales and measure my deeds against that person's.";
        }
        if (randBond == 23){
            bonds = "I will do anything to prove myself superior to me hated rival.";
        }
        if (randBond == 24){
            bonds = "I would do anything for the other members of my old troupe.";
        }
        if (randBond == 25){
            bonds = "I have a family, but I have no idea where they are. One day, I hope to see them again.";
        }
        if (randBond == 26){
            bonds = "I worked the land, I love the land, and I will protect the land.";
        }
        if (randBond == 27){
            bonds = "A proud noble once gave me a horrible beating, and I will take my revenge on any bully I encounter.";
        }
        if (randBond == 28){
            bonds = "My tools are symbols of my past life, and I carry them so that I will never forget my roots.";
        }
        if (randBond == 29){
            bonds = "I protect those who cannot protect themselves.";
        }
        if (randBond == 30){
            bonds = "I wish my childhood sweetheart had come with me to pursue my destiny.";
        }
        if (randBond == 31){
            bonds = "The workshop where I learned my trade is the most important place in the world to me.";
        }
        if (randBond == 32){
            bonds = "I created a great work for someone, and then found them unworthy to receive it. I'm still looking for someone worthy.";
        }
        if (randBond == 33){
            bonds = "I owe my guild a great debt for forging me into the person I am today.";
        }
        if (randBond == 34){
            bonds = "I pursue wealth to secure someone's love.";
        }
        if (randBond == 35){
            bonds = "One day I will return to my guild and prove that I am the greatest artisan of them all.";
        }
        if (randBond == 36){
            bonds = "I will get revenge on the evil forces that destroyed my place of business and ruined my livelihood.";
        }
        if (randBond == 37){
            bonds = "Nothing is more important than the other members of my hermitage, order, or association.";
        }
        if (randBond == 38){
            bonds = "I entered seclusion to hide from the ones who might still be hunting me. I must someday confront them.";
        }
        if (randBond == 39){
            bonds = "I'm still seeking the enlightenment I pursued in my seclusion, and it still eludes me.";
        }
        if (randBond == 40){
            bonds = "I entered seclusion because I loved someone I could not have.";
        }
        if (randBond == 41){
            bonds = "Should my discovery come to light, it could bring ruin to the world.";
        }
        if (randBond == 42){
            bonds = "My isolation gave me great insight into a great evil that only I can destroy.";
        }
        if (randBond == 43){
            bonds = "I will face any challenge to win the approval of my family.";
        }
        if (randBond == 44){
            bonds = "My house's alliance with another noble family must be sustained at all costs.";
        }
        if (randBond == 45){
            bonds = "Nothing is more important that the other members of my family.";
        }
        if (randBond == 46){
            bonds = "I am in love with the heir of a family that my family despises.";
        }
        if (randBond == 47){
            bonds = "My loyalty to my sovereign is unwavering.";
        }
        if (randBond == 48){
            bonds = "The common folk must see me as a hero of the people.";
        }
        if (randBond == 49){
            bonds = "My family, clan, or tribe is the most important thing in my life, even when they are far from me.";
        }
        if (randBond == 50){
            bonds = "An injury to the unspoiled wilderness of my home is an injury to me.";
        }
        if (randBond == 51){
            bonds = "I will bring terrible wrath down on the evildoers who destroyed my homeland.";
        }
        if (randBond == 52){
            bonds = "I am the last of my tribe, and it is up to me to ensure their names enter legend.";
        }
        if (randBond == 53){
            bonds = "I suffer awful visions of a coming disaster and will do anything to prevent it.";
        }
        if (randBond == 54){
            bonds = "It is my duty to provide children to sustain my tribe.";
        }
        if (randBond == 55){
            bonds = "It is my duty to protect my students.";
        }
        if (randBond == 56){
            bonds = "I have an ancient text that holds terrible secrets that must not fall into the wrong hands.";
        }
        if (randBond == 57){
            bonds = "I work to preserve a library, university, scriptorium, or monastery.";
        }
        if (randBond == 58){
            bonds = "My life's work is a series of tomes related to a specific field of lore.";
        }
        if (randBond == 59){
            bonds = "I've been searching my whole life for the answer to a certain question.";
        }
        if (randBond == 60){
            bonds = "I sold my soul for knowledge. I hope to do great deeds and win it back.";
        }
        if (randBond == 61){
            bonds = "I'm loyal to my captain first, everything else second.";
        }
        if (randBond == 62){
            bonds = "The ship is most important--crewmates and captains come and go.";
        }
        if (randBond == 63){
            bonds = "I'll always remember my first ship.";
        }
        if (randBond == 64){
            bonds = "In a harbor town, I have a paramour whose eyes nearly stole me from the sea.";
        }
        if (randBond == 65){
            bonds = "I was cheated of my fair share of the profits, and I want to get my due.";
        }
        if (randBond == 66){
            bonds = "Ruthless pirates murdered my captain and crewmates, plundered our ship, and left me to die. Vengeance will be mine.";
        }
        if (randBond == 67){
            bonds = "I would lay down my life for the people I served with.";
        }
        if (randBond == 68){
            bonds = "Someone saved my life on the battlefield. To this day, I will never leave a friend behind.";
        }
        if (randBond == 69){
            bonds = "My honor is my life.";
        }
        if (randBond == 70){
            bonds = "I'll never forget the crushing defeat my company suffered or the enemies who dealt it.";
        }
        if (randBond == 71){
            bonds = "Those who fight beside me are those worth dying for.";
        }
        if (randBond == 72){
            bonds = "I fight for those who cannot fight for themselves.";
        }
        if (randBond == 73){
            bonds = "My town or city is my home, and I'll fight to defend it.";
        }
        if (randBond == 74){
            bonds = "I sponsor an orphanage to keep others from enduring what I was forced to endure.";
        }
        if (randBond == 75){
            bonds = "I owe my survival to another urchin who taught me to live on the streets.";
        }
        if (randBond == 76){
            bonds = "I owe a debt I can never repay to the person who took pity on me.";
        }
        if (randBond == 77){
            bonds = "I escaped my life of poverty by robbing an important person, and I'm wanted for it.";
        }
        if (randBond == 78){
            bonds = "No one else is going to have to endure the hardships I've been through.";
        }
    }
    else if (userOption == 'N'){
        cout << "Enter Ideals" << endl;
        getline (cin, ideals);
    }

    ///Flaws
    cout << "Randomize Flaws?" << endl << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if (userOption == 'Y'){
        int randFlaw = 1 + rand() % 78;
        if (randFlaw == 1){
            flaws = "I judge others harshly, and myself even more severely.";
        }
        if (randFlaw == 2){
            flaws = "I put too much trust in those who wield power within my temple's hierarchy.";
        }
        if (randFlaw == 3){
            flaws = "My piety sometimes leads me to blindly trust those that profess faith in my god.";
        }
        if (randFlaw == 4){
            flaws = "I am inflexible in my thinking.";
        }
        if (randFlaw == 5){
            flaws = "I am suspicious of strangers and suspect the worst of them.";
        }
        if (randFlaw == 6){
            flaws = "Once I pick a goal, I become obsessed with it to the detriment of everything else in my life.";
        }
        if (randFlaw == 7){
            flaws = "I can't resist a pretty face.";
        }
        if (randFlaw == 8){
            flaws = "I'm always in debt. I spend my ill-gotten gains on decadent luxuries faster than I bring them in.";
        }
        if (randFlaw == 9){
            flaws = "I'm convinced that no one could ever fool me in the way I fool others.";
        }
        if (randFlaw == 10){
            flaws = "I'm too greedy for my own good. I can't resist taking a risk if there's money involved.";
        }
        if (randFlaw == 11){
            flaws = "I can't resist swindling people who are more powerful than me.";
        }
        if (randFlaw == 12){
            flaws = "I hate to admit it and will hate myself for it, but I'll run and preserve my own hide if the going gets tough.";
        }
        if (randFlaw == 13){
            flaws = "When I see something valuable, I can't think about anything but how to steal it.";
        }
        if (randFlaw == 14){
            flaws = "When faced with a choice between money and my friends, I usually choose the money.";
        }
        if (randFlaw == 15){
            flaws = "If there's a plan, I'll forget it. If I don't forget it, I'll ignore it.";
        }
        if (randFlaw == 16){
            flaws = "I have a 'tell' that reveals when I'm lying.";
        }
        if (randFlaw == 17){
            flaws = "I turn tail and run when things go bad.";
        }
        if (randFlaw == 18){
            flaws = "An innocent person is in prison for a crime that I committed. I'm okay with that.";
        }
        if (randFlaw == 19){
            flaws = "I'll do anything to win fame and renown.";
        }
        if (randFlaw == 20){
            flaws = "I'm a sucker for a pretty face.";
        }
        if (randFlaw == 21){
            flaws = "A scandal prevents me from ever going home again. That kind of trouble seems to follow me around.";
        }
        if (randFlaw == 22){
            flaws = "I once satirized a noble who still wants my head. It was a mistake that I will likely repeat.";
        }
        if (randFlaw == 23){
            flaws = "I have trouble keeping my true feelings hidden. My sharp tongue lands me in trouble.";
        }
        if (randFlaw == 24){
            flaws = "Despite my best efforts, I am unreliable to my friends.";
        }
        if (randFlaw == 25){
            flaws = "The tyrant who rules my land will stop at nothing to see me killed.";
        }
        if (randFlaw == 26){
            flaws = "I'm convinced of the significance of my destiny, and blind to my shortcomings and the risk of failure.";
        }
        if (randFlaw == 27){
            flaws = "The people who knew me when I was young know my shameful secret, so I can never go home again.";
        }
        if (randFlaw == 28){
            flaws = "I have a weakness for the vices of the city, especially hard drink.";
        }
        if (randFlaw == 29){
            flaws = "Secretly, I believe that things would be better if I were a tyrant lording over the land.";
        }
        if (randFlaw == 30){
            flaws = "I have trouble trusting in my allies.";
        }
        if (randFlaw == 31){
            flaws = "I'll do anything to get my hands on something rare or priceless.";
        }
        if (randFlaw == 32){
            flaws = "I'm quick to assume that someone is trying to cheat me.";
        }
        if (randFlaw == 33){
            flaws = "No one must ever learn that I once stole money from guild coffers.";
        }
        if (randFlaw == 34){
            flaws = "I'm never satisfied with what I have--I always want more.";
        }
        if (randFlaw == 35){
            flaws = "I would kill to acquire a noble title.";
        }
        if (randFlaw == 36){
            flaws = "I'm horribly jealous of anyone who outshines my handiwork. Everywhere I go, I'm surrounded by rivals.";
        }
        if (randFlaw == 37){
            flaws = "Now that I've returned to the world, I enjoy its delights a little too much.";
        }
        if (randFlaw == 38){
            flaws = "I harbor dark bloodthirsty thoughts that my isolation failed to quell.";
        }
        if (randFlaw == 39){
            flaws = "I am dogmatic in my thoughts and philosophy.";
        }
        if (randFlaw == 40){
            flaws = "I let my need to win arguments overshadow friendships and harmony.";
        }
        if (randFlaw == 41){
            flaws = "I'd risk too much to uncover a lost bit of knowledge.";
        }
        if (randFlaw == 42){
            flaws = "I like keeping secrets and won't share them with anyone.";
        }
        if (randFlaw == 43){
            flaws = "I secretly believe that everyone is beneath me.";
        }
        if (randFlaw == 44){
            flaws = "I hide a truly scandalous secret that could ruin my family forever.";
        }
        if (randFlaw == 45){
            flaws = "I too often hear veiled insults and threats in every word addressed to me, and I'm quick to anger.";
        }
        if (randFlaw == 46){
            flaws = "I have an insatiable desire for carnal pleasures.";
        }
        if (randFlaw == 47){
            flaws = "In fact, the world does revolve around me.";
        }
        if (randFlaw == 48){
            flaws = "By my words and actions, I often bring shame to my family.";
        }
        if (randFlaw == 49){
            flaws = "I am too enamored of ale, wine, and other intoxicants.";
        }
        if (randFlaw == 50){
            flaws = "There's no room for caution in a life lived to the fullest.";
        }
        if (randFlaw == 51){
            flaws = "I remember every insult I've received and nurse a silent resentment toward anyone who's ever wronged me.";
        }
        if (randFlaw == 52){
            flaws = "I am slow to trust members of other races";
        }
        if (randFlaw == 53){
            flaws = "Violence is my answer to almost any challenge.";
        }
        if (randFlaw == 54){
            flaws = "Don't expect me to save those who can't save themselves. It is nature's way that the";
        }
        if (randFlaw == 55){
            flaws = "I am easily distracted by the promise of information.";
        }
        if (randFlaw == 56){
            flaws = "Most people scream and run when they see a demon. I stop and take notes on its anatomy.";
        }
        if (randFlaw == 57){
            flaws = "Unlocking an ancient mystery is worth the price of a civilization.";
        }
        if (randFlaw == 58){
            flaws = "I overlook obvious solutions in favor of complicated ones.";
        }
        if (randFlaw == 59){
            flaws = "I speak without really thinking through my words, invariably insulting others.";
        }
        if (randFlaw == 60){
            flaws = "I can't keep a secret to save my life, or anyone else's.";
        }
        if (randFlaw == 61){
            flaws = "I follow orders, even if I think they're wrong.";
        }
        if (randFlaw == 62){
            flaws = "I'll say anything to avoid having to do extra work.";
        }
        if (randFlaw == 63){
            flaws = "Once someone questions my courage, I never back down no matter how dangerous the";
        }
        if (randFlaw == 64){
            flaws = "Once I start drinking, it's hard for me to stop.";
        }
        if (randFlaw == 65){
            flaws = "I can't help but pocket loose coins and other trinkets I come across.";
        }
        if (randFlaw == 66){
            flaws = "My pride will probably lead to my destruction";
        }
        if (randFlaw == 67){
            flaws = "The monstrous enemy we faced in battle still leaves me quivering with fear.";
        }
        if (randFlaw == 68){
            flaws = "I have little respect for anyone who is not a proven warrior.";
        }
        if (randFlaw == 69){
            flaws = "I made a terrible mistake in battle that cost many lives--and I would do anything to keep that mistake secret.";
        }
        if (randFlaw == 70){
            flaws = "My hatred of my enemies is blind and unreasoning.";
        }
        if (randFlaw == 71){
            flaws = "I obey the law, even if the law causes misery.";
        }
        if (randFlaw == 72){
            flaws = "I'd rather eat my armor than admit when I'm wrong.";
        }
        if (randFlaw == 73){
            flaws = "If I'm outnumbered, I always run away from a fight.";
        }
        if (randFlaw == 74){
            flaws = "Gold seems like a lot of money to me, and I'll do just about anything for more of it.";
        }
        if (randFlaw == 75){
            flaws = "I will never fully trust anyone other than myself.";
        }
        if (randFlaw == 76){
            flaws = "I'd rather kill someone in their sleep than fight fair.";
        }
        if (randFlaw == 77){
            flaws = "It's not stealing if I need it more than someone else.";
        }
        if (randFlaw == 78){
            flaws = "People who don't take care of themselves get what they deserve.";
        }
    }
    else if (userOption == 'N'){
        cout << "Enter Flaws" << endl;
        getline (cin, flaws);
    }

    ///Ideals
    cout << "Randomize Ideals?" << endl << "enter Y or N (Capital Letters)" << endl;
    cin >> userOption;
    if (userOption == 'Y'){
            int randChoice = 1 + rand() % 2;
            if (randChoice == 1){
                if(Alignment.find("Lawful") != string::npos){
                    int randIdeal = 1 + rand() % 14;
                    if (randIdeal == 1){
                        ideals = "Tradition. The ancient traditions of worship and sacrifice must be preserved and upheld.";
                    }
                    if (randIdeal == 2){
                        ideals = "Power. I hope to one day rise to the top of my faith's religious hierarchy.";
                    }
                    if (randIdeal == 3){
                        ideals = "Fairness. I never target people who can't afford to lose a few coins.";
                    }
                    if (randIdeal == 4){
                        ideals = "Honor. I don't steal from others in the trade.";
                    }
                    if (randIdeal == 5){
                        ideals = "Tradition. The stories, legends, and songs of the past must never be forgotten.";
                    }
                    if (randIdeal == 6){
                        ideals = "Fairness. No one should get preferential treatment before the law, and no one is above the law.";
                    }
                    if (randIdeal == 7){
                        ideals = "Community. It is the duty of all civilized people to strengthen the bonds of community and the security of civilization.";
                    }
                    if (randIdeal == 8){
                        ideals = "Logic. Emotions must not cloud our sense of what is right and true, or our logical thinking.";
                    }
                    if (randIdeal == 9){
                        ideals = "Responsibility. It is my duty to respect the authority of those above me, just as those below me must respect mine.";
                    }
                    if (randIdeal == 10){
                        ideals = "Honor. If I dishonor myself, I dishonor my whole clan.";
                    }
                    if (randIdeal == 11){
                        ideals = "Logic. Emotions must not cloud our logical thinking.";
                    }
                    if (randIdeal == 12){
                        ideals = "Fairness. We all do the work, so we all share in the rewards.";
                    }
                    if (randIdeal == 13){
                        ideals = "Responsibility. I do what I must and obey just authority.";
                    }
                    if (randIdeal == 14){
                        ideals = "Community. We have to take care of each other, because no one else is going to do it.";
                    }
                }
                else if(Alignment.find("Neutral") != string::npos){
                    int randIdeal = 1 + rand() % 10;
                    if (randIdeal == 1){
                        ideals = "People. I'm loyal to my friends, not to any ideals, and everyone else can take a trip down the Styx for all I care.";
                    }
                    if (randIdeal == 2){
                        ideals = "People. I like seeing the smiles on people's faces when I perform. That's all that matters.";
                    }
                    if (randIdeal == 3){
                        ideals = "Sincerity. There's no good pretending to be something I'm not.";
                    }
                    if (randIdeal == 4){
                        ideals = "People. I'm committed to the people I care about, not to ideals.";
                    }
                    if (randIdeal == 5){
                        ideals = "Live and Let Live. Meddling in the affairs of others only causes trouble.";
                    }
                    if (randIdeal == 6){
                        ideals = "Nature. The natural world is more important than all the constructs of civilization.";
                    }
                    if (randIdeal == 7){
                        ideals = "Knowledge. The path to power and self-improvement is through knowledge.";
                    }
                    if (randIdeal == 8){
                        ideals = "People. I'm committed to my crewmates, not to ideals.";
                    }
                    if (randIdeal == 9){
                        ideals = "Ideals aren't worth killing for or going to war for.";
                    }
                    if (randIdeal == 10){
                        ideals = "People. I help people who help me--that's what keeps us alive.";
                    }
                }
                else if(Alignment.find("Chaotic") != string::npos){
                    int randIdeal = 1 + rand() % 14;
                    if (randIdeal == 1){
                        ideals = "Change. We must help bring about the changes the gods are constantly working in the world.";
                    }
                    if (randIdeal == 2){
                        ideals = "Independence. I am a free spirit--no one tells me what to do.";
                    }
                    if (randIdeal == 3){
                        ideals = "Creativity. I never run the same con twice.";
                    }
                    if (randIdeal == 4){
                        ideals = "Freedom. Chains are meant to be broken, as are those who would forge them.";
                    }
                    if (randIdeal == 5){
                        ideals = "Creativity. The world is in need of new ideas and bold action.";
                    }
                    if (randIdeal == 6){
                        ideals = "Freedom. Tyrants must not be allowed to oppress the people.";
                    }
                    if (randIdeal == 7){
                        ideals = "Freedom. Everyone should be free to pursue his or her livelihood.";
                    }
                    if (randIdeal == 8){
                        ideals = "Free Thinking. Inquiry and curiosity are the pillars of progress.";
                    }
                    if (randIdeal == 9){
                        ideals = "Independence. I must prove that I can handle myself without the coddling of my family.";
                    }
                    if (randIdeal == 10){
                        ideals = "Change. Life is like the seasons, in constant change, and we must change with it.";
                    }
                    if (randIdeal == 11){
                        ideals = "No Limits. Nothing should fetter the infinite possibility inherent in all existence.";
                    }
                    if (randIdeal == 12){
                        ideals = "Freedom. The sea is freedom--the freedom to go anywhere and do anything.";
                    }
                    if (randIdeal == 13){
                        ideals = "Independence. When people follow orders blindly they embrace a kind of tyranny.";
                    }
                    if (randIdeal == 14){
                        ideals = "Change. The low are lifted up, and the high and mighty are brought down. Change is the nature of things.";
                    }
                }
                else if(Alignment.find("Good") != string::npos){
                    int randIdeal = 1 + rand() % 15;
                    if (randIdeal == 1){
                        ideals = "Charity. I always try to help those in need, no matter what the personal cost.";
                    }
                    if (randIdeal == 2){
                        ideals = "Charity. I distribute money I acquire to the people who really need it.";
                    }
                    if (randIdeal == 3){
                        ideals = "Friendship. Material goods come and go. Bonds of friendship last forever.";
                    }
                    if (randIdeal == 4){
                        ideals = "Charity. I steal from the wealthy so that I can help people in need.";
                    }
                    if (randIdeal == 5){
                        ideals = "Redemption. There's a spark of good in everyone.";
                    }
                    if (randIdeal == 6){
                        ideals = "Beauty. When I perform, I make the world better than it was.";
                    }
                    if (randIdeal == 7){
                        ideals = "Generosity. My talents were given to me so that I could use them to benefit the world.";
                    }
                    if (randIdeal == 8){
                        ideals = "Greater Good. My gifts are meant to be shared with all, not used for my own benefit.";
                    }
                    if (randIdeal == 9){
                        ideals = "Respect. Respect is due to me because of my position, but all people regardless of station deserve to be treated with dignity.";
                    }
                    if (randIdeal == 10){
                        ideals = "Noble Obligation. It is my duty to protect and care for the people beneath me.";
                    }
                    if (randIdeal == 11){
                        ideals = "Greater Good. It is each person's responsibility to make the most happiness for the whole tribe.";
                    }
                    if (randIdeal == 12){
                        ideals = "Beauty. What is beautiful points us beyond itself toward what is true.";
                    }
                    if (randIdeal == 13){
                        ideals = "Respect. The thing that keeps a ship together is mutual respect between captain and crew.";
                    }
                    if (randIdeal == 14){
                        ideals = "Greater Good. Our lot is to lay down our lives in defense of others.";
                    }
                    if (randIdeal == 15){
                        ideals = "Respect. All people, rich or poor, deserve respect.";
                    }
                    if (randIdeal == 16){
                        ideals = "Respect. People deserve to be treated with dignity and respect.";
                    }
                }
                else if(Alignment.find("Evil") != string::npos){
                    int randIdeal = 1 + rand() % 11;
                    if (randIdeal == 1){
                        ideals = "Greed. I will do whatever it takes to become wealthy.";
                    }
                    if (randIdeal == 2){
                        ideals = "Greed. I'm only in it for the money and fame.";
                    }
                    if (randIdeal == 3){
                        ideals = "Might. If I become strong, I can take what I want--what I deserve.";
                    }
                    if (randIdeal == 4){
                        ideals = "Greed. I'm only in it for the money.";
                    }
                    if (randIdeal == 5){
                        ideals = "Power. Solitude and contemplation are paths toward mystical or magical power.";
                    }
                    if (randIdeal == 6){
                        ideals = "Power. If I can attain more power, no one will tell me what to do.";
                    }
                    if (randIdeal == 7){
                        ideals = "Might. The strongest are meant to rule.";
                    }
                    if (randIdeal == 8){
                        ideals = "Power. Knowledge is the path to power and domination.";
                    }
                    if (randIdeal == 9){
                        ideals = "Master. I'm a predator, and the other ships on the sea are my prey.";
                    }
                    if (randIdeal == 10){
                        ideals = "Might. In life as in war, the stronger force wins.";
                    }
                    if (randIdeal == 11){
                        ideals = "Retribution. The rich need to be shown what life and death are like in the gutters.";
                    }
                }
            }
            else { ///Any
                int randIdeal = 1 + rand() % 13;
                if (randIdeal == 1){
                    ideals = "5. Aspiration. I seek to prove my self worthy of my god's favor by matching my actions against his or her teachings. (Any)";
                }
                if (randIdeal == 2){
                    ideals = "11. Aspiration. I'm determined to make something of myself. (Any)";
                }
                if (randIdeal == 3){
                    ideals = "23. Honesty. Art should reflect the soul; it should come from within and reveal who we really are. (Any)";
                }
                if (randIdeal == 4){
                    ideals = "29. Destiny. Nothing and no one can steer me away from my higher calling. (Any)";
                }
                if (randIdeal == 5){
                    ideals = "35. Aspiration. I work hard to be the best there is at my craft. (Any)";
                }
                if (randIdeal == 6){
                    ideals = "41. Self-Knowledge. If you know yourself, there're nothing left to know. (Any)";
                }
                if (randIdeal == 7){
                    ideals = "46. Family. Blood runs thicker than water. (Any)";
                }
                if (randIdeal == 8){
                    ideals = "53. Glory. I must earn glory in battle, for myself and my clan. (Any)";
                }
                if (randIdeal == 9){
                    ideals = "59. Self-improvement. The goal of a life of study is the betterment of oneself.";
                }
                if (randIdeal == 10){
                    ideals = "65. Aspiration. Someday I'll own my own ship and chart my own destiny. (Any)";
                }
                if (randIdeal == 11){
                    ideals = "71. Nation. My city, nation, or people are all that matter. (Any)";
                }
                if (randIdeal == 12){
                    ideals = "77. Aspiration. I'm going to prove that I'm worthy of a better life. (Any)";
                }
            }
    }
    else if (userOption == 'N'){
        cout << "Enter Ideals" << endl;
        getline (cin, ideals);
    }
}

void setLanguages(){
if (Race == "Aarakocra"){
    languages.push_back("Common");
    languages.push_back("Aarakocra");
    languages.push_back("Auran");
}
if (Race == "Aasimar"){
    languages.push_back("Common");
    languages.push_back("Celestial");
}
if (Race == "Animal-Hybrid"){
    languages.push_back("Common");
    languages.push_back("Elvish");
}
if (Race == "Bugbear"){
    languages.push_back("Common");
    languages.push_back("Goblin");
}
if (Race == "Centaur"){
    languages.push_back("Common");
    languages.push_back("Sylvan");
    languages.push_back("Elven");
}
if (Race == "Dragonborn"){
    languages.push_back("Common");
    languages.push_back("Draconic");
}
if (Race == "Dwarf"){
    languages.push_back("Common");
    languages.push_back("Dwarvish");
}
if (Race == "Loxodon"){
    languages.push_back("Common");
}
if (Race == "Elf"){
    languages.push_back("Common");
    languages.push_back("Elvish");
}
if (Race == "Firbolg"){
    languages.push_back("Common");
    languages.push_back("Elvish");
    languages.push_back("Giant");
}
if (Race == "Genasi"){
    languages.push_back("Common");
    languages.push_back("Primordial");
}
if (Race == "Gith"){
    languages.push_back("Common");
    languages.push_back("Gith");
}
if (Race == "Gnome"){
    languages.push_back("Common");
    languages.push_back("Gnomish");
}
if (Race == "Goblin"){
    int randNum = 1 + rand() % 2;
    if (randNum == 1){
        Alignment = Alignment + "Neutral";
    }
    if (randNum == 2){
        Alignment = Alignment + "Evil";
    }
}
if (Race == "Goliath"){
    languages.push_back("Common");
    languages.push_back("Giant");
}
if (Race == "Half-Elf"){
    languages.push_back("Common");
    languages.push_back("Elvish");
}
if (Race == "Half-Orc"){
    languages.push_back("Common");
    languages.push_back("Orc");
}
if (Race == "Halfling"){
    languages.push_back("Common");
    languages.push_back("Halfling");
}
if (Race == "Hobgoblin"){
    languages.push_back("Common");
    languages.push_back("Goblin");
}
if (Race == "Human"){
    languages.push_back("Common");
}
if (Race == "Kenku"){
    languages.push_back("Mimicry");
}
if (Race == "Kobold"){
    languages.push_back("Common");
    languages.push_back("Draconic");
}
if (Race == "Lizardfolk"){
    languages.push_back("Common");
    languages.push_back("Lizardfolk");
}
if (Race == "Minotaur"){
    languages.push_back("Common");
    languages.push_back("Sylvan");
}
if (Race == "Orc"){
    languages.push_back("Orc");
}
if (Race == "Yuan-Ti"){
    languages.push_back("Common");
    languages.push_back("Yuan-ti");
}
if (Race == "Tabaxi"){
    languages.push_back("Common");
    languages.push_back("Tabaxi");
}
if (Race == "Tiefling"){
    languages.push_back("Common");
    languages.push_back("Infernal");
}
if (Race == "Triton"){
    languages.push_back("Common");
    languages.push_back("Primordial");
}
if (Race == "Tortle"){
    languages.push_back("Common");
    languages.push_back("Aquan");
}
if (Race == "Vedalken"){
    languages.push_back("Common");
    languages.push_back("Vedalken");
}


}
