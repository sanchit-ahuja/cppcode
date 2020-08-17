from collections import defaultdict


def favorite(userBookslistened, bookgenres):
    # book genre --> [genre: books]
    booktogenre = {}
    for key, val in bookgenres.items():
        # temp_li = val
        for book in val:
            booktogenre[book] = key

    temp_dict = defaultdict(lambda: defaultdict(int))
    for key, val in userBookslistened.items():
        for book in val:
            if book in booktogenre:
                try:
                    temp_dict[key][booktogenre[book]] += 1
                except Exception as e:
                    print(e, "except")

    temp_dict = dict(temp_dict)
    final_dict = defaultdict(list)
    for key, val in temp_dict.items():
        maxnum = -1
        for key2, val2 in val.items():
            maxnum = max(maxnum, val2)

        for key2, val2 in val.items():
            if maxnum == val2:
                final_dict[key].append(key2)

    print(dict(final_dict))
    # print(temp_dict)


if __name__ == "__main__":
    userBookslistened = {"Fred": ["mass", "world", "stress"], "Jennie": [
        "happy", "pride"], "Rorie": ["alexander"]}
    bookgenres = {"Horror": ["mass", "stress"], "Comedy": [
        "happy"], "Romance": ["world", "alexander", "pride"]}
    favorite(userBookslistened, bookgenres)
