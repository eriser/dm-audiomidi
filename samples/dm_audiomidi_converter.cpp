
#include <iostream>
#include <chrono>
#include "AudioFormatsManager.hpp"
#include "StringUtilities.hpp"

using namespace dinahmoe;
using namespace assets;

int main (int argc, char** argv) {
  if (argc < 3 || argc >4 || (argc == 4 && strcmp(argv[3], "-v") != 0)) {
    std::cout << "Usage: dm_audiomidi_converter file.in file.out (-v)" << std::endl << std::endl;
    return 1;
  }
  bool verbose = (argc == 4);
  AudioBuffer inBuf;
  AudioFormatsManager afm;
  float samplingRate;
  std::string fileInString(argv[2]);
  assets::AudioFormatTypes outFormat = assets::extensionToAudioFormat(utils::getFileExtension(fileInString).c_str());
  
  if (outFormat == assets::DM_FORMAT_UNKNOWN) {
    std::cerr << "Invalid output format" << std::endl;
    return 1;
  }
  
  auto start = std::chrono::system_clock::now();
  
  if (!afm.loadFile(argv[1], inBuf, samplingRate)) {
    std::cerr << "Problem with input file" << std::endl;
    return 1;
  }
  
  auto read = std::chrono::system_clock::now();
  
  if (!afm.writeFile (argv[2], inBuf, samplingRate, outFormat)) {
    std::cerr << "Problem with output file" << std::endl;
    return 1;
  }
  
  auto write = std::chrono::system_clock::now();
  
  
  if (verbose) {
    auto milliCount1 = (std::chrono::duration_cast<std::chrono::milliseconds>(read - start).count() / 1000.F);
    auto milliCount2 = (std::chrono::duration_cast<std::chrono::milliseconds>(write - read).count() / 1000.F);
    std::cout << "Sample rate: " << samplingRate << std::endl;
    std::cout << "Length: " << (float)inBuf.size / samplingRate << " s." << std::endl;
    std::cout << "Reading took " << (float)milliCount1 << " ms" << std::endl;
    std::cout << "Writing took " << (float)milliCount2 << " ms" << std::endl;
    
  }
  std::cout << "Process ended" << std::endl;
  return 0;
}


