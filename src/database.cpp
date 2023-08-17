#include "../include/database.h"

#include <iostream>

Database::Database() = default;

Database::Database(const std::string& n) : name{n} 
{
}

void Database::setName(const std::string& n) {
	name = n;
}

std::string Database::getName() const {
	return name;
}

void Database::addCollection(const std::string& n) {
	Collection col(n);
	collections.push_back(col);
}

void Database::addCollection(const Collection& col) {
	collections.push_back(col);
}

void Database::updateCollection(const std::string& colName, const std::string& key, const std::string& value) {
	for (Collection& col : collections) {
		if (col.getName() == colName) {
			col.updateDocument(colName, key, value);
			return;  
		}
	}
	std::cout << "Collection not found." << std::endl;
}

void Database::viewCollection(const std::string& colName) {
	for (const Collection& col : collections) {
		if (col.getName() == colName) {
			for (int i = 0; i < col.getDocuments().size(); ++i) {
				col.viewDocument(col.getDocuments()[i].getName());
			}
			return;
		}
	}
	std::cout << "Collection not found." << std::endl;
}

void Database::deleteCollection(const std::string& colName) {
	for (auto it = collections.begin(); it != collections.end(); ++it) {
		if (it->getName() == colName) {
			collections.erase(it);
			return;
		}
	}
	std::cout << "Collection not found." << std::endl;
}