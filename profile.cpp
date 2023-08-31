#include <iostream>
#include <json/json.h>
#include <string>

int main() {
  // Read JSON input from std::cin
  std::string jsonInput;
  std::getline(std::cin, jsonInput);

  // Parse the JSON data
  Json::CharReaderBuilder reader;
  Json::Value jsonData;
  std::string errs;
  std::istringstream jsonStream(jsonInput);
  try {
    Json::parseFromStream(reader, jsonStream, &jsonData, &errs);
  } catch (const std::exception &e) {
    std::cerr << "Error while parsing JSON: " << e.what() << std::endl;
    return 1;
  }

  // Check if the "op" field exists
  if (jsonData.isMember("op")) {
    std::string operation = jsonData["op"].asString();
    std::cout << "Found 'op' field with value: " << operation << std::endl;
  } else {
    std::cout << "No 'op' field found in the JSON." << std::endl;
  }

  return 0;
}