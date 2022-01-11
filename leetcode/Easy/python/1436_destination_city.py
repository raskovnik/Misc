def destination_city(paths: list):
    outgoing = {}
    for path in paths:
        city_a, city_b = path
        outgoing[city_a] = outgoing.get(city_a, 0) + 1
        outgoing[city_b] = outgoing.get(city_b, 0)

    for city in outgoing:
        if outgoing[city] == 0: return city

