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
	int numtel;
public:
	personne();
	personne(string np, string pr, string nais, string adr, int tel);
	virtual void saisir();
	virtual void afficher();
	virtual void sauvegarder(ofstream& fichier) const;
	virtual ~personne() {}
};

personne::personne() {
	nomp = " ";
	prenomp = " ";
	datenaissance = " ";
	adresse = " ";
	numtel = 0;
}

personne::personne(string np, string pr, string nais, string adr, int tel) {
	nomp = np;
	prenomp = pr;
	datenaissance = nais;
	adresse = adr;
	numtel = tel;
}

void personne::saisir() {
	cout << "Veuillez entrer votre nom: ";
	cin >> nomp;
	cout << "Veuillez entrer votre prenom: ";
	cin >> prenomp;
	cout << "Entrez votre date de naissance: ";
	cin >> datenaissance;
	cout << "Entrez votre adresse: ";
	cin >> adresse;
	cout << "Entrez numero de telephone: ";
	cin >> numtel;
}

void personne::afficher() {
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
	proprietaire(string np, string pr, string nais, string adr, int tel, string
		titrepropri, string notarie, string nombanq, string numbanq, string numfis)
		: personne(np, pr, nais, adr, tel) {
		titrepropriete = titrepropri;
		actenotarie = notarie;
		nombanque = nombanq;
		numbanquaire = numbanq;
		numfiscal = numfis;
	}
	void saisir() override;
	void afficher() override;
	void sauvegarder(ofstream& fichier) const override;
};

void proprietaire::saisir() {
	personne::saisir();
	cout << "Entrer le titre de votre propriete: ";
	cin >> titrepropriete;
	cout << "Entrer votre acte notarie: ";
	cin >> actenotarie;
	cout << "Entrer le nom de votre banque: ";
	cin >> nombanque;
	cout << "Entrer votre numero banquaire: ";
	cin >> numbanquaire;
	cout << "Entrer votre numero fiscal: ";
	cin >> numfiscal;
}

void proprietaire::afficher() {
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
	locataire(string np, string pr, string nais, string adr, int tel, string
		bullsalaire, string attestEmploi, string dernAvisImpos, string ancienpropri)
		: personne(np, pr, nais, adr, tel) {
		bulletinsalaire = bullsalaire;
		attestationEmploi = attestEmploi;
		dernierAvisImposition = dernAvisImpos;
		coordonneancienproprietaire = ancienpropri;
	}
	void saisir() override;
	void afficher() override;
	void sauvegarder(ofstream& fichier) const override;
};

locataire::locataire() : personne() {
	bulletinsalaire = " ";
	attestationEmploi = " ";
	dernierAvisImposition = " ";
	coordonneancienproprietaire = " ";
}

void locataire::saisir() {
	personne::saisir();
	cout << "Entrer le bulletin de salaire: ";
	cin >> bulletinsalaire;
	cout << "Entrer l'attestation de votre emploi: ";
	cin >> attestationEmploi;
	cout << "Entrer votre dernier avis d'imposition: ";
	cin >> dernierAvisImposition;
	cout << "Entrer les coordonnees de l'ancien proprietaire: ";
	cin >> coordonneancienproprietaire;
}

