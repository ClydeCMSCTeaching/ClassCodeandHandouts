class Book:
    def __init__(self, title, author, year=None):
        self.title = title
        self.author = author
        self.year = year
        
    def __str__(self):
        if self.year is None:
            return f"BOOK: Title {self.title}, Author {self.author}"
        else:
     	    return f"BOOK: Title {self.title}, Author {self.author}, year {self.year}"

if __name__ == "__main__":
    book1 = Book('The Future of Animal Farming', 'Marian Stamp Dawkins', 2015)

    print(book1)
    book1.title = 'something else'
    book1.year = 1995
    print(book1.title)
