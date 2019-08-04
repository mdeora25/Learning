import requests
from bs4 import BeautifulSoup
from csv import writer
import datetime
import time
user_input = int(input("enter how long you want the code to run: "))
user_input1 = int(input("\n enter 1 for hour and 2 for mins: "))
user_input2 = int(input("\n enter the time interval: "))
user_input3 = int(input("\n enter 1 for min and 2 for sec: "))
if (user_input1 == 1 and user_input3 == 1):
    user_input = user_input * 60
    x = user_input2 * 60
elif (user_input1 == 1 and user_input3 == 2):
    user_input = user_input * 60 * 60
    x = user_input2 * 60
elif (user_input1 == 2 and user_input3 == 1):
    x = int(user_input2 * 60)
elif (user_input1 == 2 and user_input3 == 2):
    user_input = user_input * 60
    x = int(user_input2)
time_code = user_input
time_pass = time_code
stock_input = input("enter a symbol: ")



with open(stock_input+ '.csv', 'a') as csv_file:
    csv_writer = writer(csv_file)
    header =  ['price', 'time', 'date']
    csv_writer.writerow(header)
    while (time_code != 0):
        response = requests.get('https://finance.yahoo.com/quote/'+ stock_input +'/')
        soup = BeautifulSoup(response.text, 'html.parser')
        stocks = soup.find_all('div', {'class': 'My(6px) Pos(r) smartphone_Mt(6px)'})
        for stock in stocks:
            date_time = datetime.datetime.now()
            price = stock.find('span')
            stock_time = date_time.time()
            stock_date = date_time.date()
            csv_writer.writerow([price.text,stock_time, stock_date])
        print(price.text)
        if (time_pass != 1):
            time.sleep(x)
            time_code = time_code - user_input2
        else:
            time_code = 0
print("web scraping done, data saved in ",stock_input,".csv")