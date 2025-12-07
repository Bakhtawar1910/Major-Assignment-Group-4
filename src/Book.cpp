void ExchangeSystem::saveBooks() {
    ofstream file("data/books.txt");
    for (auto &b : books) {
        file << b.getId() << "|"
             << b.getTitle() << "|"
             << b.getAuthor() << "|"
             << b.getGenre() << "\n";
    }
    file.close();
}