#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "Functions.h"
#include "User.h"

using namespace std;

//Set function
void User::setName(string name) {
	this->name = name;
}
void User::setVarsta(int varsta) {
	this->varsta = varsta;
}
void User::setInaltime(double inaltime) {
	this->inaltime = inaltime;
}
void User::setGreutate(double greutate) {
	this->greutate = greutate;
}
void User::setScop(int scop) {
	this->scop = scop;
}
void User::setMetabolism(int metabolism) {
	this->metabolism = metabolism;
}
void User::setTip_activitate_fizica(int activitate_fizica) {
	tip_activitate_fizica = activitate_fizica;
}
void User::setSex(int sex) {
	this->sex = sex;
}

void User::setGreutateDorita(int greutate_dorita) {
	this->greutate_dorita = greutate_dorita;
}

	//Set User Stats
void User::setUsersStats(User* user, ifstream& in_file, int size) {
	string line;
	char c;
	int i = 0;
	in_file.open("Users.txt");
	if (!in_file) {
		cout << "Error" << endl;
	}
	else {
		while (i != size) {
			in_file.get(c);
			line.push_back(c);
			//Set Name
			if (line == "Nume: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(user + i)->setName(line);
				line.clear();
			}
			//SET VARSTA
			if (line == "Varsta: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(user + i)->setVarsta(stoi(line));
				line.clear();
			}
			//SET INALTIME
			if (line == "Inaltime: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(user + i)->setInaltime(stoi(line));
				line.clear();
			}
			//Set Greutate
			if (line == "Greutate: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(user + i)->setGreutate(stoi(line));
				line.clear();
			}
			//Set Scop
			if (line == "Scop: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Scadere") {
					line = '1';
					(user + i)->setScop(stoi(line));
					line.clear();
				}
				else if (line == "Mentinere") {
					line = '2';
					(user + i)->setScop(stoi(line));
					line.clear();
				}
				else if (line == "Crestere") {
					line = '3';
					(user + i)->setScop(stoi(line));
					line.clear();
				}
			}
			//Set Metabolism
			if (line == "Metabolism: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Rapid") {
					line = '1';
					(user + i)->setMetabolism(stoi(line));
					line.clear();
				}
				else if (line == "Normal") {
					line = '2';
					(user + i)->setMetabolism(stoi(line));
					line.clear();
				}
				else if (line == "Lent") {
					line = '3';
					(user + i)->setMetabolism(stoi(line));
					line.clear();
				}
			}
			//Set Activitate Fizica
			if (line == "Activitate Fizica: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Sedentar") {
					line = '1';
					(user + i)->setTip_activitate_fizica(stoi(line));
					line.clear();
				}
				else if (line == "Usoara") {
					line = '2';
					(user + i)->setTip_activitate_fizica(stoi(line));
					line.clear();
				}
				else if (line == "Moderata") {
					line = '3';
					(user + i)->setTip_activitate_fizica(stoi(line));
					line.clear();
				}
				else if (line == "Intensa") {
					line = '4';
					(user + i)->setTip_activitate_fizica(stoi(line));
					line.clear();
				}
			}
			//Set Greutate Dorita
			if (line == "Greutate Dorita: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(user + i)->setGreutateDorita(stoi(line));
				line.clear();
			}
			//Set Sex
			if (line == "Sex: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Male") {
					line = '1';
					(user + i)->setSex(stoi(line));
					line.clear();
				}
				else if (line == "Female") {
					line = '2';
					(user + i)->setSex(stoi(line));
					line.clear();
				}
				getline(in_file, line);
				line.clear();
				i++;
			}

		}
	}
	in_file.close();
}
void User::setUsersStats(ifstream& in_file) {
	string line;
	int size = 1;
	char c;
	int i = 0;
	in_file.open("Users.txt");
	if (!in_file) {
		cout << "Error" << endl;
	}
	else {
		while (i != size) {
			in_file.get(c);
			line.push_back(c);
			//Set Name
			if (line == "Nume: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				name = line;
				line.clear();
			}
			//SET VARSTA
			if (line == "Varsta: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				varsta = stoi(line);
				line.clear();
			}
			//SET INALTIME
			if (line == "Inaltime: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				inaltime= stoi(line);
				line.clear();
			}
			//Set Greutate
			if (line == "Greutate: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				greutate= stoi(line);
				line.clear();
			}
			//Set Scop
			if (line == "Scop: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Scadere") {
					line = '1';
					scop = stoi(line);
					line.clear();
				}
				else if (line == "Mentinere") {
					line = '2';
					scop = stoi(line);
					line.clear();
				}
				else if (line == "Crestere") {
					line = '3';
					scop = stoi(line);
					line.clear();
				}
			}
			//Set Metabolism
			if (line == "Metabolism: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Rapid") {
					line = '1';
					metabolism = stoi(line);
					line.clear();
				}
				else if (line == "Normal") {
					line = '2';
					metabolism = stoi(line);
					line.clear();
				}
				else if (line == "Lent") {
					line = '3';
					metabolism = stoi(line);
					line.clear();
				}
			}
			//Set Activitate Fizica
			if (line == "Activitate Fizica: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Sedentar") {
					line = '1';
					tip_activitate_fizica = stoi(line);
					line.clear();
				}
				else if (line == "Usoara") {
					line = '2';
					tip_activitate_fizica = stoi(line);
					line.clear();
				}
				else if (line == "Moderata") {
					line = '3';
					tip_activitate_fizica = stoi(line);
					line.clear();
				}
				else if (line == "Intensa") {
					line = '4';
					tip_activitate_fizica = stoi(line);
					line.clear();
				}
			}
			//Set Greutate Dorita
			if (line == "Greutate Dorita: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				greutate_dorita = stoi(line);
				line.clear();
			}
			//Set Sex
			if (line == "Sex: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				if (line == "Male") {
					line = '1';
					sex = stoi(line);
					line.clear();
				}
				else if (line == "Female") {
					line = '2';
					sex = stoi(line);
					line.clear();
				}
				getline(in_file, line);
				line.clear();
				i++;
			}

		}
	}
	in_file.close();
}

