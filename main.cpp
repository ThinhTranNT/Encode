#include "FrequencyCounter.h"
#include "Huffman.h"

std::ifstream::pos_type filesize(const char* filename);

int main()
{
    FrequencyCounter frequencyCounter;
    Huffman huffman;
    cout << " Encode or decode: ";
    string workingMode;
    cin >> workingMode;
    if (workingMode == "encode")
    {
        string str;
        cout << " Enter the name of file: ";
        cin >> str;
        clock_t tStart = clock();
        frequencyCounter.readFile("../" + str);
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("../" + str, "../encode.txt");
        cout << "Time taken: " << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << "sec" << endl;
        str = "../" + str;
        cout << "Input File Size : " << filesize(str.c_str()) << " bytes." << endl;
        cout << "Compressed File Size : " << filesize("../encode.txt") << " bytes." << endl;
        cout << "Compression Ratio : " << (1.0 * filesize("../encode.txt") / filesize(str.c_str())) << endl;
    }
    else if (workingMode == "decode")
    {
        clock_t tStart = clock();
        huffman.deHuffer("../encode.txt", "../decode.txt");
        cout << "Time taken: " << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << "sec" << endl;
        cout << "Input File (Compressed) Size : " << filesize("../encode.txt") << " bytes." << endl;
        cout << "DeCompressed File Size : " << filesize("../decode.txt") << " bytes." << endl;
    }


    return 0;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

