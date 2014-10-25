#include <iostream>
#include <string>
#include <cstdio>

#define TRUE 1
#define FALSE !TRUE

using namespace std;

static bool is_uniq(string s) {
    bool* find = new bool[256];
    for (int i=0; i <= s.length(); i++) {
        int value = s[i];
        if (find[value]) return FALSE;
        find[value] = TRUE;
    }
    return TRUE;
};

static bool is_uniq_bit(string s) {
    int find = 0;
    for (int i=0; i<= s.length(); i++){
        if (find & (1 << (s[i] - 'a'))) return FALSE;
        find |= (1 << (s[i] - 'a'));
    }
    return TRUE;
}

static void sort_string(string& s, int left, int right) {
    int i = left, j = right;
    char pivot = s[(left + right)/2];
    char temp;

    while (i <= j) {
        while (s[i] < pivot)
            i++;
        while (s[j] > pivot)
            j--;
        
        if (i <= j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    
    if (i < right)
        sort_string(s, i, right);
    if (j > left)
        sort_string(s, left, j);

}

static bool is_uniq_sort(string s) {
    sort_string(s, 0, (s.length() - 1));
    for (int i=0; i<= (s.length() - 1); i++){
        if (s[i] == s[i + 1]) return FALSE;
    }
    return TRUE;
}

int main(int argc, char* argv[]) {

    if (argc <= 1 && argc >= 2) {
        perror("need one parameter");
        return 1;
    }
    
    string input(argv[1]);


    if (is_uniq(input))
        cout << "no dup in space version"<< endl;
    else
        cout << "dup in space version" << endl;

    if (is_uniq_bit(input))
        cout << "no dup in bit version"<< endl;
    else
        cout << "dup in bit version" << endl;

    if (is_uniq_sort(input))
        cout << "no dup in sort version"<< endl;
    else
        cout << "dup in srt version" << endl;

    return 0;
}