//Create Users
void User::createUser(ofstream& file, int size) {
	string line;
	string input;
	
	file.open("Users.txt", fstream::app);
	if (!file) {
		cout << "Error" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			//Nume
			cout << "Nume: ";
			cin.ignore();
			getline(cin, input);
			line = "Nume: " + input;
			file << line;
			clearStrings(&input, &line);
			system("cls");

			//Varsta
			cout << "Varsta: ";
			cin >> input;
			line = "Varsta: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Inaltime
			cout << "Inaltime: ";
			cin >> input;
			line = "Inaltime: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Greutate
			cout << "Greutate: ";
			cin >> input;
			line = "Greutate: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Scop
			cout << "Scopul" << endl;
			cout << "1.Scadere\n2.Mentinere\n3.Crestere" << endl;
			cin >> input;
			if (stoi(input) == 1) {
				line = "Scop: Scadere";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Scop: Mentinere";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Scop: Crestere";
				file << endl << line;
				line.clear();
			}
			system("cls");

			//Metabolism
			cout << "Metabolism" << endl;
			cout << "1.Rapid\n2.Normal\n3.Lent" << endl;
			cin >> input;
			if (stoi(input) == 1) {
				line = "Metabolism: Rapid";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Metabolism: Normal";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Metabolism: Lent";
				file << endl << line;
				line.clear();
			}
			system("cls");

			//Tip Activitate Fizica
			cout << "Activitate Fizica" << endl;
			cout << "1.Sedentar\n2.Usoara\n3.Moderata\n4.Intensa" << endl;
			cin >> input;
			if (stoi(input) == 1) {
				line = "Activitate Fizica: Sedentar";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Activitate Fizica: Usoara";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Activitate Fizica: Moderata";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 4) {
				line = "Activitate Fizica: Intensa";
				file << endl << line;
				line.clear();
			}
			system("cls");
			//Greutate Dorita
			cout << "Greutate Dorita: ";
			cin >> input;
			line = "Greutate Dorita: " + input;
			file << endl << line;
			clearStrings(&line, &input);
			system("cls");

			//Sex
			cout << "Sex: " << endl;
			cout << "1.Male\n2.Female" << endl;
			cin >> input;
			if (stoi(input) == 1) {
				line = "Sex: Male";
				file << endl << line;
				line.clear();
			}
			else if (stoi(input) == 2) {
				line = "Sex: Female";
				file << endl << line;
				line.clear();
			}
			file << endl << "*********************************************" << endl;
			clearStrings(&input, &line);
			system("cls");
		}
	}
	file.close();
}

