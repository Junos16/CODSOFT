#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i), available(true) {}
};

class Borrower {
public:
    std::string name;
    std::string id;

    Borrower(const std::string& n, const std::string& i)
        : name(n), id(i) {}
};

class Transaction {
public:
    Book* book;
    Borrower* borrower;
    bool checkedOut;
    std::string dueDate;

    Transaction(Book* b, Borrower* br, bool checkout, const std::string& date)
        : book(b), borrower(br), checkedOut(checkout), dueDate(date) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;
    std::vector<Transaction> transactions;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        books.emplace_back(title, author, isbn);
        std::cout << "Book added to the library: " << title << std::endl;
    }

    void searchBooks(const std::string& query) {
        std::cout << "Search results:\n";
        for (const auto& book : books) {
            if (book.title.find(query) != std::string::npos ||
                book.author.find(query) != std::string::npos ||
                book.isbn.find(query) != std::string::npos) {
                std::cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn
                          << ", Status: " << (book.available ? "Available" : "Checked Out") << std::endl;
            }
        }
    }

    void checkoutBook(const std::string& isbn, const std::string& borrowerId) {
        auto bookIter = std::find_if(books.begin(), books.end(), [&](const Book& b) { return b.isbn == isbn && b.available; });
        auto borrowerIter = std::find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& br) { return br.id == borrowerId; });

        if (bookIter != books.end() && borrowerIter != borrowers.end()) {
            bookIter->available = false;
            transactions.emplace_back(&(*bookIter), &(*borrowerIter), true, "Due Date: <calculate due date>");
            std::cout << "Book checked out to borrower " << borrowerId << std::endl;
        } else {
            std::cout << "Invalid ISBN or Borrower ID, or book is not available.\n";
        }
    }

    void returnBook(const std::string& isbn) {
        auto transactionIter = std::find_if(transactions.begin(), transactions.end(), [&](const Transaction& tr) {
            return tr.book->isbn == isbn && tr.checkedOut;
        });

        if (transactionIter != transactions.end()) {
            transactionIter->book->available = true;
            transactionIter->checkedOut = false;
            std::cout << "Book returned. Thank you!\n";
        } else {
            std::cout << "Invalid ISBN or book is not checked out.\n";
        }
    }

    void displayTransactions() const {
        std::cout << "Transaction History:\n";
        for (const auto& transaction : transactions) {
            std::cout << "Book: " << transaction.book->title << ", Borrower: " << transaction.borrower->name
                      << ", Status: " << (transaction.checkedOut ? "Checked Out" : "Returned") << std::endl;
        }
    }
};

int main() {
    Library library;

    while (true) {
        std::cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Search Books\n";
        std::cout << "3. Check Out Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Display Transactions\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author, isbn;
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter author name: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::cin >> isbn;
                library.addBook(title, author, isbn);
                break;
            }

            case 2: {
                std::string query;
                std::cout << "Enter search query: ";
                std::cin.ignore();
                std::getline(std::cin, query);
                library.searchBooks(query);
                break;
            }

            case 3: {
                std::string isbn, borrowerId;
                std::cout << "Enter ISBN of the book: ";
                std::cin >> isbn;
                std::cout << "Enter Borrower ID: ";
                std::cin >> borrowerId;
                library.checkoutBook(isbn, borrowerId);
                break;
            }

            case 4: {
                std::string isbn;
                std::cout << "Enter ISBN of the book to return: ";
                std::cin >> isbn;
                library.returnBook(isbn);
                break;
            }

            case 5:
                library.displayTransactions();
                break;

            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
