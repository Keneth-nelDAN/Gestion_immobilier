#include <iostream>
#include<string >
using namespace std;
class personne {
	private:
		string nomp;
		string prenomp;
		string datenaissance;
		string adresse;
		int numtel;
	public :
		personne();
		personne (string np ,string pr ,string nais ,string adr ,int tel);
		void saisir ();
		void afficher ();
};
	
	personne::personne (){
		nomp=" ";
		prenomp=" ";
		datenaissance=" ";
		adresse=" ";
		numtel=0;		
	}
	personne::personne (string np ,string pr ,string nais ,string adr ,int tel){
		nomp=np;
		prenomp=pr;
		datenaissance=nais;
		adresse=adr;
		numtel=tel;
	}
	void personne::saisir(){
		cout<<"veillez entrer votre nom: ";
		cin>>nomp;
		cout<<"veillez entrer votre prenom: ";
		cin>>prenomp;
		cout<<"Entrez votre date de naissance: ";
		cin>>datenaissance;
		cout<<"Entrez votre adresse: ";
		cin>>adresse;
		cout<<"Entrez numero de telephone: ";
		cin>>numtel;
	}
	void personne::afficher(){
		cout<<"Mr/Mme "<<nomp<<" ";
		cout<<" "<<prenomp<<" ";
		cout<<"ne(e) le: "<<datenaissance<<" ";
		cout<<"à: "<<adresse<<" ";
		cout<<"Enregister sous le numero telephonique: "<<numtel<<" ";
	}
class propietaire {
	private:
		string titrepropriete;
		string actenotarie;
		string nombanque;
		string numbanquaire;
		string numfiscal;
};

class locataire {
	private:
		string bulletinsalaire;
		string attestationEmploi;
		string dernierAvisImposition;
		string coordonneancienproprietaire;
};

		
  int main(){
	personne p1;
	p1.saisir();
	p1.afficher();
	return 20;
}