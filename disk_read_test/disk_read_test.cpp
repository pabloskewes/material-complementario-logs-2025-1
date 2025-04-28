#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

const size_t BUFFER_SIZE = 1024 * 1024; // 1 MB

// Generates a binary file of given size (in MB)
void generate_binary_file(const string &filename, size_t size_in_mb) {
  ofstream file(filename, ios::binary);
  if (!file) {
    cerr << "Error creating file: " << filename << endl;
    return;
  }

  size_t num_values = (size_in_mb * 1024 * 1024) / sizeof(uint64_t);
  mt19937_64 rng(42); // Fixed seed
  uniform_int_distribution<uint64_t> dist;

  for (size_t i = 0; i < num_values; ++i) {
    uint64_t value = dist(rng);
    file.write(reinterpret_cast<const char *>(&value), sizeof(uint64_t));
  }

  file.close();
  cout << "File created: " << filename << " (" << size_in_mb << " MB, "
       << num_values << " values)" << endl;
}

// Reads a binary file and reports how long it takes
void read_file(const string &filename) {
  ifstream file(filename, ios::binary);
  if (!file) {
    cerr << "Error opening file: " << filename << endl;
    return;
  }

  vector<char> buffer(BUFFER_SIZE);
  size_t total_read = 0;

  auto start = high_resolution_clock::now();

  while (file.read(buffer.data(), BUFFER_SIZE)) {
    total_read += file.gcount();
  }
  total_read += file.gcount(); // Read the last partial block

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start).count();

  cout << "Read " << total_read / (1024 * 1024) << " MB in " << duration
       << " ms" << endl;

  file.close();
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cerr << "Usage:\n"
         << "  " << argv[0] << " --generate <filename> <size_in_mb>\n"
         << "  " << argv[0] << " --read <filename>\n";
    return 1;
  }

  string command = argv[1];

  if (command == "--generate") {
    if (argc != 4) {
      cerr << "Usage: " << argv[0] << " --generate <filename> <size_in_mb>\n";
      return 1;
    }
    string filename = argv[2];
    size_t size_in_mb = stoull(argv[3]);
    generate_binary_file(filename, size_in_mb);

  } else if (command == "--read") {
    string filename = argv[2];
    cout << "First read:" << endl;
    read_file(filename);
    cout << "Second read (may be cached):" << endl;
    read_file(filename);

  } else {
    cerr << "Unknown command: " << command << endl;
    return 1;
  }

  return 0;
}
