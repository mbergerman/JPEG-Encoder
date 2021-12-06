from bs4 import BeautifulSoup
import pprint

soup = BeautifulSoup(open("huffman_tables.html", encoding="utf8"), "html.parser")
dc_table, ac_table = soup.find_all('table')

Y_DC_ENCODE = {}
Y_DC_DECODE = {}
for row in dc_table.find_all('tr')[1:]:
    cat_data, code_data = row.find_all('td')
    cat_data = int(cat_data.get_text())
    code_data = code_data.get_text().strip()
    Y_DC_ENCODE[cat_data] = code_data 
    Y_DC_DECODE[code_data] = cat_data

Y_AC_ENCODE = {}
Y_AC_DECODE = {}
for row in ac_table.find_all('tr')[1:-1]:
    runcat_data, code_data = row.find_all('td')
    run_data, cat_data = runcat_data.get_text().split(',')
    run_data = int(run_data)
    cat_data = int(cat_data.split(' ')[0])
    code_data = code_data.get_text().strip()

    Y_AC_ENCODE[run_data,cat_data] = code_data
    Y_AC_DECODE[code_data] = (run_data,cat_data)
    # use code = Y_AC_ENCODE[run,cat] for encoding
    # use run, cat = Y_AC_DECODE[code] for decoding


with open("Y_TABLES.py", "w") as fp:
    print('Y_DC_ENCODE=', file=fp)
    print(Y_DC_ENCODE, file=fp)
    print('\n')
    print('Y_DC_DECODE=', file=fp)
    print(Y_DC_DECODE, file=fp)
    print('\n')
    print('Y_AC_ENCODE=', file=fp)
    print(Y_AC_ENCODE, file=fp)
    print('\n')
    print('Y_AC_DECODE=', file=fp)
    print(Y_AC_DECODE, file=fp)
    print('\n')