//Edti user in file
void User::editUser(ofstream& file,int choice) {
	string line;
	string input;
	if (choice == 1) {
		cout << "Nume: ";
		cin.ignore();
		getline(cin, line);
		name = line;
	}
	if (choice == 2) {
		cout << "Varsta: ";
		cin >> line;
		varsta = stoi(line);
	}
	if (choice == 3) {
		cout << "Inaltime: ";
		cin >> line;
		inaltime = stoi(line);
	}
	if (choice == 4) {
		cout << "Greutate: ";
		cin >> line;
		greutate = stoi(line);
	}
	if (choice == 5) {
		cout << "Scopul" << endl;
		cout << "1.Scadere\n2.Mentinere\n3.Crestere" << endl;
		cin >> line;
		scop = stoi(line);
	}
	if (choice == 6) {
		cout << "Metabolism" << endl;
		cout << "1.Rapid\n2.Normal\n3.Lent" << endl;
		cin >> line;
		metabolism = stoi(line);
	}
	if (choice == 7) {
		cout << "Activitate Fizica" << endl;
		cout << "1.Sedentar\n2.Usoara\n3.Moderata\n4.Intensa" << endl;
		cin >> line;
		tip_activitate_fizica = stoi(line);
	}
	if (choice == 8) {
		cout << "Greutate dorita: ";
		cin >> line;
		greutate_dorita = stoi(line);
	}
	if (choice == 9) {
		cout << "Sex: " << endl;
		cout << "1.Male\n2.Female" << endl;
		cin >> line;
		sex = stoi(line);
	}

	file.open("Users.txt");
	if (!file) {
		cout << "Error" << endl;
	}
	else {
			//Nume
			input = name;
			line = "Nume: " + input;
			file << line;
			clearStrings(&input, &line);
			system("cls");

			//Varsta
			input = to_string(varsta);
			line = "Varsta: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Inaltime
			input = to_string(inaltime);
			line = "Inaltime: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Greutate
			input = to_string(greutate);
			line = "Greutate: " + input;
			file << endl << line;
			clearStrings(&input, &line);
			system("cls");

			//Scop
			input = to_string(scop);
			if (stoi(input) == 1) {
				line = "Scop: Scadere";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Scop: Mentinere";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Scop: Crestere";
				file << endl << line;
				line.clear();
			}
			system("cls");

			//Metabolism
			input = to_string(metabolism);
			if (stoi(input) == 1) {
				line = "Metabolism: Rapid";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Metabolism: Normal";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Metabolism: Lent";
				file << endl << line;
				line.clear();
			}
			system("cls");

			//Tip Activitate Fizica
			input = to_string(tip_activitate_fizica);
			if (stoi(input) == 1) {
				line = "Activitate Fizica: Sedentar";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 2) {
				line = "Activitate Fizica: Usoara";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 3) {
				line = "Activitate Fizica: Moderata";
				file << endl << line;
				line.clear();
			}
			if (stoi(input) == 4) {
				line = "Activitate Fizica: Intensa";
				file << endl << line;
				line.clear();
			}
			system("cls");
			//Greutate Dorita
			input = to_string(greutate_dorita);
			line = "Greutate Dorita: " + input;
			file << endl << line;
			clearStrings(&line, &input);
			system("cls");

			//Sex
			input = to_string(sex);
			if (stoi(input) == 1) {
				line = "Sex: Male";
				file << endl << line;
				line.clear();
			}
			else if (stoi(input) == 2) {
				line = "Sex: Female";
				file << endl << line;
				line.clear();
			}
			file << endl << "*********************************************" << endl;
			clearStrings(&input, &line);
			system("cls");
	}
	file.close();
}
//Diplay User
void User::displayUsers() {
		cout << "1.Name: " << name << endl;
		cout << "2.Varsta: " << varsta << endl;
		cout << "3.Inaltime: " << inaltime << endl;
		cout << "4.Greutate: " << greutate << endl;
		//Display Scop
		if (scop == 1) {
			cout << "5.Scop: Scadere" << endl;
		}
		else if (scop == 2) {
			cout << "5.Scop: Mentinere" << endl;
		}
		else if (scop == 3) {
			cout << "5.Scop: Crestere" << endl;
		}
		//Display Metabolsim
		if (metabolism == 1) {
			cout << "6.Metabolism: Rapid" << endl;
		}
		else if (metabolism == 2) {
			cout << "6.Metabolism: Normal" << endl;
		}
		else if (metabolism == 3) {
			cout << "6.Metabolism: Lent" << endl;
		}

		//Display Activitate fizica
		if (tip_activitate_fizica == 1) {
			cout << "7.Activitate Fizica: Sedentar" << endl;
		}
		else if (tip_activitate_fizica == 2) {
			cout << "7.Activitate Fizica: Usoara" << endl;
		}
		else if (tip_activitate_fizica == 3) {
			cout << "7.Activitate Fizica: Moderata" << endl;
		}
		else if (tip_activitate_fizica == 4) {
			cout << "7.Activitate Fizica: Intensa" << endl;
		}

		cout << "8.Greutate dorita: " << greutate_dorita << endl;

		//Display Sex
		if (sex == 1) {
			cout << "9.Sex: Male" << endl;
		}
		else if (sex == 2) {
			cout << "9.Sex: Female" << endl;
		}
}

