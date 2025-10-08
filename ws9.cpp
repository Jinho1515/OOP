#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

typedef vector<int> Records;

class RecordsManager {
private:
    fstream _file;
    string _filename;

public:
    RecordsManager(string filename) : _filename(filename) {}

    void read(Records &records) {
        try {
            _file.open(_filename, ios::in);
            if (!_file.is_open()) {
                throw runtime_error("Cannot open file");
            }

            string line;
            while (getline(_file, line)) {
                int value = stoi(line);  // may throw
                records.push_back(value);
            }
        }
        catch (const invalid_argument &e) {
            cout << "invalid_argument error" << endl;
            if (_file.is_open()) _file.close();
            throw;
        }
        catch (const out_of_range &e) {
            cout << "out_of_range error" << endl;
            if (_file.is_open()) _file.close();
            throw;
        }
        catch (const runtime_error &e) {
            cout << "runtime_error error" << endl;
            if (_file.is_open()) _file.close();
            throw;
        }
        catch (...) {
            cout << "unknown error" << endl;
            if (_file.is_open()) _file.close();
            throw;
        }

        if (_file.is_open()) _file.close();  // normal close
    }
};

int main(int argc, char* argv[]) {
    Records myRecords;
    string filename = "records.txt";
    if (argc > 1) filename = argv[1];

    RecordsManager recordM(filename);

    try {
        recordM.read(myRecords);
        int sum = 0;
        for (int i = 0; i < (int)myRecords.size(); i++) {
            sum += myRecords[i];
        }
        cout << sum << endl;
    }
    catch (const exception &e) {
        cerr << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
