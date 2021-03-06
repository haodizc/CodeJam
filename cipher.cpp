#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int char_to_num(char c) {
    return c - 65;
}

string solution_two(string ciphertext, string plaintext);

int main() {
    // Redirect file to stdin
    ifstream ifs("input/A-large-practice.in.txt");
    cin.rdbuf(ifs.rdbuf());
    ofstream ofs("onput/output-L.txt");
    cout.rdbuf(ofs.rdbuf());

    int count = 0;
    cin >> count;

    while (count-- > 0) {
        string ciphertext = "";
        string plaintext = "";

        cin >> ciphertext;

        cout << ciphertext << " -> " << solution_two(ciphertext, plaintext) << endl;
    }

    return 0;
}

string solution_two(string ciphertext, string plaintext) {
    plaintext.resize(ciphertext.length());

    // AMBIGUOUS if palindrome and not all same char
    if (ciphertext == string(ciphertext.rbegin(), ciphertext.rend())) {
        return ciphertext.find_first_not_of(ciphertext[0]) == string::npos ? ciphertext : "AMBIGUOUS";
    }

    // pin index 1 and -2
    plaintext[1] = ciphertext[0];
    plaintext[ciphertext.length() - 2] = ciphertext[ciphertext.length() - 1];

    // fill from index 3
    for (size_t i = 1; i < ciphertext.length() - 1; i++) {
        plaintext[i + 2] = (char)(((char_to_num(ciphertext[i + 1]) - char_to_num(plaintext[i]) + 26) % 26) + 65);
    }

    // fill index 0 and 2
    if (ciphertext.length() > 2) {
        plaintext[2] = (char)(((char_to_num(ciphertext[3]) - char_to_num(plaintext[4]) + 26) % 26) + 65);
        plaintext[0] = (char)(((char_to_num(ciphertext[1]) - char_to_num(plaintext[2]) + 26) % 26) + 65);
    }

    return plaintext;
}

/* 1st = 2nd, last = 2nd to last */

/* AOAAAN -> BANANA
 * BANANA
 * AOAAAN
 *  A ANA
 */

/*

 BANANA
 AOAAAN
 ??????

 BANANA
 AOAAAN
 ?A??N?

 (A + ?) mod 26 = A
 ? = A - A mod 26
 ? = 0 = A

 BANANA
 AOAAAN
 ?A?AN?

 (N + ?) mod 26 = A
 ? = A - N mod 26
 ? = 13 = N

 BANANA
 AOAAAN
 ?ANAN?

 (N + ?) mod 26 = O
 ? = O - N mod 26
 ? = 1 = B

 BANANA
 AOAAAN
 BANAN?

 (A + ?) mod 26 = A
 ? = A - A mod 26
 ? = 0 = A

 */
