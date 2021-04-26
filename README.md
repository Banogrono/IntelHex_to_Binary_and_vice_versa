# IntelHex_to_Binary_and_vice_versa

### Short description

Simple command line program that codes intel hex into binary and decodes binary into intel hex.

---

### Summary

The program requires two files: "file.hex" and "file.bin". The file "file.hex" is required to generate a code with 5-bit word length. The generated code is then saved in the "results.txt" file. 

The file "file.bin" is required to generate a file in Intel HEX format. The result of the operation is saved in the "results.txt" file. 

Switching from encoding mode to decoding mode and vice versa is performed by the "CODING_DECODING" variable of bool type, where **true** value means decoding mode and **false** value means encoding mode. 

This is the table that was used to perform coding: 
| Character | Code word |
| --------- | --------- |
| 0|0 0000|
|1| 0 0001 |
|2| 0 0010 |
|3| 0 0011 |
|4| 0 0100 |
|5| 0 0101 |
|6| 0 0110 |
|7| 0 0111 |
|8| 0 1000 |
|9| 0 1001 |
|A| 0 1010 |
|B| 0 1011 |
|C| 0 1100 |
|E| 0 1101 |
|F| 0 1111 |
| :| 1 0000 |
| \n | 1 0001 |


The program is divided into several functions:

*void save_to_file(const string &filename, const string& content)*
This function saves the string (result) to the file with the given name. 

*void code_to_bin()*
This function opens the file to be encoded, reads its contents character by character, and encodes it to a form of code with a 5-bit word length. The result of the operation is then saved to the file "results.txt", by using the function "save_to_file()". 

*void decode_to_hex()*
This function opens the file to be decoded, reads its contents in groups of five symbols, and generates the corresponding character in Intel HEX format for the given group of symbols.The result of the operation is then saved to the file "results.txt", by using the function "save_to_file()".

---
