
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <queue> 
#include <unordered_set>
#include "Node.h"
#include<stdlib.h>
#include <bitset>
#include <sstream>

using namespace std;

#ifndef HUFFMANCODING_HUFFER_H
#define HUFFMANCODING_HUFFER_H


class Huffman {
    unordered_map<char,string> codeMap;
    void encodeCharacters(Node * rootNode, string codeString);
    void writeHeader(ofstream &outputStream);
    void readHeader(ifstream &inputStream);
    Node* buildDecodingTree(unordered_map<char,string> encodingMap);
    class myCompartor{
    public :
        int operator() (Node* node1, Node* node2);
    };
public :
    void huffer(unordered_map<char, int> frequencyMap);
    void deHuffer(string fileName,string decompressedFileName);
    void compressTofile(string InputfileName ,string OutputfileName);
    void decompressToFile(string codeString,Node *rootNode,string decompressedFileName);


};



#endif //HUFFMANCODING_HUFFER_H