//Get function
string User::getName() { return name; }
int User::getVarsta() { return varsta; }
double User::getInaltime() { return inaltime; }
double User::getGreutate() { return greutate; }
int User::getScop() { return scop; }
int User::getMetabolism() { return metabolism; }
int User::getGreutateDorita() { return greutate_dorita; }
int User::getTip_activitate_fizica() { return tip_activitate_fizica; }
int User::getSex() { return sex; }

//BMI CALCULATOR
void User::CalculateBmi() {
	double bmi_calc;
	double height = pow(inaltime / 100,2);
	bmi_calc = greutate / height;
	if (bmi_calc < 18.5) {
		cout << "Greutate underweight" << endl;
	}
	if ((bmi_calc >= 18.5) && (bmi_calc <= 24.9)) {
		cout << "Greutate normala" << endl;

	}
	if ((bmi_calc >= 25) && (bmi_calc <= 29.9)) {
		cout << "Greutate overweight" << endl;
	}
	if ((bmi_calc >= 30) && (bmi_calc <= 34.9)) {
		cout << "Greutate obese" << endl;
	}
	if (bmi_calc > 35) {
		cout << "Greutate obese xtreme" << endl;
	}

}

//Calculate BMR
int User::calculateBMR() {
 int bmr{};						
 if (scop == 2) {
	 if (sex == 1) {
		 bmr = 88.362 + (13.397 * greutate) + (4.799 * inaltime) - (5.667 * varsta);
		 
	 }else if (sex == 2) {
		 bmr = 447.593 + (9.247 * greutate) + (3.098 * inaltime) - (4.330 * varsta);
		
	 }
	 if (tip_activitate_fizica == 1) {
		 return bmr * 1.2;
	 }
	 else if (tip_activitate_fizica == 2) {
		 return bmr * 1.375;
	 }
	 else if (tip_activitate_fizica == 3) {
		 return bmr * 1.55;
	 }
	 else if (tip_activitate_fizica == 4) {
		 return bmr * 1.725;
	 }
	 
 }
 else
 {
	 if (sex == 1) {
		 bmr = 88.362 + (13.397 * greutate_dorita) + (4.799 * inaltime) - (5.667 * varsta);
		
	 }
	 else if (sex == 2) {
		 bmr = 447.593 + (9.247 * greutate_dorita) + (3.098 * inaltime) - (4.330 * varsta);
		 
	 }
	 if (tip_activitate_fizica == 1) {
		 return bmr * 1.2;
	 }
	 else if (tip_activitate_fizica == 2) {
		 return bmr * 1.375;
	 }
	 else if (tip_activitate_fizica == 3) {
		 return bmr * 1.55;
	 }
	 else if (tip_activitate_fizica == 4) {
		 return bmr * 1.725;
	 }
 }

	
	return 0;
}

//Constructor incomplet
//User::User(string name="NONE", int varsta=0, double inaltim=0, double greutate, int scop, int metabolism, int greutate_dorita, int tip_activitate, int sex) : name{name} {
//}
