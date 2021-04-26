/*
@Author: Banogrono
@Description: Simple command line program that codes intel hex into binary and decodes binary into intel hex.
@Date: 10/04/2021
*/

#include <iostream>
#include <fstream>

using namespace std;

// --------------------- VARIABLES ----------------------------

char *FILE_CODING = "file.hex";    // DEFAULT NAME OF FILE TO CODE
char *FILE_DECODING = "file.bin";    // DEFAULT NAME OF FILE TO DECODE
char *FILE_RESULTS = "results.txt";    // DEFAULT NAME OF FILE CONTAINING RESULTS OF OPERATIONS

bool CODING_DECODING = true; // 0/ false - Coding | 1/ true - Decoding

// --------------------- FUNCTIONS -----------------------------

// Saving to file
void save_to_file(const string &filename, const string& content) {
    std::fstream file;
    file.open(filename, std::ios::out);

    if (file.is_open()) {
        for (char c : content) {
            file << c;
        }
        file.close();
        std::cout << "Successfully saved to: " << filename << "!" << std::endl;
    } else
        printf("E: Could not open file.");
}

// Coding
void code_to_bin() {

    // opening the file
    fstream my_file;
    my_file.open(FILE_CODING, ios::in);
    if (!my_file) {
        cout << "File could not be open!\n";
        return;
    } else {
        cout << "File opened successfully!\n";
    }

    char next_char;
    string binary_string;

    // reading file
    while (my_file >> noskipws >> next_char) {

        switch (next_char) {
            case '0':
                binary_string.append("00000");
                break;
            case '1':
                binary_string.append("00001");
                break;
            case '2':
                binary_string.append("00010");
                break;
            case '3':
                binary_string.append("00011");
                break;
            case '4':
                binary_string.append("00100");
                break;
            case '5':
                binary_string.append("00101");
                break;
            case '6':
                binary_string.append("00110");
                break;
            case '7':
                binary_string.append("00111");
                break;
            case '8':
                binary_string.append("01000");
                break;
            case '9':
                binary_string.append("01001");
                break;
            case 'A':
                binary_string.append("01010");
                break;
            case 'B':
                binary_string.append("01011");
                break;
            case 'C':
                binary_string.append("01100");
                break;
            case 'D':
                binary_string.append("01101");
                break;
            case 'E':
                binary_string.append("01110");
                break;
            case 'F':
                binary_string.append("01111");
                break;
            case ':':
                binary_string.append("10000");
                break;
            case '\n':
                binary_string.append("10011"); // CR + LF
                break;
            default:
                break;
        }
    }
    my_file.close(); // close file after reading data

    save_to_file(FILE_RESULTS, binary_string);
}

// Decoding TODO
void decode_to_hex() {

    // opening the file
    fstream my_file;
    my_file.open(FILE_DECODING, ios::in);
    if (!my_file) {
        cout << "File could not be open!\n";
        return;
    } else {
        cout << "File opened successfully!\n";
    }

    char next_char;
    int counter = 0;
    string hex_string;
    string temp;

    // reading file
    while (my_file >> noskipws >> next_char) {


        if (counter == 5) {
            if (!(temp == "00000")) {
                if (temp == "00001") { hex_string.append("1"); }
                else if (temp == "00010") { hex_string.append("2"); }
                else if (temp == "00011") { hex_string.append("3"); }
                else if (temp == "00100") { hex_string.append("4"); }
                else if (temp == "00101") { hex_string.append("5"); }
                else if (temp == "00110") { hex_string.append("6"); }
                else if (temp == "00111") { hex_string.append("7"); }
                else if (temp == "01000") { hex_string.append("8"); }
                else if (temp == "01001") { hex_string.append("9"); }
                else if (temp == "01010") { hex_string.append("A"); }
                else if (temp == "01011") { hex_string.append("B"); }
                else if (temp == "01100") { hex_string.append("C"); }
                else if (temp == "01101") { hex_string.append("D"); }
                else if (temp == "01110") { hex_string.append("E"); }
                else if (temp == "01111") { hex_string.append("F"); }
                else if (temp == "10000") { hex_string.append(":"); }
                else if (temp == "10011") { hex_string.append("\n"); }
            } else { hex_string.append("0"); }
            temp = "";
            counter = 0;
        }
        temp.append(string(1,next_char));
        counter++;
    }
    my_file.close(); // close file after reading data
    save_to_file(FILE_RESULTS, hex_string);
}

// ----------------------------------------------------------------

int main() {

    if (!CODING_DECODING)
        code_to_bin();
    else
        decode_to_hex();
    cout << "DONE" << endl;
    return 0;
}



