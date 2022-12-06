#include "FrequencyCounter.h"

void FrequencyCounter::readFile(string fileName) {
    char character;
    ifstream inputFile;
//    vector<long long int> v;
    inputFile.open(fileName, ios::binary);
    while(inputFile.get(character))
        frequencyMap[character]++;
   /* char ch;
    unsigned char bits_8 = 0;
    long long counter = 0;
    while (inputFile.get(ch))
    {
        long long temp = v[static_cast<unsigned char>(ch)];
        while (temp != 1)
        {
            bits_8 <<= 1;
            if ((temp % 10) != 0)
                bits_8 |= 1;
            temp /= 10;
            counter++;
            if (counter == 8)
            {
                
                counter = bits_8 = 0;
            }
        }
    }
    while (counter != 8)
    {
        bits_8 <<= 1;
        counter++;
    }*/
//    for (const auto &item : frequencyMap)
//        cout << item.first << item.second <<endl;

    inputFile.close();
}

const unordered_map<char, int> &FrequencyCounter::getFrequencyMap() const {
    return frequencyMap;
}
