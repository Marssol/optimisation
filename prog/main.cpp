#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int tabIdNoeuds[37], tabAltitude[37], tabIdArc[95], tabNoeudDepartArrive[97][97];
    string tabNomNoeuds[37], tabNomArc[97], tabTypeArc[97];
    ifstream fichier ("dataski.txt",ios::in);
    int nbTrajet;

    for(int j=0; j<37;j++)
        tabIdNoeuds[j]=0;

    if(fichier) {
        string line;
            int i=0;
        while(getline(fichier,line)){
            if(i<37) {
            fichier >> tabIdNoeuds[i] >> tabNomNoeuds[i] >> tabAltitude[i];
            }
            if(i=37) {
            fichier >> nbTrajet;
            //cout << nbTrajet;
            }
            if(i>37 && i<134) {
                fichier >> tabIdArc[i-38] >> tabNomArc[i-38] >> tabTypeArc[i-38] >> tabNoeudDepartArrive[i-38][0]>> tabNoeudDepartArrive[i-38][1];
                //cout <<  tabIdArc[i-38] << tabNomArc[i-38] << tabNoeudDepartArrive[i-38][0] << tabNoeudDepartArrive[i-38][1];
            }
            //cout << tabIdNoeuds[i]<< " " << tabNomNoeuds[i] << endl;
            //cout << nbTrajet;
            cout <<  tabIdArc[i-38] << tabNomArc[i-38] << tabNoeudDepartArrive[i-38][0] << tabNoeudDepartArrive[i-38][1];
            i++;
        }
    }

    else
        cerr << "Impossible d'ouvrir le fichier" << endl;
    return 0;
}

