#include "../include/collection.h"

#include <iostream>

Collection::Collection() = default;

Collection::Collection(const std::string& n) : name{n}
{
}

void Collection::setName(const std::string& n) {
	name = n;
}

std::string Collection::getName() const {
	return name;
}

std::vector<Document> Collection::getDocuments() const {
	return documents;
}

void Collection::addDocument(const Document& doc) {
	documents.push_back(doc);
	doc.saveToJSON("data/" + doc.getName() + ".json");
}

void Collection::addDocument(const std::string& n) {
	Document doc(n);
	documents.push_back(doc);
	doc.saveToJSON("data/" + n + ".json");
}

void Collection::updateDocument(const std::string& n, const std::string& key, const std::string& value) {
	for (int i = 0; i < documents.size(); ++i) {
		if (documents[i].getName() == n) {
			documents[i].update(key, value);
			documents[i].saveToJSON("data/" + n + ".json");
			return;
		}
	}
	std::cout << "Document not found." << std::endl;
}

void Collection::viewDocument(const std::string& n) const {
	for (int i = 0; i < documents.size(); ++i) {
		if (documents[i].getName() == n) {
			documents[i].select();
			return;
		}
	}
	std::cout << "Document not found." << std::endl;
}

void Collection::deleteDocument(const std::string& n) {
	for (int i = 0; i < documents.size(); ++i) {
		if (documents[i].getName() == n) {
			std::remove(("data/" + n + ".json").c_str());
			documents.erase(documents.begin() + i);
			return;
		}
	}
	std::cout << "Document not found." << std::endl;
}