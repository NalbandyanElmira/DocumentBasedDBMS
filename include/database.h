#ifndef DATABASE_H
#define DATABASE_H

#include "collection.h"

#include <vector>
#include <string>

class Database {
public:
	Database();
	Database(const std::string&);
	void setName(const std::string&);
	std::string getName() const;
	void addCollection(const std::string&);
	void addCollection(const Collection&);
	void updateCollection(const std::string&, const std::string&, const std::string&);
	void viewCollection(const std::string&);
	void deleteCollection(const std::string&);
private:
	std::string name;
	std::vector<Collection> collections;
};

#endif // DATABASE_H