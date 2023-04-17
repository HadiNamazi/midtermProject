using namespace std;
#include <vector>
#include <iostream>
#include "Genome.h"
#include <algorithm>

// salavat

class Cell: private Genome{
protected:
    int chromosomeCounter = 0;
    vector<string*> dna;
    bool palindormMokammelTest(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != mokammel(s[s.length()-i-1])) {
                return false;
            }
        }
        return true;
    }
public:
    ~Cell(){}
    void setChromosome(Genome chromosome){
        chromosomeCounter++;
        dna.push_back(chromosome.getDna());
    }
    string getDna() const {
        return dna[chromosomeCounter-1][1];
    }
    string getDnaMokammel() const {
        return dna[chromosomeCounter-1][0];
    }
    void cellDeath(Cell cell) {
        int count = 0;
        int at = 0;
        int cg = 0;
        for (int i = 0; i < cell.getDna().length(); i++) {
            if (cell.getDna()[i] != mokammel(cell.getDnaMokammel()[i]))
                count++;
            if (cell.getDna()[i] == 'A' || cell.getDna()[i] == 'T')
                at++;
            else
                cg++;
            if (at > 3*cg || count > 5){
                cell.~Cell();
            }
        }
    }
    void bigMutation(string s1, int n, string s2, int m) { // TODO: bug dare
        size_t pos11 = dna[n][1].find(s1);
        size_t pos21 = dna[m][1].find(s2);
        size_t pos12 = dna[n][0].find(s1);
        size_t pos22 = dna[m][0].find(s2);
        string s1mokammel = "";
        string s2mokammel = "";
        for (int i = 0; i < s1.length(); i++)
            s1mokammel += mokammel(s1[i]);
        for (int i = 0; i < s2.length(); i++)
            s2mokammel += mokammel(s2[i]);
        if (pos11 < pos12){
            dna[n][1].replace(pos11, s1.length(), s2);
            dna[n][0].replace(pos11, s1.length(), s2mokammel);
        }
        else {
            dna[n][1].replace(pos12, s1.length(), s2mokammel);
            dna[n][0].replace(pos12, s1.length(), s2);
        }
        if (pos21 < pos22) {
            dna[m][1].replace(pos21, s2.length(), s1);
            dna[m][0].replace(pos21, s2.length(), s1mokammel);
        }
        else {
            dna[m][1].replace(pos22, s2.length(), s1mokammel);
            dna[m][0].replace(pos22, s2.length(), s1);
        }
        cout << dna[n][1] << endl << dna[m][1] << endl;
    }
    void smallMutation(char a, char c, int n, int m) {
        int counter = 0;
        for (int i = 0; i < dna[m][0].length(); i++){
            if (counter < n) {
                if (dna[m][0][i] == a || dna[m][1][i] == a) {
                    counter++;
                    if (dna[m][0][i] == a) {
                        dna[m][0][i] = c;
                        dna[m][1][i] = mokammel(c);
                    }
                    else {
                        dna[m][1][i] = c;
                        dna[m][0][i] = mokammel(c);
                    }
                }
            }
            else
                break;
        }
        cout << dna[m][0];
    }
    void reverseMutation(string s1, int n) {
        size_t pos1 = dna[n][1].find(s1);
        size_t pos2 = dna[n][0].find(s1);
        if (pos1 < pos2) {
            if (pos1 != string::npos) {
                string before0 = dna[n][1].substr(0, pos1);
                string after0 = dna[n][1].substr(pos1 + s1.length());
                string before1 = dna[n][0].substr(0, pos1);
                string after1 = dna[n][0].substr(pos1 + s1.length());
                string reversed_s1_mokammel = "";
                reverse(s1.begin(), s1.end());
                for (int i = 0; i < s1.length(); i++){
                    reversed_s1_mokammel += mokammel(s1[i]);
                }
                dna[n][1] = before0 + s1 + after0;
                dna[n][0] = before1 + reversed_s1_mokammel + after1;
            }
        }
        else {
            if (pos2 != string::npos) {
                string before1 = dna[n][0].substr(0, pos2);
                string after1 = dna[n][0].substr(pos2 + s1.length());
                string before0 = dna[n][1].substr(0, pos2);
                string after0 = dna[n][1].substr(pos2 + s1.length());
                reverse(s1.begin(), s1.end());
                string reversed_s1_mokammel = "";
                for (int i = 0; i < s1.length(); i++){
                    reversed_s1_mokammel += mokammel(s1[i]);
                }
                dna[n][0] = before1 + s1 + after1;
                dna[n][1] = before0 + reversed_s1_mokammel + after0;
            }
        }
        cout << dna[n][1] << endl << dna[n][0];
    }
    void palindormMokammel(int n) {
        for (int i = 0; i < dna[n][1].length(); i++) {
            for (int j = 4; j < dna[n][1].length(); j += 2) {
                if (palindormMokammelTest(dna[n][1].substr(i, j))) {
                    cout << dna[n][1].substr(i, j) << endl;
                }
            }
        }
    }
};
