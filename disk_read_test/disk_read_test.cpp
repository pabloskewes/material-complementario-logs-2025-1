#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

const size_t BUFFER_SIZE = 1024 * 1024; // 1 MB

void generate_binary_file(const std::string &filename, size_t size_in_mb) {
  std::ofstream file(filename, std::ios::binary);
  if (!file) {
    std::cerr << "Error creating file: " << filename << std::endl;
    return;
  }

  size_t num_values = (size_in_mb * 1024 * 1024) / sizeof(uint64_t);

  std::mt19937_64 rng(42); // Fixed seed for reproducibility
  std::uniform_int_distribution<uint64_t> dist;

  for (size_t i = 0; i < num_values; ++i) {
    uint64_t value = dist(rng);
    file.write(reinterpret_cast<const char *>(&value), sizeof(uint64_t));
  }

  file.close();
  std::cout << "File created: " << filename << " (" << size_in_mb << " MB, "
            << num_values << " values)" << std::endl;
}

void read_file(const string &filename) {
  ifstream file(filename, ios::in | ios::binary);
  if (!file) {
    cerr << "Error abriendo archivo: " << filename << endl;
    return;
  }

  vector<char> buffer(BUFFER_SIZE);

  auto start = high_resolution_clock::now();

  size_t total_read = 0;
  while (file.read(buffer.data(), BUFFER_SIZE)) {
    total_read += file.gcount();
  }
  // Leer lo que queda (menos de un buffer)
  total_read += file.gcount();

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start).count();

  cout << "Leído " << total_read / (1024 * 1024) << " MB en " << duration
       << " ms" << endl;

  file.close();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Uso: " << argv[0] << " archivo.bin" << endl;
    return 1;
  }

  const string filename = argv[1];

  cout << "Primera lectura:" << endl;
  read_file(filename);

  cout << "Segunda lectura (posible efecto de caché):" << endl;
  read_file(filename);

  return 0;
}
