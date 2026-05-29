#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class personne {
protected:
	string nomp;
	string prenomp;
	string datenaissance;
	string adresse;
	string numtel;
public:
	personne();
	personne(string np, string pr, string nais, string adr, string tel);
	virtual void saisir();
	virtual void afficher() const;
	virtual void sauvegarder(ofstream& fichier) const;
	virtual ~personne() {}
};

personne::personne() {
	nomp = "";
	prenomp = "";
	datenaissance = "";
	adresse = "";
	numtel = "";
}

personne::personne(string np, string pr, string nais, string adr, string tel) {
	nomp = np;
	prenomp = pr;
	datenaissance = nais;
	adresse = adr;
	numtel = tel;
}

void personne::saisir() {
	cout << "Veuillez entrer votre nom: ";
	getline(cin >> ws, nomp);
	cout << "Veuillez entrer votre prenom: ";
	getline(cin >> ws, prenomp);
	cout << "Entrez votre date de naissance: ";
	getline(cin >> ws, datenaissance);
	cout << "Entrez votre adresse: ";
	getline(cin >> ws, adresse);
	cout << "Entrez numero de telephone: ";
	getline(cin >> ws, numtel);
}

void personne::afficher() const {
	cout << "Mr/Mme " << nomp << " " << prenomp << endl;
	cout << "Ne(e) le: " << datenaissance << endl;
	cout << "A: " << adresse << endl;
	cout << "Numero telephonique: " << numtel << endl;
}

void personne::sauvegarder(ofstream& fichier) const {
	fichier << nomp << "|" << prenomp << "|" << datenaissance << "|" << adresse << "|" << numtel << "|";
}

class proprietaire : public personne {
private:
	string titrepropriete;
	string actenotarie;
	string nombanque;
	string numbanquaire;
	string numfiscal;
public:
	proprietaire() : personne() {
		titrepropriete = "";
		actenotarie = "";
		nombanque = "";
		numbanquaire = "";
		numfiscal = "";
	}
	proprietaire(string np, string pr, string nais, string adr, string tel, string
		titrepropri, string notarie, string nombanq, string numbanq, string numfis)
		: personne(np, pr, nais, adr, tel) {
		titrepropriete = titrepropri;
		actenotarie = notarie;
		nombanque = nombanq;
		numbanquaire = numbanq;
		numfiscal = numfis;
	}
	void saisir() override;
	void afficher() const override;
	void sauvegarder(ofstream& fichier) const override;
};

void proprietaire::saisir() {
	personne::saisir();
	cout << "Entrer le titre de votre propriete: ";
	getline(cin >> ws, titrepropriete);
	cout << "Entrer votre acte notarie: ";
	getline(cin >> ws, actenotarie);
	cout << "Entrer le nom de votre banque: ";
	getline(cin >> ws, nombanque);
	cout << "Entrer votre numero banquaire: ";
	getline(cin >> ws, numbanquaire);
	cout << "Entrer votre numero fiscal: ";
	getline(cin >> ws, numfiscal);
}

void proprietaire::afficher() const {
	personne::afficher();
	cout << "\n--- Details Propriete ---" << endl;
	cout << "Propriete: " << titrepropriete << endl;
	cout << "Acte: " << actenotarie << endl;
	cout << "Banque: " << nombanque << endl;
	cout << "Numero banquaire: " << numbanquaire << endl;
	cout << "Numero fiscal: " << numfiscal << endl;
}

void proprietaire::sauvegarder(ofstream& fichier) const {
	fichier << "PROPRIETAIRE|";
	personne::sauvegarder(fichier);
	fichier << titrepropriete << "|" << actenotarie << "|" << nombanque << "|" << numbanquaire << "|" << numfiscal << "\n";
}

class locataire : public personne {
private:
	string bulletinsalaire;
	string attestationEmploi;
	string dernierAvisImposition;
	string coordonneancienproprietaire;
public:
	locataire();
	locataire(string np, string pr, string nais, string adr, string tel, string
		bullsalaire, string attestEmploi, string dernAvisImpos, string ancienpropri)
		: personne(np, pr, nais, adr, tel) {
		bulletinsalaire = bullsalaire;
		attestationEmploi = attestEmploi;
		dernierAvisImposition = dernAvisImpos;
		coordonneancienproprietaire = ancienpropri;
	}
	void saisir() override;
	void afficher() const override;
	void sauvegarder(ofstream& fichier) const override;
};

locataire::locataire() : personne() {
	bulletinsalaire = "";
	attestationEmploi = "";
	dernierAvisImposition = "";
	coordonneancienproprietaire = "";
}

void locataire::saisir() {
	personne::saisir();
	cout << "Entrer le bulletin de salaire: ";
	getline(cin >> ws, bulletinsalaire);
	cout << "Entrer l'attestation de votre emploi: ";
	getline(cin >> ws, attestationEmploi);
	cout << "Entrer votre dernier avis d'imposition: ";
	getline(cin >> ws, dernierAvisImposition);
	cout << "Entrer les coordonnees de l'ancien proprietaire: ";
	getline(cin >> ws, coordonneancienproprietaire);
}

void locataire::afficher() const {
	personne::afficher();
	cout << "\n--- Details Location ---" << endl;
	cout << "Bulletin salaire: " << bulletinsalaire << endl;
	cout << "Attestation emploi: " << attestationEmploi << endl;
	cout << "Avis imposition: " << dernierAvisImposition << endl;
	cout << "Ancien proprietaire: " << coordonneancienproprietaire << endl;
}

void locataire::sauvegarder(ofstream& fichier) const {
	fichier << "LOCATAIRE|";
	personne::sauvegarder(fichier);
	fichier << bulletinsalaire << "|" << attestationEmploi << "|" << dernierAvisImposition << "|" << coordonneancienproprietaire << "\n";
}

int main() {
	proprietaire pro1_test;
	locataire loc1_test;
	ofstream fichier("donnees.txt", ios::app);

	if (!fichier.is_open()) {
		cerr << "Erreur: impossible d'ouvrir le fichier de sauvegarde." << endl;
		return 1;
	}

	int n = 0;

	do {
		cout << "\n------------MENU------------" << endl;
		cout << " 1- Pour entrer les donnees du proprietaire" << endl;
		cout << " 2- Pour entrer les donnees du locataire" << endl;
		cout << " 3- Pour afficher les donnees du proprietaire" << endl;
		cout << " 4- Pour afficher les donnees du locataire" << endl;
		cout << " 5- Pour quitter" << endl;
		cout << "Veuillez choisir une option: ";
		if (!(cin >> n)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrée invalide." << endl;
			continue;
		}

		switch (n) {
		case 1:
			pro1_test.saisir();
			pro1_test.sauvegarder(fichier);
			cout << "\nDonnees Proprietaire enregistrees." << endl;
			break;
		case 2:
			loc1_test.saisir();
			loc1_test.sauvegarder(fichier);
			cout << "\nDonnees Locataire enregistrees." << endl;
			break;
		case 3:
			pro1_test.afficher();
			break;
		case 4:
			loc1_test.afficher();
			break;
		case 5:
			cout << "Bye." << endl;
			break;
		default:
			cout << "Veuillez entrer une valeur correcte (1-5)." << endl;
		}
	} while (n != 5);

	fichier.close();
	return 0;
}