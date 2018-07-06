# filename: gen_dummy.py
# python 3.6.2

units = ['B', 'KB', 'MB', 'GB']
print("[usage]")
print(">> [filesize] [{}]".format('|'.join(units)))

while True:
    try:
        print(">> ", end='')
        size, unit = input().split()
        size = int(size)
        unit = unit.upper()

        if unit not in units:
            print('wrong unit')
            continue

        actual_size = 2 ** (10 * (units.index(unit)))
        filename = "{}{}.dat".format(size, unit)

        with open(filename, 'w') as f:
            f.write('+' * (size * actual_size))

    except Exception as ex:
        print(ex)

