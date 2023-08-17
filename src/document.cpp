#include "../include/document.h"

#include <iostream>
#include <fstream>
#include "../include/json.hpp"

using Json = nlohmann::json;

Document::Document() = default;

Document::Document(const std::string& n) : name{n}
{
}

void Document::setName(const std::string& n) {
	name = n;
}

std::string Document::getName() const {
	return name;
}

void Document::insert(const std::string& key, const std::string& value) {
	doc[key] = value;
}

void Document::update(const std::string& key, const std::string& value) {
	doc[key] = value;
}

void Document::select() const {
	for (const auto& pair : doc) {
		std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
	}
}

void Document::remove(const std::string& key, const std::string& value) {
	doc.erase(key);
}

void Document::saveToJSON(const std::string& filename) const {
    nlohmann::json jsonDocument; 
    for (const auto& pair : doc) {
        jsonDocument[pair.first] = pair.second;
    }
    std::ofstream fileStream(filename);
    if (fileStream.is_open()) {
        fileStream << jsonDocument.dump();  
        fileStream.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void Document::loadFromJSON(const std::string& filename) {
    std::ifstream fileStream(filename);
    if (fileStream.is_open()) {
        nlohmann::json jsonDocument;
        fileStream >> jsonDocument;
        for (const auto& item : jsonDocument.items()) {
            doc[item.key()] = item.value().get<std::string>();
        }
        fileStream.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

std::string Document::getFieldValue(const std::string& field) const {
    auto it = doc.find(field);
    if (it != doc.end()) {
        return it->second;
    }
    return "";
}