void locataire::afficher() {
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

class bienImmobilier {
private:
    string reference;
    string typeBien;
    string adresseBien;
    double superficie;
    double prix;

public:
    bienImmobilier() {
        reference = "";
        typeBien = "";
        adresseBien = "";
        superficie = 0.0;
        prix = 0.0;
    }

    bienImmobilier(string ref, string type, string adr, double sup, double pr) {
        reference = ref;
        typeBien = type;
        adresseBien = adr;
        superficie = sup;
        prix = pr;
    }

    void saisir() {
        cout << "Entrer le numéro de reference du bien: ";
        cin >> reference;
        cout << "Entrer le type du bien (Maison, Appartement ou Terrain ...): ";
        cin >> typeBien;
        cout << "Entrer l'adresse du bien: ";
        cin >> adresseBien;
        cout << "Entrer la superficie en m²: ";
        cin >> superficie;
        cout << "Entrer le prix du bien: ";
        cin >> prix;
    }

    void afficher() const {
        cout << "\n--- Bien Immobilier ---" << endl;
        cout << "Reference: " << reference << endl;
        cout << "Type: " << typeBien << endl;
        cout << "Adresse: " << adresseBien << endl;
        cout << "Superficie: " << superficie << " m²" << endl;
        cout << "Prix: " << prix << " FCFA" << endl;
    }

    void sauvegarder(ofstream& fichier) const {
        fichier << "BIENIMMOBILIER|" << reference << "|" << typeBien << "|" << adresseBien << "|" << superficie << "|" << prix << "\n";
    }
};

class contratLocation {
private:
    string numeroContrat;
    string dateDebut;
    string dateFin;
    double montantLoyer;
    double caution;
    string conditions;

public:
    contratLocation() {
        numeroContrat = "";
        dateDebut = "";
        dateFin = "";
        montantLoyer = 0.0;
        caution = 0.0;
        conditions = "";
    }

    contratLocation(string num, string debut, string fin, double loyer, double cau, string cond) {
        numeroContrat = num;
        dateDebut = debut;
        dateFin = fin;
        montantLoyer = loyer;
        caution = cau;
        conditions = cond;
    }

    void saisir() {
        cout << "Entrer le numéro du contrat: ";
        cin >> numeroContrat;
        cout << "Entrer la date de début (JJ/MM/AAAA): ";
        cin >> dateDebut;
        cout << "Entrer la date de fin (JJ/MM/AAAA): ";
        cin >> dateFin;
        cout << "Entrer le montant du loyer: ";
        cin >> montantLoyer;
        cout << "Entrer le montant de la caution: ";
        cin >> caution;
        cout << "Entrer les conditions de location: ";
        cin.ignore(); // pour éviter les problèmes avec getline
        getline(cin, conditions);
    }

    void afficher() const {
        cout << "\n--- Contrat de Location ---" << endl;
        cout << "Numéro contrat: " << numeroContrat << endl;
        cout << "Date début: " << dateDebut << endl;
        cout << "Date fin: " << dateFin << endl;
        cout << "Montant loyer: " << montantLoyer << " FCFA" << endl;
        cout << "Caution: " << caution << " FCFA" << endl;
        cout << "Conditions: " << conditions << endl;
    }

    void sauvegarder(ofstream& fichier) const {
        fichier << "CONTRATLOCATION|" << numeroContrat << "|" << dateDebut << "|" << dateFin << "|" << montantLoyer << "|" << caution << "|" << conditions << "\n";
    }
};


int main() {
	proprietaire pro1_test;
	locataire loc1_test;
	bienImmobilier bien1;
	contratLocation contrat1;

	ofstream fichier("donnees.txt", ios::app);
	
	int n;

	do {
		cout << "\n------------MENU------------" << endl;
		cout << " 1- Pour entrer les donnees du proprietaire" << endl;
		cout << " 2- Pour entrer les donnees du locataire" << endl;
		cout << " 3- Pour afficher les donnees du proprietaire" << endl;
		cout << " 4- Pour afficher les donnees du locataire" << endl;
		cout << " 5- Pour ajouter un bien immobilier" <<endl;
		cout << " 6- Pour afficher le bien immobilier" <<endl;
		cout << " 7- Pour entrer les donnees du contrat de location" << endl;
		cout << " 8- Pour afficher le contrat de location" << endl;
		cout << " 9- pour quitter" << endl;
		cout << "Veuillez choisir une option: ";
		cin >> n;

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
			bien1.saisir();
			bien1.sauvegarder(fichier);
			cout<< "\nBien Immobilier enrégistrees." << endl;
			break;
		case 6:
			bien1.afficher();
			break;
		case 7:
			contrat1.saisir();
			contrat1.sauvegarder(fichier);
			cout << "\nContrat de location enregistree." << endl;
			break;
		case 8:
			contrat1.afficher();
			break;
		
		case 9:
			break;
			
		default:
			cout << "Veuillez entrer une valeur correcte (1-9)." << endl;
		}
	} while (n!=9);

	fichier.close();
	return 0;
}
