#include "include/database.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "Database 'myDatabase' is created." << std::endl;
    Collection col("User");
    std::cout << "Collection 'User' is created in 'myDatabase'." << std::endl;
    Document doc1("document1");
    std::cout << "Document 'document1' is created in 'User'.\n";
    doc1.insert("name", "John");
    doc1.insert("surname", "Snow");
    doc1.insert("age", "26");
    col.addDocument(doc1);
    Document doc2("document2");
    std::cout << "Document 'document2' is created in 'User'.\n";
    doc2.insert("name", "Damon");
    doc2.insert("surname", "Salvatore");
    doc2.insert("age", "25");
    col.addDocument(doc2);
    Document doc3("document3");
    std::cout << "Document 'document3' is created in 'User'.\n";
    doc3.insert("name", "Stefan");
    doc3.insert("surname", "Salvatore");
    doc3.insert("age", "23");
    col.addDocument(doc3);
    Database db("myDatabase");
    db.addCollection(col);
    std::cout << "View Collection's content.\n";
    db.viewCollection("User");
    std::cout << "Updating document1's value.\n";
    col.updateDocument("document1", "surname", "Rain");
    col.viewDocument("document1");
    std::cout << "Deleting document3 from collection.\n";
    col.deleteDocument("document3");
    std::cout << "View Collection's content.\n";
    db.viewCollection("User");

    return 0;
}