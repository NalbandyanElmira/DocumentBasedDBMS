#ifndef COLLECTION_H
#define COLLECTION_H

#include "document.h"

#include <vector>
#include <string>

class Collection {
public:
	Collection();
	Collection(const std::string&);
	void setName(const std::string&);
	std::string getName() const;
	std::vector<Document> getDocuments() const;
	void addDocument(const Document&);
	void addDocument(const std::string&);
	void updateDocument(const std::string&, const std::string&, const std::string&);
	void viewDocument(const std::string&) const;
	void deleteDocument(const std::string&);
private:
	std::string name;
	std::vector<Document> documents;
};

#endif // COLLECTION_H