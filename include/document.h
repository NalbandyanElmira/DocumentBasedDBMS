#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <unordered_map>

class Document {
public:
	Document();
	Document(const std::string&);
	void setName(const std::string&);
	std::string getName() const;
	void insert(const std::string&, const std::string&);
	void update(const std::string&, const std::string&);
	void select() const;
	void remove(const std::string&, const std::string&);
	void saveToJSON(const std::string&) const;
	void loadFromJSON(const std::string&);
	std::string getFieldValue(const std::string&) const;
private:
	std::string name;
	std::unordered_map<std::string, std::string> doc;
};

#endif // DOCUMENT_H