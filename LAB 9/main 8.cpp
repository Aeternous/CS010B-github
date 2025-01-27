#include <iostream>
#include <fstream>
using namespace std;

// Recursive helper function to copy contents in reverse order
void rCopy(istream &in, ostream &out) {
    char ch;
    // Move to the end of the stream and start reading backwards
    if (in.get(ch)) {
        rCopy(in, out);  // Recursive call before writing the character
        out.put(ch);
    }
}

// Main function to open files and handle errors
bool rCopy(const string &input_file, const string &output_file) {
    ifstream infile(input_file);
    if (!infile) {
        cerr << "Error opening " << input_file << endl;
        return false;
    }

    ofstream outfile(output_file);
    if (!outfile) {
        cerr << "Error opening " << output_file << endl;
        return false;
    }

    // Move to the end of the file
    infile.seekg(0, ios::end);
    streampos length = infile.tellg();
    infile.seekg(0);

    // Start the recursive copy
    rCopy(infile, outfile);

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "USAGE: " << argv[0] << " input-file output-file" << endl;
        return 1;
    }

    if (rCopy(argv[1], argv[2])) {
        cout << "Copy completed" << endl;
    } else {
        cout << "Copy not completed" << endl;
    }

    return 0;
}
