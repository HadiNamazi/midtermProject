using namespace std;
#include <iostream>
#include <algorithm>

class Genome {
private:
    string rna;
    string dna[2];
protected:
    char mokammel(char c) {
        switch (c) {
            case 'A':
                return 'T';
            case 'T':
                return 'A';
            case 'C':
                return 'G';
            case 'G':
                return 'C';
        }
    }

public:
    void setRna(string rna){
        this->rna = rna;
    }
    void setDna(string dna[2]){
        this->dna[0] = dna[0];
        this->dna[1] = dna[1];
    }
    string getRna() {
        return rna;
    }
    string* getDna() {
        return dna;
    }
    void dnaGenerator(){
        // TODO: motmaen nistam manzooresh hamine ya na
        for (int i = 0; i < dna[0].length(); i++){
            cout << mokammel(dna[0][i]);
        }
    }
    void smallMutation(char a, char c, int n){
        // rna
        int counter = 0;
        for (int i = 0; i < rna.length(); i++){
            if (counter < n) {
                if (rna[i] == a) {
                    counter++;
                    rna[i] = c;
                }
            }
            else
                break;
        }
        // dna
        counter = 0;
        for (int i = 0; i < dna[0].length(); i++){
            if (counter < n) {
                if (dna[0][i] == a || dna[1][i] == a) {
                    counter++;
                    if (dna[0][i] == a) {
                        dna[0][i] = c;
                        dna[1][i] = mokammel(c);
                    }
                    else {
                        dna[1][i] = c;
                        dna[0][i] = mokammel(c);
                    }
                }
            }
            else
                break;
        }
    }
    // TODO: learn it
    void bigMutation(const string s1, const string s2){
        // rna
        size_t pos = rna.find(s1);
        if (pos != string::npos) {
            rna.replace(pos, s1.length(), s2);
        }
        // dna
        size_t pos1 = dna[0].find(s1);
        size_t pos2 = dna[1].find(s1);
        string s2_mokammel = "";
        for (int i = 0; i < s2.length(); i++){
            s2_mokammel += mokammel(s2[i]);
        }
        if (pos1 < pos2) {
            if (pos1 != string::npos) {
                dna[0].replace(pos, s1.length(), s2);
                dna[1].replace(pos, s1.length(), s2_mokammel);
            }
        }
        else {
            if (pos2 != string::npos) {
                dna[1].replace(pos, s1.length(), s2);
                dna[0].replace(pos, s1.length(), s2_mokammel);
            }
        }
    }
    // TODO: learn it
    void reverseMutation(string s1) {
        // rna
        size_t pos = rna.find(s1);
        if (pos != string::npos) {
            string before = rna.substr(0, pos);
            string after = rna.substr(pos + s1.length());
            reverse(s1.begin(), s1.end());
            rna = before + s1 + after;
        }
        // dna
        reverse(s1.begin(), s1.end());
        size_t pos1 = dna[1].find(s1);
        size_t pos2 = dna[0].find(s1);
        if (pos1 < pos2) {
            if (pos1 != string::npos) {
                string before0 = dna[1].substr(0, pos1);
                string after0 = dna[1].substr(pos1 + s1.length());
                string before1 = dna[0].substr(0, pos1);
                string after1 = dna[0].substr(pos1 + s1.length());
                string reversed_s1_mokammel = "";
                reverse(s1.begin(), s1.end());
                for (int i = 0; i < s1.length(); i++){
                    reversed_s1_mokammel += mokammel(s1[i]);
                }
                dna[1] = before0 + s1 + after0;
                dna[0] = before1 + reversed_s1_mokammel + after1;
            }
        }
        else {
            if (pos2 != string::npos) {
                string before1 = dna[0].substr(0, pos2);
                string after1 = dna[0].substr(pos2 + s1.length());
                string before0 = dna[1].substr(0, pos2);
                string after0 = dna[1].substr(pos2 + s1.length());
                reverse(s1.begin(), s1.end());
                string reversed_s1_mokammel = "";
                for (int i = 0; i < s1.length(); i++){
                    reversed_s1_mokammel += mokammel(s1[i]);
                }
                dna[0] = before1 + s1 + after1;
                dna[1] = before0 + reversed_s1_mokammel + after0;
            }
        }
    }
};
